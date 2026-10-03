/*
 * function: func_021D505C
 * address: 0x021D505C
 * packet: pkt_ov120_021D505C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4988 0x021D4988 thumb ov120
 *   func_021D8638 0x021D8638 thumb ov120
 *   func_0203C554 0x0203C554 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4FF4 0x021D4FF4 thumb ov120
 */
typedef unsigned char u8;
extern void func_021D4988(int);
extern void func_021D8638(u8 *);
typedef unsigned int   u32;
extern void func_0203C554(u32 a);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4FF4(int);
void func_021D505C(int a, int b, int p)
{
    if (b == 0 && *(void (**)(int))p == func_021D4988) {
        func_021D8638(*(u8 **)(p + 0x40));
        func_0203C554(1);
        func_020355D8(1);
        func_020061E4(0x551);
        func_021D4244(p, func_021D4FF4, 0x5f5);
    }
}
