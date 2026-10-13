/*
 * function: NNS_G3dBindMdlPlttEx
 * address:  0x0206A5B4
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolve one animation entry out of the nested cell/attribute tables and,
 * if it is not already marked done (flags bit 0 at +3), hand it plus the
 * matching context entry to NNSi_G3dBindMdlPlttInternal.  Returns 1 when the entry was
 * dispatched, 0 otherwise.
 *
 * The listing extent runs to 332 bytes because 0x0206A67C has no label;
 * the function itself is the 200 bytes 0x0206A5B4..0x0206A67C.  The
 * unlabelled follower at 0x0206A67C is reported rather than seeded here.
 *
 * Pin evidence (2.0), measured 2026-09-21: the "kept branches" tell.  The
 * image writes the zero result of the context lookup out TWICE, once per
 * arm: `mov r3, #0` at 0x0206A614 (`00 30 a0 e3`) reached by the inner
 * bounds failure, and a second `mov r3, #0` at 0x0206A61C (`00 30 a0 e3`)
 * reached by the outer null/offset guard, each with its own `b 0x0206A620`
 * (`02 00 00 ea` at 0x0206A610, `00 00 00 ea` at 0x0206A618).  dsi/1.1p1
 * -O4,p cross-jumps the two arms into a single `mov r3, #0` and emits the
 * two branches back to back, giving 196 bytes against the original's 200,
 * every following instruction identical and shifted by exactly four.  Four
 * source spellings of the split (goto to a shared label, chained else-if,
 * hoisted `r3 = 0` initialiser, and the duplicated-else form below) all
 * fold the same way under 1.1p1.  Under the pin the C below is 200 bytes,
 * 0 mismatches.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dBindMdlPlttEx.c \
 *       --func NNS_G3dBindMdlPlttEx --addr 0x0206A5B4 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   NNSi_G3dBindMdlPlttInternal  0x0206A3CC  arm
 */
#include "../include/Obj07044.h"
#include "../include/Obj11595.h"
#include "../include/Obj16556.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  f0;
    u8  count;
    u8  f2;
    u8  flags;
    u16 f4;
    u16 tbl;
} Ent;

extern void NNSi_G3dBindMdlPlttInternal(void *a, Ent *b, void *c, Ent *d);

int NNS_G3dBindMdlPlttEx(char *h, char *c, u32 i2, u32 i3)
{
    char *base;
    Ent  *e1;
    Ent  *r3;
    Ent  *t;

    base = (h != 0 && ((struct Obj07044 *)h)->f8 != 0) ? h + ((struct Obj07044 *)h)->f8 : 0;
    e1 = (Ent *)(base + ((struct Obj16556 *)base)->f2);

    if (c != 0 && ((struct Obj11595 *)c)->f34 != 0) {
        Ent *s = (Ent *)(c + ((struct Obj11595 *)c)->f34);
        if (s != 0 && i3 < s->count) {
            u16 t3 = s->tbl;
            r3 = (Ent *)((char *)s + t3 + 4
                         + *(u16 *)((char *)s + t3) * i3);
        } else {
            r3 = 0;
        }
    } else {
        r3 = 0;
    }
    if (e1 != 0 && i2 < e1->count) {
        u16 t2 = e1->tbl;
        u16 st = *(u16 *)((char *)e1 + t2);
        t = (Ent *)((char *)e1 + t2 + 4 + st * i2);
    } else {
        t = 0;
    }

    if (t != 0 && !(t->flags & 1)) {
        NNSi_G3dBindMdlPlttInternal(base, t, c, r3);
        return 1;
    }
    return 0;
}
