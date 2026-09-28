/*
 * function: func_021BEA54
 * address:  0x021BEA54
 * packet:   pkt_021BEA54
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  size-exact, all 10 relocations resolved; only two instructions
 *           differ, the ldrb/cmp pair reads the byte into r0 where the
 *           original keeps it in r1.  Re-verified 2026-09-27: named u8 local,
 *           inline expression and pointer local all reproduce r0.  The image
 *           stores the loaded byte in r1, which is the coercion tell: the field
 *           is read through the pointer expression and the callee/most of the
 *           body reuses it without a fresh register, so look for the type the
 *           image declares on the operand rather than a different schedule
 *           (docs/idioms/argument-register-match-names-a-coerced-extern.md).
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045770  0x02045770  arm
 *   func_021BCF00  0x021BCF00  thumb ov210
 *   func_021BE44C  0x021BE44C  thumb ov210
 *   func_021BE49C  0x021BE49C  thumb ov210
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02043B5C(u32, u32);
extern u32  func_02045770(u32);
extern int  func_021BCF00(void *);
extern void func_021BE44C(void *, int, int, int, int, int, int);
extern void func_021BE49C(void *);

void func_021BEA54(u8 *p)
{
    u8 c;

    func_02043B5C(func_02045770(*(u32 *)(p + 0x1B4)), 0);
    func_02043B5C(func_02045770(*(u32 *)(p + 0x1BC)), 0);
    c = ((u8 *)*(u32 *)(*(u32 *)p + 8))[3];
    if (c != 0xFF)
        func_021BE44C(p, 0xD, func_021BCF00(p), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xD, 0x30, 0x30, 0, 0x3C40, 2);
    c = ((u8 *)*(u32 *)(*(u32 *)p + 8))[4];
    if (c != 0xFF)
        func_021BE44C(p, 0xE, func_021BCF00(p), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xE, 0x30, 0x30, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1B4);
    func_021BE49C(p + 0x1BC);
}
