/*
 * file:     unit_020746C4_p05.c
 * unit:     yes
 * function: func_02074C70, func_02074CD0
 * address:  0x02074C70
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
 *   func_020743EC  0x020743EC  arm
 *   func_0207466C  0x0207466C  arm
 *   func_02075014  0x02075014  arm
 *   func_02074450  0x02074450  arm
 *   func_02074E10  0x02074E10  arm
 *   func_02075404  0x02075404  arm
 *   func_0208A2BC  0x0208A2BC  arm
 */
#include "../../matched/include/Obj11687.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void *func_02074388(int index);
extern u32 func_02074FA8(u32, u32, u32);
extern u32 func_0207466C(u32);
u32 func_02074C70(u32 a, u32 b, u32 c, u32 d, u32 *out) {
    void *p = func_02074388(a);
    u32 r;
    if (p == 0) return 3;
    if (b & 8) {
        r = func_02074FA8(((struct Obj11687 *)p)->f0, c, d);
        if (r == 0) return 7;
    } else {
        r = func_0207466C(((struct Obj11687 *)p)->f0);
    }
    if (out != 0) *out = r;
    return 0;
}

typedef struct { u32 f0; u16 slot[4]; } Grp;

union Hdr {
    unsigned w;
    struct { unsigned v : 24; unsigned flag : 1; unsigned rest : 7; } b;
};

extern void *func_020743EC(int index);
extern u32   func_0207466C(u32 a);
extern u32   func_02075014(u32 a, u32 b, u32 c);
extern void *func_02074450(int index);
extern u32   func_02074E10(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32   func_02075404(u32 a, u32 b, u32 c, u32 d, u32 *heap);
extern void  func_0208A2BC(u32 bank, u32 i, u32 waveArc);

/*
 * The third kind dispatcher: look up the group (error 4), load or look up its
 * bank (flag bit 2; error 8), then for each of the group's four halfword slots
 * that is not 0xffff resolve the entry (error 5), load its wave through
 * func_02074E10 (its own error code is returned as is), bind the sequence's
 * banks through func_02075404 when header bit 24 and flag bit 4 are both set
 * (error 9), and finally assign the loaded wave archive to the bank slot.
 *
 * THE LAST LEVER (wave 12, from 2 bytes out): func_0208A2BC takes THREE
 * arguments, not two.  Its own prologue saves r0, r1 AND r2 (`mov r4, r2` at
 * 0x0208A2C8), which is the SDK's SND_AssignWaveArc(bank, index, waveArc)
 * shape.  The image's `ldrne r2, [sp, #4]` at 0x02074DD0 was never a
 * scratch register choice: it loads `sub` straight into the third argument
 * register for the call, and the `cmpne r2, #0` guard reads it from there.
 * Every other lever (the union header, one-argument func_02074450, the
 * func_02074E10 result returned as is, the int counter, the ../2.0/sp2 pin)
 * is documented in docs/notes/pkt_02074CD0.c.txt.
 *
 * With the three-argument callee the body is byte-exact under the project
 * default dsi/1.1p1 AND under ../2.0/sp2 / ../2.0/sp2p2 (all three checked),
 * so no front-end pin is recorded: the two-argument prototype was what made
 * 1.1p1 look wrong in the earlier notes.
 */
u32 func_02074CD0(u32 a, u32 flags, u32 c, u32 d, u32 *out)
{
    Grp *g;
    union Hdr *o;
    u32 bank;
    int i;
    u32 want;
    u32 sub;
    u32 r;

    g = func_020743EC(a);
    if (g == 0) return 4;

    if (flags & 2) {
        bank = func_02075014(g->f0, c, d);
        if (bank == 0) return 8;
    } else {
        bank = func_0207466C(g->f0);
    }

    want = flags & 4;
    for (i = 0; i < 4; i++) {
        if (g->slot[i] != 0xffff) {
            o = func_02074450(g->slot[i]);
            if (o == 0) return 5;
            r = func_02074E10(g->slot[i], flags, c, d, &sub);
            if (r != 0) return r;
            if ((o->w >> 24) & 1 && want != 0) {
                if (func_02075404(sub, bank, (u32)i, o->b.v, (u32 *)c) == 0) return 9;
            }
            if (bank != 0 && sub != 0) {
                func_0208A2BC(bank, (u32)i, sub);
            }
        }
    }
    if (out != 0) *out = bank;
    return 0;
}
