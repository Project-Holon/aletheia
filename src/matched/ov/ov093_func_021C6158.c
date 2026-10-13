/*
 * function: BTL_SERVER_FLOW_ProcClientMemberChange
 * address: 0x021C6158
 * packet: pkt_ov093_021C6158
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SLOT_UpdateIllusion 0x021B9D10 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj09972.h"
typedef unsigned char u8;
struct Arr;
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern void BTL_SLOT_UpdateIllusion(char *, struct Arr *, int);
typedef unsigned int   u32;
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
void BTL_SERVER_FLOW_ProcClientMemberChange(u8 *p, u8 *a)
{
    unsigned int i;
    struct Arr *arr;
    for (i = 0; i < a[0]; i++) {
        arr = (struct Arr *)BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj09972 *)p)->f8, a[i + 1]);
        BTL_SERVER_CMD_Push(((struct Obj09972 *)p)->fC, 0x2a, a[i + 1]);
        BTL_SLOT_UpdateIllusion(*(char * *)&((struct Obj09972 *)p)->f4, arr, a[i + 1]);
    }
}
