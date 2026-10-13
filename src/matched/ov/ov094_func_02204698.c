/*
 * function: func_02204698
 * address:  0x02204698
 * packet:   pkt_ov094_02204698
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * note: the row offset goes into the row pointer first and the table base is added
 *   to it (base + offset); that order gives the original r0/r1 colouring at +0056.
 *
 * symbols:
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_022047CC  0x022047CC  thumb  ov094
 *   func_022047F8  0x022047F8  thumb  ov094
 *   d_0220AEB0  0x0220AEB0  data  a4
 *   d_0220A53C  0x0220A53C  data  a4
 *   d_0220A85C  0x0220A85C  data  a4
 *   CLACT_SetActorAffineMode  0x0204B570  arm  arm9
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
typedef struct Obj {
    void *h0;
    char pad04[0x68 - 4];
    Bits f68;
    char pad6c[0x104 - 0x6c];
    int h104;
    int h108;
    int h10c;
    char pad110[0x240 - 0x110];
    u16 heap;
} Obj;
typedef struct Quad { u16 v[4]; } Quad;
typedef struct Pos { short x; short y; } Pos;
typedef struct Row { Pos pos[6]; int val[2]; } Row;
typedef struct Res { Obj *owner; void *h; void *e[6]; } Res;
extern void *func_02030734(u32, u32, int, const char *, u16);
typedef unsigned char  u8;
struct Actor;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void *func_02030DA8(void *, void (*)(void *, Res *), void *, u32);
extern void func_0220684C(char *p, int a, int b);
extern void func_022047CC(void *a, void **s);
extern void func_022047F8(void *);
extern const char d_0220AEB0[];
extern const Quad d_0220A53C;
extern Row d_0220A85C[];

void func_02204698(Obj *p, int a, int b)
{
    Res *r;
    u16 v;
    int i;
    Row *row;
    Quad quad;

    r = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xc53);
    quad = d_0220A53C;
    r->owner = p;
    r->h = CLACT_CreateUnit(6, 0, p->heap);
    row = (Row *)(a << 5);
    row = (Row *)((u32)d_0220A85C + (u32)row);
    v = row->val[b];
    for (i = 0; i < 6; i++) {
        if (row->pos[i].x == -1) {
            r->e[i] = 0;
        } else {
            r->e[i] = CLACT_CreateActor(r->h, p->h104, p->h108, p->h10c, &quad, 1, p->heap);
            CLACT_AddActorSurfacePos(r->e[i], (const struct Vec2 *)(&row->pos[i]), 1);
            CLACT_SetActorAffineMode(r->e[i], 2);
            CLACT_SetActorAutoAnim(r->e[i], 1);
            CLACT_SetActorAnimSeq(r->e[i], v);
        }
    }
    func_0220684C((char *)p, (int)func_02030DA8(p->h0, (void (*)(void *, Res *))func_022047CC, r, 0), (int)func_022047F8);
    p->f68.n++;
}
