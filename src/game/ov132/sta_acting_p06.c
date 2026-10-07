/*
 * file:     sta_acting_p06.c
 * unit:     yes
 * function: func_021F9730, func_021F9754, func_021F9768, func_021F9774, func_021F9794, func_021F99F4, func_021F9A48, func_021F9AD8, func_021F9CF4, func_021F9D08, func_021F9D18, func_021F9D80, func_021F9D90, func_021F9DA0, func_021F9DA4, func_021F9DAC, func_021F9DB0, func_021F9DB8, func_021F9DC0, func_021F9DC4, func_021F9DCC, func_021F9DD4, func_021F9DDC, func_021F9DE8, func_021F9DF4, func_021F9DFC, func_021F9E00, func_021F9E04, func_021F9E08, func_021F9E0C, func_021F9E18
 * address:  0x021F9730
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
 *   func_021F7A80 0x021F7A80 thumb ov112
 *   func_021FD8C4 0x021FD8C4 thumb ov132
 *   func_021F79A8 0x021F79A8 thumb ov112
 *   func_02005728 0x02005728 thumb
 *   func_021FD9FC 0x021FD9FC thumb ov132
 *   func_021FD9A0 0x021FD9A0 thumb ov132
 *   func_021FDA18 0x021FDA18 thumb ov132
 *   func_021FD9D0 0x021FD9D0 thumb ov132
 *   func_020061E4 0x020061E4 thumb
 *   func_0203D378 0x0203D378 arm
 *   func_021FDA24 0x021FDA24 thumb ov132
 *   func_021F5140 0x021F5140 thumb ov112
 *   func_02157394 0x02157394 thumb ov010
 *   func_021F95F0 0x021F95F0 thumb ov132
 *   func_021FD974 0x021FD974 thumb ov132
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ll_mul 0x0209C054 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021F9EDC  0x021F9EDC  thumb
 *   func_021F9F58  0x021F9F58  thumb
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_021FAAB8  0x021FAAB8  thumb
 *   func_021F4F10 0x021F4F10 thumb ov112
 */
#include "../../matched/include/Obj08153.h"
#include "../../matched/include/Obj14085.h"
#include "../../matched/include/Obj08155.h"
#include "../../matched/include/Obj00159.h"
#include "../../matched/include/Obj10534.h"
#include "../../matched/include/Obj23204.h"
#include "../../matched/include/Obj08154.h"
#include "../../matched/include/Obj03287.h"
#include "../../matched/include/Obj14086.h"
#include "../../matched/include/Obj14087.h"
#include "../../matched/include/Obj14088.h"
#include "../../matched/include/Obj23210.h"
#include "../../matched/include/Obj23211.h"
#include "../../matched/include/Obj23212.h"
#include "../../matched/include/Obj23213.h"
#include "../../matched/include/Obj23214.h"
#include "../../matched/include/Obj23215.h"
#include "../../matched/include/Obj23216.h"
#include "../../matched/include/Obj23217.h"
#include "../../matched/include/Obj23218.h"
#include "../../matched/include/Obj23219.h"
#include "../../matched/include/Obj23220.h"
#include "../../matched/include/Obj23221.h"

typedef unsigned char u8;

typedef unsigned int   u32;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef enum { ENABLED = 1 } Enabled;

typedef unsigned long long u64;

typedef enum { ACTION7 = 7, ACTION8 = 8 } Action;

typedef struct { int x, y, z; } Vec;

