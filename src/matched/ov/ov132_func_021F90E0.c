/*
 * function: STA_ACTING_LoadCharAnims
 * address: 0x021F90E0
 * packet: pkt_ov132_021F90E0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_SCRIPT_AddScript 0x021FAC74 thumb ov132
 *   d_021FDBD0 0x021FDBD0 data a1
 */
#include "../include/Obj08150.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Bytes { u8 a, b, c, d; };
extern const struct Bytes d_021FDBD0;
extern void *STA_ACT_SCRIPT_AddScript(char *p, void *arg, int flag);
void STA_ACTING_LoadCharAnims(u8 *p)
{
    u8 i;
    u32 *table;
    struct Bytes order;
    table = *(u32 * *)&((struct Obj08150 *)p)->fB4;
    order = d_021FDBD0;
    STA_ACT_SCRIPT_AddScript(((struct Obj08150 *)p)->fB0, (u8 *)table + table[0], 1);
    for (i = 0; i < 4; i++) {
        if (table[0] != table[((u8 *)&order)[i]]) {
            STA_ACT_SCRIPT_AddScript(((struct Obj08150 *)p)->fB0, *(u8 * *)&((struct Obj08150 *)p)->fB4 + table[((u8 *)&order)[i]], 1);
        }
    }
}
