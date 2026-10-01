/*
 * unit: yes
 * function: func_021C471C, func_021C4740, func_021C4750, func_021C4760, func_021C4770, func_021C4780
 * address: 0x021C471C
 * packet: pkt_ov127_021C471C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204B8D4(void *, u32);
extern void func_0204B878(void *, u16);
void func_021C471C(u8 *p)
{
    if (*(s16 *)(p + 20) == 0) func_0204B8D4(*(void **)(p + 4), 1);
    else func_0204B878(*(void **)(p + 4), *(u32 *)(p + 16) + 5);
}
void func_021C4740(u8 *p) { func_0204B8D4(*(void **)(p + 4), 8192); }
void func_021C4750(u8 *p) { func_0204B8D4(*(void **)(p + 4), 4096); }
void func_021C4760(u8 *p) { func_0204B8D4(*(void **)(p + 4), 4096); }
void func_021C4770(u8 *p) { func_0204B8D4(*(void **)(p + 4), 32768); }
void func_021C4780(u8 *p) { func_0204B8D4(*(void **)(p + 4), 24576); }
