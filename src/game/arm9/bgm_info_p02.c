/*
 * file:     bgm_info_p02.c
 * unit:     yes
 * function: sub_02006D44, sub_02006D64, sub_02006D94, func_02006DAC, func_02006DD8, func_02006E18, func_02006E2C, func_02006E40, func_02006E64, func_02006E7C, func_02006EA4
 * address:  0x02006D44
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02006D44_Ptr  0x02146164  data
 *   func_020307B0     0x020307B0  arm
 *   PM_SetAmp         0x0208BEF0  arm
 *   sub_02006DAC_Ptr           0x02146164  data
 *   MIC_AdjustLimitedSampling  0x0208B500  arm
 *   func_02006E2C  0x02006E2C  thumb
 *   func_02007BD0  0x02007BD0  thumb
 *   sub_02006E2C_Ptr    0x02146164  data
 *   sub_02006E40_File  0x020A7048  data
 *   func_02030734      0x02030734  arm
 *   func_02048F74      0x02048F74  arm
 */
struct PerapVoice;
typedef unsigned int u32;

struct Sub02006D44Obj {
    u32   unk00[7];
    u32   unk1C;
    u32   unk20_0 : 1;
    u32   unk20_1 : 31;
    void *unk24;
};

struct Sub02006DACParam {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub02006DACObj {
    struct Sub02006DACParam unk00;
    u32 unk1C;
};

typedef signed char    s8;

struct Sub02006E2CObj {
    u32 unk00[9];
    u32 unk24;
};

typedef unsigned char  u8;

typedef unsigned short u16;

struct Sub02006E40Obj {
    u8   count;
    u8   pad01[3];
    u16 *unk04;
    u8  *unk08;
};

extern u32 func_020307B0(void *p);
extern void PM_SetAmp(u32 on);
extern u32 MIC_AdjustLimitedSampling(const struct Sub02006DACParam *param);
extern u32 func_02006E2C(void);
extern void func_02007BD0(struct PerapVoice *p, const s8 *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
void sub_02006EA4(struct Sub02006E40Obj *obj, u32 heap);
void func_02006E18(void *a0);
u32 sub_02006E2C(void);
struct Sub02006E40Obj *sub_02006E40(u32 heap);
void sub_02006D44(void);
void sub_02006D64(u32 n);
u32 sub_02006D94(void);
extern struct Sub02006D44Obj *sub_02006D44_Ptr;
extern struct Sub02006DACObj *sub_02006DAC_Ptr;
extern struct Sub02006E2CObj *sub_02006E2C_Ptr;
extern const char sub_02006E40_File[];


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The tail of "snd_mic.c": the teardown of the microphone object and the two
 * functions that own the counter at +0x20.  The object is the one
 * src/matched/unit_02006DAC.c and src/matched/sub_02006E2C.c reach through
 * the same pointer at 0x02146164: seven words of MICAutoParam at +0, a flag
 * word at +0x1C, the packed word at +0x20 and the sampling buffer at +0x24,
 * which is 0x28 bytes and is exactly what the constructor at 0x02006CBC
 * allocates and clears.
 *
 * The word at +0x20 is two unsigned bitfields, one bit at bit 0 and thirty
 * one bits at bit 1, and all three functions here turn on that declaration:
 *
 *  - sub_02006D94 reads the wide field with a bare `lsrs r0, r0, #1` and no
 *    mask, which is only correct because the field runs to the top of the
 *    word.  A plain u32 shifted by hand gives the same instruction here but
 *    not in sub_02006D64;
 *  - sub_02006D64 writes it back with `movs r0, #1` / `ands r2, r0` /
 *    `lsrs r0, r1, #1` / `adds` / `lsls r0, r0, #1` / `orrs r0, r2`, which is
 *    the read modify write of a bitfield that has to preserve bit 0.  Written
 *    as `w = (w & 1) | ((((w >> 1) + n) << 1))` this compiler materialises the
 *    mask differently and reorders the two halves;
 *  - sub_02006D64 tests bit 0 with `lsls #0x1f` / `lsrs #0x1f`, the one bit
 *    case of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * The range starts at 0x02006D44 rather than earlier because 0x02006D3C is
 * four bytes of ARM: `ldr pc, [pc, #-4]` over the pointer word at 0x02006D40,
 * a linker veneer, which no compiler input produces.  What is left out below
 * it is recorded in the header of src/matched/unit_02006B20.c.
 */
void sub_02006D44(void)
{
    PM_SetAmp(0);
    func_020307B0(sub_02006D44_Ptr->unk24);
    func_020307B0(sub_02006D44_Ptr);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The tail of "snd_mic.c": the teardown of the microphone object and the two
 * functions that own the counter at +0x20.  The object is the one
 * src/matched/unit_02006DAC.c and src/matched/sub_02006E2C.c reach through
 * the same pointer at 0x02146164: seven words of MICAutoParam at +0, a flag
 * word at +0x1C, the packed word at +0x20 and the sampling buffer at +0x24,
 * which is 0x28 bytes and is exactly what the constructor at 0x02006CBC
 * allocates and clears.
 *
 * The word at +0x20 is two unsigned bitfields, one bit at bit 0 and thirty
 * one bits at bit 1, and all three functions here turn on that declaration:
 *
 *  - sub_02006D94 reads the wide field with a bare `lsrs r0, r0, #1` and no
 *    mask, which is only correct because the field runs to the top of the
 *    word.  A plain u32 shifted by hand gives the same instruction here but
 *    not in sub_02006D64;
 *  - sub_02006D64 writes it back with `movs r0, #1` / `ands r2, r0` /
 *    `lsrs r0, r1, #1` / `adds` / `lsls r0, r0, #1` / `orrs r0, r2`, which is
 *    the read modify write of a bitfield that has to preserve bit 0.  Written
 *    as `w = (w & 1) | ((((w >> 1) + n) << 1))` this compiler materialises the
 *    mask differently and reorders the two halves;
 *  - sub_02006D64 tests bit 0 with `lsls #0x1f` / `lsrs #0x1f`, the one bit
 *    case of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * The range starts at 0x02006D44 rather than earlier because 0x02006D3C is
 * four bytes of ARM: `ldr pc, [pc, #-4]` over the pointer word at 0x02006D40,
 * a linker veneer, which no compiler input produces.  What is left out below
 * it is recorded in the header of src/matched/unit_02006B20.c.
 */
void sub_02006D64(u32 n)
{
    struct Sub02006D44Obj *obj = sub_02006D44_Ptr;

    if (obj->unk20_0) {
        if (sub_02006D94() == 0) {
            obj->unk20_1 += n;
        }
    }
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The tail of "snd_mic.c": the teardown of the microphone object and the two
 * functions that own the counter at +0x20.  The object is the one
 * src/matched/unit_02006DAC.c and src/matched/sub_02006E2C.c reach through
 * the same pointer at 0x02146164: seven words of MICAutoParam at +0, a flag
 * word at +0x1C, the packed word at +0x20 and the sampling buffer at +0x24,
 * which is 0x28 bytes and is exactly what the constructor at 0x02006CBC
 * allocates and clears.
 *
 * The word at +0x20 is two unsigned bitfields, one bit at bit 0 and thirty
 * one bits at bit 1, and all three functions here turn on that declaration:
 *
 *  - sub_02006D94 reads the wide field with a bare `lsrs r0, r0, #1` and no
 *    mask, which is only correct because the field runs to the top of the
 *    word.  A plain u32 shifted by hand gives the same instruction here but
 *    not in sub_02006D64;
 *  - sub_02006D64 writes it back with `movs r0, #1` / `ands r2, r0` /
 *    `lsrs r0, r1, #1` / `adds` / `lsls r0, r0, #1` / `orrs r0, r2`, which is
 *    the read modify write of a bitfield that has to preserve bit 0.  Written
 *    as `w = (w & 1) | ((((w >> 1) + n) << 1))` this compiler materialises the
 *    mask differently and reorders the two halves;
 *  - sub_02006D64 tests bit 0 with `lsls #0x1f` / `lsrs #0x1f`, the one bit
 *    case of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * The range starts at 0x02006D44 rather than earlier because 0x02006D3C is
 * four bytes of ARM: `ldr pc, [pc, #-4]` over the pointer word at 0x02006D40,
 * a linker veneer, which no compiler input produces.  What is left out below
 * it is recorded in the header of src/matched/unit_02006B20.c.
 */
u32 sub_02006D94(void)
{
    if (sub_02006D44_Ptr->unk20_1 > 0xB4) {
        return 1;
    }
    return 0;
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The microphone sampling request and its one caller.  The record both
 * functions pass around is seven words, and the SDK call at 0x0208B500 is
 * MIC_AdjustLimitedSampling in layout/symbols_sdk.txt, so the record is a
 * MICAutoParam: type, buffer, size, rate, loop flag, callback and callback
 * argument, in that order, which is exactly the seven stores sub_02006DD8
 * makes and exactly the 0x1C bytes sub_02006DAC copies.  The fields are
 * still spelled unkXX here because only the SDK call attests the shape, not
 * the meaning of the two constants.
 *
 * sub_02006DAC reads the global pointer at 0x02021664 twice, once for the
 * flag word at +0x1C and once for the copy, because the store through the
 * first load can alias the pointer itself and the compiler has to reload it.
 * That reload is not a second variable in the source.  The copy is the
 * unrolled aggregate assignment of
 * docs/idioms/aggregate-assignment-is-ldm-stm.md: 0x1C bytes is three
 * ldm/stm pairs and a trailing ldr/str, and it says the seven words are one
 * nested struct rather than seven fields.
 *
 * The two constants sub_02006DD8 stores come out of literal pools, and the
 * round down of the first is emitted as a live test and mask rather than
 * folded: `movs r0, #0x1f; tst r0, r1; beq; movs r0, #0x1f; bics r1, r0`,
 * with the mask materialised twice because Thumb has no immediate bic.  The
 * compiler does not constant fold it even though the value is a pool word,
 * so the guard is in the source and not an artefact.
 *
 * What is left out of this range, and why, is sub_02006E18 at
 * 0x02006E18..0x02006E2A, eighteen bytes that reproduce every concrete byte
 * and cap at MATCH.  It is `sub_02007BD0(a, sub_02006E2C());` and the
 * evidence for 0x02007BD0 is the `bl` at 0x02006E24 inside that very
 * the function list: the census is one witness image wide, one of them inside the
 * range, so no cut can free it.  The `literal` class has nothing either,
 * because no pool word anywhere in the image holds 0x02007BD0.  It closes
 * the day a second caller of 0x02007BD0 appears, exactly like 0x02005DE4 and
 * 0x02005A98 in the near-miss register of docs/MATCHING.md.  Note that
 * sub_02006E2C itself is fine either way: it has two callers, 0x02006DE4 in
 * this range and 0x02006E1C in sub_02006E18, so whichever of the two files a
 * range holds, the other is its witness.
 */
u32 sub_02006DAC(const struct Sub02006DACParam *param)
{
    u32 r = MIC_AdjustLimitedSampling(param);

    sub_02006DAC_Ptr->unk1C = 1;
    sub_02006DAC_Ptr->unk00 = *param;
    return r;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The microphone sampling request and its one caller.  The record both
 * functions pass around is seven words, and the SDK call at 0x0208B500 is
 * MIC_AdjustLimitedSampling in layout/symbols_sdk.txt, so the record is a
 * MICAutoParam: type, buffer, size, rate, loop flag, callback and callback
 * argument, in that order, which is exactly the seven stores sub_02006DD8
 * makes and exactly the 0x1C bytes sub_02006DAC copies.  The fields are
 * still spelled unkXX here because only the SDK call attests the shape, not
 * the meaning of the two constants.
 *
 * sub_02006DAC reads the global pointer at 0x02021664 twice, once for the
 * flag word at +0x1C and once for the copy, because the store through the
 * first load can alias the pointer itself and the compiler has to reload it.
 * That reload is not a second variable in the source.  The copy is the
 * unrolled aggregate assignment of
 * docs/idioms/aggregate-assignment-is-ldm-stm.md: 0x1C bytes is three
 * ldm/stm pairs and a trailing ldr/str, and it says the seven words are one
 * nested struct rather than seven fields.
 *
 * The two constants sub_02006DD8 stores come out of literal pools, and the
 * round down of the first is emitted as a live test and mask rather than
 * folded: `movs r0, #0x1f; tst r0, r1; beq; movs r0, #0x1f; bics r1, r0`,
 * with the mask materialised twice because Thumb has no immediate bic.  The
 * compiler does not constant fold it even though the value is a pool word,
 * so the guard is in the source and not an artefact.
 *
 * What is left out of this range, and why, is sub_02006E18 at
 * 0x02006E18..0x02006E2A, eighteen bytes that reproduce every concrete byte
 * and cap at MATCH.  It is `sub_02007BD0(a, sub_02006E2C());` and the
 * evidence for 0x02007BD0 is the `bl` at 0x02006E24 inside that very
 * the function list: the census is one witness image wide, one of them inside the
 * range, so no cut can free it.  The `literal` class has nothing either,
 * because no pool word anywhere in the image holds 0x02007BD0.  It closes
 * the day a second caller of 0x02007BD0 appears, exactly like 0x02005DE4 and
 * 0x02005A98 in the near-miss register of docs/MATCHING.md.  Note that
 * sub_02006E2C itself is fine either way: it has two callers, 0x02006DE4 in
 * this range and 0x02006E1C in sub_02006E18, so whichever of the two files a
 * range holds, the other is its witness.
 */
u32 sub_02006DD8(void *a, u32 b)
{
    struct Sub02006DACParam param;

    param.unk00 = 2;
    param.unk04 = sub_02006E2C();
    param.unk08 = 0x1FF4;
    if (param.unk08 & 0x1F) {
        param.unk08 &= ~0x1Fu;
    }
    param.unk0C = 0x1001;
    param.unk10 = 0;
    param.unk14 = (u32)a;
    param.unk18 = b;
    return sub_02006DAC(&param);
}


void func_02006E18(void *a0)
{
    void *res = (void *)func_02006E2C();
    func_02007BD0(a0, res);
}


/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/000_02004000.s.
 *
 * Original (20 bytes, leaf, one ABS32 literal):
 *   ldr  r0, [pc, #0xc]   ; &sub_02006E2C_Ptr
 *   movs r1, #0x1f
 *   ldr  r0, [r0]
 *   ldr  r0, [r0, #0x24]
 *   adds r0, #0x1f
 *   bics r0, r1
 *   bx   lr
 *
 * Round a size up to a multiple of 32.  The mask is materialised in r1 and
 * applied with bics because Thumb has no immediate form of bic; the
 * compiler hoists the movs above both loads, which is the schedule the
 * original shows.
 *
 * The pool word is an ABS32 relocation, resolved to the address declared
 * above; five other functions load the same address from their own pools.
 */
u32 sub_02006E2C(void)
{
    return (sub_02006E2C_Ptr->unk24 + 0x1F) & ~0x1Fu;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * alias: the file identity is in the image.  sub_02006E40 and sub_02006EA4
 * both pass 0x020A7048 to the debug allocator at 0x02030734, and the bytes
 * at 0x020A7048 spell "bgm_info.c".  The string before it is "snd_mic.c",
 * whose terminator at 0x020A7045 plus two bytes of padding fixes 0x020A7048
 * by construction, so the address is carried by the `string` class: the two
 * pool words that name it are both inside this range and `literal` discards
 * them.  See "The string class" in docs/MATCHING.md.
 *
 * A twelve byte record holding a count and two parallel arrays: a u16 key
 * array at +4 and a u8 value array at +8, both allocated from the same heap
 * by sub_02006EA4 and both freed by sub_02006E64.  sub_02006E7C is the
 * lookup, a linear scan of the key array returning the value at the same
 * index.
 *
 * Two things the bytes settle:
 *
 *  - sub_02006E7C saves r4 and r5 and no lr, so it is a leaf, and it still
 *    carries a label because the sweep accepts `push {r4, r5}` when the
 *    trace reaches it from a branch.  Its loop bound is signed (`ble` on the
 *    guard, `blt` on the back edge) even though the count is a `u8` field,
 *    which is the ordinary integer promotion of a byte compared against an
 *    `int` induction variable.
 *  - the fourth argument of the four func_02048F74 calls is a running
 *    counter, not a function of the loop index.  Written as `i * 3 + 1` and
 *    `i * 3 + 3` the compiler reassociates the multiply against the array
 *    index and computes the value inside the loop (`adds r6, r4, r1`), which
 *    is 49 bytes wrong; written as a variable stepped by three it produces
 *    the original's `adds r3, r6, #0` and `adds r3, r6, #2`.
 *  - where that variable is stepped decides two registers and one
 *    instruction.  The original materialises its value 1 as `adds r6, r4, #1`
 *    off the zero already in r4, immediately before the first allocation, so
 *    the increment has to sit between the first func_02048F74 call and the
 *    two allocations.  Move it after them and the compiler hoists the file
 *    name pool word into r7 instead, loading it once rather than twice, and
 *    puts the heap id in r6.  Write the increment as `k = 1` anywhere and the
 *    constant is common-subexpression-eliminated with the 1 that is the fifth
 *    argument of the first call, which deletes the instruction outright and
 *    shifts the rest of the function by two bytes.
 */
struct Sub02006E40Obj *sub_02006E40(u32 heap)
{
    struct Sub02006E40Obj *obj = func_02030734(
        heap, sizeof(struct Sub02006E40Obj), 0, sub_02006E40_File, 0x47);

    sub_02006EA4(obj, heap);
    return obj;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * alias: the file identity is in the image.  sub_02006E40 and sub_02006EA4
 * both pass 0x020A7048 to the debug allocator at 0x02030734, and the bytes
 * at 0x020A7048 spell "bgm_info.c".  The string before it is "snd_mic.c",
 * whose terminator at 0x020A7045 plus two bytes of padding fixes 0x020A7048
 * by construction, so the address is carried by the `string` class: the two
 * pool words that name it are both inside this range and `literal` discards
 * them.  See "The string class" in docs/MATCHING.md.
 *
 * A twelve byte record holding a count and two parallel arrays: a u16 key
 * array at +4 and a u8 value array at +8, both allocated from the same heap
 * by sub_02006EA4 and both freed by sub_02006E64.  sub_02006E7C is the
 * lookup, a linear scan of the key array returning the value at the same
 * index.
 *
 * Two things the bytes settle:
 *
 *  - sub_02006E7C saves r4 and r5 and no lr, so it is a leaf, and it still
 *    carries a label because the sweep accepts `push {r4, r5}` when the
 *    trace reaches it from a branch.  Its loop bound is signed (`ble` on the
 *    guard, `blt` on the back edge) even though the count is a `u8` field,
 *    which is the ordinary integer promotion of a byte compared against an
 *    `int` induction variable.
 *  - the fourth argument of the four func_02048F74 calls is a running
 *    counter, not a function of the loop index.  Written as `i * 3 + 1` and
 *    `i * 3 + 3` the compiler reassociates the multiply against the array
 *    index and computes the value inside the loop (`adds r6, r4, r1`), which
 *    is 49 bytes wrong; written as a variable stepped by three it produces
 *    the original's `adds r3, r6, #0` and `adds r3, r6, #2`.
 *  - where that variable is stepped decides two registers and one
 *    instruction.  The original materialises its value 1 as `adds r6, r4, #1`
 *    off the zero already in r4, immediately before the first allocation, so
 *    the increment has to sit between the first func_02048F74 call and the
 *    two allocations.  Move it after them and the compiler hoists the file
 *    name pool word into r7 instead, loading it once rather than twice, and
 *    puts the heap id in r6.  Write the increment as `k = 1` anywhere and the
 *    constant is common-subexpression-eliminated with the 1 that is the fifth
 *    argument of the first call, which deletes the instruction outright and
 *    shifts the rest of the function by two bytes.
 */
void sub_02006E64(struct Sub02006E40Obj *obj)
{
    func_020307B0(obj->unk04);
    func_020307B0(obj->unk08);
    func_020307B0(obj);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * alias: the file identity is in the image.  sub_02006E40 and sub_02006EA4
 * both pass 0x020A7048 to the debug allocator at 0x02030734, and the bytes
 * at 0x020A7048 spell "bgm_info.c".  The string before it is "snd_mic.c",
 * whose terminator at 0x020A7045 plus two bytes of padding fixes 0x020A7048
 * by construction, so the address is carried by the `string` class: the two
 * pool words that name it are both inside this range and `literal` discards
 * them.  See "The string class" in docs/MATCHING.md.
 *
 * A twelve byte record holding a count and two parallel arrays: a u16 key
 * array at +4 and a u8 value array at +8, both allocated from the same heap
 * by sub_02006EA4 and both freed by sub_02006E64.  sub_02006E7C is the
 * lookup, a linear scan of the key array returning the value at the same
 * index.
 *
 * Two things the bytes settle:
 *
 *  - sub_02006E7C saves r4 and r5 and no lr, so it is a leaf, and it still
 *    carries a label because the sweep accepts `push {r4, r5}` when the
 *    trace reaches it from a branch.  Its loop bound is signed (`ble` on the
 *    guard, `blt` on the back edge) even though the count is a `u8` field,
 *    which is the ordinary integer promotion of a byte compared against an
 *    `int` induction variable.
 *  - the fourth argument of the four func_02048F74 calls is a running
 *    counter, not a function of the loop index.  Written as `i * 3 + 1` and
 *    `i * 3 + 3` the compiler reassociates the multiply against the array
 *    index and computes the value inside the loop (`adds r6, r4, r1`), which
 *    is 49 bytes wrong; written as a variable stepped by three it produces
 *    the original's `adds r3, r6, #0` and `adds r3, r6, #2`.
 *  - where that variable is stepped decides two registers and one
 *    instruction.  The original materialises its value 1 as `adds r6, r4, #1`
 *    off the zero already in r4, immediately before the first allocation, so
 *    the increment has to sit between the first func_02048F74 call and the
 *    two allocations.  Move it after them and the compiler hoists the file
 *    name pool word into r7 instead, loading it once rather than twice, and
 *    puts the heap id in r6.  Write the increment as `k = 1` anywhere and the
 *    constant is common-subexpression-eliminated with the 1 that is the fifth
 *    argument of the first call, which deletes the instruction outright and
 *    shifts the rest of the function by two bytes.
 */
u8 sub_02006E7C(const struct Sub02006E40Obj *obj, u16 key)
{
    int i;

    for (i = 0; i < obj->count; i++) {
        if (key == obj->unk04[i]) {
            return obj->unk08[i];
        }
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * alias: the file identity is in the image.  sub_02006E40 and sub_02006EA4
 * both pass 0x020A7048 to the debug allocator at 0x02030734, and the bytes
 * at 0x020A7048 spell "bgm_info.c".  The string before it is "snd_mic.c",
 * whose terminator at 0x020A7045 plus two bytes of padding fixes 0x020A7048
 * by construction, so the address is carried by the `string` class: the two
 * pool words that name it are both inside this range and `literal` discards
 * them.  See "The string class" in docs/MATCHING.md.
 *
 * A twelve byte record holding a count and two parallel arrays: a u16 key
 * array at +4 and a u8 value array at +8, both allocated from the same heap
 * by sub_02006EA4 and both freed by sub_02006E64.  sub_02006E7C is the
 * lookup, a linear scan of the key array returning the value at the same
 * index.
 *
 * Two things the bytes settle:
 *
 *  - sub_02006E7C saves r4 and r5 and no lr, so it is a leaf, and it still
 *    carries a label because the sweep accepts `push {r4, r5}` when the
 *    trace reaches it from a branch.  Its loop bound is signed (`ble` on the
 *    guard, `blt` on the back edge) even though the count is a `u8` field,
 *    which is the ordinary integer promotion of a byte compared against an
 *    `int` induction variable.
 *  - the fourth argument of the four func_02048F74 calls is a running
 *    counter, not a function of the loop index.  Written as `i * 3 + 1` and
 *    `i * 3 + 3` the compiler reassociates the multiply against the array
 *    index and computes the value inside the loop (`adds r6, r4, r1`), which
 *    is 49 bytes wrong; written as a variable stepped by three it produces
 *    the original's `adds r3, r6, #0` and `adds r3, r6, #2`.
 *  - where that variable is stepped decides two registers and one
 *    instruction.  The original materialises its value 1 as `adds r6, r4, #1`
 *    off the zero already in r4, immediately before the first allocation, so
 *    the increment has to sit between the first func_02048F74 call and the
 *    two allocations.  Move it after them and the compiler hoists the file
 *    name pool word into r7 instead, loading it once rather than twice, and
 *    puts the heap id in r6.  Write the increment as `k = 1` anywhere and the
 *    constant is common-subexpression-eliminated with the 1 that is the fifth
 *    argument of the first call, which deletes the instruction outright and
 *    shifts the rest of the function by two bytes.
 */
void sub_02006EA4(struct Sub02006E40Obj *obj, u32 heap)
{
    int i;
    int k;

    k = 0;
    func_02048F74(obj, 0x57, 0, k, (u32 *)1);
    k++;
    obj->unk04 = func_02030734(heap, obj->count * 2, 0, sub_02006E40_File,
                               0xAF);
    obj->unk08 = func_02030734(heap, obj->count, 0, sub_02006E40_File, 0xB0);
    for (i = 0; i < obj->count; i++) {
        func_02048F74(&obj->unk04[i], 0x57, 0, k, (u32 *)2);
        func_02048F74(&obj->unk08[i], 0x57, 0, k + 2, (u32 *)1);
        k += 3;
    }
}
