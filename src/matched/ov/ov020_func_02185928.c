/*
 * function: func_02185928
 * address:  0x02185928
 * packet:   pkt_ov020_02185928
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  byte-correct (MATCH*, 198 of 200 bytes, the rest is padding);
 *           the THM_CALL to func_02013DD0 (arm9) has no witness: 0x02013DD0
 *           is an unlabelled arm9 leaf (Ilias's, inside func_02013D9C's
 *           listing extent; see unit_02013D9C.c's near-miss note). Verified
 *           C for it, per ov018_func_0217EC7C.c:
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 *
 * symbols:
 *   func_02013DD0  0x02013DD0  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_020127E0  0x020127E0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02186538  0x02186538  thumb  ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02186854  0x02186854  thumb  ov020
 *   func_021868B8  0x021868B8  thumb  ov020
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 */

int func_02013DD0(unsigned short a);
int func_02012B38(int a);
int func_0201444C(int a);
int func_02012964(int a);
int func_0201296C(int a);
unsigned short *func_020127C4(int a);
unsigned short *func_020127D0(int a, int b);
int func_020127E0(int a);
void func_020307B0(int a);
int func_02186538(unsigned short *a, int b, int c);
int func_02186278(unsigned short *a, int b);
int func_02186854(int a);
int func_021868B8(int a, int b, int c, int d);
void func_0216CEAC(int a, int b, int c, int d, int e);

void func_02185928(int a, const short *p)
{
    int r6;
    int r5;
    int r4;
    int ip;
    int sc;
    int s8;
    unsigned short *r7;

    if (func_02013DD0(p[2]) == 0)
        return;

    r6 = func_0201444C(func_02012B38(a));
    sc = func_02012964(a);
    s8 = func_0201296C(a);
    if (r6 == 0)
        r7 = func_020127C4(a);
    else
        r7 = func_020127D0(a, 0);

    r5 = func_02186538(r7, r6, 1);
    ip = func_02186278(r7, r6);
    if (r5 != 0 && ip != 0)
        func_0216CEAC(sc, r5, p[2], ip, s8);
    if (r5 != 0)
        func_020307B0(r5);

    r5 = func_020127E0(a);
    r4 = func_02186854(r5);
    r5 = func_021868B8(r5, r6, r7[1], 1);
    if (r5 != 0 && r4 != 0)
        func_0216CEAC(sc, r5, p[2], r4, s8);
    if (r5 != 0)
        func_020307B0(r5);
}
