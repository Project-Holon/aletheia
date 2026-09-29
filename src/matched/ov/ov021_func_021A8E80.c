/*
 * function: func_021A8E80
 * address:  0x021A8E80
 * packet:   pkt_ov021_021A8E80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_021A8E78  0x021A8E78  thumb  ov021
 *   func_021A8B84  0x021A8B84  thumb  ov021
 *   d_021D8C4C     0x021D8C4C  data  ov021  a1
 *   d_021D8B26     0x021D8B26  data  ov021  a1
 *   d_021D8B27     0x021D8B27  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct W {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20;
    u8 f21;
};

extern u8 d_021D8C4C[][8][4];
extern u8 d_021D8B26[];
extern u8 d_021D8B27[];

extern int func_021A8E78(u32 a, u32 b);
extern int func_021A8B84(u32 a);

u32 func_021A8E80(struct W *w, u32 dir)
{
    u32 idx = func_021A8E78(w->f1E, w->f1F);
    u32 r = d_021D8C4C[func_021A8B84(w->f21) - 4][idx][dir];

    if (idx != r) {
        if (r == 0xFF) {
            w->f1F = 2;
            return 1;
        }
        if (r == 0xFE) {
            w->f1F = 1;
            return 1;
        }
        if (r != 6) {
            w->f1E = d_021D8B26[r * 2];
        }
        w->f1F = d_021D8B27[r * 2];
        return 1;
    }
    return 0;
}
