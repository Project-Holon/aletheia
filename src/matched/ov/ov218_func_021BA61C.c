/*
 * function: func_021BA61C
 * address: 0x021BA61C
 * packet: pkt_ov218_021BA61C
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * single-lever: row base retains ctx+i*4; fields at 244/2DC reproduce rematerialized id offset instead of hoisting a second array base.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef struct Pair { short x, y; } Pair;
typedef struct Row { char pad[0x244]; void *item; char gap[0x94]; unsigned id; } Row;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BA61C(char *ctx)
{
    int i;
    void *item;
    Pair pos;
    Row *row;
    for (i = 0; i < 20; i++) {
        row = (Row *)(ctx + i * 4);
        item = row->item;
        if (row->id == 65535) {
            func_0204B3DC(item, 0);
        } else {
            CLACT_GetActorSurfacePos(item, (struct PtS *)&pos, 65535);
            pos.y = row->id * 2 + 92;
            func_0204B404(item, (const struct Vec2 *)(&pos), 65535);
        }
    }
}
