/*
 * file:     unit_021D6660.c
 * unit:     yes
 * function: func_021D6660, func_021D6710, func_021D6918, func_021D696C, func_021D6998, func_021D69A8, func_021D69C0, func_021D69EC, func_021D6A10, func_021D6A40, func_021D6A44, func_021D6A48, func_021D6A4C, func_021D6A5C, func_021D6AF0, func_021D6B30, func_021D6B50, func_021D6B70, func_021D6B88, func_021D6C50, func_021D6CBC, func_021D6D18, func_021D6D40, func_021D6E3C, func_021D6E50, func_021D6EC4, func_021D7010, func_021D7038, func_021D7060, func_021D70B0, func_021D70D8, func_021D70E4, func_021D70EC, func_021D7158, func_021D7184, func_021D7200, func_021D724C, func_021D7250, func_021D7258, func_021D7260, func_021D7278
 * address:  0x021D6660
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
 *   func_02034AC4 0x02034AC4 arm
 *   ov_id 0x00000072 data
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012EFC 0x02012EFC thumb
 *   func_02012EF0 0x02012EF0 thumb
 *   func_02008B08 0x02008B08 thumb
 *   func_021D737C 0x021D737C thumb ov116
 *   func_021D73D4 0x021D73D4 thumb ov116
 *   func_021D7B70 0x021D7B70 thumb ov116
 *   func_021D7A3C 0x021D7A3C thumb ov116
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D8190 0x021D8190 thumb ov116
 *   func_021D7A94 0x021D7A94 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 *   func_021D7424 0x021D7424 thumb ov116
 *   func_021D7AA8 0x021D7AA8 thumb ov116
 *   func_021D7AC8 0x021D7AC8 thumb ov116
 *   func_021D7C58 0x021D7C58 thumb ov116
 *   func_021D73E0 0x021D73E0 thumb ov116
 *   func_021D7B00 0x021D7B00 thumb ov116
 *   func_021D7B64 0x021D7B64 thumb ov116
 *   func_021D7CF4 0x021D7CF4 thumb ov116
 *   func_021C8FA8 0x021C8FA8 arm ov114
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021D730C 0x021D730C thumb ov116
 *   func_021D73D0 0x021D73D0 thumb ov116
 *   func_021D7420 0x021D7420 thumb ov116
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021C941C 0x021C941C arm ov114
 *   func_021C94A0 0x021C94A0 arm ov114
 *   func_02025C1C 0x02025C1C thumb
 *   func_02025C30 0x02025C30 thumb
 *   func_02025CB0 0x02025CB0 thumb
 *   func_02025C88 0x02025C88 thumb
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_0200DD28 0x0200DD28 thumb
 *   func_0200DF10 0x0200DF10 thumb
 *   func_0200846C 0x0200846C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02008510 0x02008510 thumb
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0217BC44 0x0217BC44 arm ov009
 *   func_02045808 0x02045808 arm
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_021B9B00 0x021B9B00 thumb ov114
 *   func_021C9744 0x021C9744 arm ov114
 *   func_02012EBC 0x02012EBC thumb
 *   func_02009470 0x02009470 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0200E6F0 0x0200E6F0 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_02008530 0x02008530 thumb
 *   d_0209DF08 0x0209DF08 data a1
 *   d_0209DF0C 0x0209DF0C data a1
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200E6FC 0x0200E6FC thumb
 *   func_0200DCF8 0x0200DCF8 thumb
 *   func_0200DC74 0x0200DC74 thumb
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B99F0 0x021B99F0 thumb ov114
 *   func_021B9A14 0x021B9A14 thumb ov114
 *   func_021B99F4 0x021B99F4 thumb ov114
 *   D_020A7370 0x020A7370 data a4
 *   func_02045F5C 0x02045F5C arm
 *   func_021C9530 0x021C9530 arm ov114
 *   func_0200DE94 0x0200DE94 thumb
 *   func_0200DEA0 0x0200DEA0 thumb
 *   func_021C93D0 0x021C93D0 arm ov114
 *   func_021C940C 0x021C940C arm ov114
 *   func_021C9634 0x021C9634 arm ov114
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_0200FB4C 0x0200FB4C thumb
 *   func_0202E4EC 0x0202E4EC thumb
 *   func_020120B4 0x020120B4 thumb
 *   d_021D8560 0x021D8560 data ov116 a4
 *   d_021D8568 0x021D8568 data ov116 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   ov129_id 0x81 data
 */
