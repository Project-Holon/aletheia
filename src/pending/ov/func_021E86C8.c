/*
 * function: func_021E86C8
 * address:  0x021E86C8
 * packet:   pkt_ov093_021E86C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 DIFF: image is C8168(a)==0 then B8DDC(b); one cmp r0,#1 followed by BOTH beq ret1 and bne ret0 (two branches, shared single movs r0,#0 tail, 32 bytes). Plain if/&&, ternary, switch and double-test spellings give 30-34 bytes with a single bne. Branch shape not reproduced.
 *
 * symbols:
 *   func_021C8168  0x021C8168  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021C8168(void *p);
extern int func_021B8DDC(int m);

int func_021E86C8(void *a, int b)
{
    if (func_021C8168(a) == 0) {
        switch (func_021B8DDC(b)) {
        case 1:
            return 1;
        default:
            return 0;
        }
    }
    return 0;
}
