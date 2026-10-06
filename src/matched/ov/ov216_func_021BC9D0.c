/*
 * function: func_021BC9D0
 * address: 0x021BC9D0
 * packet: pkt_ov216_021BC9D0
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses at 0x021BC9EA-0x021BCA04.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BCB70 0x021BCB70 thumb ov216
 *   func_021BCAB8 0x021BCAB8 thumb ov216
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021BCB70(char *p);
extern void func_021BCAB8(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BC9D0(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_021BCB70((char *)(p+1));
    func_021BCAB8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
