/*
 * function: func_021C4BFC
 * address: 0x021C4BFC
 * packet: pkt_ov136_021C4BFC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 0x021C4C9A..0x021C4C9C is a zero alignment halfword.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_021C4DE4 0x021C4DE4 thumb ov136
 *   func_021C4EEC 0x021C4EEC thumb ov136
 *   func_021C515C 0x021C515C thumb ov136
 *   func_021C5420 0x021C5420 thumb ov136
 *   func_021C4D54 0x021C4D54 thumb ov136
 *   func_021C5360 0x021C5360 thumb ov136
 *   func_021C5268 0x021C5268 thumb ov136
 *   func_021C4C9C 0x021C4C9C thumb ov136
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045B38(int, int, int, u32);
extern void *func_020457B0(int, u32);
extern void func_021C4DE4(u8 *);
extern void func_021C4EEC(u8 *);
extern void func_021C515C(u8 *);
extern void func_021C5420(u8 *);
extern void *func_02027F60(int, int, void *, void *, u16);
extern void func_021C4D54(u8 *);
extern void func_021C5360(u8 *);
extern void func_021C5268(u8 *);
extern void func_021C4C9C(u8 *);
int func_021C4BFC(u8 *p)
{
    switch (*(u16 *)(p + 8)) {
    case 0:
        *(void **)(p + 0x20) = func_02045B38(0, 2, 60, (u16)*(u32 *)p);
        *(void **)(p + 0x34) = func_020457B0(128, (u16)*(u32 *)p);
        func_021C4DE4(p);
        break;
    case 1:
        func_021C4EEC(p);
        break;
    case 2:
        func_021C515C(p);
        break;
    case 3:
        func_021C5420(p);
        *(void **)(p + 0x108) = func_02027F60(0, 8, *(void **)(p + 0x24), *(void **)(p + 0x98), (u16)*(u32 *)p);
        *(u16 *)(p + 8) = 0;
        func_021C4D54(p);
        func_021C5360(p);
        func_021C5268(p);
        func_021C4C9C(p);
        return 1;
    }
    (*(u16 *)(p + 8))++;
    return 0;
}
