/*
 * file:     br_util_p12.c
 * unit:     yes
 * function: func_021FE794, func_021FE7B0, func_021FE7B4, func_021FE7F4, func_021FE7F8, func_021FE840, func_021FE8E8, func_021FE90C, func_021FE970, func_021FE9D4, func_021FEB1C, func_021FEC14, func_021FED08, func_021FED50, func_021FEDC4, func_021FEE00, func_021FEE24, func_021FEE4C, func_021FEE74, func_021FEE9C, func_021FEEC0
 * address:  0x021FE794
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020216D4 0x020216D4 thumb
 *   func_02022004 0x02022004 thumb
 *   func_02021F08 0x02021F08 thumb
 *   func_02021D50 0x02021D50 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02021660 0x02021660 thumb
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0204E6E0 0x0204E6E0 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FEEF4 0x021FEEF4 thumb ov186
 *   d_02200D78 0x02200D78 data a1
 *   d_02200B74 0x02200B74 data a4
 *   func_021FF028 0x021FF028 thumb ov186
 *   func_021FF004 0x021FF004 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_020307B0 0x020307B0 arm
 *   func_021FF01C 0x021FF01C thumb ov186
 *   func_021FF038 0x021FF038 thumb ov186
 *   func_021FF074 0x021FF074 thumb ov186
 *   func_021FF02C 0x021FF02C thumb ov186
 */
#include "../../matched/include/Obj05506.h"
#include "../../matched/include/Obj24849.h"
#include "../../matched/include/Obj05507.h"
#include "../../matched/include/Obj24850.h"
#include "../../matched/include/Obj01285.h"
#include "../../matched/include/Obj01426.h"

struct PalAnmSlot;
struct Obj02021F08;
struct S02021D50;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02022004(unsigned, unsigned, unsigned short, unsigned, unsigned);
extern void func_02021F08(struct Obj02021F08 *o, int v);
extern void func_02021D50(struct S02021D50 *p);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02021660(struct PalAnmSlot *,void *,u32,u32,u32,u32,u16,u16);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern int func_0204E6E0(void);
extern int func_0209C0A4(int,int);
extern u32 _u32_div_f(u32,u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_021FBE54(char *, unsigned, unsigned);
extern void func_021FEEF4(char *, int, char *, const char *, unsigned);
extern int func_021FF028(u32 *p);
extern void func_021FF004(char *);
extern void func_021FC0C8(char *,u32);
extern void func_020307B0(void *);
extern void func_021FF01C(char *);
extern void func_021FF038(char *,u32);
extern void func_021FF074(char *);
extern void func_021FF02C(u8 *p, u32 v);
void func_021FE794(char *p,u32 index,u32 a,u32 b,u32 c);
int func_021FE7B0(int *p);
void func_021FE7B4(char *p);
void func_021FE7F4(char *p,u16 value);
void func_021FE7F8(char *p, int mask);
void func_021FE840(int unused, int mask, int value);
void func_021FE8E8(char *p,void *arc,u32 file,u32 idx,u32 off,u32 count,u16 tag);
int func_021FE90C(u32 *p, u32 *state);
int func_021FE970(u32 *p, u32 *state);
int func_021FE9D4(char *p,int *state);
int func_021FEB1C(char *p,int *state);
int func_021FEC14(char *p,int *state);
void *func_021FED08(unsigned index);
char *func_021FED50(int a, int unused, char *resources, unsigned heap);
void func_021FEDC4(char *p,char *ctx);
void func_021FEE00(char *p);
void func_021FEE24(char *p);
void func_021FEE4C(char *p);
void func_021FEE74(char *p);
void func_021FEE9C(char *p);
void func_021FEEC0(char *p,int mode,u32 value);
extern const char d_02200D78[];
extern const char d_02200B74[];

void func_021FE794(char *p,u32 index,u32 a,u32 b,u32 c) { ((struct Obj05506 *)p)->f4=a; ((struct Obj05506 *)p)->f18=c; ((struct Obj05506 *)p)->f8=b; ((struct Obj05506 *)p)->f1C=func_021FED08(index); ((struct Obj05506 *)p)->f0=0; ((struct Obj05506 *)p)->fC=0; }

/*
 * Unlabelled ov186 leaf hidden in a word run: loads the word its argument
 * points at.  Matched to supply the `matched` witness for the two pending
 * ov184 callers (func_021F85DC, func_021F8624).
 */
int func_021FE7B0(int *p)
{
    return *p;
}

/*
 * lever: plain literals 512 and 448; mwcc derives 448 from the held 512 itself. Twin shape: matched ov197 0220C980 call to func_020216D4.
 */
void func_021FE7B4(char *p)
{
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 0, 0, 512);
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 2, 0, 448);
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 1, 0, 512);
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 3, 0, 448);
}

