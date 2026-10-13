/*
 * function: func_02166F1C
 * address:  0x02166F1C
 * packet:   pkt_ov010_02166F1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0202C794  0x0202C794  thumb
 *   func_021A1BE4  0x021A1BE4  thumb  ov021
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 *   GAME_DATA_SetSubscreenMode  0x020129A0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *a);
extern void *func_0215A5DC(void *a);
extern void *func_0215A5E4(void *a);
struct BigObj;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C6C(u8 *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 func_02188C9C(u8 *p);
extern u8 func_0202C794(void *a0, u32 a1);
extern void func_021A1BE4(int a, int b);
extern void func_021A1BDC(int a, int b);
extern void GAME_DATA_SetSubscreenMode(struct BigObj *p, u8 v);

int func_02166F1C(void *a, void *b)
{
    void *s4;
    void *s0;
    void *s8;
    int r7;
    int r4;
    int r5;
    func_0215A5F4(b);
    s4 = func_0215A5DC((void *)b);
    s0 = func_0215A5E4((void *)b);
    s8 = func_0201210C((void *)s4);
    r7 = func_02188C6C((u8 *)s8);
    r4 = func_02159B10(a, b);
    r5 = func_02159B10(a, b);
    if (r4 == 0xFFFF)
        r4 = func_0202C794(s4, func_02188C9C(s8));
    if (r5 != 0)
        func_021A1BE4(r7, r4);
    else
        func_021A1BDC(r7, r4);
    GAME_DATA_SetSubscreenMode(s0, r4 & 0xff);
    return 0;
}
