/*
 * function: func_021E1880
 * address: 0x021E1880
 * packet: pkt_ov119_021E1880
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E7984 0x021E7984 data a4
 *   func_02045CAC 0x02045CAC arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 */
typedef short s16;
typedef struct { int v[5]; } T5;
extern const T5 d_021E7984;
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int func_02017E1C(int, int, int);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(int);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
void func_021E1880(int a, int b, int c, int d, char *p)
{
    int i = 0;
    T5 t = d_021E7984;
    for (; i < 5; i++) {
        func_02045CAC(*(void **)(p + 0x720), 0x28, *(void **)(p + 0x734));
        func_0201EFA4(*(void **)(p + 0x724), 0, func_02017E1C(a, t.v[i], 0), 3, 1, 1);
        func_0201F250(*(void **)(p + 0x724), *(void **)(p + 0x730), *(void **)(p + 0x734));
        func_0201C7A4(func_02045770(b), (s16)c, (s16)(d + i * 16), *(void **)(p + 0x730), *(void **)(p + 0x728));
    }
}
