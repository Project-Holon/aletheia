/*
 * function: func_0218AC4C
 * address:  0x0218AC4C
 * packet:   pkt_ov021_0218AC4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the save flag from func_0200D564 is set, shows message 0x2792 through
 * func_02158768 with the position's func_02188C84 value; returns 0 otherwise.
 *
 * symbols:
 *   func_0200D564  0x0200D564  thumb
 *   func_02188C84  0x02188C84  thumb
 *   func_02158768  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_02012EBC(void *p);
extern void *func_0200D418(void *p);
extern int func_0200D564(void *p);
extern u16 func_02188C84(u8 *p);
extern int func_02158768(int a0, int a1, int a2, int a3);

int func_0218AC4C(u8 *pos, void *msg, void *sys)
{
    if ((u8)func_0200D564(func_0200D418(func_02012EBC(sys))))
        return func_02158768((int)msg, 0x2792, 0, func_02188C84(pos));
    return 0;
}
