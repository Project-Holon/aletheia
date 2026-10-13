/*
 * function: func_021B9F90
 * address:  0x021B9F90
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorPos  0x0204B528  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 */
typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x2c];
    void *f2c;              /* 0x2c */
} Obj;

struct Actor;
struct Pt;
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);
typedef unsigned int   u32;
struct Node;
struct Obj;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void func_021B9F90(Obj *o, Pos pos, int c)
{
    Pos t;

    t.x = pos.x + 8;
    t.y = pos.y;
    CLACT_SetActorPos(o->f2c, (const struct Pt *)(&t));
    CLACT_SetActorDrawPriority(o->f2c, (unsigned char)c);
    CLACT_SetActorDrawEnable(o->f2c, 1);
}
