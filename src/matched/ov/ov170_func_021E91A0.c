/*
 * function: func_021E91A0
 * address: 0x021E91A0
 * packet: pkt_ov170_021E91A0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EBCB4 0x021EBCB4 thumb ov170
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_02007E50 0x02007E50 thumb
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021EBB34 0x021EBB34 thumb ov170
 *   func_021DD2B4 0x021DD2B4 thumb ov170
 *   func_021DD718 0x021DD718 thumb ov170
 *   func_021DD8A8 0x021DD8A8 thumb ov170
 *   func_021EC48C 0x021EC48C thumb ov170
 *   func_021DEFF8 0x021DEFF8 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBB58 0x021EBB58 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23943.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021EBB34(char *p, int a, int b);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD718(unsigned char *p, void *mon);
extern void func_021DD8A8(unsigned char *p, unsigned idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFF8(char *p, unsigned b);
extern void func_020061E4(unsigned se);
extern void func_021EBB58(char *p, int b);
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021ED55C(char **p, int flag);
extern int func_021E8F50(unsigned char *p, int v);
extern void func_021DEFEC(unsigned char *,int);
extern void func_021ED6E4(unsigned char *,int);
extern void func_021EBA5C(char *,int);
extern void func_021DD14C(unsigned char *);
extern void func_021EF670(char *);
extern void func_021ED108(char *,int);
extern void func_021EBFA8(char *,int,int);
extern void func_021EBCB4(unsigned char *,int,int);
#define WORK(p) (*(char **)((p) + 0x2C))
int func_021E91A0(unsigned char *p)
{
    void *mon;
    if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
    else { func_020260F4(*(void **)(WORK(p)+0x70),1); func_021ED55C((char **)p,0); }
    if(func_02007E50(((struct Obj23943 *)(*(char * *)&((struct Obj00000 *)p)->f0))->fC,*(unsigned short *)(WORK(p)+0xa16c),1,0x4c)==1) {
        mon=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
        func_021DD2B4((int)p,p[0x16],p[0x14],6,0);
        if(func_021DD718(p,mon)==1) {
            func_021DD8A8(p,p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK(p)+p[0x16]+0x3dd2));
        }
        func_021DEFEC(p,p[0x16]); func_021ED6E4(p,0);
        func_021EBA5C(WORK(p),0x18); func_021DD14C(p); func_021EF670(WORK(p));
        func_021ED108(WORK(p),1); func_021EBFA8(WORK(p),0xa,2);
        return 0x3b;
    }
    func_020061E4(0x557); func_021EBCB4(p,6,0x18);
    ((struct Obj00000 *)p)->f28=0xe;
    return func_021E8F50(p,6);
}
