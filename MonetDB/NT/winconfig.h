/*
 * The contents of this file are subject to the MonetDB Public
 * License Version 1.0 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at 
 * http://monetdb.cwi.nl/Legal/MonetDBLicense-1.0.html
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is the Monet Database System.
 * 
 * The Initial Developer of the Original Code is CWI.
 * Portions created by CWI are Copyright (C) 1997-2002 CWI.  
 * All Rights Reserved.
 * 
 * Contributor(s):
 * 		Martin Kersten <Martin.Kersten@cwi.nl>
 * 		Peter Boncz <Peter.Boncz@cwi.nl>
 * 		Niels Nes <Niels.Nes@cwi.nl>
 * 		Stefan Manegold  <Stefan.Manegold@cwi.nl>
 */

/* Manual config.h. needed for win32 .  */

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
/* In this case, malloc and friends are redefined in crtdbg.h to debug
   versions.  We need to include stdlib.h and malloc.h first or else
   we get conflicting declarations.
*/
#include <stdlib.h>
#include <malloc.h>
#include <crtdbg.h>
#endif

#include <process.h>
#include <windows.h>
#undef ERROR			/* too generic name defined in wingdi.h */

#ifndef WIN32
#define WIN32
#endif
#define NATIVE_WIN32

#define DIR_SEP '\\'
#define DIR_SEP_STR "\\"
#define PATH_SEP ';'
#define PATH_SEP_STR ";"
#define SO_EXT ".dll"

#define isatty _isatty

/* Define if on AIX 3.
   System headers sometimes define this.
   We just want to avoid a redefinition error message.  */
#ifndef _ALL_SOURCE
/* #undef _ALL_SOURCE */
#endif

/* Define if using alloca.c.  */
/* #undef C_ALLOCA */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
   This function is required for alloca.c support on those systems.  */
/* #undef CRAY_STACKSEG_END */

/* Define if you have alloca, as a function or macro.  */
#define HAVE_ALLOCA 1

/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
/* #undef HAVE_ALLOCA_H */

/* Define if you don't have vprintf but do have _doprnt.  */
/* #undef HAVE_DOPRNT */

/* Define if you have a working `mmap' system call.  */
#define HAVE_MMAP 1

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
/* #undef HAVE_SYS_WAIT_H */

/* Define if your struct tm has tm_zone.  */
/* #undef HAVE_TM_ZONE */

/* Define if you don't have tm_zone but do have the external array
   tzname.  */
#define HAVE_TZNAME 

/* Define if utime(file, NULL) sets file's timestamp to the present.  */
#define HAVE_UTIME_NULL 1

/* Define if you have the vprintf function.  */
#define HAVE_VPRINTF 1

/* Define as __inline if that's what the C compiler calls it.  */
#define inline __inline

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
#define pid_t int

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if the `setpgrp' function takes no argument.  */
/* #undef SETPGRP_VOID */

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at run-time.
 STACK_DIRECTION > 0 => grows toward higher addresses
 STACK_DIRECTION < 0 => grows toward lower addresses
 STACK_DIRECTION = 0 => direction of growth unknown
 */
/* #undef STACK_DIRECTION */

/* Define if the `S_IS*' macros in <sys/stat.h> do not work properly.  */
/* #undef STAT_MACROS_BROKEN */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
/* #undef TIME_WITH_SYS_TIME */

/* Define if your <sys/time.h> declares struct tm.  */
/* #undef TM_IN_SYS_TIME */

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* Define if lex declares yytext as a char * by default, not a char[].  */
#define YYTEXT_POINTER 1

/* Define this if the compiler has bool type defined */
#define HAVE_BOOL 1

/* Define this if you have the readline library */
/* #undef HAVE_LIBREADLINE */
/* #undef HAVE_LIBZ */
/* #undef HAVE_LIBBZ2 */

/* Define these if you have the respective hardware-counters library */
/* #undef HAVE_LIBPPERF	*/ /* Linux <= 2.2 */
/* #undef HAVE_LIBPERFCTR */ /* Linux >= 2.4 */
/* #undef HAVE_LIBPERFMON */ /* Solaris <= 7 */
/* #undef HAVE_LIBCPC */ /* Solaris >= 8 */

/* Define this if you have ctime_r(time_t*,char *buf,size_t s) */
/* #undef HAVE_CTIME_R3 */

/* LONGLONG */
/* #undef HAVE_LONGLONG */
#define HAVE__INT64 1

/* The number of bytes in a char.  */
#define SIZEOF_CHAR 1

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a long long.  */
/* #undef SIZEOF_LONG_LONG */

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* Define if you have the drand48 function.  */
/* #undef HAVE_DRAND48 */

/* Define if you have the ctime_r function.  */
/* #undef HAVE_CTIME_R */

/* Define if you have the fpclass function.  */
#define HAVE_FPCLASS 1

/* Define if you have the fpclassify function.  */
/* #undef HAVE_FPCLASSIFY */

/* Define if you have the fstat function.  */
#define HAVE_FSTAT 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the gethostname function.  */
#define HAVE_GETHOSTNAME 1

/* Define if you have the getopt function.  */
/* #undef HAVE_GETOPT */

/* Define if you have the getopt_long function.  */
/* #undef HAVE_GETOPT_LONG */

