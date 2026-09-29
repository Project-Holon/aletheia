/*
 * function: func_021BAB04
 * address:  0x021BAB04
 * packet:   pkt_ov070_021BAB04
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocked: every concrete byte matches; the one wildcard is the bl at +0x0E to
 * func_0201C1E8, an arm9 unlabelled leaf (Ilias's) between unit_0201C1C8 and
 * unit_0201C1F4 with no label and no matched entry; its other caller
 * (src/pending/ov/ov070_func_021B97E8.c) is itself MATCH on the same leaf.
 * Unblocks once the leaf is filed.
 * blocker:
 *   func_0201C1E8  0x0201C1E8  thumb  (arm9; `one --thumb`, no region: EXACT)
 *     extern int func_0201BD28(int, int);   // symbols: func_0201BD28 0x0201BD28 thumb
 *     int func_0201C1E8(int a) { return func_0201BD28(a, 2); }
 *
 * Levers: a byte-pointer object and the window address bound to a local
 * (win = p + 0x734) before the first statement; that makes 0x734 the pooled
 * constant every other offset (0x6C0, 0x6CC) is derived from.
 *
 * symbols:
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_0201C1C8  0x0201C1C8  thumb
 *   func_0201C158  0x0201C158  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   func_0201C1F4  0x0201C1F4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_021BB724  0x021BB724  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern int func_0201C1E8(u16);
extern int func_0201C1C8(u16);
extern int func_0201C158(u16, int);
extern int func_0201BD28(u16, int);
extern int func_0201C1F4(u16);
extern void func_0204B3DC(int, int);
extern int func_02045770(int);
extern void func_02043AF4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02045CAC(int, int, int);
extern void func_0201EFA4(int, int, int, int, int, int);
extern void func_0201F250(int, int, int);
extern void func_021BB6E0(u8 *p, u8 *obj, int str, u16 x, s16 y, u16 color);
extern void func_021BB724(u8 *);

void func_021BAB04(u8 *p, int x)
{
    int a;
    int b;
    int c;
    u8 *win;

    win = p + 0x734;

    func_0204B3DC(*(int *)(p + func_0201C1E8(x) * 4 + 0x6C0), 1);
    func_0204B3DC(*(int *)(p + func_0201C1C8(x) * 4 + 0x6CC), 1);
    a = func_0201C158(x, 0);
    b = func_0201BD28(x, 3);
    c = func_0201BD28(x, 4);
    func_02043AF4(func_02045770(*(int *)win), 0xB0, 0, 0x20, 0x28, 0);
    func_02043AF4(func_02045770(*(int *)win), 0xE8, 0, 0x18, 0x18, 0);
    if (b <= 1) {
        func_02045CAC(*(int *)(p + 0x51C), 0x17, *(int *)(p + 0x524));
        func_021BB6E0(p, win, *(int *)(p + 0x524), 0xB0, 4, 0x3DC0);
    } else {
        func_02045CAC(*(int *)(p + 0x51C), 0x5F, *(int *)(p + 0x524));
        func_0201EFA4(*(int *)(p + 0x520), 0, b, 3, 0, 1);
        func_0201F250(*(int *)(p + 0x520), *(int *)(p + 0x528), *(int *)(p + 0x524));
        func_021BB6E0(p, win, *(int *)(p + 0x528), 0xB0, 4, 0x3DC0);
    }
    if (c == 0 || func_0201C1F4(x) == 1) {
        func_02045CAC(*(int *)(p + 0x51C), 0x17, *(int *)(p + 0x524));
        func_021BB6E0(p, win, *(int *)(p + 0x524), 0xB0, 0x18, 0x3DC0);
    } else {
        func_02045CAC(*(int *)(p + 0x51C), 0x5F, *(int *)(p + 0x524));
        func_0201EFA4(*(int *)(p + 0x520), 0, c, 3, 0, 1);
        func_0201F250(*(int *)(p + 0x520), *(int *)(p + 0x528), *(int *)(p + 0x524));
        func_021BB6E0(p, win, *(int *)(p + 0x528), 0xB0, 0x18, 0x3DC0);
    }
    func_02045CAC(*(int *)(p + 0x51C), 0x5E, *(int *)(p + 0x524));
    func_0201EFA4(*(int *)(p + 0x520), 0, a, 2, 0, 1);
    func_0201F250(*(int *)(p + 0x520), *(int *)(p + 0x528), *(int *)(p + 0x524));
    func_021BB6E0(p, win, *(int *)(p + 0x528), 0xE8, 4, 0x3DC0);
    func_021BB724(win);
}
