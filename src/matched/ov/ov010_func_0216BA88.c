/*
 * function: func_0216BA88
 * address:  0x0216BA88
 * packet:   pkt_ov010_0216BA88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200E394  0x0200E394  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0216BB90  0x0216BB90  thumb  ov010
 *   func_0216BB80  0x0216BB80  thumb  ov010
 *   func_0216BBB4  0x0216BBB4  thumb  ov010
 *   func_0216B970  0x0216B970  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0200E394(void *a0);
extern void *func_0200C0E8(void *sys);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern void func_0216BB90(int index, u8 *out);
extern int func_0216BB80(int index);
extern int func_0216BBB4(int index);
extern u32 func_0216B970();

u16 func_0216BA88(int c)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;
    u32 best;
    void *r7;
    int r4;

    r7 = func_0200E394((void *)c);
    r4 = func_0200C32C(func_0200C0E8((void *)c));
    lim = func_0216BBB4(r4);
    n = (u8)func_0216BB80(r4);
    func_0216BB90(r4, buf);
    best = 1009998;
    for (i = 0; i < n; i++) {
        u32 v = func_0216B970(r7, buf[i]);
        if (v < best) {
            best = v;
        }
    }
    return lim - best;
}
