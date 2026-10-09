/*
 * file:     unit_021DF8E8.c
 * unit:     yes
 * function: func_021DF8E8, func_021DF8F4, func_021DF900, func_021DF90C, func_021DF918, func_021DF924, func_021DF930, func_021DF93C, func_021DF968
 * address:  0x021DF8E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F1544     0x021F1544  data   ov093  a4
 *   d_021F14DC     0x021F14DC  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   d_021F1414     0x021F1414  data    a4
 *   d_021F141C     0x021F141C  data   ov093  a4
 */
extern int func_021D775C(int key);
extern void func_021D7704(int key, int m);
extern int func_021DD008(int a);
void func_021DF8E8(int a, int b, int c);
int *func_021DF8F4(int *p);
void func_021DF900(int a, int b, int c);
int *func_021DF90C(int *p);
void func_021DF918(int a, int b, int c);
int *func_021DF924(int *p);
void func_021DF930(int a, int b, int c);
void func_021DF93C(int a, int b, int c, int d);
int *func_021DF968(int *p);
extern int d_021F1544[];
extern int d_021F14DC[];
extern int d_021F1414[];
extern int d_021F141C[];




void func_021DF8E8(int a, int b, int c)
{
    func_021DF93C(a, b, c, 5);
}




int *func_021DF8F4(int *p)
{
    *p = 1;
    return d_021F1544;
}




void func_021DF900(int a, int b, int c)
{
    func_021DF93C(a, b, c, 10);
}



int *func_021DF90C(int *p)
{
    *p = 1;
    return d_021F14DC;
}



void func_021DF918(int a, int b, int c)
{
    func_021DF93C(a, b, c, 10);
}


int *func_021DF924(int *p)
{
    *p = 1;
    return d_021F1414;
}


void func_021DF930(int a, int b, int c)
{
    func_021DF93C(a, b, c, 0xb);
}



void func_021DF93C(int a, int b, int c, int d)
{
    if (c != func_021D775C(3))
        return;
    if (d != func_021D775C(22))
        return;
    func_021D7704(49, func_021DD008(a));
}


/*
 * sdk:      sciGetServiceUrl (libdwcgssc.TWL.HYB.a(sciinterface.o))
 */
int *func_021DF968(int *p)
{
    *p = 1;
    return d_021F141C;
}
