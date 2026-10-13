/*
 * file:     unit_021EAC54.c
 * unit:     yes
 * function: func_021EAC54, func_021EAC64, func_021EAC80, func_021EADA4, func_021EADB4, func_021EADC4, func_021EADD4, func_021EADE4, func_021EADF4, func_021EAE04, func_021EAE14, func_021EAE24, func_021EAE34, func_021EAE44, func_021EAE54, func_021EAE64, func_021EAE74
 * address:  0x021EAC54
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
 *   func_0689B780  0x0689B780  thumb
 *   func_0689B5CC   0x0689B5CC  thumb  ov095
 *   func_021E9984  0x021E9984  thumb  ov093
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   ov196_id 0x000000C4 data
 *   ov198_id 0x000000C6 data
 *   BTLV_SCU_StartBallWindowOpen 0x021EE264 thumb ov093
 *   BTLV_SCU_UpdateBallWindowOpen 0x021EE2A0 thumb ov093
 *   BTLV_SCU_StartBallWindowRefresh 0x021EE2F8 thumb ov093
 *   BTLV_SCU_UpdateBallWindowRefresh 0x021EE318 thumb ov093
 *   BTLV_SCU_StartBallWindowClose 0x021EE370 thumb ov093
 *   BTLV_SCU_UpdateBallWindowClose 0x021EE390 thumb ov093
 *   BTLV_SCU_StartFadeIn   0x021EE228  thumb  ov093
 *   BTLV_SCU_GetWaitState   0x021EE25C  thumb  ov093
 *   BTLV_SCU_ClearWaitWindow 0x021EE23C thumb ov093
 *   func_0689B670   0x0689B670  thumb  ov095
 *   func_0689B69C   0x0689B69C  thumb  ov095
 *   func_0689B790   0x0689B790  thumb  ov095
 */
#include "../../matched/include/Obj01694.h"
#include "../../matched/include/Obj21571.h"
#include "../../matched/include/Obj21572.h"
#include "../../matched/include/Obj21573.h"
#include "../../matched/include/Obj21574.h"
#include "../../matched/include/Obj21575.h"
#include "../../matched/include/Obj21576.h"
#include "../../matched/include/Obj21577.h"
#include "../../matched/include/Obj21578.h"
#include "../../matched/include/Obj07847.h"

struct T;
struct O;
struct Q;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);
extern void func_06899CA4(void *, int);
extern int func_06899D04(void *);
extern void func_06899D2C(void *);
extern void func_06899CDC(void *);
extern void func_06899D30(void *);
extern int func_02034AC4(signed int);
extern void func_02034A5C(int);
extern void func_0220F3E8(u8 *p);
extern void BTLV_SCU_StartBallWindowOpen(char *, int, struct T *);
extern int BTLV_SCU_UpdateBallWindowOpen(struct O *);
extern void BTLV_SCU_StartBallWindowRefresh(struct O *);
extern int BTLV_SCU_UpdateBallWindowRefresh(struct O *);
extern void BTLV_SCU_StartBallWindowClose(struct O *);
extern int BTLV_SCU_UpdateBallWindowClose(struct O *);
extern void BTLV_SCU_ClearWaitWindow(struct Q *q);
extern int BTLV_SCU_GetWaitState(void *);
extern void func_0689B780(void *a, void *b);
void func_021EAC54(E64 *p, u32 a2);
void func_021EAC64(u8 *p, u8 a, int c);
int func_021EAC80(u8 *p, u8 *out);
void func_021EADA4(u8 *p, int a, struct T *b);
int func_021EADB4(u8 *p);
void func_021EADC4(u8 *p);
int func_021EADD4(u8 *p);
void func_021EADE4(u8 *p);
int func_021EADF4(u8 *p);
void func_021EAE04(u32 *p);
int func_021EAE14(void **p);
void func_021EAE24(u8 *p);
int func_021EAE34(u8 *p);
void func_021EAE44(E64 *p);
void func_021EAE54(E64 *p);
void func_021EAE64(E64 *p);
void func_021EAE74(char *p, u32 a, u32 b);
extern u8 ov196_id[], ov198_id[];


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021EAC54(E64 *p, u32 a2) { func_0689B5CC(p[0x6].f0, a2); }


