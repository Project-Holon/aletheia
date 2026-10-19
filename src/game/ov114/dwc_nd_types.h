#ifndef OV114_DWC_ND_TYPES_H
#define OV114_DWC_ND_TYPES_H
/* Types of the DWC download (nd) front end (dwc_nd.o). */

#include "dwci_nd_types.h"
#include "dwc_svl_types.h"

#include "../types.h"

/* Heap block of one nd session: credentials, SVL result and the token wait thread with its stack. */
typedef struct NdParam {
    char gameCode[0x20];        /* +0x000 */
    char password[0x20];        /* +0x020 */
    int status;                 /* +0x040, 1 once the download server is started */
    DWCSvlResult svl;           /* +0x044 */
    u8 stack[0x800];            /* +0x1b8 */
    u8 thread[0xc0];            /* +0x9b8, OSThread */
} NdParam;

/* File statics of dwc_nd.o. */
typedef struct NdState {
    DWCNdCallback callback;        /* +0x00 */
    int errorReported;          /* +0x04, set once the error callback was issued */
    int serverError;            /* +0x08 */
    int error;                  /* +0x0c */
    int reason;                 /* +0x10 */
    int state;                  /* +0x14, 0 idle, 1 ready, 2 busy, 3 token ready, 4 failed */
    NdParam *param;             /* +0x18 */
} NdState;

extern NdState gDwcNdState;
extern char gDwcNdMutex[];

#endif
