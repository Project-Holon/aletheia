/*
 * function: func_02188AD4
 * address:  0x02188AD4
 * packet:   pkt_ov021_02188AD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021D31A4  0x021D31A4  thumb
 *   func_021C6D5C  0x021C6D5C  thumb
 *   func_0218CA4C  0x0218CA4C  thumb
 *   func_021890C8  0x021890C8  thumb
 *   func_02188E38  0x02188E38  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   abs_id_13  0x00000013  data
 *   abs_id_12  0x00000012  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 abs_id_13[];
extern u8 abs_id_12[];
extern void func_02030DA4(u32 a);
extern void func_020307B0(u32 a);
extern void func_02030EAC(u32 a);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_02034A5C(s32 handle);
extern void func_021D31A4(u32 a);
extern void func_021C6D5C(u32 a);
extern void func_0218CA4C(u32 a);
extern void func_021890C8(void *a);
extern void func_02188E38(void *a);
extern u32 func_02013CC8(u32 a);
extern u32 func_02013CE0(u32 a);

u32 func_02188AD4(void *a, u8 *b)
{
    func_02030DA4(*(u32 *)(b + 0x110));
    func_020307B0(*(u32 *)(b + 0x114));
    func_021D31A4(*(u32 *)(b + 0x14C));
    *(u32 *)(b + 0x14C) = 0;
    func_021C6D5C(*(u32 *)(b + 0x134));
    func_02030EAC(*(u32 *)(b + 0xAC));
    func_0218CA4C(*(u32 *)(b + 0x48));
    func_021890C8(b);
    func_0204A5AC();
    func_020450C8();
    func_02188E38(b);
    if (func_02013CC8(*(u16 *)(b + 0xD0)) == 1 || func_02013CE0(*(u16 *)(b + 0xD0)) == 1)
        func_02034A5C((s32)abs_id_13);
    else
        func_02034A5C((s32)abs_id_12);
    return 2;
}
