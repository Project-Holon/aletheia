/*
 * function: initGraphics
 * address:  0x021CBCF0
 * packet:   pkt_021CBCF0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics   0x021CBCF0  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   DWCi_GXlVisible   0x021D603C  arm  ov016
 *   sSceneSetSelectApPathYbBgStep11Pltt   0x021DA7BC  data
 *   sSceneSetSelectApPathYbObjWayPltt   0x021DB708  data
 *   GX_LoadOBJPltt   0x0207E51C  data
 *   sSceneSetSelectApPathJbBgStep1Char   0x021DB71C  data
 *   GX_LoadBG2Char   0x0207F0B8  data
 *   sSceneSetSelectApPathJbBgStep1Pltt   0x021DB734  data
 *   GX_LoadBGPltt   0x0207E3D0  data
 *   sSceneSetSelectApPathJb2ApScr   0x021DB74C  data
 *   GX_LoadBG2Scr   0x0207EB78  data
 *   dat_021DE60C   0x021DE60C  data
 *
 * Copy a 0x16-byte NCL resource path into a stack buffer, load four
 * tilemaps through DWCi_CMNlLoadResource, publish the buffer through
 * DWCi_Char/DWCi_ARClReadEx into the record held by 0x021DE60C+4, poke
 * DWCi_GXlVisible, then set the low two bits of the 0x04001008 and
 * 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/initGraphics.c \
 *       --func initGraphics --addr 0x021CBCF0 --region ov016 --cc dsi/1.1p1 --arm
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

extern T22 sSceneSetSelectApPathYbBgStep11Pltt;
extern unsigned char sSceneSetSelectApPathYbObjWayPltt[];
extern unsigned char GX_LoadOBJPltt[];
extern unsigned char sSceneSetSelectApPathJbBgStep1Char[];
extern unsigned char GX_LoadBG2Char[];
extern unsigned char sSceneSetSelectApPathJbBgStep1Pltt[];
extern unsigned char GX_LoadBGPltt[];
extern unsigned char sSceneSetSelectApPathJb2ApScr[];
extern unsigned char GX_LoadBG2Scr[];
extern unsigned char dat_021DE60C[];

void initGraphics(void)
{
    T22 buf;
    u16 *p;
    int r;

    buf = sSceneSetSelectApPathYbBgStep11Pltt;
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSelectApPathYbObjWayPltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadOBJPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSelectApPathJbBgStep1Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSelectApPathJbBgStep1Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetSelectApPathJb2ApScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));

    r = (int)DWCi_ARClReadEx((char *)((int)DWCi_Char((unsigned char *)(&buf))), 0, 4);
    *(int *)(*(int *)(dat_021DE60C + 4)) = r;
    DWCi_GXlVisible(1, 0x10);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
