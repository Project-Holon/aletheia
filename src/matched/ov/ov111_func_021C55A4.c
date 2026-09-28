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
 *   func_02035C08  0x02035C08  arm
 *   func_02035BA4  0x02035BA4  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02035D20  0x02035D20  arm
 *   func_02035C38  0x02035C38  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021C6874  0x021C6874  thumb  ov111
 *   func_020061E4  0x020061E4  thumb
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

extern int func_02035C08(const void *rect);
extern u32 func_02035BA4(const void *rect);
extern u32 func_02035C60(void);
extern u32 func_02035D20(u32 *x, u32 *y);
extern u32 func_02035C38(void);
extern u32 func_02035CB8(u32 *x, u32 *y);
extern void func_021C6874(Work *p, int scroll, int flush, int idx);
extern void func_020061E4(int se);
extern const u8 d_021C8544[];

void func_021C55A4(Work *p)
{
    u32 x, y;
    int lim;

    if (!func_02035C08(d_021C8544)) {
        p->b330E = 1;
    }
    if (p->b330E != 0 && !func_02035BA4(d_021C8544)) {
        if (func_02035C60()) {
            func_02035D20(&x, &y);
            p->grabY = y;
            p->grabScroll = p->scroll;
        }
        if (func_02035C38()) {
            func_02035CB8(&x, &y);
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
            func_020061E4(0x645);
        }
        p->prevScroll = p->scroll;
    }
}
