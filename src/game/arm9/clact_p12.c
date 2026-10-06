/*
 * file:     clact_p12.c
 * unit:     yes
 * function: func_0204D510, func_0204D52C
 * address:  0x0204D510
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
 *   g_DispatchTable_0204D510  0x020A7F48  data
 */
struct CellAnim;
typedef unsigned int u32;

struct Ctl {
    u32 mode;  /* 0x00 */
};

typedef void (*Handler)(struct Ctl *c);

extern void func_020643A4(struct CellAnim *anim);
void func_0204D52C(void *p);
extern Handler g_DispatchTable_0204D510[];


/*
 * Closes the clact.c fan-in-1 blocker documented in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt: func_0204B9A0 (its only
 * caller image wide) forwards its argument unchanged.
 *
 * Dispatch through a function-pointer table indexed by the mode word at
 * +0x00 of the argument; the call itself is an indirect `blx` (no PC24
 * relocation to attest), but the table base at 0x020A7F48 is an ABS32
 * literal with no second reference anywhere in the ARM9 image, so this
 * stays MATCH regardless of the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D510.c \
 *       --func func_0204D510 --addr 0x0204D510 --cc 1.1p1 --arm
 */
void func_0204D510(struct Ctl *c)
{
    g_DispatchTable_0204D510[c->mode](c);
}

void func_0204D52C(void *p){ func_020643A4((struct CellAnim *)((char *)p + 0xc)); }
