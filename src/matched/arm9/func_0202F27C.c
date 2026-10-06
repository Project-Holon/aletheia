/*
 * function: func_0202F27C
 * address:  0x0202F27C
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203F4E4   0x0203F4E4  arm
 *   func_02017E64   0x02017E64  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F27C.c \
 *       --func func_0202F27C --addr 0x0202F27C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct RtcDate;
extern void func_0203F4E4(struct RtcDate *date);
extern void func_02017E64(void *p, u32 id, u32 v);

void func_0202F27C(void *a0)
{
    u32 buf[4];

    func_0203F4E4((struct RtcDate *)buf);

    func_02017E64(a0, 0x92, buf[0]);
    func_02017E64(a0, 0x93, buf[1]);
    func_02017E64(a0, 0x94, buf[2]);
}
