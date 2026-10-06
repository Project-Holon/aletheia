/*
 * file:     clact_p16.c
 * unit:     yes
 * function: func_0204E010, func_0204E01C, func_0204E074, func_0204E0C4, func_0204E0D0
 * address:  0x0204E010
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734     0x02030734  arm
 *   func_0204E01C_File 0x020A7F74 data
 *   func_02062820  0x02062820  arm
 *   func_02062670  0x02062670  arm
 *   func_02062A00  0x02062A00  arm
 *   func_0204DACC  0x0204DACC  arm
 */
struct NitroFileHeader;
struct Ovr;
struct Res;
struct Sink;
typedef unsigned int   u32;

typedef unsigned char  u8;

struct Entry_0204E01C {
    u8  pad_00[0x10];
    u32 unk_10;
};

typedef unsigned short u16;

typedef signed int     s32;

struct Entry_0204E074 {
    u8    pad_00[8];
    void *unk_08;
    void *unk_0c;
    u32   unk_10;
};

struct Pool {
    u8            pad_00[0x10];
    struct Entry_0204E074 *entries;
};

struct Slot {
    u8  pad_00[0x3c];
    u32 unk_3c;
};

struct Owner {
    u8           pad_00[8];
    struct Slot *slots;
};

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02062820(int a, int *out);
extern s32 func_02062670(void *handle, void **slot);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void func_0204DACC(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr, u32 mode);
void func_0204E010(void *ptr);
struct Entry_0204E01C *func_0204E01C(u32 heap, u32 count);
void func_0204E0C4(void *ptr);
extern const char func_0204E01C_File[];


void func_0204E010(void *ptr)
{
    func_020307B0(ptr);
}


/*
 * Allocate the 0x14-byte entry pool and mark every entry free.  The
 * allocation size is `count * sizeof(struct Entry)`, and the `mvn`-free
 * `mov r2, r4` is the alignment argument sharing the zero the loop counter
 * was just materialised into, so `i` must be spelled before the call, not
 * only in the `for` header.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 7494; it is declared as an extern array pinned by address,
 * never as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E01C.c \
 *       --func func_0204E01C --addr 0x0204E01C --cc 1.1p1 --arm
 */
struct Entry_0204E01C *func_0204E01C(u32 heap, u32 count)
{
    struct Entry_0204E01C *entries;
    u32 i;

    i = 0;
    entries = (struct Entry_0204E01C *)func_02030734(heap,
                                            count * sizeof(struct Entry_0204E01C), i,
                                            func_0204E01C_File, 7494);

    for (; i < count; i++) {
        entries[i].unk_10 = 1;
    }

    return entries;
}


/*
 * Publish the two handles of one 0x14-byte pool entry.  The entry is
 * addressed as `pool->entries[idx]` (the `mla` by 0x14 is the subscript,
 * not a byte offset), each handle is registered through its own registrar,
 * and only when both succeed is the entry's +0x10 slot cleared and 1
 * returned.  Either failure leaves the entry alone and returns 0.
 *
 * The two guards must be written nested (`if (ok1) { if (ok2) { ...; return
 * 1; } } return 0;`), not as two early-`return 0` guards and not as one
 * `||`.  Only the nested form leaves the success path as the fall-through
 * of the second `cmp`, which is what lets the store, the constant and the
 * return if-convert into `movne`/`strne`/`movne`/`popne` above a single
 * shared `mov r0, #0` tail.  Two early returns give an if-converted first
 * guard and no shared tail (76 bytes); `||` emits the failure block first
 * and duplicates the return (84 bytes).  Both arguments must be read
 * into locals before the first call: the `mov r5, r3` ahead of the `bl` is
 * the fourth argument being parked in a callee-saved register, which only
 * happens when it is live across the call as a plain value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E074.c \
 *       --func func_0204E074 --addr 0x0204E074 --cc 1.1p1 --arm
 */
s32 func_0204E074(struct Pool *pool, s32 idx, void *a, void *b)
{
    struct Entry_0204E074 *entry = &pool->entries[idx];

    if (func_02062820((int)a, (int *)(&entry->unk_08)) != 0) {
        if (func_02062670(b, &entry->unk_0c) != 0) {
            entry->unk_10 = 0;
            return 1;
        }
    }
    return 0;
}


void func_0204E0C4(void *ptr)
{
    func_020307B0(ptr);
}


/*
 * Resolve a handle through func_02062A00 into a stack temporary and, only
 * on success, hand it to func_0204DACC together with the two stacked
 * arguments, then clear bit 31 of +0x3c in the 0x40-byte slot `idx` of the
 * table at `owner->unk_08`.
 *
 * The temporary must be a plain local whose address is taken: the `add r1,
 * sp, #4` before the first call and the `ldr r2, [sp, #4]` after it are the
 * out-parameter, and the `ldr r3, [sp, #0x18]` is the caller's fifth
 * argument being reloaded from the incoming stack area, which fixes the
 * arity at five.  Argument four reaches func_0204DACC's own stack slot and
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
 *   python tools/match.py one --src src/matched/func_0204E0D0.c \
 *       --func func_0204E0D0 --addr 0x0204E0D0 --cc 1.1p1 --arm
 */
void func_0204E0D0(struct Owner *owner, s32 idx, u32 handle, u32 a3, u32 a4)
{
    u32 value;
    struct Slot *slot;

    if (func_02062A00((struct NitroFileHeader *)handle, (void **)(&value)) != 0) {
        func_0204DACC((struct Res *)owner, idx, (struct Sink *)value, (struct Ovr *)a4, a3);
        slot = &owner->slots[idx];
        slot->unk_3c &= ~0x80000000;
    }
}
