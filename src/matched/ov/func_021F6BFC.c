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
struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017DE4(struct Sav *p, u32 f);

int func_021F6BFC(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 5, 0);
    func_02017E88((void *)handle, 0x6f, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}
