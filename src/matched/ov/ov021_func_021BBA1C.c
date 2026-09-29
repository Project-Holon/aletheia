/*
 * function: func_021BBA1C
 * address:  0x021BBA1C
 * packet:   pkt_ov021_021BBA1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned short u16;

void func_020307B0(int a);
void func_02030EAC(int a);
void func_02034A5C(int a);
void func_02082BCC(void *p, int v, int n);

void func_021BBA1C(int *p)
{
    int *c;

    if (p[1] == 0) {
        return;
    }
    c = (int *)p[3];
    if (c[3] != 0) {
        ((void (*)(int *, int, int))c[3])(p, *(int *)p[0], p[4]);
    }
    if (*(u16 *)((char *)p[3] + 4) != 0) {
        func_020307B0(p[4]);
    }
    func_02030EAC(p[1]);
    func_02030EAC(p[2]);
    if (p[5] != -1) {
        func_02034A5C(p[5]);
    }
    func_02082BCC(p, 0, 0x18);
}
