/*
 * function: func_021C1680
 * address:  0x021C1680
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Bumps the record's +0x10 counter, then selects a ceiling by the word at
 * +8 and clamps the counter to it (the ceiling is uninitialised on the
 * default path, which is how the image reads too).  Called once from
 * 0x021C1604 with only r0 live.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w0;
    u32 w4;
    u32 type;
    u32 wc;
    u32 counter;
} Rec;

void func_021C1680(Rec *p)
{
    u32 v;

    p->counter++;
    switch (p->type) {
    case 0:
        v = (u32)-1;
        break;
    case 1:
        v = 0x78;
        break;
    case 2:
        v = 0x1e;
        break;
    case 3:
        v = 0x14;
        break;
    case 4:
        v = (u32)-1;
        break;
    case 5:
        v = 0x3c;
        break;
    }
    if (v < p->counter)
        p->counter = v;
}
