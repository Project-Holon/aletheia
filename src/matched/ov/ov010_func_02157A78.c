/*
 * function: func_02157A78
 * address:  0x02157A78
 * packet:   pkt_ov010_02157A78
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217998C  0x0217998C  thumb ov015
 *   func_02157960  0x02157960  thumb
 *   func_02157A30  0x02157A30  thumb
 *   func_02157A58  0x02157A58  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_020399A8(void *);
struct Link;
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 func_0203D378(void);
extern void func_0217998C(int);
extern void func_02157960(void *, void (*)(void), int);
extern void func_02157A30(void);
extern void func_02157A58(void);

void func_02157A78(u32 *p)
{
    int k = 0x23;
    void *h = func_020399A8(p);

    if (func_02039CB4(h, 0x23, (u8)*p) != 0) {
        if (func_0203D378() != 0) {
            k = 0x12C;
            func_0217998C(k);
            k -= 0x19;
            func_02157960(p, func_02157A30, k);
            return;
        }
        k += 0xF3;
        func_02157960(p, func_02157A58, k);
    }
}
