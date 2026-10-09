/*
 * file:     unit_02175C40.c
 * unit:     yes
 * function: func_02175C40, func_02175C58, func_02175C78, func_02175C88, func_02175CF4, func_02175D20, func_02175D34, func_02175D7C, func_02175DA8, func_02175DCC, func_02175DE4, func_02175E30, func_02175E90, func_02175EB8, func_02175ED8, func_02175EE8, func_02175EFC, func_02175F34, func_02175FB4, func_02175FB8, func_02176048, func_02176158, func_02176194, func_021761C4, func_021761EC, func_02176200, func_0217620C, func_02176230, func_02176258, func_02176280, func_021762C0, func_021762D8, func_021763BC, func_021763D8, func_02176424, func_02176454, func_02176504
 * address:  0x02175C40
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021756A4 0x021756A4 thumb ov011
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 *   func_02175BCC 0x02175BCC thumb ov011
 *   func_02082BCC 0x02082BCC arm
 *   func_021583EC 0x021583EC thumb ov010
 *   func_020084F8 0x020084F8 thumb
 *   func_02008550 0x02008550 thumb
 *   func_021583CC  0x021583CC  thumb  ov010
 *   func_0200855C  0x0200855C  thumb
 *   func_021756B0  0x021756B0  thumb  ov011
 *   func_021756D0  0x021756D0  thumb  ov011
 *   func_020392B8  0x020392B8  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02175920  0x02175920  thumb  ov011
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_02173E6C 0x02173E6C thumb ov011
 *   memset 0x02082BCC arm
 *   func_021740AC  0x021740AC  thumb  ov011
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201F184  0x0201F184  thumb
 *   d_02176C4C     0x02176C4C  data  ov011  a1
 *   func_020056EC  0x020056EC  thumb
 *   func_0203159C  0x0203159C  arm
 *   func_02031324  0x02031324  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201BA34  0x0201BA34  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201AB34  0x0201AB34  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_02034714  0x02034714  arm
 *   d_02177010     0x02177010  data  ov011  a1
 *   func_02012138  0x02012138  thumb
 *   func_02031330  0x02031330  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02013790  0x02013790  thumb
 *   func_02013128  0x02013128  thumb
 *   func_02039338  0x02039338  arm
 *   func_0203A424  0x0203A424  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_02031348  0x02031348  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_020130DC  0x020130DC  thumb
 *   ov093_id       0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  ov093  a4
 *   d_021EFDAC     0x021EFDAC  data  ov093  a4
 */
#include "../../matched/include/Obj12438.h"
#include "../../matched/include/Obj07335.h"

struct BigObj;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
struct Strbuf;
struct U16Vec;
struct WordSet;
struct Obj0203159C;
struct Ctx;
struct Party;
struct PartyMon;
struct Entry;
struct Link;
typedef unsigned char u8;

typedef struct { u8 pad[0x1a5]; u8 low:5; u8 value:2; u8 high:1; } Bits_02175C40;

typedef struct { u8 pad[0x1a5]; u8 low:5; u8 value:2; u8 high:1; } Bits_02175C58;

typedef unsigned int  u32;

typedef struct Rec_02175C88 {
    u32 w[13];
} Rec_02175C88;

typedef signed int     s32;

typedef struct Rec_02175D34 {
    u32 w[11];
    u8  f2c;
    u8  pad2d[7];
} Rec_02175D34;

typedef struct { u32 words[15]; } Rec_02175D7C;

typedef struct { u8 pad[0x1a5]; u8 flag:1; u8 rest:7; } Bits_02175D7C;

typedef struct { u8 pad[0x1a5]; u8 flag:1; u8 rest:7; } Bits_02175DA8;

typedef struct { u8 pad[0x2c]; u8 value; } Rec_02175DA8;

typedef struct { u8 pad[0x7c]; u32 value:4; u32 rest:28; } Bits;

typedef struct {
    u32 w0;
    u8  pad04[0x30];
    u8  f34[3];
    u8  f37;
} Blk;

typedef struct {
    u8 v : 6;
} Bf6;

typedef struct {
    u32 w0;
    u32 slot : 4;
} Rec_02175C40;

