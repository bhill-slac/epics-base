/*  dbStaticPvt.h */
/*
 *	Author:		Marty Kraimer
 *      Date:           06Jun95
 *
 *      Experimental Physics and Industrial Control System (EPICS)
 *
 *      Copyright 1991, the Regents of the University of California,
 *      and the University of Chicago Board of Governors.
 *
 *      This software was produced under  U.S. Government contracts:
 *      (W-7405-ENG-36) at the Los Alamos National Laboratory,
 *      and (W-31-109-ENG-38) at Argonne National Laboratory.
 *
 *      Initial development by:
 *              The Controls and Automation Group (AT-8)
 *              Ground Test Accelerator
 *              Accelerator Technology Division
 *              Los Alamos National Laboratory
 *
 *      Co-developed with
 *              The Controls and Computing Group
 *              Accelerator Systems Division
 *              Advanced Photon Source
 *              Argonne National Laboratory
 *
 * Modification Log:
 * -----------------
 * .01  06JUN95		mrk	Initial version
 */

#ifndef INCdbStaticPvth
#define INCdbStaticPvth 1

/*Following are not intended for client code */
void dbInitDeviceMenu(DBENTRY *pdbentry);

/*The following routines have different versions for run-time no-run-time*/
long dbAllocRecord(DBENTRY *pdbentry,char *precordName);
long dbFreeRecord(DBENTRY *pdbentry);

long dbGetFieldAddress(DBENTRY *pdbentry);
char *dbRecordName(DBENTRY *pdbentry);

char *dbGetStringNum(DBENTRY *pdbentry);
long dbPutStringNum(DBENTRY *pdbentry,char *pstring);

void dbGetRecordtypeSizeOffset(dbRecDes *pdbRecDes);

/*The following are in dbPvdLib.c*/
/*directory*/
typedef struct{
	ELLNODE		node;
	dbRecDes	*precdes;
	dbRecordNode	*precnode;
}PVDENTRY;
int dbPvdTableSize(DBBASE *pdbBase,int size);
void	dbPvdInitPvt(DBBASE *pdbBase);
PVDENTRY *dbPvdFind(DBBASE *pdbBase,char *name,int lenname);
PVDENTRY *dbPvdAdd(DBBASE *pdbBase,dbRecDes *precdes,dbRecordNode *precnode);
void dbPvdDelete(DBBASE *pdbBase,dbRecordNode *precnode);
void dbPvdFreeMem(DBBASE *pdbBase);
void dbPvdDump(DBBASE *pdbBase,int verbose);
#endif /*INCdbStaticPvth*/
