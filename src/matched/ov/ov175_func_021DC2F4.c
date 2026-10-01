/*
 * function: func_021DC2F4
 * address: 0x021DC2F4
 * packet: pkt_ov175_021DC2F4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0208D7E0 0x0208D7E0 arm
 *   d_021E2FA4 0x021E2FA4 data a1
 */
extern void func_02082BCC(void *,int,int);
extern int func_0208D7E0(char *,const char *,...);
extern const char d_021E2FA4[];
void func_021DC2F4(char *p,unsigned a)
{
    *(int *)(p+0x12c)=0;
    *(int *)(p+0x1458)=0;
    func_02082BCC(p+0x144c,0,10);
    func_02082BCC(p+0x1390,0,0xb0);
    func_0208D7E0(p+0x144c,d_021E2FA4,a);
}
