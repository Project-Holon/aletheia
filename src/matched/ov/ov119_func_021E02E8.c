/*
 * function: func_021E02E8
 * address: 0x021E02E8
 * packet: pkt_ov119_021E02E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008FEC 0x02008FEC thumb
 *   func_02008FFC 0x02008FFC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008C20 0x02008C20 thumb
 *   func_021E017C 0x021E017C thumb ov119
 *   func_021E01E0 0x021E01E0 thumb ov119
 *   func_021E0240 0x021E0240 thumb ov119
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_020086F8 0x020086F8 thumb
 *   func_02007AEC 0x02007AEC thumb
 *   func_02007AF4 0x02007AF4 thumb
 *   func_02012F98 0x02012F98 thumb
 *   func_02007B5C 0x02007B5C thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj00589.h"
#include "../include/Obj22755.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Big;
struct PerapVoice;
struct PlayTime;
struct PlayTimeStamp;
struct Rec534;
struct Sub02007AC8Entry;
struct Sub02008F80Obj;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02012F2C(int *p);
extern int func_02012FCC(int p0);
extern struct Sub02007AC8Entry *func_02007AF4(void **save, u32 box);
extern void *func_02012F98(void *);
extern u32 func_02008FFC(void);
extern u32 func_02008C20(void);
extern u32 func_02007AEC(void);
extern void func_02082D44(const void *,void *,u32);
extern u32 func_020307B0(void *p);
extern void func_021E017C(void *,void *);
extern void func_021E01E0(void *,void *);
extern void func_021E0240(void **h, void *dst);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_020086F8(struct PlayTime *p, const struct PlayTimeStamp *in);
extern void func_02007B5C(struct PerapVoice *p);
extern void func_02082BCC(void *,int,u32);
void func_021E02E8(char *p)
{
    void *dest,*src;
    u32 n;
    dest=((struct Obj00589 *)p)->f60C;
    if(dest) {
        src=((struct Obj00589 *)p)->f82C;
        func_02012EBC(src);
        src=func_02008FEC(src);
        n=func_02008FFC();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    dest=((struct Obj00589 *)p)->f610;
    if(dest) {
        src=func_02012F2C(((struct Obj00589 *)p)->f82C);
        n=func_02008C20();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    if(((struct Obj00589 *)p)->f614) func_021E017C(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f614);
    if(((struct Obj00589 *)p)->f618) func_021E01E0(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f618);
    if(((struct Obj00589 *)p)->f61C) func_021E0240(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f61C);
    if(((struct Obj00589 *)p)->f620) {
        func_0201AC2C(((struct Obj00589 *)p)->f620,((struct Obj00589 *)p)->f838);
        func_020086F8((void *)func_02012FCC((int)(((struct Obj00589 *)p)->f82C)),(const struct PlayTimeStamp *)(p+0x628));
        func_020307B0(((struct Obj00589 *)p)->f620);
        *(int *)&((struct Obj00589 *)p)->f620=0;
    }
    if(((struct Obj00589 *)p)->f624) {
        n=func_02007AEC();
        src=func_02007AF4(((struct Obj00589 *)p)->f828,((struct Obj22755 *)(*(char * *)&((struct Obj00589 *)p)->f8))->f28);
        func_02082D44(((struct Obj00589 *)p)->f624,src,n);
        func_020307B0(((struct Obj00589 *)p)->f624);
    }
    if(((struct Obj00589 *)p)->f62C) func_02007B5C(func_02012F98(((struct Obj00589 *)p)->f82C));
    func_02082BCC(p+0x60c,0,0x24);
}
