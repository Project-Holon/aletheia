/*
 * function: sub_020130DC
 * address:  0x020130DC
 * packet:   pkt_020130DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * verdict is EXACT* : all 74 code bytes reproduce (5 of 5 relocation sites
 * resolved), the inferred extent only ran long by the follower at 0x02013128
 * (28 bytes, a tail-call wrapper into 0x0201AC2C|1) which has no label
 * because it saves nothing -- report it for layout/function_starts.txt
 * rather than editing that file here.
 */

typedef struct {
    char pad0[0x24];
    void *a24[4];
    void *a34[4];
    char pad1[4];
    void *a48[4];
    char pad2[0x3c];
    void *a94;
} S;

extern void sub_020307B0(void *p);
extern int sub_02013270(int a0);
extern void sub_02082BCC(void *p, int c, int n);

void sub_020130DC(S *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p->a24[i] != 0)
            sub_020307B0(p->a24[i]);
        if (p->a48[i] != 0)
            sub_02013270((int)p->a48[i]);
        if (i != 0 && p->a34[i] != 0)
            sub_020307B0(p->a34[i]);
    }
    if (p->a94 != 0)
        sub_020307B0(p->a94);
    sub_02082BCC(p, 0, 0xf0);
}
