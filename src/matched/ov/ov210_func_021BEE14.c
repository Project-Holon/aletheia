/*
 * unit:     yes
 * function: func_021BEE14, func_021BEE38, func_021BEE58
 * address:  0x021BEE14
 * packet:   pkt_021BEE14
 * region:   ov210
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 */

typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Actor; struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

void func_021BEE14(char *p, int idx, int flag)
{
    if (flag == 1)
    {
        CLACT_SetActorObjMode(*(void **)(p + 0x28 + idx * 4), 1);
    }
    else
    {
        CLACT_SetActorObjMode(*(void **)(p + 0x28 + idx * 4), 0);
    }
}

void func_021BEE38(char *p, int idx, int a, short b, unsigned short c)
{
    unsigned short buf[2];
    buf[0] = a;
    buf[1] = b;
    CLACT_AddActorSurfacePos(*(void **)(p + idx * 4 + 0x28), (const struct Vec2 *)buf, c);
}

void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in)
{
    short buf[2];
    CLACT_GetActorSurfacePos(*(void **)(p + idx * 4 + 0x28), (struct PtS *)buf, in);
    *outA = buf[0];
    *outB = buf[1];
}
