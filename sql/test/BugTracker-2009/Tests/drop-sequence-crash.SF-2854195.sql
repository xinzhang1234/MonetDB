-- http://bugs.monetdb.org/show_bug.cgi?id=2184

START TRANSACTION;

CREATE SEQUENCE "seq_2184" AS INTEGER;
CREATE TABLE x (
	id INTEGER NOT NULL DEFAULT NEXT VALUE FOR "seq_2184",
	CONSTRAINT "x_id_pkey" PRIMARY KEY ("id")
);

DROP TABLE x;

DROP SEQUENCE "seq_2184";

ROLLBACK;
