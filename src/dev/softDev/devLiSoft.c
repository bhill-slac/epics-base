/*************************************************************************\
* Copyright (c) 2008 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/* devLiSoft.c,v 1.10.2.1 2008/08/06 22:11:50 anj Exp
 *
 *      Author: Janet Anderson
 *      Date: 09-23-91
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "alarm.h"
#include "dbDefs.h"
#include "dbAccess.h"
#include "recGbl.h"
#include "devSup.h"
#include "longinRecord.h"
#include "epicsExport.h"

/* Create the dset for devLiSoft */
static long init_record(longinRecord *prec);
static long read_longin(longinRecord *prec);

struct {
    long      number;
    DEVSUPFUN report;
    DEVSUPFUN init;
    DEVSUPFUN init_record;
    DEVSUPFUN get_ioint_info;
    DEVSUPFUN read_longin;
} devLiSoft = {
    5,
    NULL,
    NULL,
    init_record,
    NULL,
    read_longin
};
epicsExportAddress(dset, devLiSoft);

static long init_record(longinRecord *prec)
{
    /* INP must be CONSTANT, PV_LINK, DB_LINK or CA_LINK*/
    switch (prec->inp.type) {
    case CONSTANT:
        if (recGblInitConstantLink(&prec->inp, DBF_LONG, &prec->val))
            prec->udf = FALSE;
        break;
    case PV_LINK:
    case DB_LINK:
    case CA_LINK:
        break;
    default:
        recGblRecordError(S_db_badField, (void *)prec,
            "devLiSoft (init_record) Illegal INP field");
        return S_db_badField;
    }
    return 0;
}

static long read_longin(longinRecord *prec)
{
    long status;

    status = dbGetLink(&prec->inp, DBR_LONG, &prec->val, 0, 0);
    if (!status &&
        prec->tsel.type == CONSTANT &&
        prec->tse == epicsTimeEventDeviceTime)
        dbGetTimeStamp(&prec->inp, &prec->time);
    return status;
}
