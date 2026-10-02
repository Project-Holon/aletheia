/*
 * function: func_0217B9F4
 * address: 0x0217B9F4
 * packet: pkt_ov019_0217B9F4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021807E4 0x021807E4 data a1
 */
extern void func_02034714(const char *, int, const char *);
extern void func_020307B0(void *);
extern const char d_021807E4[];
void func_0217B9F4(void *p)
{
    if (!p) func_02034714(d_021807E4, 0, d_021807E4);
    func_020307B0(p);
}
