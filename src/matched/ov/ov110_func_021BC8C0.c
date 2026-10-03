/*
 * function: func_021BC8C0
 * address: 0x021BC8C0
 * packet: pkt_ov110_021BC8C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0207D63C(void *, int, int, int, int);
void func_021BC8C0(void *task, u8 *p)
{
    int level;
    if (*(int *)(p + 20) != 0) {
        *(int *)(p + 8) += *(int *)(p + 16);
        level = *(int *)(p + 8) >> 3;
        *(int *)(p + 20) -= 1;
    } else {
        level = *(int *)(p + 12) >> 3;
    }
    if (level > 16) level = 16;
    func_0207D63C((void *)0x04000050, *(int *)(p + 0), *(int *)(p + 4), level, 16 - level);
}
