/*
 * function: func_02185A68
 * address:  0x02185A68
 * packet:   pkt_ov020_02185A68
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014450  0x02014450  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013DF0  0x02013DF0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_020129AC  0x020129AC  thumb
 *   func_020129B8  0x020129B8  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02012974  0x02012974  thumb
 *   func_02013B44  0x02013B44  thumb
 *   func_02162408  0x02162408  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_02185A34  0x02185A34  thumb  ov020
 */

void *func_020120F4(void *p);
void *func_02012844(void *p);
void *func_0201210C(void *p);
int func_02012B70(void *p);
int func_02013D5C(int v);
void *func_02012B38(void *p);
void func_02014450(void *p, int v);
int func_02013CC8(int v);
int func_02013CE0(int v);
int func_02013DF0(int v);
int func_02013D20(int v);
int func_020129AC(void *p);
void func_020129B8(void *p, int v);
int func_02012984(void *p);
void *func_02012974(void *p);
int func_02013B44(int v);
void func_02162408(void *p, int v, int w);
void func_02159B94(void *p, int a, int b, int c);
void func_02159CC4(void *p, void *a, int b);
void func_02185A34(void *p, int v);

void func_02185A68(void *a, int b)
{
    void *r4;
    void *r7;
    int st;

    r4 = func_020120F4(a);
    r7 = func_02012844(r4);
    func_0201210C(a);
    if (func_02012B70(r4) == 1 && func_02013D5C(b) == 0)
        func_02014450(func_02012B38(r4), 1);
    else
        func_02014450(func_02012B38(r4), 0);

    if (func_02013CC8(b) != 0) {
        func_020129B8(r4, 2);
    } else if (func_02013CE0(b) != 0 || func_02013DF0(b) != 0 || func_02013D20(b) != 0) {
        func_020129B8(r4, 5);
    } else {
        if (func_02012B70(r4) == 1 && func_020129AC(r4) != 3)
            func_020129B8(r4, 3);
        else if (func_02012B70(r4) == 0 && func_020129AC(r4) == 3)
            func_020129B8(r4, 0);
        st = func_020129AC(r4);
        if (st != 3 && st != 4 && st != 6)
            func_020129B8(r4, 0);
    }

    func_02162408(r7, b, func_02012984(r4));
    r7 = func_02012974(r4);
    func_02159B94(r7, func_02013B44(b), b, 0x8001);
    func_02159CC4(r7, a, 0x8001);
    func_02185A34(r4, b);
}
