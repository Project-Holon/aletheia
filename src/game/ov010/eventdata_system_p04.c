/*
 * file:     eventdata_system_p04.c
 * unit:     yes
 * function: func_02161F68, func_02161F74, func_02161F90
 * address:  0x02161F68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216210C  0x0216210C  thumb  ov010
 *   func_02162120  0x02162120  thumb  ov010
 *   func_02161DC4  0x02161DC4  thumb
 *   func_021867C4  0x021867C4  thumb ov020
 *   func_0218682C  0x0218682C  thumb
 *   func_02186804  0x02186804  thumb
 *   func_02186520  0x02186520  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02161E60  0x02161E60  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

void func_02082BCC(void *p, int v, int n);
extern int func_0216210C(int a0);
extern int func_02162120();
extern u8 *func_02161DC4(char *, int, int);
extern int *func_021867C4(int a, int id);
extern u16 *func_0218682C(int h);
extern void func_02186804(int);
extern void func_02186520(u16 *, int, u8 *);
extern void func_02161E78(void *a0);
extern int func_02161E60(int a0, int a1);
void func_02161F68(void *p);
void func_02161F74(int a0, int a1, int a2);
void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v);


void func_02161F68(void *p)
{
    func_02082BCC(p, 0, 0x48);
}


void func_02161F74(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = func_0216210C(a0);
loc_02161F80:
    if (a0 != 0) goto loc_02161F8E;
loc_02161F84:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = func_02162120(a0, a1, a2);
loc_02161F8E:
    return;}


void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v)
{
    u8 *r4;
    int h;
    u16 *q;

    r4 = func_02161DC4(y, w, 1);
    h = (int)func_021867C4(w, v);
    q = func_0218682C(h);
    if (x[1] == 0)
        r4[2] = q[3];
    else
        r4[2] = q[2];
    r4[3] = 7;
    func_02186804(h);
    func_02186520(x, z, r4);
    func_02161E78(r4);
    func_02161E60((int)y, 1);
}
