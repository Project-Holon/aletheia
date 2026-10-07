/*
 * file:     wifibattlematch_net_p18.c
 * unit:     yes
 * function: func_021DADAC, func_021DADB4, func_021DADCC, func_021DAE00, func_021DAE18, func_021DAE54
 * address:  0x021DADAC
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
 *   func_021DF224  0x021DF224  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   DWC_ScDestroyReport  0x021DF458  arm
 *   DWC_ScShutdown       0x021DEF58  arm
 *   func_021DF23C  0x021DF23C  arm
 *   func_021DF298  0x021DF298  arm
 *   func_021DF2C8  0x021DF2C8  arm
 *   func_021DF2F8  0x021DF2F8  arm
 *   func_021DF328  0x021DF328  arm
 *   func_021DF358  0x021DF358  arm
 *   func_021DF3B0  0x021DF3B0  arm
 *   func_02034714  0x02034714  arm
 *   d_021E2EF8     0x021E2EF8  data
 */
#include "../../matched/include/Obj24330.h"
#include "../../matched/include/Obj14335.h"
#include "../../matched/include/Obj10685.h"
#include "../../matched/include/Obj14336.h"
#include "../../matched/include/Obj03320.h"
#include "../../matched/include/Obj24331.h"
#include "../../matched/include/Obj02887.h"
#include "../../matched/include/Obj14337.h"
#include "../../matched/include/Obj24332.h"

typedef unsigned char u8;

typedef unsigned int u32_021DADAC;

typedef unsigned long u32_021DADCC;

typedef unsigned long u32_021DAE18;

typedef unsigned long u32_021DAE54;

typedef int (*RoundFn)(char *ctx, char *peer, int dir, int flag);

typedef signed int     s32;

extern void *func_021DF224(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32_021DADCC size);
extern void DWC_ScDestroyReport(u32_021DAE18 report);
extern void DWC_ScShutdown(void);
extern int func_021DF23C(u32_021DAE54 a0, u32_021DAE54 a1, u32_021DAE54 a2, u32_021DAE54 a3);
extern int func_021DF298(u32_021DAE54 *a0);
extern int func_021DF2C8(u32_021DAE54 *a0);
extern int func_021DF2F8(u32_021DAE54 *a0);
extern int func_021DF328(u8 *a0);
extern s32 func_021DF358(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, char *a5, s32 a6);
extern int func_021DF3B0(u32_021DAE54 h, u32_021DAE54 a, int flag);
extern void func_02034714(const char *expr, u32_021DAE54 line, const char *file);
u32_021DADAC func_021DADAC(u8 *p);
void func_021DADB4(int result, char *obj);
void func_021DADCC(int result, char *obj);
void func_021DAE00(int result, char *obj);
void func_021DAE18(char *obj);
int func_021DAE54(char *ctx, char *other, char *peer, u32_021DAE54 a3, RoundFn cb, int flag, int have, int twoway);
extern const char d_021E2EF8[];

u32_021DADAC func_021DADAC(u8 *p) { return ((struct Obj24330 *)p)->f150; }


/*
 * Competition-server completion callback: records a nonzero result at +0x15c and drops the pending-request count at +0x134 (unlabelled; its address is a code pointer in func_021DA6B8's pool).
 */
void func_021DADB4(int result, char *obj)
{
    if (result != 0)
        ((struct Obj14335 *)obj)->f15C = result;
    (((struct Obj14335 *)obj)->f134)--;
}


/*
 * Report-intention completion callback: on success copies the 0x28-byte session id into the report block (+0x34 of the record at +0x1464), otherwise records the result at +0x15c; then drops the pending-request count at +0x134.
 */
void func_021DADCC(int result, char *obj)
{
    char *p = *(char * *)&((struct Obj10685 *)obj)->f1464 + 4;

    if (result == 0)
        MI_CpuCopy8(func_021DF224(), p + 0x30, 0x28);
    else
        ((struct Obj10685 *)obj)->f15C = result;
    (((struct Obj10685 *)obj)->f134)--;
}


void func_021DAE00(int result, char *obj)
{
    if (result != 0)
        ((struct Obj14336 *)obj)->f15C = result;
    (((struct Obj14336 *)obj)->f134)--;
}


/*
 * Report teardown: when the state word at +0x170 is 1, destroys the report once the +0x12c step is past 0x13, shuts the storage client down once the +0x12c step is 4 or more, and clears the state word.
 */
void func_021DAE18(char *obj)
{
    if (((struct Obj03320 *)obj)->f170 == 1) {
        if (((struct Obj03320 *)obj)->f12C > 0x13)
            DWC_ScDestroyReport(((struct Obj24331 *)(*(char * *)&((struct Obj03320 *)obj)->f1464))->f8);
        if (((struct Obj03320 *)obj)->f12C >= 4)
            DWC_ScShutdown();
        ((struct Obj03320 *)obj)->f170 = 0;
    }
}


/*
 * One exchange round: bails with the first nonzero status of the four session checks, sends the local record (mode from the peer kind), runs the callback, optionally sends the peer's record back and runs the callback again, then closes with the flag.
 */
int func_021DAE54(char *ctx, char *other, char *peer, u32_021DAE54 a3, RoundFn cb, int flag, int have, int twoway)
{
    int r;
    int mode;
    int mode2;

    if ((r = func_021DF23C(1, 2, 0, (u32_021DAE54)(ctx + 4))) != 0)
        return r;
    if ((r = func_021DF298((u32_021DAE54 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if ((r = func_021DF2C8((u32_021DAE54 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if ((r = func_021DF328((u8 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;

    if (flag != 0 || have == 0) {
        mode = 5;
    } else {
        switch (((struct Obj14337 *)peer)->f4) {
        case 1:
        case 4:
            mode = 0;
            break;
        case 0:
        case 3:
            mode = 1;
            break;
        case 2:
            mode = 2;
            break;
        default:
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    }
    if ((r = func_021DF358(((struct Obj02887 *)ctx)->f4, 0, (s32)(ctx + 0x30), 0, mode, (char *)(((struct Obj02887 *)ctx)->f0), (s32)(ctx + 0x58))) != 0)
        return r;
    if ((r = cb(ctx, peer, 1, flag)) != 0)
        return r;
    if ((r = func_021DF328((u8 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;

    if (twoway == 1) {
        if (have == 0) {
            mode2 = 5;
        } else if (flag != 0) {
            mode2 = 3;
        } else {
            switch (((struct Obj14337 *)peer)->f4) {
            case 1:
            case 4:
                mode2 = 1;
                break;
            case 0:
            case 3:
                mode2 = 0;
                break;
            case 2:
                mode2 = 2;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
        if ((r = func_021DF358(((struct Obj02887 *)ctx)->f4, 1, (s32)(other + 0x30), 0, mode2, (char *)(((struct Obj24332 *)other)->f0), (s32)(other + 0x58))) != 0)
            return r;
        if ((r = cb(ctx, peer, 0, flag)) != 0)
            return r;
    }
    if ((r = func_021DF2F8((u32_021DAE54 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if (flag != 0)
        return func_021DF3B0(((struct Obj02887 *)ctx)->f4, a3, 1);
    return func_021DF3B0(((struct Obj02887 *)ctx)->f4, a3, 0);
}
