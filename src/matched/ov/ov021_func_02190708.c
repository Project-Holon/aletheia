/*
 * function: func_02190708
 * address:  0x02190708
 * packet:   pkt_ov021_02190708
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02190680  0x02190680  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

struct Obj;
extern struct Obj *func_02190680(struct Fx *a, u32 b, u16 c, u16 d, u16 e, u16 f, u16 g);

void *func_02190708(Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e)
{
    p->f06 = 0xE;
    return func_02190680(p, a, b, c, d, e, p->f06);
}
