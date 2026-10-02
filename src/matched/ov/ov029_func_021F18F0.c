/*
 * function: func_021F18F0
 * address: 0x021F18F0
 * packet: pkt_ov029_021F18F0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F2DA8 0x021F2DA8 thumb ov029
 *   func_021F1758 0x021F1758 thumb ov029
 */
typedef unsigned char u8;
extern int func_021F2DA8(void *p);
extern void func_021F1758(u8 *p, int key);
void func_021F18F0(int key, int flag, u8 *p)
{
    if (func_021F2DA8(p) == 0 && flag == 0)
        func_021F1758(p, key);
}
