/*
 * file:     unit_021DE980_p02.c
 * unit:     yes
 * function: func_021DEA58, func_021DEA8C
 * address:  0x021DEA58
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
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */
struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern void *func_021C7CF4(int *,int);
extern int func_021D5B48(u8 *p);
extern int func_021D76BC(int,unsigned int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
void func_021DEA58(int a,int *b,int c,int *p);
void func_021DEA8C(int a, void *b, int c, int *d);

/*
 * interface: func_021C7CF4 returns its live r0 here (the matched
 * tail forwarder is declared void); r1 is visibly loaded with c before
 * the call and is retained as an argument, per canonical exceptions.
 */
void func_021DEA58(int a,int *b,int c,int *p) { if(c==func_021D775C(4)) { if(func_021D5B48(func_021C7CF4(b,c))) *p=func_021D76BC(58,3); else *p=0; } }


void func_021DEA8C(int a, void *b, int c, int *d)
{
    u8 *r;

    if (c == func_021D775C(2) && *d != 0) {
        r = (u8 *)func_021C88A4(b, 0x23, c);
        func_021C8838(r + 8, 2, 0x3ef);
        func_021C8860((struct S *)(r + 8), c);
        func_021C8860((struct S *)(r + 8), func_021D70A8((void *)a));
        func_021C88C8(b, r);
        *d = 0;
    }
}
