/*
 * function: func_02206604
 * address:  0x02206604
 * packet:   pkt_02206604
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022076A0 0x022076A0 thumb ov195
 *   func_02208410 0x02208410 thumb ov195
 *   func_02208430 0x02208430 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
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
    u8 pad02[0x3e];
    u32 f40;
    u8 pad44[0x14];
    Work *work;
} Owner;

extern void func_022076A0(Owner *o);
extern int func_02208410(Grid *g, u16 heap);
extern void func_02208430(Grid *g, u16 heap);

void func_02206604(Owner *o)
{
    Work *w = o->work;
    u16 heap = o->heap;
    u8 i;
    Grid *g;

    switch (w->f00) {
    case 0:
        break;
    case 1:
        func_022076A0(o);
        break;
    case 2:
    case 3:
        break;
    }
    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            if (o->f40 != 0 && func_02208410(g, heap))
                g->state = 4;
            func_02208430(g, heap);
        }
    }
}
