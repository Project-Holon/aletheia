/*
 * function: func_020113D8
 * address:  0x020113D8
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_020113F0  0x020113F0  thumb
 *
 * Fills a 12-byte buffer through func_0203F4CC and tail-hands its own
 * argument and the buffer's first word to func_020113F0, a table lookup
 * that is a documented near miss (src/matched/sub_02011410.c's header has
 * the details) and so is declared here only, not defined.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020113D8.c \
 *       --func func_020113D8 --addr 0x020113D8 --cc 1.1p1 --lang c99 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct RtcTime;
extern void func_0203F4CC(struct RtcTime *time);
extern int func_020113F0(int row, int col);

u32 func_020113D8(u32 row)
{
    u32 buf[3];

    func_0203F4CC((struct RtcTime *)buf);
    return func_020113F0(row, buf[0]);
}
