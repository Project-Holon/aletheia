/*
 * function: func_021F3D9C
 * address:  0x021F3D9C
 * packet:   pkt_ov056_021F3D9C
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021F408C  0x021F408C  thumb  ov056
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned int u32;

struct IcaAnime;
extern void func_021F408C(struct IcaAnime **pp);
extern void func_02082BCC(void *p, int c, u32 n);

void func_021F3D9C(void *o)
{
    if (*(void **)o != 0) {
        func_021F408C(*(void **)o);
    }
    func_02082BCC(o, 0, 4);
}
