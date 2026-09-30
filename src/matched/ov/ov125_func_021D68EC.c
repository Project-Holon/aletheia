/*
 * function: func_021D68EC
 * address: 0x021D68EC
 * packet: pkt_ov125_021D68EC
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D730C 0x021D730C thumb ov125
 *   d_021D8D28 0x021D8D28 data a4
 *   d_021D8C80 0x021D8C80 data a2
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021D730C(void *);
extern void func_02034714(const char *, int, const char *);
extern void func_02082BCC(void *, int, unsigned int);
extern const char d_021D8D28[];
extern const u16 d_021D8C80[][2];
int func_021D68EC(char *p, int id, unsigned int index, int mode, u8 other)
{
    if (!func_021D730C(p)) return 0;
    if (index >= 20) func_02034714(d_021D8D28, 0, d_021D8D28);
    func_02082BCC(p + 0x174, 0, 16);
    *(u16 *)(p + 0x174) = id;
    *(u16 *)(p + 0x176) = d_021D8C80[index][0];
    *(u16 *)(p + 0x178) = d_021D8C80[index][1];
    *(u8 *)(p + 0x17a) = mode;
    *(u8 *)(p + 0x17b) = other;
    *(int *)(p + 0x17c) = 100;
    *(int *)(p + 0x3e0) = 0;
    *(int *)(p + 0x3d8) = 0x55f1;
    return 1;
}
