/*
 * function: func_021BC2B8
 * address: 0x021BC2B8
 * packet: pkt_ov210_021BC2B8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * SDK HW_DTCM integer address arithmetic retains the base symbol and 0x3ff8 offset separately.
 * volatile: 021BC308 reads and 021BC30C writes interrupt-check hardware flag 02FE3FF8.
 * symbols:
 *   d_02FE0000 0x02FE0000 data a4
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
struct S_02021D50;
extern unsigned d_02FE0000[];
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void func_02021D50(struct S_02021D50 *);
extern void func_020434DC(unsigned,unsigned);
extern void func_02043598(unsigned,unsigned);
void func_021BC2B8(void *unused,unsigned char *p)
{
    func_020419E4();
    func_0204A648();
    func_02021D50(*(struct S_02021D50 **)(p+12));
    if (p[0x2b8]==1) {
        func_020434DC(10,1);
        func_02043598(2,1);
        p[0x2b8]=0;
    } else if (p[0x2b8]==2) {
        func_020434DC(10,0);
        func_02043598(2,0);
        p[0x2b8]=0;
    }
    *(volatile unsigned *)((unsigned)d_02FE0000+0x3ff8) |= 1;
}
