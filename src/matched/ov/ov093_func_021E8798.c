/*
 * function: func_021E8798
 * address:  0x021E8798
 * packet:   pkt_ov093_021E8798
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8434  0x021C8434  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5C30(struct UtilWork *p);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int func_021D76BC(int key, u32 val);
extern void func_021C8434(u8 *p, int a, int b);

void func_021E8798(int u, void *a, int b, int d)
{
    u8 k;
    u16 m;
    int z;

    z = 4;
    if (b == func_021D775C(4)) {
        if (func_021D775C(0x4e) == 0) {
            if (func_021D5C30(func_021C7CF4(a, b)) == 0) {
                m = func_021D775C(0x12);
                if (WAZA_TOOL_GetFlag(m, z) != 0) {
                    z = 1;
                    if (func_021D76BC(0x40, 1) != 0) {
                        k = func_021D775C(3);
                        func_021C8434(a, b, k);
                        func_021D76BC(0x51, z);
                    }
                }
            }
        }
    }
}
