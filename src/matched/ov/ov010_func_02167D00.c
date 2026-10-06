/*
 * function: func_02167D00
 * address:  0x02167D00
 * packet:   pkt_ov010_02167D00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[0x724];
    u8 b724;
    u8 b725;
    u8 pad726[2];
    u16 h728;
} Obj;

extern u32 func_0200FB24(void);

int func_02167D00(Obj *o, u16 *out)
{
    int want;

    if (func_0200FB24() != 0)
        return 1;
    want = 1;
    if (o->b725 != 1)
        want = 2;
    if (o->b724 == want) {
        o->b724 = 0;
        if (out != 0)
            *out = o->h728;
        return 1;
    }
    return 0;
}
