/*
 * function: func_0216AC90
 * address:  0x0216AC90
 * packet:   pkt_0216AC90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching func_0217C294 (ov018, EXACT; itself unblocked by
 * func_0216D63C): the +0026 call site now attests as `matched`.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0216AED0  0x0216AED0  thumb  ov010
 *   func_0217C294  0x0217C294  thumb  ov018
 *   func_0200E18C  0x0200E18C  thumb
 *   func_0216AF3C  0x0216AF3C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern int func_02159B10(int a0, int a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
extern void *func_0216AED0(void *p, u32 id);
extern int func_0217C294(char *a0);
extern int func_0200E18C();
extern void func_0216AF3C(int a0);

int func_0216AC90(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *w;
    void *r;

t5 = a1 + 0;
    a0 = func_02159B10(a0, a1);
loc_0216AC98:
t4 = a0 + 0;
a0 = t5 + 0;
    w = func_0215A5E4((void *)a0);
loc_0216ACA0:
    w = func_02012EBC(w);
loc_0216ACA4:
    t6 = func_0200E0B0(w);
loc_0216ACA8:
a0 = t5 + 0;
a1 = t4 + 0;
    r = func_0216AED0((void *)a0, a1);
loc_0216ACB2:
    if (r == 0) goto loc_0216ACC8;
loc_0216ACB6:
    a0 = func_0217C294(r);
loc_0216ACBA:
a1 = a0 + 0;
    a0 = func_0200E18C(t6, a1);
loc_0216ACC2:
a0 = t5 + 0;
    func_0216AF3C(a0);
loc_0216ACC8:
a0 = 0;
    return a0;}
