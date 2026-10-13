/*
 * unit:     yes
 * function: WIPE_SYS_SetDivision, sub_02022424
 * address:  0x020223C0
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Mode decoder for the dual-screen text cluster: a five-case dense switch on
 * the mode index that fills the five leading words of the object with one of
 * five fixed (kind, flagA, flagB) triples.  The writer at 0x02022424 is an
 * unlabelled leaf static in the same translation unit (no lr save, so
 * disasm.py never labels it); it stores the triple twice, once at +0x00/+0x04/
 * +0x08 and once more at +0x0C/+0x10, which is what makes the two later
 * readers see the same pair of values from either half.  It carries its
 * address as its name, and is listed in `function:` above, so the manifest
 * records the address it covers: coverage is counted per address named by an
 * entry, and a range covered only by a unit names nothing on its own.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020223C0.c \
 *       --addr 0x020223C0 --thumb
 */
typedef unsigned int u32;

struct Mode {
    u32 kind;
    u32 a;
    u32 b;
    u32 a2;
    u32 b2;
};

static void sub_02022424(struct Mode *p, u32 kind, u32 a, u32 b);

void WIPE_SYS_SetDivision(u32 mode, struct Mode *p)
{
    switch (mode) {
    case 0:
        sub_02022424(p, 0, 1, 1);
        break;
    case 1:
        sub_02022424(p, 1, 1, 1);
        break;
    case 2:
        sub_02022424(p, 2, 1, 1);
        break;
    case 3:
        sub_02022424(p, 1, 1, 0);
        break;
    case 4:
        sub_02022424(p, 2, 0, 1);
        break;
    }
}

static void sub_02022424(struct Mode *p, u32 kind, u32 a, u32 b)
{
    p->kind = kind;
    p->a = a;
    p->b = b;
    p->a2 = a;
    p->b2 = b;
}