typedef struct Sub {
    u8 pad000[0x1a5];
    u8 bit0 : 1;
    u8 bit1 : 1;
    u8 bit2 : 1;
    u8 bit3 : 1;
    u8 bit4 : 1;
} Sub;

typedef struct { u8 pad[0x10]; u8 index; u8 flag:1; u8 rest:7; } Ent_02175C40;

typedef struct Sub0200852CObj Sub0200852CObj;

typedef unsigned short u16;

typedef struct {
    u16 h[8];
    u8  f10;
    u8  f11;
    u8  f12;
    u8  pad13;
    u8  f14[0x14];
} Ent_02175F34;

typedef struct {
    u16 h[8];
} Half8;

typedef struct {
    u32 w0_lo : 15;
    u32 a : 7;
    u32 b : 10;
    u32 t : 4;
    u32 w4_mid : 3;
    u32 c : 11;
    u32 d : 11;
    u32 e : 3;
    u16 pad8;
    u16 h0a[3];
    u8  b10[4];
    u16 h14;
    u16 h16;
} Rec_02175F34;

typedef struct {
    u32 f0_0 : 15;
    u32 f0_15 : 7;
    u32 f0_22 : 10;
    u32 kind : 4;
    u32 f4_4 : 28;
    u32 w8[4];
} Head;

typedef struct {
    u16 name[8];
    u8 b10;
    u8 pad11;
    u16 pad12;
} Name;

typedef struct {
    Head head;
    Name name;
    u8 b2C;
} Src_02175C40;

typedef struct {
    Head head;
    Name name;
    u8 idx;
    u8 b2D;
    u8 b2E;
    u16 h30;
    u16 h32;
} Rec;

typedef struct {
    u8 state;
    Rec rec;
} Entry;

typedef struct {
    u8 pad0[0x78];
    Rec tmp;
    u8 padAC[0xE8 - 0xAC];
    Entry entries[1];
} Work_02175C40;

typedef struct {
    u8 pad[0x197];
    u8 f197[3];
} Work_02176194;

typedef struct { int d[13]; } B34;

typedef struct { u8 bit : 1; } Flag;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u32 f0_0 : 15;
    u32 f0_15 : 7;
    u32 f0_22 : 10;
    u32 kind : 4;
    u32 f4_4 : 28;
    u32 pad8[3];
    Pos pos;
} Obj_021762D8;

typedef struct {
    u8 key;
    u8 f1;
    u8 f2;
    u8 f3;
} Ent;

typedef struct {
    u8  pad[0xc];
    u16 h0c;
    u16 h0e;
} Src_021761EC;

typedef struct {
    u32 w0;
    u8  pad4;
    u8  b5;
    u8  b6;
} Arg;

typedef struct {
    u32 w0;
    u8 b4;
} Obj_02175C40;

typedef struct {
    u8 pad0[0xC];
    int w0C;
    u8 pad10[0x8];
    u16 h18;
    u8 pad1A[0x7];
    u8 b21;
    u8 pad22[0x76 - 0x22];
    u16 h76;
    u8 pad78[0x84 - 0x78];
    u16 h84;
    u8 pad86[0xF4 - 0x86];
    u32 wF4;
    u32 wF8;
    int wFC;
} Work;

extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern u8 func_021756A4(char *);
extern int func_02175B14(u8 *p);
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern void *func_020127B8(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_021584F4(int a0, int a1);
extern u8 *func_02175BCC(u8 *p);
extern void func_02082BCC(void *, int, int);
extern int func_021583EC(void *, int);
extern u32 func_020084F8(void *, u32, u32);
extern int func_02008550(const Sub0200852CObj *);
extern int func_021583CC(void *a0, int a1);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
extern int func_021756B0(int value);
extern int func_021756D0(u32 a);
extern u32 func_020392B8(void);
extern int func_0203D1B4(void);
extern void func_02175920(void *p);
extern u32 func_0203F4FC(void);
extern int func_02173E6C(int a, int b, int c);
extern void *memset(void *p, int value, unsigned int size);
extern int func_021740AC(int a, int b, int c, ...);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern u32 func_020056EC(u32 a);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02031324(int heap);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void func_0201BA34(void *p);
extern u32 func_0201AA18(void *p);
extern struct Party *func_0201A920(u32 heap);
extern u32 func_0201AB34(void *p, u32 idx);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_02019CA0(void *p, u32 v);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_02012138(const struct Ctx *a);
extern u32 func_02031330(void *a);
extern u32 func_0200FB24(void);
extern int func_0203CDBC(void);
extern struct Entry *func_020399A8(void);
extern void func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013128(void *p, void *src, int i);
extern u16 func_02039338(void);
extern void func_0203A424(char *p, int a, int b, int c);
extern u32 func_02039CB4(struct Link *a, u32 b, u32 c);
extern int func_02034AC4(int id);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_02031348(u32 a, int b, void *c, Work *w);
extern int func_0203CD98(void);
extern void func_0203A5E4(u32 key);
extern void func_02034A5C(int handle);
extern void func_020130DC(Work *w);
int func_02175C40(void *p);
void func_02175C58(void *p, int v);
int func_02175C78(u8 *p, void *b, int c);
int func_02175C88(u8 *a, Rec_02175C88 *b, int c);
int func_02175CF4(char *p, u8 *q);
void func_02175D20(u8 *p);
void func_02175D2C(u8 *p, u8 v);
void func_02175D34(void *unused, u8 *b);
void func_02175D7C(void *unused, u8 *p, Rec_02175D7C *q);
int func_02175DA8(u8 *p);
int func_02175DCC(void *p);
int func_02175DE4(void *p, u8 *a1);
void func_02175E30(void *a, u8 *b, Rec_02175C40 *c);
int func_02175E90(void *p, u8 *q);
int func_02175EB8(void *p);
int func_02175ED8(Sub *s);
void func_02175EE8(u8 *p);
void func_02175EFC(void *w, void *obj, u8 index);
void func_02175F34(void *w, Ent_02175F34 *tbl, u32 arg, int idx);
int func_02175FB4(u8 *p);
int func_02175FB8(void *unused, void *obj);
int func_02176048(u8 *a0, Work_02175C40 *p, Src_02175C40 *src, int idx);
void func_02176158(int a, u8 *p);
void func_02176194(void *a, Work_02176194 *w);
void func_021761C4(u8 *p, u8 *s);
u8 func_021761EC(char *p);
void func_02176200(char *p);
int func_0217620C(u8 *p, int key);
u8 func_02176230(u8 *p, u8 *q);
int func_02176258(u8 *p);
void func_02176280(void *win, u32 slot, void *src, u32 size, u16 heap, u32 a);
void func_021762C0(void *win, u32 slot, u8 *src, u16 heap);
void func_021762D8(const Obj_021762D8 *obj, u8 *a1, void *a2, u16 a3);
void func_021763BC(u8 *p);
void func_021763D8(u8 *p, u32 key);
int func_02176424(u8 *p, u8 *a, u8 *b);
int func_02176454(struct Obj0203159C *a0, int a1, Arg *arg);
int func_02176504(void *a0, int *state, Obj_02175C40 *obj, Work *work);
extern Ent d_02176C4C[];
extern u8 d_02177010[];
extern char d_021F03C4[];
extern u8 ov093_id[];
extern char d_021EFDAC[];








int func_02175C40(void *p)
{
    int v;
    v = ((Bits_02175C40 *)p)->value;
    func_02175C58(p, 0);
    return v;
}








void func_02175C58(void *p, int v)
{
    ((Bits_02175C58 *)p)->value = v;
}








int func_02175C78(u8 *p, void *b, int c)
{
    if (p[0xe0] == 4) return 0;
    return 3;
}









int func_02175C88(u8 *a, Rec_02175C88 *b, int c)
{
    Rec_02175C88 *dst;
    int r;

    dst = (Rec_02175C88 *)(a + 0xac);
    if (func_0203EFC8(a + 0x78, (const u8 *)b, 0x30) != 0) {
        (a + c)[0x197] = 2;
        return 0;
    }
    r = func_02175C78(a, b, c);
    if (r == 3) {
        (a + c)[0x197] = 2;
        return 0;
    }
    *dst = *b;
    ((u8 *)dst + r)[0x34] = c;
    (a + c)[0x197] = 1;
    a[0x19b] = 1;
    return 1;
}








/*
 * extent: Two alignment bytes at 02175D1E before D20.
 * note: Outer non-one guard returns the original byte, including values beyond boolean.
 */
int func_02175CF4(char *p, u8 *q)
{
    int v;
    v = q[0x1a4];
    if (v == 1) {
        if (func_02175DA8(q) == 1 && func_021756A4(p) == 1) return 1;
        return 0;
    }
    return v;
}








/*
 * extent: store-return follower at 02175D2C, claimed by root for this unit.
 */
void func_02175D20(u8 *p)
{
    p[0x1a4] = 0;
}








void func_02175D2C(u8 *p, u8 v)
{
    p[0x1a4] = v;
}









void func_02175D34(void *unused, u8 *b)
{
    Rec_02175D34 *src;
    Rec_02175D34 *dst;

    src = (Rec_02175D34 *)(b + 0x78);
    dst = (Rec_02175D34 *)(b + 0xac);
    if (src->f2c != 4 && dst->f2c == 4) {
        *dst = *src;
        ((u8 *)dst)[0x37] = 1;
        b[0x19b] = 1;
        b[0x19c] = 0;
    }
}








void func_02175D7C(void *unused, u8 *p, Rec_02175D7C *q)
{
    *(Rec_02175D7C *)(p + 0xac) = *q;
    ((Bits_02175D7C *)p)->flag = 1;
}








int func_02175DA8(u8 *p)
{
    Rec_02175DA8 *r;
    r = (Rec_02175DA8 *)(p + 0xac);
    if (((Bits_02175DA8 *)p)->flag == 1 && r->value != 4) return 1;
    return 0;
}








int func_02175DCC(void *p)
{
    if (func_02175B14(p) == 0) return 6;
    return ((Bits *)p)->value;
}









int func_02175DE4(void *p, u8 *a1)
{
    Blk *b;
    int sv;
    int i;

    sv = func_02026478(((void **)p)[1]);
    b = (Blk *)((char *)p + 0x258);
    if (b->f37 == 1) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (b->f34[i] == func_02012B58((const struct BigObj *)sv)) {
            u32 v = (b->w0 << 10) >> 25;
            if (v > 0x14) {
                return 1;
            }
            return v;
        }
    }
    return 0;
}









