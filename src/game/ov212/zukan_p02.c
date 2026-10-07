/*
 * file:     zukan_p02.c
 * unit:     yes
 * function: func_021C8FF4, func_021C9024, func_021C9098, func_021C9130, func_021C9184, func_021C91C4, func_021C9244
 * address:  0x021C8FF4
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02031348 0x02031348 arm
 *   func_021C9348 0x021C9348 thumb ov212
 *   func_021C8F90 0x021C8F90 thumb ov212
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021BE794 0x021BE794 data ov209 a4
 *   ov209_id 0x000000D1 data a1
 *   func_021C8F7C 0x021C8F7C thumb ov212
 *   func_021C9288 0x021C9288 thumb ov212
 *   func_020307B0 0x020307B0 arm
 *   d_021C0714 0x021C0714 data ov210 a4
 *   ov210_id 0x000000D2 data a1
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA8C 0x0200CA8C thumb
 *   d_021C8108 0x021C8108 data ov208 a4
 *   ov208_id 0x000000D0 data a1
 *   func_0200CA78 0x0200CA78 thumb
 */
#include "../../matched/include/Obj08417.h"
#include "../../matched/include/Obj25654.h"
#include "../../matched/include/Obj25655.h"
#include "../../matched/include/Obj25656.h"
#include "../../matched/include/Obj02259.h"
#include "../../matched/include/Obj04626.h"
#include "../../matched/include/Obj25658.h"
#include "../../matched/include/Obj25659.h"
#include "../../matched/include/Obj01587.h"
#include "../../matched/include/Obj25660.h"
#include "../../matched/include/Obj25661.h"
#include "../../matched/include/Obj25662.h"
#include "../../matched/include/Obj25663.h"
#include "../../matched/include/Obj25664.h"
#include "../../matched/include/Obj25665.h"
#include "../../matched/include/Obj25666.h"
#include "../../matched/include/Obj06702.h"
#include "../../matched/include/Obj06703.h"
#include "../../matched/include/Obj25668.h"
#include "../../matched/include/Obj04627.h"
#include "../../matched/include/Obj10926.h"
#include "../../matched/include/Obj25669.h"
#include "../../matched/include/Obj04628.h"
#include "../../matched/include/Obj04629.h"

struct Obj020314F4;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_020307B0(void *p);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02031348(struct Obj020314F4 *,unsigned,unsigned,unsigned);
extern int func_021C9348(struct Blk37 *);
extern int func_021C8F90(char *,int);
extern void func_021C8F7C(u8 *p);
extern u16 func_021C9288(struct Blk37 *,u16 **,unsigned);
extern void *func_0200CA1C(void *);
extern u16 func_0200CA8C(struct Blk37 *);
extern void func_0200CA78(struct Blk37 *p, u32 v);
int func_021C8FF4(u8 *p);
void func_021C9024(char *p);
int func_021C9098(char *p);
void func_021C9130(char *p);
int func_021C9184(char *p);
void func_021C91C4(char *p);
int func_021C9244(char *p);
extern const char d_021C99A0[];
extern const unsigned d_021BE794[];
extern unsigned char ov209_id[];
extern const unsigned d_021C0714[];
extern unsigned char ov210_id[];
extern const unsigned d_021C8108[];
extern unsigned char ov208_id[];

