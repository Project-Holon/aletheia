/*
 * file:     field_fog_p14.c
 * unit:     yes
 * function: func_021A065C, func_021A066C, func_021A0734, func_021A0748
 * address:  0x021A065C
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
 *   func_021A0CE4 0x021A0CE4 thumb ov021
 *   func_02048CA4  0x02048CA4  arm
 *   func_02048CDC  0x02048CDC  arm
 *   func_0206AA8C  0x0206AA8C  arm
 *   func_0206AAB0  0x0206AAB0  arm
 *   func_021A01C4  0x021A01C4  thumb  ov021
 *   func_0207DD24  0x0207DD24  arm
 *   func_020490A8  0x020490A8  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_0207CDB8  0x0207CDB8  arm
 */
#include "../../matched/include/Obj19696.h"
#include "../../matched/include/Obj12699.h"

struct LightSlot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 x, y, z;
} V3s;

typedef struct {
    u8 pad[0x35A];
    u8 used[4];
    u16 c[4];
    V3s b[4];
    u16 f37E;
    u16 f380;
    u16 f382;
    u16 f384;
    u16 f386;
    u16 f388;
    u16 active;
} W;

typedef signed short   s16;

typedef signed int     s32;

extern int func_021A0CE4(u16 *p);
extern void func_02048CA4(u32, u8, const V3s *);
extern void func_02048CDC(struct LightSlot *slots, u32 i, u16 *in);
extern void func_0206AA8C(u32 v, u32 bits, u32 flag);
extern void func_0206AAB0(u32 v, u32 bits, u32 flag);
extern int func_021A01C4(u32 a, u32 b);
extern void func_0207DD24(u16, int, int, int, int);
extern u32 func_020490A8(u32 b, u32 c);
extern void func_02048F4C(void *a, u32 b, u32 c);
extern void func_0207CDB8(void *a, void *b);
int func_021A065C(u8 *p);
void func_021A066C(const W *w, u32 a, u32 p);
void func_021A0734(u8 *a, u32 b);
void func_021A0748(u8 *a, u32 b, u32 c);


/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
int func_021A065C(u8 *p)
{
    return func_021A0CE4((u16 *)(p + 0x484));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A066C(const W *w, u32 a, u32 p)
{
    int i;
    V3s zb = {0, 0, 0};
    u16 zc = 0;

    if (w->active == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (w->used[i]) {
            func_02048CA4(p, i, &w->b[i]);
            func_02048CDC((struct LightSlot *)p, (u8)i, (u16 *)(&w->c[i]));
        } else {
            func_02048CA4(p, i, &zb);
            func_02048CDC((struct LightSlot *)p, (u8)i, &zc);
        }
    }
    func_0206AA8C(w->f37E, w->f380, 1);
    func_0206AAB0(w->f382, w->f384, 0);
    func_021A01C4(a, w->f386);
    func_0207DD24(w->f388, 0x1F, 0x7FFF, 0, 0);
}


void func_021A0734(u8 *a, u32 b)
{
    ((struct Obj19696 *)a)->f354 = b;
    func_021A0748(a, 0x3d, b);
}


void func_021A0748(u8 *a, u32 b, u32 c)
{
    u32 i;
    s32 j;
    u8 *q;

    ((struct Obj12699 *)a)->fC = func_020490A8(b, c) / 0x34;
    func_02048F4C(a + 0x10, b, c);
    for (i = 0; i < ((struct Obj12699 *)a)->fC; i++) {
        q = a + 0x20 + i * 0x34;
        for (j = 0; j < 4; j++) {
            func_0207CDB8(q + j * 6, q + j * 6);
        }
    }
}
