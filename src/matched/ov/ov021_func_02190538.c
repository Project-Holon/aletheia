/*
 * function: func_02190538
 * address:  0x02190538
 * packet:   pkt_ov021_02190538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

extern void func_02045808(u32 a);

void func_02190538(Slot *s)
{
    s->f08 = 0;
    s->f0c = 0;
    func_02045808(s->f18);
    s->f18 = 0;
    s->f10 = 0;
}
