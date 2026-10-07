/*
 * file:     wifibattlematch_net_p24.c
 * unit:     yes
 * function: func_021DC77C, func_021DC8A0, func_021DC8B4, func_021DC908, func_021DCA28, func_021DCAEC, func_021DCB58, func_021DCC28, func_021DCE08, func_021DCE24, func_021DCE40, func_021DCE48, func_021DCE50, func_021DCE58, func_021DCE60, func_021DCEE0, func_021DCFDC, func_021DCFFC, func_021DD008, func_021DD020, func_021DD02C, func_021DD034, func_021DD038, func_021DD040, func_021DD044
 * address:  0x021DC77C
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
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021DC610 0x021DC610 thumb ov175
 *   func_0200FB4C 0x0200FB4C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   d_021E2EF8 0x021E2EF8 data
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_02008510              0x02008510  thumb
 *   MI_CpuFill8                0x02082BCC  arm
 *   func_02045A90              0x02045A90  arm
 *   func_020458F8              0x020458F8  arm
 *   func_02045A98              0x02045A98  arm
 *   DWC_CheckProfanityExAsync  0x0217BC44  arm  ov009
 *   func_02045808              0x02045808  arm
 *   DWC_CheckProfanityProcess  0x0217BC90  arm  ov009
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020084E4  0x020084E4  thumb
 *   func_020173EC 0x020173EC thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B99F0 0x021B99F0 thumb ov114
 *   func_021B99F4 0x021B99F4 thumb ov114
 *   func_021B9A14 0x021B9A14 thumb ov114
 *   func_02082D44 0x02082D44 arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_021E3270  0x021E3270  data
 *   d_021E3250  0x021E3250  data
 *   g_021E32C4   0x021E32C4  data
 *   g_021E32C8   0x021E32C8  data
 *   g_021E32E0   0x021E32E0  data
 *   g_021E32FC   0x021E32FC  data
 *   g_021E3318   0x021E3318  data
 *   g_021E3338   0x021E3338  data
 *   g_021E3354   0x021E3354  data
 *   g_021E3370   0x021E3370  data
 *   g_021E3390   0x021E3390  data
 *   g_021E33B0   0x021E33B0  data
 *   g_021E33D0   0x021E33D0  data
 *   g_021E33E8   0x021E33E8  data
 *   g_021E3400   0x021E3400  data
 *   g_021E3418   0x021E3418  data
 *   g_021E3430   0x021E3430  data
 *   g_021E3448   0x021E3448  data
 *   g_021E3460   0x021E3460  data
 *   g_021E347C   0x021E347C  data
 *   g_021E348C   0x021E348C  data
 *   g_021E34A4   0x021E34A4  data
 *   g_021E34C0   0x021E34C0  data
 *   g_021E34D4   0x021E34D4  data
 *   g_021E34F0   0x021E34F0  data
 *   g_021E3508   0x021E3508  data
 *   g_021E3520   0x021E3520  data
 *   g_021E3538   0x021E3538  data
 *   g_021E3550   0x021E3550  data
 *   g_021E356C   0x021E356C  data
 *   g_021E3584   0x021E3584  data
 *   g_021E359C   0x021E359C  data
 *   g_021E35B4   0x021E35B4  data
 *   g_021E35CC   0x021E35CC  data
 *   g_021E35E4   0x021E35E4  data
 *   g_021E3600   0x021E3600  data
 *   g_021E3618   0x021E3618  data
 */
#include "../../matched/include/Obj06576.h"
#include "../../matched/include/Obj10693.h"
#include "../../matched/include/Obj01956.h"
#include "../../matched/include/Obj14349.h"
#include "../../matched/include/Obj14350.h"
#include "../../matched/include/Obj14351.h"
#include "../../matched/include/Obj14352.h"
#include "../../matched/include/Obj14353.h"
#include "../../matched/include/Obj14354.h"
#include "../../matched/include/Obj24396.h"
#include "../../matched/include/Obj24397.h"

