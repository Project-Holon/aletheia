/*
 * function: SHINKA_DEMO_GRAPHIC_SetupSubBg
 * address:  0x02205A34
 * packet:   pkt_02205A34
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208CA0 0x02208CA0 data a4
 *   d_02208D1C 0x02208D1C data a4
 *   func_0203FC6C 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *
 * The `(int)i` cast on the id read (permuter, seed 6401) keeps the id load
 * and the element address separate values, so `adds r6, r7, r0` is emitted
 * inside the guarded block instead of hoisted above the `cmp`.
 */

#include "../include/G_02208D1C.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 id;
    u8 data[0x20];
    u32 len;
    u32 mode;
} Entry;

extern u8 d_02208CA0[];
extern struct G_02208D1C d_02208D1C[];
struct BgTemplate;
struct BgVramReq;
extern void func_0203FC6C(const struct BgVramReq *req, u32 which);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);

void SHINKA_DEMO_GRAPHIC_SetupSubBg(void)
{
    u32 i;

    func_0203FC6C((const struct BgVramReq *)d_02208CA0, (int)1);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v >= 4) {
            Entry *e = &((Entry *)d_02208D1C)[i];
            BG_SYS_InitBgLayer((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            func_020414AC(v);
            func_02040588(v, e->mode);
        }
    }
}
