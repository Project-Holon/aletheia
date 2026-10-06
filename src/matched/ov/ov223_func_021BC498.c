/*
 * function: func_021BC498
 * address: 0x021BC498
 * packet: pkt_ov223_021BC498
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses at 0x021BC4BA-0x021BC4D4.
 * symbols:
 *   func_021BC6CC 0x021BC6CC thumb ov223
 *   func_02030EAC 0x02030EAC arm
 *   func_021BC630 0x021BC630 thumb ov223
 *   func_021BC5AC 0x021BC5AC thumb ov223
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021BC6CC(int *);
extern void func_021BC630(char *);
extern void func_021BC5AC(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BC498(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_021BC6CC((int *)(p+2));
    func_021BC630((char *)(p+1));
    func_021BC5AC(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
