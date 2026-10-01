/*
 * function: func_021BC650
 * address: 0x021BC650
 * packet: pkt_ov216_021BC650
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCA38 0x021BCA38 thumb ov216
 *   func_021BC614 0x021BC614 thumb ov216
 *   func_0204B6F4 0x0204B6F4 arm
 */
extern void *func_021BCA38(void *);
extern void *func_021BC614(void *,void *,void *,short,short,unsigned char,unsigned char,unsigned char,unsigned short);
extern void func_0204B6F4(void *,int,int);
void func_021BC650(char *p)
{
    void *q=func_021BCA38(*(void **)(p+0x50));
    void *a=func_021BC614(p,q,p+0x80,128,120,0,0,2,0);
    *(void **)(p+0x264)=a;
    func_0204B6F4(a,0,1);
    *(void **)(p+0x268)=func_021BC614(p,q,p+0x5c,96,120,0,1,2,0);
}
