/*
 * function: func_021E01B0
 * address: 0x021E01B0
 * packet: pkt_ov137_021E01B0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021E026A.
 * symbols:
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_02039338 0x02039338 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201EF40 0x0201EF40 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C724(void *,void *,int,int,void *,void *,u16);
extern void func_02045334(struct Descriptor *),func_02045374(void *);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_021DEB10(void *);
extern void *func_02184180(void *,u8);
extern u16 func_02039338(void);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_021E01B0(u8 *p,int message,void *value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=*(void **)(s+16);
    func_0201F02C(*(void **)(s+12),1,func_02184180(func_021DEB10(p),func_02039338()));
    func_0201F02C(*(void **)(s+12),2,value);
    text=func_020457B0(256,114);
    func_02045CAC(*(void **)(s+8),message,text);
    func_0201F250(*(void **)(s+12),*(void **)(s+92),text);
    func_02045808(text);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    owner=*(void **)(s+88);
    data=func_02045770(*(void **)(s+40));
    func_0201C724(owner,data,0,0,*(void **)(s+92),*(void **)(s+4),1088);
    *(u8 *)(s+44)=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}
