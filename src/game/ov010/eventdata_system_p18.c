/*
 * file:     eventdata_system_p18.c
 * unit:     yes
 * function: func_021630F4, func_0216310C, func_02163130
 * address:  0x021630F4
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
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_021640B0 0x021640B0 thumb ov010
 *   func_0216DA70 0x0216DA70 thumb ov010
 *   func_021641C8 0x021641C8 thumb ov010
 *   func_02163230 0x02163230 thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern u32 func_0216D57C(void *p, u32 v);
extern int func_02164010(int a);
extern int func_021640B0(int p);
extern void func_0216DA70(void *a0);
extern void func_021641C8(void *a);
extern void func_02163230(int a0);
extern char *func_0216D570(char *p, u32 v);
int func_021630F4(int a0, int a1);
void func_0216310C(char *p);
void func_02163130(char *p);


int func_021630F4(int a0, int a1)
{
    int t4;

a1 = 1;
a1 = a1 << 0xc;
t4 = a0 + 0;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163100:
    if (a0 == 0) goto loc_0216310A;
loc_02163104:
a0 = t4 + 0;
    a0 = func_02164010(a0);
loc_0216310A:
    return a0;}

/*
 * trailing: two-byte zero alignment at 0x0216312E before func_02163130.
 */
void func_0216310C(char *p)
{
    if (func_0216D57C(p, 0x800) != 0 && func_021640B0((int)p) == 1)
        func_0216DA70(p);
}

void func_02163130(char *p)
{
    if (func_0216D57C(p, 0x20)) {
        func_021641C8(p);
        func_02163230((int)p);
    }
    func_0216D570(p, 0xa0);
}
