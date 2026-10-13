/*
 * function: BTL_SERVER_FLOW_CureMajorStatusWithMessage
 * address:  0x021C557C
 * packet:   pkt_ov093_021C557C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_ClearMajorStatus  0x021D61F0  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj06227.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct UtilSlots;
extern void BTL_POKEPARAM_ClearMajorStatus(struct UtilSlots *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

void BTL_SERVER_FLOW_CureMajorStatusWithMessage(u8 *p, u8 *a, int k, int flag)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    BTL_POKEPARAM_ClearMajorStatus((struct UtilSlots *)a);
    BTL_SERVER_CMD_Push(((struct Obj06227 *)p)->fC, 0x10, n);
    BTL_SERVER_CMD_Push(((struct Obj06227 *)p)->fC, 0x35, n, 0);
    if (flag != 0) {
        switch (k) {
        case 2:
            BTL_SERVER_CMD_PushVariable(((struct Obj06227 *)p)->fC, 0x5b, 0x138, n, 0xffff0000);
            break;
        case 3:
            BTL_SERVER_CMD_PushVariable(((struct Obj06227 *)p)->fC, 0x5b, 0x126, n, 0xffff0000);
            break;
        default:
            BTL_SERVER_CMD_PushVariable(((struct Obj06227 *)p)->fC, 0x5b, 0x156, n, 0xffff0000);
            break;
        }
    }
}
