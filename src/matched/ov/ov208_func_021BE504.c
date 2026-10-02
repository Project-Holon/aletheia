/*
 * function: ov208_func_021BE504
 * address:  0x021BE504
 * packet:   pkt_ov208_021BE504
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BD148  0x021BD148  thumb
 *   func_021BD3C0  0x021BD3C0  thumb
 *   func_021BD394  0x021BD394  thumb
 *   func_021BD378  0x021BD378  thumb
 *   data_021C83C8  0x021C83C8  data
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208ActSrc {
    int id;
    u16 x;
    u16 y;
    u16 h8;
    u16 pad;
    u32 fc;
    u32 f10;
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

extern void *func_020490F4(unsigned int id, u16 heap);
extern u32  func_0204AC18(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heap);
extern u32  func_0204A6C8(void *h, u32 a, u32 b, u32 c, u32 heap);
extern u32  func_0204AF28(void *h, u32 a, u32 b, u32 heap);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32  func_021BD148(struct Ov208ActList *list, u32 heap);
extern u32  func_021BD3C0(u32 mgr, int key);
extern void func_021BD394(u32 mgr, int key, int v);
extern void func_021BD378(u32 mgr, int key, int v);
extern struct Ov208ActSrc data_021C83C8[];

void ov208_func_021BE504(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[6];
    struct Ov208ActDesc *d;
    void *h;
    u8 i;

    h = func_020490F4(0x9f, p->heap);
    p->f5c = func_0204AC18(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f60 = func_0204A6C8(h, 0xd, 0, 0, p->heap);
    p->f64 = func_0204AF28(h, 0x1b, 0x2c, p->heap);
    func_02049238(h);
    p->count = 6;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C83C8[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    d = &descs[3];
    d->ha = p->f60;
    d->hc = p->f5c;
    d->he = p->f64;
    d->h10 = 0xe;
    d->h12 = 0xe;
    d->h14 = 0x14;
    d->f18 = 1;
    d->f1c = 0x54c;
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 6;
    list.f8 = p->f28;
    list.fc = 1;
    list.f10 = 0xd;
    list.f14 = 8;
    list.f18 = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0(p->mgr, p->slots[i].src->id);
    func_021BD394(p->mgr, p->slots[1].src->id, 0x110);
    func_021BD394(p->mgr, p->slots[2].src->id, 0x220);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[5].src->id, 0);
        func_021BD378(p->mgr, p->slots[4].src->id, 0);
    }
}
