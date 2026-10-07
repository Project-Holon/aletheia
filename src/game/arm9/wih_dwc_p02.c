/*
 * file:     wih_dwc_p02.c
 * unit:     yes
 * function: func_020103E4, func_0201042C, func_02010444
 * address:  0x020103E4
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
 *   g_021461E0        0x021461E0  data
 *   sWihDwc           0x020A7240  data
 *   ov015_id          0x0000000F  data
 *   func_02034714     0x02034714  arm
 *   func_0217963C     0x0217963C  thumb  ov014
 *   func_0203D7FC     0x0203D7FC  arm
 *   func_02034A5C     0x02034A5C  arm
 */
#include "../../matched/include/Obj11238.h"

typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

struct Entry {
    u16 flag;
    u16 pad;
};

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0217963C(u32 v);
extern void func_0203D7FC(void *p);
extern void func_02034A5C(int handle);
void func_020103E4(u8 *p);
void func_0201042C(void);
void func_02010444(void);
extern u32 g_021461E0;
extern u8  sWihDwc;
extern u8  ov015_id[];


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           address in overlay space: two overlays overlap it (ov009, ov014)
 *           and NEITHER carries a func_ label there (ov009 decodes it as
 *           `moveq r0, #1` in the middle of a function, ov014 has the data
 *           word 0x680A4902).  attest_overlay_label() needs part 1 of the
 *           rule, a label in the overlay's own listing, so the site has no
 *           witness outside this range and no cut can give it one: the only
 *           branch to 0x0217963C in the image is the pair at 0x020103B6 and
 *           0x020103FE, and both are inside this packet.  `matched` cannot
 *           reach it either (0x0217963C is not matched).
 *           2026-09-23 (wave 14): 0x0217963C is an unlabelled ov014 Thumb
 *           setter (`ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,
 *           [r2,r1]; bx lr`), printed as .word data.  SEED REQUEST: `ov014
 *           0x0217963C thumb`; the two bl sites then witness each other and
 *           this file and sub_02010360 go EXACT unchanged.
 *
 * "wih_dwc.c" teardown, the counterpart of func_02010360 (same packet):
 * both guard on the same pointer at 0x021461E0 being null before running
 * the 0x020A7240-argument call, both take the same (p, 0, p) argument
 * triple, and both end by clearing that pointer again.  The pool word is
 * the address of the four zero bytes immediately before the "wih_dwc.c"
 * string at 0x020A7244 - the file anchor the packet reports.
 *
 * The last call's argument arrives from a pool word holding 0x0000000F, not
 * from a `movs`, so it is a symbol rather than an integer: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  The
 * pool words on either side of this function (0x020103E0 and 0x02010428)
 * both hold 0x0F, and func_02034AC4 - the sibling entry point in
 * src/pending/unit_0200BA58.c - takes the same kind of value, so this is
 * the same linker-defined id, spelled ov015_id here.  It is `literal`-
 * attested by 0x020103E0, which is outside this function's range.
 *
 * The call at 0x0217963C is a branch into overlay space (it is why the
 * listing prints it as .inst.w "outside this region").  Its argument is a
 * literal zero, and that same zero is what the store at +0x30 writes: mwcc
 * materialises it once, keeps it in r4 across both func_0203D7FC calls and
 * stores it, which is the `movs r4, #0` beside the `movs r0, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020103E4.c \
 *       --func func_020103E4 --addr 0x020103E4 --cc 1.1p1 --thumb
 *   MATCH, 72 bytes, 7 relocation sites, 6 resolved, 1 wildcard:
 *     +001A THM_CALL func_0217963C - unresolved, no outside witness.
 */
void func_020103E4(u8 *p)
{
    if (g_021461E0 == 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    func_0217963C(0);
    func_0203D7FC((void *)((struct Obj11238 *)p)->f300);
    func_0203D7FC(p);
    g_021461E0 = 0;
    func_02034A5C((int)ov015_id);
}


/*
 * Two mirror-image four-word functions: set and clear one flag halfword of
 * entry 0xC3 in a table reached through the pointer variable at 0x0214617C's
 * neighbour, 0x021461E0.  0x021461E0 is a plain literal pool word (the same
 * address is loaded by nine other functions in this file's neighbourhood, at
 * 0x020103D4, 0x02010420 and so on), so it needed no relocation resolution,
 * the same situation documented in src/matched/sub_0200F800.c for 0x0214617C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201042C.c \
 *       --addr 0x0201042C --thumb
 */
void func_0201042C(void)
{
    struct Entry *arr = *(struct Entry **)0x021461E0;
    if (arr != 0) {
        arr[0xC3].flag = 1;
    }
}


void func_02010444(void)
{
    struct Entry *arr = *(struct Entry **)0x021461E0;
    if (arr != 0) {
        arr[0xC3].flag = 0;
    }
}
