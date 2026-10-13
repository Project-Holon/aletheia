/*
 * function: BTL_CLIENT_SetChangeActionsFirstAble
 * address: 0x021D0BB0
 * packet: pkt_ov093_021D0BB0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_MAIN_GetViewPositionsPerClient 0x021B99C0 thumb ov093
 *   BTL_MAIN_GetSlotClientAndNth 0x021B8E28 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 */
#include "../include/Obj03198.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Q1;
struct S2;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 BTL_MAIN_GetViewPositionsPerClient(void *, int);
extern void BTL_MAIN_GetSlotClientAndNth(u8 *, u8, u8 *, u8 *);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_ACTION_SetChange(void *, u8, u8);
void BTL_CLIENT_SetChangeActionsFirstAble(u8 *p)
{
    u8 pair[2];
    u8 start;
    u8 count;
    u32 n;
    u32 i;
    u32 j;
    count = 0;
    n = BTL_SLOT_GetCount(((struct Obj03198 *)p)->f118);
    start = BTL_MAIN_GetViewPositionsPerClient(((struct Obj03198 *)p)->f0, p[0x1a6]);
    for (i = 0; i < p[0x1b3]; i++) {
        BTL_MAIN_GetSlotClientAndNth(*(u8 * *)&((struct Obj03198 *)p)->f0, p[0x1b5 + i], &pair[1], &pair[0]);
        for (j = start; j < n; j++) {
            if (!BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(((struct Obj03198 *)p)->f118, (u8)j))) {
                BTL_ACTION_SetChange(p + 0x124 + count++ * 4, pair[0], j);
                start = j + 1;
                break;
            }
        }
    }
    ((struct Obj03198 *)p)->fD8 = p + 0x124;
    ((struct Obj03198 *)p)->fDC = count * 4;
}
