/*
 * file:     zukan_detail_graphic_p15.c
 * unit:     yes
 * function: func_021BE170, func_021BE1BC, func_021BE20C, func_021BE300, func_021BE32C, func_021BE378, func_021BE3C4
 * address:  0x021BE170
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD3C0  0x021BD3C0  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BD148  0x021BD148  thumb
 *   data_021C8390  0x021C8390  data
 */
struct Obj;
typedef unsigned int u32;

struct Ov208Slot_021BE170 {
    int *key;
    u32 f4;
};

struct Ov208Scene_021BE170 {
    u32 pad0[7];
    u32 f1c;
    u32 pad20[4];
    u32 mgr;
    u32 pad34[14];
    struct Ov208Slot_021BE170 slots[10];
};

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16_021BE1BC;

struct Ov208ActDesc {
    int f0;
    s16_021BE1BC x;
    s16_021BE1BC y;
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

struct Ov208Slot_021BE1BC {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene_021BE1BC {
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
    struct Ov208Slot_021BE1BC slots[10];
};

typedef short s16_021BE20C;

struct Ov208Pal {
    char pad[0xb6];
    u16 a[16];
    u16 b[16];
    u16 out[16];
    int phase;
};

typedef signed int     s32;

typedef signed short   s16_021BE3C4;

struct Ov208Slot_021BE3C4 {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene_021BE3C4 {
    u16 heap;
    u16 pad2;
    u32 pad4[9];
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 pad34[7];
    u32 f50;
    u32 f54;
    u32 f58;
    u32 pad5c[3];
    u8  count;
    u8  pad69[3];
    struct Ov208Slot_021BE3C4 slots[10];
};

extern int func_021BD3C0(void *mgr, int key);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32  func_021BD148(struct Ov208ActList *list, u32 heap);
void ov208_func_021BE170(struct Ov208Scene_021BE170 *p);
void ov208_func_021BE1BC(struct Ov208Scene_021BE1BC *p);
s32 func_021BE20C(struct Ov208Pal *m);
int func_021BE300(int kind);
unsigned func_021BE32C(unsigned n);
unsigned func_021BE378(unsigned n);
void ov208_func_021BE3C4(struct Ov208Scene_021BE3C4 *p);
extern s16_021BE20C tbl_020A1B38[];
extern struct Ov208ActSrc data_021C8390[];


void ov208_func_021BE170(struct Ov208Scene_021BE170 *p)
{
    u32 idx = 9;

    switch (p->f1c) {
    case 0:
        idx = 6;
        break;
    case 1:
        idx = 5;
        break;
    case 2:
        idx = 4;
        break;
    case 3:
        idx = 3;
        break;
    }
    if (idx != 9)
        func_0204B6F4((struct Obj *)func_021BD3C0((void *)p->mgr, *p->slots[idx].key), 2, 0);
}


void ov208_func_021BE1BC(struct Ov208Scene_021BE1BC *p)
{
    int slot = 9;

    switch (p->f1c) {
    case 0:
        slot = 6;
        break;
    case 1:
        slot = 5;
        break;
    case 2:
        slot = 4;
        break;
    case 3:
        slot = 3;
        break;
    }
    if (slot != 9) {
        func_0204B6F4((struct Obj *)func_021BD3C0((void *)p->mgr, p->slots[slot].src->id), 0, 0);
        p->f1c = 4;
    }
}

s32 func_021BE20C(struct Ov208Pal *m)
{
    s16_021BE20C t;
    u8 i;
    if (m->phase + 0x400 >= 0x10000)
        m->phase -= 0xfc00;
    else
        m->phase += 0x400;
    t = (tbl_020A1B38[2 * (m->phase >> 4) + 1] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u16 c1 = m->a[i];
        u16 c2 = m->b[i];
        u8 r1 = c1 & 0x1f;
        u8 g1 = (c1 & 0x3e0) >> 5;
        u8 b1 = (c1 & 0x7c00) >> 10;
        u8 r2 = c2 & 0x1f;
        u8 g2 = (c2 & 0x3e0) >> 5;
        u8 b2 = (c2 & 0x7c00) >> 10;
        u8 r = r1 + ((r2 - r1) * t >> 12);
        u8 g = g1 + ((g2 - g1) * t >> 12);
        u8 b = b1 + ((b2 - b1) * t >> 12);
        m->out[i] = r | g << 5 | b << 10;
    }
    return func_02061CA4((void *)14, 0x1a0, (u32)m->out, 0x20);
}

/*
 * Returns 6, 5, 4 or 3 for the four known kinds and 9 for anything else.
 */
int func_021BE300(int kind)
{
    switch (kind) {
    case 0:
        return 6;
    case 1:
        return 5;
    case 2:
        return 4;
    case 3:
        return 3;
    }
    return 9;
}

/*
 * trailing: 021BE376..021BE378 is two-byte zero alignment padding.
 */
unsigned func_021BE32C(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 6;
    case 7: case 16: return 5;
    case 8: case 17: return 4;
    case 9: case 18: return 3;
    default: break;
    }
    return 9;
}

/*
 * trailing: 021BE3C2..021BE3C4 is two-byte zero alignment padding.
 */
unsigned func_021BE378(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 0;
    case 7: case 16: return 1;
    case 8: case 17: return 2;
    case 9: case 18: return 3;
    default: break;
    }
    return 4;
}


void ov208_func_021BE3C4(struct Ov208Scene_021BE3C4 *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[1];
    void *h;
    u8 i;

    h = func_020490F4(0x55, p->heap);
    p->f50 = func_0204AC18(h, 2, 0, 0x160, 2, 3, p->heap);
    p->f54 = func_0204A6C8(h, 8, 0, 0, p->heap);
    p->f58 = func_0204AF28(h, 0xc, 0x13, p->heap);
    func_02049238(h);
    p->count = 1;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8390[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 1;
    list.f8 = p->f28;
    list.fc = 1;
    list.f10 = 0xd;
    list.f14 = 8;
    list.f18 = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0((void *)p->mgr, p->slots[i].src->id);
}
