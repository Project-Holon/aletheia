/*
 * function: func_021BBA94
 * address:  0x021BBA94
 * packet:   pkt_ov172_021BBA94
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Scene setup: fifteen rows of three sprite objects (stride 0x1c), the objects at +0x400 and
 * +0x404, fifteen 0x24-byte entries with text buffers, fifteen windows, then state clears.
 * note 2026-10-05 (wD7 lane03): EXACT. Closing levers: the d.z choice as an if/else (the ternary
 * gave the inverted branch layout and changed the whole colouring), the missing `d.a = 0x10` in
 * the third object of each row (logic error in the draft), row computed after the descriptor
 * stores, and separate pointer locals for loop 2 and loop 3 (spill slots 0x10 and 0xc).
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE010  0x021BE010  thumb  ov172
 *   func_021BE018  0x021BE018  thumb  ov172
 *   func_021BE024  0x021BE024  thumb  ov172
 *   func_021BE004  0x021BE004  thumb  ov172
 *   func_021BE0EC  0x021BE0EC  thumb  ov172
 *   func_021BD134  0x021BD134  thumb  ov172
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B878  0x0204B878  arm
 *   func_02030734  0x02030734  arm
 *   d_021C7234     0x021C7234  data
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

struct Obj;
extern u16 func_021BE00C(u16 *p);
extern u32  func_021BE010(void *c);
extern u32  func_021BE018(void *c, int i);
extern u32  func_021BE024(void *c);
extern u32 func_021BE004(void *p);
extern u32 func_021BE0EC(void *c);
extern void func_021BD134(void *ctx, char *st, u32 msgId);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 a);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *o, unsigned int k);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0204B878(struct Obj *, u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 d_021C7234[];

#define MK(c, p, a1, a2, a3, sp) func_0204B294((void *)func_021BE024(c), func_021BE018(c, a1), func_021BE018(c, a2), func_021BE018(c, a3), &d, sp, v)

void func_021BBA94(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u32 o;
    u8 i;
    u8 j;
    u8 k;
    u8 z;
    u8 *row;
    u8 *ent;
    u8 *slot;
    u32 owner;
    int o1, o2, o3, o4, o5, o6, o7;

    v = func_021BE00C(a0);
    owner = func_021BE010(a0);
    o = func_021BE004(a0);
    if (*(u32 *)(o + 4) != 2 && *(u32 *)(o + 4) != 3 && func_021BE0EC(a0) == 0) {
        func_02049658((void *)owner, 0xb, 4, 0, 0xa << 10, 0, v);
        func_020498F4((void *)owner, 0x12, 4, 0, 0, 0, v);
        func_020409B4(4);
    }
    d.b = 3;
    for (i = 0; i < 15; i++) {
        d.x = 0x80;
        d.y = i * 32 + 0x10;
        d.z = 8;
        d.a = 0x20;
        row = p + i * 0x1c;
        *(u32 *)(row + 0x48) = (u32)MK(a0, p, 5, 1, 9, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(row + 0x48), 0);
        func_0204B92C((struct Obj *)*(u32 *)(row + 0x48), 1);
        d.x = 0x12;
        d.z = 9;
        d.a = 0x10;
        *(u32 *)(row + 0x4c) = (u32)MK(a0, p, 5, 1, 9, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(row + 0x4c), 0);
        d.x = 0xc8;
        d.z = 0x12;
        d.a = 0x10;
        *(u32 *)(row + 0x50) = (u32)MK(a0, p, 5, 1, 9, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(row + 0x50), 0);
    }
    d.x = 0xe0;
    d.y = 0xa8;
    if (func_021BE0EC(a0) == 0)
        d.z = 1;
    else
        d.z = 0xf;
    j = 0;
    d.a = j;
    d.b = j;
    *(u32 *)(p + 0x400) = (u32)MK(a0, p, 6, 2, 10, 1);
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0x400), 1);
    func_0204B92C((struct Obj *)*(u32 *)(p + 0x400), 1);
    d.x = 0xf8;
    d.y = 0x18;
    d.z = 0xc;
    *(u32 *)(p + 0x404) = (u32)MK(a0, p, 5, 1, 9, 1);
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0x404), 0);
    o1 = 0x14A;
    o1 += 0x9a;
    o2 = 0x14A;
    o2 += 0x9e;
    o3 = 0x14A;
    o3 += 0xa2;
    o4 = 0x14A;
    o4 += 0xaa;
    o5 = 0x14A;
    o5 += 0xba;
    o6 = 0x14A;
    o6 += 0xae;
    o7 = 0x14A;
    o7 += 0xb9;
    for (j = 0; j < 15; j++) {
        ent = p + j * 0x24;
        *(u32 *)(ent + o1) = 0;
        *(u32 *)(ent + o2) = 0;
        *(u32 *)(ent + o3) = 0;
        *(u32 *)(ent + o4) = 0;
        *(u8 *)(ent + o5) = 0xff;
        *(u32 *)(ent + o6) = (u32)func_02030734(v, 0x64, 1, (const char *)d_021C7234, 0xff + 0x4b);
        *(u8 *)(ent + o7) = 0;
    }
    for (k = 0; k < 15; k++) {
        slot = p + k * 0x1c;
        *(u32 *)(slot + 0x40) = 0;
        *(u32 *)(slot + 0x44) = 0;
        *(u8 *)(slot + 0x58) = 0xff;
        *(u32 *)(slot + 0x54) = func_020450F0(6, 3, (u8)(k * 4 + 1), 0x19, 2, 0xa, 1);
    }
    *(u32 *)(p + 0x2c) = func_020450F0(4, 1, 0x15, 0x15, 2, 0xa, 1);
    *(u32 *)(p + 0x30) = func_020450F0(4, 2, 9, 0x1c, 2, 0xa, 1);
    z = 0;
    *(u32 *)(p + 0x38) = z;
    *(u16 *)(p + 0x36) = z;
    for (z = 0; z < 3; z++) {
        p[z] = 0xff;
    }
    p[3] = 0xff;
    *(u16 *)(p + 4) = 0;
    *(u16 *)(p + 6) = 0;
    p[0x14] = 0;
    p[0x15] = 0xff;
    *(u32 *)(p + 0x18) = 0xff;
    *(u32 *)(p + 0xc) = 0;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x20) = 0;
    *(u32 *)(p + 0x24) = 0;
    *(u32 *)(p + 0x28) = 0;
    *(u32 *)(p + 0x1c) = 0;
    *(u32 *)(p + 8) = 0;
    *(u16 *)(p + 0x34) = 0;
    func_02041EE4(6, 3, 0);
    if ((u32)(*(u32 *)(o + 4) - 2) <= 1 && func_021BE0EC(a0) == 0) {
        func_0204B878((struct Obj *)*(u32 *)(p + 0x400), 0xf);
        func_021BD134(a0, (char *)p, 0x18);
        *(u32 *)(p + 0x38) = 1;
        *(u32 *)(p + 0x18) = 3;
    }
}
