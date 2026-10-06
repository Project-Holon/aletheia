/*
 * function: func_021B6DC0
 * address:  0x021B6DC0
 * packet:   pkt_ov067_021B6DC0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     `mode = 0` goes after the allocation call (before it, the zero
 *           takes r1 ahead of the parameter copies; the compiler still
 *           stores it before the call); f1C is a flag local set to 1 in an
 *           `if` (the `a1 > 3` value compiles the opposite polarity); the
 *           palette rows are a flat u16 index `(i + 1) * 16 + j`; the
 *           func_021B76C8 calls are inline arguments (x/y locals schedule
 *           the i * 4 after them); stack locals are declared in reverse
 *           slot order.
 *
 * symbols:
 *   d_021B9564     0x021B9564  data  a1
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_020493D4  0x020493D4  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02049238  0x02049238  arm
 *   func_021B7718  0x021B7718  thumb  ov067
 *   func_02040588  0x02040588  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021B6208  0x021B6208  thumb  ov067
 *   func_021B76C8  0x021B76C8  thumb  ov067
 *   func_021B629C  0x021B629C  thumb  ov067
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    u8 b1c;
    u8 b1d;
    u8 b1e;
} In;

typedef struct {
    u16 heap;
    u16 _2;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 _1b;
    u32 f1C;
    u8 f20;
    u8 _21;
    u16 pal[3][16];
    u16 _82;
    u32 f84;
    int f88;
    int f8c;
    u32 f90;
    u32 f94;
    u32 f98;
    u32 f9c;
    int arrA0[4];
    u8 fB0[0xc0 - 0xb0];
    u32 fC0;
    u8 _c4[0xcc - 0xc4];
} S;

typedef struct {
    u8 _0[0xc];
    u16 (*data)[16];
} Pltt;

extern const char d_021B9564[];

struct ArcFile;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_020414AC(u32 a);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
typedef signed int     s32;
struct NitroFileHeader;
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern u32 func_020307B0(void *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void func_02049238(void *h);
extern void func_021B7718(int which, int idx, void *data);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021B6208(void *out, In *in, int unused, u16 d);
extern u8 func_021B76C8(u32 a, u32 b, u32 c);
extern int func_021B629C(void *p, int a, u16 x, u16 y, u8 e, u16 f);
extern void func_0204B84C(int p, u32 a);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Obj;
extern void func_0204B92C(struct Obj *a, u32 b);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

S *func_021B6DC0(u16 heap, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u32 a6, u32 a7)
{
    In in;
    Pltt *pl;
    void *q;
    void *h;
    void *buf;
    u32 mode;
    S *p;
    u16 *src;
    u8 i;
    u8 j;
    u32 flag;

    p = func_02030734(heap, 0xcc, 0, d_021B9564, 0xd3);
    mode = 0;
    func_02082BCC(p, 0, 0xcc);
    p->heap = heap;
    p->f4 = a5;
    p->f8 = a6;
    p->fC = a7;
    if (a1 > 3)
        mode = 4;
    p->f10 = mode;
    p->f14 = a1 + 1;
    p->f18 = a1;
    p->f15 = a2 + 1;
    p->f19 = a2;
    p->f16 = a3;
    p->f17 = a3 + 1;
    p->f1A = a3 + 2;
    flag = 0;
    if (a1 > 3)
        flag = 1;
    p->f1C = flag;
    p->f20 = a4;
    func_020414AC(p->f14);
    func_020414AC(p->f18);
    p->f98 = 0;
    p->f9c = 2;
    p->fC0 = 0;
    h = func_020490F4(0x53, p->heap);
    buf = func_02030734(p->heap, func_020493D4(h, 0xa3), 0, d_021B9564, 0x10d);
    func_0204932C(h, 0xa3, buf);
    func_02062A98(buf, (void **)(&pl));
    src = (u16 *)pl->data;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 16; j++) {
            p->pal[i][j] = src[(i + 1) * 16 + j];
        }
    }
    func_020307B0(buf);
    func_02049B68(h, 0xa3, p->f10, p->f16 << 5, 0x40, p->heap);
    p->f84 = func_02049740(h, 0xa4, p->f14, 0x1a0, 0, p->heap);
    func_020498F4(h, 0xa5, p->f14, (u16)p->f84, 0x600, 0, p->heap);
    func_020413B0(p->f14, 0, 0, 0x20, 0xb, p->f16);
    func_020413B0(p->f14, 0, 0xb, 0x20, 0xd, p->f17);
    func_020409B4(p->f14);
    func_02049238(h);
    func_021B7718(p->f10, p->f16, p->pal);
    func_021B7718(p->f10, p->f17, p->pal);
    func_02040588(p->f14, 0);
    func_02049B40(0x17, 5, p->f10, p->f1A << 5, 0x20, p->heap);
    p->f88 = func_020450F0(p->f18, 0, 5, 0x20, 6, p->f1A, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f88)), 0);
    p->f8c = func_020450F0(p->f18, 0, 0xb, 0x20, 6, p->f1A, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f8c)), 0);
    func_02040588(p->f18, 0);
    in.f0 = p->f1C;
    in.f4 = 0;
    in.f8 = 0xb;
    in.fC = 0x74;
    in.f10 = 0x77;
    in.f14 = 0x78;
    in.f18 = 0x79;
    in.b1c = p->f20;
    in.b1d = 0;
    in.b1e = 5;
    func_021B6208(p->fB0, &in, p->f4, p->heap);
    q = p->fB0;
    for (i = 0; i < 4; i++) {
        p->arrA0[i] = func_021B629C(q, p->f4, func_021B76C8(p->fC0, i, 0),
                                    func_021B76C8(p->fC0, i, 1), i, p->heap);
        func_0204B84C(p->arrA0[i], p->f19);
        func_0204B3DC((struct Obj *)p->arrA0[i], 0);
        func_0204B92C((struct Obj *)p->arrA0[i], 0);
    }
    if (p->f1C == 0)
        func_020434DC(0x10, 1);
    else
        func_02043598(0x10, 1);
    return p;
}