#include "../../matched/include/Obj00671.h"
#include "../../matched/include/Obj22612.h"
#include "../../matched/include/Obj22613.h"
#include "../../matched/include/Obj22614.h"
#include "../../matched/include/Obj13858.h"
#include "../../matched/include/Obj22615.h"
#include "../../matched/include/Obj13859.h"
#include "../../matched/include/Obj10337.h"
#include "../../matched/include/Obj13860.h"
#include "../../matched/include/Obj22616.h"
#include "../../matched/include/Obj22617.h"
#include "../../matched/include/Obj22618.h"
#include "../../matched/include/Obj13861.h"
#include "../../matched/include/Obj22619.h"
#include "../../matched/include/Obj10338.h"
#include "../../matched/include/Obj04469.h"
#include "../../matched/include/Obj13862.h"
#include "../../matched/include/Obj22621.h"
#include "../../matched/include/Obj13863.h"
#include "../../matched/include/Obj04470.h"
#include "../../matched/include/Obj01925.h"
#include "../../matched/include/Obj08046.h"
#include "../../matched/include/Obj10339.h"
#include "../../matched/include/Obj13864.h"
#include "../../matched/include/Obj08047.h"
#include "../../matched/include/Obj06416.h"
#include "../../matched/include/Obj22622.h"
#include "../../matched/include/Obj06417.h"
#include "../../matched/include/Obj13865.h"
#include "../../matched/include/Obj13866.h"
#include "../../matched/include/Obj22623.h"

struct Big;
struct BigObj;
struct Ctx;
struct Sub02008AECObj;
struct Obj0203159C;
struct S020315D4;
struct RecSlot;
struct U16Vec;
struct MsgBank;
struct Rec;
struct Blk1AC;
struct Rec0200E6FC;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct MsgData;
struct IcaAnime;
struct Param;
typedef unsigned char u8;

typedef signed int     s32_021D6660;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int     s32_021D6710;

typedef short s16;

typedef signed char s8;

typedef int s32_021D6A48;

typedef struct { u8 a : 1, b : 1, c : 6; } Bits;

struct Record { unsigned short id:11; unsigned short rest:5; };

typedef int s32_021D70D8;

typedef int s32_021D70E4;

typedef int s32_021D724C;

typedef int s32_021D7250;

typedef int s32_021D7258;

