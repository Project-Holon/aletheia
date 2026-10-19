/*
 * function: BTLV_MCSS_ShakeTaskEnd
 * address:  0x02201098
 * packet:   pkt_ov094_02201098
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *
 *
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)c + 4)) while the tag index uses c->key, as in sibling
 * BTLV_MCSS_BounceTaskEnd. With one spelling CSE hoists key ahead of the index and it
 * loads first (the +0x50 twins' order); with two spellings key is
 * copy-propagated and c->w loads first, as the image does.
 */
#include "../include/Obj06318.h"
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
    char body[0x24];
} Mover;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x38 */
} Ctx;

typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern int BTLV_EFFECT_GetBitMask(int x);

void BTLV_MCSS_ShakeTaskEnd(void *h)
{
    Ctx *c = (Ctx *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= BTLV_EFFECT_GetBitMask(((struct Obj06318 *)c)->f4) ^ 0xFFFFFFFF;
}
