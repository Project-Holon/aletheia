/*
 * function: func_021F1290
 * address:  0x021F1290
 * packet:   pkt_ov029_021F1290
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-05 (wD5 lane18): tried k = call result as a local with `for (i = 0, xx = x; ...)` and pal computed inside the outer body (LICM preheader order is what the original shows: x to ip, i=0, then v*5): 176 B, 116 differ, v spilled to [sp,#0x10]. xx/i before v (64), xx/i after v (67), still no gain. Residue unchanged: original schedules `ldr x; mov ip; i=0` before the v*5 arithmetic.
 *
 * 2026-10-04 (wD1 lane 11): 29 of 172 bytes differ, pure scheduling and
 * colouring, same length and same stack frame. The original loads x ([sp,#0x10])
 * into ip and stores i=0 to [sp,#8] BEFORE the pal arithmetic (the v*5 row
 * address); ours does that after pal. The outer-loop locals then colour
 * i*32 in r4 and the row pointer in r5 in the original, swapped in ours.
 * What closed the earlier gap (89 -> 29): separate copy xx = x for the loop,
 * declaration order y, x, xx, v, pal, i, yy, j, buf after the ints, a local
 * o = i * 32, yy as a separate counter. Tried without gain: hoisting
 * xx=x/i=0 above pal (57/67), a k local for the 0C70 result (116), operand
 * order of the final or, for-with-comma form.
 *
 * 2026-10-05 (wD4 lane 15): tried a k local for the func_021F0C70 result with xx = x; i = 0 after the call and before pal
 * (176 B, v spills), the same with pal computed inside the outer loop so LICM hoists it (176 B). The extra local
 * costs 4 bytes and spills v. Residue unchanged at 29 bytes: original has x loaded to ip and i=0 stored before the pal
 * arithmetic, and `orrs r1,r6` uses pal<<12 in place (ours copies it with an extra adds).
 *
 * symbols:
 *   func_021F0D14  0x021F0D14  thumb  ov029
 *   func_021F0C70  0x021F0C70  thumb  ov029
 *   func_0204162C  0x0204162C  arm
 *   d_021F3354     0x021F3354  data  a4
 *   d_021F31D4     0x021F31D4  data  a2
 *   d_021F323C     0x021F323C  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int w[6]; } Tab;

extern const Tab d_021F3354;
extern const u16 d_021F31D4[];
extern const u8 d_021F323C[];
extern void func_021F0D14(int a, int b, int *x, int *y);
extern int func_021F0C70(void *p, int i, int j, int k);
extern u16 *func_0204162C(int channel);

void func_021F1290(void *q, int a, int b, int c)
{
    Tab t = d_021F3354;
    int y, x, xx, v, pal, i, yy, j;
    u16 *buf;

    buf = func_0204162C(4);
    func_021F0D14(a, b, &y, &x);
    v = d_021F31D4[c];
    pal = (d_021F323C + v * 5)[func_021F0C70(q, v, a, b)];
    xx = x;
    for (i = 0; i < 4; i++) {
        int o = i * 32;
        u16 *row = buf + xx * 32;
        yy = y;
        for (j = 0; j < 4; j++) {
            if (yy >= 0 && yy < 0x20)
                row[yy] = (t.w[c] + o + j) | (pal << 12);
            yy++;
        }
        xx++;
    }
}
