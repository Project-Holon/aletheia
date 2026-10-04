/*
 * function: func_0217D624
 * address:  0x0217D624
 * packet:   pkt_ov018_0217D624
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_02025538  0x02025538  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   d_021836B4     0x021836B4  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GfFont;
struct Tcbl;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Obj;
struct Bank;

struct State {
    u8 pad00[0x1C];
    struct GfFont *font;      /* 0x1C */
    struct Tcbl *tcbl;        /* 0x20 */
    struct WordSet *words;    /* 0x24 */
    int unk28;                /* 0x28 */
    struct MsgBank *msg2C;    /* 0x2C */
    struct MsgBank *msg30;    /* 0x30 */
    u8 pad34[4];
    struct U16Vec *str38;     /* 0x38 */
    struct U16Vec *str3C;     /* 0x3C */
    struct U16Vec *str40;     /* 0x40 */
    u8 pad44[0x10];
    struct Bank *bank;        /* 0x54 */
    struct Obj *obj;          /* 0x58 */
    u8 pad5C[0x54];
    void *unkB0;              /* 0xB0 */
};

extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(unsigned char *a0, unsigned int a1, unsigned int heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern unsigned char d_021836B4[];

void func_0217D624(struct State *o)
{
    struct Obj *t;

    o->bank = func_0204B100(0x29, 5, 0x70);
    t = func_0204B034(d_021836B4, 1, 0x70);
    o->obj = t;
    func_0204B258(o->bank, t);
    o->unkB0 = func_02025538(0x70, o->bank);
    o->tcbl = func_0203101C(0x70, 0x70, 4, 0x20);
    o->font = func_0201D7EC(0x17, 0, 0, 0, 0x70);
    o->words = func_0201EC64(0x70);
    o->unk28 = func_0201C440((void *)0x70);
    o->msg2C = func_02045B38(0, 2, 0x2D, 0x70);
    o->msg30 = func_02045B38(0, 2, 0x42, 0x70);
    o->str38 = func_020457B0(0x80, 0x70);
    o->str3C = func_020457B0(0x80, 0x70);
    o->str40 = func_020457B0(0x80, 0x70);
}
