/*
 * file:     script_command_p04.c
 * unit:     yes
 * function: func_021FAAF4, func_021FAB58, func_021FABD8, func_021FAC74, func_021FAD0C, func_021FAD2C, func_021FAD7C, func_021FADA0, func_021FADF8, func_021FAE1C, func_021FAE4C, func_021FAEA8, func_021FAEE8, func_021FAF1C, func_021FAF28, func_021FAF38, func_021FAF54, func_021FAF70, func_021FAFDC, func_021FB050, func_021FB0DC, func_021FB104, func_021FB190, func_021FB1C0, func_021FB1CC, func_021FB1E4, func_021FB1F4, func_021FB208, func_021FB258, func_021FB2B0, func_021FB3E0, func_021FB528, func_021FB55C, func_021FB5A4
 * address:  0x021FAAF4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02060468 0x02060468 arm
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 *   func_02011290 0x02011290 thumb
 *   func_02011264 0x02011264 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02060614 0x02060614 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_021F9E44 0x021F9E44 thumb ov132
 *   func_02030D28 0x02030D28 arm
 *   func_0201121C 0x0201121C thumb
 *   func_0201126C 0x0201126C thumb
 *   func_0201127C 0x0201127C thumb
 *   d_021FDC2C 0x021FDC2C data ov132 a4
 *   func_02011298 0x02011298 thumb
 *   func_02030DA8 0x02030DA8 arm
 *   func_020604AC 0x020604AC arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020605B4 0x020605B4 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 *   func_021F96D0 0x021F96D0 thumb ov132
 *   func_021F9E00 0x021F9E00 thumb ov132
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F9E08 0x021F9E08 thumb ov132
 *   func_021F9E40 0x021F9E40 thumb ov132
 *   func_021F9D80  0x021F9D80  thumb
 *   func_021F9AD8  0x021F9AD8  thumb
 *   func_021F9D90  0x021F9D90  thumb
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F80D4 0x021F80D4 thumb ov112
 *   func_021F812C 0x021F812C thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_0207CA00 0x0207CA00 arm
 *   func_021F80B0 0x021F80B0 thumb ov112
 *   func_021F80A0 0x021F80A0 thumb ov112
 */
#include "../../matched/include/Obj05398.h"
#include "../../matched/include/Obj14093.h"
#include "../../matched/include/Obj23230.h"
#include "../../matched/include/Obj23231.h"
#include "../../matched/include/Obj23232.h"
#include "../../matched/include/Obj23233.h"
#include "../../matched/include/Obj10540.h"
#include "../../matched/include/Obj14094.h"
#include "../../matched/include/Obj23234.h"
#include "../../matched/include/Obj23235.h"
#include "../../matched/include/Obj01157.h"
#include "../../matched/include/Obj23236.h"
#include "../../matched/include/Obj23237.h"
#include "../../matched/include/Obj23238.h"
#include "../../matched/include/Obj23239.h"
#include "../../matched/include/Obj23240.h"
#include "../../matched/include/Obj23241.h"
#include "../../matched/include/Obj23242.h"
#include "../../matched/include/Obj23243.h"
#include "../../matched/include/Obj23245.h"
#include "../../matched/include/Obj23246.h"
#include "../../matched/include/Obj23247.h"
#include "../../matched/include/Obj23248.h"
#include "../../matched/include/Obj10541.h"
#include "../../matched/include/Obj02485.h"
#include "../../matched/include/Obj10542.h"
#include "../../matched/include/Obj14095.h"
#include "../../matched/include/Obj14096.h"
#include "../../matched/include/Obj03818.h"
#include "../../matched/include/Obj03288.h"
#include "../../matched/include/Obj06489.h"
#include "../../matched/include/Obj05400.h"
#include "../../matched/include/Obj14098.h"
#include "../../matched/include/Obj23249.h"
#include "../../matched/include/Obj14099.h"
#include "../../matched/include/Obj08157.h"
#include "../../matched/include/Obj10543.h"
#include "../../matched/include/Obj03289.h"
#include "../../matched/include/Obj10544.h"
#include "../../matched/include/Obj10545.h"
#include "../../matched/include/Obj02850.h"
#include "../../matched/include/Obj08158.h"
#include "../../matched/include/Obj10546.h"
#include "../../matched/include/Obj03819.h"
#include "../../matched/include/Obj06490.h"
#include "../../matched/include/Obj08159.h"
#include "../../matched/include/Obj10547.h"
#include "../../matched/include/Obj03820.h"
#include "../../matched/include/Obj06491.h"
#include "../../matched/include/Obj08160.h"
#include "../../matched/include/Obj08161.h"
#include "../../matched/include/Obj23250.h"
#include "../../matched/include/Obj14100.h"
#include "../../matched/include/Obj23253.h"
#include "../../matched/include/Obj23254.h"
#include "../../matched/include/Obj10548.h"
#include "../../matched/include/Obj14101.h"
#include "../../matched/include/Obj10549.h"
#include "../../matched/include/Obj14102.h"
#include "../../matched/include/Obj02192.h"
#include "../../matched/include/Obj03821.h"
#include "../../matched/include/Obj08162.h"
#include "../../matched/include/Obj08163.h"
#include "../../matched/include/Obj14103.h"
#include "../../matched/include/Obj14104.h"
#include "../../matched/include/Obj14105.h"
#include "../../matched/include/Obj14106.h"

