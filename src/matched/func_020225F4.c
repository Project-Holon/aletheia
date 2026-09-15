/*
 * function: func_020225F4
 * address:  0x020225F4
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sentinel resolver for the dual-screen text cluster: 0xFFFF in the caller's
 * value means "use the object's own default", which lives in the u16 at
 * +0x150, the same sentinel colour slot func_0202223C and func_02022268 read.
 * Any other value passes through untouched, which is what fixes the return
 * type as u32 rather than u16: the pass-through arm carries no truncation.
 *
 * The 0xFFFF compare constant costs a pool word rather than a movs/lsls pair
 * because it is compared, not materialised into a store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020225F4.c \
 *       --func func_020225F4 --addr 0x020225F4 --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct TextObj {
    u8  pad00[0x150];
    u16 f150;
};

u32 func_020225F4(struct TextObj *obj, u32 value)
{
    if (value == 0xFFFF)
        value = obj->f150;
    return value;
}
