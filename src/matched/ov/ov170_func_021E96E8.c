/*
 * function: func_021E96E8
 * address: 0x021E96E8
 * packet: pkt_ov170_021E96E8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED164 0x021ED164 thumb
 *   func_021EA878 0x021EA878 thumb
 *   func_021EBCB4 0x021EBCB4 thumb
 *   func_021ED094 0x021ED094 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 *   func_021ED2F4 0x021ED2F4 thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021EA75C 0x021EA75C thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF4E4 0x021EF4E4 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_021ED55C 0x021ED55C thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23949.h"
struct WinMgr;
extern void func_021EF670(char *);
extern void func_021EA75C(int p);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *,int);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EF68C(char *);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021ED588(char *p);
extern void func_021DEFEC(char *p, int b);
extern void func_021EB988(unsigned char *,const void *,unsigned);
extern void func_021EF4E4(struct WinMgr *mgr);
extern void func_021EBC58(unsigned char *,int,int,int);
extern unsigned func_0202136C(unsigned short);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(unsigned char *,unsigned);
extern void func_021EC48C(unsigned char *,int,int,int);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021ED55C(char **p, int flag);
extern void func_021ED164(char *,int,int);
extern void func_021EA878(unsigned char *,int);
extern void func_021EBCB4(unsigned char *,int,int);
extern void func_021ED094(char *,unsigned);
extern void func_021EC000(char *,int,int);
extern void func_021ED1C8(char *);
extern void func_021ED2F4(char *);
#define WORK (*(char **)(p+0x2c))
#define ITEM (*(unsigned short *)(p+0x10))
int func_021E96E8(unsigned char *p)
{
    int next;
    void *mon;
    switch(p[0x13]) {
    case 0: func_021ED164(WORK,p[0x16],0); next=0x39; break;
    case 1:
        func_021EA75C((int)p); func_021ED888(WORK,0);
        func_021ED164(WORK,p[0x16],1); func_021EE364((char **)p,8,0xa); next=0x46; break;
    }
    func_021EA878(p,*(short *)&((struct Obj00000 *)p)->f10);
    if(ITEM==0) {
        func_021DEFEC((char *)p,p[0x16]); func_021EF4E4(*(struct WinMgr **)(WORK+0x74));
        func_021EBCB4(p,0,0x18);
        if(p[0x13]==0) func_021ECB20((char *)p,0x81,1);
        else { func_021ECB20((char *)p,1,1); func_021ECB20((char *)p,0x82,1); }
        return next;
    }
    if(func_0202136C(ITEM)==0) {
        mon=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
        func_021DD2B4((int)p,p[0x16],p[0x14],6,ITEM);
        if(func_021DD718((void **)p,mon)==1) {
            func_021DD8A8(p,p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK+p[0x16]+0x3dd2));
        }
        func_02007F1C(((struct Obj23949 *)(*(char * *)&((struct Obj00000 *)p)->f0))->fC,ITEM,1,0x804c);
        *(unsigned short *)(WORK+0xa16c)=ITEM;
        func_021ED094(WORK,*(unsigned short *)(WORK+0xa16c));
        func_021EC000(WORK,0xa,1); func_021ED1C8(WORK); func_021ED2F4(WORK);
    }
    if(p[0x13]==0) { func_021ECB20((char *)p,0x81,1); func_021EF670(WORK); }
    else { func_021ECB20((char *)p,1,1); func_021ECB20((char *)p,0x82,1); func_021EF68C(WORK); }
    func_021DEFEC((char *)p,p[0x16]); func_021ED55C((char **)p,0);
    return 0x54;
}
