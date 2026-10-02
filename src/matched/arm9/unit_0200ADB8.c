/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200ADB8
 * packet:   pkt_0200ADB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200ADB8, func_0200ADD0, func_0200ADD8, func_0200ADE0,
 *           func_0200ADE8, func_0200ADF0, func_0200AE08, func_0200AE14,
 *           func_0200AE18, func_0200AE3C, func_0200AE54, func_0200AEE8,
 *           func_0200AFD4, func_0200B040, func_0200B074, func_0200B078,
 *           func_0200B110, func_0200B1A8, func_0200B1C4, func_0200B1D4,
 *           func_0200B1E0, func_0200B1F8, func_0200B204, func_0200B214,
 *           func_0200B254
 *
 * symbols:
 *   func_0200ADF0_File  0x020A71B4  data
 *
 * alias: the original source file is named in the image.  The constructor at
 * 0x0200ADF0 passes 0x020A71B4 to the debug allocator at 0x02030734, and the
 * bytes there spell "regulation.c"; the string before it is
 * "mystery_data.c", which is what the `string` attestation class uses to fix
 * the address without reading the pool word under test.  That makes this the
 * second original source file name this project has recovered, after
 * "playtime.c".  The functions keep their func_<address> names, because the
 * file identity is attested and the individual entry points are not.
 *
 * 1260 bytes, 0x0200ADB8..0x0200B2A4, 25 functions, eleven of which carry no
 * label in the generated listing.
 *
 * What a regulation is, read off the accessors: a 0xBC-byte record of
 * battle-rule settings.  The pair at 0x0200AE54 and 0x0200AEE8 is its whole
 * scalar interface, a get and a set indexed by a rule id in 0..22, and the
 * set carries the legal range of every rule: ids 0 to 3 take a value under 7,
 * 6 and 6 and 6; id 4 is capped at 100; id 6 at 600; ids 7, 8, 13, 17 and 19
 * are booleans; id 11 is a u16 under 651; id 20 is capped at 99.  Ids 9, 10
 * and 14 are missing from both tables because they are not scalars: they are
 * the three bitmaps at +0x0A, +0x5C and +0xAC that func_0200AFD4 tests a bit
 * of.  A second pair at 0x0200B078 and 0x0200B110 does the same job for a
 * larger record that contains this one at offset 0, over ids 1..12 and a set
 * of signed fields at 0x152..0x15D.  0x0200B1A8 checks the record against the
 * checksum stored at +0x15E.
 *
 * Four things here are worth naming:
 *
 *  - a dense switch becomes a PC-relative halfword jump table, and the whole
 *    of it, table included, comes out of ordinary C.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The table
 *    is what reads the case list back: an entry pointing at the common exit
 *    is a case that is absent from the source, which is how ids 9, 10 and 14
 *    above are known to be missing rather than empty.
 *  - func_0200B078 falls off the end of its switch with no return statement,
 *    and the original's default arm is a bare `bx lr` that returns the
 *    incoming pointer.  Adding a `return 0;` to make the C well-formed adds
 *    an instruction and moves every case body.
 *  - a 0x160-byte struct assignment is an inline eight-byte `ldm`/`stm` loop
 *    rather than a call, but only when the struct is four-aligned; declared
 *    as a `u8` array it is a byte loop instead.  See
 *    docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *  - `p->unk12 >> n` on a `u8` field is an *arithmetic* shift, because the
 *    field promotes to `int` before the shift.  Writing the field as `u32`,
 *    or casting, gives `lsrs` and two bytes wrong in func_0200B214.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u32   func_020173EC(void *p);
extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern void *func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern void  func_02045CAC(void *g, u32 id, void *dest);
extern void  func_02045C04(void *g);
extern u16   func_0203F1FC(void *p, u32 size);
extern void *func_020457B0(u32 size, u32 heap);
extern const char func_0200ADF0_File[];

struct Reg {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    u16 unk06;
    u8  unk08;
    u8  unk09;
    u8  unk0A[0x52];
    u8  unk5C[0x4C];
    u16 unkA8;
    u8  unkAA;
    u8  unkAB;
    u8  unkAC[7];
    u8  unkB3;
    u8  unkB4;
    u8  unkB5;
    u8  unkB6;
    u8  unkB7;
    u8  unkB8;
    u8  unkB9;
    u8  unkBA;
    u8  unkBB;
};

