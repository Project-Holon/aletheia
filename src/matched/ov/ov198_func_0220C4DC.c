/*
 * function: func_0220C4DC
 * address: 0x0220C4DC
 * packet: pkt_ov198_0220C4DC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_02045770(void *);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
void func_0220C4DC(char *p,int value,int slot,int id,u16 x,s16 y,u32 color)
{
    void *handle;
    void *buf;
    void *text;
    void *context;
    u32 width;
    handle=*(void **)(p+0x1F70+slot*8);
    buf=func_020457B0(16,*(u16 *)(*(char **)p+16));
    text=func_02045EC0(*(void **)(p+0x1EA0),id);
    func_0201EF34(*(void **)(p+0x1EA4),0,value);
    func_0201F250(*(void **)(p+0x1EA4),buf,text);
    if (x==0xFFFF) {
        width=func_02045738(handle);
        x=((width<<3)-func_0201D304(buf,*(u32 *)(*(char **)p+12),0))>>1;
    }
    context=*(void **)(p+0x1EAC);
    func_0201C724(context,func_02045770(*(void **)(p+0x1F70+slot*8)),(s16)x,y,(u32)buf,*(u32 *)(*(char **)p+12),(u16)color);
    *(u8 *)(p+slot*8+0x1F74)=1;
    func_02045808(text);
    func_02045808(buf);
}
