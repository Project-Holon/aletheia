/*
 * function: func_0220C714
 * address: 0x0220C714
 * packet: pkt_ov198_0220C714
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045738 0x02045738 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_022110D4(u8 *,int);
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_02045770(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Bits7 { unsigned char value:7; unsigned char flag:1; };
void func_0220C714(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    void *thirdContext;
    u32 width;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(*(void **)(p+0x1EA0),0x21);
    context=*(void **)(p+0x1EAC);
    func_0201C724(context,func_02045770(*(void **)(p+0x2008)),0,0,(u32)text,*(u32 *)(*(u8 **)p+12),0x3DC0);
    *(u8 *)(p+0x200C)=1;
    func_02045808(text);
    text=func_02045EC0(*(void **)(p+0x1EA0),0x22);
    buf=func_020457B0(8,*(u16 *)(*(u8 **)p+16));
    func_0201EFA4(*(void **)(p+0x1EA4),0,((struct Bits7 *)(elem+0x16))->value,3,0,1);
    func_0201F250(*(void **)(p+0x1EA4),buf,text);
    secondContext=*(void **)(p+0x1EAC);
    func_0201C724(secondContext,func_02045770(*(void **)(p+0x1FC8)),0,0,(u32)buf,*(u32 *)(*(u8 **)p+12),0x3DC0);
    *(u8 *)(p+0x1FCC)=1;
    func_02045808(text);
    func_02045808(buf);
    text=func_02045EC0(*(void **)(p+0x1EA0),0x23);
    thirdContext=*(void **)(p+0x1EAC);
    func_0201C724(thirdContext,func_02045770(*(void **)(p+0x2010)),0,0,(u32)text,*(u32 *)(*(u8 **)p+12),0x3DC0);
    *(u8 *)(p+0x2014)=1;
    func_02045808(text);
    text=func_02045EC0(*(void **)(p+0x1EA0),0x24);
    buf=func_020457B0(14,*(u16 *)(*(u8 **)p+16));
    if (((struct Bits7 *)(elem+0x16))->value<100) {
        func_0201EFA4(*(void **)(p+0x1EA4),0,*(u32 *)(elem+0x24)-*(u32 *)(elem+0x1C),6,1,1);
    } else {
        func_0201EFA4(*(void **)(p+0x1EA4),0,0,6,1,1);
    }
    func_0201F250(*(void **)(p+0x1EA4),buf,text);
    width=func_02045738(*(void **)(p+0x1FD0));
    x=(width<<3)-func_0201D304(buf,*(u32 *)(*(u8 **)p+12),0);
    context=*(void **)(p+0x1EAC);
    func_0201C724(context,func_02045770(*(void **)(p+0x1FD0)),(s16)x,0,(u32)buf,*(u32 *)(*(u8 **)p+12),0x2120);
    *(u8 *)(p+0x1FD4)=1;
    func_02045808(text);
    func_02045808(buf);
}