struct Ctx;
struct ScriptVm;
struct DList;
struct ScriptVmParams;
struct Node;
struct Cursor;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

typedef struct {int x,y,z;} Vec;

typedef enum { COORD_ZERO } Coord;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02060468(int p0, int p1);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void func_02011264(void *);
extern u32 func_020307B0(void *p);
extern void *func_02060614(struct DList *list, void *elem);
extern void func_02030DA4(void *);
extern u32 func_021F9E44(u8 *p);
extern void func_02030D28(struct Ctx *c);
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern int func_02011298(struct ScriptVm *vm);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern void func_020604AC(void *, void *);
extern void func_02030EAC(struct Node *n);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_0207CEE4(int, void *, void *, void *);
extern void *func_021F9DA0(char *p);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_0207C9D0(void *, void *, void *);
extern u32 func_0201134C(struct Cursor *p);
extern u16 func_021F9DFC(void *);
extern void func_021F96D0(char *p);
extern void func_021F9E00(void *, u16);
extern u16 func_021F9E04(u8 *p);
extern void func_021F9E08(u8 *p, u16 v);
extern void func_021F9E40(u8 *p, u32 v);
extern void func_021F9D80(char *p);
extern void func_021F9AD8(char *p, int mode, u8 slot);
extern void func_021F9D90(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void func_021F80D4(char *, char *, int);
extern int func_021F812C(int unused, int *p, int flag);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern void func_0207CA00(void *,void *,void *);
extern void func_021F80B0(char *, char *);
extern void func_021F80A0(int a, u8 *p);
void *func_021FAAF4(u32 heap, void *owner);
void func_021FAB58(char *p);
void func_021FABD8(char *p);
void *func_021FAC74(char *p, void *arg, int flag);
char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag);
int func_021FAD2C(void *unused, char *p);
u8 func_021FAD7C(char *p);
void *func_021FADA0(char *p, u32 fn, u32 arg, u32 key);
void func_021FADF8(char *p, char *q);
int func_021FAE1C(char *p, int *out);
int func_021FAE4C(char *p, int *out);
int func_021FAEA8(char *p, void *out);
int func_021FAEE8(char *p);
int func_021FAF10(void *unused, char *p);
int func_021FAF1C(void *a, char *p);
int func_021FAF28(void *a, u8 *p);
int func_021FAF38(void *a, u8 *p);
int func_021FAF54(int a, char *b);
int func_021FAF70(void *unused, char *ctx);
int func_021FAFDC(void *unused, char *ctx);
int func_021FB050(void *unused, char *ctx);
void func_021FB0DC(void *unused, char *p);
int func_021FB104(void *unused, char *ctx);
void func_021FB190(void *unused, char *p);
int func_021FB1C0(void *unused,char *p);
int func_021FB1CC(int a, char **pp);
int func_021FB1E4(void *a, void **pp);
int func_021FB1F4(char *p, int i);
int func_021FB208(int unused, char *p);
int func_021FB258(int unused, char *p);
int func_021FB2B0(int unused,char *p);
int func_021FB3E0(int unused,char *p);
void func_021FB528(int unused,char *p);
int func_021FB55C(int unused, char *p);
int func_021FB5A4(int unused, char *p);
extern char d_021FDCEC[];
extern char d_021FDC2C[];
extern char d_021FDD00[];

