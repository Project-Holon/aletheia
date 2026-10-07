/*
 * file:     p_sta_oam_p04.c
 * unit:     yes
 * function: func_021D5BAC, func_021D5C4C, func_021D5C98, func_021D5DC4, func_021D6064
 * address:  0x021D5BAC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D62F4 0x021D62F4 thumb ov131
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D60D4 0x021D60D4 thumb ov131
 *   func_021D6CDC 0x021D6CDC thumb ov131
 *   func_021D91EC 0x021D91EC thumb ov131
 *   func_021D697C 0x021D697C thumb ov131
 *   func_021D911C 0x021D911C thumb ov131
 *   func_021D7E84 0x021D7E84 thumb ov131
 *   func_021D9D44 0x021D9D44 thumb ov131
 *   func_021D909C 0x021D909C thumb ov131
 *   func_021DA84C 0x021DA84C thumb ov131
 *   func_021D7C38 0x021D7C38 thumb ov131
 *   func_021D9C3C 0x021D9C3C thumb ov131
 *   func_021D8F50 0x021D8F50 thumb ov131
 *   func_021DA6A4 0x021DA6A4 thumb ov131
 *   func_021D6D04 0x021D6D04 thumb ov131
 *   func_021D6A38 0x021D6A38 thumb ov131
 *   func_021D7EAC 0x021D7EAC thumb ov131
 *   func_021D9D94 0x021D9D94 thumb ov131
 *   func_021D90C0 0x021D90C0 thumb ov131
 *   func_021DA8BC 0x021DA8BC thumb ov131
 *   func_021D7CAC 0x021D7CAC thumb ov131
 *   func_021D9CD0 0x021D9CD0 thumb ov131
 *   func_021D8FAC 0x021D8FAC thumb ov131
 *   func_021DA7A4 0x021DA7A4 thumb ov131
 *   func_021D62E4 0x021D62E4 thumb ov131
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_02006BB4 0x02006BB4 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02006CAC 0x02006CAC thumb
 *   func_02006984 0x02006984 thumb
 *   func_020173E8 0x020173E8 thumb
 */
#include "../../matched/include/Obj03284.h"
#include "../../matched/include/Obj00112.h"
#include "../../matched/include/Obj00039.h"
#include "../../matched/include/Obj00035.h"

