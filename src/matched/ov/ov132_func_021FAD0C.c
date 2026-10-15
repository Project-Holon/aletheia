/*
 * function: STA_ACT_SCRIPT_AddScriptFromTable
 * address: 0x021FAD0C
 * packet: pkt_ov132_021FAD0C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_SCRIPT_AddScript 0x021FAC74 thumb ov132
 */
#include "../include/Obj10541.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *STA_ACT_SCRIPT_AddScript(char *, void *, int);
char *STA_ACT_SCRIPT_AddScriptFromTable(char *p, char *base, unsigned index, unsigned char flag)
{
    char *q = STA_ACT_SCRIPT_AddScript(p, base + *(unsigned *)(base + index * 4), 0);
    *(char * *)&((struct Obj10541 *)q)->fC = base;
    ((struct Obj10541 *)q)->f16 |= 8;
    ((struct Obj10541 *)q)->f18 = flag;
    return q;
}
