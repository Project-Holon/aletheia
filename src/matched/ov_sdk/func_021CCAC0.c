/*
 * function: func_021CCAC0
 * address:  0x021CCAC0
 * packet:   pkt_021CCAC0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CCAC0   0x021CCAC0  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   sSceneSetSelectWayPathYbBgStep21Pltt   0x021DA800  data
 *   sSceneSetSelectWayPathJbBgStep2Char   0x021DB778  data
 *   GX_LoadBG2Char   0x0207F0B8  data
 *   sSceneSetSelectWayPathYbBgStep2Pltt   0x021DB790  data
 *   GX_LoadBGPltt   0x0207E3D0  data
 *   sSceneSetSelectWayPathJb3WayScr   0x021DB7A8  data
 *   GX_LoadBG2Scr   0x0207EB78  data
 *   gFocusState   0x021DE614  data
 *   DWCi_GXlVisible  0x021D603C  arm
 *
 * Copy a 0x16-byte NCL resource path from the static table into a stack
 * buffer, load three tilemaps through DWCi_CMNlLoadResource, publish the buffer
 * through DWCi_Char/DWCi_ARClReadEx into the 0x021DE614 record, then set
 * the low two bits of the 0x04001008 and 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CCAC0.c \
 *       --func func_021CCAC0 --addr 0x021CCAC0 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    char name[0x14];
    u8 f14;
    u8 f15;
} T22;

extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *DWCi_Char(unsigned char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void DWCi_GXlVisible(int lcd, int plane);

extern T22 sSceneSetSelectWayPathYbBgStep21Pltt;
extern unsigned char sSceneSetSelectWayPathJbBgStep2Char[];
extern unsigned char GX_LoadBG2Char[];
extern unsigned char sSceneSetSelectWayPathYbBgStep2Pltt[];
extern unsigned char GX_LoadBGPltt[];
extern unsigned char sSceneSetSelectWayPathJb3WayScr[];
extern unsigned char GX_LoadBG2Scr[];
extern unsigned char gFocusState[];

void func_021CCAC0(void)
{
    T22 buf;
    u16 *p;

    buf = sSceneSetSelectWayPathYbBgStep21Pltt;
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSelectWayPathJbBgStep2Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSelectWayPathYbBgStep2Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSelectWayPathJb3WayScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));
    ((int *)gFocusState)[1] = (int)DWCi_ARClReadEx((char *)((int)DWCi_Char((unsigned char *)(&buf))), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
