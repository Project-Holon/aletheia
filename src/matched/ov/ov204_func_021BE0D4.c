/*
 * function: func_021BE0D4
 * address:  0x021BE0D4
 * packet:   pkt_021BE0D4
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02048C4C(u32);
extern void func_02048AC4(void *ptr);
extern void func_02046788(void);

void func_021BE0D4(u8 *p)
{
    func_02048C4C(*(u32 *)(p + 4));
    func_02048AC4((void *)(*(u32 *)p));
    func_02046788();
}

