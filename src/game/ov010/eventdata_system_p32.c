/*
 * file:     eventdata_system_p32.c
 * unit:     yes
 * function: func_02163F10, func_02163F40
 * address:  0x02163F10
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
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb
 *   func_02164280  0x02164280  thumb
 *   func_02164208  0x02164208  thumb
 *   func_02163E34  0x02163E34  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216D83C(void *p);
extern int func_0216D80C();
extern int func_0216D854(void *p);
extern int func_0216D818();
extern int func_0216D86C(void *p);
extern int func_0216D824();
extern u32 func_0216D8AC(void *p);
extern void func_02164280(int x, int y, int *p);
extern void func_02164208(int dir, int *p, int amt);
extern void func_02163E34(int a, int *p, int *out);
int func_02163F10(int a0);
int func_02163F40(int a, int dir);


int func_02163F10(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
    a0 = func_0216D83C((void *)a0);
loc_02163F18:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216D80C(a0, a1);
loc_02163F20:
a0 = t4 + 0;
    a0 = func_0216D854((void *)a0);
loc_02163F26:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216D818(a0, a1);
loc_02163F2E:
a0 = t4 + 0;
    a0 = func_0216D86C((void *)a0);
loc_02163F34:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216D824(a0, a1);
loc_02163F3C:
    return a0;}


int func_02163F40(int a, int dir)
{
    int buf[3];
    int v;

    v = -1;
    func_02164280(func_0216D83C((void *)a), func_0216D86C((void *)a), buf);
    buf[1] = func_0216D8AC((void *)a);
    func_02164208(dir, buf, 0x10000);
    func_02163E34(a, buf, &v);
    return v;
}
