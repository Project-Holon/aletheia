/*
 * file:     unit_020746C4_p10.c
 * unit:     yes
 * function: func_02074F3C, func_02074FA8, func_02075014, func_02075080
 * address:  0x02074F3C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_0207466C(u32);
struct Global;
extern struct Global *func_020742FC(void);
extern void func_02074694(u32, u32);
extern void *func_02074E9C(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void func_0207524C(u8 *p, u32 len, u32 b, u32 c);
u32 func_02074F3C(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_0207524C, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}

u32 func_02074FA8(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_0207524C, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}

extern void func_02075274(u8 *p, u32 len, u32 b, u32 c);
/*
 *           own, so the ABS32 site has no outside witness; 0x02075274 in turn
 *           cannot be filed because SND_InvalidateBankData (0x020896CC) and
 *           SND_DestroyBank (0x0208A38C) each have their only caller inside it
 */
u32 func_02075014(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_02075274, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}

extern void func_020752A4(int a, int b, int c, int d);
u32 func_02075080(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_020752A4, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}
