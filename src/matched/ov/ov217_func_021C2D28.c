/*
 * function: func_021C2D28
 * address: 0x021C2D28
 * packet: pkt_ov217_021C2D28
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Original truncates weight to u8 before calling 02021F64; its legacy
 * Rgb555 stack input reads only the low halfword, so scalar u16 keeps
 * the original caller's full-word str without aggregate partial stores.
 * symbols:
 *   func_02021F64 0x02021F64 thumb
 *   func_021C2A28 0x021C2A28 thumb ov217
 *   func_021C2D88 0x021C2D88 thumb ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
struct Rgb555 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};
extern void func_02021F64(unsigned short *, unsigned short *, unsigned int, unsigned char, unsigned short);
extern void func_021C2A28(void *);
extern int func_021C2D88(char *);
void func_021C2D28(char *p)
{
    unsigned int weight = 7 - *(unsigned int *)(p + 0x1c) * 7 / 30;
    func_02021F64(*(unsigned short **)(p + 12), *(unsigned short **)(p + 8), *(unsigned char *)(p + 16), weight, *(unsigned short *)(p + 18));
    if (++*(unsigned int *)(p + 0x1c) > 30) {
        func_021C2A28(p);
        func_021C2D88(p);
    }
}
