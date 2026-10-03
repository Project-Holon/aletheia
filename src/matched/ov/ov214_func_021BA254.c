/*
 * function: func_021BA254
 * address: 0x021BA254
 * packet: pkt_ov214_021BA254
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent-tail: 021BA2B6 alignment padding (two zero bytes).
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_021BA2B8 0x021BA2B8 thumb ov214
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct Rec3;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern int func_021BA2B8(void*,char*);
void func_021BA254(void*obj,char*p,unsigned entry)
{
    func_02043B5C(func_02045770(*(void**)(p+0x6c)),15);
    if(*(void**)(p+0x5c))func_0201CE48(*(void**)(p+0x5c));
    *(int*)(p+0x5c)=0;
    if(*(void**)(p+0x78))func_02045808(*(void**)(p+0x78));
    *(void**)(p+0x78)=func_02045EC0(*(void**)(p+0x58),entry);
    *(int*)(p+0x7c)=0;
    func_0201C6FC(*(void**)(p+0xc),(unsigned)func_02045770(*(void**)(p+0x6c)),0,0,*(void**)(p+0x78),*(unsigned*)(p+8));
    func_021BA2B8(obj,p);
}
