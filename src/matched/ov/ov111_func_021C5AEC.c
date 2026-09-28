/*
 * function: func_021C5AEC
 * address:  0x021C5AEC
 * packet:   pkt_ov111_021C5AEC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C59DC  0x021C59DC  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
} Info;

typedef struct {
    u8 pad0[0x28];
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x32C7 - 0x3038];
    u8 blink;
    u8 phase;
} Work;

extern void func_021C59DC(u32 bg, int mode);

void func_021C5AEC(Work *p)
{
    if (p->f3034 != 0 && p->info->f4_4) {
        p->blink++;
        if (p->blink > 20) {
            p->phase ^= 1;
            func_021C59DC(7, p->phase);
            p->blink = 0;
        }
    }
}