struct RegB {
    u8  unk00[0xEE];
    u16 unkEE;
    u32 unkF0;
    u32 unkF4;
};

void func_0200AE18(struct Reg *p, void *dest);

void func_0200ADB8(void *dest, const void *src)
{
    MI_CpuCopy8(src, dest, func_020173EC(dest));
}

void func_0200ADD0(struct RegB *p, u32 value)
{
    p->unkF0 = value;
}

void func_0200ADD8(struct RegB *p, u32 value)
{
    p->unkF4 = value;
}

u16 func_0200ADE0(struct RegB *p)
{
    return p->unkEE;
}

u32 func_0200ADE8(void)
{
    return 0x2FC;
}

struct Reg *func_0200ADF0(u32 heap)
{
    return func_02030734(heap, sizeof(struct Reg), 1, func_0200ADF0_File,
                         0x73);
}

void func_0200AE08(const struct Reg *src, struct Reg *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Reg));
}

void func_0200AE14(void)
{
}

void func_0200AE18(struct Reg *p, void *dest)
{
    void *g = func_02045B38(0, 2, 0xA6, 1);

    func_02045CAC(g, *(u8 *)p, dest);
    func_02045C04(g);
}

void *func_0200AE3C(struct Reg *p, u32 heap)
{
    void *dest = func_020457B0(0x1A, heap);

    func_0200AE18(p, dest);
    return dest;
}

u32 func_0200AE54(struct Reg *p, u32 id)
{
    u32 v = 0;

    switch (id) {
    case 0:  v = p->unk00; break;
    case 1:  v = p->unk01; break;
    case 2:  v = p->unk02; break;
    case 3:  v = p->unk03; break;
    case 4:  v = p->unk04; break;
    case 5:  v = p->unk05; break;
    case 6:  v = p->unk06; break;
    case 7:  v = p->unk08; break;
    case 8:  v = p->unk09; break;
    case 11: v = p->unkA8; break;
    case 12: v = p->unkAA; break;
    case 13: v = p->unkAB; break;
    case 15: v = p->unkB3; break;
    case 16: v = p->unkB4; break;
    case 17: v = p->unkB5; break;
    case 18: v = p->unkB6; break;
    case 19: v = p->unkB8; break;
    case 20: v = p->unkB9; break;
    case 21: v = p->unkBA; break;
    case 22: v = p->unkBB; break;
    }
    return v;
}

void func_0200AEE8(struct Reg *p, u32 id, s32 value)
{
    switch (id) {
    case 0:  if (value < 7)     { p->unk00 = value; } break;
    case 1:  if (value < 6)     { p->unk01 = value; } break;
    case 2:  if (value < 6)     { p->unk02 = value; } break;
    case 3:  if (value < 6)     { p->unk03 = value; } break;
    case 4:  if (value <= 100)  { p->unk04 = value; } break;
    case 5:  if (value <= 6)    { p->unk05 = value; } break;
    case 6:  if (value <= 600)  { p->unk06 = value; } break;
    case 7:  if (value < 2)     { p->unk08 = value; } break;
    case 8:  if (value < 2)     { p->unk09 = value; } break;
    case 11: if (value < 0x28B) { p->unkA8 = value; } break;
    case 12: p->unkAA = value; break;
    case 13: if (value < 2)     { p->unkAB = value; } break;
    case 15: p->unkB3 = value; break;
    case 16: p->unkB4 = value; break;
    case 17: if (value < 2)     { p->unkB5 = value; } break;
    case 18: p->unkB6 = value; break;
    case 19: if (value < 2)     { p->unkB8 = value; } break;
    case 20: if (value <= 0x63) { p->unkB9 = value; } break;
    case 21: if (value < 6)     { p->unkBA = value; } break;
    case 22: p->unkBB = value; break;
    }
}

