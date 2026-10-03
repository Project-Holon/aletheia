/*
 * function: func_021C7558
 * address: 0x021C7558
 * packet: pkt_ov128_021C7558
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void func_0201CE48(struct Rec3 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void func_02045808(struct U16Vec *vec);
extern void func_021CA3E8(int);
void func_021C7558(u8 *p,u8 *ctx,unsigned v,unsigned heap)
{
    void *buf;
    void *obj;
    int font;
    if(*(void **)(ctx+0x2c)) {
        func_0201CE48(*(void **)(ctx+0x2c));
        *(void **)(ctx+0x2c)=0;
    }
    buf=func_020457B0(128,heap);
    func_02043B5C(func_02045770(*(void **)(p+0x1c)),15);
    func_02045CAC(*(void **)(ctx+4),v,buf);
    func_0201F250(*(void **)ctx,*(void **)(p+0x2c),buf);
    font=func_02012FFC();
    *(void **)(ctx+0x2c)=func_0201CCE4(*(void **)(p+0x1c),0,0,*(void **)(p+0x2c),*(void **)(ctx+0x17c),font,*(void **)(ctx+0x28),10,*(u16 *)(ctx+0x180),0);
    func_0201F73C(*(void **)(p+0x1c),2,70,11);
    obj=*(void **)(p+0x1c);
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
    func_02045808(buf);
    func_021CA3E8(0);
}
