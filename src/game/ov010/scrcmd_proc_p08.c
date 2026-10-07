/*
 * file:     scrcmd_proc_p08.c
 * unit:     yes
 * function: func_0215C7E0, func_0215C870
 * address:  0x0215C7E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02014840  0x02014840  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215C7C4  0x0215C7C4  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   ov136_id       0x00000088  data
 *   d_021C78A4     0x021C78A4  data  ov136  a1
 *   func_020307B0  0x020307B0  arm
 *   func_0216F940  0x0216F940  thumb  ov010
 */
#include "../../matched/include/Obj04131.h"

struct Ctx;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0215897C(void *p, void *v);
extern void func_0215C7C4(struct Rec *r);
extern int func_020307B0();
extern int func_0216F940();
int func_0215C7E0(void *c, void *vm);
int func_0215C870(int a0, int a1);
extern const char d_021728F0[];
extern const u8 d_021C78A4[];
extern u8 ov136_id[];


/*
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the func_0215C7C4 callback and
 * parks the result in the script's slot.
 *
 * 2026-10-05 (wave D9): EXACT. d_021C78A4 resolves once its symbols line carries the ov136 token (the overlay the function loads); func_0215C7C4 has its own witness.
 */
int func_0215C7E0(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 *a;
    u32 *b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = func_02030734(4, 8, 0, d_021728F0, 0x14F);
    b = func_02030734(4, 8, 0, d_021728F0, 0x150);
    a[0] = (u32)w;
    b[0] = (u32)a;
    b[1] = (u32)func_02159AE8(c, vm);
    func_0215897C(slot, func_02014840(sys, (int)x, (u32)ov136_id, (int)d_021C78A4, (int)a, (int)((void *)func_0215C7C4), (int)b));
    return 1;
}


int func_0215C870(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj04131 *)((char *)t4))->f0;
a0 = ((struct Obj04131 *)a0)->f1A;
    if (a0 == 0) goto loc_0215C880;
loc_0215C87C:
    if (a0 == 1) goto loc_0215C884;
loc_0215C880:
a1 = 0;
    goto loc_0215C886;
loc_0215C884:
a1 = 1;
loc_0215C886:
a0 = ((struct Obj04131 *)t4)->f4;
*(u16 *)&((struct Obj04131 *)((char *)a0))->f0 = a1;
a0 = ((struct Obj04131 *)((char *)t4))->f0;
a0 = ((struct Obj04131 *)a0)->f10;
    a0 = func_020307B0(a0);
loc_0215C892:
a0 = ((struct Obj04131 *)((char *)t4))->f0;
    a0 = func_0216F940(a0);
loc_0215C898:
    return a0;}
