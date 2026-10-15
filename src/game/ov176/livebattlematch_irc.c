/*
 * file:     livebattlematch_irc.c
 * unit:     yes
 * function: func_0217DEA4, func_0217DEDC, func_0217DFA8, func_0217DFBC, func_0217DFD0, func_0217DFE4, func_0217DFF0, func_0217E000, func_0217E00C, func_0217E058, func_0217E074, func_0217E078, func_0217E0A8, func_0217E0B0, func_0217E158, func_0217E178, func_0217E1C0, func_0217E1FC, func_0217E23C, func_0217E258, func_0217E298, func_0217E2C0, func_0217E2F8, func_0217E318, func_0217E380, func_0217E414, func_0217E45C, func_0217E484, func_0217E4AC, func_0217E4D4, func_0217E4FC, func_0217E524
 * address:  0x0217DEA4
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * leaf: callback blocker of func_0217E0B0
 *
 * symbols:
 *   func_021E5F24 0x021E5F24 thumb ov177
 *   func_021E62CC 0x021E62CC thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E88B0 0x021E88B0 thumb ov177
 *   func_021E89D0  0x021E89D0  thumb  ov177
 *   func_021E8A00  0x021E8A00  thumb  ov177
 *   func_021E8738  0x021E8738  thumb  ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_02040588  0x02040588  arm
 *   func_021E8870 0x021E8870 thumb ov177
 *   func_02030734 0x02030734 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_0217E634 0x0217E634 data a1
 *   d_0217E544 0x0217E544 data a4
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0200FB24 0x0200FB24 thumb
 *   DELIVERY_IRC_Delete 0x02157E8C thumb ov010
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   IRCNET_SetFilter 0x021799C0 thumb ov015
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   d_0217E564 0x0217E564 data a4
 *   d_0217E630 0x0217E630 data a4
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GAME_LANGUAGE_Code 0x0209DF0C data a1
 *   func_02034714 0x02034714 arm
 *   d_0217E64C 0x0217E64C data a1
 *   DELIVERY_IRC_Create 0x02157DD8 thumb ov010
 *   DELIVERY_IRC_Main 0x02157E78 thumb ov010
 *   DELIVERY_IRC_Start 0x02157E34 thumb ov010
 *   DELIVERY_IRC_GetResult 0x02157E6C thumb ov010
 *   GFL_NET_IsIdle 0x0203D210 arm
 */
#include "../../matched/include/Obj00348.h"
#include "../../matched/include/Obj24433.h"
#include "../../matched/include/Obj10705.h"
#include "../../matched/include/Obj14368.h"
#include "../../matched/include/Obj14369.h"
#include "../../matched/include/Obj14370.h"
#include "../../matched/include/Obj08287.h"
#include "../../matched/include/Obj01957.h"
#include "../../matched/include/Obj04563.h"
#include "../../matched/include/Obj24438.h"
#include "../../matched/include/Obj24439.h"
#include "../../matched/include/Obj24440.h"
#include "../../matched/include/Obj24441.h"

struct S;
struct Req;
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f00, f04, f08, option0, option1, f14, f18, count;
    u16 f20, f22, f24, f26;
    u32 f28;
    u16 f2c, f2e;
} Menu;

typedef struct {
    unsigned a;
    unsigned short b, heap;
    unsigned c, value, byte, flags;
    unsigned pad[24];
    unsigned last;
} Config;

