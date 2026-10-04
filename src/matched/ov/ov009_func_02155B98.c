/*
 * function: func_02155B98
 * address:  0x02155B98
 * packet:   pkt_ov009_02155B98
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_0205984C  0x0205984C  arm
 *   func_02059870  0x02059870  arm
 *   func_02155374  0x02155374  thumb  ov009
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x108];
    int h;
    char pad2[0x7a2 - 0x10c];
    u8 flag;
} G;

extern G *d_021A8264;
int func_0205984C(void *userdata);
void func_02059870(int h);
void func_02155374(int n);

void func_02155B98(int a)
{
    if (func_0205984C((void *)d_021A8264->h) != 0) {
        func_02059870(d_021A8264->h);
        d_021A8264->flag = 1;
    }
    if (a == 0)
        func_02155374(4);
    else
        func_02155374(14);
}
