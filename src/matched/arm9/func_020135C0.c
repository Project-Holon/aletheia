/*
 * function: BTL_SETUP_SetupDemo
 * address:  0x020135C0
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SETUP_Clear   0x020130C4  thumb
 *   BTL_SETUP_SetPlayerParty   0x0201333C  thumb
 *   BTL_SETUP_InitCommon   0x02013360  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   POKEPARTY_Copy   0x0201AC2C  thumb
 *
 * btl_setup.c.  The four-argument variant of the setup builder: the shared
 * writers run first, then up to two optional attachments are bound through
 * POKEPARTY_Copy, and the object is left in mode 4.
 *
 * This closes the near miss documented in docs/notes/pkt_02013528.c.txt.
 * That note was right that POKEPARTY_Copy cannot carry a fixed two-parameter
 * prototype - the first call site passes r0 and r1, the second passes only
 * r0 - and right that a variadic declaration, `void POKEPARTY_Copy(u32 a,
 * ...)`, is the only one under which both sites emit the original bytes.
 * What it could not recover was the `adds r1, r0, #0` the original keeps
 * before the +0x28 store, and it concluded that binding the result to a
 * named local did not help.
 *
 * The resolution is that r1 is not a register copy at all: it is the SECOND
 * ARGUMENT of the second POKEPARTY_Copy call.  Writing the call as
 * `POKEPARTY_Copy(a3, r)` - handing it the POKEPARTY_Create result the +0x28
 * store also consumes - produces `adds r1, r0, #0; str r1, [r5, #0x28]`
 * exactly, because the value has to reach r1 for the call and the store
 * then reads it from there.  The "leftover" register really is a passed
 * argument, the same tell as
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 * The variadic declaration is what lets the two sites differ in arity.
 *
 * Permuter note: tools/permuter.py hill (179 mutations tried) reached
 * 6 bytes out at the right size with copy(r->r_@6), but its mutation was
 * `r_ = r;` BEFORE r is assigned - an uninitialised read that scores well
 * and is not admissible C.  It did correctly localise the residue to a
 * single r1 -> r0 substitution at the store, which is what pointed at the
 * argument reading rather than at a copy.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupDemo.c \
 *       --func BTL_SETUP_SetupDemo --addr 0x020135C0 --cc 1.1p1 --thumb
 */
#include "../include/Obj00155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BTL_SETUP_Clear(u8 *p);
struct Party;
struct Rec534;
extern void BTL_SETUP_InitCommon(u8 *o, void *a1, const void *a2);
extern int BTL_SETUP_SetPlayerParty(int a0, int a1, int a2);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);

void BTL_SETUP_SetupDemo(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5)
{
    u32 r;

    BTL_SETUP_Clear(a0);
    BTL_SETUP_InitCommon(a0, a1, (const void *)a4);
    BTL_SETUP_SetPlayerParty((int)a0, (int)a1, a5);
    if (a2 != 0) {
        POKEPARTY_Copy((const struct Rec534 *)a2, (struct Rec534 *)(((struct Obj00155 *)a0)->f24));
    }
    r = (u32)POKEPARTY_Create(a5);
    ((struct Obj00155 *)a0)->f28 = r;
    if (a3 != 0) {
        POKEPARTY_Copy((const struct Rec534 *)a3, (struct Rec534 *)r);
    }
    ((struct Obj00155 *)a0)->f0 = 4;
    ((struct Obj00155 *)a0)->f4 = 0;
}
