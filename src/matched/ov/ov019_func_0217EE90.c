/*
 * function: UNION_MSG_RegisterPartnerWords
 * address:  0x0217EE90
 * packet:   pkt_ov019_0217EE90
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetString  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F048  0x0201F048  thumb
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb
 *   UNION_MSG_SetGreetingWordFlag  0x0217EFE0  thumb  ov019
 *   d_021807F8     0x021807F8  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u8  pad0[7];
    u8  lo7 : 3;
    u8  flag7 : 1;
    u8  hi7 : 4;
    u8  pad8;
    u8  f9;
    u8  padA[2];
    u16 name[13];
    u8  f26;
    u8  f27;
} Rec;

typedef struct Sys {
    u32 f0;
    u32 pad4;
    u32 f8;
} Sys;

typedef struct Sub {
    u8   pad0[0x14];
    Rec *rec;
} Sub;

typedef struct Self {
    Sys *sys;
    u8   pad4[0x2800];
    void *win2804;
    void *msg2808;
    u8   pad280C[0x24];
    Sub  sub;
} Self;

struct MsgBank;
struct Strbuf;
struct U16Vec;
struct WordSet;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u16  *func_020084F4(u32 a);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void UNION_MSG_SetGreetingWordFlag(int a, unsigned int n);
extern const char d_021807F8[];

void UNION_MSG_RegisterPartnerWords(Self *self)
{
    void *t;
    void *s;
    u32 x;
    u16 *buf;
    Sub *sub = &self->sub;
    int kind;
    u8 flag;
    int id;
    Rec *r;

    x = self->sys->f0;
    if (self->msg2808 == 0)
        func_02034714(d_021807F8, 0, d_021807F8);
    if (self->win2804 == 0)
        func_02034714(d_021807F8, 0, d_021807F8);

    r = sub->rec;
    if (r != 0) {
        buf = r->name;
        kind = r->f9;
        flag = r->flag7;
    } else {
        buf = func_020084F4(x);
        kind = 2;
        flag = (int)func_02008550((const struct Sub0200852CObj *)x);
    }

    s = STRBUF_Create(0x20, 0x41);
    STRBUF_SetString(s, buf);
    func_0201EE0C(self->win2804, 0, s, flag, 1, kind);
    STRBUF_Delete(s);
    func_0201F02C(self->win2804, 1, (void *)x);

    switch (kind) {
    case 1: id = 0xe7; break;
    case 2: id = 0xe8; break;
    case 3: id = 0xe9; break;
    case 4: id = 0xea; break;
    case 5: id = 0xeb; break;
    case 7: id = 0xec; break;
    case 8: id = 0xee; break;
    default: id = 0xed; break;
    }
    t = func_02045EC0(self->msg2808, id);
    func_0201EE0C(self->win2804, 2, t, flag, 1, kind);
    STRBUF_Delete(t);

    if (sub->rec != 0 && sub->rec->f26 != 0) {
        func_0201F048(self->win2804, 3, sub->rec->f26);
        if (sub->rec->f27 != 0)
            WORDSET_DeleteMsgdataF094(self->win2804, 4, sub->rec->f26, sub->rec->f27);
    }
    UNION_MSG_SetGreetingWordFlag(self->sys->f8, kind);
}
