/*
 * function: func_0205C4C8
 * address:  0x0205C4C8
 * packet:   pkt_0205C4C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ConvConnectAPType (dwc_ac.o)
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;

u8 func_0205C4C8(u8 type)
{
    if (type >= 0x12) return (u8)(type - 0xf);
    if (type >= 0xf) return (u8)(type - 5);
    if (type >= 0xc) return (u8)(type - 2);
    if (type >= 9) return (u8)(type + 1);
    if (type >= 6) return (u8)(type + 4);
    if (type >= 3) return (u8)(type - 3);
    return type;
}
