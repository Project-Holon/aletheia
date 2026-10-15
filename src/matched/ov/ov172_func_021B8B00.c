/*
 * function: CTVT_COMM_ClaimSlot
 * address:  0x021B8B00
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Claims the +0x68 slot of record i and releases the +0x3dc block once.
 *
 * symbols:
 *   COMM_TVT_SYS_ClearNameWindows  0x021BE1A4  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24087.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void COMM_TVT_SYS_ClearNameWindows(char *p);

void CTVT_COMM_ClaimSlot(int i, void *a, void *b, char *q)
{
    u32 *p = (u32 *)(q + 0x68) + (i << 4);

    if (*p == 0) {
        *p = 1;
        COMM_TVT_SYS_ClearNameWindows(*(char * *)&((struct Obj24087 *)q)->f3DC);
    }
}
