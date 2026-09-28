/*
 * unit:     no
 * function: func_0209AB8C
 * address:  0x0209AB8C
 * packet:   pkt_0209A0EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * note:     EXACT* not EXACT: the label following this function in the
 *           listing is the veneer block at 0x0209AC04 (0x0209ABEC/0x0209ABF8
 *           are unlabelled), so the printed extent is 120 against a compiled
 *           96.  All 96 compared bytes (code + literal pool) match and the
 *           single relocation resolves via `literal`.
 * symbols:
 *   g_020A60DC  0x020A60DC  data
 *
 * Case-insensitive string compare: each byte is mapped through the 256-byte
 * table at 0x020A60DC when it is below 0x80, then compared as unsigned.
 * The `>= 0` half of the guard is what emits the `cmp #0; blt` before the
 * `cmp #0x80; ldrblt`, even though the byte load is unsigned.
 *
 * The interleaved declarations (`int c1; u8 m1; int c2; u8 m2;`) matter:
 * they make mwccarm color the c1 mask into ip and the raw c2 into lr, which
 * is what the original does.  Declaring the two mask temps together instead
 * swaps those two scratch registers (9-byte DIFF).
 */

typedef unsigned char u8;

extern const u8 g_020A60DC[];

int func_0209AB8C(const u8 *s1, const u8 *s2)
{
    const u8 *tab = g_020A60DC;
    int c1;
    u8 m1;
    int c2;
    u8 m2;

    for (;;)
    {
        c1 = *s1++;
        if (c1 >= 0 && c1 < 0x80)
            c1 = tab[c1];
        m1 = (u8)c1;

        c2 = *s2++;
        if (c2 >= 0 && c2 < 0x80)
            c2 = tab[c2];
        m2 = (u8)c2;

        if (m1 < m2)
            return -1;
        if (m1 > m2)
            return 1;
        if (m1 == 0)
            return 0;
    }
}