u32 func_0200AFD4(struct Reg *p, u32 id, s32 n)
{
    s32 byte = n / 8;
    s32 bit  = n % 8;

    switch (id) {
    case 9:
        if (p->unk0A[byte] & (1 << bit)) {
            return 1;
        }
        break;
    case 10:
        if (p->unk5C[byte] & (1 << bit)) {
            return 1;
        }
        break;
    case 14:
        if (p->unkAC[byte] & (1 << bit)) {
            return 1;
        }
        break;
    }
    return 0;
}

struct RegAC {
    u8 unk0[7];
    u8 unk7;
};

void func_0200B040(struct Reg *p, struct RegAC *out)
{
    MI_CpuFill8(out, 0, sizeof(struct RegAC));
    out->unk7 = func_0200AE54(p, 13);
    if (out->unk7 >= 2) {
        out->unk7 = 1;
    }
    MI_CpuCopy8(p->unkAC, out, 7);
}

struct Reg2 {
    struct Reg reg;
    s32 unkBC;
    u8  unkC0[0x92];
    s16 unk152;
    s8  unk154;
    s8  unk155;
    s8  unk156;
    s8  unk157;
    s8  unk158;
    s8  unk159;
    s8  unk15A;
    s8  unk15B;
    u8  unk15C;
    u8  unk15D;
    u16 unk15E;
};

u8 *func_0200B074(struct Reg2 *p)
{
    return p->unkC0;
}

s32 func_0200B078(struct Reg2 *p, u32 id)
{
    switch (id) {
    case 1:  return p->unkBC;
    case 2:  return p->unk152;
    case 3:  return p->unk154;
    case 4:  return p->unk155;
    case 5:  return p->unk156;
    case 6:  return p->unk157;
    case 7:  return p->unk158;
    case 8:  return p->unk159;
    case 9:  return p->unk15A;
    case 10: return p->unk15B;
    case 11: return p->unk15C;
    case 12: return p->unk15D;
    }
}

void func_0200B110(struct Reg2 *p, u32 id, s32 value)
{
    switch (id) {
    case 1:  p->unkBC  = value; break;
    case 2:  p->unk152 = value; break;
    case 3:  p->unk154 = value; break;
    case 4:  p->unk155 = value; break;
    case 5:  p->unk156 = value; break;
    case 6:  p->unk157 = value; break;
    case 7:  p->unk158 = value; break;
    case 8:  p->unk159 = value; break;
    case 9:  p->unk15A = value; break;
    case 10: p->unk15B = value; break;
    case 11: p->unk15C = value; break;
    case 12: p->unk15D = value; break;
    }
}

struct Rec160 {
    u32 unk000[0x58];
};

struct Rec1E {
    u16 unk00[6];
    u8  unk0C[6];
    u8  unk12;
    u8  unk13;
    u8  unk14[10];
};

struct RecBig {
    u8 unk000[0x2C0];
    struct Rec1E unk2C0[1];
};

u16 func_0200B1C4(struct Reg2 *p);

u32 func_0200B1A8(struct Reg2 *p)
{
    if (p->unk15E == func_0200B1C4(p)) {
        return 1;
    }
    return 0;
}

u16 func_0200B1C4(struct Reg2 *p)
{
    return func_0203F1FC(p, 0x15E);
}

struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index)
{
    return &arr[index];
}

void func_0200B1E0(struct Rec160 *arr, u32 index, const struct Rec160 *src)
{
    arr[index] = *src;
}

void func_0200B1F8(struct Rec1E *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec1E));
}

struct Rec1E *func_0200B204(struct RecBig *p, u32 index)
{
    return &p->unk2C0[index];
}

s32 func_0200B214(struct Rec1E *p, u32 id, u32 n)
{
    switch (id) {
    case 0: return p->unk00[n];
    case 1: return p->unk0C[n];
    case 2: return (p->unk12 >> n) & 1;
    case 3: return (p->unk13 >> n) & 1;
    }
    return 0;
}

void func_0200B254(struct Rec1E *p, u32 id, u32 n, s32 value)
{
    switch (id) {
    case 0: p->unk00[n] = value; break;
    case 1: p->unk0C[n] = value; break;
    case 2: p->unk12 |= (u8)((value == 1) << n); break;
    case 3: p->unk13 |= (u8)((value == 1) << n); break;
    }
}