void func_021FE7F4(char *p,u16 value) { ((struct Obj24849 *)p)->f24=value; }

void func_021FE7F8(char *p, int mask)
{
    if (mask & 1)
        func_02022004(*(unsigned *)&((struct Obj05507 *)p)->f20, 0, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    if (mask & 2)
        func_02022004(*(unsigned *)&((struct Obj05507 *)p)->f20, 1, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    func_02021F08(((struct Obj05507 *)p)->f20, 1);
    func_02021D50(((struct Obj05507 *)p)->f20);
}

void func_021FE840(int unused, int mask, int value)
{
    if (mask & 1) {
        func_0207D63C(0x04000050, 7, 31, value, 16 - value);
        if (value == 0) {
            func_020434DC(1, 0);
            func_020434DC(2, 0);
            func_020434DC(4, 0);
        } else {
            func_020434DC(1, 1);
            func_020434DC(2, 1);
            func_020434DC(4, 1);
        }
    }
    if (mask & 2) {
        func_0207D63C(0x04001050, 3, 7, value, 16 - value);
        if (value == 0) {
            func_02043598(1, 0);
            func_02043598(2, 0);
        } else {
            func_02043598(1, 1);
            func_02043598(2, 1);
        }
    }
}

void func_021FE8E8(char *p,void *arc,u32 file,u32 idx,u32 off,u32 count,u16 tag) { func_02021660(*(struct PalAnmSlot * *)&((struct Obj24850 *)p)->f20,arc,file,tag,idx,count,off,0); }

/*
 * Three-state fade task.  start/end are assigned only for p[2] == 0 or 1:
 * the original passes callee-saved r5 and entry r2 unset on any other
 * value, exactly what C locals left unassigned on that path give
 * (docs/idioms/switch-arms-tail-merge.md).  The earlier DIFF note
 * initialised them to 16/0 and could not lose the extra moves.
 */
int func_021FE90C(u32 *p, u32 *state)
{
    u32 mask;
    s32 start, end;
    switch (*state) {
    case 0:
        mask = 0;
        if (p[1] & 1) mask |= 1;
        if (p[1] & 2) mask |= 2;
        if (p[2] == 0) {
            start = 16;
            end = 0;
        } else if (p[2] == 1) {
            start = 0;
            end = 16;
        }
        func_0204E720(mask, start, end, p[6]);
        *state = 1;
        break;
    case 1:
        if (func_0204E804() == 0) *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}

/*
 * Twin of func_021FE90C with mask bits 4/8.  start/end are assigned only
 * for p[2] == 0 or 1; the original forwards entry r1/r2 unset on any
 * other value (docs/idioms/switch-arms-tail-merge.md).  98 bytes; the
 * last two bytes of the 100-byte extent are alignment padding (00 00).
 */
int func_021FE970(u32 *p, u32 *state)
{
    u32 mask;
    s32 start, end;
    switch (*state) {
    case 0:
        mask = 0;
        if (p[1] & 1) mask |= 4;
        if (p[1] & 2) mask |= 8;
        if (p[2] == 0) {
            start = 16;
            end = 0;
        } else if (p[2] == 1) {
            start = 0;
            end = 16;
        }
        func_0204E720(mask, start, end, p[6]);
        *state = 1;
        break;
    case 1:
        if (func_0204E804() == 0) *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}

/*
 * volatile: 021FEA84 and 021FEACC write the engine-A/B blend coefficients.
 * abi: E6E0's r0 return is consumed.
 */
int func_021FE9D4(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int a,b,duration;
        if(((struct Obj01285 *)p)->f8==0){a=0;b=16;}
        else if(((struct Obj01285 *)p)->f8==1){a=16;b=0;}
        if(((struct Obj01285 *)p)->f4&1)func_0207D63C(0x04000050,7,31,a,b);
        if(((struct Obj01285 *)p)->f4&2)func_0207D63C(0x04001050,3,7,a,b);
        ((struct Obj01285 *)p)->f10=0;
        duration=((struct Obj01285 *)p)->f18;
        if(duration==0)duration=func_0209C0A4(16,func_0204E6E0());
        ((struct Obj01285 *)p)->f14=duration;
        *state=1;
        break;
    }
    case 1: {
        int a,b;
        if(((struct Obj01285 *)p)->f8==0){b=_u32_div_f(((struct Obj01285 *)p)->f10<<4,((struct Obj01285 *)p)->f14);a=16-b;}
        else if(((struct Obj01285 *)p)->f8==1){a=_u32_div_f(((struct Obj01285 *)p)->f10<<4,((struct Obj01285 *)p)->f14);b=16-a;}
        if(((struct Obj01285 *)p)->f4&1) {
            *(volatile u16 *)0x04000052=b|(a<<8);
            if(b==0){func_020434DC(1,0);func_020434DC(2,0);func_020434DC(4,0);}
            else{func_020434DC(1,1);func_020434DC(2,1);func_020434DC(4,1);}
        }
        if(((struct Obj01285 *)p)->f4&2) {
            *(volatile u16 *)0x04001052=b|(a<<8);
            if(b==0){func_02043598(1,0);func_02043598(2,0);}
            else{func_02043598(1,1);func_02043598(2,1);}
        }
        if((((struct Obj01285 *)p)->f10)++ >= ((struct Obj01285 *)p)->f14)*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}

/*
 * note: 2026-10-05 the older draft used 0x3fff for both calls of the first pair and 0xbfff for both of the second. The listing pairs them as (2,0x3fff) (0,0xbfff) (3,0x3fff) (1,0xbfff). Variable value is read uninitialised when field 8 is not 0 or 1 (original behaviour, kept).
 */
int func_021FEB1C(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int duration;
        *(u32 *)(p+0x10)=0;
        duration=*(int *)(p+0x18);
        if(duration==0)duration=func_0209C0A4(16,func_0204E6E0());
        *(u32 *)(p+0x14)=duration;
        func_02021F08(*(struct Obj02021F08 **)(p+0x20),1);
        *state=1;
        break;
    }
    case 1: {
        int value;
        if(*(int *)(p+8)==0)value=(u8)(16-_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14)));
        else if(*(int *)(p+8)==1)value=(u8)_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14));
        if(*(int *)(p+4)==15) {
            func_02022004(*(u32 *)(p+0x20),1,0x3000,value,0xffff);
        } else {
            if(*(int *)(p+4)&1) {
                func_02022004(*(u32 *)(p+0x20),2,0x3fff,value,*(u16 *)(p+0x24));
                func_02022004(*(u32 *)(p+0x20),0,0xbfff,value,*(u16 *)(p+0x24));
            }
            if(*(int *)(p+4)&2) {
                func_02022004(*(u32 *)(p+0x20),3,0x3fff,value,*(u16 *)(p+0x24));
                func_02022004(*(u32 *)(p+0x20),1,0xbfff,value,*(u16 *)(p+0x24));
            }
        }
        func_02021D50(*(struct S02021D50 **)(p+0x20));
        if((*(u32 *)(p+0x10))++ >= *(u32 *)(p+0x14))*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}

