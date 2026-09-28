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

extern int func_02011590(void *anim, u32 v);

int func_0216C270(Work *w)
{
    return func_02011590(w->anim, 0x1000);
}
