/*
 * function: func_021E54E0
 * address: 0x021E54E0
 * packet: pkt_ov177_021E54E0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display registers 04000050/04001050 cleared; DISPCNT 04000000/04001000 read-modify-write at 021E5506-021E5514.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021E564C 0x021E564C thumb ov177
 *   func_021E55C8 0x021E55C8 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_02030EAC(void *);
extern void func_021E564C(int *);
extern void func_021E55C8(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_020307B0(void *);
void func_021E54E0(char *p)
{
    func_02030EAC(*(void **)(p + 0xc));
    func_021E564C((int *)(p + 4));
    func_021E55C8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}
