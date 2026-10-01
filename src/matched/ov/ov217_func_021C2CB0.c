/*
 * function: func_021C2CB0
 * address: 0x021C2CB0
 * packet: pkt_ov217_021C2CB0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021C2CEE..021C2CF0 is two zero alignment bytes.
 * Callee 02021F64's legacy Rgb555 aggregate input reads only its low
 * stack halfword; scalar u16 preserves the original caller's str word.
 * symbols:
 *   func_02021F64 0x02021F64 thumb
 *   func_021C2A28 0x021C2A28 thumb ov217
 *   func_021C2D88 0x021C2D88 thumb ov217
 */
struct Rgb555 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};
extern void func_02021F64(unsigned short *, unsigned short *, unsigned int, int, unsigned short);
extern void func_021C2A28(void *);
extern int func_021C2D88(char *);
void func_021C2CB0(char *p)
{
    int weight = ((*(unsigned int *)(p + 0x1c) >> 2) & 1) == 0 ? 0 : 9;
    func_02021F64(*(unsigned short **)(p + 12), *(unsigned short **)(p + 8), *(unsigned char *)(p + 16), weight, *(unsigned short *)(p + 18));
    if (++*(unsigned int *)(p + 0x1c) > 20) {
        func_021C2A28(p);
        func_021C2D88(p);
    }
}
