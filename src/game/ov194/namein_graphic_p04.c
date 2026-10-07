/*
 * file:     namein_graphic_p04.c
 * unit:     yes
 * function: func_021F2190, func_021F21BC, func_021F21FC, func_021F22AC, func_021F22E8, func_021F2328, func_021F233C, func_021F235C, func_021F2394
 * address:  0x021F2190
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GX_GetBankForLCDC 0x02045A98 arm
 *   func_02045A98 0x02045A98 arm
 *   func_021F23FC 0x021F23FC thumb
 *   func_021F4ED8 0x021F4ED8 thumb ov194
 *   func_021F4E18 0x021F4E18 thumb ov194
 *   func_021F4DDC 0x021F4DDC thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F4F7C 0x021F4F7C thumb ov194
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02045994 0x02045994 arm
 */
#include "../../matched/include/Obj02909.h"
#include "../../matched/include/Obj01574.h"
#include "../../matched/include/Obj08342.h"
#include "../../matched/include/Obj10807.h"
#include "../../matched/include/Obj05509.h"
#include "../../matched/include/Obj24901.h"
#include "../../matched/include/Obj03897.h"

struct PrintSys;
struct Descriptor;
struct Strbuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 removedCount, addedCount; u16 removed[4],added[4]; } Changes;

extern unsigned int GX_GetBankForLCDC(void);
extern unsigned short func_02045A98(void);
extern int func_021F23FC(u8 *p, int direction);
extern u16 func_021F4ED8(const char *p, const u16 *b);
extern int func_021F4E18(int,int,u16 *,int,u8 *);
extern void func_021F4DDC(const char *p, int i, u16 *dst, u32 n, u8 *count);
extern int func_021F2150(u8 *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
int func_021F2190(char *p, unsigned short v);
int func_021F21BC(unsigned char *p, unsigned short a, unsigned short b);
int func_021F21FC(u8 *a,int b);
int func_021F22AC(char *p);
int func_021F22E8(unsigned char *p);
void func_021F2328(char *self, struct Strbuf *dst);
void func_021F233C(char *p);
void func_021F235C(char *p);
void func_021F2394(u8 *p);


int func_021F2190(char *p, unsigned short v)
{
    if (((struct Obj02909 *)p)->f1E < ((struct Obj02909 *)p)->f22)
    {
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = v;
        ((struct Obj02909 *)p)->f1E += 1;
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = GX_GetBankForLCDC();
        ((struct Obj02909 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}


int func_021F21BC(unsigned char *p, unsigned short a, unsigned short b)
{
    if (((struct Obj01574 *)p)->f1E < ((struct Obj01574 *)p)->f22 &&
        ((struct Obj01574 *)p)->f20 < 3) {
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) = a;
        ((struct Obj01574 *)p)->f20 += 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) =
            func_02045A98();
        func_021F23FC(p, b);
        ((struct Obj01574 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}

/*
 * lever: shared failure label retains one exit; byte-offset cast +10 inside the loop
 * materialises the added-array base after the entry guard, unlike change.added.
 */
int func_021F21FC(u8 *a,int b)
{
    void *p;
    u16 v;
    Changes change;
    int i;
    u16 *tab;
    switch(b) {
    case 0: p=((struct Obj08342 *)a)->f84; break;
    case 1: p=((struct Obj08342 *)a)->f88; break;
    default:return 0;
    }
    if (((struct Obj08342 *)a)->f1E==0) goto fail;
    v=func_021F4ED8(p,(u16 *)(a+(((struct Obj08342 *)a)->f1E-1)*2));
    if(v==65535) goto fail;
    if(!func_021F4E18((int)p,v,change.added,4,&change.addedCount)) goto fail;
    func_021F4DDC(p,v,change.removed,4,&change.removedCount);
    for(i=0;i<change.removedCount;i++) func_021F2150(a);
    for(i=0;i<change.addedCount;i++) {
        tab=(u16 *)((u8 *)&change+10);
        func_021F2190((char *)a,tab[i]);
    }
    return 1;
fail:
    return 0;
}

int func_021F22AC(char *p) { u16 v;if(((struct Obj10807 *)p)->f1E!=0 && func_021F4F7C(*(char * *)&((struct Obj10807 *)p)->f90,(u16 *)((u32)p+(((struct Obj10807 *)p)->f1E-1)*2),&v)) { func_021F2150((u8 *)p);func_021F2190(p,v);return 1; }return 0; }


int func_021F22E8(unsigned char *p)
{
    int c = p[0x30];
    int r4 = ((struct Obj05509 *)p)->f38;

    if (c != 0) {
        if (func_0201C6C4((struct PrintSys *)r4, (void *)((int)func_02045770((struct Descriptor *)((struct Obj05509 *)p)->f2C))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj05509 *)p)->f2C);
            p[0x30] = 0;
        }
    }
    return p[0x30] == 0;
}


void func_021F2328(char *self, struct Strbuf *dst)
{
    func_02045994(dst, (const u16 *)self,
                 ((struct Obj24901 *)self)->f1E + 1);
}


void func_021F233C(char *p)
{
    if (((struct Obj03897 *)p)->f20 != 0)
    {
        unsigned int v;
        ((struct Obj03897 *)p)->f20 = 0;
        v = GX_GetBankForLCDC();
        *(unsigned short *)(p + 0x16 + (((struct Obj03897 *)p)->f20 << 1)) = v;
        ((struct Obj03897 *)p)->f28 = 1;
    }
}

void func_021F235C(char *p) { int i; for(i=0;i<((struct Obj02909 *)p)->f20;i++)func_021F2190(p,*(u16 *)((u32)p+(u32)i*2+22));((struct Obj02909 *)p)->f20=0;*(u16 *)((u32)p+((struct Obj02909 *)p)->f20*2+22)=func_02045A98();((struct Obj02909 *)p)->f28=1; }

void func_021F2394(u8 *p) {if(((struct Obj03897 *)p)->f1E) {((struct Obj03897 *)p)->f1E=0;*(u16 *)(p+((struct Obj03897 *)p)->f1E*2)=func_02045A98();((struct Obj03897 *)p)->f28=1;}func_021F233C((char *)p);}
