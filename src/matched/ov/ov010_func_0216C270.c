/*
 * function: func_0216C270
 * address:  0x0216C270
 * packet:   pkt_ov010_0216C270
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011590  0x02011590  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Work {
    u8 pad00[0x10];
    void *anim;         /* 0x10 */
} Work;

typedef signed int     s32;
struct IcaAnime;
extern u32 func_02011590(struct IcaAnime *p, s32 v);

int func_0216C270(Work *w)
{
    return func_02011590(w->anim, 0x1000);
}
