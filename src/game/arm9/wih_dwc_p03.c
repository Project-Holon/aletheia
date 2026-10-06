/*
 * file:     wih_dwc_p03.c
 * unit:     yes
 * function: func_0201045C, func_02010498, func_020104F8, func_0201054C, func_0201057C, func_0201058C
 * address:  0x0201045C
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
 *   g_021461E0     0x021461E0  data
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0203F004  0x0203F004  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203CF10  0x0203CF10  arm
 *   func_0205D01C  0x0205D01C  arm
 *   func_02178098  0x02178098  thumb  ov014
 *   sub_020107FC   0x020107FC  thumb
 *   func_0201057C  0x0201057C  thumb
 */
#include "../../matched/include/Obj05697.h"
#include "../../matched/include/Obj01818.h"
#include "../../matched/include/Obj03426.h"
#include "../../matched/include/Obj03426.h"

struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Ctx {
    u8  unk00[0x2C];
    u16 unk2C;
};

struct WihInfo {
    int kind;          /* +0x00 */
    u8  rest[0x3C];    /* +0x04 */
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_02082D44(u8 *p, u8 *rec);
extern u32 func_0203F004(const u8 *s);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void *func_0203D798(void);
extern int  func_0203D1B4(void);
extern u32 func_0203CF10(u32 a);
extern u8   func_02178098(u8 i);
extern int  func_0205D01C(u32 buf, u8 *rec, struct WihInfo *out);
extern int  sub_020107FC(void *key);
extern u32  func_0201057C(const struct Ctx *rec);
void func_0201045C(const void *src);
void sub_02010498(void);
int sub_020104F8(u8 *obj);
int func_0201054C(const u8 *obj);
u32 func_0201058C(void *key);
extern u8 *g_021461E0;




/*
 * wih_dwc.c: append one 0xC0-byte record to the four-slot table at the head
 * of the object behind 0x021461E0, guarded on the capacity at +0x310 and the
 * fill index at +0x316.  The object is the one func_02010360 allocates
 * (0x328 bytes) and stores into the global; func_02010360 also hands this
 * function's address (pool word 0x0201045D) to the ov014 setter 0x0217963C,
 * so it is a receive callback.
 *
 * The closing fact was the callee: 0x02082D44 is MI_CpuCopy8(src, dest,
 * size) (layout/symbols_sdk.txt), so the call takes THREE arguments and the
 * `movs r2, #0xc0` is the size argument shared with the index multiply.
 * With a two-argument prototype (docs/notes/unit_0201045C.c.txt) the
 * compiler folds the index copy `adds r3, r6, #0` away and the index lands
 * in a scratch register; with r2 pinned to the size, the product needs its
 * own register and the copy reappears.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201045C.c \
 *       --func func_0201045C --addr 0x0201045C --thumb
 */
void func_0201045C(const void *src)
{
    u8 *o = g_021461E0;

    if (((struct Obj05697 *)o)->f310 != 0 && ((struct Obj05697 *)o)->f316 < ((struct Obj05697 *)o)->f310 && ((struct Obj05697 *)o)->f316 < 4) {
        MI_CpuCopy8(src, o + ((struct Obj05697 *)o)->f316 * 0xC0, 0xC0);
        *(u16 *)(g_021461E0 + 0x316) = *(u16 *)(g_021461E0 + 0x316) + 1;
    }
}




/*
 *           function_starts.txt line 337 seeds this leaf at 0x0201049C (4 bytes
 *           too high); the real prologue and byte-exact fit are at 0x02010498,
 *           per docs/notes/unit_0201045C.c.txt.
 * blocked:  +005C ABS32 g_021461E0 : unresolved: no address for 'g_021461E0':
 *           not in the symbols: block, not an address-bearing name, not in
 *           layout/symbols_sdk.json
 */
void sub_02010498(void)
{
    u8 *o = g_021461E0;

    if (o != 0 && ((struct Obj01818 *)o)->f30C != 0)
        return;
    if (o == 0)
        return;
    if (((struct Obj01818 *)o)->f318 > 0)
        ((struct Obj01818 *)o)->f318 = ((struct Obj01818 *)o)->f318 - 1;
    o = g_021461E0;
    if (((struct Obj01818 *)o)->f31C > 0)
        ((struct Obj01818 *)o)->f31C = ((struct Obj01818 *)o)->f31C - 1;
    o = g_021461E0;
    if (((struct Obj01818 *)o)->f320 > 0)
        ((struct Obj01818 *)o)->f320 = ((struct Obj01818 *)o)->f320 - 1;
    o = g_021461E0;
    if (((struct Obj01818 *)o)->f324 > 0)
        ((struct Obj01818 *)o)->f324 = ((struct Obj01818 *)o)->f324 - 1;
}




/*
 * Three 0x100-byte slots at +0x640 of the object hanging off +0x304 of the
 * global at 0x021461E0 (the same global func_0201045C reads); the first slot
 * with a positive func_0203F004 whose func_0203EFC8 against obj+0xC returns
 * zero makes the function return 1.
 *
 * Three spellings the previous pass (docs/notes/pkt_0201045C.c.txt) did not
 * have, and each is needed:
 *
 *  1. the pool word is 0x021461E0, not 0x020461E0, and it holds a POINTER,
 *     not the object: the original does one `ldr r1, [r7]` and then
 *     `ldr r1, [r1, r0]` with r0 = 0x304.  Reading it as `**` costs an extra
 *     dereference at both sites.  It is the same global func_0201045C reads.
 *  2. func_0203EFC8 takes THREE arguments, and the third is the result of
 *     func_0203F004.  That is what the otherwise pointless `adds r2, r0, #0`
 *     at 0x02010518 is: r2 is set right after the first call and is still
 *     live, unwritten, at the `blx` to func_0203EFC8 twenty-four bytes
 *     later.  Two arguments plus a named local for the comparison folds the
 *     copy away (80 bytes); a function-scope or volatile local gives it a
 *     stack home (`str r0, [sp]` / `ldr r0, [sp]`) instead of r2.  The local
 *     must be declared inside the loop body.
 *     docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md
 *  3. `i` must be initialised before `q`: the original opens
 *     `movs r4, #0` then `adds r6, #0xc`, and writing the loop as a plain
 *     `for (i = 0; ...)` after `u8 *q = obj + 0xC;` emits those two the
 *     other way round.  That swap is the last two bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020104F8.c \
 *       --func sub_020104F8 --addr 0x020104F8 --cc 1.1p1 --thumb
 */
int sub_020104F8(u8 *obj)
{
    int i = 0;
    u8 *q = obj + 0xC;

    for (; i < 3; i++) {
        u8 *slot = *(u8 **)(g_021461E0 + 0x304) + 0x640 + i * 0x100;
        int n = func_0203F004(slot);

        if (n > 0) {
            slot = *(u8 **)(g_021461E0 + 0x304) + 0x640 + i * 0x100;
            if (func_0203EFC8(slot, q, n) == 0)
                return 1;
        }
    }
    return 0;
}




/*
 * Three gates on one object then `return 1`.  All three false paths share the
 * single `return 0` at the bottom, which is what puts the `bne`/`beq` on the
 * shared epilogue instead of inlining two `movs r0, #0`: the source is a nest
 * of three `if`s with one `return 1` inside and one `return 0` after them.
 * The compare is against the 8 bytes at 0x020A7250, a cast address constant
 * (no relocation), and `func_0203EFC8` is a memcmp-shaped helper whose zero
 * means equal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201054C.c \
 *       --func func_0201054C --addr 0x0201054C --cc 1.1p1 --thumb
 */
int func_0201054C(const u8 *obj)
{
    if (*(const u16 *)&((struct Obj03426 *)obj)->fA == 8) {
        if (func_0203EFC8((const void *)0x020A7250, obj + 0xc, 8) != 0) {
            if ((*(const u16 *)&((struct Obj03426 *)obj)->f2C & 0x10) == 0) {
                return 1;
            }
        }
    }
    return 0;
}




/*
 * Sixteen bytes: a boolean test of bit 0x10 of a halfword field at +0x2C of
 * its argument.  The functions on both sides of it are not matched yet, so
 * it is a file of its own, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201057C.c \
 *       --func func_0201057C --addr 0x0201057C --cc 1.1p1
 */
u32 func_0201057C(const struct Ctx *p)
{
    if (p->unk2C & 0x10) {
        return 1;
    }
    return 0;
}


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02178098 as .word data (0x680B4909), and this call is
 *           the only branch to it in the image.  SEED REQUEST: `ov014
 *           0x02178098 thumb`, evidence the bl at arm9 0x020105E8.  Every
 *           other site resolves and every concrete byte matches (520 of 520).
 *
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in sub_020107FC, the connection state byte +0x67
 * and slot count +0x62 of the func_0203D798 context, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * func_0201045C fills, arming the four countdowns at +0x318..+0x324 that
 * sub_02010498 decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.
 *
 * Two declaration facts close it: func_0205D01C's third argument is a
 * 0x40-byte out record whose first word is the switch key (the frame is
 * sub sp,#0x60 plus the r3 pad; an `int *` gives sub sp,#0x24), and the
 * switch has explicit empty arms for 7 and 9 so the 13-entry halfword table
 * exists (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201058C.c \
 *       --func func_0201058C --addr 0x0201058C --thumb
 */
u32 func_0201058C(void *key)
{
    u32 flags = 0;
    u8 *st = func_0203D798();
    int i;
    int j;
    u8 *rec;
    struct WihInfo info;
    u8 s;

    if (g_021461E0 == 0)
        return flags;

    if (sub_020107FC(key) != -1)
        flags |= 8;
    if (st[0x67] == 2 && func_0203D1B4() > 1)
        flags |= 4;

    for (i = 0; i < st[0x62]; i++) {
        if (func_0203CF10(i) != 0) {
            s = func_02178098(i);
            if (s >= 0x14 && s <= 0x1B)
                flags |= 0x10;
            else if (s == 9)
                flags |= 0x20;
        }
    }

    for (j = 0; j < *(u16 *)(g_021461E0 + 0x316); j++) {
        rec = g_021461E0 + j * 0xC0;
        if (sub_020104F8(rec)) {
            *(int *)(g_021461E0 + 0x318) = 600;
        } else if (func_0201054C(rec)) {
            *(int *)(g_021461E0 + 0x31C) = 600;
        } else if (func_0205D01C(*(u32 *)(g_021461E0 + 0x300), rec, &info)) {
            switch (info.kind) {
            case 0: case 1: case 2: case 3:
            case 10: case 11: case 12:
                *(int *)(g_021461E0 + 0x318) = 600;
                break;
            case 4: case 5: case 6: case 8:
                *(int *)(g_021461E0 + 0x31C) = 600;
                break;
            case 7: case 9:
                break;
            }
        } else if (((struct Obj03426 *)rec)->fA != 0) {
            if (func_0201057C((const struct Ctx *)rec) == 0)
                *(int *)(g_021461E0 + 0x320) = 400;
            else
                *(int *)(g_021461E0 + 0x324) = 400;
        }
    }

    if (*(int *)(g_021461E0 + 0x318) > 0)
        flags |= 0x40;
    if (*(int *)(g_021461E0 + 0x31C) > 0)
        flags |= 0x80;
    if (*(int *)(g_021461E0 + 0x320) > 0)
        flags |= 0x100;
    if (*(int *)(g_021461E0 + 0x324) > 0)
        flags |= 0x200;
    if (*(u16 *)(g_021461E0 + 0x30E) != 0)
        *(u16 *)(g_021461E0 + 0x30E) = *(u16 *)(g_021461E0 + 0x30E) - 1;

    if (flags == 0) {
        *(u16 *)(g_021461E0 + 0x312) = 0;
    } else if (*(u16 *)(g_021461E0 + 0x314) != 0 && *(u16 *)(g_021461E0 + 0x30E) == 0) {
        *(u16 *)(g_021461E0 + 0x312) = *(u16 *)(g_021461E0 + 0x314);
        *(u16 *)(g_021461E0 + 0x30E) = 400;
        *(u16 *)(g_021461E0 + 0x314) = 0;
    }
    *(u16 *)(g_021461E0 + 0x316) = 0;
    return flags | 2;
}
