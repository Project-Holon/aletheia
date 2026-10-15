/*
 * function: BOX2_SEQ_CreateActorFromDesc
 * address:  0x021EBEE0
 * packet:   pkt_ov170_021EBEE0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorVisible 0x0204BA20 arm
 */
#include "../include/Obj23997.h"

typedef struct {
    int pad0;
    int pad4;
    int a;
    int b;
    int c;
    unsigned short pad14;
    unsigned short d;
} Desc;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);

void *BOX2_SEQ_CreateActorFromDesc(char *w, const Desc *s)
{
    void *r = CLACT_CreateActor(((struct Obj23997 *)w)->f9E70, (unsigned int)*(void **)(w + s->a * 4 + 0x9FF4),
                            (unsigned int)*(void **)(w + s->b * 4 + 0xA108), (unsigned int)*(void **)(w + s->c * 4 + 0xA134),
                            s, s->d, 0x4C);
    CLACT_SetActorVisible(r, 0);
    return r;
}
