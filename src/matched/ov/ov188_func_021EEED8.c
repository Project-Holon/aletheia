/*
 * function: BATTLE_REC_TOOL_PackParty
 * address:  0x021EEED8
 * packet:   pkt_021EEED8
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   POKEPARTY_GetCapacity   0x0201AA14  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_GetMember   0x0201AB28  thumb
 *   BATTLE_REC_TOOL_PackMon   0x021EE920  thumb
 *
 * Clear a 0x2A4-byte record, copy the pair of counts out of a and release
 *   each of the 0x70-byte subrecords through 0x21EE920.
 */
#include "../include/Obj10803.h"


typedef unsigned int u32;

extern void MI_CpuFill8(int, int, int);
struct Mon;
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void BATTLE_REC_TOOL_PackMon(struct Mon *p, char *q);

void BATTLE_REC_TOOL_PackParty(int a, char *p)
{
    int i;
    MI_CpuFill8((int)p, 0, 0x2A4);
    if (POKEPARTY_GetCount((void *)a) == 0)
        return;
    ((struct Obj10803 *)p)->f0 = POKEPARTY_GetCapacity((void *)a);
    ((struct Obj10803 *)p)->f2 = POKEPARTY_GetCount((void *)a);
    for (i = 0; i < ((struct Obj10803 *)p)->f2; i++)
        BATTLE_REC_TOOL_PackMon((struct Mon *)((int)POKEPARTY_GetMember((void *)a, i)), p + 4 + i * 0x70);
}
