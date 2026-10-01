/*
 * function: func_021BA178
 * address: 0x021BA178
 * packet: pkt_ov220_021BA178
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BA19E/021BA1A8 hardware DISPCNT masked updates.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA2E4 0x021BA2E4 thumb ov220
 *   func_021BA260 0x021BA260 thumb ov220
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021BA2E4(char *);
extern void func_021BA260(unsigned char *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,unsigned,unsigned);
extern void func_020307B0(void *);
void func_021BA178(unsigned char *p)
{
    func_02030EAC(*(struct Node **)(p+12));
    func_021BA2E4((char *)p+4);
    func_021BA260(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
