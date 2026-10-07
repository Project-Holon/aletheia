/*
 * file:     zukan_detail_graphic_p05.c
 * unit:     yes
 * function: func_021BD3B4, func_021BD3C0
 * address:  0x021BD3B4
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
 *   func_021BD868 0x021BD868  thumb  ov208
 *   func_021BD404 0x021BD404  thumb  ov208
 */
extern void *func_021BD43C(void *mgr, int key);
extern int func_021BD868(const void *p);
extern void *func_021BD404(void *mgr, int key);
int func_021BD3B4(void *mgr, int key);
int func_021BD3C0(void *mgr, int key);


int func_021BD3B4(void *mgr, int key)
{
    return func_021BD868(func_021BD43C(mgr, key));
}


int func_021BD3C0(void *mgr, int key)
{
    return *(int *)func_021BD404(mgr, key);
}
