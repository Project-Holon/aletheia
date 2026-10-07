/*
 * file:     field_msgbg_p36.c
 * unit:     yes
 * function: func_0218E404, func_0218E4B0, func_0218E540
 * address:  0x0218E404
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218F1BC  0x0218F1BC  thumb  ov021
 *   func_0218F1DC  0x0218F1DC  thumb  ov021
 *   func_0218E2B4  0x0218E2B4  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_0218F004  0x0218F004  thumb  ov021
 *   func_0218E764  0x0218E764  thumb  ov021
 */
#include "../../matched/include/Obj00428.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { int x, y, z; } V;

typedef unsigned int   u32;

extern void func_0218F1BC(u32 *a, u32 b);
extern void func_0218F1DC(u32 *a, u32 b);
extern void func_0218E2B4(V *a, V *out, int i, int j, int e);
extern void func_0207C9D0(void *a, void *b, void *c);
extern void func_02048B44(int, void *);
extern void func_02048AFC(int, void *);
extern void func_0218F004(u8 *a);
extern void func_0218E764(u8 *a, void *b, void *c);
void func_0218E404(u8 *a);
void func_0218E4B0(u8 *a);
void func_0218E540(u8 *a);


/*
 * Mirror of func_0218E358 with the two halves swapped.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E404(u8 *a)
{
    int i;

    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
    func_0218E2B4((V *)(a + 0x3C), (V *)(a + 0x48), ((struct Obj00428 *)a)->f7A, ((struct Obj00428 *)a)->f78, ((struct Obj00428 *)a)->f7C);
    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
}


/*
 * Copies +0x24 to +0x3c and +0x48 to +0x54, updating the children after each.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E4B0(u8 *a)
{
    int i;

    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
}


/*
 * Builds two 12-byte vectors from matrix pairs and pushes them to the owner.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E540(u8 *a)
{
    u8 t1[12];
    u8 t0[12];

    func_0207C9D0(a + 0x54, a + 0x60, t1);
    func_0207C9D0(a + 0x3C, a + 0x30, t0);
    func_02048B44(((struct Obj00428 *)a)->fC, t1);
    func_02048AFC(((struct Obj00428 *)a)->fC, t0);
    func_0218F004(a);
    func_0218E764(a, t1, a + 0x3C);
}
