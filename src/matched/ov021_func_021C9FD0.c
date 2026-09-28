/*
 * function: func_021C9FD0
 * address:  0x021C9FD0
 * packet:   pkt_ov021_021C9FD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Latches bit 0 of +0xc once the +0x70 object's count reaches 7.
 *
 * symbols:
 *   func_0200DA54  0x0200DA54  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 done : 1;
    u16 rest : 15;
} Latch;

extern u32 func_0200DA54(u32 h);

int func_021C9FD0(u8 *p)
{
    if (((Latch *)p)->done == 0) {
        if (func_0200DA54(*(u32 *)(p + 0x70)) < 7)
            return 0;
        ((Latch *)p)->done = 1;
    }
    return 1;
}
