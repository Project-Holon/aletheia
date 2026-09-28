/*
 * function: func_021C983C
 * address:  0x021C983C
 * packet:   pkt_ov212_021C983C
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0204A39C  0x0204A39C  arm
 *   g_021C99A8     0x021C99A8  data
 *   g_021C9968     0x021C9968  data
 */
typedef unsigned short u16;

extern u16 *func_02030734(int heap, int size, int align, const char *file, int line);
extern unsigned int func_0204A39C(int a, int b, int c, int d, unsigned int *e);
extern const char g_021C99A8[];
extern int g_021C9968[];

unsigned int func_021C983C(int a0, int a1, int a2, int a3, u16 **out)
{
    u16 *buf;
    unsigned int n;

    if (a1 == 0 && a2 == 0) {
        u16 i;
        buf = func_02030734(a3, 0x512, 0, g_021C99A8, 0x3B1);
        for (i = 0; i < 0x289;) {
            buf[i] = i + 1;
            i++;
        }
        n = 0x289;
    } else {
        unsigned int tmp;
        buf = (u16 *)func_0204A39C(a0, g_021C9968[a2], 0, a3, &tmp);
        n = (tmp >> 1) & 0xFFFF;
    }
    *out = buf;
    return n;
}
