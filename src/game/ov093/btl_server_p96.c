/*
 * function: func_021C9828
 * address:  0x021C9828
 * packet:   pkt_ov093_021C9828
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C9888  0x021C9888  thumb  ov093
 *   func_021C4BAC  0x021C4BAC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021C9888(u32 a, u32 i);
extern void func_021C4BAC(u8 *p, int k, int v);

static inline int test(u8 *s, u32 i)
{
    u8 idx = (i >> 3) + 1;
    u8 bit = i & 7;
    if (idx < s[4]) {
        if ((1 << bit) & s[4 + idx]) return 1;
        else return 0;
    }
    return 0;
}

int func_021C9828(void *w, u8 *s)
{
    int r = 0;
    u32 i;
    for (i = 0; i < 14; i++) {
        if (test(s, i) && func_021C9888(s[7], i)) {
            func_021C4BAC(w, i, s[7]);
            r = 1;
        }
    }
    return r;
}
