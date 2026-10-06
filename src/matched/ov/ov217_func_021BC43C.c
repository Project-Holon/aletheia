/*
 * function: func_021BC43C
 * address: 0x021BC43C
 * packet: pkt_ov217_021BC43C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BBF28 0x021BBF28 thumb ov217
 *   func_021BBF3C 0x021BBF3C thumb ov217
 * Legacy matched forwarders declare (void), but their leading bl forwards r0/r1
 * into 021BBF04/021BBF1C. Preserve caller's object and explicit u8 index.
 */
typedef unsigned char u8;
extern int func_021BBF28(unsigned char *p, unsigned int slot);
extern int func_021BBF3C(u8 *p,u8 slot);
void func_021BC43C(u8 *p)
{
    int i;
    int x;
    int y;
    for(i=0;i<=9;i++) {
        x=func_021BBF28(p,(u8)i);
        y=func_021BBF3C(p,i);
        p[i*4+0x66]=x;
        p[i*4+0x67]=x+0xd8;
        p[i*4+0x64]=y;
        p[i*4+0x65]=y+0x18;
    }
}
