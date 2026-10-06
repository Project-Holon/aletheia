/*
 * function: func_0220B3B8
 * address: 0x0220B3B8
 * packet: pkt_ov207_0220B3B8
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses at 0x0220B3D6-0x0220B3EC.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_0220B52C 0x0220B52C thumb ov207
 *   func_0220B4A8 0x0220B4A8 thumb ov207
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
struct Node;
extern void func_02030EAC(struct Node *n);
struct Bank;
extern void func_0220B52C(struct Bank **p);
extern void func_0220B4A8(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_0220B3B8(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_0220B52C((struct Bank **)(p+1));
    func_0220B4A8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