void *func_021FAAF4(u32 heap, void *owner)
{
    u8 i;
    char *p;
    i = 0;
    p = func_02030734(heap, 0x44, 0, d_021FDCEC, 0x3f);
    ((struct Obj05398 *)p)->f0 = heap;
    ((struct Obj05398 *)p)->f34 = owner;
    ((struct Obj05398 *)p)->f8 = func_02030734(((struct Obj05398 *)p)->f0, func_02030CB0(16), 0, d_021FDCEC, 0x43);
    ((struct Obj05398 *)p)->f4 = func_02030CBC(16, ((struct Obj05398 *)p)->f8);
    func_02060468((int)(p + 0x38), 0);
    for (; i < 10; i++) *(void **)(p + 0xc + i * 4) = 0;
    return p;
}

void func_021FAB58(char *p)
{
    u8 i;
    char **slot;
    void *cur;
    void *next;
    for (i = 0; i < 10; i++) {
        slot = (char **)(p + i * 4);
        if (slot[3] != 0) {
            func_02011290(((struct Obj23230 *)(slot[3]))->f4);
            func_02011264(((struct Obj23231 *)(slot[3]))->f4);
            if (((struct Obj23232 *)(slot[3]))->f16 & 8) func_020307B0(((struct Obj23233 *)(slot[3]))->fC);
            func_020307B0(slot[3]);
            slot[3] = 0;
        }
    }
    cur = func_02060614((struct DList *)(p + 0x38), 0);
    while (cur != 0) {
        next = func_02060614((struct DList *)(p + 0x38), cur);
        func_021FADF8(p, cur);
        cur = next;
    }
    func_02030DA4(((struct Obj14093 *)p)->f4);
    func_020307B0(((struct Obj14093 *)p)->f8);
    func_020307B0(p);
}

/*
 * note: two bytes of zero padding follow the epilogue before 021FAC74.
 */
void func_021FABD8(char *p)
{
    char **slot;
    u8 i;
    int ready;
    int count;
    ready = 1;
    count = func_021F9E44(((struct Obj14094 *)p)->f34);
    while (count != 0) {
        for (i = 0; i < 10; i++) {
            slot = (char **)(p + i * 4);
            if (slot[3] != 0) {
                if (func_021FAD2C(p, slot[3]) == 1) {
                    func_020307B0(slot[3]);
                    slot[3] = 0;
                } else {
                    if ((((struct Obj23234 *)(slot[3]))->f16 & 2) && !(((struct Obj23235 *)(slot[3]))->f16 & 4)) ready = 0;
                }
            }
        }
        if (ready == 1) {
            for (i = 0; i < 10; i++) {
                char *q;
                q = *(char **)(p + 0xc + i * 4);
                if (q != 0 && (((struct Obj10540 *)q)->f16 & 2) && (((struct Obj10540 *)q)->f16 & 4)) ((struct Obj10540 *)q)->f16 ^= 4;
            }
        }
        func_02030D28(((struct Obj14094 *)p)->f4);
        count--;
    }
}

