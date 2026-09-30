/*
 * function: func_021C9744
 * address: 0x021C9744
 * packet: pkt_ov114_021C9744
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D3EFC 0x021D3EFC data a4
 *   d_021D4084 0x021D4084 data a4
 *   d_021CF6D4 0x021CF6D4 data a4
 *   d_021CF78C 0x021CF78C data a4
 *   d_021D4098 0x021D4098 data a4
 *   func_02087C6C 0x02087C6C arm
 *   func_02092344 0x02092344 arm
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */
extern void *d_021D3EFC;
typedef struct { unsigned words[103]; unsigned value; } State;
extern State d_021D4084;
extern unsigned d_021CF6D4[], d_021CF78C[], d_021D4098[];
extern void func_02087C6C(void *);
extern void *func_02092344(void *, const void *, unsigned);
extern void func_021C9EE4(void *, void *);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C9744(unsigned char *p, unsigned x)
{
    func_02087C6C(p + 0x1c);
    func_02092344(d_021D4098, p, 100);
    d_021D4084.value = x;
    func_021C9EE4(d_021D3EFC, d_021CF6D4);
    if (func_021CA470(d_021CF78C, d_021D4084.words[2], d_021D4098, 100, 0) == 0) {
        d_021D4084.words[0] = 10;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}
