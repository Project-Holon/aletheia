/*
 * function: func_021DE128
 * address: 0x021DE128
 * packet: pkt_ov121_021DE128
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note pass 2 2026-10-06 P2L16: closed from 7/44. The function returns void (the only
 *   caller, ov121 021DD9CC, declares it void) and the +0 halfword is a direct copy
 *   `*(u16 *)p = *(u16 *)(p+2)` at its store position; the scheduler hoists the ldrh.
 *   The 11 store after the two b stores gives the image colours (b r7, c r4, d r6).
 *   The earlier u16 t local and return form stayed at 7 for every variant.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,u32);
void func_021DE128(u8 *p,u16 b,int c,int d)
{
    func_02082BCC(p,0,44);
    *(u16 *)(p+2)=b;
    *(u16 *)(p+4)=b;
    *(u16 *)(p+10)=11;
    *(int *)(p+20)=c;
    *(int *)(p+24)=d;
    *(int *)(p+28)=c;
    *(int *)(p+32)=d;
    *(u16 *)p=*(u16 *)(p+2);
    *(int *)(p+36)=c;
    *(int *)(p+40)=d;
}
