/*
 * function: func_021A9CAC
 * address:  0x021A9CAC
 * packet:   pkt_ov021_021A9CAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   data_021D8DCC  0x021D8DCC  data
 *   func_02017E40  0x02017E40  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_021A9DC8  0x021A9DC8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_021A9DC8(void);
extern const u8 data_021D8DCC[];

void func_021A9CAC(void *mon, void *src, int a, int b)
{
    u16 vals[3];
    int i;
    const u8 *w;
    u8 r;
    u8 acc;

    for (i = 0; i < 3; i++)
        vals[i] = func_0201AE1C(src, 0x11 + i);
    if (vals[0] == vals[1]) {
        func_02017E40(mon, 6, vals[0]);
        return;
    }
    w = &data_021D8DCC[(a + b * 2) * 3];
    r = func_021A9DC8();
    acc = 0;
    for (i = 0; i < 3; i++) {
        acc += w[i];
        if (r < acc) {
            func_02017E40(mon, 6, vals[i]);
            return;
        }
    }
}
