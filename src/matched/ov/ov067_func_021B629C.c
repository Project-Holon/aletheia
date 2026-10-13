/*
 * function: UI_SCENE_CreateActor
 * address:  0x021B629C
 * packet:   pkt_ov067_021B629C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} P;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *a, unsigned int b, unsigned int c, unsigned int d, const void *r, u16 e, u16 f);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

int UI_SCENE_CreateActor(P *p, int a, u16 x, u16 y, u8 e, u16 f)
{
    Rect rc = {0, 0, 0, 0};
    int r;

    rc.x = x;
    rc.y = y;
    r = (int)CLACT_CreateActor((void *)a, p->f0, p->f4, p->f8, &rc, (u16)p->fC, f);
    CLACT_SetActorAnimSeq((struct Obj *)r, e);
    return r;
}
