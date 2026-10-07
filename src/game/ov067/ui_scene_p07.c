/*
 * file:     ui_scene_p07.c
 * unit:     yes
 * function: func_021B6B2C, func_021B6C4C, func_021B6C74, func_021B6CCC, func_021B6CE0, func_021B6D70, func_021B6DC0
 * address:  0x021B6B2C
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_021B6AE4  0x021B6AE4  thumb  ov067
 *   func_02045808  0x02045808  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021B9558     0x021B9558  data  a1
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020458F8 0x020458F8 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02045F50 0x02045F50 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045A90  0x02045A90  arm
 *   d_021B9564     0x021B9564  data  a1
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
struct MsgBank;
struct Rec;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Obj;
struct ArcFile;
struct NitroFileHeader;
struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021B6B2C;

typedef unsigned int u32_021B6C4C;

typedef unsigned int u32_021B6C74;

typedef unsigned u32_021B6CE0;

typedef struct { u32_021B6CE0 id,index; } Pair;

typedef struct { u32_021B6CE0 str,count; void *bank[1]; } Obj;

typedef unsigned int u32_021B6D70;

typedef unsigned int u32_021B6DC0;

typedef struct {
    int f0;
    u32_021B6DC0 f4;
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
    u32_021B6DC0 f4;
    u32_021B6DC0 f8;
    u32_021B6DC0 fC;
    u32_021B6DC0 f10;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 _1b;
    u32_021B6DC0 f1C;
    u8 f20;
    u8 _21;
    u16 pal[3][16];
    u16 _82;
    u32_021B6DC0 f84;
    int f88;
    int f8c;
    u32_021B6DC0 f90;
    u32_021B6DC0 f94;
    u32_021B6DC0 f98;
    u32_021B6DC0 f9c;
    int arrA0[4];
    u8 fB0[0xc0 - 0xb0];
    u32_021B6DC0 fC0;
    u8 _c4[0xcc - 0xc4];
} S;

typedef struct {
    u8 _0[0xc];
    u16 (*data)[16];
} Pltt;

typedef signed int     s32;

extern struct MsgBank *func_02045B38(u32_021B6B2C resident, u32_021B6B2C arcId, u32_021B6B2C fileId, u32_021B6B2C heapId);
extern void *func_0201EC64(u16 heap);
extern void *func_020457B0(u32_021B6B2C size, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32_021B6B2C index);
extern u32_021B6B2C func_0201D304(struct StrObj *s, u32_021B6B2C a, u32_021B6B2C b);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32_021B6B2C s0, u32_021B6B2C s1, u16 s2, u32_021B6B2C s3);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32_021B6B2C i, u32_021B6B2C a, u32_021B6B2C b, u32_021B6B2C c, u32_021B6B2C d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32_021B6B2C func_0201ED04(struct WordSet *p);
extern u32_021B6B2C func_02045C04(struct Rec *rec);
extern void *func_02030734(u32_021B6C74 heapId, u32_021B6C74 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern void ENV_SetResourceSet(void *p);
extern u16 func_020458F8(struct U16Vec *vec);
extern void func_02082A7C(u32_021B6CE0,void *,u32_021B6CE0);
extern u16 func_02045F50(const struct Obj *o);
extern void func_02045CAC(struct MsgBank *bank, u32_021B6CE0 index, void *dest);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_020414AC(u32_021B6DC0 a);
extern void *func_020490F4(u32_021B6DC0 id, u32_021B6DC0 heap);
extern u32_021B6DC0 func_020493D4(struct ArcFile *arc, u32_021B6DC0 member);
extern void func_0204932C(struct ArcFile *arc, u32_021B6DC0 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern u32_021B6DC0 func_020307B0(void *p);
extern void func_02049B68(void *a, u32_021B6DC0 b, u32_021B6DC0 c, u32_021B6DC0 d, u32_021B6DC0 e, u16 f);
extern u32_021B6DC0 func_02049740(void *a0, u32_021B6DC0 a1, u32_021B6DC0 a2, u32_021B6DC0 a3, u32_021B6DC0 a4, u16 flags);
extern void func_020498F4(void *a, u32_021B6DC0 b, u32_021B6DC0 c, u32_021B6DC0 d, u32_021B6DC0 e, u32_021B6DC0 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32_021B6DC0 index);
extern void func_02049238(void *h);
extern void func_021B7718(int which, int idx, void *data);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B40(u32_021B6DC0 a, u32_021B6DC0 b, u32_021B6DC0 c, u32_021B6DC0 d, u32_021B6DC0 e, u16 f);
extern u32_021B6DC0 func_020450F0(u32_021B6DC0 layer, u32_021B6DC0 a, u32_021B6DC0 b, u32_021B6DC0 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021B6208(void *out, In *in, int unused, u16 d);
extern u8 func_021B76C8(u32_021B6DC0 a, u32_021B6DC0 b, u32_021B6DC0 c);
extern int func_021B629C(void *p, int a, u16 x, u16 y, u8 e, u16 f);
extern void func_0204B84C(int p, u32_021B6DC0 a);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *a, u32_021B6DC0 b);
extern void func_020434DC(u32_021B6DC0 mask, u32_021B6DC0 enable);
extern void func_02043598(u32_021B6DC0 mask, u32_021B6DC0 enable);
void func_021B6B2C(u32_021B6B2C a0, void *a1, u32_021B6B2C a2, u16 a3, u16 a4, u16 a5, u32_021B6B2C a6, u32_021B6B2C a7, u16 heap);
u16 func_021B6C4C(struct StrObj *s, u32_021B6C4C a, u32_021B6C4C mode);
u32_021B6C74 *func_021B6C74(u32_021B6C74 *src, u32_021B6C74 n, u16 heap);
void func_021B6CCC(int *p);
u32_021B6CE0 func_021B6CE0(Obj *p,u32_021B6CE0 id,u32_021B6CE0 unused,u32_021B6CE0 str,Pair *out,u32_021B6CE0 max);
int func_021B6D70(u32_021B6D70 a, u32_021B6D70 b, u32_021B6D70 n);
S *func_021B6DC0(u16 heap, u32_021B6DC0 a1, u32_021B6DC0 a2, u32_021B6DC0 a3, u8 a4, u32_021B6DC0 a5, u32_021B6DC0 a6, u32_021B6DC0 a7);
extern const char d_021B9558[];
extern const char d_021B9564[];


/*
 * note:     the heap id and a4/a5 are reloaded from their stack slots before
 *           every call because the callees take them as u16 (with u32 callee
 *           parameters they stay in registers: 300 bytes); `a3 = a3 - f()`
 *           (`-=` truncates the call result first).
 */
