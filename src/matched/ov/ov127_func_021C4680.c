/*
 * unit: yes
 * function: func_021C4680, func_021C4698, func_021C46AC, func_021C46C0, func_021C46D4, func_021C46E8, func_021C46FC, func_021C470C
 * address: 0x021C4680
 * packet: pkt_ov127_021C4680
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B8A0 0x0204B8A0 arm
 *   func_0204B8D4 0x0204B8D4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B8A0(struct Obj *p, u16 v);
extern void func_0204B8D4(struct Obj *p, u32 arg);
void func_021C4680(u8 *p, u32 i)
{
    func_0204B8A0(*(void **)(p + 4), *(u32 *)(p + 16) + 5);
    *(u32 *)(p + 16) = i;
}
void func_021C4698(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), i + 9);
}
void func_021C46AC(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), i + 5);
}
void func_021C46C0(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), i + 5);
}
void func_021C46D4(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), i + 5);
}
void func_021C46E8(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), i + 5);
}
void func_021C46FC(u8 *p) { func_0204B8D4(*(void **)(p + 4), 8192); }
void func_021C470C(u8 *p) { func_0204B8D4(*(void **)(p + 4), 8192); }
