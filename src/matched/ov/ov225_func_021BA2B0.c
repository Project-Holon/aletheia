/*
 * function: func_021BA2B0
 * address: 0x021BA2B0
 * packet: pkt_ov225_021BA2B0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021BA240 0x021BA240 thumb ov225
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct PrintSys;struct Descriptor;struct CharBuf;struct MsgBank;struct U16Vec;
extern void func_0201C6EC(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern void func_0201C724(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02045808(struct U16Vec *);
extern void func_021BA240(char *);
void func_021BA2B0(char *p)
{
    void *s;
    func_0201C6EC(*(struct PrintSys **)(*(char **)p+0x18));
    func_02043B5C(func_02045770(*(struct Descriptor **)(p+0x14)),0);
    s=func_02045EC0(*(struct MsgBank **)(*(char **)p+0x1c),2);
    func_0201C724(*(void **)(*(char **)p+0x18),(unsigned)func_02045770(*(struct Descriptor **)(p+0x14)),0,4,(unsigned)s,*(unsigned *)(*(char **)p+0xc),0x3c40);
    func_02045808(s);*(unsigned *)(p+0x1c)=1;func_021BA240(p);
}
