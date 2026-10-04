/*
 * function: func_022011FC
 * address:  0x022011FC
 * packet:   pkt_ov094_022011FC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_021F935C  0x021F935C  thumb  ov094
 *
 *
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)c + 4)) while the tag index uses c->key. With the same
 * field name on both uses, CSE makes key a temp ahead of the index
 * expression and it loads first (the twins' order); with distinct
 * spellings key is copy-propagated instead and c->w loads first.
 */
#include "../include/Obj06319.h"
typedef unsigned char u8;
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x514 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x514 */
    char pad518[0x542 - 0x518];
    u8 tag[1];              /* 0x542 */
} Work;

typedef struct {
    char body[0x14];
} Mover;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x28 */
} Ctx;

extern Ctx *func_02030EE8(void *h);
extern int func_021F935C(int x);

void func_022011FC(void *h)
{
    Ctx *c = func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(((struct Obj06319 *)c)->f4) ^ 0xFFFFFFFF;
}
