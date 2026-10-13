/*
 * function: func_021C555C
 * address:  0x021C555C
 * packet:   pkt_ov111_021C555C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   func_021C6874  0x021C6874  thumb  ov111
 *   d_021C8544     0x021C8544  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x3034];
    u32 f3034;
    u8 pad3038[0x32E2 - 0x3038];
    s16 scroll;
    u8 pad32E4[0x32F7 - 0x32E4];
    u8 b32F7;
    u8 b32F8;
    u8 pad32F9[0x330E - 0x32F9];
    u8 b330E;
} Work;

extern int TOUCHPANEL_HitCont(const void *p);
extern void func_021C6874(Work *p, int scroll, int flush, int idx);
extern const u8 d_021C8544[];

void func_021C555C(Work *p)
{
    if (p->f3034 != 0 && TOUCHPANEL_HitCont(d_021C8544) && p->b32F7 == 1) {
        func_021C6874(p, p->scroll, 1, 0);
        p->b32F7 = 0;
        p->b32F8 = 0;
        p->b330E = 0;
    }
}
