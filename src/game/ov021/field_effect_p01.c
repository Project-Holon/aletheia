/*
 * file:     field_effect_p01.c
 * unit:     yes
 * function: func_021A87A8, func_021A8840, func_021A8874, func_021A8AFC, func_021A8B18, func_021A8B84, func_021A8BB8, func_021A8D40, func_021A8DD8, func_021A8E10, func_021A8E20
 * address:  0x021A87A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B09C  0x0204B09C  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0207D534  0x0207D534  arm
 *   d_021D8BBC     0x021D8BBC  data  a4
 *   d_021D8B5C     0x021D8B5C  data  a4
 *   d_021D8B7C     0x021D8B7C  data  a4
 *   d_021D8B44     0x021D8B44  data  a4
 *   d_021D8C1C     0x021D8C1C  data  a4
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040618  0x02040618  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02049238  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_021A92A4  0x021A92A4  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020142E8  0x020142E8  thumb
 *   d_021D8D24  0x021D8D24  data  a4
 *   func_02045B38  0x02045B38  arm
 *   d_021D8C0C     0x021D8C0C  data  ov021  a2
 *   func_020457B0  0x020457B0  arm
 *   func_020084BC  0x020084BC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02045924  0x02045924  arm
 *   d_021D8B34     0x021D8B34  data  a2
 *   func_02045EC0  0x02045EC0  arm
 *   d_021D8CAC     0x021D8CAC  data  ov021  a4
 *   func_02008550  0x02008550  thumb
 *   d_021D8B18     0x021D8B18  data  ov021  a1
 *   func_021A9154  0x021A9154  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0203F684  0x0203F684  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_021A9080  0x021A9080  thumb  ov021
 */
struct Actor;
struct PtS;
struct Obj_021A87A8;
struct BgTemplate;
struct BigObj;
struct MsgBank;
struct Rec;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct Src;
typedef unsigned char u8;

typedef short s16_021A87A8;

typedef struct {
    s16_021A87A8 x;
    s16_021A87A8 y;
} P_021A87A8;

typedef struct {
    int pad0;
    int f0;
    int pad8[3];
    int f10;
    int pad18;
} E;

typedef struct {
    char pad0[0x2c];
    int f2c;
    char pad30[0x8];
    E e[7];
    s16_021A87A8 hfc;
    char pad2[0x120 - 0xfe];
    int f120;
    int f124;
} S_021A87A8;

typedef unsigned short u16;

typedef struct {
    char pad[0xfc];
    short hfc;
    short pad2;
    int f100;
} S_021A8840;

typedef unsigned int   u32;

typedef signed short s16_021A8874;

typedef struct Obj_021A87A8 {
    u16 f00;
    u16 f02;
    u8 pad04[0x104 - 0x04];
    u32 f104;
    u32 f108;
    u32 f10C;
    u32 f110;
    u32 f114;
    u32 f118;
    u32 f11C;
    u32 f120;
    u32 f124;
    u32 f128;
} Obj_021A87A8;

typedef struct Pos_021A87A8 {
    s16_021A8874 x;
    s16_021A8874 y;
    s16_021A8874 z;
    u8 a;
    u8 b;
} Pos_021A87A8;

typedef struct Bank {
    u32 w[4];
} Bank;

typedef signed int     s32;

typedef signed char    s8;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj_021A8AFC {
    u16 f00;
    u16 f02;
    void *f04;
    void *f08;
    int f0C;
    u32 f10;
    u32 f14;
    void *f18;
    u16 f1C;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 pad22[2];
    int f24;
    int f28;
    int f2C;
    int f30;
    Item items[7];
} Obj_021A8AFC;

typedef struct Name {
    u16 s[7];
} Name;

typedef struct Pos_021A8AFC {
    u8 x;
    u8 y;
} Pos_021A8AFC;

typedef struct Rect {
    int a;
    int b;
    int c;
} Rect;

