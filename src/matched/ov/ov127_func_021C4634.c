/*
 * unit: yes
 * function: func_021C4634, func_021C464C, func_021C465C, func_021C466C
 * address: 0x021C4634
 * packet: pkt_ov127_021C4634
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C5FE4 0x021C5FE4 data a4
 *   func_0204B8A0 0x0204B8A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void (*const d_021C5FE4[])(u8 *);
extern void func_0204B8A0(void *, u16);
void func_021C4634(u8 *p)
{
    void (*f)(u8 *);
    f = d_021C5FE4[*(u32 *)(p + 12)];
    if (f) f(p);
}
void func_021C464C(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), i);
}
void func_021C465C(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), 4);
}
void func_021C466C(u8 *p, u32 i)
{
    *(u32 *)(p + 16) = i;
    func_0204B8A0(*(void **)(p + 4), i + 5);
}