void func_02175E30(void *a, u8 *b, Rec_02175C40 *c)
{
    u8 *d;
    u32 v;
    int r;
    int t;

    d = func_020127B8(a);
    t = (int)func_02012950(a, ((u8 *)c)[0x34]);
    v = ((Bf6 *)(b + ((u8 *)c)[0x34] * 0x1c + 0xa7))->v;
    r = func_021584F4((u8)v, func_02008530((const struct Sub0200852CObj *)t));
    if (r == 0x14) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 1;
    } else if (r == 0x15) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 2;
    }
}








/*
 * interface: DE4 source declares one argument; original E90 visibly sets r1, preserved here.
 */
int func_02175E90(void *p, u8 *q)
{
    if (func_02175DA8(q) == 0) return 0;
    if (func_02175DE4(p, q) > 0) return 1;
    return 0;
}







/*
 * extent: alignment at 02175ED6 then existing filed leaf ov011_func_02175ED8.c.
 * interface: BCC matched caller returns int; body returns original object +0xac or null.
 */
int func_02175EB8(void *p)
{
    u8 *r;
    r = (u8 *)func_02175BCC(p);
    if (r == 0) return 0;
    if (r[0x37] == 1) return 1;
    return 0;
}








/*
 * Flag getter: bit 4 of the byte at 0x1A5 (the lsls #27 / lsrs #31 pair is
 * a one-bit bitfield read).  A leaf with no lr save, so disasm.py left it as
 * .word data; filed for ov011 func_02172D70, whose only unresolved call
 * site besides arm9 0x02008494 it was.
 */
int func_02175ED8(Sub *s)
{
    return s->bit4;
}





