/*
 * function: func_02167590
 * address:  0x02167590
 * packet:   pkt_ov010_02167590
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02167A74  0x02167A74  thumb
 *   func_02012114  0x02012114  thumb
 *   func_021BB5C8  0x021BB5C8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u8 pad00[0x14];
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

extern void func_02167A74(void *a, Work *w);
struct Ctx;
extern u32 func_02012114(const struct Ctx *p);
extern int func_021BB5C8(u32 v);

void func_02167590(void *a, Work *w)
{
    int i;

    func_02167A74(a, w);
    if (func_02012114(w->sys) == 1) {
        for (i = 0; i < 4; i++) {
            if (w->e[i].used == 1 && w->e[i].f18 != 0 && func_021BB5C8(w->e[i].f18) == 1)
                w->e[i].f18 = 0;
        }
    }
}
