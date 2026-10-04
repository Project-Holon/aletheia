/*
 * function: func_021F6C28
 * address:  0x021F6C28
 * packet:   pkt_021F6C28
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Restart the channel: take a stamp, force port 6 to zero and hand the handle over.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017DE4(struct Sav *p, u32 f);

int func_021F6C28(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 6, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}