/*
 * extent: Two alignment bytes at 02175EFA before EFC.
 */
void func_02175EE8(u8 *p)
{
    func_02082BCC(p, 0, 0x14);
    p[0x10] = 4;
}




void func_02175EFC(void *w, void *obj, u8 index)
{
    Ent_02175C40 *p = (Ent_02175C40 *)obj;
    int rec;
    p->index = index;
    rec = func_021583EC((void *)func_02026478(((void **)w)[1]), p->index);
    func_020084F8((void *)rec, (u32)p, 8);
    p->flag = func_02008550((const Sub0200852CObj *)rec);
}





/*
 * note:     the unlabelled 2-instruction leaf at 0x02175FB4 (ldrb r0,[r0,#0x10]; bx lr) follows.
 */
void func_02175F34(void *w, Ent_02175F34 *tbl, u32 arg, int idx)
{
    int sv;
    Ent_02175F34 *e;
    Half8 *src;
    int t;
    int u;
    u8 flag;

    sv = func_02026478(((void **)w)[1]);
    e = (Ent_02175F34 *)((u8 *)tbl + idx * 0x28);
    if (e->f10 != 1) {
        src = (Half8 *)func_021583CC((void *)sv, idx);
        t = func_021583EC((void *)sv, idx);
        u = func_0200855C((const struct Sub0200852CObj *)t);
        flag = func_021584F4(u, func_02008530((const struct Sub0200852CObj *)t)) == 0x15;
        *(Half8 *)e = *src;
        e->f11 = flag;
        e->f12 = arg;
        func_02175EFC(w, e->f14, idx);
        e->f10 = 1;
    }
}






int func_02175FB4(u8 *p)
{
    return p[0x10];
}






int func_02175FB8(void *unused, void *obj)
{
    Rec_02175F34 *p = (Rec_02175F34 *)obj;
    int i;

    if (p->t >= 6 || p->a > 0x14 || p->b > 0xb4 || p->c >= 0x2e || p->d >= 0x53) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (p->b10[i] >= 5) return 0;
        if (func_021756B0(p->h0a[i]) == 0) return 0;
    }
    for (i = 0; i < 2; i++) {
        if (p->t == 3) {
            if (func_021756D0(p->h14) == 0) return 0;
        } else if (p->t == 4) {
            if (func_021756D0(p->h16) == 0) return 0;
        }
    }
    return 1;
}





int func_02176048(u8 *a0, Work_02175C40 *p, Src_02175C40 *src, int idx)
{
    Rec *tmp = &p->tmp;

    func_02082BCC(&p->entries[idx], 0, sizeof(Entry));
    if (func_02175B14(a0 + 0x1AC) == 1) {
        p->entries[idx].state = 2;
        return 0;
    }
    if (func_02175FB8(a0 + 0x1AC, src) == 0) {
        p->entries[idx].state = 2;
        return 0;
    }
    if (src->head.kind == 0 || src->head.kind == 3) {
        if (func_020392B8() != 2 || func_0203D1B4() != 2) {
            p->entries[idx].state = 4;
            return 0;
        }
    }
    tmp->head = src->head;
    tmp->name = src->name;
    tmp->idx = idx;
    tmp->b2D = src->name.b10;
    tmp->b2E = src->b2C;
    tmp->h30 = 10;
    tmp->h32 = src->head.f0_22;
    p->entries[idx].rec = *tmp;
    p->entries[idx].state = 1;
    func_02175920(p);
    ((struct Obj12438 *)p)->f190 = func_0203F4FC();
    *((u8 *)p + 0x19C) = 0;
    return 1;
}




/*
 * Lever: split the offset arithmetic and the memset pointer calculation.
 * Once-300 permuter found this semantically unchanged spelling at candidate 74.
 * The three-iteration bound proves i stays 0..2; all call inputs are explicit.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`offset = i;` before `offset = i;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_02176158(int a, u8 *p)
{
    unsigned int offset;
    int i;
    u8 *tmp;
    for (i = 0; i < 3; i++) {
        do {
            offset = i;
            offset = offset * 0x38;
            if (p[0xe8 + offset] != 0) {
                if (func_02173E6C(a, (int)((p + 0xe8) + offset), i) == 1) {
                    tmp = p + 0xe8;
                    tmp = tmp + offset;
                    memset(tmp, 0, 0x38);
                }
            }
        } while (0);
    }
}




/*
 * note:     an unlabelled leaf follows the pool word, at 0x021761C4.
 */
