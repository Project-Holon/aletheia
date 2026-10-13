/*
 * function: func_0216A674
 * address:  0x0216A674
 * packet:   pkt_ov010_0216A674
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
 *   func_020120F4  0x020120F4  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021D0DB0  0x021D0DB0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;

extern void *func_020120F4(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore);

int func_0216A674(int a0, int a1)
{
    void *r7;
    int *r6;
    u16 *l0;

    func_0215A5F4((void *)a1);
    r7 = func_0215A5DC((void *)a1);
    r6 = (int *)GAME_DATA_GetListCursor(func_020120F4((const struct Ctx *)r7));
    l0 = func_02159AE8((void *)a0, (void *)a1);
    func_021D0DB0((u32)r7, (u8 *)(*r6), l0, func_02159AE8((void *)a0, (void *)a1));
    return 0;
}
