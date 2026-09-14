/*
 * unit:     yes
 * function: sub_0204349C
 * address:  0x0204349C
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A48     0x02146A48  data
 *
 * The tail of the packet: two one-line mask-downs of the same 32-bit word
 * at +4 of the object that starts at 0x02146A48, and the wrapper that runs
 * both.  Each accessor keeps only the bits its own half owns (0x10 for the
 * first, 0x0f for the second), so calling both in sequence clears the word
 * outright; the wrapper is the reset path.
 *
 * Kept as one unit so the two `bl` sites in sub_020434CC are `local`: they
 * are that pair's only callers image-wide, and split into three files
 * neither could attest the other
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md in
 * reverse).
 */

typedef unsigned int u32;

struct Flags {
    u32 unk_00;
    u32 unk_04;
};

extern struct Flags g_02146A48;

void sub_0204349C(void)
{
    g_02146A48.unk_04 = g_02146A48.unk_04 & 0x10;
}

void sub_020434B4(void)
{
    g_02146A48.unk_04 = g_02146A48.unk_04 & 0xf;
}

void sub_020434CC(void)
{
    sub_0204349C();
    sub_020434B4();
}
