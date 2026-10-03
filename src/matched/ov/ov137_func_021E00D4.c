/*
 * function: func_021E00D4
 * address: 0x021E00D4
 * packet: pkt_ov137_021E00D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021E012E follow the 90-byte function.
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021E03A0 0x021E03A0 thumb ov137
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_020450C8 0x020450C8 arm
 */
typedef unsigned char u8;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void *func_02045730(void *);
extern void func_020409B4(void *);
extern void func_020452E8(struct Descriptor *d);
extern void func_021E03A0(u8 *);
extern void func_02045C04(void *),func_0201ED04(void *),func_0201D83C(void *),func_02045808(void *);
extern void func_020450C8(void);
void func_021E00D4(u8 *p)
{
    u8 *s;
    void *obj;
    int i;
    s=p+3296;
    obj=*(void **)(s+16);
    func_020456F8(obj);
    func_020409B4(func_02045730(obj));
    func_020452E8(*(void **)(s+16));
    func_021E03A0(p);
    func_02045C04(*(void **)(s+8));
    func_0201ED04(*(void **)(s+12));
    func_0201D83C(*(void **)(s+4));
    func_02045808(*(void **)(s+92));
    for(i=0;i<5;i++) func_02045808(*(void **)(p+164+i*4));
    func_020450C8();
}