struct Sub0200852CObj;
struct U16Vec;
struct MsgBank;
struct Rec;
typedef unsigned char u8;

typedef unsigned int u32_021DC77C;

typedef struct {u32_021DC77C a,b;} Pair;

typedef unsigned int u32_021DC8A0;

typedef struct { char pad[0x1220]; u32_021DC8A0 a,b; } Obj;

typedef unsigned int u32_021DC8B4;

typedef struct { u32_021DC8B4 a, b; } W;

typedef unsigned int u32_021DC908;

typedef unsigned short u16;

typedef unsigned long u32_021DCA28;

typedef unsigned long u32_021DCAEC;

typedef unsigned int   u32_021DCB58;

typedef unsigned int u32_021DCC28;

typedef unsigned long u32_021DCE08;

typedef unsigned int   u32_021DCE24;

typedef unsigned long u32_021DCE40;

typedef unsigned long u32_021DCE48;

typedef unsigned long u32_021DCE50;

typedef unsigned long u32_021DCE58;

typedef unsigned long u32_021DCE60;

typedef unsigned long u32_021DCEE0;

typedef unsigned long u32_021DCFDC;

typedef unsigned long u32_021DCFFC;

typedef unsigned int   u32_021DD008;

typedef unsigned long u32_021DD020;

typedef unsigned long u32_021DD02C;

typedef unsigned long u32_021DD034;

typedef unsigned long u32_021DD038;

typedef unsigned long u32_021DD040;

typedef unsigned int u32_021DD044;

