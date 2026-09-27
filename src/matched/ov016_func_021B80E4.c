/*
 * function: MakeKey
 * address:  0x021B80E4
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol MakeKey (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B80E4.c \
 *       --func MakeKey --addr 0x021B80E4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

void MakeKey(int ID, char *Key, int maclen, char *Wep, int weplen)
{
    int i, size, pos;

    size = maclen / 2;
    pos = ID % weplen;
    for (i = 0; i < size; i++) {
        Key[i] = i;
        Key[i] = Key[i] ^ Wep[pos];
        pos++;
        if (pos >= weplen)
            pos = 0;
    }
}
