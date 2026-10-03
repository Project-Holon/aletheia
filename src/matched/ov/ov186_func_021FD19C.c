/*
 * function: func_021FD19C
 * address: 0x021FD19C
 * packet: pkt_ov186_021FD19C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021FC20C(void *);
extern void func_021FC7C4(char *,void *,void *,u16);
void func_021FD19C(char *p,void *q,void *text)
{
    func_021FC7C4(p,text,(void *)func_021FC20C(q),0x3dac);
}
