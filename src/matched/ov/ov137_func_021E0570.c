/*
 * function: func_021E0570
 * address: 0x021E0570
 * packet: pkt_ov137_021E0570
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E15DC 0x021E15DC thumb ov137
 */
typedef unsigned char u8;
typedef short s16;
extern void func_021E15DC(int *,int);
void func_021E0570(u8 *p)
{
    u8 *s;
    int angle;
    s=p+224;
    angle=*(int *)(p+88);
    func_021E15DC(&angle,*(int *)(s+64));
    func_021E15DC(&angle,*(int *)(s+68));
    *(s16 *)(s+78)=(360-angle/4096)%360;
    *(int *)(s+12)=*(int *)(p+224)+*(int *)(s+48)+*(int *)(s+36);
    *(int *)(s+16)=*(int *)(s+4)+*(int *)(s+52)+*(int *)(s+40);
    *(int *)(s+20)=*(int *)(s+8)+*(int *)(s+56)+*(int *)(s+44);
}
