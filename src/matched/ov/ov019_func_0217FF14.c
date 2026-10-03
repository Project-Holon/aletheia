/*
 * function: func_0217FF14
 * address:  0x0217FF14
 * packet:   pkt_ov019_0217FF14
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   d_021807AC     0x021807AC  data  ov019  a4
 *   d_021807C0     0x021807C0  data  ov019  a4
 */

typedef short s16;

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *func_02188CB4(u8 *p);
extern void func_021A3038(void *p, int *v);
extern u16 func_02188C9C(u8 *p);
extern s16 d_021807AC[][2];
extern s16 d_021807C0[][2];

int func_0217FF14(void *a)
{
    int v[3];
    s16 (*t)[2];
    int i;
    int n;

    func_021A3038(func_02188CB4(a), v);
    v[0] >>= 12;
    v[2] >>= 12;
    if (func_02188C9C(a) == 0x96) {
        t = d_021807AC;
        n = 5;
    } else {
        t = d_021807C0;
        n = 5;
    }
    for (i = 0; i < n; i++) {
        if (v[0] == t[i][0] && v[2] == t[i][1])
            return 1;
    }
    return 0;
}
