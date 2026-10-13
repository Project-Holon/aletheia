/*
 * function: BTL_CLIENT_StepRunServerCommands
 * address: 0x021D1A74
 * packet: pkt_ov093_021D1A74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ADAPTER_GetRecvData 0x021EEC20 thumb ov093
 *   BTL_SERVER_CompareFlowOutput 0x021BB570 thumb ov093
 *   BTL_MAIN_SetRecordInvalid 0x021B9184 thumb ov093
 *   MIi_CpuCopy32 0x02082A90 arm
 *   BTLV_CORE_EndWaitMessage 0x021EA824 thumb ov093
 *   BTL_CLIENT_IsCounterFadeDone 0x021D3F4C thumb ov093
 *   BTL_SERVER_CMD_ReadNext 0x021CD5E0 thumb ov093
 *   gServerCommandHandlers 0x021F00DC data a4
 */
#include "../include/Obj01237.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 wpos, rpos; } Buf;
typedef struct { u8 pad[0x1B2]; unsigned char f0:3; unsigned char flag:1; unsigned char f4:4; } Flags;
typedef int (*Callback)(u8 *, int *, int *);
typedef struct { int code; Callback fn; } Entry;
extern const Entry gServerCommandHandlers[];
extern int BTL_ADAPTER_GetRecvData(int, u8 **);
extern int BTL_SERVER_CompareFlowOutput(u8 *, int, void *, u32);
extern void BTL_MAIN_SetRecordInvalid(void *);
extern void MIi_CpuCopy32(const void *, void *, u32);
extern void BTLV_CORE_EndWaitMessage(char *p);
extern int BTL_CLIENT_IsCounterFadeDone(void *);
extern int BTL_SERVER_CMD_ReadNext(Buf *, int *);
int BTL_CLIENT_StepRunServerCommands(u8 *p, int *state, void *a2)
{
    u8 *args;
    int size;
    u16 len;
    Buf *buf;
    u32 i;
    int code;
again:
    switch (*state) {
    case 0:
        size = BTL_ADAPTER_GetRecvData(((struct Obj01237 *)p)->f50, &args);
        if (*(u8 * *)&((struct Obj01237 *)p)->fA0 != 0 && p[0x1AE] != 0 && ((Flags *)p)->flag != 0) {
            if (BTL_SERVER_CompareFlowOutput(*(u8 * *)&((struct Obj01237 *)p)->fA0, p[0x1AE], args, size) != 0) {
                BTL_MAIN_SetRecordInvalid(((struct Obj01237 *)p)->f0);
                ((Flags *)p)->flag = 0;
            }
            p[0x1AE] = 0;
        }
        buf = *(Buf * *)&((struct Obj01237 *)p)->f134;
        len = size;
        MIi_CpuCopy32(args, buf + 1, len);
        buf->wpos = len;
        buf->rpos = 0;
        if (p[0x1A9] != 0) {
            p[0x1A9] = 0;
            BTLV_CORE_EndWaitMessage(((struct Obj01237 *)p)->f54);
        }
        (*state)++;
    case 1:
        buf = *(Buf * *)&((struct Obj01237 *)p)->f134;
        if (buf->rpos == buf->wpos) {
            *state = 4;
            return 1;
        }
        if (BTL_CLIENT_IsCounterFadeDone(p + 0x18) != 0) return 1;
        (*state)++;
    case 2:
        code = BTL_SERVER_CMD_ReadNext(*(Buf * *)&((struct Obj01237 *)p)->f134, (int *)(p + 0x138));
        ((struct Obj01237 *)p)->f178 = code;
        if (code == 0x5E) return 1;
        for (i = 0; i < 0x5D; i++) {
            if (code == gServerCommandHandlers[i].code) break;
        }
        if (i == 0x5D) {
            *state = 1;
            goto again;
        }
        *(Callback *)&((struct Obj01237 *)p)->f17C = gServerCommandHandlers[i].fn;
        ((struct Obj01237 *)p)->f180 = 0;
        (*state)++;
    case 3:
        if ((*(Callback *)(p + 0x17C))(p, (int *)(p + 0x180), (int *)(p + 0x138)) != 0) {
            *state = 1;
            goto again;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}
