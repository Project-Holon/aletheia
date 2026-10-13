/*
 * function: CLACT_SetupCharacter
 * address:  0x0204E0D0
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   func_02062A00  0x02062A00  arm
 *   CLACT_SetupCharacterVram  0x0204DACC  arm
 *
 * Resolve a handle through func_02062A00 into a stack temporary and, only
 * on success, hand it to CLACT_SetupCharacterVram together with the two stacked
 * arguments, then clear bit 31 of +0x3c in the 0x40-byte slot `idx` of the
 * table at `owner->unk_08`.
 *
 * The temporary must be a plain local whose address is taken: the `add r1,
 * sp, #4` before the first call and the `ldr r2, [sp, #4]` after it are the
 * out-parameter, and the `ldr r3, [sp, #0x18]` is the caller's fifth
 * argument being reloaded from the incoming stack area, which fixes the
 * arity at five.  Argument four reaches CLACT_SetupCharacterVram's own stack slot and
 * argument five reaches its r3, so the two are swapped relative to this
 * function's own signature; that is the original's order, not a slip.
 *
 * The final read-modify-write must go through a named `struct Slot *`.
 * Written inline as `owner->slots[idx].unk_3c &= ~0x80000000`, the compiler
 * folds the constant 0x3c into the base and leaves the scaled index in both
 * the load and the store (`[r1, r5, lsl #6]`), three instructions wrong;
 * binding the element address to a local first forces `add r1, r0, r5, lsl
 * #6` once with an immediate-offset load and store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetupCharacter.c \
 *       --func CLACT_SetupCharacter --addr 0x0204E0D0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

struct Slot {
    u8  pad_00[0x3c];
    u32 unk_3c;
};

struct Owner {
    u8           pad_00[8];
    struct Slot *slots;
};

struct NitroFileHeader;
struct Ovr;
struct Res;
struct Sink;
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void CLACT_SetupCharacterVram(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr, u32 mode);

void CLACT_SetupCharacter(struct Owner *owner, s32 idx, u32 handle, u32 a3, u32 a4)
{
    u32 value;
    struct Slot *slot;

    if (func_02062A00((struct NitroFileHeader *)handle, (void **)(&value)) != 0) {
        CLACT_SetupCharacterVram((struct Res *)owner, idx, (struct Sink *)value, (struct Ovr *)a4, a3);
        slot = &owner->slots[idx];
        slot->unk_3c &= ~0x80000000;
    }
}
