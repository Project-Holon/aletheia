/*
 * function: FLD_VREQ_VBlank
 * address:  0x021D31AC
 * packet:   pkt_ov021_021D31AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The slot byte is func_02040588's second argument (it takes two, like every
 * other caller): passing p->slot[i] is what puts the ldrb in r1.
 *
 * symbols:
 *   sFldVReqBlendFuncs     0x021DE6AC  data  ov021  a4
 *   func_02040588  0x02040588  arm
 *   func_0207D534  0x0207D534  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 h0;
    u16 h2;
    u8 b4[0x28];
    u8 slot[8];
    u8 b34;
    u8 b35;
    signed char s36;
    signed char s37;
} Rec;

extern void (*sFldVReqBlendFuncs[])(void *, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D534(volatile u16 *reg, int brightness);

void FLD_VREQ_VBlank(Rec *p)
{
    int i;

    if (sFldVReqBlendFuncs[p->h0] != 0) {
        sFldVReqBlendFuncs[p->h0]((u8 *)p + 4, 1);
        p->h0 = 0;
    }
    if (sFldVReqBlendFuncs[p->h2] != 0) {
        sFldVReqBlendFuncs[p->h2]((u8 *)p + 0x18, 0);
        p->h2 = 0;
    }
    for (i = 0; i < 8; i++) {
        if (p->slot[i] != 0xff) {
            func_02040588((u8)i, p->slot[i]);
            p->slot[i] = 0xff;
        }
    }
    if (p->b34 != 0) {
        func_0207D534((volatile u16 *)0x0400006C, p->s36);
        p->b34 = 0;
    }
    if (p->b35 != 0) {
        func_0207D534((volatile u16 *)0x0400106C, p->s37);
        p->b35 = 0;
    }
}