extern int func_02034AC4(s32_021D6660 handle);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern u32 func_0201283C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EFC(void **p);
extern void *func_02012EF0(void **p);
extern u32 func_0200FB24(void);
extern int func_02005E50(void);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int,int);
extern void func_02005DF8(unsigned);
extern void func_02005E30(u32 a);
extern void func_021D737C(u8 *);
extern void func_021D7B70(u8 *,u32);
extern void func_0204E720(u32 a, s32_021D6710 b, s32_021D6710 c, s32_021D6710 d);
extern void func_021D7A3C(u8 *);
extern int func_021D73D4(u8 *),func_0204E804(void),func_021D7A94(u8 *),func_021D80CC(void *);
extern void func_021D8010(void *,u32);
extern void func_021D8190(u8 *p);
extern int func_021D6C50(u8 *,unsigned),func_021D6D18(u8 *,u8 *),func_021D7424(u8 *,int),func_021D7AC8(u8 *);
extern void func_021D6CBC(u8 *,void *,u8 *),func_021D7AA8(u8 *),func_021D7C58(u8 *),func_021D73E0(u8 *);
extern u32 func_0200F7B8(u32 a0);
extern int func_021D7B00(u8 *);
extern int func_021D7B64(u8 *);
extern void func_021D7038(u8 *),func_021C8FA8(void),func_021D7CF4(u8 *);
extern void func_021D730C(u8 *p);
extern void func_021D73D0(void *);
extern void func_021D7420(void *);
extern void func_021D7C58(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_02034A5C(int handle);
extern int func_02005E9C(void);
extern int func_0204E804(void);
extern void func_021C941C(unsigned x);
extern void func_021C94A0(unsigned x, unsigned y, unsigned z);
extern u32 func_02025C1C(u32,u32,u32);
extern u32 func_02025C30(u32,u32,u32);
extern u32 func_02025CB0(u32);
extern u32 func_02025C88(u32);
extern int func_02167ED8(void *, void *);
extern void func_0200DE6C(struct RecSlot *p, const void *src, u8 a, u8 b);
extern void func_0200DD28(u8 *p, u8 a, u8 b, u32 *q);
extern void func_0200DF10(struct RecSlot *p, const void *src, u8 a, u8 b);
extern void *func_0200846C(int);
extern u32 func_020307B0(void *p);
extern void func_02008494(void *, void *);
extern void *func_02008510(void *, int);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
extern void func_02045808(struct U16Vec *vec);
extern int func_0217BC90(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_021B9B00(u8 *,int);
extern void func_021C9744(unsigned char *p, unsigned x);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void *func_0200E6F0(u32);
extern const void *func_020084F4(const void *p);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u16 func_0200DCF8(struct Blk1AC *p);
extern void func_0200DC74(struct Blk1AC *p, u32 which, void *dest);
extern void func_021B9774(unsigned char *);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *func_021B9800(int,int,int);
extern void func_02156DC4(int a0, int a1);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *p, int a, int n);
extern int func_021B98F8(u8 *p);
extern int func_021B9748(u8 *);
extern int func_021B99DC(u8 *);
extern int func_021B9790(u8 *);
extern void func_021B99B8(u8 *);
extern void func_021B9838(u8 *);
extern u8 *func_021B97F4(u8 *);
extern int func_021B99F0(u8 *p);
extern u8 *func_021B9A14(u8 *p, u32 i);
extern u32 func_021B99F4(u32 p, u32 i);
extern void func_02045F5C(struct MsgData *,unsigned int,unsigned short *,unsigned int);
extern u8 func_0200DE94(struct RecSlot *p);
extern u8 func_0200DEA0(struct RecSlot *p);
extern u8 func_0200DCFC(struct Blk1AC *p);
extern void func_021C9530(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v);
extern int func_021C93D0(void);
extern int func_021C940C(void);
extern void func_021C9634(void);
extern void func_0200FB4C(unsigned int x);
extern struct Param *func_0202E4EC(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
int func_021D6660(void *ctx,int unused,u8 *q);
int func_021D6710(void *a,int *state,int b,u8 *p);
int func_021D6918(void *p, int a, int b, u8 *q);
int func_021D696C(unsigned char *a,int b);
void func_021D6998(void *a);
void func_021D69A8(unsigned char *a,unsigned char *b,unsigned short c);
int func_021D69C0(unsigned char *a,unsigned char *b);
void func_021D69EC(unsigned char *a,unsigned char *b,unsigned short c);
int func_021D6A10(unsigned char *a,unsigned char *b);
u16 func_021D6A40(u8 *p);
u16 func_021D6A44(u8 *p);
u16 func_021D6A48(u8 *p);
int func_021D6A4C(unsigned char *p);
void func_021D6A5C(u8 *p);
void func_021D6AF0(u8 *p, void *q);
void func_021D6B30(unsigned char *a,void *b);
void func_021D6B50(unsigned char *a,int b);
void func_021D6B70(unsigned char *a);
void func_021D6B88(u8 *p, void *save, int id);
int func_021D6C50(u8 *p,unsigned heap);
void func_021D6CBC(u8 *p,void *q,u8 *r);
int func_021D6D18(unsigned char *a,unsigned char *b);
void func_021D6D40(u8 *p, void *save, void *idx);
void func_021D6E3C(unsigned char *a);
void func_021D6E50(u8 *p,u8 *q,int a,int b);
int func_021D6EC4(u8 *p, u8 *q, int flag);
void func_021D7010(unsigned int a,unsigned int b);
void func_021D7038(u8 *p);
void func_021D7060(u8 *p, u8 *q);
int func_021D70B0(void *unused, u8 *p);
void func_021D70D8(void *p);
void func_021D70E4(u8 *p);
int func_021D70EC(u8 *p,int *q);
int func_021D7158(u8 *p);
int func_021D7184(int *p);
int func_021D7200(int *p);
void func_021D724C(u8 *p, u32 v);
void func_021D7250(u8 *p, u32 v);
void func_021D7258(u8 *p);
void func_021D7260(u8 *p);
void func_021D7278(u8 *p,int a);
extern u8 ov_id[];
extern u8 d_0209DF08, d_0209DF0C;
extern struct MsgData *D_020A7370;
extern u32 d_021D8560[],d_021D8568[],d_021DA62C[];
extern u8 ov129_id[];

int func_021D6660(void *ctx,int unused,u8 *q) {
    u8 *p;
    void *save;
    func_02034AC4((s32_021D6660)ov_id);
    func_0203064C(1,125,0x18000);
    p=func_0203159C(ctx,0x185c,125);
    func_02082BCC(p,0,0x185c);
    *(u8 **)p=q;
    *(int *)(q+8)=1;
    save=func_020120F4(*(void **)(*(u8 **)p+4));
    q=func_02012EBC(save);
    *(void **)(p+0x1844)=save;
    *(int *)(p+0x1848)=(int)func_02008B08(q);
    *(int *)(p+0x184c)=func_0201283C(save);
    *(int *)(p+0x1850)=(int)func_02012944(save);
    *(int *)(p+0x1854)=(int)func_02012EFC(save);
    *(int *)(p+0x1858)=(int)func_02012EF0(save);
    func_021D6998(p+0xb74);
    func_021D6B50(p+0x1610,125);
    func_021D70D8(p+0x182c);
    return 1;
}

int func_021D6710(void *a,int *state,int b,u8 *p)
{
    int v;
    if(func_021D696C(p,*state)!=0) {
        if(func_021D7158(p+0x182c)!=0 || func_0200FB24()!=0) *state=20;
    }
    switch(*state) {
    case 0: func_02005E30(6); ++*state; break;
    case 1: if(func_02005E50()==0) { func_02005DE4((void *)1); func_02005E64(); func_02005D90(1153,65535); func_02005DF8(6); ++*state; } break;
    case 2: func_021D737C(p); ++*state; break;
    case 3: if(func_021D73D4(p)==0) ++*state; else { ((struct Obj22612 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=2; *state=17; } break;
    case 4: func_021D7B70(p+4,125); func_0204E720(3,16,0,1); ++*state; break;
    case 5: if(func_0204E804()==0) ++*state; break;
    case 6: func_021D7A3C(p); func_021D8010(p+4,26); func_021D8190(p+4); ++*state; break;
    case 7: if(func_021D7A94(p)!=0) ++*state; break;
    case 8: if(func_021D80CC(p+4)!=0) ++*state; break;
    case 9: func_021D6B88(p+0x1610,((struct Obj00671 *)p)->f1844,125); ++*state; break;
    case 10: if(func_021D6C50(p+0x1610,125)!=0) ++*state; break;
    case 11: func_021D6CBC(p+0x1610,((struct Obj00671 *)p)->f1844,p+0x182c); ++*state; break;
    case 12: if(func_021D6D18(p+0x1610,p+0x182c)!=0) ++*state; break;
    case 13: v=func_021D7424(p,125); if(v==1) { ((struct Obj22613 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=0; ++*state; } else if(v==2) { ((struct Obj22614 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f8=2; ++*state; } break;
    case 14: func_021D7AA8(p); func_0204E720(3,0,16,1); ++*state; break;
    case 15: if(func_021D7AC8(p)!=0 && func_0204E804()==0) { func_021D7C58(p+4); ++*state; } break;
    case 16: if(func_0200F7B8(0)==0) func_021D73E0(p); ++*state; break;
    case 17: func_02005E30(6); ++*state; break;
    case 18: if(func_02005E50()==0) ++*state; break;
    case 19: return 1;
    case 20: if(func_021D7B00(p)!=0) *state=21; else *state=14; func_021D7038(p+0x1610); break;
    case 21: if(func_021D7B64(p)!=0) *state=14; break;
    }
    if(((struct Obj00671 *)p)->fB68!=0) func_021C8FA8();
    func_021D7CF4(p+4);
    return 0;
}

int func_021D6918(void *p, int a, int b, u8 *q) {
    func_021D730C(q);
    func_021D73D0(q);
    func_021D7420(q);
    func_021D6B70(q + 0x1610);
    func_021D7C58(q + 4);
    func_020315D4(p);
    func_020306F0(125);
    func_02034A5C((int)ov_id);
    func_02005E9C();
    func_02005DE4(0);
    func_02005DF8(60);
    return 1;
}

int func_021D696C(unsigned char *a,int b) { if(b<=13 && func_0204E804()==0 && ((struct Obj13858 *)a)->fB68!=0 && ((struct Obj13858 *)a)->fB6A==0) return 1; return 0; }

void func_021D6998(void *a) { func_02082BCC(a,0,0xa9c); }

/*
 * Two bytes zero alignment padding follow the compiled function.
 */
void func_021D69A8(unsigned char *a,unsigned char *b,unsigned short c) { ((struct Obj22615 *)a)->f8=c; func_021C941C((unsigned char)c); func_021D70E4(b); }

int func_021D69C0(unsigned char *a,unsigned char *b) { int result; if(func_021D70EC(b,&result) && func_021D7158(b)==0) { ((struct Obj13859 *)a)->fC=result; ((struct Obj13859 *)a)->f0=1; return 1; } return 0; }

void func_021D69EC(unsigned char *a,unsigned char *b,unsigned short c) { ((struct Obj10337 *)a)->fA=c; func_021C94A0((unsigned char)(((struct Obj10337 *)a)->f8),(unsigned char)(((struct Obj10337 *)a)->fA),(unsigned int)(a+14)); func_021D70E4(b); }

/*
 * Remaining extent: existing matched accessor files at 021D6A40 and 021D6A44.
 */
int func_021D6A10(unsigned char *a,unsigned char *b) { int result; if(((struct Obj13860 *)a)->f4) return 1; if(func_021D70EC(b,&result) && func_021D7158(b)==0) { ((struct Obj13860 *)a)->f4=1; return 1; } return 0; }

/*
 * leaf: blocks func_021D7550.
 */
u16 func_021D6A40(u8 *p) { return ((struct Obj22616 *)p)->f8; }

u16 func_021D6A44(u8 *p) { return ((struct Obj22617 *)p)->fA; }


u16 func_021D6A48(u8 *p) { return ((struct Obj22618 *)p)->fC; }

int func_021D6A4C(unsigned char *p)
{
    if (*(unsigned short *)(p + 12) < 100) {
        return 2;
    }
    return 3;
}

void func_021D6A5C(u8 *p) {
    int i,j;
    u8 *q,*r;
    q=p+14;
    r=p+0x69e;
    for(i=0;i<7;i++) {
        j=i*240;
        q[j+0xc6]=func_02025C1C(q[j+0xc6],q[j+0xc7],q[j+0xc5]);
        q[j+0xc7]=func_02025C30(q[j+0xc6],q[j+0xc7],q[j+0xc5]);
        q[j+0xd5]=func_02025C88(func_02025CB0(q[j+0xd5]));
    }
    for(i=0;i<30;i++) {
        q=r+i*34;
        q[18]=func_02025C1C(q[18],q[19],q[17]);
        q[19]=func_02025C30(q[18],q[19],q[17]);
    }
}

void func_021D6AF0(u8 *p, void *q) {
    u32 time[3];
    u32 date[4];
    func_02167ED8(date, time);
    func_0200DE6C(q, p + 14, *(u16 *)(p + 8), *(u16 *)(p + 10));
    func_0200DD28(q, *(u16 *)(p + 8), *(u16 *)(p + 10), date);
}

void func_021D6B30(unsigned char *a,void *b) { func_0200DF10(b,a+0x69e,((struct Obj13861 *)a)->f8,((struct Obj13861 *)a)->fA); }

void func_021D6B50(unsigned char *a,int b) { func_02082BCC(a,0,0x21c); ((struct Obj22619 *)a)->f218=func_0200846C(b); }

void func_021D6B70(unsigned char *a) { if(((struct Obj10338 *)a)->f218) { func_020307B0(((struct Obj10338 *)a)->f218); ((struct Obj10338 *)a)->f218=0; } }

/*
 * extent: two zero alignment bytes at 021D6C4E follow the epilogue.
 * evidence: 0217BC44's full ov009 ARM wrapper forwards r0-r3 and
 * three full-word stack arguments to 0217B828; this caller supplies all7.
 */
void func_021D6B88(u8 *p, void *save, int id)
{
    void *str;
    u16 *chars;
    u32 i;
    func_02008494(func_02012944(save), ((struct Obj04469 *)p)->f218);
    str = func_02008510(((struct Obj04469 *)p)->f218, id);
    func_02082BCC(p + 0x1f0, 0, 40);
    ((struct Obj04469 *)p)->f214 = id;
    chars = func_02045A90(str);
    for (i = 0; i < func_020458F8(str) + 1u; i++) {
        u16 c = chars[i];
        if (c == func_02045A98()) ((u16 *)(p + 0x1f0))[i] = 0;
        else ((u16 *)(p + 0x1f0))[i] = c;
    }
    ((struct Obj04469 *)p)->f208 = p + 0x1f0;
    ((struct Obj04469 *)p)->f210 = 0;
    func_0217BC44((short unsigned int **)(p + 0x208), 1, 0, 0, (char *)(p + 0x20c), (int *)(p + 0x210), 128);
    func_02045808(str);
}

int func_021D6C50(u8 *p,unsigned heap) {
    int flag,ready;
    void *bank,*str;
    flag = func_0217BC90()==2;
    if(flag) ready = ((struct Obj13862 *)p)->f210>0;
    if(flag==0) return 0;
    if(flag==1 && ready==1) {
        bank = func_02045B38(0,2,0x51,heap);
        str = func_02045EC0(bank,15);
        func_02045C04(bank);
        func_020084E4((u16 *)((struct Obj13862 *)p)->f218,str);
        func_02045808(str);
        return 2;
    }
    return 1;
}

/*
 *   extern int func_020071CC(void *,int);
 *   int func_02012EF0(void **p) { return func_020071CC(*p,58); }
 *   extern int func_020071CC(void *,int);
 *   int func_02012EFC(void **p) { return func_020071CC(*p,59); }
 */
void func_021D6CBC(u8 *p,void *q,u8 *r) {
    int a,b,c;
    func_02012EBC(q);
    a = (int)func_02012EFC(q);
    b = (int)func_02012EF0(q);
    c = *(int *)(p+0x218);
    func_021B9B00(p+4,c);
    func_021C9744(p+4,(unsigned int)(p+0x68));
    func_021D70E4(r);
    func_021D6D40(p+0x70,q,(void *)c);
    *(int *)(p+0x160)=a;
    *(int *)(p+0x164)=b;
}

int func_021D6D18(unsigned char *a,unsigned char *b) { int result; if(func_021D70EC(b,&result) && func_021D7158(b)==0) { ((struct Obj22621 *)a)->f0=1; return 1; } return 0; }

/*
 * singleton tu --suggest-split returns MATCH252, no viable partition.
 * fixed dsi/1.1p1 -O4,p Thumb; copied prior 6CBC blocker, owner Ilias.
 *   extern int func_020071CC(void *, int);
 *   int func_02012EF0(void **p) { return func_020071CC(*p, 58); }
 * evidence: 084F4 is bx lr and preserves its incoming pointer in r0;
 * caller consumes it despite the matched callee's void signature.
 * evidence: 08550's matched body returns zero-extended byte +1d;
 * original caller explicitly truncates that r0 before the byte bitfield.
 * A wide extern and explicit u8 cast retain that redundant conversion.
 * checks: 1 own callee/unit bodies and original live registers agree;
 * 2 full 6CBC/6A5C/6E50 twins; 3 wide8550+u8 cast fixes missing4B;
 * 4 redundant-bitfield/result-truncation idioms; 5 fresh full idiom ls
 * and full 6C50/6A5C/6E50 neighbours. Iteration2, no stop exhaustion.
 */
void func_021D6D40(u8 *p, void *save, void *idx)
{
    void *profile, *n, *object;
    int i;
    profile = func_02012EBC(save);
    func_02009470(profile);
    func_0201283C(save);
    n = func_02012EF0(save);
    object = func_0200E6F0((u32)profile);
    func_02082BCC(p, 0, 240);
    func_02082D44(func_020084F4(idx), p + 0xb4, 16);
    *(u32 *)(p + 0xc8) = func_02008530(idx);
    p[0xc4] = d_0209DF08;
    p[0xc5] = d_0209DF0C;
    p[0xc6] = func_0200856C(idx);
    p[0xc7] = func_02008570(idx);
    ((Bits *)(p + 0xd4))->b = (u8)(u32)func_02008550(idx);
    p[0xd5] = func_02008554(idx);
    p[0xd5] = func_02025C88(p[0xd5]);
    for (i = 0; i < 3; i++) func_0200E6FC(object, i + 1, (struct Rec0200E6FC *)(p + 0xd6 + i * 8));
    func_0200E6FC(object, 4, (struct Rec0200E6FC *)(p + 0xcc));
    *(u16 *)(p + 0xee) = func_0200DCF8(n);
    func_0200DC74(n, 1, p);
}

void func_021D6E3C(unsigned char *a) { if(((struct Obj13863 *)a)->f168) func_021B9774(((struct Obj13863 *)a)->f168); }

void func_021D6E50(u8 *p,u8 *q,int a,int b) {
    *(u8 * *)&((struct Obj04470 *)p)->f168=func_021B9800(b,func_0200853C(((struct Obj04470 *)p)->f218),a);
    func_02156DC4((int)func_021D6E3C,(int)p);
    func_021B98A0(*(u8 * *)&((struct Obj04470 *)p)->f168,b,180,4);
    func_021B98D8(*(u8 * *)&((struct Obj04470 *)p)->f168,(int)(p+0x70),180);
    ((struct Obj04470 *)p)->f16C=3;
    func_021B98F8(*(u8 * *)&((struct Obj04470 *)p)->f168);
    func_021B9748(*(u8 * *)&((struct Obj04470 *)p)->f168);
    func_021D7258(q);
}

/*
 * extent: two zero alignment bytes at 021D700E follow the epilogue.
 * evidence: ov114 labelled 97F4/99F0/99F4/9A14 bodies read the
 * declared pointer/index inputs; 99F4 reconstructs a full32-bit value.
 * Original keeps field loads and repeated per-call object reloads.
 */
int func_021D6EC4(u8 *p, u8 *q, int flag)
{
    int result = 0;
    int code, status, all, i;
    u8 *x;
    code = func_021B99DC(*(u8 * *)&((struct Obj01925 *)p)->f168);
    status = func_021B9790(*(u8 * *)&((struct Obj01925 *)p)->f168);
    if (code != 200 && status == 0) {
        func_021D7250(q, code);
        func_021B9774(*(u8 * *)&((struct Obj01925 *)p)->f168);
        func_021B99B8(*(u8 * *)&((struct Obj01925 *)p)->f168);
        func_021B9838(*(u8 * *)&((struct Obj01925 *)p)->f168);
        *(u8 * *)&((struct Obj01925 *)p)->f168 = 0;
        func_02156DC4(0, 0);
        return 2;
    }
    if (status != 0) {
        func_021D7260(q);
    } else {
        x = func_021B97F4(*(u8 * *)&((struct Obj01925 *)p)->f168);
        if (func_021B99F0(x) == 0) {
            all = 1;
            func_02082D44(func_021B9A14(x, ((struct Obj01925 *)p)->f16C), p + 0x16e, 128);
            for (i = 0; i < ((struct Obj01925 *)p)->f16C; i++) {
                if (func_021B99F4((u32)x, i) != 0) {
                    all = 0;
                    if (flag != 0) func_021D724C(q, 1);
                    else func_021D7010((unsigned int)p, i);
                }
            }
            if (all != 0) result = 1;
            else result = 2;
        } else {
            if (flag != 0) func_021D724C(q, 2);
            result = 2;
            for (i = 0; i < ((struct Obj01925 *)p)->f16C; i++) {
                if (func_021B99F4((u32)x, i) != 0) func_021D7010((unsigned int)p, i);
            }
        }
        func_021B99B8(*(u8 * *)&((struct Obj01925 *)p)->f168);
        func_021B9838(*(u8 * *)&((struct Obj01925 *)p)->f168);
        *(u8 * *)&((struct Obj01925 *)p)->f168 = 0;
        func_02156DC4(0, 0);
    }
    return result;
}

void func_021D7010(unsigned int a,unsigned int b) { unsigned int p; p=a+0x70+b*0x3c; func_02045F5C(D_020A7370,((struct Record *)p)->id,(unsigned short *)(p+0x22),11); }

void func_021D7038(u8 *p)
{
    if (*(u8 * *)&((struct Obj08046 *)p)->f168) {
        func_02156DC4(0, 0);
        func_021B99B8(*(u8 * *)&((struct Obj08046 *)p)->f168);
        func_021B9838(*(u8 * *)&((struct Obj08046 *)p)->f168);
        *(u8 * *)&((struct Obj08046 *)p)->f168 = 0;
    }
}

void func_021D7060(u8 *p, u8 *q) {
    int a, b, c;
    a = func_0200DE94(((struct Obj10339 *)p)->f160);
    b = func_0200DEA0(((struct Obj10339 *)p)->f160);
    c = func_0200DCFC(((struct Obj10339 *)p)->f164);
    func_021C9530((u8)a,(u8)b,(u8)c,p+0x70,p+0x16e,(int)0x80);
    func_021D70E4(q);
}

int func_021D70B0(void *unused, u8 *p)
{
    int result;
    if (func_021D70EC(p, &result) && func_021D7158(p) == 0) return 1;
    return 0;
}

void func_021D70D8(void *p) { func_02082BCC(p, 0, 0x14); }


void func_021D70E4(u8 *p) { ((struct Obj13864 *)p)->f8 = 0; ((struct Obj13864 *)p)->fA = 0; }

/*
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 and 0x021C940C (pengy overlay, no witness).
 * Also unresolved: ov114 ARM 0x021C93D0, unlabelled state query leaf.
 * No overlay leaves filed because the SDK blocker persists; parent requested park.
 * ISA evidence: show --region ov114 --arm reads state at 0x021D4084;
 * overlapping ov021 0x021C93D0 is different Thumb code.
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Open relocations: func_021C93D0 and func_021C940C (ov114
 *   ARM, SDK-side, no witness). Nothing source-side to change.
 */
int func_021D70EC(u8 *p,int *q) {
    int done=0;
    if(func_021C93D0()==0) {
        (*(s16 *)(p+10))++;
        if(*(s16 *)(p+10)==3600) {
            func_021C9634();
            *(s16 *)(p+8)=1;
        }
    } else {
        int result=func_021C940C();
        done=1;
        switch(result) {
        case -7: case -6: case -4: case -3: case -2: case -1:
            *(int *)p=result; break;
        case -5: func_0200F7B8(1); break;
        default:
            if(result>=0) *q=result;
            else func_0200F7B8(1);
            break;
        }
    }
    return done;
}

int func_021D7158(u8 *p)
{
    if (((struct Obj08047 *)p)->f0 < 0) return 1;
    if (((struct Obj08047 *)p)->f4 != 0) return 1;
    if (((struct Obj08047 *)p)->fC != 0) return 1;
    if (((struct Obj08047 *)p)->f8 != 0) return 1;
    return 0;
}

int func_021D7184(int *p) {
    int result=0;
    if(p[0]<0) {
        switch(p[0]) {
        case -2: result=16; break;
        case -6: result=17; break;
        case -1: result=15; break;
        case -7: result=19; break;
        case -4: result=18; break;
        case -3: result=20; break;
        default: result=22; break;
        }
    } else {
        switch(p[1]) {
        case 1: result=13; break;
        case 2: result=14; break;
        case 0:
            switch(p[3]) {
            case 1: result=23; break;
            case 2: result=23; break;
            case 0: if(((struct Obj06416 *)p)->f8!=0) result=16; break;
            }
            break;
        }
    }
    return result;
}

int func_021D7200(int *p) {
    int v;
    if(p[3]==3) {
        switch(p[4]) {
        case 200: case 400: v=65; break;
        case 401: v=66; break;
        case 408: v=68; break;
        default: v=67; break;
        }
        func_0200FB4C(v);
        return 1;
    }
    return 0;
}


void func_021D724C(u8 *p, u32 v) { ((struct Obj22622 *)p)->fC = v; }


void func_021D7250(u8 *p, u32 v) { ((struct Obj06417 *)p)->fC = 3; ((struct Obj06417 *)p)->f10 = v; }


void func_021D7258(u8 *p) { ((struct Obj13865 *)p)->f8 = 0; ((struct Obj13865 *)p)->fA = 0; }

void func_021D7260(u8 *p)
{
    (((struct Obj06417 *)p)->fA)++;
    if (((struct Obj06417 *)p)->fA == 3600) ((struct Obj06417 *)p)->f8 = 1;
}

void func_021D7278(u8 *p,int a) {
    void *obj;
    d_021D8560[2]=(u32)func_021D6A4C(p+0xb74);
    obj=func_0202E4EC(a,1,func_021D6A48(p+0xb74),3,d_021D8568);
    ((struct Obj13866 *)p)->f1840=obj;
    func_020120B4(((struct Obj22623 *)(*(u8 * *)&((struct Obj13866 *)p)->f0))->f4,(u32)ov129_id,d_021DA62C,obj);
}
