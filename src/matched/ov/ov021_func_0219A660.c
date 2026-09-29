/*
 * function: func_0219A660
 * address:  0x0219A660
 * packet:   pkt_ov021_0219A660
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0219B0C4  0x0219B0C4  thumb  ov021
 *   func_0219B200  0x0219B200  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x; u8 b; u8 pad; int n; } St;
extern int func_0216D5A8(u32);
extern int func_02164168(u32);
extern int func_0219B0C4(void);
extern int func_0219B200(u32, u32, u32);

int func_0219A660(u32 a, St *p)
{
    if (func_0216D5A8(a) == 11) {
        if (p->n != 0) {
            p->n = 0;
            return 0;
        }
        if (func_02164168(a) == 0)
            return 0;
        if (func_0219B0C4() == 0)
            return 0;
        p->n = p->n + 1;
    } else {
        if (p->n != 0) {
            if (func_0219B200(a, 0x26, 9) != 9) {
                p->b = 0;
                return 1;
            }
        }
        p->n = p->n + 1;
        if (p->n < 0x18)
            return 0;
    }
    p->b = 3;
    return 1;
}
