/*
 * function: func_0215C064
 * address:  0x0215C064
 * packet:   pkt_ov010_0215C064
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0215B4DC  0x0215B4DC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   d_02171180     0x02171180  data   ov010  a2
 *   d_0217118E     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u32 func_02017E1C(void *p, u32 id, u32 v);

int func_0215C064(void *a0, void *a1)
{
    u16 *o0 = func_02159AE8(a0, a1);
    u16 *o1 = func_02159AE8(a0, a1);
    u16 *o2 = func_02159AE8(a0, a1);
    void *v;

    if (func_0215B4AC(a1, func_02159B10(a0, a1), &v) == 1) {
        *o0 = func_02017E1C(v, 0x92, 0);
        *o1 = func_02017E1C(v, 0x93, 0);
        *o2 = func_02017E1C(v, 0x94, 0);
    } else {
        *o0 = 0;
        *o1 = 0;
        *o2 = 0;
    }
    return 0;
}
