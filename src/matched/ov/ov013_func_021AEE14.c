/*
 * function: func_021AEE14
 * address:  0x021AEE14
 * packet:   pkt_ov013_021AEE14
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frame step: records the input halfword at G+0x19B0, accumulates the
 * elapsed microseconds past one 60 Hz frame (16666 us) at G+0x1A44 since
 * the tick stamped at G+0x1A3C, runs func_021B386C once per whole frame
 * owed, then advances the state machine at G+0x19AC unless G+0x19A8 is 3.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021B386C  0x021B386C  arm  ov013
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_021AEC74  0x021AEC74  thumb  ov013
 *   func_021AECC4  0x021AECC4  thumb  ov013
 *   d_021B3C80     0x021B3C80  data  ov013
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

struct Work {
    u8 pad0000[0x19A8];
    s32 f19A8;
    s32 f19AC;
    u16 f19B0;
    u8 pad19B2[0x1A3C - 0x19B2];
    u64 f1A3C;
    s32 f1A44;
    u16 f1A48;
};

extern struct Work *d_021B3C80;

extern u64 func_020870D0(void);
extern void func_021B386C(void);
extern unsigned char func_0216B838(void);
extern int func_021AEC74(int x);
extern int func_021AECC4(int x);

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
