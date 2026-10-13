/*
 * function: func_021FD368
 * address: 0x021FD368
 * packet: pkt_ov135_021FD368
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FFD1C 0x021FFD1C thumb ov135
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01063.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef unsigned char  u8;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FFD1C(void *, int, int);
extern void GFL_USE_PlaySeDefaultVolume(u32);
void func_021FD368(unsigned char *p, int i)
{
    if (i != ((struct Obj01063 *)p)->fD4 && i >= 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + (i + 1) * 4 + 0xd0c)), i * 4 + 16);
        ((struct Obj01063 *)p)->f28 = 2;
        func_021F4EC0(p, 3, 17);
        ((struct Obj01063 *)p)->fD4 = i;
        func_021FFD1C(p, i, 0);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ((struct Obj01063 *)p)->f12E4 = 1;
        ((struct Obj01063 *)p)->f12FC = 1;
    }
}
