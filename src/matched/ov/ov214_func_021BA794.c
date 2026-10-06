/*
 * function: func_021BA794
 * address:  0x021BA794
 * packet:   pkt_ov214_021BA794
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045770  0x02045770  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021BA4E8  0x021BA4E8  thumb  ov214
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned short f00;
    unsigned short pad02;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    char pad1c[0x58 - 0x1c];
    int f58;
    char pad5c[0x94 - 0x5c];
    int f94;
    int f98;
    char pad9c[0xa4 - 0x9c];
    int fA4;
    int fA8;
    char padAC[0xbc - 0xac];
    int fBC;
    unsigned short fC0;
} Ent;

typedef struct {
    int f00;
    int f04;
    int f08;
} Obj;

struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct U16Vec;
struct WordSet;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C724(int, int, int, int, int, int, int);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct S;
extern void func_021BA4E8(void *unused, struct S *p);

void func_021BA794(Obj *obj, Ent *e, unsigned int v)
{
    int state;
    int flag;
    int tmp;
    int h;
    int p;
    int x;
    int h2;
    int p2;
    int q;

    if (obj->f08 == 0)
        return;

    if (v > 0xa) {
        flag = 0x440;
        state = 1;
    } else {
        flag = 0xc80;
        state = 2;
    }

    if (state != e->fBC) {
        tmp = (int)func_02045770((struct Descriptor *)e->f94);
        func_02043B5C((struct CharBuf *)tmp, 0);
        tmp = (int)func_02045770((struct Descriptor *)e->f98);
        func_02043B5C((struct CharBuf *)tmp, 0);
    } else if (v != e->fC0) {
        tmp = (int)func_02045770((struct Descriptor *)e->f98);
        func_02043B5C((struct CharBuf *)tmp, 0);
    }

    if (state != e->fBC) {
        func_0201C6EC((struct PrintSys *)e->f14);
        h = (int)func_02045EC0((struct MsgBank *)e->f58, 0x10);
        p = (int)func_02045770((struct Descriptor *)e->f94);
        func_0201C724(e->f14, p, 4, 1, h, e->f08, flag);
        e->fA4 = 0;
        func_02045808((struct U16Vec *)h);
    }

    if (state != e->fBC || v != e->fC0) {
        x = (int)func_0201EC64(e->f00);
        h2 = (int)func_02045EC0((struct MsgBank *)e->f58, 0x12);
        p2 = (int)func_020457B0(8, e->f00);
        func_0201C6EC((struct PrintSys *)e->f18);
        func_0201EFA4((struct WordSet *)x, 1, v, 2, 2, 1);
        func_0201F250((struct WordSet *)x, (void *)p2, (void *)h2);
        q = (int)func_02045770((struct Descriptor *)e->f98);
        func_0201C724(e->f18, q, 2, 2, p2, e->f08, flag);
        e->fA8 = 0;
        func_02045808((struct U16Vec *)p2);
        func_02045808((struct U16Vec *)h2);
        func_0201ED04((struct WordSet *)x);
    }

    e->fBC = state;
    e->fC0 = v;
    func_021BA4E8(obj, (struct S *)e);
}
