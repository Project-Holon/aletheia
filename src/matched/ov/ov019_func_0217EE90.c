/*
 * function: func_0217EE90
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
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_0217EFE0  0x0217EFE0  thumb  ov019
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

extern void  func_02034714(const char *file, int line, const char *msg);
extern u16  *func_020084F4(u32 a);
extern int   func_02008550(u32 a);
extern void *func_020457B0(int a, int b);
extern void  func_02045924(void *s, u16 *name);
extern void  func_0201EE0C(void *win, int a, void *s, int b, int c, int d);
extern void  func_02045808(void *s);
extern void  func_0201F02C(void *win, int a, u32 b);
extern void *func_02045EC0(void *msg, int id);
extern void  func_0201F048(void *win, int a, int b);
extern void  func_0201F094(void *win, int a, int b, int c);
extern void  func_0217EFE0(u32 a, int n);
extern const char d_021807F8[];

void func_0217EE90(Self *self)
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
        flag = func_02008550(x);
    }

    s = func_020457B0(0x20, 0x41);
    func_02045924(s, buf);
    func_0201EE0C(self->win2804, 0, s, flag, 1, kind);
    func_02045808(s);
    func_0201F02C(self->win2804, 1, x);

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
    func_02045808(t);

    if (sub->rec != 0 && sub->rec->f26 != 0) {
        func_0201F048(self->win2804, 3, sub->rec->f26);
        if (sub->rec->f27 != 0)
            func_0201F094(self->win2804, 4, sub->rec->f26, sub->rec->f27);
    }
    func_0217EFE0(self->sys->f8, kind);
}