struct Obj;
struct PrintSys;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021D62F4(char *p, void *q);
extern int func_021D60A4(char *p);
extern void func_021D60D4(unsigned char *p, int a);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_021D6CDC(unsigned char *a, unsigned char *b);
extern void func_021D91EC(void *,void *);
extern void func_021D697C(u8 *,int *);
extern void func_021D911C(u8 *a, u8 *p);
extern void func_021D7E84(void *p, void **q);
extern void func_021D9D44(void *,u8 *);
extern void func_021D909C(u8 *a, u8 *p);
extern void func_021DA84C(u8 *,u8 *);
extern void func_021D7C38(void *,u8 *);
extern void func_021D9C3C(void *,u8 *);
extern void func_021D8F50(void *,u8 *);
extern void func_021DA6A4(u8 *a, u8 *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021D6D04(void *,u8 *);
extern void func_021D6A38(u8 *p, u8 *q);
extern void func_021D7EAC(u8 *,void *);
extern void func_021D9D94(u8 *,u8 *);
extern void func_021D90C0(u8 *,u8 *);
extern void func_021DA8BC(u8 *,u8 *);
extern void func_021D7CAC(u8 *,u8 *);
extern void func_021D9CD0(u8 *,u8 *);
extern void func_021D8FAC(u8 *,u8 *);
extern void func_021DA7A4(u8 *,u8 *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021D62E4(char *);
extern void func_02006BB4(u32);
extern void func_02006CAC(void **);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern void *func_020185F0(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_020173E8(void);
int func_021D5BAC(unsigned char *p,int direction,unsigned short *out);
void func_021D5C4C(unsigned char *p);
void func_021D5C98(u8 *p);
void func_021D5DC4(u8 *p);
void *func_021D6064(unsigned char *p);

int func_021D5BAC(unsigned char *p,int direction,unsigned short *out) {
 int result=0;
 int old;
 int done;
 void *m;
 done=0;
 old=((struct Obj03284 *)p)->f18;
 do {
 if(direction==1 && ((struct Obj03284 *)p)->f18>=(*(unsigned char **)(p+8))[14]-1) {done=1;continue;}
 if(direction==0 && ((struct Obj03284 *)p)->f18==0) {done=1;continue;}
 if(direction==1) ++((struct Obj03284 *)p)->f18; else --((struct Obj03284 *)p)->f18;
 m=func_021D6064(p);
 if(func_02017E88(m,169,0)!=0) {
 if(func_02017E88(m,76,0)!=1 || ((struct Obj03284 *)p)->f58==0) {
 if(((struct Obj03284 *)p)->f58!=2 || func_021D62F4((char *)p,m)!=0) {done=1;result=1;}
 }
 }
 } while(done==0);
 if(out) *out=((struct Obj03284 *)p)->f18;
 ((struct Obj03284 *)p)->f18=old;
 return result;
}

void func_021D5C4C(unsigned char *p) {
 void *q=(void *)func_021D60A4((char *)p);
 void *m=func_021D6064(p);
 int one=1;
 func_021D60D4(p,1);
 *(int *)&((struct Obj00112 *)p)->f38=func_02017E1C(q,76,0);
 ((struct Obj00112 *)p)->f3C=func_02017E1C(q,9,0);
 ((struct Obj00112 *)p)->f40=func_021D62F4((char *)p,m);
 func_021D60D4(p,0);
 ((struct Obj00112 *)p)->f10=one;
}

/*
 * volatile: hardware halfwords reread at 021D5D96, 021D5DA0, 021D5DA6
 *   and written at 021D5D9C, 021D5DA4, 021D5DAA.
 * arithmetic: full-word selectors have cases 0..3 and an empty default;
 *   no selector bound is assumed. Halfword OR with 64 fits promoted int.
 * interfaces: own matched 60D4,697C,7C38,9C3C,8F50,9D44,A84C;
 *   matched callers 4418,4240,7BF0 supply remaining two-argument calls.
 *   Full original 6CDC and 909C confirm both incoming payloads are passed.
 */
void func_021D5C98(u8 *p)
{
    func_021D60D4(p,1);
    if (p[0x1a]!=((struct Obj00039 *)p)->f18) {
        if (p[0x1a]!=255) {
            func_021D6CDC(p,((struct Obj00039 *)p)->f88);
            func_021D91EC(p,((struct Obj00039 *)p)->f94);
        }
        func_021D697C(p,*(int * *)&((struct Obj00039 *)p)->f88);
        func_021D911C(p,((struct Obj00039 *)p)->f94);
    }
    switch (((struct Obj00039 *)p)->f5C) {
    case 0: func_021D7E84(p,(void **)(*(u8 * *)&((struct Obj00039 *)p)->f8C)); break;
    case 1: func_021D9D44(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: func_021D909C(p,((struct Obj00039 *)p)->f94); break;
    case 3: func_021DA84C(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    }
    switch (*(u32 *)&((struct Obj00039 *)p)->f58) {
    case 0: func_021D7C38(p,*(u8 * *)&((struct Obj00039 *)p)->f8C); break;
    case 1: func_021D9C3C(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: func_021D8F50(p,*(u8 * *)&((struct Obj00039 *)p)->f94); break;
    case 3: func_021DA6A4(p,((struct Obj00039 *)p)->f90); break;
    }
    if (((struct Obj00039 *)p)->f5C!=*(u32 *)&((struct Obj00039 *)p)->f58) {
        ((struct Obj00039 *)p)->f25C=1;
        p[0x260]=0;
        *(volatile u16 *)0x0400000c |= 64;
        *(volatile u16 *)0x0400100a |= 64;
        *(volatile u16 *)0x0400100c |= 64;
    }
    func_021D60D4(p,0);
    ((struct Obj00039 *)p)->fC=1;
}

/*
 * volatile: byte hardware writes 0400004C at 021D5DE6/021D5E1C
 *   and 0400104C at 021D5DF2/021D5E28; no ordinary object is volatile.
 * arithmetic: byte inc/dec is modulo 256; reloaded byte <=255 shifted
 *   by five fits int. Signed selector <3 admits negatives: address uses
 *   unsigned full-word multiply/add, preserving original wrap.
 * output: matched unit_02006CAC unconditionally stores the one-word out;
 *   the pointer payload passed as the eighth 02006984 argument is u32.
 * interfaces: callee own matched files; 7EAC keeps second caller payload
 *   visibly set at 021D5E9C despite its own body's unused parameter.
 */
void func_021D5DC4(u8 *p)
{
    void *q;
    u32 a,b;
    void *out;
    if (((struct Obj00035 *)p)->f25C==1) {
        ++p[0x260];
        *(volatile u8 *)0x0400004c=p[0x260] | (p[0x260]<<5);
        *(volatile u8 *)0x0400104c=p[0x260] | (p[0x260]<<5);
        if (p[0x260]>=3) ((struct Obj00035 *)p)->f25C=2;
    }
    if (((struct Obj00035 *)p)->f25C==3) {
        --p[0x260];
        *(volatile u8 *)0x0400004c=p[0x260] | (p[0x260]<<5);
        *(volatile u8 *)0x0400104c=p[0x260] | (p[0x260]<<5);
        if (p[0x260]==0) {
            *(u32 *)&((struct Obj00035 *)p)->fC=0;
            ((struct Obj00035 *)p)->f25C=0;
            return;
        }
    }
    if (func_0201C6B4(((struct Obj00035 *)p)->f84)==1 &&
        (((struct Obj00035 *)p)->f25C==2 || ((struct Obj00035 *)p)->f25C==0)) {
        if (p[0x1a]!=((struct Obj00035 *)p)->f18) {
            if (p[0x1a]!=255) func_021D6D04(p,*(u8 * *)&((struct Obj00035 *)p)->f88);
            func_021D6A38(p,((struct Obj00035 *)p)->f88);
            p[0x1a]=((struct Obj00035 *)p)->f18;
        }
        switch (((struct Obj00035 *)p)->f5C) {
        case 0: func_021D7EAC(p,((struct Obj00035 *)p)->f8C); break;
        case 1: func_021D9D94(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        case 2: func_021D90C0(p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
        case 3: func_021DA8BC(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        }
        switch (((struct Obj00035 *)p)->f58) {
        case 0: func_021D7CAC(p,*(u8 * *)&((struct Obj00035 *)p)->f8C); break;
        case 1: func_021D9CD0(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        case 2: func_021D8FAC(p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
        case 3: func_021DA7A4(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        }
        if (((struct Obj00035 *)p)->f38==0 && (*(u8 **)(p+8))[13]!=2) {
            func_0204B3DC(((struct Obj00035 *)p)->f17C,1);
            if (((struct Obj00035 *)p)->f40==0) func_0204B3DC(((struct Obj00035 *)p)->f180,0);
            else func_0204B3DC(((struct Obj00035 *)p)->f180,1);
        } else {
            func_0204B3DC(((struct Obj00035 *)p)->f17C,0);
            func_0204B3DC(((struct Obj00035 *)p)->f180,0);
        }
        if (*(u32 *)&((struct Obj00035 *)p)->f48==0) {
            if (func_021D5BAC(p,0,0)==1) func_0204B878(((struct Obj00035 *)p)->f188,3);
            else func_0204B878(((struct Obj00035 *)p)->f188,17);
        }
        if (*(u32 *)&((struct Obj00035 *)p)->f4C==0) {
            if (func_021D5BAC(p,1,0)==1) func_0204B878(((struct Obj00035 *)p)->f18C,2);
            else func_0204B878(((struct Obj00035 *)p)->f18C,16);
        }
        if (*(int *)&((struct Obj00035 *)p)->f58<3 && func_021D62E4((char *)p)==1) {
            if (*(u32 *)((u32)p + (u32)*(int *)&((struct Obj00035 *)p)->f58*4 + 0x60)==1)
                func_0204B878(((struct Obj00035 *)p)->f184,7);
            else func_0204B878(((struct Obj00035 *)p)->f184,6);
        }
        if (((struct Obj00035 *)p)->f10==1) {
            ((struct Obj00035 *)p)->f10=0;
            func_02006BB4(0);
            if (((struct Obj00035 *)p)->f38==0) {
                q=(void *)func_021D60A4((char *)p);
                a=func_02017E1C(q,5,0);
                b=func_02017E1C(q,111,0);
                func_02006CAC(&out);
                func_02006984(a,b,64,0,0,0,0,(u32)&out);
            }
        }
        if (((struct Obj00035 *)p)->f25C==2) {
            ((struct Obj00035 *)p)->f25C=3;
            ((struct Obj00035 *)p)->f5C=((struct Obj00035 *)p)->f58;
            return;
        }
        *(u32 *)&((struct Obj00035 *)p)->fC=0;
        ((struct Obj00035 *)p)->f5C=((struct Obj00035 *)p)->f58;
    }
}

void *func_021D6064(unsigned char *p) {
 switch((*(unsigned char **)(p+8))[12]) {
 case 0: return func_020185F0(**(void ** *)&((struct Obj00112 *)p)->f8);
 case 1: return func_020185F0(func_0201AB28(**(void ** *)&((struct Obj00112 *)p)->f8,((struct Obj00112 *)p)->f18));
 case 2: return (unsigned char *)**(void ** *)&((struct Obj00112 *)p)->f8+func_020173E8()* ((struct Obj00112 *)p)->f18;
 default: return 0;
 }
}
