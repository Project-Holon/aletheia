/*
 * function: func_0216DDC0
 * address: 0x0216DDC0
 * packet: pkt_ov010_0216DDC0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216DD60 0x0216DD60 thumb ov010
 */

typedef unsigned int u32;
typedef struct { int n; void *e[16]; } List;
extern int func_0216DD60(u32 a, u32 b, u32 c, u32 d, List *out);
void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d)
{
    List out;
    if (func_0216DD60(a, b, c, d, &out) != 0)
        return out.e[0];
    return 0;
}
