/*
 * file:     btlv_effvm_p18.c
 * unit:     yes
 * function: func_021F8524, func_021F853C
 * address:  0x021F8524
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02209500  0x02209500  thumb ov094
 *   d_0220AF20     0x0220AF20  data ov094
 *   func_021FF348  0x021FF348  thumb  ov094
 */
struct W;
extern int func_02209500(struct W *w, int i);
extern int func_021FF348(void *, int);
int func_021F8524(int i);
int func_021F853C(int a);
extern char *d_0220AF20;


/*
 * Thumb tail call through r3: the work record at +0x1B0 of d_0220AF20 and the argument. Labelled in wave D8.
 */
int func_021F8524(int i)
{
    return func_02209500(*(struct W **)(d_0220AF20 + 0x1B0), i);
}


/*
 * Tail call to func_021FF348 with the handle at 0x190 of the global work block.
 * Unlabelled; filed as a witness for the caller ov093 func_021EA354 (wave B3 lane 17).
 */
int func_021F853C(int a)
{
    return func_021FF348(*(void **)(d_0220AF20 + 0x190), a);
}
