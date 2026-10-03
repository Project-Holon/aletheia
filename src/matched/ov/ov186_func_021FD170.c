/*
 * function: func_021FD170
 * address: 0x021FD170
 * packet: pkt_ov186_021FD170
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FC754(char *,void *,void *,void *,u16);
void func_021FD170(char *p,char *q,void *text)
{
    u32 font;
    font=func_021FC20C(q);
    func_021FC754(p,(void *)func_021FC214(q),text,(void *)font,0x3dac);
}
