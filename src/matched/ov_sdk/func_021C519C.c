/*
 * function: func_021C519C
 * address:  0x021C519C
 * packet:   pkt_021C519C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C519C   0x021C519C  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   DWCi_SCREENlInit   0x021CE668  arm  ov016
 *   DWCi_SCREENlRenew   0x021CE6F0  arm  ov016
 *   sSceneSetApListPathXb4ApListBackScr   0x021DA58C  data
 *   sSceneSetApListPathYbBgStep31Pltt   0x021DA574  data
 *   sSceneSetApListPathJb4ApListScr   0x021DB438  data
 *   GX_LoadBG3Scr   0x0207ECF0  data
 *   gSceneSetApListWork   0x021DE5D8  data
 *
 * Copy a 0x19-byte and a 0x16-byte NCL resource path into two stack buffers
 * (the first copy is odd-sized, so it ends with a trailing byte), load one
 * tilemap through DWCi_CMNlLoadResource, publish both buffers through
 * DWCi_Char/DWCi_ARClReadEx into the record held by 0x021DE5D8+4, poke
 * DWCi_SCREENlInit/DWCi_SCREENlRenew on it, then set the low two bits of the
 * 0x04001008 pair, 0x04000008 and the 0x0400000A triple.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C519C.c \
 *       --func func_021C519C --addr 0x021C519C --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { char s[0x19]; } T25;
typedef struct { char s[0x17]; } T23;
typedef struct { char s[0x16]; } T22;
typedef struct { char s[0x15]; } T21;

extern void DWCi_CMNlLoadResource(int, int);
extern int DWCi_Char(void *);
extern int DWCi_ARClReadEx(int, int, int);

extern T25 sSceneSetApListPathXb4ApListBackScr;
extern T22 sSceneSetApListPathYbBgStep31Pltt;
extern unsigned char sSceneSetApListPathJb4ApListScr[];
extern unsigned char GX_LoadBG3Scr[];
extern unsigned char gSceneSetApListWork[];

void func_021C519C(void)
{
    T25 buf2;
    T22 buf;
    u16 *p;

    buf2 = sSceneSetApListPathXb4ApListBackScr;
    buf = sSceneSetApListPathYbBgStep31Pltt;
    DWCi_CMNlLoadResource((int)sSceneSetApListPathJb4ApListScr, (int)GX_LoadBG3Scr);

    (*(int **)(gSceneSetApListWork + 4))[1] = DWCi_ARClReadEx(DWCi_Char(&buf2), 0, 4);
    DWCi_SCREENlInit((*(int **)(gSceneSetApListWork + 4))[1]);
    DWCi_SCREENlRenew();
    (*(int **)(gSceneSetApListWork + 4))[2] = DWCi_ARClReadEx(DWCi_Char(&buf), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 2;
    p[1] = (p[1] & ~3) | 3;
    p[2] = (p[2] & ~3) | 2;
}
