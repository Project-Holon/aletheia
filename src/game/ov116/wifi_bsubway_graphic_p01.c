/*
 * file:     wifi_bsubway_graphic_p01.c
 * unit:     yes
 * function: func_021D72D0, func_021D730C, func_021D7324, func_021D737C, func_021D73D0, func_021D73D4, func_021D73E0, func_021D7420, func_021D7424, func_021D7450, func_021D7550, func_021D77D0, func_021D7A3C, func_021D7A94, func_021D7AA8, func_021D7AC8, func_021D7B00, func_021D7B70
 * address:  0x021D72D0
 * region:   ov116
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202E4EC 0x0202E4EC thumb
 *   func_020120B4 0x020120B4 thumb
 *   d_021D8574 0x021D8574 data a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   func_0202E54C 0x0202E54C thumb
 *   func_02045A98 0x02045A98 arm
 *   func_02045A90 0x02045A90 arm
 *   d_021D6338 0x021D6338 data ov115 a4
 *   d_021D654C 0x021D654C data ov115 a4
 *   d_021D8580 0x021D8580 data a4
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D6EC4 0x021D6EC4 thumb ov116
 *   func_021D6E50 0x021D6E50 thumb ov116
 *   func_021D7060 0x021D7060 thumb ov116
 *   func_021D70B0 0x021D70B0 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 *   func_021D81D0 0x021D81D0 thumb ov116
 *   func_021D81EC 0x021D81EC thumb ov116
 *   func_021D81B4 0x021D81B4 thumb ov116
 *   func_021D69A8 0x021D69A8 thumb ov116
 *   func_021D69C0 0x021D69C0 thumb ov116
 *   func_021D69EC 0x021D69EC thumb ov116
 *   func_021D6A10 0x021D6A10 thumb ov116
 *   func_021D6A40 0x021D6A40 thumb ov116
 *   func_021D6A44 0x021D6A44 thumb ov116
 *   func_021D6A48 0x021D6A48 thumb ov116
 *   func_021D6A4C 0x021D6A4C thumb ov116
 *   func_021D6A5C 0x021D6A5C thumb ov116
 *   func_021D6AF0 0x021D6AF0 thumb ov116
 *   func_021D6B30 0x021D6B30 thumb ov116
 *   func_021D7278 0x021D7278 thumb ov116
 *   func_021D7C58 0x021D7C58 thumb ov116
 *   func_021D8118 0x021D8118 thumb ov116
 *   func_021D8134 0x021D8134 thumb ov116
 *   func_021D8168 0x021D8168 thumb ov116
 *   func_021D8190 0x021D8190 thumb ov116
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_021D6998 0x021D6998 thumb ov116
 *   func_02009860 0x02009860 thumb
 *   func_02009CC0 0x02009CC0 thumb
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0205994C 0x0205994C arm
 *   func_021C8F2C 0x021C8F2C arm ov114
 *   func_021C96CC 0x021C96CC arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 *   func_021D70EC 0x021D70EC thumb ov116
 *   func_021C93D0 0x021C93D0 arm ov114
 *   func_021C9634 0x021C9634 arm ov114
 *   func_021C93BC 0x021C93BC arm ov114
 *   func_02157170 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CA98 0x0203CA98 arm
 *   func_021D7158 0x021D7158 thumb ov116
 *   func_021D7200 0x021D7200 thumb ov116
 *   func_021D7184 0x021D7184 thumb ov116
 *   func_021D821C 0x021D821C thumb ov116
 *   func_021D7D0C 0x021D7D0C thumb ov116
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 */
#include "../../matched/include/Obj13867.h"
#include "../../matched/include/Obj22624.h"
#include "../../matched/include/Obj10340.h"
#include "../../matched/include/Obj22625.h"
#include "../../matched/include/Obj22626.h"
#include "../../matched/include/Obj00671.h"
#include "../../matched/include/Obj22627.h"
#include "../../matched/include/Obj22628.h"
#include "../../matched/include/Obj22629.h"
#include "../../matched/include/Obj01926.h"
#include "../../matched/include/Obj00494.h"
#include "../../matched/include/Obj00470.h"
#include "../../matched/include/Obj13868.h"
#include "../../matched/include/Obj10342.h"