void *func_021FAC74(char *p, void *arg, int flag)
{
    u8 i;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) == 0) break;
    ((char **)(p + 0xc))[i] = func_02030734(((struct Obj01157 *)p)->f0, 0x1c, 0, d_021FDCEC, 0xc4);
    ((struct Obj23236 *)(((char **)(p + 0xc))[i]))->f8 = arg;
    ((struct Obj23237 *)(((char **)(p + 0xc))[i]))->fC = 0;
    ((struct Obj23238 *)(((char **)(p + 0xc))[i]))->f14 = 0;
    ((struct Obj23239 *)(((char **)(p + 0xc))[i]))->f10 = 0;
    ((struct Obj23240 *)(((char **)(p + 0xc))[i]))->f16 = 0;
    ((struct Obj23241 *)(((char **)(p + 0xc))[i]))->f18 = 0;
    ((struct Obj23242 *)(((char **)(p + 0xc))[i]))->f19 = i;
    if (flag == 1) ((struct Obj23243 *)(((char **)(p + 0xc))[i]))->f16 |= 2;
    *(char **)((char **)(p + 0xc))[i] = p;
    ((struct Obj23245 *)(((char **)(p + 0xc))[i]))->f4 = func_0201121C(((struct Obj01157 *)p)->f0, (const struct ScriptVmParams *)d_021FDC2C);
    func_0201126C(((struct Obj23246 *)(((char **)(p + 0xc))[i]))->f4, ((char **)(p + 0xc))[i]);
    func_0201127C(((struct Obj23247 *)(((char **)(p + 0xc))[i]))->f4, ((struct Obj23248 *)(((char **)(p + 0xc))[i]))->f8);
    return ((char **)(p + 0xc))[i];
}

char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag)
{
    char *q = func_021FAC74(p, base + *(unsigned *)(base + index * 4), 0);
    *(char * *)&((struct Obj10541 *)q)->fC = base;
    ((struct Obj10541 *)q)->f16 |= 8;
    ((struct Obj10541 *)q)->f18 = flag;
    return q;
}

int func_021FAD2C(void *unused, char *p)
{
    if (((struct Obj02485 *)p)->f14 != 0) (((struct Obj02485 *)p)->f14)--;
    if (((struct Obj02485 *)p)->f14 == 0 && !(((struct Obj02485 *)p)->f16 & 4)) {
        func_02011298(((struct Obj02485 *)p)->f4);
        if (((struct Obj02485 *)p)->f16 & 1) {
            func_02011290(((struct Obj02485 *)p)->f4);
            func_02011264(((struct Obj02485 *)p)->f4);
            if (((struct Obj02485 *)p)->f16 & 8) func_020307B0(((struct Obj02485 *)p)->fC);
            return 1;
        }
    }
    (((struct Obj02485 *)p)->f10)++;
    return 0;
}

/*
 * note: unlabelled follower in 021FAD2C extent; counts ten nonnull slots.
 */
u8 func_021FAD7C(char *p)
{
    u8 i;
    u8 count;
    count = 0;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) != 0) count++;
    return count;
}

void *func_021FADA0(char *p, u32 fn, u32 arg, u32 key)
{
    char *q;
    q = func_02030734(((struct Obj14095 *)p)->f0, 16, 0, d_021FDCEC, 0x115);
    ((struct Obj10542 *)q)->fC = func_02030DA8(((struct Obj14095 *)p)->f4, fn, arg, key);
    if (((struct Obj10542 *)q)->fC != 0) {
        ((struct Obj10542 *)q)->f8 = arg;
        func_020604AC(p + 0x38, q);
        return q;
    }
    func_020307B0(q);
    return 0;
}

void func_021FADF8(char *p, char *q)
{
    func_020307B0(((struct Obj14096 *)q)->f8);
    func_02030EAC(((struct Obj14096 *)q)->fC);
    func_020605B4((volatile struct DList *)(p + 0x38), q);
    func_020307B0(q);
}


int func_021FAE1C(char *p, int *out)
{
    int start;
    int delta;
    ((struct Obj03818 *)p)->fE += 1;
    if (((struct Obj03818 *)p)->fE >= ((struct Obj03818 *)p)->fC) {
        *out = ((struct Obj03818 *)p)->f8;
        return 1;
    }
    start = ((struct Obj03818 *)p)->f4;
    delta = ((struct Obj03818 *)p)->f8 - start;
    *out = start + (delta * ((struct Obj03818 *)p)->fE) / ((struct Obj03818 *)p)->fC;
    return 0;
}

