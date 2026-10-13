/*
 * function: func_021FD52C
 * address:  0x021FD52C
 * packet:   pkt_ov132_021FD52C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf hidden in a .word run; helper whose address is the
 * witness for the call in ov010 MUSICAL_DRESSUP_SYS_Main.
 */

typedef unsigned char u8;

typedef struct S {
    u8 pad00[0x14C];
    u8 f14c;
    int f150;
    int f154;
    u8 pad158[0x24];
    int f17c;
} S;

void func_021FD52C(S *s)
{
    if (s->f150 == 0) {
        s->f150 = 1;
        s->f14c = 0;
        s->f17c = 1;
        s->f154 = 0;
    }
}