extern int func_021F7A80(char *,char *);
extern int func_021FD8C4(void *, int);
extern void func_021F79A8(char *, char *, int);
extern u32 func_02005728(u32);
extern int func_021FD9FC(char *p);
extern int func_021FD9A0(void *, unsigned);
extern void func_021FDA18(unsigned char *p);
extern void func_021FD9D0(unsigned char *p, unsigned char key);
extern void func_020061E4(u32 a);
extern u32 func_0203D378(void);
extern void func_021FDA24(void *, u32, u32, u32);
extern unsigned char func_021F5140(void *p, int i);
extern u16 func_02157394(int a0, int a1);
extern void func_021F95F0(u8 *);
extern void func_021FD974(char *p, u32 key, u8 value);
extern u32 func_0203F0A8(void);
extern char *func_021F9EDC(char *p, u32 a);
extern void func_021F9F58(u8 *unused, u8 *p);
extern void func_021F8044(void *unused, unsigned int *p, unsigned int *q);
extern void func_021F9F74(char *, unsigned, const int *);
extern void func_021FAAB8(char *p, unsigned flag);
extern u32 func_021F4F10(u8 *);
void func_021F9730(char *p,int value);
void func_021F9754(char *p, u32 i, int v);
int func_021F9768(char *p);
int func_021F9774(char *p,u32 i);
void func_021F9794(char *p);
int func_021F99F4(char *p, unsigned i, unsigned j);
void func_021F9A48(char *p);
void func_021F9AD8(char *p, int mode, u8 slot);
void func_021F9CF4(char *p);
void func_021F9D08(char *p);
void func_021F9D18(char *p, unsigned i);
void func_021F9D80(char *p);
void func_021F9D90(char *p);
void *func_021F9DA0(char *p);
void *func_021F9DA4(char *p,u32 i);
void *func_021F9DAC(void *p);
u32 *func_021F9DB0(void *p,u8 i);
void func_021F9DB8(void *p,void *v,u32 i);
void *func_021F9DC0(void *p);
void *func_021F9DC4(void *p,u8 i);
void func_021F9DCC(void *p,void *v,u32 i);
void *func_021F9DD4(void *p);
void *func_021F9DDC(void *p,u8 i);
void func_021F9DE8(void *p,void *v,u8 i);
void *func_021F9DF4(void *p);
u16 func_021F9DFC(void *p);
void func_021F9E00(void *p,u16 v);
u16 func_021F9E04(u8 *p);
void func_021F9E08(u8 *p,u16 v);
u32 func_021F9E0C(u8 *p);
int func_021F9E18(char *p);

void func_021F9730(char *p,int value){if(!**(int * *)&((struct Obj08153 *)p)->f30)func_021F9754(p,((struct Obj08153 *)p)->fA,value);else{((struct Obj08153 *)p)->f15C=1;((struct Obj08153 *)p)->f160=value;}}

void func_021F9754(char *p, u32 i, int v)
{
    Enabled one;
    one = ENABLED;
    i = (u32)p + i * 4;
    ((struct Obj14085 *)i)->fFC = one;
    ((struct Obj14085 *)i)->f10C = v;
}

int func_021F9768(char *p){return func_021F9774(p,((struct Obj08155 *)p)->fA);}

int func_021F9774(char *p,u32 i){if(func_021F7A80(*(char * *)&((struct Obj08155 *)p)->f40,*(char **)((u32)p+i*4+0x44))==1)return 1;return *(int *)((u32)p+0xfc+i*4);}

/*
 * lever: slots[count] = i; count++; keeps the byte store before the increment; if/else field stores preserve the shared flag-store block.
 */
