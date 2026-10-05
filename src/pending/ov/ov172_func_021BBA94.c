/*
 * function: func_021BBA94
 * address:  0x021BBA94
 * packet:   pkt_ov172_021BBA94
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wave D5 lane 02): first full draft from the listing, DIFF (788 bytes differ, same 956-byte size,
 * all 49 call sites resolve). Structure follows ov172_func_021BA2C4: fifteen-object loop (stride 0x1c, three
 * objects each), objects at +0x400/+0x404, a 15-row loop with stride 0x24 (offsets 0x14A+n kept as locals),
 * 15 text windows, three 0xFF bytes, state clears. Residue is register colouring: original keeps a0 in r5,
 * p in r6, the heap id in r7 and the owner in r4; this draft puts a0 in r4, spills the heap id and hoists the
 * constants 0 and 1 into r7 and r5. Declaration order changes did not move it. Not a witness yet.
 * note 2026-10-05 (wD6 lane06): still DIFF (788 bytes). Listing facts for the next lane: i is a u8 spilled
 *   as a word at [sp,#0x18]; j at [sp,#0x14] is the same variable as the 0 stored to d.a/d.b (reloaded for
 *   each); the 0x400 slot is addressed as `lsls r1,r4,#0xa` from a 1 held in r4 that is also the space
 *   argument of the 0x400 and 0x404 objects (a local `one = 1`, D3 lever), while 0x404 is a pool word; the
 *   end test re-derives 0x400 as `movs #1; lsls #0xa`; the seven 0x14A offsets share one pool word.
 *   Main residue: the image keeps a0 r5, p r6, v r7, owner/row r4 and rematerialises 0 and 1 in loop 1;
 *   our build hoists 1 (seven uses in loop 1: the 018 index, the space argument, func_0204B92C) into r5
 *   and spills v. Tried: the `one` local (862 bytes, worse), v as u32 with u32 heap prototypes, v declared
 *   first or last, MK as a static inline function, row removed (inline p + i*0x1c + K). None stops the hoist.
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
extern void func_021BD134(void *c, u8 *p, u32 n);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 a);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *o, unsigned int k);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0204B878(struct Obj *, u16);
extern void *func_02030734(u16 heap, u32 size, u32 c, void *d, u32 e);
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
        row = p + i * 0x1c;
        d.x = 0x80;
        d.y = i * 32 + 0x10;
        d.z = 8;
        d.a = 0x20;
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
        *(u32 *)(row + 0x50) = (u32)MK(a0, p, 5, 1, 9, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(row + 0x50), 0);
    }
    d.x = 0xe0;
    d.y = 0xa8;
    d.z = (func_021BE0EC(a0) == 0) ? 1 : 0xf;
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
        row = p + j * 0x24;
        *(u32 *)(row + o1) = 0;
        *(u32 *)(row + o2) = 0;
        *(u32 *)(row + o3) = 0;
        *(u32 *)(row + o4) = 0;
        *(u8 *)(row + o5) = 0xff;
        *(u32 *)(row + o6) = (u32)func_02030734(v, 0x64, 1, d_021C7234, 0xff + 0x4b);
        *(u8 *)(row + o7) = 0;
    }
    for (k = 0; k < 15; k++) {
        row = p + k * 0x1c;
        *(u32 *)(row + 0x40) = 0;
        *(u32 *)(row + 0x44) = 0;
        *(u8 *)(row + 0x58) = 0xff;
        *(u32 *)(row + 0x54) = func_020450F0(6, 3, (u8)(k * 4 + 1), 0x19, 2, 0xa, 1);
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
        func_021BD134(a0, p, 0x18);
        *(u32 *)(p + 0x38) = 1;
        *(u32 *)(p + 0x18) = 3;
    }
}
