/*
 * function: func_0215C0D0
 * address:  0x0215C0D0
 * packet:   pkt_ov010_0215C0D0
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

extern int func_02159B10(void *, void *);
extern int func_0215B4AC(void *, int, void *);
extern void func_02017E40(void *, int, int);
extern void func_020185C4(void *);
extern struct { u16 a; u16 b; } d_0217118E[6];

int func_0215C0D0(void *a0, void *a1)
{
    int k = func_02159B10(a0, a1);
    u32 x = func_02159B10(a0, a1);
    u32 y = func_02159B10(a0, a1);
    void *v;
    u32 i;

    for (i = 0; i < 6; i++) {
        if (x == d_0217118E[i].a) {
            if (y <= d_0217118E[i].b && func_0215B4AC(a1, k, &v) == 1) {
                func_02017E40(v, x, y);
                func_020185C4(v);
            }
            return 0;
        }
    }
    return 0;
}
