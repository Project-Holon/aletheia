/*
 * function: FIELD_MENU_UpdateActorsForScroll
 * address:  0x021A87A8
 * packet:   pkt_ov021_021A87A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetSurfacePos  0x0204B09C  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    int pad0;
    int f0;
    int pad8[3];
    int f10;
    int pad18;
} E;

typedef struct {
    char pad0[0x2c];
    int f2c;
    char pad30[0x8];
    E e[7];
    s16 hfc;
    char pad2[0x120 - 0xfe];
    int f120;
    int f124;
} S;

extern void CLACT_SetSurfacePos(int a, int b, P *c);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *h, unsigned int v);

void FIELD_MENU_UpdateActorsForScroll(S *s)
{
    P v;
    P p4;
    P p0;
    u8 i;

    v.x = 0;
    v.y = -s->hfc;
    CLACT_SetSurfacePos(s->f120, 0, &v);
    for (i = 0; i < 7; i++) {
        if (s->e[i].f10 != 0 && s->e[i].f0 != 7) {
            CLACT_GetActorSurfacePos((struct Actor *)s->e[i].f10, (struct PtS *)&p4, 0);
            if (p4.y < 0xd0) {
                CLACT_SetActorDrawEnable((struct Obj *)s->e[i].f10, 1);
            } else {
                CLACT_SetActorDrawEnable((struct Obj *)s->e[i].f10, 0);
            }
        }
    }
    CLACT_GetActorSurfacePos((struct Actor *)s->f124, (struct PtS *)&p0, 0);
    if (s->f2c != 0 && p0.y < 0xd6) {
        CLACT_SetActorDrawEnable((struct Obj *)s->f124, 1);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)s->f124, 0);
    }
}
