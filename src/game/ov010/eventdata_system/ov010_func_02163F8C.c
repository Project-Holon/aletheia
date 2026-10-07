/*
 * function: func_02163F8C
 * address: 0x02163F8C
 * packet: pkt_ov010_02163F8C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * contract: matched func_0216D88C copies all three Actor.pos words to v;
 * no uninitialized local component is read. Additions wrap as unsigned32.
 * symbols:
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_0216D89C 0x0216D89C thumb ov010
 */

typedef struct { int x,y,z; } Vec;
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D89C(void *, const Vec *);
void func_02163F8C(void *a, const Vec *b) { Vec v; func_0216D88C(a,(struct VecFx32 *)&v); v.x=(int)((unsigned)v.x+(unsigned)b->x); v.y=(int)((unsigned)v.y+(unsigned)b->y); v.z=(int)((unsigned)v.z+(unsigned)b->z); func_0216D89C(a,&v); }
