/*
 * function: func_021E7E58
 * address:  0x021E7E58
 * packet:   pkt_ov093_021E7E58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021C8300  0x021C8300  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 *   func_021B99F0  0x021B99F0  thumb  ov093
 *   func_021C8020  0x021C8020  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C815C(int *p);
extern u8 func_021B8DDC(u32 x);
extern u32 func_021C8300(int *p, u8 k);
extern u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v);
extern u32 func_021B99F0(u32 x);
extern int func_021C8020(void *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E7E58(int a, u8 *b, int c)
{
    int x, y;
    u32 k;
    u8 *p;

    x = func_021C8010(b, c);
    y = c;
    switch (func_021C815C((int *)b)) {
    case 1:
        if (func_021C8300((int *)b, func_021B8DDC(c)) == 4) {
            k = BTL_MAIN_GetOwnLanePos(x, 0);
            if (k == x)
                k = BTL_MAIN_GetOwnLanePos(x, 1);
            y = func_021C8020(b, k);
        }
        break;
    case 2:
        if (func_021B99F0(x) == 0) {
            k = BTL_MAIN_GetOwnLanePos(x, 0);
            if (k == x)
                k = BTL_MAIN_GetOwnLanePos(x, 2);
            y = func_021C8020(b, k);
        }
        break;
    }
    if (y != c) {
        p = func_021C88A4((char *)b, 0x32, c);
        p[4] = c;
        p[5] = y;
        func_021C8838(p + 8, 2, 1137);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), y);
        func_021C88C8(b, p);
    }
}