/* Define if you have the getpagesize function.  */
/* #undef HAVE_GETPAGESIZE */

/* Define if you have the getpgid function.  */
/* #undef HAVE_GETPGID */

/* Define if you have the getpwuid function.  */
/* #undef HAVE_GETPWUID */

/* Define if you have the getrlimit function.  */
/* #undef HAVE_GETRLIMIT */

/* Define if you have the gettimeofday function.  */
/* #undef HAVE_GETTIMEOFDAY */

/* Define if you have the ftime function.  */
#define HAVE_FTIME 1

/* Define if you have the getuid function.  */
/* #undef HAVE_GETUID */

/* Define if you have the isinf function.  */
/* #undef HAVE_ISINF */

/* Define if you have the mallinfo function.  */
/* #undef HAVE_MALLINFO */

/* Define if you have the mallopt function.  */
/* #undef HAVE_MALLOPT */

/* Define if you have the mkdir function.  */
#define HAVE_MKDIR 1

/* Define if you have the mrand48 function.  */
/* #undef HAVE_MRAND48 */

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1
#define putenv _putenv

/* Define if you have the rmdir function.  */
#define HAVE_RMDIR 1

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the setenv function.  */
/* #define HAVE_SETENV */

/* Define if you have the snprintf function.  */
#define HAVE_SNPRINTF 1
#define snprintf _snprintf

/* Define if you have the strcasecmp function.  */
#define HAVE_STRCASECMP 1
#define strcasecmp(x,y) stricmp(x,y)

/* Define if you have the strcspn function.  */
#define HAVE_STRCSPN 1

/* Define if you have the strdup function.  */
#define HAVE_STRDUP 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 

/* Define if you have the strstr function.  */
#define HAVE_STRSTR 1

/* Define if you have the strtod function.  */
#define HAVE_STRTOD 1

/* Define if you have the strtol function.  */
#define HAVE_STRTOL 1

/* Define if you have the sysconf function.  */
/* #undef HAVE_SYSCONF */

/* Define if you have the vsnprintf function.  */
#define HAVE_VSNPRINTF 1
#define vsnprintf _vsnprintf

/* Define if you have the <dirent.h> header file.  */
/* #undef HAVE_DIRENT_H */

/* Define if you have the <dlfcn.h> header file.  */
/* #undef HAVE_DLFCN_H */

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <getopt.h> header file.  */
/* #undef HAVE_GETOPT_H */

#define HAVE_GETSYSTEMINFO
#define HAVE_GLOBALMEMORYSTATUS
/* #undef HAVE_GLOBALMEMORYSTATUSEX */

/* Define if you have the <ieeefp.h> header file.  */
/* #undef HAVE_IEEEFP_H */

/* Define if you have the <io.h> header file.  */
#define HAVE_IO_H 1

/* Define if you have the <libcpc.h> header file.  */
/* #undef HAVE_LIBCPC_H */

/* Define if you have the <libperfctr.h> header file.  */
/* #undef HAVE_LIBPERFCTR_H */

/* Define if you have the <libpperf.h> header file.  */
/* #undef HAVE_LIBPPERF_H */

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <malloc.h> header file.  */
#define HAVE_MALLOC_H 1

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <netdb.h> header file.  */
/* #undef HAVE_NETDB_H */

/* Define if you have the <perfmon.h> header file.  */
/* #undef HAVE_PERFMON_H */

/* Define if you have the <pthread.h> header file.  */
#define HAVE_PTHREAD_H 1

/* Define this if you have the pthread_sigmask function */
/* #undef HAVE_PTHREAD_SIGMASK */

/* Define if you have the <pwd.h> header file.  */
/* #undef HAVE_PWD_H */

/* Define if you have the <rlimit.h> header file.  */
/* #undef HAVE_RLIMIT_H */

/* Define if you have the <semaphore.h> header file.  */
#define HAVE_SEMAPHORE_H 1

/* Define if you have the <signal.h> header file.  */
#define HAVE_SIGNAL_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
/* #undef HAVE_STRINGS_H */

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/file.h> header file.  */
/* #undef HAVE_SYS_FILE_H */

/* Define if you have the <sys/mman.h> header file.  */
/* #undef HAVE_SYS_MMAN_H */

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/param.h> header file.  */
/* #undef HAVE_SYS_PARAM_H */

/* Define if you have the <sys/resource.h> header file.  */
/* #undef HAVE_SYS_RESOURCE_H */

/* Define if you have the <sys/socket.h> header file.  */
/* #undef HAVE_SYS_SOCKET_H */

/* Define if you have the <sys/time.h> header file.  */
/* #undef HAVE_SYS_TIME_H */

/* Define if you have the <sys/times.h> header file.  */
/* #undef HAVE_SYS_TIMES_H */

/* Define if you have the <sys/utime.h> header file.  */
#define HAVE_SYS_UTIME_H 1

/* Define if you have the <time.h> header file.  */
#define HAVE_TIME_H 1

/* Define if you have the <unistd.h> header file.  */
/* #undef HAVE_UNISTD_H */

/* Define if you have the <winsock.h> header file.  */
#define HAVE_WINSOCK_H 1

/* Name of package */
#define PACKAGE "MonetDB"

/* Version number of package */
#define VERSION "4.3.6"

/* Host identifier */
#define HOST "i686-pc-win32"

/* directory prefix */
