/*
 * file:     weather_task_p10.c
 * unit:     yes
 * function: func_021A23E8, func_021A23F4, func_021A2400
 * address:  0x021A23E8
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
 *   func_021A0380  0x021A0380  thumb  ov021
 *   func_021A0390  0x021A0390  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 */
int func_021A0380(int *p);
int func_021A0390(int *p);
int func_021A03A4(int *p);
int func_021A23E8(int *p);
int func_021A23F4(int *p);
int func_021A2400(int *p);


/*
 * Unlabelled tail-call stub, filed as a blocker of the ov024 lane S26.
 */
int func_021A23E8(int *p)
{
    return func_021A0380((int *)p[4]);
}


int func_021A23F4(int *p)
{
    return func_021A0390((int *)p[4]);
}


int func_021A2400(int *p)
{
    return func_021A03A4((int *)p[4]);
}
