/*
 * file:     weather_task_p11.c
 * unit:     yes
 * function: func_021A240C, func_021A2418
 * address:  0x021A240C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_021A03CC  0x021A03CC  thumb  ov021
 */
int func_021A03B8(int *p);
int func_021A03CC(int *p);
int func_021A240C(int *p);
int func_021A2418(int *p);


/*
 * Unlabelled tail-call stub, filed as a blocker of the ov024 lane S26.
 */
int func_021A240C(int *p)
{
    return func_021A03B8((int *)p[4]);
}


int func_021A2418(int *p)
{
    return func_021A03CC((int *)p[4]);
}
