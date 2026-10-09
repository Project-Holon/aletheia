/*
 * file:     unit_021AEB20_p03.c
 * unit:     yes
 * function: func_021AEDEC, func_021AEE14, func_021AEF44
 * address:  0x021AEDEC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B3C80 0x021B3C80 data ov013 a4
 *   func_021B074C 0x021B074C arm ov013
 *   func_021B1F54 0x021B1F54 arm ov013
 *   func_02156400 0x02156400 thumb ov009
 *   func_020870D0  0x020870D0  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021B386C  0x021B386C  arm  ov013
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_021AEC74  0x021AEC74  thumb  ov013
 *   func_021AECC4  0x021AECC4  thumb  ov013
 *   func_021B38B0 0x021B38B0 arm ov013
 */
#include "../../matched/include/G_Work.h"
#include "../../matched/include/G_Work.h"

struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

typedef unsigned long long u64;

extern void func_021B074C(void *);
extern int func_021B1F54(struct Node *);
extern void func_02156400(void);
extern u64 func_020870D0(void);
extern void func_021B386C(void);
extern unsigned char func_0216B838(void);
extern int func_021AEC74(int x);
extern int func_021AECC4(int x);
extern int func_021B38B0(int a, int b, int c);
void func_021AEDEC(struct Node *p);
/* * Frame step: records the input halfword at G+0x19B0, accumulates the * elapsed microseconds past one 60 Hz frame (16666 us) at G+0x1A44 since * the tick stamped at G+0x1A3C, runs func_021B386C once per whole frame * owed, then advances the state machine at G+0x19AC unless G+0x19A8 is 3. */ void func_021AEE14(int input);
int func_021AEF44(int a, int b, int c);
extern struct Work *d_021B3C80;


void func_021AEDEC(struct Node *p)
{
    func_021B074C(p);
    func_021B1F54(p);
    *(int *)(((u8 *)d_021B3C80) + 0x1A1C) = 0;
    func_02156400();
}



/*
 * Frame step: records the input halfword at G+0x19B0, accumulates the
 * elapsed microseconds past one 60 Hz frame (16666 us) at G+0x1A44 since
 * the tick stamped at G+0x1A3C, runs func_021B386C once per whole frame
 * owed, then advances the state machine at G+0x19AC unless G+0x19A8 is 3.
 */
void func_021AEE14(int input)
{
    u64 tick;

    d_021B3C80->f19B0 = input;
    tick = func_020870D0();
    d_021B3C80->f1A44 +=
        (s32)(((u32)tick - (u32)d_021B3C80->f1A3C) * 64000 / 33514) - 16666;
    if (d_021B3C80->f1A44 < -10000) {
        d_021B3C80->f1A44 = 0;
    }
    d_021B3C80->f1A3C = tick;
    func_021B386C();
    while (d_021B3C80->f1A44 >= 16666) {
        func_021B386C();
        d_021B3C80->f1A44 -= 16666;
    }
    if (d_021B3C80->f19A8 == 3) {
        return;
    }
    switch (d_021B3C80->f19AC) {
    case 0:
        if (func_0216B838() == 0) {
            if (func_021AEC74(1) != 0) {
                d_021B3C80->f19AC = 1;
                d_021B3C80->f1A48 = 60;
            }
        } else if (func_0216B838() == 1) {
            if (func_021AECC4(0) != 0) {
                d_021B3C80->f19AC = 2;
            }
        }
        break;
    case 1:
        d_021B3C80->f1A48 -= 1;
        if (d_021B3C80->f1A48 == 0) {
            d_021B3C80->f19AC = 0;
        }
        break;
    case 2:
        break;
    }
}

/*
 * Narrow first callee argument follows the explicit lsls/lsrs at 021AEF52;
 * the other two inputs stay live from entry for the three-input callee.
 */
int func_021AEF44(int a, int b, int c)
{
    if (d_021B3C80 == 0) return 0;
    if (func_021B38B0((unsigned char)a, b, c) != 0) return 1;
    return 0;
}
