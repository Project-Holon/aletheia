/*
 * function: func_021C360C
 * address:  0x021C360C
 * packet:   pkt_ov021_021C360C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021C3670  0x021C3670  thumb  ov021
 *   func_020181F4  0x020181F4  thumb
 *   func_020180F4  0x020180F4  thumb
 *   d_021DA8C8     0x021DA8C8  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { u32 v[4]; } T4;

extern u32 func_02017E1C(void *, u32, u32);
extern int func_021C3670(void *, u32);
extern void func_020181F4(void *, u16, u8);
extern void func_020180F4(void *, u16);
extern const T4 d_021DA8C8;

void func_021C360C(void *a, u32 b)
{
    T4 t = d_021DA8C8;
    int i;

    if (b != 0 && func_021C3670(a, b) == 0) {
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(a, t.v[i], 0) == 0) {
                func_020181F4(a, b, i);
                return;
            }
        }
        func_020180F4(a, b);
    }
}
