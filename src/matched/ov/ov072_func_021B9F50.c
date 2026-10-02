/*
 * function: func_021B9F50
 * address:  0x021B9F50
 * packet:   pkt_ov072_021B9F50
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the unlabelled follower at 0x021BA028 (push {r4,lr}; getter
 * over func_021B6448) is outside the handed 216-byte extent.
 * Lever: each sprite-animation pick written as if/else of two calls
 * (tail-merged, h load hoisted over the bne), and func_0204B878's second
 * parameter int here (no truncation before the blx).
 *
 * symbols:
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_0204B454  0x0204B454  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BB0E0  0x021BB0E0  thumb  ov072
 *   func_0204B898  0x0204B898  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B95C  0x0204B95C  arm
 */
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 x, y;
} Pt;

extern void func_021B63D0(void *p);
extern void func_0204B454(void *h, Pt *pt, int k);
extern int func_02035D20(u32 *a, u32 *b);
extern void func_020355D8(int v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(void *h);
extern int func_021BB0E0(void *p);
extern u16 func_0204B898(void *h);
extern void func_0204B878(void *h, int a);
extern void func_0204B95C(void *h);

void func_021B9F50(u32 *p, void *q)
{
    u32 x;
    u32 y;
    Pt pt;
    int hit;

    func_021B63D0((void *)p[3]);
    p[6] = -1;
    switch (p[7]) {
    case 0:
        hit = 0;
        func_0204B454((void *)p[5], &pt, 0);
        if (func_02035D20(&x, &y)) {
            if (x - pt.x <= 0x18 && y - pt.y <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        } else if (func_020362DC() & 4) {
            func_020355D8(hit);
            hit = 1;
        }
        if (hit && func_0204B98C((void *)p[5]) == 0 && func_021BB0E0(q) == 0) {
            if (func_0204B898((void *)p[5]) == 7)
                func_0204B878((void *)p[5], 9);
            else
                func_0204B878((void *)p[5], 10);
            func_0204B95C((void *)p[5]);
            p[6] = 7;
            p[7] = 1;
        }
        break;
    case 1:
        if (func_0204B98C((void *)p[5]) == 0) {
            if (func_0204B898((void *)p[5]) == 9)
                func_0204B878((void *)p[5], 8);
            else
                func_0204B878((void *)p[5], 7);
            p[7] = 0;
        }
        break;
    }
}
