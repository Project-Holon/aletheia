/*
 * function: POKETRADE_2D_ClearSubScreen
 * address: 0x021E5D84
 * packet: pkt_ov119_021E5D84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: byte-pointer base keeps counter in r4, element base in r5.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02040618 0x02040618 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040618(u32 layer, u32 a, u32 b);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
void POKETRADE_2D_ClearSubScreen(char *p)
{
    unsigned i;
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_02040618(6, 0, 0);
    if (*(int *)&((struct Obj00001 *)p)->fF04) CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04, 1);
    if (((struct Obj00001 *)p)->fF18) CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00001 *)p)->fF18, 1);
    for (i = 0; i < 26; i++) {
        if (*(int *)(p + i * 4 + 0x750)) {
            BMP_WIN_ClearScreen((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            func_0201F7A8((void *)(*(int *)(p + i * 4 + 0x750)), 2);
            BMP_WIN_Delete((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            *(int *)(p + i * 4 + 0x750) = 0;
        }
    }
    func_02041B6C(6);
}
