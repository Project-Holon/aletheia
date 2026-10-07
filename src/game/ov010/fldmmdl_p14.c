/*
 * file:     fldmmdl_p14.c
 * unit:     yes
 * function: func_0216D3CC, func_0216D410
 * address:  0x0216D3CC
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
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216D55C(int a0, int a1);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_0216D7C0(void *p, u16 v);
extern void *func_0216D7C8(void *p, u16 v);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
int func_0216D3CC(int a0);
void func_0216D410(void *a0, u16 a1);


int func_0216D3CC(int a0)
{
    int a1;
    int t4;
    int t5;

a1 = 1;
t5 = a0 + 0;
    a0 = func_0216D55C(a0, a1);
loc_0216D3D6:
    if (a0 != 0) goto loc_0216D3DE;
loc_0216D3DA:
a0 = 0;
    return a0;
loc_0216D3DE:
a0 = t5 + 0;
a1 = 0x10;
t4 = 0x10;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D3E8:
    if (a0 == 0) goto loc_0216D3F0;
loc_0216D3EC:
a0 = 0;
    return a0;
loc_0216D3F0:
a0 = t5 + 0;
a1 = t4 << 5;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D3F8:
    if (a0 == 0) goto loc_0216D40C;
loc_0216D3FC:
a0 = t5 + 0;
a1 = t4 << 6;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D404:
    if (a0 != 0) goto loc_0216D40C;
loc_0216D408:
a0 = 0;
    return a0;
loc_0216D40C:
a0 = 1;
    return a0;}


/*
 * blocked:  listing 40 compiled 38
 */
void func_0216D410(void *a0, u16 a1)
{
    u32 t4;

    func_0216D7C0(a0, a1);
    func_0216D7C8(a0, 0);
    t4 = 2;
    t4 = t4 << 8;
    func_0216D568(a0, t4);
    func_0216D570(a0, t4 << 1);
}
