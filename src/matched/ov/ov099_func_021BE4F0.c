/*
 * function: func_021BE4F0
 * address:  0x021BE4F0
 * packet:   pkt_ov099_021BE4F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_021C27E8  0x021C27E8  thumb  ov099
 *   func_021C2864  0x021C2864  thumb  ov099
 *   func_021C0C7C  0x021C0C7C  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021C27E8(void *, u8);
extern void func_021C2864(void *, u8);
extern void func_021C0C7C(void);

int func_021BE4F0(char *p, int v)
{
    if (v != 0)
        func_0202208C(0, 1, 1, 0, 6, 1, 0x21);
    func_021C27E8(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    func_021C2864(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    func_021C0C7C();
    return 9;
}
