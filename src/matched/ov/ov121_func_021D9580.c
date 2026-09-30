/*
 * function: func_021D9580
 * address: 0x021D9580
 * packet: pkt_ov121_021D9580
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware rereads at 021D959A..021D95CA
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021DF5E4 0x021DF5E4 data a4
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern const int d_021DF5E4[];
extern void func_020434DC(int,int);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(int,int,int,int,int);
extern void func_02046A94(u8,const void *);
extern void func_02046BE0(int,int);
#define REG (*(volatile u16 *)0x04000060)
void func_021D9580(void)
{
    unsigned i;
    func_020434DC(1,0);
    *(volatile u16 *)0x04000008=(u16)(*(volatile u16 *)0x04000008 &~3);
    REG=(u16)((REG&~0x3002)|2);
    REG&=(u16)~0x3010;
    REG&=(u16)~0x3004;
    REG=(u16)((REG&~0x3000)|8);
    REG&=(u16)~0x3020;
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) func_02046A94(i,d_021DF5E4+i*2);
    func_02046BE0(0,0);
}
