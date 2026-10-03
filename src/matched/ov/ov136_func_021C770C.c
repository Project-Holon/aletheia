/*
 * function: func_021C770C
 * address:  0x021C770C
 * packet:   pkt_ov136_021C770C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   func_020362DC                0x020362DC  arm
 *   d_021C7E14 0x021C7E14 data a4
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021C7E14[];
extern int func_02035C08(const void *);
extern u32 func_020362DC(void);
int func_021C770C(void)
{
    if (func_02035C08(d_021C7E14) != -1) {
        return 1;
    }
    if ((func_020362DC() & 3) != 0) {
        return 1;
    }
    return 0;
}
