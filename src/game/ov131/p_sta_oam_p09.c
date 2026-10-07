/*
 * file:     p_sta_oam_p09.c
 * unit:     yes
 * function: func_021D6324, func_021D657C, func_021D65BC, func_021D65D8, func_021D6608
 * address:  0x021D6324
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
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   func_0203630C 0x0203630C arm
 *   func_0201A920 0x0201A920 thumb
 *   func_0201A954 0x0201A954 thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020173E8 0x020173E8 thumb
 *   func_02017550 0x02017550 thumb
 *   func_02005728 0x02005728 thumb
 *   func_02017600 0x02017600 thumb
 *   func_02017E64 0x02017E64 thumb
 *   func_020124F4 0x020124F4 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_021D4240 0x021D4240 thumb ov131
 *   d_021DC80C 0x021DC80C data a1
 *   d_021DC138 0x021DC138 data a2
 *   d_021DC144 0x021DC144 data a2
 *   func_021D4418 0x021D4418 thumb ov131
 *   func_02012704 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021D44C8  0x021D44C8  thumb
 *   d_021DC818 0x021DC818 data a1
 */
#include "../../matched/include/Obj00830.h"
#include "../../matched/include/Obj14064.h"
#include "../../matched/include/Obj01255.h"
#include "../../matched/include/Obj23132.h"

struct Obj0203159C;
struct Party;
struct PartyMon;
struct Sav;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u16 v[5];} Moves;

typedef signed int     s32;

typedef unsigned long long u64;

extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203630C(void);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_020173F0(u16,u16,u32,u32,u32);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern u32 func_020173E8(void);
extern void func_02017550(struct Sav *p);
extern u32 func_02005728(u32 range);
extern void func_02017600(void *obj,u16 species,u16 level,u64 id);
extern void func_02017E64(void *p, u32 id, u32 v);
extern void *func_020124F4(u16);
extern void func_020355D8(u8 v);
extern int func_021D4240(char *);
extern int func_021D4418(char *p);
extern void func_02012704(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern int func_021D44C8(char *p);
int func_021D6324(u32 heap,int *st,u8 *obj,char *d);
int func_021D657C(struct S020315D4 *handle, int unused, int mode, char *p);
int func_021D65BC(int a, int b, int c, int d);
void func_021D65D8(u16 *a);
void func_021D6608(void *a,void *b);
extern const char d_021DC80C[];
extern const Moves d_021DC138,d_021DC144;
extern const char d_021DC818[];

static inline void SetA(void *p, Moves m) { func_02017E40(p,0x8e,(u32)(&m)); }

static inline void SetB(void *p, Moves m) { func_02017E64(p,0x8e,(u32)(&m)); }

int func_021D6324(u32 heap,int *st,u8 *obj,char *d) {
    switch(*st) {
    case 0: {
        u8 *c=obj;
        u8 *o;
        u8 i;
                func_0203064C(1,0x42,0x50000);
        o=func_0203159C((void *)heap,0x264,0x42);
        func_02082BCC(o,0,0x264);
        ((struct Obj14064 *)o)->f0=0x42;
        i=0;
        if(c==0) {
            c=func_02030734(1,0x28,0,d_021DC80C,0x4d);
            if((func_0203630C()&0x400)==0) {
                void *party;
                void *pt;
                party=func_0201A920(1);
                func_0201A954(party,6);
                for(i=0;i<5;i++) {
                    pt=func_020173F0(i+3,10,-1,0,1);
                    SetA(pt,d_021DC138);
                    func_02017E40(pt,0x9a,0);
                    func_0201A98C(party,pt);
                    func_020307B0(pt);
                }
                c[0xf]=0;
                ((struct Obj00830 *)c)->f0=party;
                c[0xc]=1;
                c[0xe]=5;
            } else {
                int n;
                u8 *base;
                u32 off;
                n=func_020173E8();
                ((struct Obj00830 *)c)->f0=func_02030734(1,n*0x1e,1,d_021DC80C,0x81);
                c[0xc]=2;
                c[0xe]=0x1e;
                c[0xf]=0xff;
                for(i=0;i<c[0xe];i++) {
                    n=func_020173E8();
                    base=*(u8 * *)&((struct Obj00830 *)c)->f0;
                    off=i*n;
                    func_02017550((struct Sav *)(base+off));
                    if(func_02005728(3)!=0) {
                        func_02017600(base+off,i+1,0x32,(u64)-1);
                        SetB(base+off,d_021DC144);
                        func_02017E64(base+off,0x9a,0);
                        if(c[0xf]==0xff) c[0xf]=i;
                    }
                }
            }
            i=0;
            c[0xd]=0;
            c[0x10]=0;
            ((struct Obj00830 *)c)->f20=1;
            ((struct Obj00830 *)c)->f18=1;
            ((struct Obj00830 *)c)->f8=func_020124F4(1);
            if(func_0203630C()&0x400) {
                c[0xd]=2;
                ((struct Obj00830 *)c)->f20=i;
                ((struct Obj00830 *)c)->f14=10;
            }
            if(func_0203630C()&0x100) {
                c[0xd]=1;
                ((struct Obj00830 *)c)->f20=0;
            }
            func_020355D8(1);
        }
        *(u8 * *)&((struct Obj14064 *)o)->f8=c;
        *st=1;
        break;
    }
    case 1:
        if(func_021D4240(d)==1) return 1;
        break;
    }
    return 0;
}

int func_021D657C(struct S020315D4 *handle, int unused, int mode, char *p)
{
    if (!func_021D4418(p)) return 0;
    if (!mode) {
        func_02012704(*(u8 * *)&((struct Obj23132 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8);
        func_020307B0(*(void **)*(char * *)&((struct Obj01255 *)p)->f8);
        func_020307B0(((struct Obj01255 *)p)->f8);
    }
    func_020315D4(handle);
    func_020306F0(0x42);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021D65BC(int a, int b, int c, int d)
{
    int r = func_021D44C8((char *)d);

    if (r == 1)
        return 1;
    if (r == 2)
        return 1;
    return 0;
}

void func_021D65D8(u16 *a) {
 u32 *p=func_02030734(*a,0x9c,1,d_021DC818,0x10d);
 p[0]=0;
 p[1]=0;
 p[27]=0;
 p[3]=1;
 p[2]=0;
 p[23]=0;
}

void func_021D6608(void *a,void *b) {
 func_020307B0(b);
}
