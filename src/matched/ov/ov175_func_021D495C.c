/*
 * function: WIFIBATTLEMATCH_NET_TaskStepD
 * address: 0x021D495C
 * packet: pkt_ov175_021D495C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_NET_GdbRequest 0x021DB3A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbGetMyRecords 0x021DB478 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetSetBsubwayStat 0x021D646C thumb ov175
 *   WIFIBATTLEMATCH_NET_CopyBsubwayStat 0x021D6724 thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteBoxAndWait 0x021D63DC thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepB 0x021D4608 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetNetId 0x021DC194 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbClearRecord 0x021DBFA4 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbCreateRecord 0x021DBFB4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsBoxAnimDone 0x021D63BC thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteBoxRecord 0x021D639C thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupBoxRecord 0x021D62A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsBoxReady 0x021D63B0 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepE 0x021D4B3C thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 */
typedef unsigned int u32;
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(u32, u32);
extern void WIFIBATTLEMATCH_NET_GdbRequest(char *, u32, int, u32);
extern int WIFIBATTLEMATCH_NET_GdbGetMyRecords(char *);
extern int WIFIBATTLEMATCH_NET_GetSetBsubwayStat(u32 save, u32 kind, u32 obj);
extern void WIFIBATTLEMATCH_NET_CopyBsubwayStat(u32 *, u32 *);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
extern void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(char *);
extern void func_021E8AA0(int *, int);
typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_NET_TaskStepB(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
extern u32 WIFIBATTLEMATCH_NET_GetNetId(char *);
extern void WIFIBATTLEMATCH_NET_GdbClearRecord(char *);
extern int WIFIBATTLEMATCH_NET_GdbCreateRecord(char *);
extern u32 WIFIBATTLEMATCH_NET_IsBoxAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteBoxRecord(char *);
extern void WIFIBATTLEMATCH_NET_SetupBoxRecord(u32 *p, u32 mode);
extern u32 WIFIBATTLEMATCH_NET_IsBoxReady(char *);
extern void WIFIBATTLEMATCH_NET_TaskStepE(unsigned sys, int *state, char *p);
extern int func_021E8844(const int *);
extern void func_021E8AB8(u32);
void WIFIBATTLEMATCH_NET_TaskStepD(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 24, 2);
        func_021E8AB4(sys, 1); *state = 11; break;
    case 1:
        if (*(u32 *)ctx[8] == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest((char *)p[12], -1, 0, ctx[14]);
            *state = 2;
        }
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_GdbGetMyRecords((char *)p[12]);
        if (result == 1) {
            *(u32 *)((u32 *)p[16])[8] = 1800;
            p[60] = WIFIBATTLEMATCH_NET_GetSetBsubwayStat(ctx[4], ((u32 *)ctx[2])[1], (u32)p);
            WIFIBATTLEMATCH_NET_CopyBsubwayStat((u32 *)ctx[5], p);
            *(u32 *)((u32 *)p[16])[10] = ((u32 *)((u32 *)p[16])[14])[21];
            *state = 3;
        }
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)p);
                func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepB);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            }
        }
        break;
    case 3:
        if (WIFIBATTLEMATCH_NET_GetNetId((char *)p[12]) == 0) {
            WIFIBATTLEMATCH_NET_GdbClearRecord((char *)p[12]); *state = 4;
        } else *state = 5;
        break;
    case 4:
        result = WIFIBATTLEMATCH_NET_GdbCreateRecord((char *)p[12]);
        if (result == 1) *state = 1;
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)p);
                func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepB);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            }
        }
        break;
    case 5:
        if (p[6] == 0) *state = 8;
        else if (p[60]) *state = 6;
        else *state = 10;
        p[60] = 0;
        break;
    case 6: *state = 7; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsBoxAnimDone((char *)p)) {
            WIFIBATTLEMATCH_NET_DeleteBoxRecord((char *)p); *state = 8;
        }
        break;
    case 8: WIFIBATTLEMATCH_NET_SetupBoxRecord((u32 *)p, 0); *state = 9; break;
    case 9: if (WIFIBATTLEMATCH_NET_IsBoxReady((char *)p)) *state = 10; break;
    case 10: func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepE); break;
    case 11: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}
