/*
 * function: func_021BC3B0
 * address:  0x021BC3B0
 * packet:   pkt_ov093_021BC3B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB890  0x021BB890  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021BC408  0x021BC408  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021BB890(u8 *p, u8 i);
extern u32 func_021B8588(void **p);
extern int func_021BC408(u8 *p, u8 i, u32 *out);
extern void func_021CD4B0(int p, int k, u8 a, u8 b);

void func_021BC3B0(int *p)
{
    u32 i;
    u32 x;
    u32 v;

    if (p[6] == 1) {
        for (i = 0; i < 4; i++) {
            if (func_021BB890((u8 *)p[0], i) != 0) {
                if (func_021B8588((void **)p[1]) != 2)
                    v = 1;
                else
                    v = func_021BC408((u8 *)p + 0x1ab8, i, &x) + 1;
                func_021CD4B0(p[3], 0x29, i, v);
            }
        }
    }
}
