/*
 * function: func_021B6824
 * address: 0x021B6824
 * packet: pkt_ov174_021B6824
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 * symbols:
 *   func_02028604 0x02028604 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_0201DD68 0x0201DD68 thumb
 */
typedef unsigned char u8;
extern void func_02028604(void *),func_0201C4C0(void *),func_0201CE48(void *),func_02045808(void *),func_0201ED04(void *),func_02045C04(void *),func_020452E8(void *),func_0201D83C(void *),func_02031140(void *);
extern void func_0201DD68(void);
void func_021B6824(u8 *p)
{
    func_02028604(*(void **)(p+124));
    func_0201C4C0(*(void **)(p+120));
    if(*(void **)(p+100)) func_0201CE48(*(void **)(p+100));
    if(*(void **)(p+112)) func_02045808(*(void **)(p+112));
    if(*(void **)(p+116)) func_0201ED04(*(void **)(p+116));
    func_02045C04(*(void **)(p+108));
    func_02045C04(*(void **)(p+104));
    if(*(void **)(p+92)) func_020452E8(*(void **)(p+92));
    func_0201D83C(*(void **)(p+96));
    func_02031140(*(void **)(p+88));
    func_0201DD68();
}
