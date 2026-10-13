/*
 * function: FIELD_BUILDMODEL_ClearEntry
 * address:  0x0218C490
 * packet:   pkt_ov021_0218C490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    int a;
    int b;
    short c;
    short d;
    int e;
} S;

void FIELD_BUILDMODEL_ClearEntry(int unused, S *s)
{
    s->a = 0;
    s->b = -1;
    s->c = 0;
    s->d = 0;
    s->e = 0;
}
