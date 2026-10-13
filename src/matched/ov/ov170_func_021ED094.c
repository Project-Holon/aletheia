/*
 * function: func_021ED094
 * address:  0x021ED094
 * packet:   pkt_ov170_021ED094
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020F08 0x02020F08 thumb
 *   func_02020E60 0x02020E60 thumb
 *   func_02049E34 0x02049E34 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049F34 0x02049F34 arm
 *   CLACT_GetActorPaletteIndex 0x0204B7F8 arm
 *   func_0204ADEC 0x0204ADEC arm
 */
#include "../include/Obj14276.h"


extern unsigned func_02020F08(void);
extern unsigned func_02020E60(unsigned item, unsigned which);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub0204A9D0;
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 CLACT_GetActorCharacterIndex(u8 *p);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern u16 CLACT_GetActorPaletteIndex(u8 *p);
extern void func_0204ADEC(void *dst, void *src, unsigned flag);

void func_021ED094(char *w, unsigned item)
{
    void *a;
    void *b;
    void *q;
    q = func_02049E34(func_02020F08(), func_02020E60(item, 1), 0, (u32)(&a), 0x4C);
    func_0204A9D0(CLACT_GetActorCharacterIndex(((struct Obj14276 *)w)->f9E9C), a);
    func_020307B0(q);
    q = func_02049F34(func_02020F08(), func_02020E60(item, 2), (u32)(&b), 0x4C);
    func_0204ADEC((void *)CLACT_GetActorPaletteIndex(((struct Obj14276 *)w)->f9E9C), b, 1);
    func_020307B0(q);
}
