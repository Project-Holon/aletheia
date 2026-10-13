/*
 * unit: yes
 * function: IRC_COMPATIBLE_ResultStepCreateArgs, IRC_COMPATIBLE_ResultStepDestroyArgs
 * address: 0x021B6DAC
 * packet: pkt_ov101_021B6DAC
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: reversed flag/both declarations preserve saved-register allocation.
 * trailing: 6E84..6E8C is Thumb free veneer; odd callback at 74F4 is code-start proof.
 * prototype: 6ECC reads eight arguments, but original caller explicitly supplies ninth 58; preserve it.
 * symbols:
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * func_020120F4 0x020120F4 thumb
 * func_02012EBC 0x02012EBC thumb
 * func_0200A8A0 0x0200A8A0 thumb
 * func_02008530 0x02008530 thumb
 * func_0200A9D4 0x0200A9D4 thumb
 * func_021B658C 0x021B658C thumb ov101
 * func_0203D378 0x0203D378 arm
 * IRC_COMPATIBLE_CalcCompatibility 0x021B6ECC thumb ov101
 * IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 */
#include "../include/Obj01387.h"
#include "../include/Obj07971.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; unsigned char low:4; unsigned char high:4; u8 tail[32]; } Data;
extern char IRC_COMPATIBLE_SourceFileName[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *,int,u32);
struct Big;
struct Ctx;
struct T0200A9A4;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_0200A9D4(struct T0200A9A4 *o, u32 v);
extern void func_021B658C(void *,Data *);
extern u32 func_0203D378(void);
extern int IRC_COMPATIBLE_CalcCompatibility(u32 a, u32 b, int c, int d, char *x, char *y, int flag, u32 id, int a8);
void *IRC_COMPATIBLE_ResultStepCreateArgs(u32 heap,char *p)
{
    Data data;
    void *token;
    char *out,*name;
    int both,flag=0;
    u32 id;
    out=func_02030734(heap,16,0,IRC_COMPATIBLE_SourceFileName,0x418);
    func_02082BCC(out,0,16);
    ((struct Obj07971 *)out)->f0=**(u32 * *)&((struct Obj01387 *)p)->f10;
    ((struct Obj07971 *)out)->f4=((struct Obj01387 *)p)->f0;
    ((struct Obj07971 *)out)->f8=*(u32 *)&((struct Obj01387 *)p)->f3C;
    if(((struct Obj01387 *)p)->f2C && ((struct Obj01387 *)p)->f2E) {
        name=*(char * *)&((struct Obj01387 *)p)->f3C+12;
        func_020120F4(**(void ** *)&((struct Obj01387 *)p)->f10);
        token=func_0200A8A0(func_02012EBC(func_020120F4(**(void ** *)&((struct Obj01387 *)p)->f10)));
        if(func_0200A9D4(token,func_02008530((const struct Sub0200852CObj *)name))==0) flag=1;
        both=0;
        if(((struct Obj01387 *)p)->f30 && flag) both=1;
        func_021B658C(**(void ** *)&((struct Obj01387 *)p)->f10,&data);
        if(func_0203D378()) id=data.f00;
        else id=**(u32 * *)&((struct Obj01387 *)p)->f3C;
        ((struct Obj07971 *)out)->fC=IRC_COMPATIBLE_CalcCompatibility(((struct Obj01387 *)p)->f2C,((struct Obj01387 *)p)->f2E,((struct Obj01387 *)p)->f2D,((struct Obj01387 *)p)->f2F,(char *)(&data),((struct Obj01387 *)p)->f3C,both,id,58);
    }
    return out;
}
void IRC_COMPATIBLE_ResultStepDestroyArgs(void *p)
{
    func_020307B0(p);
}