void func_02176194(void *a, Work_02176194 *w)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (w->f197[i] != 0 && func_021740AC((int)a, w->f197[i], i) == 1) {
            w->f197[i] = 0;
        }
    }
}


void func_021761C4(u8 *p, u8 *s)
{
    u8 v = s[0];
    p[0x1a3] = v;
    if (v == 1)
        *(B34 *)(p + 0x78) = *(B34 *)(s + 4);
}





u8 func_021761EC(char *p)
{
    u8 value;
    value = ((u8 *)p)[0x1a3];
    func_02176200(p);
    return value;
}






void func_02176200(char *p)
{
    p[0x1a3] = 0;
}






/*
 * extent: two alignment bytes at 0217622E.
 */
int func_0217620C(u8 *p, int key)
{
    if (func_02175B14(p) == 0) return 0;
    if (p[0xa0] == key) return 1;
    return 0;
}






/*
 * extent: two alignment bytes at 02176256.
 * interface: original +0x1A/+0x1C narrows the full-width call result;
 * the callee's filed u8 return removes this pair (r2: DIFF 9 bytes).
 */
u8 func_02176230(u8 *p, u8 *q)
{
    if (func_02175B14(q) == 0) {
        return (int)func_02012B58((const void *)func_02026478(((void **)p)[1]));
    }
    return q[0xa0];
}





/*
 * extent: two alignment bytes at 0217627E.
 */
int func_02176258(u8 *p)
{
    if (func_0217620C(p + 0x1ac, func_02012B58((const void *)func_02026478(((void **)p)[1]))) == 1) return 1;
    return 0;
}






void func_02176280(void *win, u32 slot, void *src, u32 size, u16 heap, u32 a)
{
    void *buf;

    buf = func_020457B0(size, heap);
    func_02045994(buf, src, size);
    func_0201EE0C(win, slot, buf, a, 1, 2);
    func_02045808(buf);
}



void func_021762C0(void *win, u32 slot, u8 *src, u16 heap)
{
    func_02176280(win, slot, src, 8, heap, ((Flag *)(src + 0x11))->bit);
}




void func_021762D8(const Obj_021762D8 *obj, u8 *a1, void *a2, u16 a3)
{
    int v;

    switch (obj->kind) {
    case 0:
        func_021762C0(a2, 0, a1, a3);
        func_0201EFA4(a2, 1, obj->pos.x, 3, 0, 1);
        break;
    case 1:
        func_021762C0(a2, 0, a1, a3);
        func_0201F184(a2, 1, obj->pos.x);
        break;
    case 2:
        func_021762C0(a2, 0, a1, a3);
        func_0201F184(a2, 1, obj->pos.x);
        break;
    case 3: {
        const Pos *pos = &obj->pos;
        func_021762C0(a2, 0, a1, a3);
        func_0201EF40(a2, 1, pos->x);
        func_0201EFA4(a2, 2, pos->y, 5, 0, 1);
        break;
    }
    case 4:
        func_0201EF40(a2, 0, obj->pos.y);
        func_021762C0(a2, 1, a1, a3);
        break;
    case 5:
        func_021762C0(a2, 0, a1, a3);
        break;
    }
    func_0201EFA4(a2, 2, obj->f0_22, 4, 0, 1);
    v = obj->f0_15;
    if (v > 20) {
        v = 1;
    }
    func_0201EFA4(a2, 3, v, 4, 0, 1);
}





/*
 * Zeroes the six bytes at +6 one at a time, and after each store lets
 * func_021763D8 fill p[key] for key 0..5.  Called from arm9 func_0200BDE4
 * (bl at 0x0200BDF2) and from ov011 at 0x0217644C.
 */
void func_021763BC(u8 *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        p[i + 6] = 0;
        func_021763D8(p, i);
    }
}





