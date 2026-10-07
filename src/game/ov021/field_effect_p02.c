/*
 * file:     field_effect_p02.c
 * unit:     yes
 * function: func_021A8AFC, func_021A8B18, func_021A8B84, func_021A8BB8
 * address:  0x021A8AFC
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
 *   func_021A92A4  0x021A92A4  thumb
 *   func_02040588  0x02040588  arm
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
 */
struct BigObj;
struct MsgBank;
struct Rec;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct Src;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
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
} Obj;

typedef struct Name {
    u16 s[7];
} Name;

typedef struct Pos {
    u8 x;
    u8 y;
} Pos;

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

extern void func_021A92A4(u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
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
extern void func_021A9154(struct Obj *p, struct Item *it, const struct Src *s);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
void func_021A8AFC(int a, int b);
u32 func_021A8B18(void *a, void *b, u32 c);
int func_021A8B84(int idx);
void func_021A8BB8(Obj *p, void *q, int r);
extern const int d_021D8D24[][7];
extern const Name d_021D8C0C;
extern const u16 d_021D8B34[];
extern const Rect d_021D8CAC[];
extern const Pos d_021D8B18[];


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


void func_021A8BB8(Obj *p, void *q, int r)
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