typedef struct St {
    int k;
    u8 x;
    u8 y;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 padA[2];
    void *s;
    void *q;
    int a;
    int b;
    int c;
} St;

struct W_021A8D40 {
    u8 pad00[0x134];
    u32 f134;
};

typedef short s16_021A8D40;

typedef struct {
    s16_021A8D40 x;
    s16_021A8D40 y;
} P_021A8D40;

typedef struct {
    char pad0[0xfc];
    s16_021A8D40 hfc;
    char pad2[0x120 - 0xfe];
    int f120;
} S_021A8DD8;

typedef struct {
    int pad[2];
    int f8;
} T;

typedef struct {
    char pad[0xf8];
    T *pf8;
} S_021A8E10;

struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    void *f18;
};

struct W_021A8E20 {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[0xC];
    struct Slot slots[7];
};

extern void func_0204B09C(int a, int b, P_021A87A8 *c);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B3DC(struct Obj_021A87A8 *h, unsigned int v);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020414EC(u32 i);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void func_02049238(void *h);
extern void func_020409B4(u32 layer);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj_021A87A8 *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern struct Obj_021A87A8 *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_0204B92C(struct Obj_021A87A8 *, u32);
extern void func_0204B84C(u32, int);
extern void func_021A92A4(u32 a, u32 b);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u16 v);
extern u32 func_02013D20(u16 v);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_020084BC(const u16 *values);
extern const void *func_020084F4(const void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_021A9154(struct Obj_021A8AFC *p, struct Item *it, const struct Src *s);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern short func_0203F684(unsigned short x);
extern void func_0207E5D0(void *src, u32 off, u32 n);
extern void func_021A9080(struct W_021A8E20 *w, u32 a, u32 b);
void func_021A87A8(S_021A87A8 *s);
void func_021A8840(S_021A8840 *s);
void func_021A8874(Obj_021A87A8 *p, void *q, int r, u32 unused);
void func_021A8AFC(int a, int b);
u32 func_021A8B18(void *a, void *b, u32 c);
int func_021A8B84(int idx);
void func_021A8BB8(Obj_021A8AFC *p, void *q, int r);
void func_021A8D40(void *unused, struct W_021A8D40 *w);
void func_021A8DD8(S_021A8DD8 *s);
int func_021A8E10(S_021A8E10 *s);
void func_021A8E20(struct W_021A8E20 *w, u32 v);
extern const u8 d_021D8BBC[];
extern const u8 d_021D8B5C[];
extern const u8 d_021D8B7C[];
extern const u32 d_021D8B44[];
extern const Bank d_021D8C1C;
extern const int d_021D8D24[][7];
extern const Name d_021D8C0C;
extern const u16 d_021D8B34[];
extern const Rect d_021D8CAC[];
extern const Pos_021A8AFC d_021D8B18[];




void func_021A87A8(S_021A87A8 *s)
{
    P_021A87A8 v;
    P_021A87A8 p4;
    P_021A87A8 p0;
    u8 i;

    v.x = 0;
    v.y = -s->hfc;
    func_0204B09C(s->f120, 0, &v);
    for (i = 0; i < 7; i++) {
        if (s->e[i].f10 != 0 && s->e[i].f0 != 7) {
            func_0204B454((struct Actor *)s->e[i].f10, (struct PtS *)&p4, 0);
            if (p4.y < 0xd0) {
                func_0204B3DC((struct Obj_021A87A8 *)s->e[i].f10, 1);
            } else {
                func_0204B3DC((struct Obj_021A87A8 *)s->e[i].f10, 0);
            }
        }
    }
    func_0204B454((struct Actor *)s->f124, (struct PtS *)&p0, 0);
    if (s->f2c != 0 && p0.y < 0xd6) {
        func_0204B3DC((struct Obj_021A87A8 *)s->f124, 1);
    } else {
        func_0204B3DC((struct Obj_021A87A8 *)s->f124, 0);
    }
}




void func_021A8840(S_021A8840 *s)
{
    if (s->f100 == 1) {
        func_02041EE4(5, 3, -s->hfc);
        func_02041EE4(6, 3, -5 - s->hfc);
        s->f100 = 0;
    }
}




void func_021A8874(Obj_021A87A8 *p, void *q, int r, u32 unused)
{
    void *h;
    u32 t;
    Pos_021A87A8 pos;
    Bank bank;

    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_0203FCA0(5, (const struct BgTemplate *)d_021D8BBC, 0);
    func_02040588(5, 1);
    func_020414EC(5);
    func_0203FCA0(6, (const struct BgTemplate *)d_021D8B5C, 0);
    func_02040588(6, 1);
    func_020414EC(6);
    func_0203FCA0(7, (const struct BgTemplate *)d_021D8B7C, 0);
    func_02040588(7, 1);
    func_020414EC(7);
    func_02040618(6, 3, -5);
    func_02049B68(q, 0, 4, 0, 0, p->f02);
    func_02049658(q, 2, 5, 0, 0, 0, p->f02);
    func_020498F4(q, d_021D8B44[r], 5, 0, 0, 0, p->f02);
    func_020498F4(q, 0xE, 7, 0, 0, 0, p->f02);
    p->f104 = func_0204AC18(q, 1, 1, 0, 0, 0xB, p->f00);
    p->f108 = func_0204A6C8(q, 0xD, 0, 1, p->f00);
    p->f10C = func_0204AF28(q, 0x1C, 0x26, p->f00);
    h = func_020490F4(func_020275E4(), p->f02);
    p->f110 = func_0204AC18(h, func_02027614(), 1, 0x160, 0, 2, p->f00);
    p->f114 = func_0204A6C8(h, func_02027618(), 0, 1, p->f00);
    t = func_0202761C(0);
    p->f118 = func_0204AF28(h, t, func_02027620(0), p->f00);
    func_02049238(h);
    func_020409B4(5);
    p->f11C = (u32)func_0204B100(8, 0, p->f00);
    bank = d_021D8C1C;
    p->f120 = (u32)func_0204B034((u8 *)(&bank), 1, p->f00);
    func_0204B258((struct Bank *)p->f11C, (void *)p->f120);
    pos.x = 0x40;
    pos.y = 0x2C;
    pos.z = 0;
    pos.a = 0;
    pos.b = 0;
    p->f124 = (u32)func_0204B294((void *)p->f11C, p->f108, p->f104, p->f10C, &pos, 0, p->f00);
    func_0204B954((struct Actor *)p->f124, 0x1000);
    func_0204B92C((struct Obj_021A87A8 *)p->f124, 1);
    func_0204B84C(p->f124, 2);
    pos.x = 0xE0;
    pos.y = 0xA8;
    p->f128 = (u32)func_0204B294((void *)p->f11C, p->f114, p->f110, p->f118, &pos, 0, p->f00);
    func_0204B954((struct Actor *)p->f128, 0x1000);
    func_0204B92C((struct Obj_021A87A8 *)p->f128, 1);
    func_0204B3DC((struct Obj_021A87A8 *)p->f128, 1);
    func_0204B954((struct Actor *)p->f128, 0x2000);
}




void func_021A8AFC(int a, int b)
{
    func_021A92A4(a, 4);
    if (b != 0) {
        func_02040588(4, 0);
    }
}




/*
 * Addresses are Black-image addresses.
 */
u32 func_021A8B18(void *a, void *b, u32 c)
{
    u32 r = 0;

    if (func_02013CC8((u16)c) || func_02013CE0(c)) {
        r = 1;
    } else if (func_02013D20(c)) {
        r = 4;
    } else if (func_02012B70(a)) {
        r = 5;
    } else if (!func_020142E8(b, 0x961)) {
        r = 3;
    } else if (!func_020142E8(b, 0x962)) {
        r = 2;
    }
    return r;
}



int func_021A8B84(int idx)
{
    int i;
    int n;
    i = 0;
    n = 0;
    for (; d_021D8D24[idx][i] != 0; i++) {
        if (d_021D8D24[idx][i] != 7) {
            n++;
        }
    }
    return n;
}




void func_021A8BB8(Obj_021A8AFC *p, void *q, int r)
{
    void *h;
    u8 i;
    u8 j;
    int k;
    const int *row;
    St st;
    Name n;
    Name def;

    h = func_02045B38(0, 2, 0x22, p->f02);
    for (i = 0; i < 7; i++) {
        p->items[i].f00 = 0;
    }
    j = 0;
    row = d_021D8D24[r];
    def = d_021D8C0C;
    for (; j < 7; j++) {
        k = row[j];
        if (k == 4) {
            st.s = func_020457B0(0x10, p->f02);
            if (func_020084BC(p->f18) == 0) {
                func_02045924(st.s, func_020084F4(p->f18));
            } else {
                n = def;
                func_02045924(st.s, n.s);
            }
        } else {
            st.s = func_02045EC0(h, d_021D8B34[k]);
        }
        st.k = k;
        if (j != 6) {
            st.x = (j % 2) * 128 + 0x40;
            st.y = (j / 2) * 0x30 + 0x2C;
            st.b8 = st.x - 0x20;
            st.b9 = st.y;
            st.q = q;
            st.a = d_021D8CAC[k].a;
            st.b = d_021D8CAC[k].b;
            st.c = d_021D8CAC[k].c;
            if (k == 3 && func_02008550(p->f18) == 1) {
                st.a = 7;
                st.b = 0x16;
                st.c = 0x20;
            }
            if (k == 2 && func_02008550(p->f18) == 1) {
                st.a = 0xC;
                st.b = 0x1B;
                st.c = 0x25;
            }
        } else {
            st.x = 0x80;
            st.y = 0xB4;
            st.b8 = 0;
            st.b9 = 0;
            st.q = 0;
            st.a = 0;
            st.b = 0;
            st.c = 0;
        }
        st.b6 = d_021D8B18[j].x;
        st.b7 = d_021D8B18[j].y;
        func_021A9154(p, &p->items[j], (const struct Src *)(&st));
        func_02045808(st.s);
    }
    func_02045C04(h);
}



void func_021A8D40(void *unused, struct W_021A8D40 *w)
{
    s32 t = func_0203F684((u16)w->f134) + 0x1000;
    u16 c[2];

    c[1] = (t * 8 / 0x2000 + 9) | ((0x1F << 10) | ((t * 5 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[1], 0x142, 2);
    c[0] = (t * 0x1F / 0x2000) |
           (((t * 6 / 0x2000 + 0x19) << 10) | ((t * 13 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[0], 0x15E, 2);
    w->f134 += 6;
}



void func_021A8DD8(S_021A8DD8 *s)
{
    P_021A8D40 v;
    s->hfc = 0xc0;
    func_02040618(5, 3, -0xc0);
    func_02040618(6, 3, -0xc5);
    v.x = 0;
    v.y = 0xc0;
    func_0204B09C(s->f120, 0, (void *)&v);
}



int func_021A8E10(S_021A8E10 *s)
{
    T *p = s->pf8;
    if (p == 0) {
        return 0;
    }
    return p->f8;
}



void func_021A8E20(struct W_021A8E20 *w, u32 v)
{
    u8 i;
    struct Slot *s;

    for (i = 0, s = w->slots; i < 7; i++) {
        if (w->slots[i].f00 == 1 && v == w->slots[i].f08) {
            w->f1E = i % 2;
            w->f1F = i / 2;
            w->f24 = 1;
            func_021A9080(w, s[w->f1E + w->f1F * 2].f14,
                          s[w->f1E + w->f1F * 2].f15);
        }
    }
}
