/*
 * function: func_021C41C0
 * address:  0x021C41C0
 * packet:   pkt_ov093_021C41C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C4208  0x021C4208  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern int func_021C4208(u8 *p, int i);
extern void func_021C5D88(u8 *p, u8 *a, int b);
extern void func_021D6D70(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);

void func_021C41C0(u8 *p, u8 *a)
{
    int i = func_021D5440(a);
    int r = func_021C4208(p + 0x1ab8, i);
    func_021C5D88(p, a, 0x31a);
    func_021D6D70(a);
    func_021CD4B0(*(void **)(p + 0xc), 0x28, i);
    func_021CD4B0(*(void **)(p + 0xc), 0x52, r);
}
