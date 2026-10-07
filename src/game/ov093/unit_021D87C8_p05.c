/*
 * file:     unit_021D87C8_p05.c
 * unit:     yes
 * function: func_021D8AEC, func_021D8B1C
 * address:  0x021D8AEC
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F0738 0x021F0738 data a4
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
extern int func_021D7AD4(int);
extern void func_021D7704(int,int);
void func_021D8AEC(int a, int b, int c, int d, unsigned char e);
void func_021D8B1C(int a, int b, int c);
void *func_021D8B44(int *p);
extern unsigned char d_021F0738[];


void func_021D8AEC(int a, int b, int c, int d, unsigned char e)
{
    if(c==func_021D775C(2) && func_021D775C(0x32)>0 && e==func_021D775C(0x39)) func_021D76BC(0x41,1);
}


void func_021D8B1C(int a, int b, int c)
{
    if(c==func_021D775C(3) && func_021D7AD4(func_021D775C(0x38))==3) func_021D7704(0x35,0x2000);
}


void *func_021D8B44(int *p)
{
    *p = 1;
    return d_021F0738;
}
