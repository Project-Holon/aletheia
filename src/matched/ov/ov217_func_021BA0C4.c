/*
 * function: func_021BA0C4
 * address:  0x021BA0C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BA144  0x021BA144  thumb  ov217
 *   func_021BA150  0x021BA150  thumb  ov217
 *   func_021BA5D8  0x021BA5D8  thumb  ov217
 *   func_021BA624  0x021BA624  thumb  ov217
 *   func_021BA748  0x021BA748  thumb  ov217
 *   func_021BA7B4  0x021BA7B4  thumb  ov217
 *   func_021BA7D0  0x021BA7D0  thumb  ov217
 *   func_021BA82C  0x021BA82C  thumb  ov217
 *   func_021BA848  0x021BA848  thumb  ov217
 *   func_021BA8E0  0x021BA8E0  thumb  ov217
 *   func_021BA960  0x021BA960  thumb  ov217
 *   func_021BA9D0  0x021BA9D0  thumb  ov217
 *   func_021BAA28  0x021BAA28  thumb  ov217
 *   func_021BAAB8  0x021BAAB8  thumb  ov217
 *   func_021BAAF4  0x021BAAF4  thumb  ov217
 *   func_021BAB38  0x021BAB38  thumb  ov217
 *   func_021BAB68  0x021BAB68  thumb  ov217
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00511.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021BA144(u8 *a0, u32 a1);
extern u32 func_021BA150();
extern void func_021BA5D8(u8 *a0);
extern void func_021BA624(int *p);
extern u32 func_021BA748();
extern u32 func_021BA7B4();
extern u32 func_021BA7D0();
extern u32 func_021BA82C();
extern u32 func_021BA848();
extern void func_021BA8E0(int *p);
extern u32 func_021BA960(u32 a0);
extern u32 func_021BA9D0(u32 a0);
extern void func_021BAA28(int *p);
extern void func_021BAAB8(u8 *a0);
extern void func_021BAAF4(int *p);
extern void func_021BAB38(char *self);
extern void func_021BAB68(void);
extern void RESEARCH_COMMON_StopPaletteAnime(u32 a0);
extern void RESEARCH_COMMON_RestorePaletteAnime(u32 a0);
u32 func_021BA0C4(u32 a0)
{
    func_021BAB68();
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct Obj00511 *)((u8*)a0))->f0);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct Obj00511 *)((u8*)a0))->f0);
    func_021BAB38((char *)a0);
    func_021BAAF4((int *)a0);
    func_021BAAB8((u8 *)a0);
    func_021BAA28((int *)a0);
    func_021BA960(a0);
    func_021BA9D0(a0);
    func_021BA8E0((int *)a0);
    func_021BA848(a0);
    func_021BA82C(a0);
    func_021BA7D0(a0);
    func_021BA7B4(a0);
    func_021BA748(a0);
    func_021BA624((int *)a0);
    func_021BA5D8((u8 *)a0);
    ((struct Obj00511 *)((u8*)a0))->f88 = 1;
    func_021BA144((u8 *)a0, 6);
    return func_021BA150(a0);
}

