/*
 * file:     egg_demo_view_p02.c
 * unit:     yes
 * function: func_021F6600, func_021F661C, func_021F6624, func_021F6630, func_021F669C, func_021F66AC, func_021F66C8, func_021F6718, func_021F6720, func_021F67B0, func_021F67E0, func_021F6A24, func_021F6A3C
 * address:  0x021F6600
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021F6328 0x021F6328 thumb ov215
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021F7160 0x021F7160 data a4
 *   d_021F7154 0x021F7154 data a4
 *   d_021F716C 0x021F716C data a4
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   func_02030734 0x02030734 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   d_021F73F4 0x021F73F4 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021F6AB4 0x021F6AB4 thumb ov215
 *   func_021F6AB8 0x021F6AB8 thumb ov215
 *   func_021F6AEC 0x021F6AEC thumb ov215
 *   func_021F6DB4 0x021F6DB4 thumb ov215
 *   func_021F6EF8 0x021F6EF8 thumb ov215
 *   func_021F6F64 0x021F6F64 thumb ov215
 *   d_021F7340 0x021F7340 data a4
 *   d_021F7314 0x021F7314 data a4
 *   func_021F7028 0x021F7028 thumb ov215
 *   func_021F6F18 0x021F6F18 thumb ov215
 *   func_021F6E4C 0x021F6E4C thumb ov215
 *   func_021F6CAC 0x021F6CAC thumb ov215
 *   func_021F6AE0 0x021F6AE0 thumb ov215
 *   sub_02030EAC 0x02030EAC arm
 *   func_021F6CCC 0x021F6CCC thumb ov215
 *   func_021F6EEC 0x021F6EEC thumb ov215
 *   func_020061E4 0x020061E4 thumb
 *   func_02006238 0x02006238 thumb
 *   func_02006224 0x02006224 thumb
 *   func_02006148 0x02006148 thumb
 *   func_0200616C 0x0200616C thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_021F6D58 0x021F6D58 thumb ov215
 *   func_021F70F8 0x021F70F8 thumb ov215
 *   func_021F6D7C 0x021F6D7C thumb ov215
 *   func_021F7100 0x021F7100 thumb ov215
 *   func_021F6CC0 0x021F6CC0 thumb ov215
 *   func_021F6D90 0x021F6D90 thumb ov215
 *   func_021F7110 0x021F7110 thumb ov215
 *   func_02006984 0x02006984 thumb
 *   func_02006650 0x02006650 thumb
 *   func_021F6D1C 0x021F6D1C thumb ov215
 *   func_02014C08 0x02014C08 thumb
 *   func_021F6E5C 0x021F6E5C thumb ov215
 *   func_021F7048 0x021F7048 thumb ov215
 *   func_02014D2C 0x02014D2C thumb
 *   func_021F6F24 0x021F6F24 thumb ov215
 *   func_021F6EE4 0x021F6EE4 thumb ov215
 */
#include "../../matched/include/Obj25751.h"
#include "../../matched/include/Obj25752.h"
#include "../../matched/include/Obj25755.h"
#include "../../matched/include/Obj00317.h"
#include "../../matched/include/Obj04636.h"
#include "../../matched/include/Obj01083.h"
#include "../../matched/include/Obj06708.h"
#include "../../matched/include/Obj25756.h"
#include "../../matched/include/Obj25757.h"

#define W(o) (*(u32 *)(p+(o)))
struct Bank;
struct Light;
struct Node;
struct McssSys;
typedef unsigned int   u32;

typedef signed short s16;

typedef unsigned short u16;

struct Vec3 { unsigned x,y,z; };

typedef struct { int tag,x,y,z,sx,sy,sz,matrix[9],tail; } Record;

extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,unsigned);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021F6328(void);
extern void func_02046440(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,const struct Vec3 *,const struct Vec3 *,const struct Vec3 *,u16);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(int);
extern void func_02047964(void *);
extern void func_02048AD0(struct Light *);
extern void func_020479D8(void);
extern void func_02047970(void);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_0207ADC4(void *);
extern u32 func_020307B0(void *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_020056A0(void (*)(void),void *,unsigned);
extern void func_021F6AB4(void);
extern void func_021F6AB8(char *p);
extern void func_021F6AEC(char *p);
extern char *func_021F6DB4(unsigned,unsigned,const void *);
extern void func_021F6EF8(char *p);
extern void func_021F6F64(char *p);
extern void func_021F7028(char *);
extern void func_021F6F18(char *);
extern void func_021F6E4C(char *);
extern void func_021F6CAC(char *);
extern void func_021F6AE0(char *);
extern void sub_02030EAC(struct Node *);
extern void func_021F6CCC(char *,unsigned,int);
extern void func_021F6EEC(char *);
extern void func_020061E4(u32);
extern int func_02006238(void);
extern int func_02006224(u32);
extern int func_02006148(u32);
extern void func_0200616C(void *,int);
extern void func_020061F8(int);
extern void func_021F6D58(char *);
extern void func_021F70F8(char *);
extern int func_021F6D7C(char *);
extern int func_021F7100(char *);
extern void func_021F6CC0(char *);
extern void func_021F6D90(char *);
extern void func_021F7110(char *);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern int func_02006650(void);
extern void func_021F6D1C(char *);
extern void func_02014C08(char *);
extern void func_021F6E5C(char *);
extern void func_021F7048(char *);
extern void func_02014D2C(struct McssSys *);
extern void func_021F6F24(char *);
extern void func_021F6EE4(char *);
void func_021F6600(char *p);
void func_021F661C(void *a0);
void func_021F6624(void *a0);
int func_021F662C(void *p);
void func_021F6630(void **out,u16 heap);
void func_021F669C(int *p);
void func_021F66AC(void *p);
void func_021F66C0(void *p);
Record *func_021F66C8(unsigned heap,unsigned count);
void func_021F6718(void *p);
char *func_021F6720(unsigned heap,void *mon);
void func_021F67B0(char *p);
void func_021F67E0(char *p);
void func_021F6A24(char *p);
void func_021F6A3C(char *p);
int func_021F6A44(char *p);
extern const s16 d_020A1EB8[];
extern const struct Vec3 d_021F7160,d_021F7154,d_021F716C;
extern const char d_021F73F4[];
extern const unsigned d_021F7340[],d_021F7314[];

/*
 * extent: two-byte alignment padding follows the body.
 */
void func_021F6600(char *p){func_0204B1CC(*(struct Bank * *)&((struct Obj25751 *)p)->f0);func_0204A5AC();func_02082BCC(p,0,4);}

void func_021F661C(void *a0){func_0204A600();}

/*
 * extent: includes cleared tiny follower func_021F662C; no further code included.
 */
void func_021F6624(void *a0){func_0204A648();}

int func_021F662C(void *p){return ((struct Obj25752 *)p)->f0;}

/*
 * evidence: 46440 heap extern widened; original stores full r1 at sp+4.
 */
void func_021F6630(void **out,u16 heap)
{
    func_02046440(0,2,0,1,0,heap,func_021F6328);
    *out=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,4194304,0,&d_021F7160,&d_021F7154,&d_021F716C,heap);
}


void func_021F669C(int *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}

/*
 * extent: includes cleared tiny follower func_021F66C0; no further code included.
 */
void func_021F66AC(void *p){func_02047964(p);func_02048AD0(*(struct Light * *)&((struct Obj25755 *)p)->f0);func_020479D8();}

void func_021F66C0(void *p){func_02047970();}

Record *func_021F66C8(unsigned heap,unsigned count)
{
    Record *p;
    u16 i;
    p=func_02030734(heap,68*count,1,d_021F73F4,283);
    for(i=0;i<count;i++) {
        p[i].x=0;p[i].y=0;p[i].z=0;
        p[i].sx=4096;p[i].sy=4096;p[i].sz=4096;
        func_0207ADC4(p[i].matrix);
    }
    return p;
}

void func_021F6718(void *p){func_020307B0(p);}

/*
 * evidence: sole callback 021F6AB4 resolved after owned leaf shard verification.
 */
char *func_021F6720(unsigned heap,void *mon)
{
    char *p;
    p=func_02030734(heap,96,1,d_021F73F4,433);
    ((struct Obj00317 *)p)->f0=heap;
    ((struct Obj00317 *)p)->f4=mon;
    ((struct Obj00317 *)p)->f8=func_02017E1C(mon,5,0);
    ((struct Obj00317 *)p)->fC=0;
    ((struct Obj00317 *)p)->f10=0;
    ((struct Obj00317 *)p)->f14=0;
    ((struct Obj00317 *)p)->f18=0;
    ((struct Obj00317 *)p)->f1C=0;
    ((struct Obj00317 *)p)->f24=0;
    ((struct Obj00317 *)p)->f28=0;
    ((struct Obj00317 *)p)->f2C=func_020056A0(func_021F6AB4,p,1);
    func_021F6AB8(p);
    func_021F6AEC(p);
    if(((struct Obj00317 *)p)->f8==490)
        ((struct Obj00317 *)p)->f44=func_021F6DB4(((struct Obj00317 *)p)->f0,5,d_021F7340);
    else
        ((struct Obj00317 *)p)->f44=func_021F6DB4(((struct Obj00317 *)p)->f0,3,d_021F7314);
    func_021F6EF8(p);
    func_021F6F64(p);
    return p;
}

