/*
 * file:     unit_021DEDF8_p01.c
 * unit:     yes
 * function: func_021DEE48, func_021DEE7C
 * address:  0x021DEE48
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
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */
typedef unsigned char u8;

extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_021D76BC(int,unsigned int);
extern void func_021DD044(void *, void *, int);
void func_021DEE48(int a,int b,int c,int *p);
void func_021DEE7C(void *a, void *b, int c, int *d);

void func_021DEE48(int a,int b,int c,int *p) { if(c==func_021D775C(3)) { if(func_021D775C(18)!=507) { if(func_021D76BC(81,1)) *p=1; } } }

void func_021DEE7C(void *a, void *b, int c, int *d)
{
    if (c == func_021D775C(3) && *d != 0)
        func_021DD044(a, b, c);
}
