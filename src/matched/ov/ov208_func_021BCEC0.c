/*
 * function: func_021BCEC0
 * address: 0x021BCEC0
 * packet: pkt_ov208_021BCEC0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware writes 021BCEE4/021BCEEA and read-modify-write 021BCEEC/021BCEF4, 021BCEF6/021BCEFA.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BCF6C 0x021BCF6C thumb ov208
 *   func_021BD07C 0x021BD07C thumb ov208
 *   func_021BCFF8 0x021BCFF8 thumb ov208
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_02030EAC(void *);
extern void func_021BCF6C(void *);
extern void func_021BD07C(void *);
extern void func_021BCFF8(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
extern void func_020307B0(unsigned);
void func_021BCEC0(char *p)
{
    func_02030EAC(*(void **)(p+0xc));
    func_021BCF6C(p);
    func_021BD07C(p+4);
    func_021BCFF8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,0x14);
    func_020307B0((unsigned)p);
}