int func_021FAE4C(char *p, int *out)
{
    int v;
    (((struct Obj03288 *)p)->f2A)++;
    if (((struct Obj03288 *)p)->f2A >= ((struct Obj03288 *)p)->f28) {
        out[0] = ((struct Obj03288 *)p)->f10;
        out[1] = ((struct Obj03288 *)p)->f14;
        out[2] = ((struct Obj03288 *)p)->f18;
        return 1;
    }
    if (((struct Obj03288 *)p)->f2A != 0) v = (int)(0.5f + (float)(((struct Obj03288 *)p)->f2A << 12));
    else v = (int)((float)(((struct Obj03288 *)p)->f2A << 12) - 0.5f);
    func_0207CEE4(v, p + 0x1c, p + 4, out);
    return 0;
}

/*
 * note: extent ends with two bytes of zero alignment padding.
 */
int func_021FAEA8(char *p, void *out)
{
    int v[3];
    func_021F8044(func_021F9DA0(((struct Obj06489 *)p)->f0), (u32 *)(((struct Obj06489 *)p)->f4), (u32 *)v);
    func_0207C9D0(v, p + 8, out);
    (((struct Obj06489 *)p)->f16)++;
    if (((struct Obj06489 *)p)->f16 >= ((struct Obj06489 *)p)->f14) return 1;
    return 0;
}


/*
 * follower: func_021FAF10 at 0x021FAF10
 */
int func_021FAEE8(char *p)
{
    ((struct Obj05400 *)p)->f4 += 1;
    if (((struct Obj05400 *)p)->f4 >= ((struct Obj05400 *)p)->f8) {
        ((struct Obj05400 *)p)->fC -= 1;
        ((struct Obj05400 *)p)->f4 = 0;
        if (((struct Obj05400 *)p)->fC == 0) return 2;
        return 1;
    }
    return 0;
}


int func_021FAF10(void *unused, char *p)
{
    ((struct Obj14098 *)p)->f16 = 1 | ((struct Obj14098 *)p)->f16;
    return 1;
}

int func_021FAF1C(void *a, char *p)
{
    func_0201134C(((struct Obj23249 *)p)->f4);
    return 0;
}


/*
 * blocker resolved: func_0201134C was matched in arm9 (src/matched/
 * func_0201134C.c, shard pkt_0201134C); the +0006 call now attests as
 * `matched`.  The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * Addresses are Black-image addresses.
 */
int func_021FAF28(void *a, u8 *p)
{
    ((struct Obj14099 *)p)->f14 = (u16)func_0201134C(((struct Obj14099 *)p)->f4);
    return 1;
}


/*
 * blocker resolved: func_0201134C was matched in arm9 (src/matched/
 * func_0201134C.c, shard pkt_0201134C); the call now attests as `matched`.
 * The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * Addresses are Black-image addresses.
 */
