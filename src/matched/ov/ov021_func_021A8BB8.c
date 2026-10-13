/*
 * function: FIELD_MENU_CreateItems
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
 *   gFieldMenuLayouts     0x021D8D24  data  ov021  a4
 *   gFieldMenuDefaultName     0x021D8C0C  data  ov021  a2
 *   STRBUF_Create  0x020457B0  arm
 *   func_020084BC  0x020084BC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   gFieldMenuMsgIds     0x021D8B34  data  a2
 *   func_02045EC0  0x02045EC0  arm
 *   gFieldMenuIconRes     0x021D8CAC  data  ov021  a4
 *   func_02008550  0x02008550  thumb
 *   gFieldMenuWindowPos     0x021D8B18  data  ov021  a1
 *   FIELD_MENU_CreateItem  0x021A9154  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
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

extern const int gFieldMenuLayouts[][7];
extern const Name gFieldMenuDefaultName;
extern const u16 gFieldMenuMsgIds[];
extern const Rect gFieldMenuIconRes[];
extern const Pos gFieldMenuWindowPos[];

struct MsgBank;
struct Rec;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern int func_020084BC(const u16 *values);
struct Src;
extern const void *func_020084F4(const void *p);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void FIELD_MENU_CreateItem(struct Obj *p, struct Item *it, const struct Src *s);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);

void FIELD_MENU_CreateItems(Obj *p, void *q, int r)
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
    row = gFieldMenuLayouts[r];
    def = gFieldMenuDefaultName;
    for (; j < 7; j++) {
        k = row[j];
        if (k == 4) {
            st.s = STRBUF_Create(0x10, p->f02);
            if (func_020084BC(p->f18) == 0) {
                STRBUF_SetString(st.s, func_020084F4(p->f18));
            } else {
                n = def;
                STRBUF_SetString(st.s, n.s);
            }
        } else {
            st.s = func_02045EC0(h, gFieldMenuMsgIds[k]);
        }
        st.k = k;
        if (j != 6) {
            st.x = (j % 2) * 128 + 0x40;
            st.y = (j / 2) * 0x30 + 0x2C;
            st.b8 = st.x - 0x20;
            st.b9 = st.y;
            st.q = q;
            st.a = gFieldMenuIconRes[k].a;
            st.b = gFieldMenuIconRes[k].b;
            st.c = gFieldMenuIconRes[k].c;
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
        st.b6 = gFieldMenuWindowPos[j].x;
        st.b7 = gFieldMenuWindowPos[j].y;
        FIELD_MENU_CreateItem(p, &p->items[j], (const struct Src *)(&st));
        STRBUF_Delete(st.s);
    }
    MSGDATA_Delete(h);
}
