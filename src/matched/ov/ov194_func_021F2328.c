/*
 * function: func_021F2328
 * address:  0x021F2328
 * packet:   pkt_021F2328
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045994 0x02045994 arm
 */

typedef unsigned short u16;
typedef unsigned int u32;
struct Strbuf;
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);

void func_021F2328(char *self, struct Strbuf *dst)
{
    func_02045994(dst, (const u16 *)self,
                 *(unsigned short *)(self + 0x1e) + 1);
}
