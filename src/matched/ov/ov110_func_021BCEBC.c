/*
 * function: PMSIV_MENU_IsEntry0Done
 * address: 0x021BCEBC
 * packet: pkt_ov110_021BCEBC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 38-byte function followed by two zero alignment bytes.
 * lever: inline helper reuses its dying pointer for the zero/one result;
 *   zero assignment remains explicit, and the allocator shares r4.
 * symbols:
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_IsEntryFinished 0x021BCFF0 thumb ov110
 */
#include "../include/Obj06390.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern u32 PMSIV_MENU_IsEntryFinished(char *,u32);
static inline int Check(char *p, int zero)
{
    u32 value;
    value = PMSIV_MENU_IsEntryFinished(p, zero);
    p = 0;
    if (value) p = (char *)1;
    return (int)p;
}
int PMSIV_MENU_IsEntry0Done(char *p)
{
    if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) {
        return Check(p, 0);
    }
    return 1;
}
