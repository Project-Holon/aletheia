/*
 * function: BOX2_SEQ_StateDispatchFont
 * address:  0x021E2154
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021EFA28  0x021EFA28  data  ov170
 *
 * Dispatch through the 12-byte table at 0x021EFA28 keyed by p[0x12].
 *   CLOSES the operand-order residue: the image's `ldr r1,[r1,r3]` (base first)
 *   comes out of a pointer VARIABLE holding the element address; writing the
 *   subscript as a direct member access makes mwccarm encode `[r3,r1]`.
 */


extern struct Ent { void (*fn)(void *); int a; int b; } g_021EFA28[];
int BOX2_SEQ_StateDispatchFont(unsigned char *p)
{
    struct Ent *e = &g_021EFA28[p[0x12]];
    e->fn(p);
    return 10;
}
