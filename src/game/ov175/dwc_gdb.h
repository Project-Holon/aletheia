#ifndef GAME_OV175_DWC_GDB_H
#define GAME_OV175_DWC_GDB_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_gdb.c, prototypes copied from their definitions. */

#include "../arm9/dwc_account.h"
#include "../ov175/sake_types.h"
#include "../ov175/gdb_types.h"

int DWC_GdbInitialize(int game_id, DWCstAccUserData *userdata, int ssl_type);
int DWC_GdbCancelRequest(void);
int DWC_GdbShutdown(void);
void DWCi_GdbCleanupRootCAList(void);
void DWC_GdbProcess(void);
int DWC_GdbGetState(void);
int DWC_GdbGetAsyncResult(void);
int DWC_GdbCreateRecordAsync(char *gdb_name, SAKEField *fields, int field_num, int *record_id);
int DWC_GdbUpdateRecordAsync(char *gdb_name, int record_id, SAKEField *fields, int field_num);
int DWC_GdbGetMyRecordsAsync(char *gdb_name, char **field_names, int field_num, DWCGdbGetRecordsCallback callback, void *user_param);
int DWC_GdbGetRecordsAsync(char *gdb_name, int *record_ids, int record_num, char **field_names, int field_num, DWCGdbGetRecordsCallback callback, void *user_param);
void DWCi_GdbPrintf(int line, char *fmt, ...);
int DWCi_GdbCheckStateForAsyncProcess(int *result);
void DWCi_GdbShutdownGsCore(void);
void DWCi_GdbSakeRequestCallback(SAKEInternal *sake, SAKERequestInternal *request, int result, void *inputData, void *outputData, void *userData);
int DWCi_GdbStartupResultToError(int startupResult, int *dwcError);
int DWCi_GdbStartRequestResultToError(int startRequestResult, int *dwcError);
int DWCi_GdbGetStartRequestErrorCode(int source, int error);
int DWCi_GdbHandleStartupResult(int startupResult);
int DWCi_GdbHandleStartRequestResult(int source, int startRequestResult);
int DWCi_GdbRequestResultToAsyncResult(int requestResult, int *dwcError);
int DWCi_GdbGetRequestResultErrorCode(int process, int asyncResult);
int DWCi_GdbHandleRequestResult(int process, int requestResult);
void DWCi_GdbSetAsyncStatus(unsigned int process);
void DWCi_GdbSwitchWork(void);
void DWCi_GdbSetUseSSL(int ssl_type);
/* END mkheaders: generated region */

#endif