extern void func_021E5F24(char *,int,void *,void *,int,u16);
extern void func_021E62CC(char *p, int mode, void *mgr, void *print, int font, u32 a5);
extern void MI_CpuFill8(void *, int, u32);
extern void *func_021E88B0(Menu *, u8, u8, u8, u8, int);
extern void func_021E89D0(int);
extern int func_021E8A00(int);
extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *);
extern int func_02040588(int, int);
extern void func_021E8870(struct S *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern int DELIVERY_IRC_Delete(void *a0);
extern u32 func_0200FBB0(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void GFL_NET_StartSession(struct Req *req, unsigned int a2, unsigned int a3);
extern void IRCNET_SetFilter(int);
extern int GFL_NET_StartChangeoverChild(int a0);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void MI_CpuCopy8(void *,const void *,u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *DELIVERY_IRC_Create(u8 *p);
extern void DELIVERY_IRC_Main(u8 *p);
extern int DELIVERY_IRC_Start(void *p);
extern unsigned char DELIVERY_IRC_GetResult(char *p);
extern u32 GFL_NET_IsIdle(void);
void func_0217DEA4(int *p, int a);
void func_0217DEDC(char *p, int mode);
void func_0217DFA8(int *p);
int func_0217DFBC(int *p);
void func_0217DFD0(int *p, int a, int b);
int func_0217DFE4(int *p);
int func_0217DFF0(int a0, int b);
void func_0217E000(int *p);
void *func_0217E00C(int unused, int heap);
void func_0217E058(int *p);
void func_0217E074(void);
int func_0217E078(u8 *p);
int func_0217E0A8(int *p);
int func_0217E0B0(unsigned *p);
void func_0217E158(u32 *p);
int func_0217E178(int *p);
int func_0217E1B8(int *p);
int func_0217E1C0(int *p);
int func_0217E1FC(int unused, int arg);
int func_0217E23C(char *p, void **out);
int func_0217E258(int unused, int arg);
int func_0217E298(u8 *p,const void *q);
u32 func_0217E2C0(int unused,int a);
int func_0217E2F8(u8 *p,const void *q);
void func_0217E318(char *p, unsigned value);
int func_0217E380(char *p);
void func_0217E40C(int *p);
int func_0217E414(char *p);
void func_0217E45C(u32 a, void *b, void *c, u8 *p, struct Entry *e);
void func_0217E484(u32 a, void *b, void *c, u8 *p, struct Entry *e);
void func_0217E4AC(u32 a, void *b, void *c, u8 *p, struct Entry *e);
void func_0217E4D4(u32 a, void *b, void *c, u8 *p, struct Entry *e);
int func_0217E4FC(int a, int b);
int func_0217E524(int a, int b);
extern const char d_0217E634[];
extern const unsigned d_0217E544[];
extern const unsigned d_0217E564[];
extern int d_0217E630;
extern unsigned char GAME_LANGUAGE_Code;
extern const char d_0217E64C[];


void func_0217DEA4(int *p, int a) {if(((struct Obj00348 *)p)->f14==0)func_021E5F24(*(char * *)&((struct Obj00348 *)p)->f8,a,((struct Obj00348 *)p)->f0,((struct Obj00348 *)p)->f24,((struct Obj00348 *)p)->f1C,((struct Obj00348 *)p)->f34);else func_021E62CC(*(char * *)&((struct Obj00348 *)p)->f8,a,((struct Obj00348 *)p)->f0,((struct Obj00348 *)p)->f24,((struct Obj00348 *)p)->f1C,((struct Obj00348 *)p)->f34);}


/*
 * E88B0 returns its allocated record; original call truncates four coordinates to bytes.
 */
void func_0217DEDC(char *p, int mode)
{
    Menu rec;
    int layout, x, y, width, height;
    if (*(int *)&((struct Obj00348 *)p)->fC == 0) {
        MI_CpuFill8(&rec, 0, 0x30);
        rec.f00 = *(u32 *)&((struct Obj00348 *)p)->f0;
        rec.f04 = *(u32 *)&((struct Obj00348 *)p)->f1C;
        rec.f08 = *(u32 *)&((struct Obj00348 *)p)->f24;
        rec.f20 = 0; rec.f22 = 15; rec.f24 = 13; rec.f26 = 1;
        switch (mode) {
        case 0:
            rec.option0 = 0x76; rec.option1 = 0x77; rec.count = 2;
            rec.f28 = 1; rec.f2c = 1; layout = 0; rec.f2e = 1; break;
        case 1:
            rec.option0 = 0x74; rec.count = 1; rec.f28 = 1; rec.f2c = 0;
            layout = 0; break;
        case 2:
            rec.option0 = 0x75; rec.option1 = 0x74; rec.count = 2;
            rec.f28 = 1; rec.f2c = 1; layout = 1; rec.f2e = 1; break;
        }
        switch (layout) {
        case 0: height = rec.count * 2; width = 12; x = 19; y = 17 - height; break;
        case 1: height = rec.count * 2; width = 15; x = 16; y = 17 - height; break;
        }
        ((struct Obj00348 *)p)->fC = func_021E88B0(&rec, x, y, width, height, ((struct Obj00348 *)p)->f34);
    }
}



void func_0217DFA8(int *p)
{
    if (*(int *)&((struct Obj00348 *)p)->fC) {
        func_021E89D0(*(int *)&((struct Obj00348 *)p)->fC);
        *(int *)&((struct Obj00348 *)p)->fC = 0;
    }
}



int func_0217DFBC(int *p)
{
    if (*(int *)&((struct Obj00348 *)p)->fC)
        return func_021E8A00(*(int *)&((struct Obj00348 *)p)->fC);
    return -1;
}



void func_0217DFD0(int *p, int a, int b)
{
    func_021E8738((int *)(*(int *)&((struct Obj00348 *)p)->f18), *(int *)&((struct Obj00348 *)p)->f0, a, b);
}


int func_0217DFE4(int *p) {return func_021E8844(*(int * *)&((struct Obj00348 *)p)->f18);}



/*
 * Extent runs long: 0x0217E000 is an unlabelled follower leaf, so EXACT*.
 */
int func_0217DFF0(int a0, int b)
{
    return func_02040588(0, (unsigned char)b);
}


/*
 * Unlabelled blocker leaf for DA38 and DB0C; parent confirmed unowned.
 */
void func_0217E000(int *p)
{
    func_021E8870((struct S *)p[6]);
}


void *func_0217E00C(int unused, int heap)
{
    char *p = func_02030734(heap, 0x1020, 0, d_0217E634, 0x8E);
    MI_CpuFill8(p, 0, 0x1020);
    ((struct Obj24433 *)p)->f4 = heap;
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_AddCommandTable(0x1F00, (u32)d_0217E544, 4, (u32)p);
    return p;
}



void func_0217E058(int *p)
{
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_DeleteCommandTable(0x1f00);
    func_020307B0(p);
}


void func_0217E074(void) {}


int func_0217E078(u8 *p) {if(func_0200FB24()!=0) {if(((struct Obj10705 *)p)->f1018!=0) {DELIVERY_IRC_Delete((void *)(((struct Obj10705 *)p)->f1018));((struct Obj10705 *)p)->f1018=0;}func_0200FBB0();GFL_NET_ERR_ShowSimpleScreen();return 1;}return 0;}


int func_0217E0A8(int *p){*p=0;return 1;}


int func_0217E0B0(unsigned *p)
{
    switch (*p) {
    case 0:
        GFL_NET_StartSession((struct Req *)d_0217E564, 0, 0);
        d_0217E630 = 1;
        *p = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState())
            *p = 2;
        break;
    case 2:
        GFL_NET_COMMAND_AddCommandTable(0x1F00, (u32)d_0217E544, 4, (u32)p);
        IRCNET_SetFilter((int)func_0217E524);
        *p = 3;
        break;
    case 3:
        GFL_NET_StartChangeoverChild(0);
        *p = 4;
        break;
    case 4:
        if (GFL_NET_GetNegotiationNum() > 1)
            *p = 5;
        if (d_0217E630 == 0)
            *p = 6;
        break;
    case 5:
        IRCNET_SetFilter(0);
        return 1;
    case 6:
        IRCNET_SetFilter(0);
        return 2;
    }
    return 0;
}


void func_0217E158(u32 *p) {int n;if(*p>=2)GFL_NET_COMMAND_DeleteCommandTable(0x1f00);n=0;IRCNET_SetFilter(0);*p=n;}


int func_0217E178(int *p)
{
    switch (*p) {
    case 0:
        if (GFL_NET_GetRunState()) {
            GFL_NET_Exit(0);
            *p = 1;
        } else {
            *p = 2;
        }
        break;
    case 1:
        if (GFL_NET_IsSessionNull())
            *p = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}


int func_0217E1B8(int *p) { *p = 0; return 1; }


int func_0217E1C0(int *p) {switch(*p) {case 0:GFL_NET_COMMAND_DeleteCommandTable(0x1f00);GFL_NET_Exit(0);*p=1;break;case 1:if(GFL_NET_IsSessionNull())*p=2;break;case 2:return 1;}return 0;}


/*
 * extent: remaining code is the separate leaf func_0217E23C
 */
int func_0217E1FC(int unused, int arg)
{
    int flag;
    int obj;
    unsigned n;
    int r;
    r = GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));
    flag = 1;
    if (r != 0)
        flag = 0;
    obj = (int)GFL_NET_HANDLE_GetCurrentHandle();
    n = POKE_REGULATION_GetDataSize();
    return GFL_NET_SendData((int)obj, (unsigned char)flag, (int)0x1F00, n + 0xD4, (int)arg, (int)1, (int)1, (int)1);
}


/*
 * leaf: follower of func_0217E1FC
 */
int func_0217E23C(char *p, void **out)
{
    int value = ((struct Obj14368 *)p)->f1008;
    if (value) {
        ((struct Obj14368 *)p)->f1008 = 0;
        *out = p + 6;
    }
    return value;
}


int func_0217E258(int unused, int arg)
{
    int flag;
    int obj;
    unsigned n;
    int r;
    r = GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));
    flag = 1;
    if (r != 0)
        flag = 0;
    obj = (int)GFL_NET_HANDLE_GetCurrentHandle();
    n = POKE_REGULATION_GetDataSize();
    return GFL_NET_SendData((int)obj, (unsigned char)flag, (int)0x1F01, n, (int)arg, (int)1, (int)1, (int)1);
}


