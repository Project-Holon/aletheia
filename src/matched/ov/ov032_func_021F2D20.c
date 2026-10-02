/*
 * function: func_021F2D20
 * address:  0x021F2D20
 * packet:   pkt_ov032_021F2D20
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the work block must be a struct with the two Ent arrays as members:
 *           raw (p + K)[i] offsets fold the base into one register and the
 *           frame comes out 0x10 bytes short.
 *
 * symbols:
 *   func_021F2D20  0x021F2D20  thumb
 *   func_021F30D4  0x021F30D4  thumb  ov032
 *   func_020490F4  0x020490F4  arm
 *   func_020216B4  0x020216B4  thumb
 *   func_02021640  0x02021640  thumb
 *   func_02049250  0x02049250  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02062A00  0x02062A00  arm
 *   DC_FlushAll    0x02086284  arm
 *   func_02049238  0x02049238  arm
 *   d_021F35BC     0x021F35BC  data  ov032  a2
 *   d_021F35C8     0x021F35C8  data  ov032  a2
 *   d_021F35D4     0x021F35D4  data  ov032  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 count;
    u32 *items;
} ResList;

typedef struct {
    u16 count;
    u16 base;
} ResSpec;

typedef struct {
    ResSpec s[3];
} ResSpec3;

typedef struct {
    void *data;
    void *res;
} Ent;

typedef struct {
    u8 *hdr;
    u32 data;
    void *res;
} Res3;

typedef struct {
    u8 pad0[0x96];
    u16 heap;
    u16 heap2;
    u8 pad9a[0x12];
    u32 fac;
    u8 padb0[0x84];
    ResList l134[3];
    ResList l14c[3];
    ResList l164[3];
    u8 pad17c[0x15c];
    Ent e2[12];
    Ent e1[16];
    Res3 r3b8;
    Res3 r3c4;
} Work;

extern const ResSpec3 d_021F35BC;
extern const ResSpec3 d_021F35C8;
extern const ResSpec3 d_021F35D4;

extern void func_021F30D4(Work *p, ResList *out, const ResSpec *spec, void *arc);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_020216B4(u32 a, void *h, u32 b, u32 heap, u32 c, u32 d, u32 e);
extern void func_02021640(u32 a, u32 b, u32 c, u32 heap, u32 d, u32 e, u32 f);
extern void *func_02049250(void *h, u32 id, u16 heap);
extern void func_02062A98(void *res, u8 **out);
extern void func_02062A00(void *res, void **out);
extern void DC_FlushAll(void);
extern void func_02049238(void *h);

void func_021F2D20(Work *p, void *h)
{
    void *h2;
    ResSpec3 a;
    ResSpec3 b;
    ResSpec3 c;
    int i;

    h2 = func_020490F4(0x20, p->heap);
    a = d_021F35BC;
    func_021F30D4(p, p->l134, a.s, h);
    b = d_021F35D4;
    func_021F30D4(p, p->l164, b.s, h);
    c = d_021F35C8;
    func_021F30D4(p, p->l14c, c.s, h2);
    func_020216B4(p->fac, h, 0, p->heap, 3, 0x1c0, 0);
    func_02021640(p->fac, 0, 1, p->heap, 3, 0x20, 0xe0);
    p->r3c4.res = func_02049250(h, 4, p->heap2);
    func_02062A98(p->r3c4.res, &p->r3c4.hdr);
    p->r3c4.data = *(u32 *)(p->r3c4.hdr + 0xc);
    p->r3b8.res = func_02049250(h2, 0, p->heap2);
    func_02062A98(p->r3b8.res, &p->r3b8.hdr);
    p->r3b8.data = *(u32 *)(p->r3b8.hdr + 0xc);
    for (i = 0; i < 16; i++) {
        p->e1[i].res = func_02049250(h2, i + 0x31, p->heap2);
        func_02062A00(p->e1[i].res, &p->e1[i].data);
    }
    for (i = 0; i < 12; i++) {
        p->e2[i].res = func_02049250(h, i + 7, p->heap2);
        func_02062A00(p->e2[i].res, &p->e2[i].data);
    }
    DC_FlushAll();
    func_02049238(h2);
}