int func_021FAF38(void *a, u8 *p)
{
    int v = func_0201134C(((struct Obj08157 *)p)->f4);
    if (((struct Obj08157 *)p)->f10 >= (u32)v)
        return 0;
    ((struct Obj08157 *)p)->f14 = (u16)(v - ((struct Obj08157 *)p)->f10);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021FAF54(int a, char *b)
{
    func_0201134C(((struct Obj10543 *)b)->f4);
    if (((struct Obj10543 *)b)->f16 & 2)
        ((struct Obj10543 *)b)->f16 |= 4;
    return 1;
}

int func_021FAF70(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct Obj10544 *)ctx)->f0;
    wait = func_0201134C(((struct Obj10544 *)ctx)->f4);
    p = func_02030734(((struct Obj10545 *)owner)->f0, 0x18, 0, d_021FDD00, 0x1a4);
    *(char * *)&((struct Obj03289 *)p)->f10 = owner;
    ((struct Obj03289 *)p)->f0 = ((struct Obj10545 *)owner)->f34;
    ((struct Obj03289 *)p)->fE = 0;
    ((struct Obj03289 *)p)->f4 = func_021F9DFC(((struct Obj10545 *)owner)->f34);
    ((struct Obj03289 *)p)->f8 = 224;
    delta = 224 - ((struct Obj03289 *)p)->f4;
    if (delta < 0) delta = -delta;
    ((struct Obj03289 *)p)->fC = delta / 2;
    ((struct Obj03289 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
    if (wait == 1) {
        ((struct Obj10544 *)ctx)->f14 = ((struct Obj03289 *)p)->fC;
        return 1;
    }
    return 0;
}

int func_021FAFDC(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct Obj10546 *)ctx)->f0;
    wait = func_0201134C(((struct Obj10546 *)ctx)->f4);
    p = func_02030734(((struct Obj08158 *)owner)->f0, 0x18, 0, d_021FDD00, 0x1c1);
    *(char * *)&((struct Obj02850 *)p)->f10 = owner;
    ((struct Obj02850 *)p)->f0 = ((struct Obj08158 *)owner)->f34;
    ((struct Obj02850 *)p)->fE = 0;
    ((struct Obj02850 *)p)->f4 = func_021F9DFC(((struct Obj08158 *)owner)->f34);
    ((struct Obj02850 *)p)->f8 = 0;
    delta = ((struct Obj02850 *)p)->f8 - ((struct Obj02850 *)p)->f4;
    if (delta < 0) delta = -delta;
    ((struct Obj02850 *)p)->fC = delta / 2;
    ((struct Obj02850 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
    func_021F96D0(((struct Obj08158 *)owner)->f34);
    if (wait == 1) {
        ((struct Obj10546 *)ctx)->f14 = ((struct Obj02850 *)p)->fC;
        return 1;
    }
    return 0;
}

int func_021FB050(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct Obj06490 *)ctx)->f0;
    time = func_0201134C(((struct Obj06490 *)ctx)->f4);
    target = func_0201134C(((struct Obj06490 *)ctx)->f4);
    wait = func_0201134C(((struct Obj06490 *)ctx)->f4);
    if (time == 0) {
        func_021F9E00(((struct Obj08159 *)owner)->f34, target);
    } else {
        p = func_02030734(((struct Obj08159 *)owner)->f0, 0x18, 0, d_021FDD00, 0x1e9);
        *(char * *)&((struct Obj03819 *)p)->f10 = owner;
        ((struct Obj03819 *)p)->f0 = ((struct Obj08159 *)owner)->f34;
        ((struct Obj03819 *)p)->fE = 0;
        ((struct Obj03819 *)p)->f4 = func_021F9DFC(((struct Obj08159 *)owner)->f34);
        ((struct Obj03819 *)p)->f8 = target;
        ((struct Obj03819 *)p)->fC = time;
        ((struct Obj03819 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
        if (wait == 1) {
            ((struct Obj06490 *)ctx)->f14 = ((struct Obj03819 *)p)->fC;
            return 1;
        }
    }
    return 0;
}

void func_021FB0DC(void *unused, char *p)
{
    int v;
    int done = func_021FAE1C(p, &v);
    func_021F9E00(((struct Obj10547 *)p)->f0, v);
    if (done == 1) func_021FADF8(*(char * *)&((struct Obj10547 *)p)->f10, *(char * *)&((struct Obj10547 *)p)->f14);
}

int func_021FB104(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct Obj06491 *)ctx)->f0;
    time = func_0201134C(((struct Obj06491 *)ctx)->f4);
    target = func_0201134C(((struct Obj06491 *)ctx)->f4);
    wait = func_0201134C(((struct Obj06491 *)ctx)->f4);
    if (time == 0) {
        func_021F9E08(((struct Obj08160 *)owner)->f34, target);
    } else {
        p = func_02030734(((struct Obj08160 *)owner)->f0, 0x18, 0, d_021FDD00, 0x225);
        *(char * *)&((struct Obj03820 *)p)->f10 = owner;
        ((struct Obj03820 *)p)->f0 = ((struct Obj08160 *)owner)->f34;
        ((struct Obj03820 *)p)->fE = 0;
        ((struct Obj03820 *)p)->f4 = func_021F9E04(((struct Obj08160 *)owner)->f34);
        ((struct Obj03820 *)p)->f8 = target;
        ((struct Obj03820 *)p)->fC = time;
        ((struct Obj03820 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB190, (u32)p, 10);
        if (wait == 1) {
            ((struct Obj06491 *)ctx)->f14 = ((struct Obj03820 *)p)->fC;
            return 1;
        }
    }
    return 0;
}

