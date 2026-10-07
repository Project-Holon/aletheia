/*
 * file:     wifibattlematch_net_p06.c
 * unit:     yes
 * function: func_021D61F0, func_021D62A4, func_021D639C
 * address:  0x021D61F0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02082D44 0x02082D44 arm
 *   func_021DCB58 0x021DCB58 thumb ov175
 *   func_021DCC28 0x021DCC28 thumb ov175
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_02012944 0x02012944 thumb
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_02008554 0x02008554 thumb
 *   func_021E5C20 0x021E5C20 thumb ov177
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb
 *   func_021E5F24   0x021E5F24  thumb
 */
#include "../../matched/include/Obj03317.h"
#include "../../matched/include/Obj24227.h"
#include "../../matched/include/Obj10680.h"

#define CTX ((u32_021D62A4 *)p[16])
#define REC ((u32_021D62A4 *)CTX[2])
struct Sub0200852CObj;
typedef unsigned int u32_021D61F0;

typedef unsigned char  u8;

typedef unsigned int u32_021D62A4;

typedef unsigned short u16;

typedef struct { u32_021D62A4 kind; u16 count,pad; u32_021D62A4 name,total; u16 a,b; } Desc;

typedef unsigned long u32_021D639C;

extern void func_02082BCC(void *,int,int);
extern void func_02082D44(const void *,void *,int);
extern void func_021DCB58(char *p, void *q, int mode);
extern int func_021DCC28(char *p, u8 *out);
extern void func_021E8AA8(int a);
extern u8 *func_02012944(void *p);
extern int func_021E5548(int *);
extern u32_021D62A4 func_0200DFD8(u32_021D62A4,u32_021D62A4,u32_021D62A4);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32_021D62A4 func_021E5C20(Desc *,int,u32_021D62A4,int,u32_021D62A4,u32_021D62A4,u32_021D62A4,u32_021D62A4,u32_021D62A4,int);
extern void func_021E5D40(u32_021D639C p);
void func_021D61F0(u32_021D61F0 sys,int *state,char *p);
void func_021D62A4(u32_021D62A4 *p, u32_021D62A4 mode);
void func_021D639C(char *obj);

void func_021D61F0(u32_021D61F0 sys,int *state,char *p)
{
    char *base=*(char * *)&((struct Obj24227 *)(*(char * *)&((struct Obj03317 *)p)->f40))->f14;
    int result;
    switch(*state) {
    case 0:
        ((struct Obj03317 *)p)->fE0=0;
        func_02082BCC(p+0x44,0,0x9c);
        (*state)++;
        break;
    case 1:
        func_021DCB58(((struct Obj03317 *)p)->f30,base+0xd4,1);
        (*state)++;
        break;
    case 2:
        result=func_021DCC28(((struct Obj03317 *)p)->f30,(u8 *)(p+0x44));
        if(result==1) *state=3;
        else if(result==2) { ((struct Obj03317 *)p)->f3C=2; *state=4; }
        else if(result==3) { ((struct Obj03317 *)p)->f3C=3; *state=4; }
        break;
    case 3:
        if(((struct Obj03317 *)p)->f44==0) {
            func_02082D44(p+0x60,base+0x54,0x80);
            ((struct Obj03317 *)p)->f3C=0; *state=4;
        } else { ((struct Obj03317 *)p)->f3C=1; *state=4; }
        break;
    case 4: func_021E8AA8(sys); break;
    }
}

void func_021D62A4(u32_021D62A4 *p, u32_021D62A4 mode)
{
    u32_021D62A4 sys;
    int base,flag;
    Desc desc;
    if(p[6]==0) {
        sys=(u32_021D62A4)func_02012944((void *)REC[0]);
        base=func_021E5548((int *)p[0]);
        func_02082BCC(&desc,0,20);
        if(mode==0) {
            desc.kind=REC[1]; flag=1;
            desc.count=func_0200DFD8(CTX[4],REC[1]+5,0);
            desc.a=func_0200DFD8(CTX[4],REC[1]+5,1);
            desc.b=func_0200DFD8(CTX[4],REC[1]+5,2);
            desc.total=desc.a+desc.b;
            if(desc.count==0 && desc.total==0) desc.count=1500;
        } else if(mode==1) {
            desc.kind=REC[1]; flag=0; desc.count=0;
            desc.a=func_0200DFD8(CTX[4],REC[1],1);
            desc.b=func_0200DFD8(CTX[4],REC[1],2);
            desc.total=desc.a+desc.b;
        }
        desc.name=func_02008554((const struct Sub0200852CObj *)sys);
        p[6]=func_021E5C20(&desc,flag,sys,base,p[1],p[2],p[3],p[4],p[5],87);
    }
}


/*
 * Release path for the ov175 object's 0x18 block pointer: free it
 *     through 0x021E5D40 and clear the field.  Null-safe, so a second call is a
 *     no-op.
 */
void func_021D639C(char *obj)
{
    u32_021D639C p = ((struct Obj10680 *)obj)->f18;

    if (p != 0) {
        func_021E5D40(p);
        ((struct Obj10680 *)obj)->f18 = 0;
    }
}
