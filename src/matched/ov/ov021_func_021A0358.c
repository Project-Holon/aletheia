/*
 * function: FIELD_ZONEFOG_Clear
 * address:  0x021A0358
 * packet:   pkt_ov021_021A0358
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;

typedef struct {
    u8 state;
    u8 pad[3];
    void *buf;
    int val;
} S;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void FIELD_ZONEFOG_Clear(S *s)
{
    if (s->buf != 0) {
        func_020307B0(s->buf);
        s->buf = 0;
    }
    s->val = 0x0FFFFFFF;
    if (s->state == 1) {
        s->state = 0;
    }
}
