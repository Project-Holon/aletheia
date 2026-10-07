/*
 * file:     unit_021DE980_p03.c
 * unit:     yes
 * function: func_021DEAF4, func_021DEB30, func_021DEB5C
 * address:  0x021DEAF4
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
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021DCFD0 0x021DCFD0 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
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
extern int func_021DCFF8(int,int);
extern int func_021DCFD0(int *,unsigned int);
extern int func_021D76BC(int,unsigned int);
extern void func_021DD044(void *,void *,int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
void func_021DEAF4(int a,int *b,int c,int *p);
void func_021DEB30(int a,int b,int c,int *p);
void func_021DEB5C(int a, void *b, int c);

/*
 * lever: int n = (unsigned char)func_021DCFF8(a,2) schedules the
 * narrowing in r0 then r1. An inline call cast costs an extra copy (62 B).
 */
void func_021DEAF4(int a,int *b,int c,int *p) { int n; if(c==func_021D775C(4)) { n=(unsigned char)func_021DCFF8(a,2); if(func_021DCFD0(b,n)) *p=func_021D76BC(58,3); else *p=0; } }

/*
 * extent: remaining two bytes are zero alignment padding.
 */
void func_021DEB30(int a,int b,int c,int *p) { if(c==func_021D775C(2)) { if(*p) { func_021DD044((void *)a,(void *)b,c); *p=0; } } }


void func_021DEB5C(int a, void *b, int c)
{
    u8 *r;

    if (c == func_021D775C(2)) {
        r = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(r + 4, 2, 0x3ef);
        func_021C8860((struct S *)(r + 4), c);
        func_021C8860((struct S *)(r + 4), func_021D70A8((void *)a));
        func_021C88C8(b, r);
    }
}
