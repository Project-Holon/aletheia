/*
 * function: func_021BCB70
 * address:  0x021BCB70
 * packet:   pkt_021BCB70
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   MI_CpuFill8   0x02082BCC arm
 */

extern void func_0204B084(void *);
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void MI_CpuFill8(void *, int, int);

void func_021BCB70(char *p)
{
    func_0204B084(*(void **)(p + 4));
    func_0204B1CC(*(void **)(p));
    func_0204A5AC();
    MI_CpuFill8(p, 0, 8);
}
