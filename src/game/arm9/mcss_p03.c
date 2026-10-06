/*
 * file:     mcss_p03.c
 * unit:     yes
 * function: func_020159C8, func_02015BA4, func_02015BF0, func_02015C00, func_02015C0C, func_02015C1C, func_02015C30, func_02015C48, func_02015C60, func_02015C78, func_02015C94, func_02015CAC, func_02015CC4, func_02015CDC, func_02015CF8, func_02015D14, func_02015D30, func_02015D4C, func_02015D64
 * address:  0x020159C8
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
 *   func_020159C8_File  0x020A72CC  data
 *   func_02016BA0  0x02016BA0  thumb
 *   func_02016C0C  0x02016C0C  thumb
 *   func_02016C38  0x02016C38  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj02638.h"
#include "../../matched/include/Obj03429.h"
#include "../../matched/include/Obj11824.h"
#include "../../matched/include/Obj17197.h"
#include "../../matched/include/Obj17198.h"
#include "../../matched/include/Obj17199.h"
#include "../../matched/include/Obj08751.h"
#include "../../matched/include/Obj00933.h"
#include "../../matched/include/Obj08752.h"
#include "../../matched/include/Obj08754.h"
#include "../../matched/include/Obj08756.h"
#include "../../matched/include/Obj08757.h"
#include "../../matched/include/Obj08759.h"
#include "../../matched/include/Obj08761.h"
#include "../../matched/include/Obj08763.h"
#include "../../matched/include/Obj08765.h"
#include "../../matched/include/Obj08767.h"
#include "../../matched/include/Obj08769.h"

struct Ctx;
struct Src;
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020163C4(struct Ctx *a0, u32 idx, const struct Src *a2);
extern void func_02016BA0(void *obj);
extern void func_02016C0C(void *id);
extern int func_02016C38(int a0);
extern u32 func_020307B0(void *p);
void sub_02015BA4(void *sys, void *obj);
void sub_02015BF0(void *obj);
void sub_02015C00(void *obj);
void sub_02015C0C(void *obj);
void sub_02015C1C(void *obj);
void func_02015C30(void *p, u32 *out);
void func_02015C48(void *p, u32 *src);
void func_02015C60(void *p, u32 *out);
void func_02015C78(void *p, u32 *src);
void func_02015C94(void *p, u32 *out);
void func_02015CAC(void *p, u32 *src);
void func_02015CC4(void *p, u32 *out);
void func_02015CDC(void *p, u32 *src);
void func_02015CF8(void *p, u32 *out);
void func_02015D14(void *p, u32 *src);
void func_02015D30(void *p, u32 *src);
void func_02015D4C(void *p, u32 *out);
void func_02015D64(void *p, u32 *src);
extern const char func_020159C8_File[];




/*
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
 *   python tools/match.py one --src src/matched/sub_020159C8.c  *       --func func_020159C8 --addr 0x020159C8 --cc 1.1p1
 */
struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3,
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
            func_020163C4((struct Ctx *)obj, i, (const struct Src *)src);
            break;
        }
    }
    return obj->unk14[i];
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02015C1C
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void sub_02015BA4(void *sys, void *obj)
{
    u32 *p = (u32 *)obj;
    u32 idx;
    u32 *arr;

    func_02016BA0(obj);

    if (p[0] != 0) {
        func_02016C0C((void *)p[0]);
        p[0] = 0;
    }
    if (p[1] != 0) {
        func_02016C38(p[1]);
        p[1] = 0;
    }
    if (p[2] != 0) {
        func_02016C38(p[2]);
        p[2] = 0;
    }

    idx = ((struct Obj02638 *)obj)->f148;
    arr = *(u32 * *)&((struct Obj03429 *)sys)->f14;
    arr[idx] = 0;

    func_020307B0(obj);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02015C1C
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void sub_02015BF0(void *obj)
{
    ((struct Obj11824 *)obj)->f2C &= ~1;
    ((struct Obj11824 *)obj)->f2C |= 1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02015C1C
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void sub_02015C00(void *obj)
{
    ((struct Obj17197 *)obj)->f2C &= ~1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02015C1C
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void sub_02015C0C(void *obj)
{
    ((struct Obj17198 *)obj)->f140 |= 0x20000000;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02015C1C
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void sub_02015C1C(void *obj)
{
    ((struct Obj17199 *)obj)->f140 &= ~0x20000000;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word). Copies three words out of the structure at +0xE0.
 * The inverse of func_02015C48; in the ov118 event state machine
 * (0x021D7130) it is the out-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C30(void *p, u32 *out)
{
    out[0] = ((struct Obj08751 *)p)->fE0;
    out[1] = ((struct Obj08751 *)p)->fE4;
    out[2] = ((struct Obj08751 *)p)->fE8;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xE0. The inverse of func_02015C30; in the ov118 event state
 * machine (0x021D7130) and func_021D6E04 it is the in-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C48(void *p, u32 *src)
{
    ((struct Obj00933 *)p)->fE0 = src[0];
    ((struct Obj00933 *)p)->fE4 = src[1];
    ((struct Obj00933 *)p)->fE8 = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x11C. Twin of func_02015C78.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C60(void *p, u32 *out)
{
    out[0] = ((struct Obj08752 *)p)->f11C;
    out[1] = ((struct Obj08752 *)p)->f120;
    out[2] = ((struct Obj08752 *)p)->f124;
}



/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Copies three words
 * into the structure at +0x11C; same shape as func_02015C48 further
 * back.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C78(void *p, u32 *src)
{
    ((struct Obj08754 *)p)->f11C = src[0];
    ((struct Obj08754 *)p)->f120 = src[1];
    ((struct Obj08754 *)p)->f124 = src[2];
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of the
 * structure at +0xEC. The inverse of func_02015CAC; same shape as
 * func_02015C30 one word-group further along.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C94(void *p, u32 *out)
{
    out[0] = ((struct Obj08756 *)p)->fEC;
    out[1] = ((struct Obj08756 *)p)->fF0;
    out[2] = ((struct Obj08756 *)p)->fF4;
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xEC. The inverse of func_02015C94.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CAC(void *p, u32 *src)
{
    ((struct Obj00933 *)p)->fEC = src[0];
    ((struct Obj00933 *)p)->fF0 = src[1];
    ((struct Obj00933 *)p)->fF4 = src[2];
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x128.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CC4(void *p, u32 *out)
{
    out[0] = ((struct Obj08757 *)p)->f128;
    out[1] = ((struct Obj08757 *)p)->f12C;
    out[2] = ((struct Obj08757 *)p)->f130;
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x128. Inverse of func_02015CC4.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CDC(void *p, u32 *src)
{
    ((struct Obj08759 *)p)->f128 = src[0];
    ((struct Obj08759 *)p)->f12C = src[1];
    ((struct Obj08759 *)p)->f130 = src[2];
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0xF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CF8(void *p, u32 *out)
{
    out[0] = ((struct Obj08761 *)p)->fF8;
    out[1] = ((struct Obj08761 *)p)->fFC;
    out[2] = ((struct Obj08761 *)p)->f100;
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0xF8. Inverse of func_02015CF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D14(void *p, u32 *src)
{
    ((struct Obj08763 *)p)->fF8 = src[0];
    ((struct Obj08763 *)p)->fFC = src[1];
    ((struct Obj08763 *)p)->f100 = src[2];
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x104.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D30(void *p, u32 *src)
{
    ((struct Obj08765 *)p)->f104 = src[0];
    ((struct Obj08765 *)p)->f108 = src[1];
    ((struct Obj08765 *)p)->f10C = src[2];
}



/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x110.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D4C(void *p, u32 *out)
{
    out[0] = ((struct Obj08767 *)p)->f110;
    out[1] = ((struct Obj08767 *)p)->f114;
    out[2] = ((struct Obj08767 *)p)->f118;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x110. Inverse of func_02015D4C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D64(void *p, u32 *src)
{
    ((struct Obj08769 *)p)->f110 = src[0];
    ((struct Obj08769 *)p)->f114 = src[1];
    ((struct Obj08769 *)p)->f118 = src[2];
}