int func_0217E298(u8 *p,const void *q) {int v;v=((struct Obj14369 *)p)->f100C;if(v) {((struct Obj14369 *)p)->f100C=0;MI_CpuCopy8(p+6,q,POKE_REGULATION_GetDataSize());}return v;}


u32 func_0217E2C0(int unused,int a) {int flag;int v;v=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));flag=1;if(v!=0)flag=0;return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(),(u8)flag,0x1f03,4,(int)a,(int)1,(int)1,(int)1);}


int func_0217E2F8(u8 *p,const void *q) {int v;v=((struct Obj14370 *)p)->f1014;if(v) {((struct Obj14370 *)p)->f1014=0;MI_CpuCopy8(p+6,q,4);}return v;}


void func_0217E318(char *p, unsigned value)
{
    Config config;
    MI_CpuFill8(&config, 0, 0x7C);
    config.a = 0x30;
    config.c = 0x160;
    config.value = value;
    config.b = 0;
    config.heap = ((struct Obj08287 *)p)->f4;
    config.byte = GAME_LANGUAGE_Code;
    config.flags = 0x200000;
    config.last = 1;
    if (((struct Obj08287 *)p)->f1018)
        func_02034714(d_0217E64C, 0, d_0217E64C);
    ((struct Obj08287 *)p)->f1018 = DELIVERY_IRC_Create((u8 *)(&config));
    ((struct Obj08287 *)p)->f0 = 0;
}


