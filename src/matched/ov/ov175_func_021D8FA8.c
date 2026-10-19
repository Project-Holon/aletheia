/*
 * unit: yes
 * function: WIFIBATTLEMATCH_NET_CompStepL, WIFIBATTLEMATCH_NET_CompExit
 * address: 0x021D8FA8
 * packet: pkt_ov175_021D8FA8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021D905C tail-call stub included; function_starts seed 021D905C.
 * symbols:
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetCompWaitCallback 0x021D9A1C thumb ov175
 *   WIFIBATTLEMATCH_NET_GetCompWaitResult 0x021D9A30 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepCheckPeriod 0x021D9090 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit 0x021D8EC8 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 */
#include "../include/Obj00013.h"
typedef unsigned long u32;
typedef unsigned char  u8;
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *ctx, void *a, void *b);
extern void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *, void *);
extern u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int a);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepCheckPeriod(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit(u32 sys, int *state, char *p);
void WIFIBATTLEMATCH_NET_CompStepL(u32 sys, int *state, char *ctx)
{
    int result;
    switch (*state) {
    case 0:
        result = WIFIBATTLEMATCH_NET_HandleNetError(((struct Obj00013 *)ctx)->f34, (void *)1, 0);
        switch (result) {
        case 1: case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback(ctx, WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 1;
            break;
        }
        break;
    case 1:
        result = WIFIBATTLEMATCH_NET_GetCompWaitResult(ctx);
        if (result != 0xffff) *state = 2;
        if (result == 3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        result = WIFIBATTLEMATCH_NET_HandleNetError(((struct Obj00013 *)ctx)->f34, (void *)1, 0);
        switch (result) {
        case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup); break;
        }
        break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit); break;
    case 3:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct Obj00013 *)ctx)->f2C))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}
void WIFIBATTLEMATCH_NET_CompExit(u32 sys)
{
    WIFIBATTLEMATCH_UTIL_ClearCallback(sys);
}
