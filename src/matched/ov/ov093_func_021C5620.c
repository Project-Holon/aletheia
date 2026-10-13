/*
 * function: BTL_SERVER_FLOW_CureSick
 * address:  0x021C5620
 * packet:   pkt_ov093_021C5620
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTL_POKEPARAM_ClearMajorStatus  0x021D61F0  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   func_021C5698  0x021C5698  thumb  ov093
 *   BTL_POKEPARAM_CureSick  0x021D6238  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct Slot { u32 kind : 3; u32 rest : 29; };
extern struct Slot BTL_POKEPARAM_GetSickContRaw(u8 *p, int i);
struct UtilSlots;
extern void BTL_POKEPARAM_ClearMajorStatus(struct UtilSlots *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int func_021C5698(void *p, int v);
extern void BTL_POKEPARAM_CureSick(struct UtilSlots *p, int k);
void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out)
{
    u8 n;
    if (k != 0) {
        n = BTL_POKEPARAM_GetPokeId(a);
        if (out != 0) *out = BTL_POKEPARAM_GetSickContRaw(a, k);
        if (k < 6) {
            BTL_POKEPARAM_ClearMajorStatus((struct UtilSlots *)a);
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x10, n);
            if (func_021C5698(p + 0x1AB8, n) != 6) {
                BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x35, n, 0);
            }
        } else {
            BTL_POKEPARAM_CureSick((struct UtilSlots *)a, k);
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x11, n, (u16)k);
        }
    }
}
