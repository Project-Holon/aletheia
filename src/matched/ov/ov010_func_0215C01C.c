/*
 * function: func_0215C01C
 * address:  0x0215C01C
 * packet:   pkt_ov010_0215C01C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

extern u16 *func_02159AE8(void *, void *);
extern int func_02159B10(void *, void *);
extern u32 func_0215B4DC(void *, int, int);
extern u16 d_02171180[];

int func_0215C01C(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int k = func_02159B10(a0, a1);
    int j = func_02159B10(a0, a1);
    u16 t = func_0215B4DC(a1, k, 0x95);

    if (t == d_02171180[j]) {
        *out = 1;
    } else {
        *out = 0;
    }
    return 0;
}
