/*
 * function: func_021F6BFC
 * address:  0x021F6BFC
 * packet:   pkt_021F6BFC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Restart the channel: stamp, force ports 5 and 0x6f to zero, hand the stamp over.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_02017DBC(void);
extern void func_02017E88(u32 a, int b, int c);
extern void func_02017DE4(u32 a, u32 b);

int func_021F6BFC(u32 handle)
{
    u32 stamp = func_02017DBC();

    func_02017E88(handle, 5, 0);
    func_02017E88(handle, 0x6f, 0);
    func_02017DE4(handle, stamp);
    return 0;
}
