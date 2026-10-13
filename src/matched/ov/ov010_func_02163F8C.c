/*
 * function: FLDMMDL_MOVE_AddVectorPos
 * address: 0x02163F8C
 * packet: pkt_ov010_02163F8C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * contract: matched FLDMMDL_GetPos copies all three Actor.pos words to v;
 * no uninitialized local component is read. Additions wrap as unsigned32.
 * symbols:
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 *   FLDMMDL_SetPos 0x0216D89C thumb ov010
 */

typedef struct { int x,y,z; } Vec;
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void FLDMMDL_SetPos(void *, const Vec *);
void FLDMMDL_MOVE_AddVectorPos(void *a, const Vec *b) { Vec v; FLDMMDL_GetPos(a,(struct VecFx32 *)&v); v.x=(int)((unsigned)v.x+(unsigned)b->x); v.y=(int)((unsigned)v.y+(unsigned)b->y); v.z=(int)((unsigned)v.z+(unsigned)b->z); FLDMMDL_SetPos(a,&v); }
