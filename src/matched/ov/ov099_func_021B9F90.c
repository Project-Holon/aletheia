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
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B528  0x0204B528  arm
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
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
typedef unsigned int   u32;
struct Node;
struct Obj;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021B9F90(Obj *o, Pos pos, int c)
{
    Pos t;

    t.x = pos.x + 8;
    t.y = pos.y;
    func_0204B528(o->f2c, (const struct Pt *)(&t));
    CLACT_SetActorDrawPriority(o->f2c, (unsigned char)c);
    func_0204B3DC(o->f2c, 1);
}
