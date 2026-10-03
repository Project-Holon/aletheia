/*
 * function: func_02174EAC
 * address:  0x02174EAC
 * packet:   pkt_ov011_02174EAC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008494  0x02008494  thumb
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02012BA4  0x02012BA4  thumb
 *   func_02174F54  0x02174F54  thumb ov011
 *   func_02039338  0x02039338  arm
 *   func_020266D4  0x020266D4  thumb
 *
 * Blocker: byte-correct; 0x02008494 is an unlabelled arm9 Thumb thunk
 * (ldr r3,=target; movs r2,#0x20; bx r3), no witness outside the range.
 * Verified C for the leaf: void func_02008494(u8 *a, int b) style thunk;
 * needs Ilias's arm9 leaf filed to promote this to EXACT.
 */

typedef unsigned char u8;

typedef struct Q {
    u8 lo : 6;
    u8 hi : 2;
} Q;

int func_02026478(int a);
int func_02012950(int a, int b);
int func_02008530(int a);
void func_02008494(u8 *a, int b);
int func_020127AC(int a, int b);
void func_02082D44(u8 *a, int b, int c);
void func_02012BA4(int a, int b, int c);
void func_02174F54(u8 *p, int idx, u8 *src, int arg);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 func_02039338(void);
void func_020266D4(u32 a, u32 b);

void func_02174EAC(u8 *p, int idx, u8 *q)
{
    int x;
    int ctx;
    int a;
    int flag;

    ctx = func_02026478(*(int *)(p + 4));
    flag = 0;
    a = func_02012950(ctx, idx);
    if (p[0x8FB] & (1 << idx)) {
        x = func_02008530(a);
        if (x == func_02008530((int)q)) {
            goto skip;
        }
    }
    flag = 1;
skip:
    func_02008494(q, a);
    func_02082D44(q + 0x20, func_020127AC(ctx, idx), 0x10);
    func_02012BA4(ctx, idx, ((Q *)(q + 0x4A))->hi);
    func_02174F54(p, idx, q + 0x30, 1);
    p[0x8FB] |= (u8)(1 << idx);
    if (flag == 1 && idx != func_02039338()) {
        func_020266D4(*(int *)(p + 4), idx);
    }
}
