/*
 * function: func_021B5CE8
 * address:  0x021B5CE8
 * packet:   pkt_ov021_021B5CE8
 * region:   ov021
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
 *   func_02017E1C  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02159AE8(void *, void *);
extern u32 func_02159B10(void *, void *);
extern int func_0215B4AC(void *, int, void *);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);

int func_021B5CE8(void *a, void *b)
{
    u16 v[6];
    void *mon;
    u32 slot;
    u32 which;
    u16 *out;
    u16 sum;
    u16 max;
    u32 i;

    slot = func_02159B10(a, b);
    which = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    if (func_0215B4AC(b, slot, &mon) == 0) {
        *out = 0;
        return 0;
    }
    sum = 0;
    v[0] = func_02017E1C(mon, 0x46, 0);
    v[1] = func_02017E1C(mon, 0x47, 0);
    v[2] = func_02017E1C(mon, 0x48, 0);
    v[3] = func_02017E1C(mon, 0x49, 0);
    v[4] = func_02017E1C(mon, 0x4a, 0);
    v[5] = func_02017E1C(mon, 0x4b, 0);
    max = 0;
    for (i = 0; i < 6; i++) {
        sum += v[i];
        if (max < v[i]) {
            max = v[i];
        }
    }
    switch (which) {
    case 0:
        *out = sum;
        break;
    case 1:
        *out = max;
        break;
    case 2:
        *out = v[0];
        break;
    case 3:
        *out = v[1];
        break;
    case 4:
        *out = v[2];
        break;
    case 5:
        *out = v[3];
        break;
    case 6:
        *out = v[4];
        break;
    case 7:
        *out = v[5];
        break;
    }
    return 0;
}
