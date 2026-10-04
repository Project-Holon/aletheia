/*
 * function: func_021F3DD4
 * address:  0x021F3DD4
 * packet:   pkt_ov055_021F3DD4
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 */

/*
 * 2026-10-04 (wave D2 lane05): DIFF, 176 bytes, same size, all calls resolve, 28 bytes differ and every one is a register name: the original keeps p in r4 and the cursor value in r5, this build swaps them (p r5, a r4). Tried: local declaration order (3 orders), int vs u32 x, splitting the pre-branch value into a second local. Body logic is believed correct (cursor stepping with bounds test on a 4-halfword rect at p+0x10).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct R { u16 h0, h2, h4, h6; };
extern u32 func_0216D5F8(u32);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern u32 func_021642A4(u32);
extern int func_021641E8(u32);
extern int func_021641F8(u32);
extern void func_0216D410(void *, u32);
extern u32 func_020056EC(u32);
void func_021F3DD4(u8 *p, u32 x)
{
    u32 a;
    u32 t0;
    int xx;
    int yy;
    int y0;
    struct R *r;
    t0 = func_0216D5F8(x);
    xx = func_0216D83C(*(void **)(p + 0xc));
    y0 = func_0216D86C(*(void **)(p + 0xc));
    if (*(u16 *)(p + 0x14) != 0) {
        a = *(u16 *)(p + 0x16);
    } else {
        if (t0 == p[3] || p[3] == func_021642A4(t0)) {
            if (func_020056EC(2) == 0) {
                a = (u16)(t0 + 2);
            } else {
                a = func_021642A4((u16)(t0 + 2));
            }
        } else {
            a = func_021642A4(t0);
        }
    }
    xx = (s16)(xx + func_021641E8(a));
    yy = (s16)(y0 + func_021641F8(a));
    r = *(struct R **)(p + 0x10);
    if (a <= 1) {
        if (yy < r->h0 || yy > r->h2) {
            a = func_021642A4(a);
        }
    } else {
        if (xx < r->h4 || xx > r->h6) {
            a = func_021642A4(a);
        }
    }
    func_0216D410(*(void **)(p + 0xc), (u16)(*(u16 *)(p + 0xa) + a));
    *(u16 *)(p + 0x14) = 1;
    *(u16 *)(p + 0x16) = a;
}
