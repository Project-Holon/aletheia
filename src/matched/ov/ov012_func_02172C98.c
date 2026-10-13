/*
 * function: UNION_COMM_SessionStartCallback
 * address:  0x02172C98
 * packet:   pkt_ov012_02172C98
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled callback leaf (a .word run in the listing); passed as
 *           a function pointer (pool words 0x02172C74 and 0x02172E44).
 * symbols:
 *   GFL_NET_SetErrorCheckEnabled  0x0203D8C4  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void GFL_NET_SetErrorCheckEnabled(u32 a);

void UNION_COMM_SessionStartCallback(u8 *p)
{
    p[0x3560] = 2;
    GFL_NET_SetErrorCheckEnabled(0);
}