void func_021FB190(void *unused, char *p)
{
    int v;
    int done = func_021FAE1C(p, &v);
    func_021F9E08(((struct Obj08161 *)p)->f0, v);
    if (done == 1) {
        func_021F9E40(((struct Obj08161 *)p)->f0, 0);
        func_021FADF8(*(char * *)&((struct Obj08161 *)p)->f10, *(char * *)&((struct Obj08161 *)p)->f14);
    }
}

int func_021FB1C0(void *unused,char *p) { func_0201134C(*(struct Cursor * *)&((struct Obj23250 *)p)->f4); return 0; }


int func_021FB1CC(int a, char **pp)
{
    char *p = *pp;

    func_021F9D80(((struct Obj14100 *)p)->f34);
    func_021F9AD8(((struct Obj14100 *)p)->f34, 0, 0);
    return 0;
}


int func_021FB1E4(void *a, void **pp)
{
    func_021F9D90(((struct Obj23253 *)((u8 *)*pp))->f34);
    return 0;
}


int func_021FB1F4(char *p, int i)
{
    if (i == -1)
        return ((struct Obj23254 *)p)->f18;
    return 1 << i;
}

int func_021FB208(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    int value;
    u8 i;
    obj = *(char * *)&((struct Obj10548 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj10548 *)p)->f4));
    value = func_0201134C(((struct Obj10548 *)p)->f4);
    ctx = func_021F9DA0(((struct Obj14101 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80D4(ctx, func_021F9DA4(((struct Obj14101 *)obj)->f34, i), value);
        }
    }
    return 0;
}

/*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 */
int func_021FB258(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj10549 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj10549 *)p)->f4));
    value = func_0201134C(((struct Obj10549 *)p)->f4);
    ctx = func_021F9DA0(((struct Obj14102 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            char *slot;
            int flag;
            slot = func_021F9DA4(((struct Obj14102 *)obj)->f34, i);
            flag = 0;
            if (value != 0) flag = 1;
            func_021F812C((int)ctx, (int *)slot, flag);
        }
    }
    return 0;
}

