/*
 * function: func_021C4590
 * address:  0x021C4590
 * packet:   pkt_ov136_021C4590
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4590 0x021C4590 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32 a);
int func_021C4590(u8 *p)
{
    if (func_020362DC()) {
        p[0xA] = 1;
    } else if (func_02035C60()) {
        p[0xA] = 0;
    } else {
        return 0;
    }
    func_020061E4(0x54E);
    return 1;
}
