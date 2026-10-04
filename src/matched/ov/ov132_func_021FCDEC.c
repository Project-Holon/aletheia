/*
 * function: func_021FCDEC
 * address:  0x021FCDEC
 * packet:   pkt_021FCDEC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *
 * Addresses are Black-image addresses.
 */

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned int, unsigned int);

void func_021FCDEC(int a, int b)
{
    func_02039C68((struct Link *)func_020399A8(), b, 0x11);
}
