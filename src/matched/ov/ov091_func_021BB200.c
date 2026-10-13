/*
 * function: func_021BB200
 * address:  0x021BB200
 * packet:   pkt_ov091_021BB200
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker: func_0204B09C (0x0204B09C, ARM, unlabelled arm9 leaf, the integrator's) has
 * no witness outside this range (both image-wide callers are the two bl in
 * this function); a split cannot help.  Verified C for the leaf (EXACT with
 * one --arm --cc dsi/1.1p1 --flags=-O4,p, 44 bytes):
 *
 *   struct Item { int x; int y; u8 pad_08[0x40]; };
 *   struct Owner { u8 pad_00[0x98]; struct Item *items; };
 *   struct Pt { s16 x; s16 y; };
 *   void CLACT_SetSurfacePos(struct Owner *owner, u32 index, struct Pt *in)
 *   {
 *       int x = in->x;
 *       int y = in->y;
 *       struct Item *it = owner->items;
 *       struct Item *p;
 *
 *       it[index].x = x << 12;
 *       p = &it[index];
 *       p->y = y << 12;
 *   }
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B09C  0x0204B09C  arm
 *   func_021BAA50  0x021BAA50  thumb  ov091
 *   func_021BAAE4  0x021BAAE4  thumb  ov091
 *   d_021BEC74     0x021BEC74  data  ov091  a1
 *   d_021BEC75     0x021BEC75  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct CharBuf;
struct Descriptor;
struct Obj;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B09C(int a, int b, s16 *c);
extern void func_021BAA50(u8 *a, u8 *s);
extern void func_021BAAE4(u8 *a, u8 *s, int c);
extern const u8 d_021BEC74[];
extern const u8 d_021BEC75[];

void func_021BB200(u8 *a, u8 *s, int p, int q)
{
    s16 b[4];
    int i = s[4];
    int x = d_021BEC74[i * 2];
    int y = d_021BEC75[i * 2];

    if (i % 2 == 0)
        q = -q;
    *(int *)s = p;
    *(int *)(s + 0x18) = 0;
    *(int *)(s + 0xc) = func_02017E1C((void *)p, 0x4c, 0);
    *(u16 *)(s + 6) = func_02017E1C((void *)(*(int *)s), 0xa0, 0);
    *(u16 *)(s + 8) = *(u16 *)(s + 6);
    func_0204B3B4((struct Obj *)(*(int *)(s + 0x30)));
    func_0204A8D4(*(int *)(s + 0x2c));
    func_02043B5C(func_02045770((struct Descriptor *)(*(u32 *)(s + 0x20))), 0);
    func_0204B3DC((struct Obj *)(*(int *)(s + 0x3c)), 0);
    func_0204B3DC((struct Obj *)(*(int *)(s + 0x40)), 0);
    b[2] = 0;
    b[3] = 0;
    func_0204B09C(*(int *)(s + 0x24), 0, &b[2]);
    func_021BAA50(a, s);
    b[0] = -(x + q) * 8;
    b[1] = -y * 8;
    func_0204B09C(*(int *)(s + 0x24), 0, b);
    func_021BAAE4(a, s, 0);
}
