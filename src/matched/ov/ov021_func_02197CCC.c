/*
 * function: func_02197CCC
 * address:  0x02197CCC
 * packet:   pkt_ov021_02197CCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sums five 12-byte records fetched from the actor at p into out.
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D8F0  0x0216D8F0  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D8B0(u8 *p, u8 *q);
extern void func_0216D8D0(u8 *p, u8 *q);
extern void func_0216D8F0(u8 *p, u8 *q);
extern void func_0216D92C(u8 *, s32 *);

void func_02197CCC(u8 *p, s32 *out)
{
    s32 a[3];
    s32 b[3];
    s32 c[3];
    s32 d[3];
    s32 e[3];

    func_0216D88C((const struct Actor *)p, (struct VecFx32 *)a);
    func_0216D8B0(p, (u8 *)b);
    func_0216D8D0(p, (u8 *)c);
    func_0216D8F0(p, (u8 *)d);
    func_0216D92C(p, e);
    out[0] = a[0] + b[0] + c[0] + d[0] + e[0];
    out[1] = a[1] + b[1] + c[1] + d[1] + e[1];
    out[2] = a[2] + b[2] + c[2] + d[2] + e[2];
}
