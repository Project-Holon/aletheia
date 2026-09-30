/*
 * function: func_021C94A0
 * address: 0x021C94A0
 * packet: pkt_ov114_021C94A0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D3EFC 0x021D3EFC data a4
 *   d_021D4084 0x021D4084 data a4
 *   d_021CF6D4 0x021CF6D4 data a4
 *   d_021CF734 0x021CF734 data a4
 *   d_021D4098 0x021D4098 data a4
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */
extern void *d_021D3EFC;
typedef struct {
    unsigned words[5];
    unsigned char first, second;
    unsigned char gap[0x186];
    unsigned value;
} State;
extern State d_021D4084;
extern unsigned d_021CF6D4[], d_021CF734[], d_021D4098[];
extern void func_021C9EE4(void *, void *);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C94A0(unsigned x, unsigned y, unsigned z)
{
    d_021D4084.value = z;
    d_021D4084.first = x - 1;
    d_021D4084.second = y - 1;
    func_021C9EE4(d_021D3EFC, d_021CF6D4);
    if (func_021CA470(d_021CF734, d_021D4084.words[2], d_021D4098, 2, 0) == 0) {
        d_021D4084.words[0] = 4;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}