void func_021B6B2C(u32_021B6B2C a0, void *a1, u32_021B6B2C a2, u16 a3, u16 a4, u16 a5, u32_021B6B2C a6, u32_021B6B2C a7, u16 heap)
{
    void *m;
    void *w;
    void *buf;
    void *s;
    u16 t;

    m = func_02045B38(0, 2, 0xa3, heap);
    w = func_0201EC64(heap);
    buf = func_020457B0(0xa, heap);
    s = func_02045EC0(m, 0);
    t = func_0201D304(s, a2, 0);
    func_021B6AE4((u8 *)a0, a1, a3, a4, (u32_021B6B2C)s, a2, a5, 2);
    a3 = a3 - func_021B6C4C(s, a2, 2);
    func_02045808(s);
    s = func_02045EC0(m, 1);
    func_0201EFA4(w, 0, a6, 8, 0, 1);
    func_0201F250(w, buf, s);
    func_021B6AE4((u8 *)a0, a1, a3, a4, (u32_021B6B2C)buf, a2, a5, 1);
    func_02045808(s);
    s = func_02045EC0(m, 2);
    func_0201EFA4(w, 0, a7, 8, 0, 1);
    func_0201F250(w, buf, s);
    func_021B6AE4((u8 *)a0, a1, a3 + t, a4, (u32_021B6B2C)buf, a2, a5, 0);
    func_02045808(s);
    func_02045808(buf);
    func_0201ED04(w);
    func_02045C04(m);
}

