/*
 * function: func_021B8304
 * address: 0x021B8304
 * packet: pkt_ov106_021B8304
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020452E8 0x020452E8 arm
 *   func_021B8D8C 0x021B8D8C thumb ov106
 *   func_021B89F4 0x021B89F4 thumb ov106
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_021B8B4C 0x021B8B4C thumb ov106
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Node;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern void func_020452E8(struct Descriptor *d);
extern u32 func_021B8D8C(u8 *);
extern void func_021B89F4(u8 *);
extern void func_0204ADA4(void *);
extern void func_021B8B4C(void *);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201D83C(void *);
extern void func_02082BCC(void *,int,int);
void func_021B8304(u8 *p) {
    int i;
    func_02030EAC(*(void **)(p+0x58c));
    for(i=0;i<2;i++)func_020452E8(*(void **)((u8 *)((u32 *)p+i)+0x568));
    for(i=0;i<func_021B8D8C(*(u8 **)(p+0x550));i++)func_021B89F4(p+0x188+i*32);
    func_0204ADA4(*(void **)p);
    func_0204ADA4(*(void **)(p+4));
    func_021B8B4C(p+8);
    func_0201ED04(*(void **)(p+0x588));
    func_0201D83C(*(void **)(p+0x570));
    func_02082BCC(p,0,0x59c);
}
