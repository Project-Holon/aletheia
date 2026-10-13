/*
 * function: func_021CC178
 * address:  0x021CC178
 * packet:   pkt_ov093_021CC178
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_CountRealMoves  0x021D5450  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_GetRealMovePPLost  0x021D5568  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_POKEPARAM_GetRealMoveId  0x021D54D0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Work;
extern u8 BTL_POKEPARAM_CountRealMoves(struct Work *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_POKEPARAM_GetRealMovePPLost(u8 *p, u32 i);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern u32 BTL_POKEPARAM_GetRealMoveId(u8 *p, u8 i);
extern void func_021C88C8(void *a, void *b);

int func_021CC178(void *a, void *m, void *s, int d, u8 n)
{
    u8 id;
    u32 cnt;
    u32 lim;
    u8 *r;

    if (BTL_POKEPARAM_CountRealMoves(m) > n) {
        id = BTL_POKEPARAM_GetPokeId(m);
        cnt = BTL_POKEPARAM_GetRealMovePPLost(m, n);
        lim = (u8)BTL_CALC_GetMonParamWithHeap(s, 0x3b);
        if (lim != 0x7f && cnt > lim)
            cnt = lim;
        if (cnt != 0) {
            r = (u8 *)func_021C88A4(a, 9, id);
            r[4] = cnt;
            r[5] = id;
            r[6] = n;
            r[7] |= 2;
            func_021C8838(r + 8, 2, 390);
            func_021C8860((struct S *)(r + 8), id);
            func_021C8860((struct S *)(r + 8), BTL_POKEPARAM_GetRealMoveId(m, n));
            func_021C88C8(a, r);
            return 1;
        }
    }
    return 0;
}
