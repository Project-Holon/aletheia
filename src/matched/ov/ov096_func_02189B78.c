/*
 * function: func_02189B78
 * address:  0x02189B78
 * packet:   pkt_ov096_02189B78
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C7DAC  0x021C7DAC  thumb  ov093
 *
 * Lever: the second parameter is a struct pointer; with an int base the
 * loop-invariant b+0xbc/b+0xc0 addresses were hoisted and b spilled.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4, fb8; u8 *fbc, *fc0; int fc4; } Obj;

extern int func_0201134C(int);
struct Cur;
struct QG;
extern void func_020113B0(struct Cur *c, u32 v);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(void *, u8);
extern u8 func_021D5440(u8 *p);
extern int func_021C7DAC(u8 *p, int a, int b, int c);

int func_02189B78(int a, Obj *b) {
    int r;
    int i;
    int c6;
    int c7;
    int c2;
    r = func_0201134C(a);
    for (i = 0; i < func_021D5448((struct QG *)b->fbc); i++) {
        c6 = func_021D54C0(b->fbc, i);
        c7 = func_021D5440(b->fbc);
        c2 = func_021D5440(b->fc0);
        if ((u32)(func_021C7DAC((u8 *)b->fb4, c7, c2, c6) - 4) <= 1) {
            func_020113B0((struct Cur *)a, *(int *)(a + 0x14) + r);
            break;
        }
    }
    return b->fc4;
}
