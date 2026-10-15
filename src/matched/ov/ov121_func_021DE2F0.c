/*
 * function: MYSTERY_NET_Delete
 * address:  0x021DE2F0
 * packet:   pkt_021DE2F0
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_NET_ClearTask  0x021DEE84  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MYSTERY_NET_ClearTask(void *);
extern u32 func_020307B0(void *p);

void MYSTERY_NET_Delete(u8 *p)
{
    MYSTERY_NET_ClearTask(p);
    func_020307B0(p);
}
