/*
 * function: SHINKA_DEMO_VIEW_StartFadeOut
 * address:  0x022067BC
 * packet:   pkt_022067BC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SHINKA_DEMO_VIEW_StartGridFade 0x022081A4 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Grid {
    u8 pad00[0x28];
    int state;
} Grid;

typedef struct Work {
    u32 f00;
    u32 f04;
    Grid *grid[2];
} Work;

typedef struct Owner {
    u16 heap;
    u8 pad02[0x56];
    Work *work;
} Owner;

struct Fade;
extern void SHINKA_DEMO_VIEW_StartGridFade(struct Fade *p, int unused, u16 color, s16 cur, s16 end, s16 wait, s16 step);

void SHINKA_DEMO_VIEW_StartFadeOut(Owner *o)
{
    int heap = o->heap;
    Work *w = o->work;
    u8 i;
    Grid *g;

    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            g->state = 5;
            SHINKA_DEMO_VIEW_StartGridFade((struct Fade *)g, heap, 0x7fff, 31, 0, 0, -1);
        }
    }
}
