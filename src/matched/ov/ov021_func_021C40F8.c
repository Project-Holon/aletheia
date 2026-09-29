/*
 * function: func_021C40F8
 * address:  0x021C40F8
 * packet:   pkt_ov021_021C40F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * r2 is never touched before the func_02048F60 call: the function takes a
 * third parameter and forwards it as the heap argument. With two
 * parameters the table copy takes r3/r2 instead of r4/r3 (7 bytes).
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021C42F4  0x021C42F4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DA908     0x021DA908  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u32 v[4]; } T;

extern void *func_02048F60(u32 archive, u32 member, u32 heap);
extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern void func_021C42F4(u32 *p, u32 v);
extern void func_020307B0(void *p);
extern T d_021DA908;

void func_021C40F8(u32 *p, u32 *q, u32 heap)
{
    T t = d_021DA908;
    u32 *pt = t.v;
    u16 *buf = func_02048F60(0x7b, q[0], heap);
    int n = buf[0];
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = func_02017E1C(p[0], pt[i], 0);
        int j;

        for (j = 1; j <= n; j++) {
            if (v == buf[j]) {
                func_021C42F4(q, v);
                break;
            }
        }
    }
    func_020307B0(buf);
}
