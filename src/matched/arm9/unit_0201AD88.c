/*
 * unit:     yes
 * address:  0x0201AD88
 * packet:   pkt_0201AD88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201AD88
 *
 * The lazy constructor for the static handle at 0x0214652C that
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c thread every
 * call through: allocates a 0x10 byte object out of the heap named by the
 * parameter the first time it is asked and does nothing afterwards.
 *
 * The `adds r1, r0, #0` that moves the parameter out of r0 sits in front of
 * the guard's own load rather than inside the `if`, which is what the
 * parameter being live across the test costs; it is not an argument set-up
 * for a call that happens later.
 *
 * symbols:
 *   g_0214652C  0x0214652C  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AD88.c \
 *       --addr 0x0201AD88 --thumb
 */

typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *g_0214652C;

void sub_0201AD88(u32 heap)
{
    if (g_0214652C == 0) {
        g_0214652C = func_020490F4(0x10, heap);
    }
}
