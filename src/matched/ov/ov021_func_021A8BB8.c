/*
 * function: func_021A8BB8
 * address:  0x021A8BB8
 * packet:   pkt_ov021_021A8BB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   d_021D8D24     0x021D8D24  data  ov021  a4
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

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

extern const int d_021D8D24[][7];
extern const Name d_021D8C0C;
extern const u16 d_021D8B34[];
extern const Rect d_021D8CAC[];
extern const Pos d_021D8B18[];

extern void *func_02045B38(u32, u32, u32, u32);
extern void *func_020457B0(u32, u32);
extern u32 func_020084BC(void *p);
extern u16 *func_020084F4(void *p);
extern void func_02045924(void *s, u16 *str);
extern void *func_02045EC0(void *bank, u32 index);
extern u32 func_02008550(void *a);
extern void func_021A9154(Obj *p, Item *it, St *st);
extern void func_02045808(void *p);
extern void func_02045C04(void *h);

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
        func_021A9154(p, &p->items[j], &st);
        func_02045808(st.s);
    }
    func_02045C04(h);
}
