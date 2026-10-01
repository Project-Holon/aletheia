/*
 * function: func_021B998C
 * address: 0x021B998C
 * packet: pkt_ov182_021B998C
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 read/write at 0x021B99B2..0x021B99C8.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B9B8C 0x021B9B8C thumb ov182
 *   func_021B9AF4 0x021B9AF4 thumb ov182
 *   func_021B9A70 0x021B9A70 thumb ov182
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_02030EAC(void *);
extern void func_021B9B8C(unsigned *);
extern void func_021B9AF4(void *);
extern void func_021B9A70(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *, int, int);
extern void func_020307B0(void *);
void func_021B998C(char *p)
{
    func_02030EAC(*(void **)(p + 0xc));
    func_021B9B8C((unsigned *)(p + 8));
    func_021B9AF4(p + 4);
    func_021B9A70(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}
