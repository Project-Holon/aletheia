/*
 * function: P_STA_SKILL_FreeStatsPage
 * address: 0x021D9D44
 * packet: pkt_ov131_021D9D44
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SKILL_FreeSlot 0x021DB9E8 thumb ov131
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj14076.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void P_STA_SKILL_FreeSlot(void *, void *, u8 *);
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
void P_STA_SKILL_FreeStatsPage(void *a, u8 *p)
{
    u8 i;
    for (i = 0; i < p[0x2b]; i++)
        P_STA_SKILL_FreeSlot(a, p, p + 0xb0 + i * 24);
    for (i = 0; i < 13; i++)
        func_020452E8(*(void **)(p + 0x5c + i * 4));
    ((struct Obj14076 *)p)->f0 = 0;
}
