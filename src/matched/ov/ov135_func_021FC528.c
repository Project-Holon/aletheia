/*
 * function: WORLDTRADE_DETAIL_CreateStrings
 * address: 0x021FC528
 * packet: pkt_ov135_021FC528
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 */
#include "../include/Obj10585.h"
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void WORLDTRADE_DETAIL_CreateStrings(char *p)
{
    int i;
    ((struct Obj10585 *)p)->fB88 = STRBUF_Create(0xb4, 0x48);
    ((struct Obj10585 *)p)->fB8C = func_02045EC0(((struct Obj10585 *)p)->fB6C, 0x2d);
    for (i = 0; i < 10; i++) {
        *(void **)(p + i * 4 + 0xb90) = STRBUF_Create(0x14, 0x48);
    }
}
