/*
 * function: sub_0204A6C8
 * address:  0x0204A6C8
 * packet:   pkt_0204A6C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_02146A74   0x02146A74  data
 *   func_0204D9D4  0x0204D9D4  arm
 *   func_0204E0D0  0x0204E0D0  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Claims the first entry of the display-object table (0x40-byte slots at
 * +0x08 of the owner block, 0x104 into the object at 0x02146A74) whose
 * pending bit (bit 31 of +0x3c) is set, loads the object for it through
 * func_0204D9D4, publishes it with func_0204E0D0, frees the handle, then
 * clears +0x24 and bit 0 of +0x3c.  Returns the slot index, or -1 when
 * nothing was waiting.  Sibling of func_0204A7A0.
 *
 * Shape notes (docs/notes/sub_0204A6C8.c.txt has the full history):
 *  - `count` is volatile (reread every iteration), `sys` is kept live for
 *    the slot address, and the not-found exit falls out of the loop past a
 *    goto.
 *  - The body sits inside `if (i != (u32)-1) { ... return i; }` with a
 *    trailing `return -1;`.  The early-return spelling
 *    `if (i == (u32)-1) return -1;` gets every byte right except the order
 *    of `mov r8, r0` (the handle) and `mov r7, #0` (the shared zero) after
 *    the load call (4 out, flat over five waves).  See
 *    docs/idioms/an-inverted-guard-returns-the-compare-constant-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204A6C8.c  *       --func sub_0204A6C8 --addr 0x0204A6C8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Slot  { u8 pad_00[0x24]; u32 unk_24; u8 pad_28[0x14]; u32 unk_3c; };
struct Slot2 { u8 pad_00[0x14]; u32 unk_14; };
struct Owner {
    u8            pad_00[8];
    struct Slot  *slots;
    struct Slot2 *slots2;
    u8            pad_10[4];
    volatile u16  count;
    volatile u16  count2;
};
struct Sys { u8 pad_00[0x104]; struct Owner owner; };
extern struct Sys *unk_02146A74;
extern u32  func_0204D9D4(u32 a, u32 b, u32 c, u16 flags);
extern void func_0204E0D0(struct Owner *owner, u32 idx, u32 handle, u32 a3, u32 a4);
extern void func_020307B0(u32 handle);

s32 sub_0204A6C8(u32 a, u32 b, u32 c, u32 a3, u16 flags)
{
    struct Sys   *sys;
    struct Owner *owner;
    struct Slot  *slot;
    u32 i;
    u32 handle;

    sys   = unk_02146A74;
    owner = &sys->owner;

    for (i = 0; i < owner->count; i++) {
        if ((owner->slots[i].unk_3c >> 31) != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot   = &sys->owner.slots[i];
        handle = func_0204D9D4(a, b, c, (u16)((flags & 0x7fff) | 0x8000));

        func_0204E0D0(&unk_02146A74->owner, i, handle, a3, 0);
        func_020307B0(handle);

        slot->unk_24 = 0;
        slot->unk_3c &= ~1;
        return i;
    }
    return -1;
}
