/*
 * function: MCSS_Add
 * address:  0x020159C8
 * packet:   pkt_02014D90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 476 bytes, one function, 29 field stores and no branches but the loop.
 *
 * "Take the first free slot of the module's array, allocate a 0x188 byte
 * record into it, fill it in and hand it back."  The loop walks
 * obj->unk14[0 .. obj->unk10) looking for a NULL entry, and on the first one
 * it allocates, initialises and breaks; the return is obj->unk14[i] either way,
 * so a full array returns the one-past-the-end element, which is the game's
 * behaviour and not a transcription error.
 *
 * ---------------------------------------------------------------------------
 * THE FILE NAME, AND WHAT IT SETTLES
 * ---------------------------------------------------------------------------
 * The allocator call passes 0x020A72CC and 906, which are __FILE__ and
 * __LINE__.  The bytes at 0x020A72CC spell **mcss.c**, so this function and
 * its neighbours in pkt_02014D90 are that original source file, at line 906.
 * The string is attested the ordinary way, seven literal-pool witnesses
 * elsewhere in the image, so it needed no widening of the `string` class; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md for why it is
 * declared as an extern array rather than written `__FILE__`.  The strings on
 * either side of it in the packed area are "field_status.c" and a run of four
 * pointer words, which is the shape
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md warns about for
 * the *next* file name in that area rather than for this one.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The loop bound is the field, not a local.**  `n = obj->unk10;` before the
 * loop and `i < n` inside it compiles to the same 476 bytes with `n` in r1
 * instead of r2, which spills the second parameter one instruction later and
 * leaves nine bytes wrong in the prologue and one at the loop's `cmp`.
 * Written `for (i = 0; i < obj->unk10; i++)` the compiler hoists the load
 * itself, into r2, and the whole function is EXACT.  Nothing in the body reads
 * the field, and the only call inside the loop is on the path that breaks out
 * of it, so the hoist is legal and the original took it.
 *
 * **sizeof is in the source, and it is what pays for the field offsets.**
 * The allocation size arrives as `movs r7, #0x62` / `lsls r7, r7, #2`, which is
 * 0x188, and r7 then stays live for the whole body: every field past the Thumb
 * immediate reach is addressed as `adds r0, r7, #0` / `subs r0, #k` with k the
 * distance back from the end of the record, and the halfword 0xC400 stored at
 * +0x178 is `lsls r2, r7, #7` off the same register.  That only happens if the
 * size the source passes to the allocator is literally `sizeof(struct Rec)`
 * and the struct is exactly 0x188 bytes, which makes the declaration
 * self-checking: a struct one word too long or too short changes the constant
 * and every offset derived from it.  The same front end goes on to reuse the
 * constant 0x1F (a bitfield value, parked in `ip`) as the base for the offsets
 * 0x110, 0x114 and 0x118, which is the extreme end of the same behaviour.
 *
 * **Every store reloads the array and the element.**  `obj->unk14[i]->f = v`
 * appears 29 times and the original reloads `obj->unk14` and then
 * `obj->unk14[i]` before each one, because the store it just made could alias
 * either.  Writing the element pointer into a local once, which is what a
 * person would do, removes 28 pairs of loads and is a different function.  The
 * counterpart is docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md:
 * there the qualifier removes the reloads, here its absence is the match.
 *
 * **The 36 byte record at +0x150 is one struct assignment.**  It compiles to a
 * counted `ldm`/`stm` loop of four iterations plus a trailing word, which is
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; declaring it as a
 * byte array instead gives a `ldrb`/`strb` loop of 36 iterations, so the
 * source's type has at least four byte alignment and `u32 w[9]` is what
 * reproduces it.
 *
 * The word at +0x140 is a bitfield container: the three writes are the low
 * eight bits set to 0x1F, the nine bits at 14 set to 0x20 and bit 11 cleared,
 * and then bit 29 set after the struct copy.  Written as masks and shifts over
 * a plain `u32` the compiler materialises each mask from a literal pool; as
 * bitfields it emits the original's `bics`/`orrs` against the small constants
 * and only the two nine-bit masks reach the pool.
 *
 * Nothing here is version specific: every constant is a structure offset, a
 * fixed-point 1.0 (0x1000), a bitfield value or the source line number.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/MCSS_Add.c  *       --func MCSS_Add --addr 0x020159C8 --cc 1.1p1
 *
 * symbols:
 *   func_020159C8_File  0x020A72CC  data
 *   MCSS_LoadResource  0x020163C4  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Sub150 {
    u32 w[9];
};

struct Rec {
    u32 pad000[0x38];
    u32 unk0E0;
    u32 unk0E4;
    u32 unk0E8;
    u32 unk0EC;
    u32 unk0F0;
    u32 unk0F4;
    u32 pad0F8[6];
    u32 unk110;
    u32 unk114;
    u32 unk118;
    u32 unk11C;
    u32 unk120;
    u32 unk124;
    u32 unk128;
    u32 unk12C;
    u32 unk130;
    u32 pad134[3];
    u32 f0 : 8;
    u32 f1 : 3;
    u32 f2 : 1;
    u32 f3 : 2;
    u32 f4 : 9;
    u32 f5 : 6;
    u32 f6 : 1;
    u32 f7 : 2;
    u32 unk144;
    u32 unk148;
    u32 unk14C;
    struct Sub150 unk150;
    u32 unk174;
    u16 unk178;
    u16 unk17A;
    u32 unk17C;
    u32 unk180;
    u32 unk184;
};

struct Obj {
    u32 pad00[4];
    s32 unk10;
    struct Rec **unk14;
    u32 pad18[10];
    u32 unk40;
};

extern const char func_020159C8_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Ctx;
struct Src;
extern void MCSS_LoadResource(struct Ctx *a0, u32 idx, const struct Src *a2);

struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3,
                          const struct Sub150 *src)
{
    s32 i;

    for (i = 0; i < obj->unk10; i++) {
        if (obj->unk14[i] == 0) {
            obj->unk14[i] = (struct Rec *)func_02030734((u16)obj->unk40,
                                                        sizeof(struct Rec), 1,
                                                        func_020159C8_File,
                                                        906);
            obj->unk14[i]->unk148 = i;
            obj->unk14[i]->unk14C = obj->unk40;
            obj->unk14[i]->unk0E0 = a1;
            obj->unk14[i]->unk0E4 = a2;
            obj->unk14[i]->unk0E8 = a3;
            obj->unk14[i]->unk0EC = 0x1000;
            obj->unk14[i]->unk0F0 = 0x1000;
            obj->unk14[i]->unk0F4 = 0x1000;
            obj->unk14[i]->unk11C = 0;
            obj->unk14[i]->unk120 = 0;
            obj->unk14[i]->unk124 = 0;
            obj->unk14[i]->unk128 = 0x1000;
            obj->unk14[i]->unk12C = 0x1000;
            obj->unk14[i]->unk130 = 0x1000;
            obj->unk14[i]->f0 = 0x1F;
            obj->unk14[i]->f4 = 0x20;
            obj->unk14[i]->f2 = 0;
            obj->unk14[i]->unk178 = 0xC400;
            obj->unk14[i]->unk17A = 0;
            obj->unk14[i]->unk17C = 0;
            obj->unk14[i]->unk180 = 0;
            obj->unk14[i]->unk184 = 0xFFFFF000;
            obj->unk14[i]->unk110 = 0x1000;
            obj->unk14[i]->unk114 = 0x1000;
            obj->unk14[i]->unk118 = 0x1000;
            obj->unk14[i]->unk150 = *src;
            obj->unk14[i]->unk174 = 0x1000;
            obj->unk14[i]->f6 = 1;
            MCSS_LoadResource((struct Ctx *)obj, i, (const struct Src *)src);
            break;
        }
    }
    return obj->unk14[i];
}
