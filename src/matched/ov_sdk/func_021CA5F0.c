/*
 * function: func_021CA5F0
 * address:  0x021CA5F0
 * packet:   pkt_021CA5F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA5F0   0x021CA5F0  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetListSavePathJbBgStep3Char    0x021DB600  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   sSceneSetListSavePathYbBgStep3Pltt    0x021DB618  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   sSceneSetListSavePathXb4NoneScr    0x021DB630  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *
 * Load three tilemaps through DWCi_CMNlLoadResource, then set the low two bits of
 * 0x04001008, 0x0400100A, 0x0400000A and 0x0400000C.
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned short sSceneSetListSavePathJbBgStep3Char[];
extern unsigned short GX_LoadBG2Char[];
extern unsigned short sSceneSetListSavePathYbBgStep3Pltt[];
extern unsigned short GX_LoadBGPltt[];
extern unsigned short sSceneSetListSavePathXb4NoneScr[];
extern unsigned short GX_LoadBG2Scr[];

void func_021CA5F0(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((int)sSceneSetListSavePathJbBgStep3Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetListSavePathYbBgStep3Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetListSavePathXb4NoneScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
