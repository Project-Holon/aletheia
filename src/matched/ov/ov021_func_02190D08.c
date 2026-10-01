/*
 * function: func_02190D08
 * address:  0x02190D08
 * packet:   pkt_ov021_02190D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_02006238  0x02006238  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void func_020061E4(u32 se);
extern int func_02006238(void);

int func_02190D08(int x)
{
    switch (x) {
    case 3:
        func_020061E4(0x56B);
        break;
    case 6:
        return func_02006238();
    }
    return 0;
}
