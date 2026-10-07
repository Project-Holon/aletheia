/*
 * file:     pokemontrade_proc_p15.c
 * unit:     yes
 * function: func_021DBD3C, func_021DBD70, func_021DBDB4
 * address:  0x021DBD3C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E665C 0x021E665C thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBC98 0x021DBC98 thumb ov119
 *   func_021DBC3C 0x021DBC3C thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD34C 0x021DD34C thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021DB9B4 0x021DB9B4 thumb ov119
 *   func_021DF708 0x021DF708 thumb ov119
 *   func_021DA640 0x021DA640 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021D8C84 0x021D8C84 thumb ov119
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj03774.h"

extern int func_021E665C(char *p);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *, int);
extern void func_021DBC98(char *p);
extern void func_021DBC3C(char *p);
extern int func_021D8AA8(void *);
extern int func_021DD34C(char *p, int a, int b);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern void func_020061E4(int);
extern void func_021DB9B4(void);
extern void func_021DF708(void);
extern void func_021DA640(void);
extern int func_02017E88(int,int,int);
extern void func_021B6558(int,int,int);
extern void func_021E12F8(void *);
extern void func_021D8C84(void *);
void func_021DBD3C(char *p);
int func_021DBD70(char *p,int a,int b);
int func_021DBDB4(char *p);

void func_021DBD3C(char *p)
{
    if (func_021E665C(p)) {
        if (func_021D8A24(p)) {
            func_021D8E84(p, (int)func_021DBC98);
            return;
        }
        func_021D8E84(p, (int)func_021DBC3C);
    }
}

int func_021DBD70(char *p,int a,int b) {
 if(func_021D8AA8(p)==0) {
  if(((struct Obj00001 *)p)->fF84==b && ((struct Obj00001 *)p)->fF88==a) return 1;
 } else { if(func_021DD34C(p,a,b)!=-1) return 1; }
 return 0;
}

int func_021DBDB4(char *p) {int e=(int)func_021D8DD0((void *)(((struct Obj03774 *)p)->f828),((struct Obj03774 *)p)->fF98,((struct Obj03774 *)p)->fF94,p);if(func_021DBD70(p,((struct Obj03774 *)p)->fF98,((struct Obj03774 *)p)->fF94)) {func_020061E4(0x626);if(func_021D8AA8(p)==0){func_021D8E84(p,(int)func_021DB9B4);return 1;}func_021D8E84(p,(int)func_021DF708);return 1;}if(e && func_02017E88(e,0xa9,0)) {func_020061E4(0x54b);func_021B6558(((struct Obj03774 *)p)->f9C0,8,0);func_021E12F8(p);func_021D8E84(p,(int)func_021DA640);return 1;}func_021D8C84(p);((struct Obj03774 *)p)->fF98=-1;((struct Obj03774 *)p)->fF94=-1;return 0;}