int func_021C8FF4(u8 *p) {
    int result;
    switch (((struct Obj25654 *)(*(u8 * *)&((struct Obj08417 *)p)->f28))->f8) {
    case 0:
        ((struct Obj25655 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 0;
        result = 9;
        break;
    case 1:
        ((struct Obj25656 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 1;
        result = 9;
        break;
    case 2: result = 3; break;
    }
    func_020307B0(((struct Obj08417 *)p)->f28);
    return result;
}

/*
 * prototype: 02031348 legacy void(void) forwards r0-r3 to 020314F4,
 * whose matched body reads all four; this caller sets all four.
 */
void func_021C9024(char *p)
{
    char *q=func_02030734(105,20,0,d_021C99A0,359);
    ((struct Obj02259 *)p)->f28=q;
    ((struct Obj04626 *)q)->f0=**(unsigned * *)&((struct Obj02259 *)p)->f0;
    ((struct Obj04626 *)q)->f4=((struct Obj25658 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4;
    ((struct Obj04626 *)q)->f8=((struct Obj02259 *)p)->f12;
    if(((struct Obj02259 *)p)->f12==0&&func_021C9348(*(struct Blk37 * *)&((struct Obj25659 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4)==0){
        *(u16 * *)&((struct Obj04626 *)q)->fC=*(u16 * *)&((struct Obj02259 *)p)->fC+1;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10-1;
    }else{
        ((struct Obj04626 *)q)->fC=((struct Obj02259 *)p)->fC;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10;
    }
    func_02031348(*(struct Obj020314F4 * *)&((struct Obj02259 *)p)->f4,(unsigned)ov209_id,(unsigned)d_021BE794,*(unsigned *)&((struct Obj02259 *)p)->f28);
    func_021C8F90(p,4);
}

/*
 * lever: spell the empty-result arm first in the nested if/else;
 * shared failure exit remains after the switch.
 */
int func_021C9098(char *p)
{
    int result;
    switch(((struct Obj25660 *)(*(char * *)&((struct Obj01587 *)p)->f28))->f10){
    case 0:
        if(((struct Obj01587 *)p)->f12==0){
            ((struct Obj25661 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
        }else{
            func_021C8F7C((u8 *)p);
            ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25662 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
            ((struct Obj01587 *)p)->f12=0;result=3;
        }
        goto done;
    case 1:((struct Obj25663 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=1;result=9;goto done;
    case 2:
        func_021C8F7C((u8 *)p);
        ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25664 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        result=3;goto done;
    case 3:result=5;((struct Obj01587 *)p)->f24=1;goto done;
    case 4:
        if(((struct Obj01587 *)p)->f12==1){
            func_021C8F7C((u8 *)p);
            ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25665 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        }
        result=7;goto done;
    default:break;
    }
    ((struct Obj25666 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
done:
    func_020307B0(((struct Obj01587 *)p)->f28);
    return result;
}

/*
 * prototype: 02031348 legacy void(void) forwards untouched r0-r3 to
 * 020314F4; its matched body reads all four and caller sets all four.
 */
void func_021C9130(char *p)
{
    char *q;
    q=func_02030734(105,24,0,d_021C99A0,455);
    ((struct Obj06702 *)p)->f28=q;
    ((struct Obj06703 *)q)->f0=**(unsigned * *)&((struct Obj06702 *)p)->f0;
    ((struct Obj06703 *)q)->f4=((struct Obj25668 *)(*(char * *)&((struct Obj06702 *)p)->f0))->f4;
    ((struct Obj06703 *)q)->f8=p+20;
    ((struct Obj06703 *)q)->f10=0;
    ((struct Obj06703 *)q)->f14=0;
    func_02031348(*(struct Obj020314F4 * *)&((struct Obj06702 *)p)->f4,(unsigned)ov210_id,(unsigned)d_021C0714,*(unsigned *)&((struct Obj06702 *)p)->f28);
    func_021C8F90(p,8);
}

/*
 * trailing: two zero alignment bytes at 021C91C2.
 * lever: assign the result in each arm after its stores, keeping r4 reusable.
 */
int func_021C9184(char *p)
{
    char *q=*(char * *)&((struct Obj04627 *)p)->f28;
    int result;
    switch(((struct Obj10926 *)q)->fC){
    case 0:
        func_021C8F7C((u8 *)p);
        ((struct Obj04627 *)p)->fC=((struct Obj10926 *)q)->f10;
        ((struct Obj04627 *)p)->f10=((struct Obj10926 *)q)->f14;
        ((struct Obj04627 *)p)->f12=1;
        result=3;
        break;
    case 1:
        ((struct Obj04627 *)p)->f12=0;
        result=3;
        break;
    case 2:
    default:
        ((struct Obj25669 *)(*(char * *)&((struct Obj04627 *)p)->f0))->fE=1;
        result=9;
        break;
    }
    func_020307B0(((struct Obj04627 *)p)->f28);
    return result;
}

/*
 * prototype: 02031348 forwards all four original inputs to 020314F4;
 * the matched forwarding target reads each, overriding legacy void(void).
 */
void func_021C91C4(char *p)
{
    char *q;
    u16 selected,i;
    selected=func_0200CA8C(func_0200CA1C(*(void **)*(char * *)&((struct Obj04628 *)p)->f0));
    q=func_02030734(105,20,0,d_021C99A0,530);
    ((struct Obj04629 *)q)->f0=**(unsigned * *)&((struct Obj04628 *)p)->f0;
    ((struct Obj04629 *)q)->f4=((struct Obj04628 *)p)->f24;
    ((struct Obj04629 *)q)->f8=((struct Obj04628 *)p)->fC;
    ((struct Obj04629 *)q)->fC=((struct Obj04628 *)p)->f10;
    ((struct Obj04629 *)q)->fE=0;
    for(i=0;i<((struct Obj04629 *)q)->fC;i++){
        if((*(u16 **)(q+8))[i]==selected){((struct Obj04629 *)q)->fE=i;break;}
    }
    func_02031348(*(struct Obj020314F4 * *)&((struct Obj04628 *)p)->f4,(unsigned)ov208_id,(unsigned)d_021C8108,(unsigned)q);
    ((struct Obj04628 *)p)->f28=q;
    func_021C8F90(p,6);
}

int func_021C9244(char *p)
{
    struct Blk37 *save;
    char *q;
    int result;
    save = func_0200CA1C(*(void **)*(char **)p);
    q = *(char **)(p + 0x28);
    func_0200CA78(save, (*(u16 **)(q + 8))[*(u16 *)(q + 14)]);
    switch (*(int *)(q + 0x10)) {
    case 0:
        *(u16 *)(*(char **)p + 14) = 1;
        result = 9;
        break;
    case 1:
        *(u16 *)(*(char **)p + 14) = 0;
        result = 3;
        break;
    }
    func_020307B0(*(void **)(p + 0x28));
    return result;
}
