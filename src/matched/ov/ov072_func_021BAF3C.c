/*
 * function: TOWNMAP_UpdateMarkerPosition
 * address: 0x021BAF3C
 * packet: pkt_ov072_021BAF3C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOWNMAP_TownGetField 0x021BA774 thumb ov072
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned int u32;
typedef struct { short x,y; } Pt;
extern int TOWNMAP_TownGetField(char *p, int i);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void TOWNMAP_UpdateMarkerPosition(u32 *p,const u32 *v) { Pt t; if(p[1]!=0) { t.x=v[0]+TOWNMAP_TownGetField((char *)p[1],2); t.y=v[1]+TOWNMAP_TownGetField((char *)p[1],3); } CLACT_AddActorSurfacePos((void *)p[0],(const struct Vec2 *)(&t),0); }
