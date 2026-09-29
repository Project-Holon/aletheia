/*
 * function: func_021C4238
 * address:  0x021C4238
 * packet:   pkt_ov021_021C4238
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020212B0  0x020212B0  thumb
 *   func_021C447C  0x021C447C  thumb  ov021
 *   func_021C42F4  0x021C42F4  thumb  ov021
 *   d_021DA8E8     0x021DA8E8  data  ov021  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u32 v[4]; } T;

extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern u32 func_020212B0(u16 a);
extern int func_021C447C(u32 *c, u16 a, u16 b, u16 d);
extern void func_021C42F4(u32 *p, u32 v);
extern T d_021DA8E8;

void func_021C4238(u32 *a, u32 *b, u32 *c)
{
    T t = d_021DA8E8;
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = func_02017E1C(a[0], t.v[i], 0);
        int k;

        for (k = 0x148; k <= 0x272; k++) {
            if (v == func_020212B0(k)) {
                if (func_021C447C(c, b[0], b[1], k)) {
                    func_021C42F4(b, v);
                    break;
                }
            }
        }
    }
}
