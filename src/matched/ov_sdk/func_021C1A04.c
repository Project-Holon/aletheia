/*
 * function: initGraphics
 * address:  0x021C1A04
 * packet:   pkt_021C1A04
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics   0x021C1A04  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   sSceneMenuPathYbBgStep11Pltt    0x021DA498  data
 *   sSceneMenuPathJbBgStep1Char    0x021DB270  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   sSceneMenuPathJbBgStep1Pltt    0x021DB288  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   sSceneMenuPathJb2MenuScr    0x021DB2A0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   gSceneMenuWork    0x021DE59C  data
 *
 * Copy a 0x16-byte NCL descriptor (name + two flags) from the static table to
 * a stack buffer, load three tilemaps through DWCi_CMNlLoadResource, publish the
 * buffer through DWCi_Char/DWCi_ARClReadEx into the 0x021DE59C record, then
 * set the low two bits of the 0x04001008 and 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/initGraphics.c \
 *       --func initGraphics --addr 0x021C1A04 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    char name[0x14];
    u8 f14;
    u8 f15;
} T;

extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *DWCi_Char(unsigned char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern T sSceneMenuPathYbBgStep11Pltt;
extern unsigned char sSceneMenuPathJbBgStep1Char[];
extern unsigned char GX_LoadBG2Char[];
extern unsigned char sSceneMenuPathJbBgStep1Pltt[];
extern unsigned char GX_LoadBGPltt[];
extern unsigned char sSceneMenuPathJb2MenuScr[];
extern unsigned char GX_LoadBG2Scr[];
extern unsigned char gSceneMenuWork[];

void initGraphics(void)
{
    T buf;
    u16 *p;

    buf = sSceneMenuPathYbBgStep11Pltt;
    DWCi_CMNlLoadResource((char *)((int)sSceneMenuPathJbBgStep1Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneMenuPathJbBgStep1Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneMenuPathJb2MenuScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));
    ((int *)gSceneMenuWork)[1] = (int)DWCi_ARClReadEx((char *)((int)DWCi_Char((unsigned char *)(&buf))), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
