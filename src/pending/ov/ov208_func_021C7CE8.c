/*
 * function: func_021C7CE8
 * address: 0x021C7CE8
 * packet: pkt_ov208_021C7CE8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: arm9 02014CEC Thumb verified EXACT4 in S27 blocker1 log
 *   typedef unsigned int u32;
 *   void func_02014CEC(char *p, u32 value) { *(u32 *)(p + 8) = value; }
 * symbols:
 *   func_021C51A0 0x021C51A0 thumb ov208
 *   func_021C51C8 0x021C51C8 thumb ov208
 *   ov208_func_021C569C 0x021C569C thumb ov208
 *   func_02014CEC 0x02014CEC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C51A0(u8 *, u32);
extern void func_021C51C8(u32, int, u8 *);
extern void ov208_func_021C569C(u16 *, u8 *, int, int, int, int, u16);
extern void func_02014CEC(u32, u32);
void func_021C7CE8(u16 *a0, u8 *p, int key)
{
    int a;
    int b;
    if (*(u32 *)(p + 0x6B8) != 0) return;
    func_021C51A0(p + 0x94, *(u32 *)(p + 8));
    func_021C51A0(p + 0xD8, *(u32 *)(p + 8));
    func_02014CEC(*(u32 *)(p + 8), 0);
    a = *(u32 *)(p + 0x124) != 0 ? 2 : 4;
    b = *(u32 *)(p + 0x124) != 0 ? 4 : 3;
    ov208_func_021C569C(a0, p, key, a, b, 2, *(u16 *)(p + 0x550));
    if (a != 4) func_021C51C8(*(u32 *)(p + 0x98), 2, p);
    if (b != 4) func_021C51C8(*(u32 *)(p + 0xDC), 3, p);
    func_02014CEC(*(u32 *)(p + 8), *(u32 *)(p + 0x120));
}