u16 func_021B6C4C(struct StrObj *s, u32_021B6C4C a, u32_021B6C4C mode)
{
    if (mode == 1) return func_0201D304(s, a, 0);
    if (mode == 2) return func_0201D304(s, a, 0) >> 1;
    return 0;
}


u32_021B6C74 *func_021B6C74(u32_021B6C74 *src, u32_021B6C74 n, u16 heap)
{
    u32_021B6C74 size;
    u32_021B6C74 *o;
    u32_021B6C74 i;

    size = n * 4 + 8;
    o = func_02030734(heap, size, 0, d_021B9558, 0x40);
    i = 0;
    func_02082BCC(o, 0, size);
    o[1] = n;
    for (i = 0; i < n; i++) {
        o[2 + i] = src[i];
    }
    o[0] = (u32_021B6C74)func_020457B0(0x80, heap);
    return o;
}


void func_021B6CCC(int *p)
{
    func_02045808((struct U16Vec *)p[0]);
    ENV_SetResourceSet(p);
}

/*
 * lever: struct bank array; explicit top-of-loop break preserves both guards.
 * ownership: Wave37 B7 conditional leaf cleared by parent after source/unit/SDK audit.
 * extent: two zero alignment bytes at 0x021B6D6E precede labelled 0x021B6D70.
 * residency: ov110 initializer 021C0134 loads 67; 021BAEDC creates caller+78 through ov067 021B6C74.
 */
u32_021B6CE0 func_021B6CE0(Obj *p,u32_021B6CE0 id,u32_021B6CE0 unused,u32_021B6CE0 str,Pair *out,u32_021B6CE0 max)
{
    u32_021B6CE0 count;
    u32_021B6CE0 n;
    void *bank;
    u32_021B6CE0 i,j,length;
    count=0;
    length=func_020458F8((void *)str);
    func_02082A7C(-1,out,max*8);
    if(length) {
        n=func_02045F50(p->bank[id]);
        bank=p->bank[id];
        i=0;
        j=0;
        for(;;i++) {
            if(i>=n) break;
            if(j>=max) break;
            func_02045CAC(bank,i,(void *)p->str);
            if(func_021B6D70(str,p->str,func_020458F8((void *)str))) {
                if(j<max) {
                    out[j].id=id;
                    out[j].index=i;
                    j++;
                }
                count++;
            }
        }
    }
    return count;
}


int func_021B6D70(u32_021B6D70 a, u32_021B6D70 b, u32_021B6D70 n)
{
    u16 *pa;
    u16 *pb;
    u32_021B6D70 i;

    if (func_020458F8((struct U16Vec *)a) < n) {
        return 0;
    }
    if (func_020458F8((struct U16Vec *)b) < n) {
        return 0;
    }
    pa = func_02045A90((struct U16Vec *)a);
    pb = func_02045A90((struct U16Vec *)b);
    for (i = 0; i < n; i++) {
        if (*pa++ != *pb++) {
            return 0;
        }
    }
    return 1;
}


S *func_021B6DC0(u16 heap, u32_021B6DC0 a1, u32_021B6DC0 a2, u32_021B6DC0 a3, u8 a4, u32_021B6DC0 a5, u32_021B6DC0 a6, u32_021B6DC0 a7)
{
    In in;
    Pltt *pl;
    void *q;
    void *h;
    void *buf;
    u32_021B6DC0 mode;
    S *p;
    u16 *src;
    u8 i;
    u8 j;
    u32_021B6DC0 flag;

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
