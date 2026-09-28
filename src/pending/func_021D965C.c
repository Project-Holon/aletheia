/*
 * function: func_021D965C
 * address:  0x021D965C
 * packet:   pkt_021D965C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200B358  0x0200B358  thumb
 *   func_0200B204  0x0200B204  thumb
 *   func_0200B074  0x0200B074  thumb
 *   func_0200B078  0x0200B078  thumb
 *   func_02008554  0x02008554  thumb
 *   func_0200DFD8  0x0200DFD8  thumb
 *   func_021E5548  0x021E5548  thumb  ov177
 *   func_021E5D68  0x021E5D68  thumb  ov177
 *
 * Opens the +0x1c profile exchange when none is open: builds a 0xac-byte
 *     profile (0x92 bytes copied from the +0x108 block, three packed byte
 *     triples, the play-time words from the +0x104 save), then hands it to
 *     0x021E5D68 with the +0x04..+0x18 words.
 *
 * Blocker: byte-correct (MATCH, 0 concrete bytes differ); the three calls to
 *     0x0200DFD8 stay wildcarded: it is an unlabelled arm9 Thumb leaf whose
 *     only callers are ov175 (here and func_021D9D50). Seed it and this file
 *     is EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Save {
    u32 f00;
    u32 f04;
    u32 *f08;
    u32 f0c;
    u32 f10;
};

struct Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8 pad20[0xe4];
    struct Save *f104;
    u32 f108;
};

struct Profile {
    u8 name[0x94];
    u32 f94;
    u32 f98;
    u32 f9c;
    u16 fa0;
    u16 fa2;
    u32 fa4;
    u16 fa8;
    u16 faa;
};

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_02012944(u32 a);
extern u32 func_02012EBC(u32 a);
extern u32 func_0200B358(u32 a);
extern u32 func_0200B204(u32 a, u32 b);
extern void *func_0200B074(u32 a);
extern u32 func_0200B078(u32 a, u32 b);
extern u32 func_02008554(u32 a);
extern u32 func_0200DFD8(u32 a, u32 b, u32 c);
extern u32 func_021E5548(u32 a);
extern u32 func_021E5D68(struct Profile *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);

void func_021D965C(struct Obj *obj)
{
    struct Profile prof;
    u32 sys;
    u32 id;
    u32 kind;
    u32 a;
    u32 b;
    u32 data;
    u32 c;

    if (obj->f1c == 0) {
        data = obj->f108;
        sys = func_02012944(*obj->f104->f08);
        id = func_021E5548(obj->f00);
        kind = func_0200B204(func_0200B358(func_02012EBC(*obj->f104->f08)), 0);
        MI_CpuFill8(&prof, 0, sizeof(prof));
        MI_CpuCopy8(func_0200B074(data), &prof, 0x92);
        a = func_0200B078(data, 6);
        b = func_0200B078(data, 5);
        c = func_0200B078(data, 4);
        prof.f94 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        a = func_0200B078(data, 9);
        b = func_0200B078(data, 8);
        c = func_0200B078(data, 7);
        prof.f98 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        prof.f9c = func_02008554(sys);
        prof.fa0 = func_0200DFD8(obj->f104->f10, 10, 0);
        a = func_0200DFD8(obj->f104->f10, 10, 1);
        prof.fa4 = a + func_0200DFD8(obj->f104->f10, 10, 2);
        prof.faa = func_0200B078(data, 11);
        if (prof.fa4 == 0 && prof.fa0 == 0)
            prof.fa0 = 1500;
        obj->f1c = func_021E5D68(&prof, 0, sys, id, obj->f04, obj->f08, obj->f10, obj->f14, obj->f18, kind, 0, 0x57);
    }
}