#define P(k) (*(void **)(p + (k)))
struct IcaAnime;
struct Param;
struct Obj0202E54C;
struct U16Vec;
struct Blk1AC;
struct BlkB90;
struct Stamp;
struct Sub020097BCObj;
struct Sub0200852CObj;
struct DWCstAccUserData;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed char s8;

typedef int s32_021D7420;

typedef struct { void (*f[3])(int **, int); } Tbl;

typedef signed int     s32_021D7450;

typedef signed int     s32_021D7550;

typedef signed int     s32_021D77D0;

typedef unsigned long long u64;

extern struct Param *func_0202E4EC(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void func_0202E54C(struct Obj0202E54C *p);
extern u16 func_02045A98(void);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_021D8010(void *,u32);
extern int func_021D6EC4(u8 *,u8 *,int);
extern void func_021D6E50(u8 *,u8 *,int,int);
extern void func_021D7060(u8 *,u8 *);
extern int func_021D70B0(void *unused, u8 *p);
extern int func_021D80CC(void *);
extern u32 func_0200DBA0(struct Blk1AC *p, s32_021D7450 i, u32 op);
extern void func_021D81D0(u8 *);
extern int func_021D81EC(u8 *);
extern void func_021D81B4(u8 *p);
extern u8 func_0200DC08(struct Blk1AC *p);
extern void func_021D69A8(u8 *,u8 *,u16),func_021D69EC(u8 *,u8 *,u16);
extern int func_021D69C0(u8 *,u8 *),func_021D6A10(u8 *,u8 *);
extern u16 func_021D6A40(u8 *),func_021D6A44(u8 *),func_021D6A48(u8 *);
extern int func_021D6A4C(unsigned char *p);
extern void func_021D6A5C(u8 *),func_021D6AF0(u8 *,void *),func_021D6B30(u8 *,void *);
extern void func_021D7278(u8 *,int);
extern u32 func_021D8168(u8 *p);
extern int func_0204E804(void);
extern void func_021D8118(u8 *p, u32 i, u32 a, u32 b);
extern void func_021D8134(u8 *p);
extern void func_021D8190(u8 *p);
extern void func_0204E720(u32 a, s32_021D7550 b, s32_021D7550 c, s32_021D7550 d);
extern int func_02167ED8(void *date, void *time);
extern int func_0200DDD0(struct BlkB90 *p, u8 a, u8 b, const struct Stamp *q);
extern void func_021D6998(void *a);
extern void func_021D69A8(u8 *,u8 *,u16);
extern void func_021D6A5C(u8 *);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int func_02009CC0(void *a0);
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode);
extern void func_021C96CC(void);
extern void func_021D70E4(u8 *p);
extern int func_021D70EC(u8 *, int *);
extern int func_021C93D0(void);
extern void func_021C9634(void);
extern void func_021C93BC(void);
extern int func_02157170(int,int);
extern u32 func_0200FB24(void);
extern u32 func_0203CA98(void);
extern int func_021D7158(u8 *p);
extern int func_021D7200(int *p);
extern int func_021D7184(int *p);
extern void *func_021D821C(int, u32);
extern void func_021D7D0C(u8 *, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0203101C(u32, u32, u32, u32);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_0203D34C(u32, u32);
void func_021D72D0(u8 *p, u32 heap);
void func_021D730C(u8 *p);
u32 func_021D7324(u8 *p);
void func_021D737C(u8 *p);
void func_021D73D0(void *a0);
int func_021D73D4(u8 *p);
void func_021D73E0(u8 *p);
void func_021D7420(void *a0);
void func_021D7424(int **p, int x);
int func_021D7450(u8 *p,int b);
int func_021D7550(u8 *p,int heap);
int func_021D77D0(u8 *p,int heap);
void func_021D7A3C(u8 *p);
int func_021D7A94(u8 *p);
void func_021D7AA8(u8 *p);
int func_021D7AC8(u8 *p);
int func_021D7B00(u8 *p);
int func_021D7B64(u8 *p);
void func_021D7B70(u8 *p, u32 heap);
extern u32 d_021D8574[], d_021DA62C[];
extern u8 ov129_id[];
extern u32 d_021D6338[];
extern u8 ov115_id[];
extern u32 d_021D654C[];
extern const Tbl d_021D8580;

void func_021D72D0(u8 *p, u32 heap)
{
    void *obj;
    obj = func_0202E4EC(heap, 2, 10, 2, d_021D8574);
    ((struct Obj13867 *)p)->f1840 = obj;
    func_020120B4(((struct Obj22624 *)(*(u8 * *)&((struct Obj13867 *)p)->f0))->f4, (u32)ov129_id, d_021DA62C, obj);
}

void func_021D730C(u8 *p)
{
    if (((struct Obj10340 *)p)->f1840) {
        func_0202E54C(((struct Obj10340 *)p)->f1840);
        ((struct Obj10340 *)p)->f1840 = 0;
    }
}

u32 func_021D7324(u8 *p) {
    u16 end=func_02045A98();
    u16 *s=func_02045A90(((struct Obj22626 *)(*(u8 * *)&((struct Obj22625 *)p)->f1840))->f20);
    u32 value=0;
    u16 i=0;
    while(s[i]!=end) {
        u16 d=(u16)(s[i]-48);
        if(d>=10) d=(u16)(s[i]-0xff10);
        value *= 10;
        value += d;
        i++;
    }
    return value;
}

void func_021D737C(u8 *p) {
    ((struct Obj00671 *)p)->f9B0=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9B4=0;
    ((struct Obj00671 *)p)->f9C8=1;
    ((struct Obj00671 *)p)->f9B8=1;
    ((struct Obj00671 *)p)->f9BC=44;
    ((struct Obj00671 *)p)->f9C0=p+0x9f4;
    func_020120B4(((struct Obj22627 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,d_021D6338,p+0x9b0);
}

/*
 * extent: two-byte zero alignment padding, then already matched getter ov116_func_021D73D4.c.
 */
void func_021D73D0(void *a0) { }

int func_021D73D4(u8 *p) { return ((struct Obj22628 *)p)->f9CC; }

void func_021D73E0(u8 *p) {
    ((struct Obj00671 *)p)->f9D8=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9DC=0;
    ((struct Obj00671 *)p)->f9E0=1;
    ((struct Obj00671 *)p)->f9E4=1;
    func_020120B4(((struct Obj22629 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,d_021D654C,p+0x9d8);
}


void func_021D7420(void *a0) { }

void func_021D7424(int **p, int x)
{
    Tbl t = d_021D8580;
    t.f[**p](p, x);
}

/*
 * ABI: incoming r1 is forwarded as fourth6E50 argument; 81EC reads
 * incoming r0 left intact by the switch. Both inputs are named.
 */
int func_021D7450(u8 *p,int b)
{
    int v;
    switch (((struct Obj01926 *)p)->fB6C) {
    case 0: func_021D8010(p+4,7); ++((struct Obj01926 *)p)->fB6C; break;
    case 1: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 2:
        v=func_021D6EC4(p+0x1610,p+0x182c,0);
        if(v==1) ((struct Obj01926 *)p)->fB6C=5;
        else if(v==2) ((struct Obj01926 *)p)->fB6C=3;
        break;
    case 3: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 4:
        if(func_021D6EC4(p+0x1610,p+0x182c,1)==1) ((struct Obj01926 *)p)->fB6C=5;
        break;
    case 5: func_021D7060(p+0x1610,p+0x182c); ++((struct Obj01926 *)p)->fB6C; break;
    case 6:
        if(func_021D70B0(p+0x1610,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj01926 *)p)->fB6C;
        break;
    case 7: func_0200DBA0(((struct Obj01926 *)p)->f1858,1,2); func_021D81D0(p); ++((struct Obj01926 *)p)->fB6C; break;
    case 8:
        if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,8); ++((struct Obj01926 *)p)->fB6C; }
        break;
    case 9: if(func_021D80CC(p+4)!=0) ++((struct Obj01926 *)p)->fB6C; break;
    case 10: return 1;
    }
    return 0;
}

int func_021D7550(u8 *p,int heap)
{
    int v,box;
    u32 n;
    u8 extra[12];
    u8 record[16];
    switch(((struct Obj00494 *)p)->fB6C) {
    case 0: func_021D69A8(p+0xb74,p+0x182c,(u32)func_0200DC08(((struct Obj00494 *)p)->f1858)); ++((struct Obj00494 *)p)->fB6C; break;
    case 1: if(func_021D69C0(p+0xb74,p+0x182c)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 2:
        func_021D81B4(p+4); v=func_021D6A48(p+0xb74);
        func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74)); func_021D8010(p+4,0); ++((struct Obj00494 *)p)->fB6C; break;
    case 3: if(func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 4: func_0204E720((int)3,0,16,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 5: if(func_0204E804()==0) { func_021D7C58(p+4); ++((struct Obj00494 *)p)->fB6C; } break;
    case 6: func_021D7278(p,heap); ++((struct Obj00494 *)p)->fB6C; break;
    case 7: ((struct Obj00494 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); func_0204E720((int)3,16,0,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 8:
        if(func_0204E804()==0) {
            box=func_021D6A40(p+0xb74); n=((struct Obj00494 *)p)->fB70; v=func_021D6A48(p+0xb74);
            func_02167ED8(record,extra);
            if(n<1 || n>(u32)v) { ((struct Obj00494 *)p)->fB6C=16; break; }
            if(func_0200DDD0(((struct Obj00494 *)p)->f1854,box,n,(const struct Stamp *)record)!=0) { ((struct Obj00494 *)p)->fB6C=14; break; }
            func_021D69EC(p+0xb74,p+0x182c,((struct Obj00494 *)p)->fB70);
            v=func_021D6A44(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74));
            func_021D8118(p+4,1,func_021D6A40(p+0xb74),(u32)((void *)2)); func_021D8010(p+4,1); func_021D8190(p+4); ++((struct Obj00494 *)p)->fB6C;
        } break;
    case 9: if(func_021D6A10(p+0xb74,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 10: func_021D6A5C(p+0xb74); func_021D6AF0(p+0xb74,((struct Obj00494 *)p)->f1854); func_021D6B30(p+0xb74,((struct Obj00494 *)p)->f1854); func_021D81D0(p); ++((struct Obj00494 *)p)->fB6C; break;
    case 11: if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,3); ++((struct Obj00494 *)p)->fB6C; } break;
    case 12: if(func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 13: return 1;
    case 14: func_021D8010(p+4,2); ++((struct Obj00494 *)p)->fB6C; break;
    case 15: if(func_021D80CC(p+4)!=0) ((struct Obj00494 *)p)->fB6C=2; break;
    case 16: func_021D8010(p+4,4); ++((struct Obj00494 *)p)->fB6C; break;
    case 17: if(func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 18: func_021D8134(p+4); ++((struct Obj00494 *)p)->fB6C; break;
    case 19: v=(int)func_021D8168(p+4); if(v==0) return 2; if(v==-2) ((struct Obj00494 *)p)->fB6C=2; break;
    }
    return 0;
}

int func_021D77D0(u8 *p,int heap)
{
    int v;
    u32 n;
    switch(((struct Obj00470 *)p)->fB6C) {
    case 0: func_021D81B4(p+4); func_021D8010(p+4,5); ++((struct Obj00470 *)p)->fB6C; break;
    case 1: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 2: func_0204E720(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 3: if(func_0204E804()==0) { func_021D7C58(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 4: func_021D72D0(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 5: ((struct Obj00470 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); func_0204E720(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 6:
        if(func_0204E804()==0) {
            n=((struct Obj00470 *)p)->fB70;
            if(n>=1 && n<=10) {
                func_021D69A8(p+0xb74,p+0x182c,n); func_021D8010(p+4,26); func_021D8190(p+4); ++((struct Obj00470 *)p)->fB6C;
            } else ((struct Obj00470 *)p)->fB6C=19;
        } break;
    case 7:
        if(func_021D69C0(p+0xb74,p+0x182c)!=0) {
            func_021D81B4(p+4); v=func_021D6A48(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74)); func_021D8010(p+4,6); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 8: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 9: func_0204E720(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 10: if(func_0204E804()==0) { func_021D7C58(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 11: func_021D7278(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 12: ((struct Obj00470 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); func_0204E720(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 13:
        if(func_0204E804()==0) {
            v=func_021D6A48(p+0xb74); n=((struct Obj00470 *)p)->fB70;
            if(n<1 || n>(u32)v) { ((struct Obj00470 *)p)->fB6C=19; break; }
            func_021D69EC(p+0xb74,p+0x182c,n);
            v=func_021D6A44(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74));
            func_021D8118(p+4,1,func_021D6A40(p+0xb74),(u32)((void *)2)); func_021D8010(p+4,1); func_021D8190(p+4); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 14: if(func_021D6A10(p+0xb74,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 15: func_021D6A5C(p+0xb74); func_021D6B30(p+0xb74,((struct Obj00470 *)p)->f1854); func_021D81D0(p); ++((struct Obj00470 *)p)->fB6C; break;
    case 16: if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,3); ++((struct Obj00470 *)p)->fB6C; } break;
    case 17: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 18: return 1;
    case 19: func_021D8010(p+4,9); ++((struct Obj00470 *)p)->fB6C; break;
    case 20: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 21: func_021D8134(p+4); ++((struct Obj00470 *)p)->fB6C; break;
    case 22: v=func_021D8168(p+4); if(v==0) return 2; if(v==-2) { func_021D6998(p+0xb74); ((struct Obj00470 *)p)->fB6C=0; } break;
    }
    return 0;
}

void func_021D7A3C(u8 *p) {
    void *a=func_02009860(((struct Obj00671 *)p)->f184C);
    void *b;
    u64 value;
    func_02008540(((struct Obj00671 *)p)->f1850,(u32)func_02009CC0(((struct Obj00671 *)p)->f184C));
    b=(void *)func_0200853C(((struct Obj00671 *)p)->f1850);
    value=func_0205994C(a);
    func_021C8F2C((unsigned int)b,(u32)value,(u32)(value>>32),0);
    func_021C96CC();
    func_021D70E4(p+0x182c);
    ((struct Obj00671 *)p)->fB68=1;
}

int func_021D7A94(u8 *p)
{
    int result;
    return func_021D70EC(p + 0x182c, &result);
}

/*
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 (pengy overlay, no witness).
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: func_021C93D0 (ov114 ARM, SDK-side
 *   libext code, no witness). Nothing source-side to change.
 */
void func_021D7AA8(u8 *p)
{
    if (func_021C93D0() == 0) {
        func_021C9634();
        func_021D70E4(p + 0x182c);
    }
}

int func_021D7AC8(u8 *p)
{
    int result;
    if (((struct Obj13868 *)p)->fB68 == 0) return 1;
    if (func_021D70EC(p + 0x182c, &result)) {
        func_021C93BC();
        ((struct Obj13868 *)p)->fB68 = 0;
        return 1;
    }
    return 0;
}

int func_021D7B00(u8 *p) {
    int yes=1;
    int no=0;
    if(func_02157170(1,0)!=0) return no;
    if(func_0200FB24()!=0) {
        func_0203CA98();
        return no;
    }
    if(func_021D7158(p+0x182c)!=0) {
        int v;
        if(func_021D7200((int *)(p+0x182c))!=0) return no;
        v=func_021D7184((int *)(p+0x182c));
        func_021D81B4(p+4);
        func_021D8010(p+4,v);
        return yes;
    }
    return no;
}

int func_021D7B64(u8 *p) { return func_021D80CC(p+4); }

/*
 * evidence: incoming heap in r1 is forwarded unchanged to 021D821C.
 * evidence: 0203101C's second parameter is wide here: original 021D7C26
 * copies full r6 to r1 with no truncation; its definition stores the low halfword.
 */
void func_021D7B70(u8 *p, u32 heap)
{
    P(8) = func_021D821C(1, heap);
    ((struct Obj10342 *)p)->f4 = heap;
    func_021D7D0C(p, heap);
    P(0x97c) = (void *)func_020450F0(1, 1, 19, 30, 4, 12, 1);
    func_0201F73C(P(0x97c), 1, (u16)(((struct Obj10342 *)p)->f984), 13);
    func_02043B5C(func_02045770(P(0x97c)), 15);
    func_02045374(P(0x97c));
    func_02045334(P(0x97c));
    func_02041B6C(1);
    P(0x990) = func_02045B38(0, 2, 206, heap);
    P(0x994) = func_0201EC64(heap);
    P(0x998) = func_0201D7EC(23, 0, 0, 0, heap);
    P(0x99c) = func_020457B0(128, heap);
    P(0x9a0) = func_020457B0(128, heap);
    P(0x9a8) = func_0203101C(heap, heap, 1, 0);
    ((struct Obj10342 *)p)->f0 = 1;
    func_020434DC(16, 1);
    func_02043598(16, 1);
    func_0203D34C(1, heap);
}
