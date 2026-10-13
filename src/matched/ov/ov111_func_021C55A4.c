/*
 * function: func_021C55A4
 * address:  0x021C55A4
 * packet:   pkt_ov111_021C55A4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_021C6874  0x021C6874  thumb  ov111
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   d_021C8544     0x021C8544  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x32E2];
    s16 scroll;
    s16 prevScroll;
    s16 grabY;
    s16 grabScroll;
    u8 pad32EA[0x32F7 - 0x32EA];
    u8 b32F7;
    u8 pad32F8[0x330D - 0x32F8];
    u8 rows;
    u8 b330E;
} Work;

extern int TOUCHPANEL_HitTrg(const void *rect);
extern int TOUCHPANEL_HitCont(const void *p);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);
extern int TOUCHPANEL_GetCont(void);
extern u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y);
extern void func_021C6874(Work *p, int scroll, int flush, int idx);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern const u8 d_021C8544[];

void func_021C55A4(Work *p)
{
    u32 x, y;
    int lim;

    if (!TOUCHPANEL_HitTrg(d_021C8544)) {
        p->b330E = 1;
    }
    if (p->b330E != 0 && !TOUCHPANEL_HitCont(d_021C8544)) {
        if (TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x, &y);
            p->grabY = y;
            p->grabScroll = p->scroll;
        }
        if (TOUCHPANEL_GetCont()) {
            TOUCHPANEL_GetPointCont(&x, &y);
            p->scroll = p->grabScroll - (p->grabY - y);
        }
        lim = -(p->rows - 4) << 4;
        if (p->scroll < lim) {
            p->scroll = lim;
        } else if (p->scroll > 0) {
            p->scroll = 0;
        }
        if (p->prevScroll != p->scroll) {
            p->b32F7 = 1;
            func_021C6874(p, p->scroll, 1, 1);
            GFL_USE_PlaySeDefaultVolume(0x645);
        }
        p->prevScroll = p->scroll;
    }
}
