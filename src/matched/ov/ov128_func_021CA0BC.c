/*
 * function: func_021CA0BC
 * address: 0x021CA0BC
 * packet: pkt_ov128_021CA0BC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202E940 0x0202E940 thumb
 *   func_0202E9AC 0x0202E9AC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CodeIn;
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
void func_021CA0BC(u8 *p,u16 heap)
{
    *(void **)(p+0x184)=func_0202E940(48,16,0,heap);
    func_0202E9AC(*(void **)(p+0x184),*(u8 **)(p+8),0,32,48);
    *(void **)(p+0x188)=func_0202E940(16,16,0xfffe,heap);
    func_0202E9AC(*(void **)(p+0x188),*(u8 **)(p+8),2,0,16);
}
