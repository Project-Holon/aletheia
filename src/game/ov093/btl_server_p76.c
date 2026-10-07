/*
 * file:     btl_server_p76.c
 * unit:     yes
 * function: func_021C6350, func_021C6394, func_021C63D0, func_021C6458, func_021C64B4, func_021C6564, func_021C65A8
 * address:  0x021C6350
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7A44  0x021D7A44  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021C1678  0x021C1678  thumb  ov093
 *   func_021C5540  0x021C5540  thumb  ov093
 *   func_021C16F8  0x021C16F8  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   sub_0201C1C8   0x0201C1C8  thumb
 *   sub_0201C1E8   0x0201C1E8  thumb
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021C6648  0x021C6648  thumb  ov093
 *   func_021C6658  0x021C6658  thumb  ov093
 */
#include "../../matched/include/Obj21104.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Out64B4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
    u32 w8;
    u32 wC;
    u32 w10;
};

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021D75A8(int, unsigned int);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D78AC(u32 range);
extern u32 _u32_div_f(u32, u32);
extern int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d);
extern void func_021C5540(u8 *p, u8 *a, int c);
extern void func_021C16F8(u8 *p, u8 *q, int v);
extern void func_021C8810(u8 *p);
extern u8 sub_0201C1C8(void *p);
extern int sub_0201C1E8(int a);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u16 func_021D57FC(void *p);
extern u32 func_021C6648(u8 *d);
extern u8 *func_021C6658(u8 *d, u32 i);
u8 func_021C6350(u8 *p, u8 *a);
void func_021C6394(u8 *p, u8 *a, unsigned int n);
u32 func_021C63D0(u8 *p, u8 *q);
int func_021C6458(u8 *p, u8 *a, u32 c, u32 d, u8 *e);
void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
void func_021C6564(u8 *p, u8 *a, u32 c, u32 d);
int func_021C65A8(u8 *p, u8 *a, u32 e, u8 *d);


u8 func_021C6350(u8 *p, u8 *a)
{
    u8 r;
    func_021D74F8(11357);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x11, 1);
    func_021D70F0(p, 0xF);
    r = func_021D775C(0x11);
    func_021D7540(11362);
    return r;
}

void func_021C6394(u8 *p, u8 *a, unsigned int n)
{
    func_021D74F8(11378);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(0x12, n);
    func_021D70F0(p, 0x15);
    func_021D7540(11382);
}


u32 func_021C63D0(u8 *p, u8 *q)
{
    u16 dmg;
    int r;
    int a = func_021D59B4(q, 8);
    int b = func_021D59B4(q, 9);
    int c = func_021D59B4(q, 0xF);

    dmg = func_021D7A44(0x28, a, c, b);
    dmg = _u32_div_f((100 - func_021D78AC(16)) * dmg, 100);
    if (dmg == 0) {
        dmg = 1;
    }
    r = func_021C1678(p, q, q, 0, &dmg);
    func_021C5540(p, q, dmg);
    if (r != 0) {
        func_021C16F8(p, q, r);
    }
    return dmg;
}


int func_021C6458(u8 *p, u8 *a, u32 c, u32 d, u8 *e)
{
    int r;
    int line = 11440;
    func_021C8810(e);
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, d);
    func_021D75EC(0x3F, (u32)e);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x19);
    r = func_021D775C(0x51);
    func_021D7540(line + 7);
    return r;
}


/*
 * Byte-correct except the call to the unlabelled arm9 leaf 0x0201C1E8,
 * which has no witness outside this function (evidence class: none until the
 * leaf is filed; it is Ilias's, inside a labelled arm9 region). Verified C for
 * that leaf (`one` --thumb, no --region, EXACT, 12 bytes):
 *
 *   extern u32 sub_0201BD28(void *p, u32 id);   // symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 sub_0201C1E8(void *p) { return sub_0201BD28(p, 2); }
 *
 * Once the leaf's shard exists re-run this file; it should go EXACT.
 */
void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out)
{
    int line = 11464;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x16, sub_0201C1C8((void *)q));
    func_021D75A8(0x1C, func_021D57FC(a));
    func_021D75A8(0x1A, sub_0201C1E8(q));
    func_021D75A8(0x1B, sub_0201BD28(q, 0x1B));
    func_021D7630(0x4B, 0);
    func_021D70F0(p, 0x28);
    out->h0 = q;
    out->h2 = q;
    out->b6 = func_021D775C(0x16);
    out->h4 = func_021D775C(0x1C);
    out->w8 = func_021D775C(0x1A);
    out->wC = func_021D775C(0x1B);
    out->w10 = 0;
    if (func_021D775C(0x4B) != 0) {
        out->b6 = 0x11;
    }
    func_021D7540(11493);
}


void func_021C6564(u8 *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(11508);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x22, d);
    func_021D70F0(p, 0x21);
    func_021D7540(11513);
}


int func_021C65A8(u8 *p, u8 *a, u32 e, u8 *d)
{
    u32 n;
    u32 i;
    int r;
    u16 t;
    n = func_021C6648(d);
    func_021D74F8(11533);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, e);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C6658(d, i)));
    }
    func_021D7630(0x3E, 0);
    func_021D7630(0x13, 0);
    func_021D70F0(p, 0x24);
    r = func_021D775C(0x3E);
    t = func_021D775C(0x13);
    func_021D7540(11550);
    if (t != 0) {
        **(u16 * *)&((struct Obj21104 *)p)->f4A8 = t;
    }
    return r;
}
