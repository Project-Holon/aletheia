/*
 * function: func_02039764
 * address:  0x02039764
 * packet:   pkt_02039764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203996C  0x0203996C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   file_020A7A68  0x020A7A68  data
 *
 * (Re)initialise one slot entry and hand it back.  The entry is wiped to
 * 0x50 zero bytes, its packed key at +0x44/+0x46 is set to the 0xFF
 * sentinel and its +0x49/+0x4A state bytes cleared.  Only the OWN slot
 * (index 0xFF) owns the eight 0x10-byte resource records at +8: for it the
 * old eight are released before the wipe and eight fresh ones allocated
 * after it out of the heap named by the record's +0x56 halfword (line 0xC7);
 * a peer slot keeps a null array on both sides of the wipe.
 *
 * This is func_02039834's per-slot worker and the constructive twin of
 * func_02039658 (which keeps the resource pointers rather than
 * reallocating them).
 *
 * TWO LEVERS, and only one of them is an allocation tie.
 *
 * IT RETURNS THE ENTRY.  The image's `mov r0, r8` at +0xBC, between the
 * +0x46 store and the +0x49 store, is the return value: both callers
 * (func_02039834, func_020398B4) discard it, so nothing downstream forces
 * it, but written `void` the function is four bytes short and that `mov` is
 * simply missing.  A dead-looking `mov r0, <callee-saved>` just before the
 * epilogue of a function whose callers ignore the result is the tell.
 *
 * DECLARATION ORDER: `struct Entry *e;` before `u8 *g;`.  The other way
 * round the two swap colours -- the record goes to r8 and the entry to sb,
 * against the image's sb and r8 -- for ten `mov`/`ldr` operands and no size
 * change (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * tools/permuter.py --explain reports this residue as exactly one swapped
 * pair (r8 <-> sb), which is what says to reach for declaration order rather
 * than for the body.
 *
 * The allocation loop's counter is a SECOND variable from the release
 * loop's, zeroed before the wipe call rather than at the loop head: that is
 * the `mov sl, #0` at +0x50 sitting above `bl func_02082BCC`, where reusing
 * `i` would re-zero it after the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039764.c \
 *       --func func_02039764 --addr 0x02039764 --cc 1.1p1 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Entry;
extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern struct Entry *func_0203996C(s32 idx);
extern void func_020307B0(void *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char file_020A7A68[];

struct Entry {
    u8    pad_00[8];
    void *slot[8];
    u8    pad_28[0x1c];
    u16   key44;
    u16   key46;
    u8    pad_48;
    u8    f49;
    u8    f4a;
};

struct Entry *func_02039764(u32 idx)
{
    struct Entry *e;
    u8 *g;
    int i;

    g = func_0203D798();
    func_0203D788();
    e = (struct Entry *)func_0203996C(idx);

    if (idx == 0xff) {
        for (i = 0; i < 8; i++) {
            if (e->slot[i] != 0)
                func_020307B0(e->slot[i]);
        }
    }

    i = 0;
    func_02082BCC(e, 0, 0x50);

    if (idx == 0xff) {
        for (; i < 8; i++)
            e->slot[i] = func_02030734(*(u16 *)(g + 0x56), 0x10, 1, file_020A7A68, 0xc7);
    }

    e->f4a = 0;
    e->key44 = 0xff;
    e->key46 = 0xff;
    e->f49 = 0;
    return e;
}
