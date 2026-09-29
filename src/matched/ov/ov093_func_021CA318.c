/*
 * function: func_021CA318
 * address:  0x021CA318
 * packet:   pkt_ov093_021CA318
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C3810  0x021C3810  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Q {
    u32 a : 8;
    u32 b : 5;
    u32 c : 19;
    u16 e;
    u8 f;
    u8 lo : 4;
    u8 hi : 4;
};

extern int func_021B9934(char *p, int i);
extern int func_021C3810(u8 *p, int a, int b, int c, int *out, int e, int hi, void *q8);

u8 func_021CA318(u8 *p, const struct Q *q)
{
    int out[1];
    int a = func_021B9934(*(char **)(p + 8), q->f);
    int b = func_021B9934(*(char **)(p + 8), (u8)q->b);
    if (func_021C3810(p, b, a, q->lo, out, q->e, q->hi, (u8 *)q + 8)) return 1;
    return 0;
}