/*
 * extent: two alignment bytes follow func_0217E40C
 */
int func_0217E380(char *p)
{
    if (((struct Obj01957 *)p)->f1018)
        DELIVERY_IRC_Main(((struct Obj01957 *)p)->f1018);
    switch (((struct Obj01957 *)p)->f0) {
    case 0:
        DELIVERY_IRC_Start(((struct Obj01957 *)p)->f1018);
        (((struct Obj01957 *)p)->f0)++;
        break;
    case 1:
        ((struct Obj01957 *)p)->f101C = DELIVERY_IRC_GetResult(((struct Obj01957 *)p)->f1018);
        if (((struct Obj01957 *)p)->f101C)
            (((struct Obj01957 *)p)->f0)++;
        break;
    case 2:
        DELIVERY_IRC_Delete((void *)(((struct Obj01957 *)p)->f1018));
        ((struct Obj01957 *)p)->f1018 = 0;
        (((struct Obj01957 *)p)->f0)++;
        break;
    case 3:
        if (GFL_NET_IsIdle()) {
            switch (((struct Obj01957 *)p)->f101C) {
            case 1: return 1;
            case 3: return 3;
            case 2: break;
            }
            return 2;
        }
        break;
    }
    return 0;
}


void func_0217E40C(int *p) { *p = 0; }


int func_0217E414(char *p)
{
    if (((struct Obj04563 *)p)->f1018)
        DELIVERY_IRC_Main(((struct Obj04563 *)p)->f1018);
    switch (((struct Obj04563 *)p)->f0) {
    case 0:
        if (((struct Obj04563 *)p)->f1018) {
            DELIVERY_IRC_Delete((void *)(((struct Obj04563 *)p)->f1018));
            ((struct Obj04563 *)p)->f1018 = 0;
        }
        (((struct Obj04563 *)p)->f0)++;
        break;
    case 1:
        if (GFL_NET_IsIdle())
            return 1;
        break;
    }
    return 0;
}


void func_0217E45C(u32 a, void *b, void *c, u8 *p, struct Entry *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            ((struct Obj24438 *)p)->f1008 = 1;
    }
}


void func_0217E484(u32 a, void *b, void *c, u8 *p, struct Entry *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            ((struct Obj24439 *)p)->f100C = 1;
    }
}


void func_0217E4AC(u32 a, void *b, void *c, u8 *p, struct Entry *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            ((struct Obj24440 *)p)->f1010 = 1;
    }
}


void func_0217E4D4(u32 a, void *b, void *c, u8 *p, struct Entry *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            ((struct Obj24441 *)p)->f1014 = 1;
    }
}



int func_0217E4FC(int a, int b)
{
    if (a == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        func_02034714(d_0217E64C, 0, d_0217E64C);
        return 0;
    }
    return b + 6;
}

int func_0217E524(int a, int b) { int value = a == b; d_0217E630 = value; return value; }
