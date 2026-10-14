/*
 * function: BTLV_EFFVM_InitParams
 * address:  0x021F9844
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFVM_InitParams   0x021F9844  thumb
 *
 * lane O10 candidate
 */

typedef struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int  w1;
    unsigned int  w2;
    unsigned short h1;
} S9844;

void BTLV_EFFVM_InitParams(S9844 *p)
{
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b3 = 0;
    p->w1 = 0;
    p->w2 = 0;
    p->h1 = 0;
}

