#include <mapi.h> 
#include <stdio.h> 
#include <stdlib.h> 

void die(Mapi dbh, MapiHdl hdl) { 
  if (hdl != NULL) { 
    mapi_explain_query(hdl, stderr); 
    do { 
      if (mapi_result_error(hdl) != NULL) 
        mapi_explain_result(hdl, stderr); 
    } while (mapi_next_result(hdl) == 1); 
    mapi_close_handle(hdl); 
    mapi_destroy(dbh); 
  } else if (dbh != NULL) { 
    mapi_explain(dbh, stderr); 
    mapi_destroy(dbh); 
  } else { 
    fprintf(stderr, "command failed\n"); 
  } 
  exit(-1); 
} 

MapiHdl query(Mapi dbh, char *q) { 
  MapiHdl ret = NULL; 

  if ((ret = mapi_query(dbh, q)) == NULL || mapi_error(dbh) != MOK) 
    die(dbh, ret); 

  return(ret); 
} 

void update(Mapi dbh, char *q) { 
  MapiHdl ret = query(dbh, q); 

  if (mapi_close_handle(ret) != MOK) 
    die(dbh, ret); 
} 

int main(int argc, char *argv[]) { 
  Mapi dbh; 
  MapiHdl hdl = NULL; 
  char *name; 
  char *age; 
  dbh = mapi_connect("localhost", 50000, "monetdb", "monetdb", "mal", "demo"); 

  if (mapi_error(dbh)) 
    die(dbh, hdl); 
  
  hdl = mapi_query(dbh, "rbase1 := bat.new(:str);"); 
  hdl = mapi_query(dbh, "bat.append(rbase1, \"abc\");"); 
  hdl = mapi_query(dbh, "bat.append(rbase1, \"cde\");"); 
  hdl = mapi_query(dbh, "c := batudf.regex(rbase1, \"a+\");");
  hdl = mapi_query(dbh, "io.print(c);"); 

  while (mapi_fetch_row(hdl)) { 
    name = mapi_fetch_field(hdl, 0); 
    age = mapi_fetch_field(hdl, 1); 
    printf("%s is %s\n", name, age); 
  } 

  mapi_close_handle(hdl); 
  mapi_destroy(dbh); 
  return(0); 
} 
