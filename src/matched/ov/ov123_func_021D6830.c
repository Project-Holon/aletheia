/*
 * function: func_021D6830
 * address: 0x021D6830
 * packet: pkt_ov123_021D6830
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: spelled-out x assignments reuse its already-loaded halfword.
 * symbols:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorScale 0x0204B5C0 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   func_021D679C 0x021D679C thumb ov123
 *   func_020056EC 0x020056EC thumb
 */
typedef unsigned short u16;
typedef short s16;
struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };
struct Pos { s16 x,y; };
struct Pair { int x,y; };
extern const s16 FX_SinCosTable_[][2];
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_GetActorScale(const struct Obj *o, struct Pair *p);
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
typedef unsigned char  u8;
extern void func_021D679C(u8 *p);
extern u32 func_020056EC(u32 range);
void func_021D6830(struct Record *p)
{
    struct Pos pos;
    struct Pair scale;
    int a,b;
    if (p == 0) return;
    a = (s16)(FX_SinCosTable_[p->a >> 4][0] * 4) >> 12;
    b = (s16)(FX_SinCosTable_[p->b >> 4][0] * 3) >> 12;
    if (p->h) {
        CLACT_GetActorSurfacePos(p->h, (struct PtS *)&pos, 0);
        pos.x = p->x + a + b;
        pos.y = (p->y + a + b + p->age) >> 2;
        if (p->age % 8 == 0) {
            if (p->x > 128) p->x = p->x - 1;
            else p->x = p->x + 1;
        }
        CLACT_AddActorSurfacePos(p->h, (const struct Vec2 *)(&pos), 0);
        CLACT_SetActorDrawEnable(p->h, 1);
        p->age++;
        if (pos.y > 25) {
            CLACT_GetActorScale(p->h, &scale);
            scale.x -= 16;
            scale.y -= 16;
            if (scale.x < 0 || scale.y < 0) func_021D679C((u8 *)p);
            else CLACT_SetActorScale(p->h, &scale);
        }
        if (pos.y > 50) func_021D679C((u8 *)p);
    } else p->g = 1;
    if (p->g == 0) {
        p->a += (u16)(func_020056EC(12) + 200);
        p->b -= (u16)(func_020056EC(12) + 666);
    }
}