void func_021F9794(char *p)
{
    u8 count = 0;
    u8 slots[4];
    u8 i;
    int action;
    int index;
    int result;
    func_021F9A48(p);
    if (**(void ** *)&((struct Obj00159 *)p)->f30 && ((struct Obj00159 *)p)->f15C == 1) {
        if (func_021FD8C4(**(void ** *)&((struct Obj00159 *)p)->f30, (u8)((struct Obj00159 *)p)->f160) == 1)
            ((struct Obj00159 *)p)->f15C = 0;
    }
    if (!**(void ** *)&((struct Obj00159 *)p)->f30) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(p + i * 4 + 0xFC) == 1) {
                func_021F79A8(*(char * *)&((struct Obj00159 *)p)->f40, *(char **)(p + i * 4 + 0x44), *(int *)(p + i * 4 + 0x10C));
                slots[count] = i;
                count++;
                *(int *)(p + i * 4 + 0xFC) = 0;
                if (*(int *)(p + i * 4 + 0x10C) == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (*(int *)(p + i * 4 + 0x10C) == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
        if (count != 0) {
            if (((struct Obj00159 *)p)->f11C == 4) ((struct Obj00159 *)p)->f120 = 1;
            else ((struct Obj00159 *)p)->f120 = 0;
            ((struct Obj00159 *)p)->f11E = 180;
            ((struct Obj00159 *)p)->f11C = slots[func_02005728(count)];
            ((struct Obj00159 *)p)->f11D = *(int *)(p + ((struct Obj00159 *)p)->f11C * 4 + 0x10C);
            ((struct Obj00159 *)p)->fEC = 1;
        }
    } else {
        index = func_021FD9FC(**(void ** *)&((struct Obj00159 *)p)->f30);
        if ((unsigned)index < 4) {
            if (((struct Obj00159 *)p)->f11C == 4) ((struct Obj00159 *)p)->f120 = 1;
            else ((struct Obj00159 *)p)->f120 = 0;
            ((struct Obj00159 *)p)->f11E = 180;
            ((struct Obj00159 *)p)->f11C = index;
            ((struct Obj00159 *)p)->f11D = func_021FD9A0(**(void ** *)&((struct Obj00159 *)p)->f30, index);
            ((struct Obj00159 *)p)->fEC = 1;
            func_021FDA18(**(void ** *)&((struct Obj00159 *)p)->f30);
        }
        for (i = 0; i < 4; i++) {
            action = func_021FD9A0(**(void ** *)&((struct Obj00159 *)p)->f30, i);
            if (action != 10) {
                func_021F79A8(*(char * *)&((struct Obj00159 *)p)->f40, *(char **)(p + i * 4 + 0x44), action);
                func_021FD9D0(**(void ** *)&((struct Obj00159 *)p)->f30, i);
                if (action == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (action == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
    }
    if (((struct Obj00159 *)p)->f11E != 0) {
        if (((struct Obj00159 *)p)->f11E > ((struct Obj00159 *)p)->f1E8) {
            ((struct Obj00159 *)p)->f11E -= (u16)((struct Obj00159 *)p)->f1E8;
            return;
        }
        ((struct Obj00159 *)p)->f11E = 0;
        if (((struct Obj00159 *)p)->f120 == 1) {
            if (!**(void ** *)&((struct Obj00159 *)p)->f30) {
                result = func_021F99F4(p, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D);
                *(int *)(*(char **)(*(char * *)&((struct Obj00159 *)p)->f30 + ((struct Obj00159 *)p)->f11C * 4 + 4) + ((struct Obj00159 *)p)->f11D * 4 + 0x54) = 1;
                func_020061E4(result);
            } else if (func_0203D378() == 1) {
                result = func_021F99F4(p, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D);
                if (result == 1580) func_021FDA24(**(void ** *)&((struct Obj00159 *)p)->f30, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D, 1);
                else func_021FDA24(**(void ** *)&((struct Obj00159 *)p)->f30, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D, 2);
            }
        }
        ((struct Obj00159 *)p)->f11C = 4;
        ((struct Obj00159 *)p)->fEC = 1;
    }
}

int func_021F99F4(char *p, unsigned i, unsigned j)
{
    u16 v;
    u8 old;
    v = func_02157394((int)(((struct Obj23204 *)(*(char * *)&((struct Obj10534 *)p)->f30))->f14), (u8)(int)func_021F5140((void *)func_021F9E0C((u8 *)p), (u16)(*(u16 *)(*(char **)(*(char * *)&((struct Obj10534 *)p)->f30 + i * 4 + 4) + j * 6 + 0x14))));
    old = *(u8 *)(p + 0xf7 + i);
    *(u8 *)(p + 0xf7 + i) = old + v;
    func_021F95F0((u8 *)p);
    return (unsigned)v >= 7 ? 1579 : 1580;
}

void func_021F9A48(char *p)
{
    u8 i;
    if (**(void ** *)&((struct Obj08154 *)p)->f30 != 0 && func_0203D378() != 1) return;
    for (i = 0; i < 4; i++) {
        if (*(u16 *)(p + i * 2 + 0x124) != 0) {
            *(u16 *)(p + i * 2 + 0x124) -= 1;
            if (*(u16 *)(p + i * 2 + 0x124) == 0) {
                if (**(void ** *)&((struct Obj08154 *)p)->f30 == 0) func_021F9754(p, i, *(int *)(p + i * 4 + 0x12c));
                else func_021FD974(**(void ** *)&((struct Obj08154 *)p)->f30, i, *(int *)(p + i * 4 + 0x12c));
            }
        }
    }
}

static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = func_0203F0A8();
    return ((u64)draw * n) >> 32;
}

/*
 * lever: The final random choice is a ternary; an if/else shares the earlier action-seven assignment and leaves 36 bytes different.
 * ABI: The matched 0203D378 body returns u32(void); the preceding guard loads r0 without an argument to that call.
 */
void func_021F9AD8(char *p, int mode, u8 slot)
{
    u8 i;
    if (**(void ** *)&((struct Obj08155 *)p)->f30 && func_0203D378() != 1) return;
    for (i = 0; i < 4; i++) {
        int eligible[2] = {0, 0};
        char *record = *(char **)(*(char * *)&((struct Obj08155 *)p)->f30 + i * 4 + 4);
        Action action;
        int value;
        if (((struct Obj03287 *)record)->f0 != 2 || func_021F9774(p, i) == 1 || *(u16 *)(p + i * 2 + 0x124) != 0) continue;
        if (((struct Obj03287 *)record)->f3E != 255 && !*(int *)(p + i * 8 + 0x13C)) eligible[0] = 1;
        if (((struct Obj03287 *)record)->f44 != 255 && !*(int *)(p + i * 8 + 0x140)) eligible[1] = 1;
        if (!eligible[0] && !eligible[1]) continue;
        if (eligible[0] == 1 && eligible[1] == 0) action = ACTION7;
        else if (eligible[1] == 1 && eligible[0] == 0) action = ACTION8;
        else {
            action = (u8)random_below(2) == 0 ? ACTION7 : ACTION8;
        }
        switch (mode) {
        case 1:
            if (((struct Obj03287 *)record)->f78 == 65533 && i == slot) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(30) + 30;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 2:
            if (((struct Obj03287 *)record)->f78 == 65535 && random_below(100) < 50) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            if (((struct Obj03287 *)record)->f78 == 65534 && random_below(100) < 25) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 0:
            if (((struct Obj03287 *)record)->f78 != 0 && ((struct Obj03287 *)record)->f78 < 65533) {
                value = ((struct Obj03287 *)record)->f78 + (s8)(random_below(121) - 60);
                if (value < 0) *(u16 *)(p + i * 2 + 0x124) = 0;
                else *(u16 *)(p + i * 2 + 0x124) = value;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F9CF4(char *p)
{
    ((struct Obj14086 *)p)->fBC = func_021F9EDC(((struct Obj14086 *)p)->f6C, 0x36);
}


void func_021F9D08(char *p)
{
    func_021F9F58(((struct Obj14087 *)p)->f6C, ((struct Obj14087 *)p)->fBC);
}

void func_021F9D18(char *p, unsigned i)
{
    Vec v;
    u8 j;
    func_021F8044(((struct Obj14088 *)p)->f40, *(void **)(p + i * 4 + 0x44), (unsigned int *)(&v));
    v.x /= 16;
    v.y = (0xc0000 - (v.y - 0x20000)) / 16;
    v.z = 0xb4000;
    for (j = 0; j < 3; j++) func_021F9F74(*(char * *)&((struct Obj14088 *)p)->fBC, j, &v.x);
    func_020061E4(1961);
}


void func_021F9D80(char *p)
{
    func_021FAAB8(((struct Obj23210 *)p)->fA4, 1);
}

void func_021F9D90(char *p){func_021FAAB8(((struct Obj23211 *)p)->fA4,0);}

void *func_021F9DA0(char *p){return ((struct Obj23212 *)p)->f40;}

void *func_021F9DA4(char *p,u32 i){return *(void **)((u32)p+4*i+0x44);}

void *func_021F9DAC(void *p){return ((struct Obj23213 *)p)->f54;}

u32 *func_021F9DB0(void *p,u8 i){return *(u32 **)((u8 *)p+(u32)i*4+0x58);}

void func_021F9DB8(void *p,void *v,u32 i){*(void **)((u8 *)p+i*4+0x58)=v;}

void *func_021F9DC0(void *p){return ((struct Obj23214 *)p)->f6C;}

void *func_021F9DC4(void *p,u8 i){return *(void **)((u8 *)p+(u32)i*4+0x70);}

void func_021F9DCC(void *p,void *v,u32 i){*(void **)((u8 *)p+i*4+0x70)=v;}

void *func_021F9DD4(void *p){return ((struct Obj23215 *)p)->f90;}

void *func_021F9DDC(void *p,u8 i){return *(void **)((u8 *)p+(u32)i*4+0x94);}

void func_021F9DE8(void *p,void *v,u8 i){*(void **)((u8 *)p+(u32)i*4+0x94)=v;}

void *func_021F9DF4(void *p){return ((struct Obj23216 *)p)->fB8;}

u16 func_021F9DFC(void *p){return ((struct Obj23217 *)p)->f8;}

void func_021F9E00(void *p,u16 v){((struct Obj23218 *)p)->f8=v;}

u16 func_021F9E04(u8 *p) { return ((struct Obj23219 *)p)->f4; }

void func_021F9E08(u8 *p,u16 v) { ((struct Obj23220 *)p)->f6=v; }

u32 func_021F9E0C(u8 *p) { return func_021F4F10(*(u8 * *)&((struct Obj10534 *)p)->f38); }

/*
 * note: unlabelled getter witnessing ov112 021F6CE0.
 */
int func_021F9E18(char *p) { return ((struct Obj23221 *)p)->f11C; }