extern int func_021B95D4(int,u8 *);
extern int func_021B9748(u8 *);
extern void func_021B9838(u8 *);
extern int func_021B99DC(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern void func_021B9774(u8 *);
extern int func_021DC610(u32_021DC77C);
extern void func_0200FB4C(unsigned int x);
extern void func_02082BCC(void *,int,int);
extern void func_02034714(const char *, unsigned, const char *);
extern u8 *func_02012944(void *);
extern u32_021DC8B4 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *func_021B9800(int, int, int);
extern int func_021B973C(char *);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void *func_02008510(void *a, int tag);
extern void MI_CpuFill8(void *dst, u8 val, u32_021DCA28 size);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern int DWC_CheckProfanityExAsync(u16 **words, int wordsnum, char *reserved, int timeout,
                                     char *result, int *badwordsnum, int region);
extern void func_02045808(struct U16Vec *vec);
extern int DWC_CheckProfanityProcess(void);
extern struct MsgBank *func_02045B38(u32_021DCAEC resident, u32_021DCAEC arcId, u32_021DCAEC fileId, u32_021DCAEC heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32_021DCAEC index);
extern u32_021DCAEC func_02045C04(struct Rec *rec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern unsigned func_020173EC(void);
extern unsigned func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32_021DCB58 idx);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *,int,int);
extern int func_021B98F8(u8 *);
extern void func_021B99B8(u8 *);
extern int func_021B99F0(u8 *p);
extern u32_021DCC28 func_021B99F4(u32_021DCC28 p, u32_021DCC28 i);
extern u8 *func_021B9A14(u8 *,u32_021DCC28);
extern void func_02082D44(const void *,void *,u32_021DCC28);
extern void func_0203C9AC(int a, u32_021DCE08 b, u32_021DCE08 c, u32_021DCE08 d);
extern void func_0203D34C(u32_021DD008 a, u32_021DD008 b);
extern int func_02009CC0(void *a0);
int func_021DC77C(u8 *p);
void func_021DC8A0(const Obj *p,Pair *out);
void func_021DC8B4(u8 *p, const W *src, int x);
int func_021DC908(char *p);
void func_021DCA28(char *obj, u32_021DCA28 win, u16 tag);
int func_021DCAEC(char *obj, int *out);
void func_021DCB58(char *p,void *q,int mode);
int func_021DCC28(char *p,u8 *out);
void func_021DCE08(char *ctx, u32_021DCE08 v, int line);
void func_021DCE24(char *p, int v, int a2);
void func_021DCE40(char *ctx, u32_021DCE40 v, int line);
void func_021DCE48(char *ctx, u32_021DCE48 v, int line);
void func_021DCE50(char *ctx, u32_021DCE50 v, int line);
void func_021DCE58(char *ctx, u32_021DCE58 v, u32_021DCE58 a2);
u32_021DCE60 func_021DCE60(int a);
u32_021DCEE0 func_021DCEE0(int a, int b, int c);
u32_021DCFDC func_021DCFDC(u32_021DCFDC v);
void func_021DCFFC(void *p);
void func_021DD008(char *p, int flag);
u32_021DD020 func_021DD020(char *obj);
char *func_021DD02C(void);
u32_021DD034 func_021DD034(void);
char *func_021DD038(void);
u32_021DD040 func_021DD040(void);
int func_021DD044(int a);
extern const char d_021E2EF8[];
extern char d_021E3270[];
extern char d_021E3250[];
extern u32_021DD044 g_021E32C4[];
extern u32_021DD044 g_021E32C8[];
extern u32_021DD044 g_021E32E0[];
extern u32_021DD044 g_021E32FC[];
extern u32_021DD044 g_021E3318[];
extern u32_021DD044 g_021E3338[];
extern u32_021DD044 g_021E3354[];
extern u32_021DD044 g_021E3370[];
extern u32_021DD044 g_021E3390[];
extern u32_021DD044 g_021E33B0[];
extern u32_021DD044 g_021E33D0[];
extern u32_021DD044 g_021E33E8[];
extern u32_021DD044 g_021E3400[];
extern u32_021DD044 g_021E3418[];
extern u32_021DD044 g_021E3430[];
extern u32_021DD044 g_021E3448[];
extern u32_021DD044 g_021E3460[];
extern u32_021DD044 g_021E347C[];
extern u32_021DD044 g_021E348C[];
extern u32_021DD044 g_021E34A4[];
extern u32_021DD044 g_021E34C0[];
extern u32_021DD044 g_021E34D4[];
extern u32_021DD044 g_021E34F0[];
extern u32_021DD044 g_021E3508[];
extern u32_021DD044 g_021E3520[];
extern u32_021DD044 g_021E3538[];
extern u32_021DD044 g_021E3550[];
extern u32_021DD044 g_021E356C[];
extern u32_021DD044 g_021E3584[];
extern u32_021DD044 g_021E359C[];
extern u32_021DD044 g_021E35B4[];
extern u32_021DD044 g_021E35CC[];
extern u32_021DD044 g_021E35E4[];
extern u32_021DD044 g_021E3600[];
extern u32_021DD044 g_021E3618[];

/*
 * checks: 1 copied own ov114/DC610 signatures and ARM9 blocker input reads; 2 existing DC8A0 Pair twin used; 3 Pair replaces scalar two-word copy; 4 aggregate-copy idioms applied; 5 fresh directory and ov175 neighbours read. Caller TU MATCH has no viable split; only ARM90200FB4C blocks it.
 * lever: Pair aggregate assignment fixes all four payload-copy register bytes; TU --suggest-split confirms MATCH, no viable cut.
 * extent: lead 292 bytes; following 20-byte DC8A0 is already B7's src/matched/ov/ov175_func_021DC8A0.c.
 */
