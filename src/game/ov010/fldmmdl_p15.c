/*
 * file:     fldmmdl_p15.c
 * unit:     yes
 * function: func_0216D438, func_0216D454
 * address:  0x0216D438
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
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216D7C0();
extern void *func_0216D7C8(void *p, u16 v);
extern char *func_0216D570(char *p, u32 v);
extern u32 func_0216D57C(void *p, u32 v);
void func_0216D438(char *a0, int a1);
int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);


void func_0216D438(char *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
    a0 = (char *)func_0216D7C0(a0, a1);
loc_0216D440:
a0 = (char *)(t4 + 0);
a1 = 0;
    a0 = (char *)func_0216D7C8(a0, a1);
loc_0216D448:
a1 = 1;
a0 = (char *)(t4 + 0);
a1 = a1 << 0xa;
    a0 = (char *)func_0216D570(a0, a1);
loc_0216D452:
    return;}


int func_0216D454(int a0, u32 a1, u32 a2, u32 a3)
{
    int t4;
    int t5;

t4 = 2;
t4 = t4 << 8;
a1 = t4 + 0;
t5 = a0 + 0;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D462:
    if (a0 != 0) goto loc_0216D46A;
loc_0216D466:
a0 = 1;
    return a0;
loc_0216D46A:
a0 = t5 + 0;
a1 = t4 << 1;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D472:
    if (a0 == 0) goto loc_0216D47A;
loc_0216D476:
a0 = 1;
    return a0;
loc_0216D47A:
a0 = 0;
    return a0;}
