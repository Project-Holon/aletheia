/*
 * unit:     yes
 * function: func_021BBE44, func_021BBE50, func_021BBE5C
 * address:  0x021BBE44
 * packet:   pkt_021BBE44
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three null-guarded wrappers, each into an ARM9 routine.
 *
 * symbols:
 *   func_02028148  0x02028148  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02028218  0x02028218  thumb
 */

extern void func_02028148(int);
extern void func_02028178(int);
extern void func_02028218(int, int);

void func_021BBE44(int x)
{
    if (x != 0)
        func_02028148(x);
}

void func_021BBE50(int x)
{
    if (x != 0)
        func_02028178(x);
}

void func_021BBE5C(int x, int f)
{
    if (x != 0)
        func_02028218(x, f);
}
