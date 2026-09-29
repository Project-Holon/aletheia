/*
 * function: func_021F4590
 * address:  0x021F4590
 * packet:   pkt_ov048_021F4590
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The one-trip outer loop survives only because its int counter is compared
 * against an unsigned (sizeof) bound: `i < 1` or an unsigned counter is
 * folded away as a single pass. Tables: d_021F4E5C = {0x0071} (u16),
 * d_021F4E5E = {6,7,8} (u8). func_02188C70 returns int (its own file); the
 * u8 local is what emits the lsls/lsrs #24.
 *
 * symbols:
 *   func_021F44B8  0x021F44B8  thumb  ov048
 *   func_02188C70  0x02188C70  thumb  ov021
 *   d_021F4E5C     0x021F4E5C  data  a2
 *   d_021F4E5E     0x021F4E5E  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_021F44B8(u8 *);
extern int func_02188C70(int, int);
extern u16 d_021F4E5C[1];
extern u8 d_021F4E5E[3];

void func_021F4590(int *p, u8 *out)
{
    int i, j, n;

    func_021F44B8(out);
    n = 0;
    for (i = 0; i < sizeof(d_021F4E5C) / sizeof(d_021F4E5C[0]); i++) {
        u16 v = d_021F4E5C[i];
        u8 r = func_02188C70(p[1], v);

        for (j = 0; j < sizeof(d_021F4E5E); j++) {
            if (r == d_021F4E5E[j]) {
                if (n >= 4)
                    break;
                ((u16 *)out)[n] = v;
                out[8 + n] = r;
                n++;
            }
        }
    }
}
