/*
 * function: func_021BA368
 * address: 0x021BA368
 * packet: pkt_ov225_021BA368
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 178 compiled bytes followed by two zero alignment bytes at 021BA41A.
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021BA240 0x021BA240 thumb ov225
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;struct Descriptor;struct CharBuf;struct WordSet;struct U16Vec;struct MsgBank;
extern void func_0201C6EC(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern struct WordSet *func_0201EC64(u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *);
extern void func_0201ED04(struct WordSet *);
extern void func_021BA240(char *);
void func_021BA368(char *p)
{
    struct WordSet *words;
    struct U16Vec *str;
    void *slot;
    func_0201C6EC(*(struct PrintSys **)(*(char **)p+0x18));
    func_02043B5C(func_02045770(*(struct Descriptor **)(p+0x14)),0);
    words=func_0201EC64(*(u16 *)(*(char **)p+4));
    slot=func_02045EC0(*(struct MsgBank **)(*(char **)p+0x1c),4);
    str=func_020457B0(16,*(u16 *)(*(char **)p+4));
    func_0201EFA4(words,0,*(u8 *)(p+0xd)+1,1,0,1);
    func_0201EFA4(words,1,*(u8 *)(p+0xc),1,0,1);
    func_0201F250(words,str,slot);
    func_0201C724(*(void **)(*(char **)p+0x18),(u32)func_02045770(*(struct Descriptor **)(p+0x14)),32,4,(u32)str,*(u32 *)(*(char **)p+0xc),0x3c40);
    func_02045808(str);func_02045808(slot);func_0201ED04(words);
    *(u32 *)(p+0x1c)=1;func_021BA240(p);
}
