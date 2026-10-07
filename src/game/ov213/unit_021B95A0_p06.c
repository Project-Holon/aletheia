/*
 * file:     unit_021B95A0_p06.c
 * unit:     yes
 * function: func_021BA444, func_021BA480, func_021BA4BC, func_021BA514
 * address:  0x021BA444
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_021BA30C 0x021BA30C thumb ov213
 *   func_021BA1C0 0x021BA1C0 thumb ov213
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0203D5D4 0x0203D5D4 arm
 */
#include "../../matched/include/Obj25702.h"
#include "../../matched/include/Obj25703.h"
#include "../../matched/include/Obj03939.h"
#include "../../matched/include/Obj25704.h"
#include "../../matched/include/Obj25705.h"
#include "../../matched/include/Obj25706.h"
#include "../../matched/include/Obj25707.h"
#include "../../matched/include/Obj25708.h"

struct Sub02008C20Obj;
enum Count{CountZero,CountTwo=2,CountFour=4};

typedef unsigned int   u32;

extern int func_021B9E50(unsigned);
extern void func_021BA30C(char *);
extern void func_021BA1C0(char *);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_0203D5D4(void);
void func_021BA444(char *p);
void func_021BA480(char *p);
void func_021BA4BC(void *p,int kind,int variant);
void func_021BA514(char *p);

void func_021BA444(char *p){int i;enum Count count;if(func_021B9E50(((struct Obj25702 *)p)->f49C8))count=CountTwo;else count=CountFour;p+=0x483C;for(i=0;i<count;i++)func_021BA30C(p+i*84);}

void func_021BA480(char *p){int i;enum Count count;if(func_021B9E50(((struct Obj25703 *)p)->f49C8))count=CountTwo;else count=CountFour;p+=0x485C;for(i=0;i<count;i++)func_021BA1C0(p+i*84);}

void func_021BA4BC(void *p,int kind,int variant)
{
    switch(kind) {
    case 13:
        if(variant==0) func_02008DF0(p,14);
        else if(variant==1) func_02008DF0(p,15);
        break;
    case 37:
        if(variant==0) func_02008DF0(p,38);
        else if(variant==1) func_02008DF0(p,39);
        break;
    case 17:
        if(variant==0) func_02008DF0(p,18);
        else if(variant==1) func_02008DF0(p,19);
        else if(variant==2) func_02008DF0(p,20);
        break;
    }
    func_02008DF0(p,kind);
}

void func_021BA514(char *p)
{
    if(((struct Obj25704 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54) {
        switch((int)func_0203D5D4()) {
        case 37:case 12:case 31:func_021BA4BC(((struct Obj25706 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,37,((struct Obj03939 *)p)->f49CC);break;
        case 10:func_021BA4BC(((struct Obj25707 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,17,((struct Obj03939 *)p)->f49CC);break;
        case 20:case 21:case 23:case 24:case 25:case 26:
            func_021BA4BC(((struct Obj25708 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,13,((struct Obj03939 *)p)->f49CC);break;
        }
    }
}
