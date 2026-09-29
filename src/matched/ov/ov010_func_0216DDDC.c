/*
 * function: func_0216DDDC
 * address:  0x0216DDDC
 * packet:   pkt_ov010_0216DDDC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DD60  0x0216DD60  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0209C054  0x0209C054  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef long long s64;

typedef struct {
    int n;
    u8 *e[16];
} List;

extern u32 func_0216DD60(u32 a, u32 b, u32 c, u32 d, List *out);
extern int func_0216D8AC(u8 *o);

u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d)
{
    List buf;
    u32 i;
    u32 n;

    n = func_0216DD60(a, b, c, d, &buf);
    if (n == 0)
        return 0;
    for (i = 0; i < n; i++) {
        s32 q = func_0216D8AC(buf.e[i]) - x;

        if (q < 0)
            q = (s32)(((s64)q * (s64)(s32)0xFFFFF000 + 0x800) >> 12);
        if (q < lim)
            return buf.e[i];
    }
    return 0;
}
