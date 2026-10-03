/*
 * function: func_021E1584
 * address: 0x021E1584
 * packet: pkt_ov137_021E1584
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E2018 0x021E2018 data a4
 *   d_021E22B8 0x021E22B8 data a1
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E1540 0x021E1540 thumb ov137
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int a, b; } Pair;
extern const Pair d_021E2018;
extern const char d_021E22B8[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(void *, void (*)(void *, int *), void *, int);
extern void func_021E1540(void *, int *);
void func_021E1584(char *p, int flag)
{
    Pair values = d_021E2018;
    int *q = func_02030734(0x8072, 12, 0, d_021E22B8, 5992);
    q[0] = (int)p;
    q[1] = flag;
    q[2] = ((int *)&values)[flag];
    func_02030DA8(*(void **)(p + 0xd98), func_021E1540, q, 0);
}