void func_021763D8(u8 *p, u32 key)
{
    int sum;
    u32 i;
    u32 lv;

    sum = ((Src_021761EC *)p)->h0c + ((Src_021761EC *)p)->h0e;
    for (i = 0; i < 0xe0; i++) {
        Ent *e = &d_02176C4C[i];
        if (key == e->key && e->f1 <= sum && (e->f3 & 2)) {
            lv = e->f2;
            if (lv == 100 || lv >= func_020056EC(0x65)) {
                p[key] = i;
                return;
            }
        }
    }
}




int func_02176424(u8 *p, u8 *a, u8 *b)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (p[i + 6] == 0) return 0;
        if (p[i + 6] == 1) (*a)++;
        else (*b)++;
    }
    func_021763BC(p);
    return 1;
}





int func_02176454(struct Obj0203159C *a0, int a1, Arg *arg)
{
    u8 *w;
    int n;
    void *list;
    int i;
    int cnt;

    cnt = 0;
    w = func_0203159C(a0, 0x100, 4);
    func_02082BCC(w, 0, 0x100);
    ((struct Obj07335 *)w)->fF4 = func_02031324(4);
    list = func_02012934(func_020120F4((const struct Ctx *)arg->w0));
    func_0201BA34(list);
    n = func_0201AA18(list);
    ((struct Obj07335 *)w)->fF8 = func_0201A920(4);
    for (i = 0; i < n; i++) {
        if (cnt >= arg->b6) {
            break;
        }
        if (func_0201AB34(list, i) == 1) {
            func_0201A98C(((struct Obj07335 *)w)->fF8, func_0201AB28(list, i));
            func_02019CA0(func_0201AB28(((struct Obj07335 *)w)->fF8, cnt), arg->b5);
            cnt++;
        }
    }
    if (cnt <= 0) {
        func_02034714((const char *)d_02177010, 0, (const char *)d_02177010);
    }
    return 1;
}





/*
 * note:     loads overlay 93 (id 0x5D) in state 2 and passes two ov093-resident
 *           data addresses; they carry an ov093 token for that reason.
 */
int func_02176504(void *a0, int *state, Obj_02175C40 *obj, Work *work)
{
    int h;
    int busy;

    h = (int)func_020120F4((const struct Ctx *)obj->w0);
    func_02012138((const struct Ctx *)obj->w0);
    busy = func_02031330((void *)work->wF4);
    if (func_0200FB24() != 0 || func_0203CDBC() == 1) {
        if (*state > 0 && *state < 6) {
            *state = 7;
        }
    }
    switch (*state) {
    case 0:
        func_02013790((u32)work, h, (int)func_020399A8(), 1, 4);
        func_02013128(work, (void *)work->wF8, 0);
        if (func_02039338() < obj->b4) {
            work->b21 = 0;
        } else {
            work->b21 = 1;
        }
        work->w0C = 15;
        work->h18 = 0x490;
        work->h84 = (1 << obj->b4) | (1 << func_02039338());
        work->h76 = 30;
        (*state)++;
        break;
    case 1:
        func_0203A424((char *)((int)func_020399A8()), 0x15, 2, (u16)((1 << obj->b4) | (1 << func_02039338())));
        (*state)++;
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x15, 2) == 1) {
            func_02034AC4((int)ov093_id);
            work->wFC = 1;
            func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
            (*state)++;
        }
        break;
    case 3:
        func_0203A424((char *)((int)func_020399A8()), 0x16, 2, (u16)((1 << obj->b4) | (1 << func_02039338())));
        (*state)++;
        break;
    case 4:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x16, 2) == 1) {
            (*state)++;
        }
        break;
    case 5:
        func_02031348(work->wF4, -1, d_021EFDAC, work);
        (*state)++;
        break;
    case 6:
        if (busy == 0) {
            (*state)++;
        }
        break;
    case 7:
        if (work->wFC == 1) {
            if (func_0203CD98() == 1) {
                func_0203A5E4(0x100);
            }
            func_02034A5C((int)ov093_id);
        }
        func_020130DC(work);
        return 1;
    }
    return 0;
}
