/*
 * function: func_021AB868
 * address:  0x021AB868
 * packet:   pkt_ov021_021AB868
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    void *f0;
    int f4;
} S;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021AB868(S *s)
{
    if (s->f0 != 0) {
        func_020307B0(s->f0);
        s->f0 = 0;
        s->f4 = 0;
    }
}