int func_021FB2B0(int unused,char *p)
{
    int mask;
    char *owner,*q,*target;
    Vec pos;
    int delta[3];
    u32 wait,z,y,x,rate;
    char *ctx;
    u8 i;
    owner=*(char * *)&((struct Obj03821 *)p)->f0;
    mask=func_021FB1F4(p,func_0201134C(((struct Obj03821 *)p)->f4));
    rate=func_0201134C(((struct Obj03821 *)p)->f4);
    x=func_0201134C(((struct Obj03821 *)p)->f4);
    y=func_0201134C(((struct Obj03821 *)p)->f4);
    z=func_0201134C(((struct Obj03821 *)p)->f4);
    wait=func_0201134C(((struct Obj03821 *)p)->f4);
    ctx=func_021F9DA0(((struct Obj08162 *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=func_021F9DA4(((struct Obj08162 *)owner)->f34,i);
            if (rate==0) {
                pos.x=x;pos.y=y;pos.z=z;
                func_021F8054(ctx,(u32 *)target,(const u32 *)(&pos));
            } else {
                q=func_02030734(((struct Obj08162 *)owner)->f0,56,0,d_021FDD00,0x2DA);
                *(char * *)&((struct Obj02192 *)q)->f30=owner;
                *(char * *)&((struct Obj02192 *)q)->f0=target;
                ((struct Obj02192 *)q)->f4=((struct Obj08162 *)owner)->f34;
                ((struct Obj02192 *)q)->f2E=0;
                func_021F8044(ctx,(u32 *)target,(u32 *)(q+8));
                ((struct Obj02192 *)q)->f14=x;((struct Obj02192 *)q)->f18=y;((struct Obj02192 *)q)->f1C=z;
                ((struct Obj02192 *)q)->f2C=rate;
                func_0207CA00(q+20,q+8,delta);
                ((struct Obj02192 *)q)->f20=delta[0]/(int)rate;
                ((struct Obj02192 *)q)->f24=delta[1]/(int)rate;
                ((struct Obj02192 *)q)->f28=delta[2]/(int)rate;
                ((struct Obj02192 *)q)->f34=func_021FADA0(owner,(u32)func_021FB528,(u32)q,10);
            }
        }
    }
    if(wait==1) {((struct Obj03821 *)p)->f14=rate;return 1;}
    return 0;
}

static inline void vset(Vec *v,Coord x,Coord y,Coord z)
{
    v->x=x;v->y=y;v->z=z;
}

#pragma opt_loop_invariants off

/*
 * pass 2 2026-10-06 P2L34: EXACT in --lang c99 and --lang c. The last 23 bytes were spill slots:
 *   with loop invariant motion on, x,y,z (each used two or three times inside the loop) got new
 *   loop webs and fell below the other spills.  for this function
 *   keeps them as declared locals, and the slots then follow declaration order
 *   (mask, x, y, z, wait / i, ctx).
 */
int func_021FB3E0(int unused,char *p)
{
    int mask;
    Coord x,y,z;
    char *owner;
    int rate;
    Coord wait;
    owner=*(char **)p;
    mask=func_021FB1F4(p,func_0201134C(*(void **)(p+4)));
    rate=func_0201134C(*(void **)(p+4));
    x=func_0201134C(*(void **)(p+4));
    y=func_0201134C(*(void **)(p+4));
    z=func_0201134C(*(void **)(p+4));
    wait=func_0201134C(*(void **)(p+4));
    {
    u8 i;
    void *ctx;
    char *q,*target;
    u32 pos[3];
    ctx=func_021F9DA0(*(void **)(owner+52));
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=func_021F9DA4(*(void **)(owner+52),i);
            if (rate==0) {
                func_021F8044(ctx,(u32 *)target,pos);
                pos[0]+=x;pos[1]+=y;pos[2]+=z;
                func_021F8054(ctx,(u32 *)target,pos);
            } else {
                q=func_02030734(*(u16 *)owner,56,0,d_021FDD00,0x31B);
                *(char **)(q+48)=owner;
                *(char **)q=target;
                *(void **)(q+4)=*(void **)(owner+52);
                *(u16 *)(q+46)=0;
                func_021F8044(ctx,(u32 *)target,(u32 *)(q+8));
                vset((Vec *)(q+20),*(int *)(q+8)+x,*(int *)(q+12)+y,*(int *)(q+16)+z);
                *(u16 *)(q+44)=rate;
                *(int *)(q+32)=(int)x/(int)rate;
                *(int *)(q+36)=(int)y/(int)rate;
                *(int *)(q+40)=(int)z/(int)rate;
                *(void **)(q+52)=func_021FADA0(owner,(u32)func_021FB528,(u32)q,10);
            }
        }
    }
    }
    if(wait==1) {*(u16 *)(p+20)=rate;return 1;}
    return 0;
}

#pragma opt_loop_invariants reset

/*
 * lever: Void callback return omits the extra zero result instruction.
 */
void func_021FB528(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DA0(((struct Obj08163 *)p)->f4); result=func_021FAE4C(p+4,pos); func_021F8054(ctx,*(unsigned int * *)&((struct Obj08163 *)p)->f0,(unsigned int *)pos); if(result==1)func_021FADF8(((struct Obj08163 *)p)->f30,((struct Obj08163 *)p)->f34); }

int func_021FB55C(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj14103 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj14103 *)p)->f4));
    ctx = func_021F9DA0(((struct Obj14104 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80B0(ctx, func_021F9DA4(((struct Obj14104 *)obj)->f34, i));
        }
    }
    return 0;
}

int func_021FB5A4(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj14105 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj14105 *)p)->f4));
    ctx = func_021F9DA0(((struct Obj14106 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80A0((int)ctx, func_021F9DA4(((struct Obj14106 *)obj)->f34, i));
        }
    }
    return 0;
}
