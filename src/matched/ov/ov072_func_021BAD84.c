/*
 * function: TOWNMAP_TownSetScroll
 * address: 0x021BAD84
 * packet: pkt_ov072_021BAD84
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TOWNMAP_TownGetField 0x021BA774 thumb ov072
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef short s16;
typedef struct { s16 x; s16 y; } Pos;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern int TOWNMAP_TownGetField(char *p, int i);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void TOWNMAP_TownSetScroll(int *p, int *b) { Pos pos; pos.x=b[0]+TOWNMAP_TownGetField((char *)p,2); pos.y=b[1]+TOWNMAP_TownGetField((char *)p,3); if(p[0]) CLACT_AddActorSurfacePos((struct Obj *)p[0],(const struct Vec2 *)(&pos),0); }
