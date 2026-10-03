/*
 * function: func_021C11B8
 * address: 0x021C11B8
 * packet: pkt_ov110_021C11B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_021C080C 0x021C080C thumb ov110
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021C080C(u8 *,int,int,int);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C724(void *,void *,unsigned,unsigned,void *,unsigned,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
void func_021C11B8(u8 *p,int index,int unused,int flag) {
    void *str;
    u16 color;
    str=func_02045EC0(*(void **)(p+0x60),17);
    func_021C080C(p+0x24,index,6,flag);
    if (flag) {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),14);
        color=0x44e;
    } else {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),13);
        color=0x44d;
    }
    func_0201C724(*(void **)(p+0x5c),func_02045770(*(void **)(p+0x6c+index*4)),0,0,str,*(unsigned *)(p+0x58),color);
    func_02045808(str);
    func_02045374(*(void **)(p+0x6c+index*4));
    func_02041B6C(func_02045730(*(void **)(p+0x6c+index*4)));
    *(int *)(p+0x7c+index*4)=1;
}
