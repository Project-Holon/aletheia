/*
 * function: func_021C71F0
 * address:  0x021C71F0
 * packet:   pkt_021C71F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C71F0   0x021C71F0  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetEditAddressPathYbObjKbPltt    0x021DB4F4  data
 *   GX_LoadOBJPltt    0x0207E51C  data
 *   sSceneSetEditAddressPathJbBgStep3Char    0x021DB508  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   sSceneSetEditAddressPathYbBgStep3Pltt    0x021DB520  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   sSceneSetEditAddressPathXb4EditAddrScr    0x021DB538  data
 *   GX_LoadBG2Scr    0x0207EB78  data

 *
 * Load 4 tilemaps through DWCi_CMNlLoadResource, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned short sSceneSetEditAddressPathYbObjKbPltt[];
extern unsigned short GX_LoadOBJPltt[];
extern unsigned short sSceneSetEditAddressPathJbBgStep3Char[];
extern unsigned short GX_LoadBG2Char[];
extern unsigned short sSceneSetEditAddressPathYbBgStep3Pltt[];
extern unsigned short GX_LoadBGPltt[];
extern unsigned short sSceneSetEditAddressPathXb4EditAddrScr[];
extern unsigned short GX_LoadBG2Scr[];

void func_021C71F0(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((int)sSceneSetEditAddressPathYbObjKbPltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadOBJPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetEditAddressPathJbBgStep3Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetEditAddressPathYbBgStep3Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetEditAddressPathXb4EditAddrScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));
    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 2;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
