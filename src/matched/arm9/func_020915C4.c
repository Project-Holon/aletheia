/*
 * function: func_020915C4
 * address:  0x020915C4
 * packet:   pkt_0209159C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * One deferred transaction against the object: re-derive the working fields
 * (func_0209159C), optionally preload the amount from the object's f20 when
 * the mode argument is 1, run the object's own f3c handler with four
 * arguments (f00, f1c, &f28 and f48 - the fourth is only visible as the dead
 * `ldr r3, [r4, #0x48]` the call does not otherwise need), publish f28 to the
 * caller's out parameter, and on success fold f28 into the running f18.
 *
 * The handler is called through a plain cast of the field
 * (`((Fn)p->f3c)(...)`, i.e. the field itself declared as a function
 * pointer).  Spelling it as a guarded indirect call (`p->f3c ? ... : 0`)
 * compiles to a branchy 102-byte-different body: the original is a bare
 * `blx ip`.
 *
 * The flag test is `((p->f04 << 19) >> 31) == 0`, one bit selected out of the
 * word at +4; the unequal shift pair keeps both shifts (a mask would fold to
 * `tst #0x1000`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020915C4.c \
 *       --func func_020915C4 --addr 0x020915C4 --cc 1.1p1 --arm
 *   EXACT, 140 bytes, 2 relocation sites, both resolved.
 *
 * symbols:
 *   func_0209159C  0x0209159C  arm
 *   func_02091598  0x02091598  arm
 */

typedef unsigned int u32;

struct S020915C4 {
    u32 f00;
    u32 f04;
    u32 pad08[4];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 pad30[3];
    u32 f3c;
    u32 f40;
    u32 pad44;
    u32 f48;
};

typedef u32 (*Fn020915C4)(u32, u32, u32 *, u32);

struct S0209159C;
extern void func_0209159C(struct S0209159C *p);
extern void func_02091598(int a, void *b);

int func_020915C4(struct S020915C4 *p, u32 *a1, int a2)
{
    u32 r;

    func_0209159C((struct S0209159C *)p);
    if (a2 == 1)
        p->f28 = p->f20;
    r = ((Fn020915C4)p->f3c)(p->f00, p->f1c, &p->f28, p->f48);
    if (r == 2)
        p->f28 = 0;
    if (a1 != 0)
        *a1 = p->f28;
    if (r != 0)
        return r;
    p->f18 += p->f28;
    if (((p->f04 << 19) >> 31) == 0)
        func_02091598(p->f1c, &p->f28);
    return 0;
}
