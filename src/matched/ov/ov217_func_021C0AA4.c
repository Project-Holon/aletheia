/*
 * function: func_021C0AA4
 * address:  0x021C0AA4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021C0AF0  0x021C0AF0  thumb  ov217
 *   func_021C0B74  0x021C0B74  thumb  ov217
 *   func_021C0BA8  0x021C0BA8  thumb  ov217
 *   func_021C0C2C  0x021C0C2C  thumb  ov217
 *   func_021C0C50  0x021C0C50  thumb  ov217
 *   func_021C0CC8  0x021C0CC8  thumb  ov217
 *   func_021C0D08  0x021C0D08  thumb  ov217
 *   func_021C0D2C  0x021C0D2C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C0AF0();
extern u32 func_021C0B74(u32 a0);
extern void func_021C0BA8(u8 *a0);
extern void func_021C0C2C(u8 *a0);
extern void func_021C0C50(u8 *a0);
extern void func_021C0CC8(int *p);
extern void func_021C0D08(u8 *a0);
extern void func_021C0D2C(u8 *);
u32 func_021C0AA4(u32 a0)
{
    func_021C0D2C((u8 *)a0);
    func_021C0D08((u8 *)a0);
    func_021C0CC8((int *)a0);
    func_021C0C50((u8 *)a0);
    func_021C0C2C((u8 *)a0);
    func_021C0BA8((u8 *)a0);
    func_021C0B74(a0);
    return func_021C0AF0(a0);
}

