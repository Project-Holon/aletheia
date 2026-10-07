/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3D98, func_021F3DAC, func_021F3DB8, func_021F3DE4, func_021F3E04, func_021F3E24
 * address:  0x021F3D98
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F36F0 0x021F36F0 thumb ov039
 *   d_021F4C0C    0x021F4C0C data ov039 a1
 *   func_021BE4C4 0x021BE4C4 thumb ov021
 *   func_02047828 0x02047828 arm
 *   func_0204784C 0x0204784C arm
 *   func_021F3E70  0x021F3E70  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 */
struct AnmCtl;
struct Ctx;
struct Big;
struct Desc;
struct Rec94;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern u8 func_021F36F0(u8 *p, int i);
extern int func_021BE4C4(void *p, u32 i, int delta);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3E70(int a0, int *a1);
u8 func_021F3D98(u8 *p, int i);
unsigned char func_021F3DAC(int i);
int func_021F3DB8(signed char *p, int i);
int func_021F3DE4(void *p, u16 delta, u16 i);
void func_021F3E04(void *p, u8 delta, u16 i, int frame);
int func_021F3E24(void *a, u32 b);
extern unsigned char d_021F4C0C[];

u8 func_021F3D98(u8 *p, int i) { return func_021F36F0(p, func_021F3DAC(i)); }


unsigned char func_021F3DAC(int i)
{
    return d_021F4C0C[i];
}

int func_021F3DB8(signed char *p, int i) { int v; v = *(p + func_021F3DAC(i) + 0x21f0); if (v == -1) return 0; return v == i; }

int func_021F3DE4(void *p, u16 delta, u16 i) { int v = 0; func_02047828((struct AnmCtl *)func_021BE4C4(p, 0, delta), i, &v); return v; }

void func_021F3E04(void *p, u8 delta, u16 i, int frame) { func_0204784C((struct AnmCtl *)func_021BE4C4(p, 0, delta), i, &frame); }


int func_021F3E24(void *a, u32 b)
{
    void *s;
    u8 *p;
    int r;

    s = func_0201210C((void *)a);
    func_02188D2C(s);
    p = (u8 *)func_021897BC(s, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 2);
    if (b >= 4) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, func_021F3E70, 0);
    p[5] = b;
    return r;
}
