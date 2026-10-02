/*
 * function: func_021EEB2C
 * address:  0x021EEB2C
 * packet:   pkt_ov093_021EEB2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EEB84  0x021EEB84  thumb  ov093
 *   func_021EEBA4  0x021EEBA4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern int func_021EEB84(W *);
extern int func_021EEBA4(W *);

int func_021EEB2C(W *p)
{
    switch (p->mode) {
    case 1:
        if (func_021EEB84(p) == 0)
            break;
        p->mode = 3;
    case 3:
        if (func_021EEBA4(p) == 0)
            break;
        p->mode = 4;
    case 4:
        return 1;
    }
    return 0;
}
