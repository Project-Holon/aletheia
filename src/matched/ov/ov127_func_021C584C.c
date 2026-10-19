/*
 * function: WF2DMAP_OBJDRAW_SetSubActorDrawEnable
 * address:  0x021C584C
 * packet:   pkt_ov127_021C584C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 8-byte ov127 accessor veneer in a .word run (0x021C5834,
 * 0x021C5840, 0x021C584C, 0x021C5858 are four in a row): `ldr r0,[r0,#0];
 * ldr r3,=WIFI_2DCHAR_SetSubActorDrawEnable; bx r3`.  Blocker target of src/pending/
 * ov099_func_021B98E4.c.
 *
 * symbols:
 *   WIFI_2DCHAR_SetSubActorDrawEnable  0x021C424C  thumb  ov127
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23051.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void WIFI_2DCHAR_SetSubActorDrawEnable(char *p, int a);

void WF2DMAP_OBJDRAW_SetSubActorDrawEnable(u8 *p, int a)
{
    WIFI_2DCHAR_SetSubActorDrawEnable(*(char * *)&((struct Obj23051 *)p)->f4, a);
}
