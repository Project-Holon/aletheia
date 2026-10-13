/*
 * function: ITEMMENU_CreateCursorActors
 * address:  0x021BA028
 * packet:   pkt_ov070_021BA028
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void ITEMMENU_MoveCursorToRow(char *);

void ITEMMENU_CreateCursorActors(char *p)
{
    Rect r1;
    Rect r2;
    Rect r3;
    int i;

    r1.a = 0xf8;
    r1.b = 0x1a;
    r1.d = 1;
    r1.e = 2;
    r1.c = 0;
    *(int *)&((struct Obj00002 *)p)->f6A8 = (int)CLACT_CreateActor((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f560, ((struct Obj00002 *)p)->f554, ((struct Obj00002 *)p)->f568, &r1, 0, ((struct Obj00002 *)p)->f544);
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    ITEMMENU_MoveCursorToRow(p);
    r2.a = 0x8c;
    r2.b = 0x30;
    r2.d = 1;
    r2.e = 2;
    r2.c = 1;
    *(int *)&((struct Obj00002 *)p)->f6A4 = (int)CLACT_CreateActor((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f560, ((struct Obj00002 *)p)->f554, ((struct Obj00002 *)p)->f568, &r2, 0, ((struct Obj00002 *)p)->f544);
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A4, 1);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A4, 1);
    for (i = 0; i < 8; i++) {
        r3.a = 0x8c;
        r3.b = i * 0x18;
        r3.d = 0xa;
        r3.e = 3;
        r3.c = 0;
        *(int *)(p + i * 4 + 0x634) = (int)CLACT_CreateActor((void *)((struct Obj00002 *)p)->f69C, *(int *)(p + i * 4 + 0x5F4), ((struct Obj00002 *)p)->f588, ((struct Obj00002 *)p)->f56C, &r3, 0, ((struct Obj00002 *)p)->f544);
        r3.a -= 0x18;
        r3.c = 1;
        *(int *)(p + i * 4 + 0x674) = (int)CLACT_CreateActor((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f578, ((struct Obj00002 *)p)->f574, ((struct Obj00002 *)p)->f57C, &r3, 0, ((struct Obj00002 *)p)->f544);
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x634), 0);
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
    }
}