void func_021EAC64(u8 *p, u8 a, int c)
{
    func_021E9984(p, p + 0x10c, 4, a, c);
    p[0x174] = 0;
}


/*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: six veneers at 021EAD44..021EADA4, then six tail stubs
 *   021EADA4/ADB4/ADC4/ADD4/ADE4/ADF4. No C unit may span veneers.
 */
int func_021EAC80(u8 *p, u8 *out)
{
    switch (p[0x174]) {
    case 0:
        func_06899CA4(((struct Obj01694 *)p)->f180, 0);
        func_02034AC4((int)ov196_id);
        p[0x174]++;
        break;
    case 1:
        if (func_06899D04(((struct Obj01694 *)p)->f180)) {
            func_06899D2C(((struct Obj01694 *)p)->f180);
            func_02034AC4((int)ov198_id);
            func_0220F3E8(p + 0x10c);
            p[0x174]++;
        }
        break;
    case 2:
        if (p[0x158]) {
            func_02034A5C((int)ov198_id);
            func_06899CDC(((struct Obj01694 *)p)->f180);
            func_06899D30(((struct Obj01694 *)p)->f180);
            p[0x174]++;
        }
        break;
    case 3:
        if (func_06899D04(((struct Obj01694 *)p)->f180)) p[0x174]++;
        break;
    default:
        *out = p[0x157];
        func_02034A5C((int)ov196_id);
        p[0x174] = 0;
        return 1;
    }
    return 0;
}


void func_021EADA4(u8 *p, int a, struct T *b)
{
    BTLV_SCU_StartBallWindowOpen(*(char * *)&((struct Obj21571 *)p)->f17C, a, b);
}


int func_021EADB4(u8 *p)
{
    return BTLV_SCU_UpdateBallWindowOpen(*(struct O * *)&((struct Obj21572 *)p)->f17C);
}


void func_021EADC4(u8 *p)
{
    BTLV_SCU_StartBallWindowRefresh(*(struct O * *)&((struct Obj21573 *)p)->f17C);
}


int func_021EADD4(u8 *p)
{
    return BTLV_SCU_UpdateBallWindowRefresh(*(struct O * *)&((struct Obj21574 *)p)->f17C);
}


void func_021EADE4(u8 *p)
{
    BTLV_SCU_StartBallWindowClose(*(struct O * *)&((struct Obj21575 *)p)->f17C);
}


int func_021EADF4(u8 *p)
{
    return BTLV_SCU_UpdateBallWindowClose(*(struct O * *)&((struct Obj21576 *)p)->f17C);
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021EAE04(u32 *p) { BTLV_SCU_StartFadeIn(p[0x5f]); }


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; BTLV_SCU_GetWaitState is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EAE14(void **p) { return BTLV_SCU_GetWaitState(p[0x5f]); }


void func_021EAE24(u8 *p)
{
    BTLV_SCU_ClearWaitWindow(((struct Obj21577 *)p)->f17C);
}


int func_021EAE34(u8 *p)
{
    return BTLV_SCU_GetWaitState(((struct Obj21578 *)p)->f17C);
}


/*
 * Resolved: func_0689B670 was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }
 */
void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }


void func_021EAE54(E64 *p) { func_0689B69C(p[0x6].f0); }


/*
 * Resolved: func_0689B790 was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }
 */
void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }


void func_021EAE74(char *p, u32 a, u32 b)
{
    ((struct Obj07847 *)p)->f160 = a;
    ((struct Obj07847 *)p)->f164 = b;
    ((struct Obj07847 *)p)->f16C = 0;
    func_0689B780(((struct Obj07847 *)p)->f180, p + 0x160);
}
