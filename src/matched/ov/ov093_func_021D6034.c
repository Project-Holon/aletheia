/*
 * function: func_021D6034
 * address: 0x021D6034
 * packet: pkt_ov093_021D6034
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021D61F0 0x021D61F0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Slot { u32 a : 3; u32 rest : 29; };
struct UtilSlots;
extern int func_021D7D6C(int);
extern void func_021D61F0(struct UtilSlots *);
void func_021D6034(struct UtilSlots *p, int k, struct Slot v)
{
    if (func_021D7D6C(k)) func_021D61F0(p);
    ((struct Slot *)((u8 *)p + 0x1c))[(u32)k] = v;
    ((u8 *)p + (u32)k)[0xac] = 0;
}
