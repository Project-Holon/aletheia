/*
 * function: func_0215BCE8
 * address:  0x0215BCE8
 * packet:   pkt_ov010_0215BCE8
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
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_0215B4AC(void *, void *, void *);
extern u32 func_02017E1C(void *, u32, u32);

int func_0215BCE8(void *a0, void *a1)
{
    u16 *out;
    void *k;
    char *p;
    void *v;

    out = func_02159AE8(a0, a1);
    k = (char *)func_02159B10(a0, a1);
    p = (char *)func_02159B10(a0, a1);
    if (func_0215B4AC(a1, k, &v) == 1) {
        *out = func_02017E1C(v, (u32)(p + 0x36), 0);
    } else {
        *out = 0;
    }
    return 0;
}
