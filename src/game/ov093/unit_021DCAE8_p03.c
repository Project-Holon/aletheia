/*
 * file:     unit_021DCAE8_p03.c
 * unit:     yes
 * function: func_021DCDD0, func_021DCDF8, func_021DCE18, func_021DCE48
 * address:  0x021DCDD0
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
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
struct QQ;
struct R4;
struct S;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021D775C(int);
extern u16 func_021D70A8(struct QQ *p);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D6C24(struct R4 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void func_021DCDD0(int a,unsigned char *b,int c);
void func_021DCDF8(int a,unsigned char *b,int c);
void func_021DCE18(int a,unsigned char *b,int c);
void func_021DCE48(int a, u8 *b, int c);

void func_021DCDD0(int a,unsigned char *b,int c) { if(c==func_021D775C(4) && func_021D775C(70)==0) func_021DCE48(a,b,c); }

void func_021DCDF8(int a,unsigned char *b,int c) { if(c==func_021D775C(2)) func_021DCE48(a,b,c); }

void func_021DCE18(int a,unsigned char *b,int c) { int k; k=func_021D775C(16); if(k!=func_021D70A8((void *)a) && c==func_021D775C(2)) func_021DCE48(a,b,c); }


void func_021DCE48(int a, u8 *b, int c)
{
    u8 *p;
    if (func_021D6C24(func_021C7CF4((int *)b, c))) {
        p = func_021C88A4((char *)b, 0x34, c);
        p[4] = c;
        func_021C8838(p + 8, 2, 478);
        func_021C8860((struct S *)(p + 8), c);
        func_021C88C8(b, p);
    }
}