int func_021DC77C(u8 *p)
{
    int query,status;
    const u8 *r;
    if(*(u8 **)(p+0x121c)==0)return 2;
    switch(*(u32_021DC77C *)(p+0x12c)) {
    case 0:
        if(func_021B95D4(5,*(u8 **)(p+0x121c))!=0)*(u32_021DC77C *)(p+0x12c)=1;
        break;
    case 1:
        if(func_021B9748(*(u8 **)(p+0x121c))==0) {*(u32_021DC77C *)(p+0x12c)=2;break;}
        if(*(u8 **)(p+0x121c)!=0) {func_021B9838(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;}
        return 2;
    case 2:
        query=func_021B99DC(*(u8 **)(p+0x121c));
        status=func_021B9790(*(u8 **)(p+0x121c));
        if(status==0) {
            r=func_021B97F4(*(u8 **)(p+0x121c));
            if(query!=0x1f6) {
                if(query==0x1f7) {*(u32_021DC77C *)(p+0x12c)=4;func_0200FB4C(62);return 0;}
            } else {*(u32_021DC77C *)(p+0x12c)=4;func_0200FB4C(63);return 0;}
            *(Pair *)(p+0x1220)=*(const Pair *)(r+0x80);
            if(*(u32_021DC77C *)r==0)*(u32_021DC77C *)(p+0x12c)=3;
            else {func_0200FB4C(func_021DC610(*(u32_021DC77C *)r));*(u32_021DC77C *)(p+0x12c)=4;}
        } else if(status!=15) {
            if(*(u8 **)(p+0x121c)!=0) {func_021B9838(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 4:
        func_02082BCC(p+0x1220,0,8);
        if(*(u8 **)(p+0x121c)!=0) {
            func_021B9774(*(u8 **)(p+0x121c));func_021B9838(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;
        }
        return 3;
    case 3:
        if(*(u8 **)(p+0x121c)!=0) {func_021B9838(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}

/*
 * Pair aggregate assignment preserves the forward load and store order.
 * leaf: coordinated transfer from B10's extent to unblock 021D6C54.
 */
void func_021DC8A0(const Obj *p,Pair *out)
{
    *out=*(const Pair *)((const char *)p+0x1220);
}

void func_021DC8B4(u8 *p, const W *src, int x)
{
    if (*(u32_021DC8B4 *)(p + 0x121C) != 0)
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
    *(u8 **)(p + 0x121C) = func_021B9800(x, func_0200853C((const struct Sub0200852CObj *)func_02012944(*(void **)(p + 8))), *(int *)(p + 0x10));
    *(W *)(p + 0x1228) = *src;
    *(u32_021DC8B4 *)(p + 0x12C) = 0;
}

int func_021DC908(char *p)
{
    int result;
    int status;
    u32_021DC908 *data;
    if(*(u8 **)(p+0x121c)==0) return 2;
    switch(*(u32_021DC908 *)(p+0x12c)) {
    case 0:
        if(func_021B95D4(6,*(u8 **)(p+0x121c))) {
            func_021BE79C((void *)func_021B973C(*(char **)(p+0x121c)),(void *)((u32_021DC908)(p+0x1228)),8);
            *(u32_021DC908 *)(p+0x12c)=1;
        }
        break;
    case 1:
        if(!func_021B9748(*(u8 **)(p+0x121c))) *(u32_021DC908 *)(p+0x12c)=2;
        else {
            if(*(u8 **)(p+0x121c)) {func_021B9838(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 2:
        result=func_021B99DC(*(u8 **)(p+0x121c));
        status=func_021B9790(*(u8 **)(p+0x121c));
        if(status==0) {
            data=(u32_021DC908 *)func_021B97F4(*(u8 **)(p+0x121c));
            switch(result) {
            case 0x1f7: *(u32_021DC908 *)(p+0x12c)=3;func_0200FB4C(0x3e);return 0;
            case 0x1f6: *(u32_021DC908 *)(p+0x12c)=3;func_0200FB4C(0x3f);return 0;
            default:
                if(*data==0) *(u32_021DC908 *)(p+0x12c)=4;
                else {func_0200FB4C(func_021DC610(*data));*(u32_021DC908 *)(p+0x12c)=3;}
                break;
            }
        } else if(status!=15) {
            func_021DCE58(p+0x18,status,0x16a0);
            if(*(u8 **)(p+0x121c)) {func_021B9838(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 3:
        if(*(u8 **)(p+0x121c)) {
            func_021B9774(*(u8 **)(p+0x121c));
            func_021B9838(*(u8 **)(p+0x121c));
            *(u8 **)(p+0x121c)=0;
        }
        return 3;
    case 4:
        if(*(u8 **)(p+0x121c)) {func_021B9838(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}


/*
 * Starts a profanity check of the string in window a1: copies it into the 20-character buffer at +0x1468 (the terminator code 0x02045A98 returns becomes 0), and submits it with DWC_CheckProfanityExAsync (one word, results at +0x1484/+0x1488, region 0x80).
 */
void func_021DCA28(char *obj, u32_021DCA28 win, u16 tag)
{
    u32_021DCA28 str;
    u16 *src;
    u32_021DCA28 i;

    ((struct Obj06576 *)obj)->f1490 = win;
    str = (u32_021DCA28)func_02008510((void *)win, ((struct Obj06576 *)obj)->f124);
    MI_CpuFill8(obj + 0x1468, 0, 0x28);
    ((struct Obj06576 *)obj)->f148C = tag;
    src = func_02045A90((struct U16Vec *)str);
    for (i = 0; i < func_020458F8((struct U16Vec *)str) + 1; i++) {
        u16 c = src[i];
        if (c == func_02045A98())
            *(u16 *)(obj + 0x1468 + i * 2) = 0;
        else
            *(u16 *)(obj + 0x1468 + i * 2) = c;
    }
    *(u16 * *)&((struct Obj06576 *)obj)->f1480 = (u16 *)(obj + 0x1468);
    ((struct Obj06576 *)obj)->f1488 = 0;
    DWC_CheckProfanityExAsync((u16 **)(obj + 0x1480), 1, 0, 0, obj + 0x1484, (int *)(obj + 0x1488), 0x80);
    func_02045808((struct U16Vec *)str);
}


/*
 * Polls the profanity check; once it has finished (state 2) reports whether the +0x1488 count is positive, and when it is, loads message 0x51 for the +0x124 id and hands it to the +0x1490 window.
 */
int func_021DCAEC(char *obj, int *out)
{
    int state = DWC_CheckProfanityProcess();
    int done = 1;

    if (state != 2)
        done = 0;
    if (done)
        *out = ((struct Obj10693 *)obj)->f1488 > 0 ? 1 : 0;
    if (done == 1 && *out == 1) {
        u32_021DCAEC msg = (u32_021DCAEC)func_02045B38(0, 2, 0x51, ((struct Obj10693 *)obj)->f124);
        u32_021DCAEC str = (u32_021DCAEC)func_02045EC0((struct MsgBank *)msg, 0xf);
        func_02045C04((struct Rec *)msg);
        func_020084E4((u16 *)((struct Obj10693 *)obj)->f1490, (struct U16Vec *)str);
        func_02045808((struct U16Vec *)str);
    }
    return done;
}

void func_021DCB58(char *p,void *q,int mode)
{
    int i;
    unsigned size;
    void *mon;
    i=0;
    ((struct Obj01956 *)p)->f12C=0;
    *(u8 * *)&((struct Obj01956 *)p)->f121C=func_021B9800(((struct Obj01956 *)p)->f124,(int)func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj01956 *)p)->f8)),((struct Obj01956 *)p)->f10);
    switch(mode) {
    case 0:
        func_021B98A0(*(u8 * *)&((struct Obj01956 *)p)->f121C,((struct Obj01956 *)p)->f124,func_020173EC(),0);
        func_021B98D8(*(u8 * *)&((struct Obj01956 *)p)->f121C,(int)q,func_020173EC());
        ((struct Obj01956 *)p)->f174=1;
        break;
    case 1:
        size=func_020173EC();
        func_021B98A0(*(u8 * *)&((struct Obj01956 *)p)->f121C,((struct Obj01956 *)p)->f124,size*func_0201AA18(q),0);
        for(i=0;i<(int)func_0201AA18(q);i++) {
            mon=func_0201AB28(q,i);
            func_021B98D8(*(u8 * *)&((struct Obj01956 *)p)->f121C,(int)mon,func_020173EC());
        }
        ((struct Obj01956 *)p)->f174=func_0201AA18(q);
        break;
    }
}

static inline void clear(char *p)
{
    if(*(u8 **)(p+0x121c)) {
        func_021B9838(*(u8 **)(p+0x121c));
        *(u8 **)(p+0x121c)=0;
        *(u32_021DCC28 *)(p+0x12c)=0;
    }
}

static inline void release(char *p)
{
    if(*(u8 **)(p+0x121c)) {
        func_021B99B8(*(u8 **)(p+0x121c));
        func_021B9838(*(u8 **)(p+0x121c));
        func_021B9774(*(u8 **)(p+0x121c));
        *(u8 **)(p+0x121c)=0;
        *(u32_021DCC28 *)(p+0x12c)=0;
    }
}

/*
 * blocker-C: copied verified32B Thumb EXACT from ov116_func_021D7200.c header, prior scratch blocker-1.log, dsi/1.1p1 -O4,p.
 * extern unsigned char g_0214617C[],g_021461BC[];
 * void func_0200FB4C(int a) {
 *   if(*(int *)(g_0214617C+44)!=2) {
 *     *(int *)(g_0214617C+96)=a;
 *     g_021461BC[26]=1;g_021461BC[25]=1;
 *     *(int *)(g_0214617C+44)=2;
 *   }
 * }
 * Blocker symbols: g_0214617C 0x0214617C data; g_021461BC 0x021461BC data.
 * abi: CE58 retains visibly loaded third argument despite its two-argument body; 9A14 reads live r1, the count last loaded by the loop.
 */
int func_021DCC28(char *p,u8 *out)
{
    int result;
    int status;
    u32_021DCC28 i;
    u8 *data;
    switch(*(u32_021DCC28 *)(p+0x12c)) {
    case 0:
        if(func_021B98F8(*(u8 **)(p+0x121c))) {
            if(!func_021B9748(*(u8 **)(p+0x121c))) (*(u32_021DCC28 *)(p+0x12c))++;
            else {clear(p);return 2;}
        } else {clear(p);return 2;}
        break;
    case 1:
        result=func_021B99DC(*(u8 **)(p+0x121c));
        status=func_021B9790(*(u8 **)(p+0x121c));
        if(status==0) {
            switch(result) {
            case 400: func_0200FB4C(0x41);release(p);return 3;
            case 401: func_0200FB4C(0x42);release(p);return 3;
            case 408: func_0200FB4C(0x44);release(p);return 3;
            default: func_0200FB4C(0x43);release(p);return 3;
            case 200: (*(u32_021DCC28 *)(p+0x12c))++;break;
            }
        } else if(status!=15) {
            func_021DCE58(p+0x18,status,0x17a4);
            func_021B99B8(*(u8 **)(p+0x121c));
            clear(p);
            return 2;
        }
        break;
    case 2:
        data=func_021B97F4(*(u8 **)(p+0x121c));
        *out=func_021B99F0(data);
        for(i=0;i<*(u32_021DCC28 *)(p+0x174);i++) *(u32_021DCC28 *)(out+4+i*4)=func_021B99F4((u32_021DCC28)data,i);
        if(*out==0) func_02082D44(func_021B9A14(data,*(u32_021DCC28 *)(p+0x174)),out+0x1c,128);
        func_021B99B8(*(u8 **)(p+0x121c));
        if(*(u8 **)(p+0x121c)) {func_021B9838(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}


/*
 * The +0x14 sibling of func_021DCE58: stores the caller's word at +0x18,
 *     hard-codes 5 at +0x1c and then calls 0x0203C9AC(0, 0, 0, 0x3F5).
 */
void func_021DCE08(char *ctx, u32_021DCE08 v, int line)
{
    ((struct Obj14349 *)ctx)->f18 = v;
    ((struct Obj14349 *)ctx)->f1C = 5;
    func_0203C9AC(0, 0, 0, 0x3F5);
}


/*
 * Set the word at +0 and mark the object armed at +0x1c, then start the
 * 0x3f7 service with a zeroed first three arguments.
 */
void func_021DCE24(char *p, int v, int a2)
{
    ((struct Obj14350 *)p)->f0 = v;
    ((struct Obj14350 *)p)->f1C = 1;
    func_0203C9AC(0, 0, 0, 0x3f7);
}


/*
 * Two-word setter: stores the caller's word at +4 and hard-codes 2 at +0x1c.
 */
void func_021DCE40(char *ctx, u32_021DCE40 v, int line)
{
    ((struct Obj14351 *)ctx)->f4 = v;
    ((struct Obj14351 *)ctx)->f1C = 2;
}


void func_021DCE48(char *ctx, u32_021DCE48 v, int line)
{
    ((struct Obj14352 *)ctx)->f8 = v;
    ((struct Obj14352 *)ctx)->f1C = 2;
}


/*
 * Two-word setter: stores the caller's word at +0xc and hard-codes 2 at +0x1c.
 */
void func_021DCE50(char *ctx, u32_021DCE50 v, int line)
{
    ((struct Obj14353 *)ctx)->fC = v;
    ((struct Obj14353 *)ctx)->f1C = 2;
}


/*
 * Symbols:
 *   (none)
 *
 * Two-word setter on an ov175 context block: stores the caller's word at
 * +0x14 and hard-codes 4 at +0x1c.  A leaf with no prologue, so disasm.py
 * only found it through a branch target.
 */
void func_021DCE58(char *ctx, u32_021DCE58 v, u32_021DCE58 a2)
{
    ((struct Obj14354 *)ctx)->f14 = v;
    ((struct Obj14354 *)ctx)->f1C = 4;
}


/*
 * Maps a code 0..14 to a class: 0 for code 0, 2 for codes 1 to 14; any other code asserts and yields 0.
 */
u32_021DCE60 func_021DCE60(int a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        return 2;
    case 4:
        return 2;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8:
        return 2;
    case 9:
        return 2;
    case 10:
        return 2;
    case 11:
        return 2;
    case 12:
        return 2;
    case 13:
        return 2;
    case 14:
        return 2;
    }
    func_02034714(d_021E2EF8, 0, d_021E2EF8);
    return 0;
}


/*
 * Three-level classifier: the first code decides when it can (1 or 2); codes 0 and 20 and unknown ones fall to the second, then the third; 0 when none decides.
 */
u32_021DCEE0 func_021DCEE0(int a, int b, int c)
{
    switch (a) {
    case 0:
        break;
    case 1: case 2: case 3: case 4: case 5:
        return 2;
    case 6: case 7: case 8: case 9: case 10: case 11:
    case 12: case 13: case 14: case 15: case 16:
        return 1;
    case 17: case 18:
        return 2;
    case 19:
        return 1;
    case 20:
        break;
    case 21: case 22:
        return 2;
    }
    switch (b) {
    case 0:
        return 1;
    case 1: case 2: case 3:
        break;
    case 4:
        return 2;
    }
    switch (c) {
    case 0: case 1:
        break;
    case 2:
        return 2;
    case 3:
        return 2;
    case 4:
        return 1;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8: case 9: case 10:
        return 2;
    case 11: case 12: case 13: case 14: case 15: case 16:
        return 1;
    case 17: case 18: case 19: case 20: case 21:
        return 1;
    case 22:
        return 2;
    case 23: case 24: case 25: case 26: case 27:
        return 1;
    case 28: case 29:
        return 2;
    case 30: case 31:
        return 2;
    }
    return 0;
}


/*
 * Maps 0, 1, 2 to themselves and everything else to 0.
 */
u32_021DCFDC func_021DCFDC(u32_021DCFDC v)
{
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 0;
}


/*
 * Tail call: clears the second and third arguments to 0 and 0x20 and
 *  *  hands r0 straight to 0x02082BCC (arm9); no lr save, so the call is a
 *  *  pooled `ldr r3; bx r3`.
 */
void func_021DCFFC(void *p)
{
    func_02082BCC(p, 0, 0x20);
}


void func_021DD008(char *p, int flag)
{
    if (flag == 0)
        return;
    func_0203D34C(1, ((struct Obj24396 *)p)->f124);
}


/*
 * Tail call to the arm9 Thumb routine 0x02009CC0 with the object's
 *  *  +0x04 field; pooled `ldr r3; bx r3`, so nothing is saved.
 */
u32_021DD020 func_021DD020(char *obj)
{
    return func_02009CC0((void *)(((struct Obj24397 *)obj)->f4));
}


/*
 * Returns the address of the ov175 table at 0x021E3270.
 */
char *func_021DD02C(void)
{
    return d_021E3270;
}


/*
 * Constant getter: returns 0x15.
 */
u32_021DD034 func_021DD034(void)
{
    return 0x15;
}


/*
 * Returns the address of the ov175 table at 0x021E3250.
 */
char *func_021DD038(void)
{
    return d_021E3250;
}


/*
 * Constant getter: returns 8.
 */
u32_021DD040 func_021DD040(void)
{
    return 8;
}


int func_021DD044(int a)
{
    if (a <= 0)
        return (int)g_021E32C4;
    if (a == 0x1e)
        return (int)g_021E32C8;
    if (a == 0x14)
        return (int)g_021E32E0;
    if (a == 0x15)
        return (int)g_021E32FC;
    if (a == 0x17)
        return (int)g_021E3318;
    if (a == 0x13)
        return (int)g_021E3338;
    if (a == 0x16)
        return (int)g_021E3354;
    if (a == 0x24)
        return (int)g_021E3370;
    if (a == 0x19)
        return (int)g_021E3390;
    if (a == 0x1a)
        return (int)g_021E33B0;
    if (a == 0x1c)
        return (int)g_021E33D0;
    if (a == 0x23)
        return (int)g_021E33E8;
    if (a == 0x1d)
        return (int)g_021E3400;
    if (a == 0x1f)
        return (int)g_021E3418;
    if (a == 0x20)
        return (int)g_021E3430;
    if (a == 0x21)
        return (int)g_021E3448;
    if (a == 0x1b)
        return (int)g_021E3460;
    if (a == 0x18)
        return (int)g_021E347C;
    if (a == 0x27)
        return (int)g_021E348C;
    if (a == 0x4)
        return (int)g_021E34A4;
    if (a == 0x3)
        return (int)g_021E34C0;
    if (a == 0x28)
        return (int)g_021E34D4;
    if (a == 0xb)
        return (int)g_021E34F0;
    if (a == 0xc)
        return (int)g_021E3508;
    if (a == 0xe)
        return (int)g_021E3520;
    if (a == 0xd)
        return (int)g_021E3538;
    if (a == 0x12)
        return (int)g_021E3550;
    if (a == 0x11)
        return (int)g_021E356C;
    if (a == 0xa)
        return (int)g_021E3584;
    if (a == 0x9)
        return (int)g_021E359C;
    if (a == 0x10)
        return (int)g_021E35B4;
    if (a == 0xf)
        return (int)g_021E35CC;
    if (a == 0x26)
        return (int)g_021E35E4;
    if (a == 0x25)
        return (int)g_021E3600;
    if (a == 0x22)
        return (int)g_021E3618;
    return (int)g_021E32C4;
}