/*
 * trailing: zero halfword at 021F67DE is alignment padding.
 */
void func_021F67B0(char *p){func_021F7028(p);func_021F6F18(p);func_021F6E4C(*(char * *)&((struct Obj04636 *)p)->f44);func_021F6CAC(p);func_021F6AE0(p);sub_02030EAC(*(struct Node * *)&((struct Obj04636 *)p)->f2C);func_020307B0(p);}

void func_021F67E0(char *p)
{
    u32 limit,a,b;
    switch(W(12)) {
    case 0:
        if(W(16)) {
            W(12)=1;W(24)=0;
            func_021F6CCC(p,1,1);
            func_021F6EEC(*(char * *)&((struct Obj01083 *)p)->f44);
        }
        break;
    case 1:
        if(((struct Obj01083 *)p)->f8==490)limit=300;else limit=380;
        W(24)++;
        if(((struct Obj01083 *)p)->f8==490) {
            switch(W(40)) {
            case 0: if(W(24)==10){func_020061E4(1955);W(40)=1;}break;
            case 1: if(!func_02006238()){func_020061E4(1960);W(40)=2;}break;
            case 2: if(!func_02006238())W(40)=3;break;
            case 3:break;
            }
        }else{
            if(W(24)==20)func_020061E4(1954);
            else if(W(24)==109)func_020061E4(1954);
            else if(W(24)==218)func_020061E4(1488);
            if(W(24)==10)func_020061E4(1968);
            else if(W(24)==15)func_020061E4(1968);
            else if(W(24)==85)func_020061E4(1968);
            else if(W(24)==90)func_020061E4(1968);
            if(W(28)&&!func_02006224(W(32))) {
                W(28)=0;
                if(W(24)>=150&&W(24)<309)W(36)=20;
                else if(W(24)>309)W(36)=0;
            }
            if(W(24)>=150&&W(24)<limit) {
                if(!W(28)) {
                    if(!W(36)) {
                        W(32)=func_02006148(1967);
                        func_0200616C((void *)1967,W(32));
                        W(28)=1;
                    }else W(36)--;
                }
            }else if(W(24)==limit&&W(28)&&func_02006224(W(32))) {
                func_020061F8(W(32));W(28)=0;
            }
        }
        if(W(24)==limit) {
            func_021F6D58(p);func_021F70F8(p);func_020061E4(1935);W(12)=2;
        }
        break;
    case 2:if(func_021F6D7C(p))W(12)=3;break;
    case 3:if(func_021F7100(p)){func_021F6CC0(p);W(20)=1;W(12)=4;}break;
    case 4:W(20)=0;break;
    case 6:
        if(++W(24)>=120){func_021F6D90(p);func_021F7110(p);W(12)=7;W(24)=0;}
        break;
    case 7:
        if(++W(24)>=65) {
            W(12)=8;
            a=func_02017E1C(((struct Obj01083 *)p)->f4,5,0);
            b=func_02017E1C(((struct Obj01083 *)p)->f4,111,0);
            func_02006984(a,b,64,0,0,0,0,0);
        }
        break;
    case 8:if(!func_02006650())W(12)=9;break;
    case 9:break;
    }
    func_021F6D1C(p);
    func_02014C08(*(char * *)&((struct Obj01083 *)p)->f30);
    func_021F6E5C(*(char * *)&((struct Obj01083 *)p)->f44);
    func_021F7048(p);
}

void func_021F6A24(char *p){func_02014D2C(*(struct McssSys * *)&((struct Obj06708 *)p)->f30);func_021F6F24(p);func_021F6EE4(*(char * *)&((struct Obj06708 *)p)->f44);}

/*
 * leaf: two unlabelled leaves blocking concrete MATCH900 ov215021F5884.
 * extent: setter, two alignment bytes, four-byte getter; twelve bytes total.
 */
void func_021F6A3C(char *p){((struct Obj25756 *)p)->f10=1;}

int func_021F6A44(char *p){return ((struct Obj25757 *)p)->f14;}
