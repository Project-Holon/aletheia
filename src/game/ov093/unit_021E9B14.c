/*
 * file:     unit_021E9B14.c
 * unit:     yes
 * function: func_021E9B14, func_021E9B20, func_021E9CE0, func_021E9D04
 * address:  0x021E9B14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06899CA4  0x06899CA4  thumb
 *   func_06899CDC  0x06899CDC  thumb
 *   func_06899D04  0x06899D04  thumb
 *   func_06899D2C  0x06899D2C  thumb
 *   func_06899D30  0x06899D30  thumb
 *   func_0689B66C  0x0689B66C  thumb
 *   func_0689CAEC  0x0689CAEC  thumb
 *   func_0689CB18  0x0689CB18  thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   ov196_id 0x000000C4 data
 *   ov198_id 0x000000C6 data
 *   func_021E9984  0x021E9984  thumb  ov093
 *   BTL_MAIN_GetMyItem 0x021B90E8 thumb ov093
 *   BTL_MAIN_GetMapMatrix 0x021B90F0 thumb ov093
 *   BTL_MAIN_GetRegulationRules 0x021BA1E4 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_CheckSetupStatusFlag 0x021BA1A8 thumb ov093
 *   BTL_SIDE_CountLivingOfClient 0x021B9B04 thumb ov093
 *   func_021D3D7C 0x021D3D7C thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 */
#include "../../matched/include/Obj00891.h"
#include "../../matched/include/Obj00056.h"

struct Q1;
struct S2;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_06899CA4(void *, int);
extern int func_06899D04(void *);
extern void func_06899D2C(void *);
extern void func_0689CAEC(void *, u8, u8);
extern void func_0689CB18(void *);
extern void func_06899CDC(void *);
extern void func_06899D30(void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void func_0220F3E8(u8 *p);
extern void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);
extern u32 BTL_MAIN_GetMyItem(void **p);
extern u32 BTL_MAIN_GetMapMatrix(void **p);
extern int func_0689B66C(void *);
extern char *BTL_MAIN_GetRegulationRules(char **);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern unsigned char BTL_SIDE_CountLivingOfClient(int a, int b);
extern u32 func_021D3D7C(u8 *p);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
void func_021E9B14(unsigned int *p);
int func_021E9B20(u8 *p);
void func_021E9CE0(u8 *p, u8 a, u8 b);
void func_021E9D04(u8 *p, int x, u8 a, u8 b, u8 c, u8 d);
extern u8 ov196_id[], ov198_id[];


void func_021E9B14(unsigned int *p)
{
    p[0x4F] = 1;
}


/*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: lead is 320 bytes; eight 16-byte Thumb veneers follow.
 */
int func_021E9B20(u8 *p)
{
    u32 i;
    switch (p[0x174]) {
    case 0:
        if ((u8)(p[0x12b] + 0xff) <= 1) func_06899CA4(((struct Obj00891 *)p)->f180, 0);
        else func_06899CA4(((struct Obj00891 *)p)->f180, 1);
        func_02034AC4((int)ov196_id);
        p[0x174]++;
        break;
    case 1:
        if (func_06899D04(((struct Obj00891 *)p)->f180)) {
            func_06899D2C(((struct Obj00891 *)p)->f180);
            func_02034AC4((int)ov198_id);
            func_0220F3E8(p + 0x10c);
            p[0x174]++;
        }
        break;
    case 2:
        if (p[0x158]) {
            if (p[0x12b] != 5 && ((struct Obj00891 *)p)->f13C == 0) {
                for (i = 0; i < 3; i++) {
                    if (p[i + 0x154] != 0xff) {
                        func_0689CAEC(((struct Obj00891 *)p)->f15C, i, p[i + 0x154]);
                        func_0689CB18(((struct Obj00891 *)p)->f15C);
                        (*(u8 **)(p + 0x15c))[8] = 0;
                    }
                }
            }
            func_02034A5C((int)ov198_id);
            func_06899CDC(((struct Obj00891 *)p)->f180);
            func_06899D30(((struct Obj00891 *)p)->f180);
            p[0x174]++;
        }
        break;
    case 3:
        if (func_06899D04(((struct Obj00891 *)p)->f180)) p[0x174]++;
        break;
    default:
        func_02034A5C((int)ov196_id);
        p[0x174] = 0;
        return 1;
    }
    return 0;
}


void func_021E9CE0(u8 *p, u8 a, u8 b)
{
    func_021E9984(p, p + 0x10c, 5, a, 0);
    p[0x157] = b;
    p[0x174] = 0;
}


void func_021E9D04(u8 *p, int x, u8 a, u8 b, u8 c, u8 d)
{
    u32 i;
    u32 n;
    void *list;
    int flag;
    if (p[0x174]) return;
    ((struct Obj00056 *)p)->fC8 = (void *)BTL_MAIN_GetMyItem(((struct Obj00056 *)p)->f0);
    ((struct Obj00056 *)p)->fE4 = (void *)BTL_MAIN_GetMapMatrix(((struct Obj00056 *)p)->f0);
    ((struct Obj00056 *)p)->fD0 = x;
    ((struct Obj00056 *)p)->fCC = ((struct Obj00056 *)p)->fB0;
    ((struct Obj00056 *)p)->fD4 = ((struct Obj00056 *)p)->f184;
    p[0xdc] = a;
    p[0xdd] = b;
    ((struct Obj00056 *)p)->fDE = 0;
    ((struct Obj00056 *)p)->fF4 = func_0689B66C(((struct Obj00056 *)p)->f180);
    ((struct Obj00056 *)p)->fE8 = 0;
    *(char * *)&((struct Obj00056 *)p)->fD8 = BTL_MAIN_GetRegulationRules(*(char ** *)&((struct Obj00056 *)p)->f0);
    flag = 0;
    if ((int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00056 *)p)->f0) != 3) flag = 1;
    ((struct Obj00056 *)p)->f108 = flag;
    ((struct Obj00056 *)p)->fEC = 0;
    flag = 0;
    if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00056 *)p)->f0) == 0) flag = 1;
    p[0xf1] = flag;
    p[0xe1] = 0;
    flag = 0;
    if (c == 0) flag = 3;
    else if (BTL_MAIN_CheckSetupStatusFlag(((struct Obj00056 *)p)->f0, 0x40)) flag = 1;
    else if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00056 *)p)->f0) == 0) {
        if (BTL_SIDE_CountLivingOfClient(((struct Obj00056 *)p)->f8, 1) > 1) flag = 2;
        else if (d) flag = 4;
    }
    p[0xf0] = flag;
    func_021E9984(p, p + 0x10c, 3, 0, 0);
    list = (void *)func_021D3D7C(((struct Obj00056 *)p)->f4);
    n = BTL_SLOT_GetCount(list);
    for (i = 0; i < n; i++)
        p[0x144 + i] = BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)BTL_SLOT_GetPokeParam(list, (u8)i), 0x13);
    for (; i < 6; i++) p[0x144 + i] = 0;
    p[0x174] = 1;
}
