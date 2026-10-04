/*
 * function: func_021F33C0
 * address: 0x021F33C0
 * packet: pkt_ov194_021F33C0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-04 wave D3 lane19: DIFF, 11 listing lines, 1 instruction. Whole function matches except case 0 tail: ours hoists the zero into r5 (movs r5,#0) and stores it with strh r5, original re-materialises movs r1,#0 right before the strh (no CSE of the zero shared with f(n,0) and f(3,0)). Tried: ternary join, duplicated arms, n=1 default form, (u16)0, 1-1, u8/u16/u32 callee second param, reordered stores. The if f118 / else n=1 / join call f(n,0) shape is needed for the movs r0,#2; b; movs r0,#1 layout.
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_02040618 0x02040618 arm
 *   func_02040588 0x02040588 arm
 *   func_021F35A8 0x021F35A8 thumb ov194
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern void func_02040804(int);
extern void func_02040618(int, int, int);
extern void func_02040588(int, int);
extern void func_021F35A8(char *, u32);
int func_021F33C0(char *p) {
    int c;
    int y;
    int n;
    if (*(u32 *)(p + 0x110) != 0)
    switch (*(u16 *)(p + 0x10c)) {
    case 0:
        func_02040804(1);
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        if ((*(u16 *)(p + 0x10a))++ > 7) {
            if (*(u32 *)(p + 0x118)) {
                func_02040588(1, 0);
                n = 2;
            } else {
                n = 1;
            }
            func_02040588(n, 0);
            func_02040588(3, 0);
            *(u16 *)(p + 0x10a) = 0;
            *(u16 *)(p + 0x10c) = 1;
        }
        break;
    case 1:
        y = -48;
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        func_021F35A8(p, *(u32 *)(p + 0x114));
        *(u16 *)(p + 0x10c) = 2;
        break;
    case 2:
        *(u16 *)(p + 0x10a) = 7;
        *(u16 *)(p + 0x10c) = 3;
        func_02040588(1, 1);
        func_02040588(3, 1);
        if (*(u32 *)(p + 0x100) != 3) func_02040588(2, 1);
        *(u16 *)0x04000052 = 1 << 12;
        break;
    case 3:
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        if ((*(u16 *)(p + 0x10a))-- == 0) *(u16 *)(p + 0x10c) = 4;
        break;
    case 4:
        func_02040618(1, 3, 0);
        func_02040618(3, 3, 0);
        func_02040618(2, 3, 0);
        *(u32 *)(p + 0x118) = 0;
        *(u16 *)0x04000050 = 0;
        *(u32 *)(p + 0x110) = 0;
        return 1;
    }
    return 0;
}
