/*
 * function: func_0218C860
 * address:  0x0218C860
 * packet:   pkt_ov021_0218C860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218BA48  0x0218BA48  thumb  ov021
 *   func_0218C0D8  0x0218C0D8  thumb  ov021
 *   func_0218C54C  0x0218C54C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

void func_0218BA48(void *s, void *v);
void func_0218C0D8(void *p);
void func_0218C54C(void *p, int save);
void func_020307B0(void *p);

typedef struct {
    void *owner;
    int f4;
    void *f8;
    unsigned char fC[1];
} S;

void func_0218C860(S *p)
{
    if (p != 0) {
        func_0218BA48(p->owner, p);
        func_0218C0D8(p->fC);
        if (p->f8 != 0)
            func_0218C54C(p->f8, 1);
        func_020307B0(p);
    }
}
