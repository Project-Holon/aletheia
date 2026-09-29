/*
 * function: func_0216DD60
 * address:  0x0216DD60
 * packet:   pkt_ov010_0216DD60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Collects up to 16 matching objects into a 0x44-byte result block
 * (count word, then the pointers).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_02163C04  0x02163C04  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int n;
    u8 *e[16];
} List;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern int func_0216DD1C(u32 x, u8 **o, int *n);
extern int func_02163C04(u8 *o, u32 b, u32 c, u32 d);

int func_0216DD60(u32 x, u32 b, u32 c, u32 d, List *out)
{
    int n;
    u8 *o;

    n = 0;
    func_02082BCC(out, 0, 0x44);
    while (func_0216DD1C(x, &o, &n) == 1) {
        if (func_02163C04(o, b, c, d) == 1) {
            int i = out->n++;
            out->e[i] = o;
            if (out->n >= 16)
                break;
        }
    }
    return out->n;
}
