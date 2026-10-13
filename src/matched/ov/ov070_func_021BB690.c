/*
 * function: ITEMMENU_MoveActorToPoint
 * address: 0x021BB690
 * packet: pkt_ov070_021BB690
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: expand q at the first call but retain q for the second call.
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021BBBCC 0x021BBBCC data a4
 */
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern short d_021BBBCC[];
int ITEMMENU_MoveActorToPoint(const char *p)
{
    unsigned i;
    short v[2];
    const char *q;
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        q = p + off;
        CLACT_GetActorSurfacePos((struct Actor *)*((int *)((p + off) + 0x6AC)), (struct PtS *)v, 0xFFFF);
        if (v[0] == *((short *)(((char *)d_021BBBCC) + off))) {
            return 0;
        }
        v[0] = v[0] + 4;
        CLACT_AddActorSurfacePos((struct Obj *)(*((int *)(q + 0x6AC))), (const struct Vec2 *)v, 0xFFFF);
    }
    return 1;
}
