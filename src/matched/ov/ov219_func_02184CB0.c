/*
 * function: func_02184CB0
 * address: 0x02184CB0
 * packet: pkt_ov219_02184CB0
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02184C8C 0x02184C8C thumb ov219
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201DD78 0x0201DD78 thumb
 */
struct TaskMenuState;struct U16Vec;struct Descriptor;
extern void func_02184C8C(char *,int),func_02027FD8(struct TaskMenuState *);
extern void func_02045808(struct U16Vec *),func_020452E8(struct Descriptor *),func_020403F4(unsigned);
extern void func_0201D83C(void *),func_0201DD78(unsigned,unsigned,unsigned);
void func_02184CB0(char *p)
{
    func_02184C8C(p,0);func_02184C8C(p,1);
    func_02027FD8(*(struct TaskMenuState **)(p+0xc058));
    func_02045808(*(struct U16Vec **)(p+0xc064));func_02045808(*(struct U16Vec **)(p+0xc068));
    *(unsigned *)(p+0xc05c)=0;*(unsigned *)(p+0xc060)=0;
    func_020452E8(*(struct Descriptor **)(p+0xc01c));
    func_020403F4(2);func_020403F4(6);func_020403F4(3);func_020403F4(7);
    func_0201D83C(*(void **)(p+0xc06c));
    func_0201DD78((unsigned char)p[0xc084],(unsigned char)p[0xc085],(unsigned char)p[0xc086]);
}
