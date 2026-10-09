/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC, func_021F3708, func_021F3714, func_021F3744, func_021F3758, func_021F3788, func_021F37B8, func_021F3808, func_021F383C, func_021F3890
 * address:  0x021F36C0
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02189764 0x02189764 thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F3894 0x021F3894 thumb ov050
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B8 0x021BE6B8 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_021BE4B4 0x021BE4B4 thumb ov021
 *   func_021BE760  0x021BE760  thumb
 *   func_021BE480  0x021BE480  thumb
 *   d_021F38A4     0x021F38A4  data  a4
 *   d_021F38B4     0x021F38B4  data  a4
 */
#include "../../matched/include/Obj20550.h"

typedef unsigned int   u32;

typedef struct { int a; int b; int c; } T12;

extern unsigned short func_02188C84(unsigned char *);
extern void *func_02189764(unsigned char *, int, int, int);
extern int *func_021897BC(char *, int);
extern void func_021F3894(int *, char *);
extern void func_021897A0(unsigned char *, int);
extern void *func_02188D2C(void *p);
extern void func_021BE580(void *p);
extern void func_021BE700(void *p, int i, unsigned short j, unsigned short k, int flag);
extern void *func_021BE674(void *p, int i, unsigned short j, unsigned short k);
extern void func_021BE6B8(unsigned char *,int);
extern int func_021BE6BC(int *);
extern void func_021BE4B4(char *,int,int,int);
extern void func_021BE760(int a, void *b, int c);
extern T12 *func_021BE480(int a, int b, unsigned short c);
void func_021F36C0(unsigned char *p);
void func_021F36EC(char *p);
void func_021F3708(void *p);
void func_021F3714(int *p);
void func_021F3744(int *p);
int func_021F3758(int *p);
void func_021F3788(int *p);
void func_021F37B8(int *a);
int func_021F3808(int *p);
void func_021F383C(void *unused, int *b);
void func_021F3890(void *q, unsigned char *p);
extern int d_021F38A4;
extern const T12 d_021F38B4[];




void func_021F36C0(unsigned char *p) { unsigned short h; void *q; h=func_02188C84(p); q=func_02189764(p,1,h,2); ((struct Obj20550 *)q)->f0=h; func_021F383C(q,(int *)p); func_021F3890(q,p); }




void func_021F36EC(char *p) { func_021F3894(func_021897BC(p,1),p); func_021897A0((unsigned char *)p,1); }


void func_021F3708(void *p)
{
    func_021BE580(func_02188D2C(p));
}





void func_021F3714(int *p) { char *q=(char *)func_02188D2C(p); func_021BE700(q,0,0,0,1); func_021BE6B8(func_021BE674(q,0,0,0),0); }





void func_021F3744(int *p) { func_021BE700((void *)func_02188D2C(p), 0, 0, 0, 0); }




int func_021F3758(int *p) { int i; char *q; q=(char *)func_02188D2C(p); for(i=0;i<1;i++) { if(func_021BE6BC(func_021BE674(q,0,0,(unsigned short)i))==0) return 0; } return 1; }



void func_021F3788(int *p) { int i; char *q; q=(char *)func_02188D2C(p); func_021BE4B4(q,0,1,1); for(i=0;i<2;i++) func_021BE700(q,0,1,(unsigned short)i,0); }




void func_021F37B8(int *a)
{
    char *r6;
    int i;
    int j;

    r6 = (char *)(int)func_02188D2C(a);
    func_021BE4B4(r6, 0, 1, 0);
    for (i = 0; i < 2; i++)
        func_021BE700(r6, 0, 1, i, 1);
    for (j = 0; j < 2; j++)
        func_021BE6B8(func_021BE674(r6, 0, 1, j), 0);
}



/*
 * note: two-byte alignment padding at 0x021F383A; index declared before pointer restores r4/r5; u16 fourth parameter matches call-site truncation.
 */
int func_021F3808(int *p) { int i; char *q; q=(char *)(int)func_02188D2C(p); for(i=0;i<2;i++) { if(func_021BE6BC((int *)func_021BE674(q, 0, 1, i))==0) return 0; } return 1; }




void func_021F383C(void *unused, int *b)
{
    int r4;
    int i;
    T12 *p;
    const T12 *s;

    r4 = (int)func_02188D2C(b);
    func_021BE760(r4, &d_021F38A4, 0);
    for (i = 0; i < 2; i++) {
        p = func_021BE480(r4, 0, i);
        s = &d_021F38B4[i];
        p->a = s->a;
        p->b = s->b;
        p->c = s->c;
    }
    func_021F3744(b);
    func_021F3788(b);
}



void func_021F3890(void *q, unsigned char *p)
{
}
