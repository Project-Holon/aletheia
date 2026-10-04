/*
 * function: func_021ABA3C
 * address:  0x021ABA3C
 * packet:   pkt_ov021_021ABA3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021AB764  0x021AB764  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *
 * Lever: `const u16 *r` sinks the t.z spill store below the first shift pair
 * (const on the vector source alone does not).
 */
typedef unsigned short u16;
typedef struct { int x; int y; int z; } V;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021AB764(u8 *p);
extern u32 func_02188CFC(u8 *p);

int func_021ABA3C(int a, const u16 *r, V *v)
{
    V t;
    u16 px;
    u16 pz;
    int w;
    int h;

    if (func_02188CFC((u8 *)func_021AB764((u8 *)a)) == 1)
        return 0;
    t = *v;
    t.x -= 0x8000;
    t.z -= 0x8000;
    px = (t.x >> 12) / 16;
    pz = (t.z >> 12) / 16;
    w = r[2];
    if (w == 1) {
        w = r[4];
        h = r[3];
    } else {
        h = r[4];
    }
    if (px >= r[0] && px < r[0] + w && pz >= r[1] && pz < r[1] + h)
        return 1;
    return 0;
}