/*
 * lever: A duration local updated by the zero arm shares the final store, removing the extra branch (248 to 244 B).
 * volatile: 021FECBC writes the engine-B blend register at 04001052.
 * abi: 0204E6E0 returns the word loaded into r0 despite its asm void declaration.
 */
int func_021FEC14(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int first,second,a,b,duration;
        if(((struct Obj01426 *)p)->f8==0){first=16;second=0;}
        else if(((struct Obj01426 *)p)->f8==1){first=0;second=16;}
        if(((struct Obj01426 *)p)->f8==0){a=0;b=16;}
        else if(((struct Obj01426 *)p)->f8==1){a=16;b=0;}
        func_0204E720(4,first,second,((struct Obj01426 *)p)->f18);
        func_0207D63C(0x04001050,3,7,a,b);
        ((struct Obj01426 *)p)->f10=0;
        duration=((struct Obj01426 *)p)->f18;
        if(duration==0)duration=func_0209C0A4(16,func_0204E6E0());
        ((struct Obj01426 *)p)->f14=duration;
        *state=1;
        break;
    }
    case 1: {
        int a,b;
        int done=1;
        if(((struct Obj01426 *)p)->f8==0){a=_u32_div_f(((struct Obj01426 *)p)->f10<<4,((struct Obj01426 *)p)->f14);b=16-a;}
        else if(((struct Obj01426 *)p)->f8==1){b=_u32_div_f(((struct Obj01426 *)p)->f10<<4,((struct Obj01426 *)p)->f14);a=16-b;}
        *(volatile u16 *)0x04001052=a|(b<<8);
        if(a==0)func_02043598(3,0);else func_02043598(3,1);
        done&=((((struct Obj01426 *)p)->f10)++ >= ((struct Obj01426 *)p)->f14);
        if(done & !func_0204E804())*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}

