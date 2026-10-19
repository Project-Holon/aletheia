/*
 * function: BTLV_FIELD_StartTint
 * address:  0x021F6DEC
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_FIELD_StartTint   0x021F6DEC  thumb
 *   BODY

 *
 * lane O10 candidate
 */

typedef struct {
    char pad[0x60];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
} S6DEC;

void BTLV_FIELD_StartTint(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d)
{
    p->f0 = 1;
    p->f2 = a;
    p->f3 = b;
    p->f4 = 0;
    p->f5 = c;
    p->f6 = d;
}

