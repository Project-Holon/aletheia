/*
 * function: func_021C0134
 * address:  0x021C0134
 * packet:   pkt_ov208_021C0134
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B034  0x0204B034  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B258  0x0204B258  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B404  0x0204B404  arm
 *   data_021C8558  0x021C8558  data
 *   data_021C8560  0x021C8560  data
 *   data_021C8568  0x021C8568  data
 *   data_021C8580  0x021C8580  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u32 w[4];
} BankDesc;

typedef struct {
    u8 v[7];
} Row7;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern const BankDesc data_021C8580;
extern const Row7 data_021C8558;
extern const Row7 data_021C8560;
extern const Row7 data_021C8568;

extern void *func_0204B034(const BankDesc *desc, unsigned int a1, unsigned int heap);
struct Actor;
struct Bank;
struct Node;
struct Obj;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_02082BCC(void *dst, int v, int n);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B878(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B84C(u32 obj, int v);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(u32 obj, Pt *pos, int n);

#define W(o) (*(u32 *)(p + (o)))
#define WP(o) (*(void **)(p + (o)))
#define OBJ(i) (*(u32 *)(p + (i) * 4 + 0xbc))

void func_021C0134(u16 *heap, u8 *p, int key)
{
    BankDesc desc;
    Row7 anim, pri, pal;
    ObjPos pos;
    Pt pt;
    void *h;
    u8 i;

    desc = data_021C8580;
    WP(0x1d4) = func_0204B034(&desc, 1, *heap);
    W(0x1d0) = (u32)func_0204B100(0x10, 0, *heap);
    func_0204B258((struct Bank *)W(0x1d0), WP(0x1d4));

    h = func_020490F4(0x55, *heap);
    W(0x9c) = func_0204AC18(h, 2, 0, 0, 0, 5, *heap);
    W(0x98) = func_0204A6C8(h, 8, 0, 0, *heap);
    W(0xa0) = func_0204AF28(h, 0xc, 0x13, *heap);
    func_02049238(h);

    h = func_020490F4(0x9f, *heap);
    W(0xa8) = func_0204AC18(h, 6, 0, 0xa0, 0, 2, *heap);
    W(0xa4) = func_0204A6C8(h, 0x10, 0, 0, *heap);
    W(0xac) = func_0204AF28(h, 0x1d, 0x2e, *heap);
    func_02049238(h);

    h = func_020490F4(0x9f, *heap);
    W(0xb4) = func_0204AC18(h, 5, 0, 0xe0, 0, 1, *heap);
    W(0xb0) = func_0204A6C8(h, 0xf, 0, 0, *heap);
    W(0xb8) = func_0204AF28(h, 0x1c, 0x2d, *heap);
    func_02049238(h);

    anim = data_021C8560;
    pri = data_021C8558;
    pal = data_021C8568;

    func_02082BCC(&pos, 0, sizeof(pos));
    for (i = 4; i < 7; i++)
        OBJ(i) = (u32)func_0204B294((void *)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
    for (i = 0; i < 4; i++)
        OBJ(i) = (u32)func_0204B294((void *)W(0x1d0), W(0xa4), W(0xa8), W(0xac), &pos, 0, *heap);

    for (i = 0; i < 7; i++) {
        func_0204B878((struct Obj *)OBJ(i), anim.v[i]);
        func_0204B92C((struct Obj *)OBJ(i), 1);
        func_0204B84C(OBJ(i), pri.v[i]);
        func_0204B800((struct Node *)OBJ(i), pal.v[i]);
        func_0204B3DC((struct Obj *)OBJ(i), 0);
        func_0204B688((struct Actor *)OBJ(i), 1);
    }

    pt.x = 0x80;
    pt.y = 0x60;
    for (i = 0; i < 4; i++)
        func_0204B404(OBJ(i), &pt, 0);

    p[0xd8] = 7;
}