void *func_021FED08(unsigned index)
{
    switch (index) {
    case 0: return (void *)func_021FE90C;
    case 1: return (void *)func_021FE970;
    case 2: return (void *)func_021FE9D4;
    case 3: return (void *)func_021FEB1C;
    case 4: return (void *)func_021FEC14;
    }
    return 0;
}

char *func_021FED50(int a, int unused, char *resources, unsigned heap)
{
    char *p = func_02030734(heap, 0x390, 0, d_02200D78, 0x132);
    int i;
    func_02082BCC(p, 0, 0x390);
    func_021FBE54(resources, 4, heap);
    func_021FBE54(resources, 5, heap);
    for (i = 0; i < 12; i++)
        func_021FEEF4(p + i * 0x4C, a, resources, d_02200B74 + i * 24, heap);
    return p;
}

void func_021FEDC4(char *p,char *ctx) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF004((char *)((u32)p+i*0x4c)); func_021FC0C8(ctx,4); func_021FC0C8(ctx,5); func_020307B0(p); }

void func_021FEE00(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF01C((char *)((u32)p+i*0x4c)); }

/*
 * extent: two zero alignment bytes at 0x021FEE4A follow; no follower.
 */
void func_021FEE24(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF038((char *)((u32)p+i*0x4c),1); }

/*
 * extent: two zero alignment bytes at 0x021FEE72 follow; no follower.
 */
void func_021FEE4C(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF038((char *)((u32)p+i*0x4c),2); }

/*
 * extent: two zero alignment bytes at 0x021FEE9A follow; no follower.
 */
void func_021FEE74(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF038((char *)((u32)p+i*0x4c),3); }

void func_021FEE9C(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF074((char *)((u32)p+i*0x4c)); }

void func_021FEEC0(char *p,int mode,u32 value) { int i; for(i=0;i<12;i++) if(mode==*(int *)((u32)d_02200B74+i*24+16)) func_021FF02C((u8 *)((u32)p+i*0x4c),value); }
