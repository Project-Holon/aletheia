/*
 * function: func_021CB7EC
 * address:  0x021CB7EC
 * packet:   pkt_021CB7EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CB7EC   0x021CB7EC  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetSearchPathJbBgStep3Char    0x021DB6C4  data
 *   sSceneSetSearchPathYbBgStep3Pltt    0x021DB6DC  data
 *   sSceneSetSearchPathXb4MultiScr    0x021DB6F4  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *
 * Load three tilemaps through DWCi_CMNlLoadResource, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned short sSceneSetSearchPathJbBgStep3Char[];
extern unsigned short sSceneSetSearchPathYbBgStep3Pltt[];
extern unsigned short sSceneSetSearchPathXb4MultiScr[];
extern unsigned short GX_LoadBG2Char[];
extern unsigned short GX_LoadBGPltt[];
extern unsigned short GX_LoadBG2Scr[];

void func_021CB7EC(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((int)sSceneSetSearchPathJbBgStep3Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSearchPathYbBgStep3Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSearchPathXb4MultiScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
