/*
 * function: func_021D3E70
 * address:  0x021D3E70
 * packet:   pkt_ov093_021D3E70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021EFF94  0x021EFF94  data  ov093  a1
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021D5F14  0x021D5F14  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 a;
    u8 b;
} Pair;

extern Pair d_021EFF94[];
typedef signed char    s8;
struct UtilWork;
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u8 func_021D5F14(struct UtilWork *p);

int func_021D3E70(void *s, void *m)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (func_021D805C(s, d_021EFF94[i].a) != 0 && func_021D5D14(m, d_021EFF94[i].b, 1) != 0)
            return 1;
    }
    if (func_021D805C(s, 0x24) != 0 && func_021D5F14(m) == 0)
        return 1;
    return 0;
}
