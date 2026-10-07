/*
 * file:     unit_021F4560_p06.c
 * unit:     yes
 * function: func_021F62A0, func_021F62B4
 * address:  0x021F62A0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F6F90   0x021F6F90  data
 */
#include "../../matched/include/G_WmBase.h"

typedef unsigned short u16;

typedef unsigned char u8;

u16 MB_GetTgid(void);
unsigned char MBi_GetAttribute(void);
extern struct WmBase d_021F6F90;


u16 MB_GetTgid(void)
{
    return *(u16 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 0xC);
}


unsigned char MBi_GetAttribute(void)
{
    char *base = *(char **)(((char *)&d_021F6F90) + 0xC);

    return (*(u16 *)(base + 0xE) ? 1 : 0) | (*(u16 *)(base + 0x12) ? 2 : 0) |
           (*(u16 *)(base + 0x14) ? 4 : 0) | (*(u16 *)(base + 0x16) ? 8 : 0);
}
