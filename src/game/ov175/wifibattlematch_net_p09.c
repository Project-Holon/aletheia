/*
 * file:     wifibattlematch_net_p09.c
 * unit:     yes
 * function: func_021D6550, func_021D65C8, func_021D65DC, func_021D65F0, func_021D6698, func_021D6724
 * address:  0x021D6550
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
 *   func_021E888C 0x021E888C thumb ov177
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb
 *   func_021E5F24   0x021E5F24  thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008468 0x02008468 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0200E6E8 0x0200E6E8 thumb
 *   func_0200E6FC 0x0200E6FC thumb
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_02009CC0 0x02009CC0 thumb
 */
#include "../../matched/include/Obj00171.h"
#include "../../matched/include/Obj24230.h"

struct Big;
struct BigObj;
struct Rec0200E6FC;
typedef unsigned int u32_021D6550;

typedef unsigned short u16;

typedef unsigned long u32_021D65C8;

typedef unsigned long u32_021D65DC;

typedef unsigned int u32_021D65F0;

typedef unsigned int u32_021D6698;

typedef unsigned char  u8;

typedef unsigned int u32_021D6724;

extern void func_02082BCC(void *,int,u32_021D6550);
extern u32_021D6550 func_021E888C(void *,u32_021D6550);
extern void func_021E89D0(u32_021D65C8 p);
extern int func_021E8A00(u32_021D65DC p);
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern int func_02008468(void);
extern void func_02082D44(const void *,void *,int);
extern void *func_0200E6E8(u32_021D6698 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32_021D6698 func_0200DFD8(u32_021D6698,u32_021D6698,u32_021D6698);
extern u32_021D6698 func_0201283C(const struct BigObj *p);
extern int func_02009CC0(void *a0);
void func_021D6550(u32_021D6550 *p,int mode);
void func_021D65C8(char *obj);
int func_021D65DC(char *obj);
void func_021D65F0(u32_021D65F0 *p,u32_021D65F0 *q);
void func_021D6698(u32_021D6698 *p,u32_021D6698 *q);
void func_021D6724(u32_021D6724 *p, u32_021D6724 *q);

void func_021D6550(u32_021D6550 *p,int mode)
{
    struct { u32_021D6550 x0,x1,x2,x3,x4,x5,x6,x7; u16 a,b,c,d; int enabled; u16 kind,pad; } desc;
    if (p[10]==0) {
        func_02082BCC(&desc,0,48);
        desc.x0=p[4]; desc.x1=p[2]; desc.x2=p[3];
        desc.a=0; desc.b=15; desc.c=13; desc.d=1;
        switch(mode) {
        case 0:
            desc.x3=31; desc.x4=32; desc.x7=2;
            desc.enabled=1; desc.kind=1;
            break;
        case 1:
            desc.x3=27; desc.x4=28; desc.x5=29;
            desc.x7=3; desc.enabled=1; desc.kind=2;
            break;
        }
        p[11]=mode;
        p[10]=func_021E888C(&desc,87);
    }
}


void func_021D65C8(char *obj)
{
    u32_021D65C8 p = ((struct Obj00171 *)obj)->f28;

    if (p != 0) {
        func_021E89D0(p);
        ((struct Obj00171 *)obj)->f28 = 0;
    }
}


/*
 * Query brother of func_021D65C8: returns the +0x28 block's handler
 *     result through 0x021E8A00, or -1 when the field is empty.
 */
int func_021D65DC(char *obj)
{
    u32_021D65DC p = ((struct Obj24230 *)obj)->f28;

    if (p != 0)
        return func_021E8A00(p);
    return -1;
}

void func_021D65F0(u32_021D65F0 *p,u32_021D65F0 *q)
{
    u32_021D65F0 *ctx,*s;
    func_02082BCC(p,0,16);
    ctx=(u32_021D65F0 *)q[16]; s=(u32_021D65F0 *)ctx[14];
    p[1]=s[8]; p[2]=0;
    s=(u32_021D65F0 *)ctx[14];
    p[3]=s[13]+(s[14]+(s[11]+(s[12]+(s[17]+(s[18]+(s[9]+(s[10]+(s[16]+s[15]))))))));
    switch(((u32_021D65F0 *)ctx[2])[1]) {
    case 0: p[0]=((u32_021D65F0 *)ctx[14])[3]; break;
    case 1: p[0]=((u32_021D65F0 *)ctx[14])[0]; break;
    case 2: p[0]=((u32_021D65F0 *)ctx[14])[4]; break;
    case 3: p[0]=((u32_021D65F0 *)ctx[14])[1]; break;
    case 4: p[0]=((u32_021D65F0 *)ctx[14])[2]; break;
    }
}

void func_021D6698(u32_021D6698 *p,u32_021D6698 *q)
{
    u32_021D6698 save=((u32_021D6698 *)((u32_021D6698 *)q[16])[2])[0];
    u32_021D6698 profile=(u32_021D6698)func_02012EBC((struct Big *)save);
    u32_021D6698 blob;
    u32_021D6698 *ctx;
    p[17]=100;
    blob=(u32_021D6698)func_02012944((void *)save);
    func_02082D44((void *)blob,p,func_02008468());
    func_0200E6FC(func_0200E6E8(profile),0,(struct Rec0200E6FC *)((char *)(p+14)));
    ctx=(u32_021D6698 *)q[16];
    if(ctx[0]==0) {
        p[10]=func_0200DFD8(ctx[4],((u32_021D6698 *)ctx[2])[1]+5,1);
        ctx=(u32_021D6698 *)q[16];
        p[11]=func_0200DFD8(ctx[4],((u32_021D6698 *)ctx[2])[1]+5,2);
    } else {
        p[10]=func_0200DFD8(ctx[4],((u32_021D6698 *)ctx[2])[1],1);
        ctx=(u32_021D6698 *)q[16];
        p[11]=func_0200DFD8(ctx[4],((u32_021D6698 *)ctx[2])[1],2);
    }
    p[18]=func_02009CC0((void *)func_0201283C((const struct BigObj *)save));
}

/*
 * extent: two-byte alignment padding at 021D6786.
 */
void func_021D6724(u32_021D6724 *p, u32_021D6724 *q)
{
    u32_021D6724 *r = (u32_021D6724 *)q[16];
    if (r[0] == 0) {
        p[10] = func_0200DFD8(r[4], ((u32_021D6724 *)r[2])[1] + 5, 1);
        r = (u32_021D6724 *)q[16];
        p[11] = func_0200DFD8(r[4], ((u32_021D6724 *)r[2])[1] + 5, 2);
        r = (u32_021D6724 *)q[16];
        p[13] = func_0200DFD8(r[4], ((u32_021D6724 *)r[2])[1] + 5, 0);
    } else {
        p[10] = func_0200DFD8(r[4], ((u32_021D6724 *)r[2])[1], 1);
        r = (u32_021D6724 *)q[16];
        p[11] = func_0200DFD8(r[4], ((u32_021D6724 *)r[2])[1], 2);
    }
}
