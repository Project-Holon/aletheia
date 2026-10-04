/*
 * function: func_021BBEF4
 * address: 0x021BBEF4
 * packet: pkt_ov110_021BBEF4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_02005624 0x02005624 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021BBE80 0x021BBE80 thumb ov110
 *   func_021BBE8C 0x021BBE8C thumb ov110
 */
typedef unsigned char u8;
struct Node;
extern void func_02030EAC(struct Node *n);
typedef unsigned int   u32;
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void *func_020056A0(void *, void *, unsigned);
extern void func_021BBE80(void);
extern void func_021BBE8C(void *unused, u8 *p);
void func_021BBEF4(u8 *p, u8 value)
{
    p[0x19c] = 0;
    p[0x19d] = value;
    if (*(void **)(p + 0x1a4)) func_02030EAC(*(void **)(p + 0x1a4));
    *(void **)(p + 0x1a4) = func_02005624((u32)func_021BBE80, (u32)p, 1);
    *(int *)(p + 0x1a8) = 0;
    *(int *)(p + 0x1ac) = 0;
    if (*(void **)(p + 0x1b0)) func_02030EAC(*(void **)(p + 0x1b0));
    *(void **)(p + 0x1b0) = func_020056A0(func_021BBE8C, p, 1);
}
