/*
 * file:     zukan_detail_graphic_p04.c
 * unit:     yes
 * function: func_021BD388, func_021BD394, func_021BD3A4
 * address:  0x021BD388
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD43C 0x021BD43C  thumb  ov208
 *   func_021BD808 0x021BD808  thumb  ov208
 *   func_021BD404 0x021BD404  thumb  ov208
 *   func_021BD844 0x021BD844  thumb  ov208
 *   func_021BD848 0x021BD848  thumb  ov208
 */
extern void *func_021BD43C(void *mgr, int key);
extern void func_021BD808(int *p);
extern int func_021BD404(int, int);
extern void func_021BD844(char *p, int v);
extern void func_021BD848(char *p, int which);
void func_021BD388(void *mgr, int key);
void func_021BD394(int a, int b, int c);
void func_021BD3A4(int a, int b, int c);


void func_021BD388(void *mgr, int key)
{
    func_021BD808(func_021BD43C(mgr, key));
}


void func_021BD394(int a, int b, int c)
{
    func_021BD844((char *)func_021BD404(a, b), c);
}


void func_021BD3A4(int a, int b, int c)
{
    func_021BD848((char *)func_021BD404(a, b), c);
}
