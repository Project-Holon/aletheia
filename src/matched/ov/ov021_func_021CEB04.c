/*
 * function: COMM_ENTRY_MENU_SetNameBuffer
 * address:  0x021CEB04
 * packet:   pkt_ov021_021CEB04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082D44(void *src, void *dst, int n);

void COMM_ENTRY_MENU_SetNameBuffer(u8 *p, void *src)
{
    func_02082D44(src, p + 0x494, 0x84);
    p[0x518] = 1;
}
