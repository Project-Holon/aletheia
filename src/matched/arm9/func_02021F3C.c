/*
 * function: PALANM_GetColor
 * address:  0x02021F3C
 * packet:   pkt_02021F3C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Witness leaf for ov071 func_021B6C7C (tiny unlabelled arm9 leaf).
 */

typedef unsigned short u16;

typedef struct {
    u16 *a;
    u16 *b;
    int pad[3];
} Slot;

u16 PALANM_GetColor(Slot *s, int idx, int which, u16 pos)
{
    if (which == 1) {
        return s[idx].a[pos];
    }
    if (which == 0) {
        return s[idx].b[pos];
    }
    return 0;
}
