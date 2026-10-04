/*
 * function: func_0220CDF0
 * address: 0x0220CDF0
 * packet: pkt_ov198_0220CDF0
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
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_0220CDF0(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(*(void **)(p+0x1EA0),0x26);
    context=*(void **)(p+0x1EAC);
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1FD8)),0,0,(u32)text,*(u32 *)(*(u8 **)p+12),0x3DC0);
    *(u8 *)(p+0x1FDC)=1;
    func_02045808(text);
    text=func_02045EC0(*(void **)(p+0x1EA0),0x29);
    width=func_0201D304(text,*(u32 *)(*(u8 **)p+12),0);
    x=((func_02045738(*(void **)(p+0x1F90))<<3)-width)>>1;
    secondContext=*(void **)(p+0x1EAC);
    func_0201C724(secondContext,(u32)func_02045770(*(void **)(p+0x1F90)),(s16)x,0,(u32)text,*(u32 *)(*(u8 **)p+12),0x2120);
    *(u8 *)(p+0x1F94)=1;
    func_02045808(text);
    text=func_02045EC0(*(void **)(p+0x1EA0),0x27);
    buf=func_020457B0(8,*(u16 *)(*(u8 **)p+16));
    func_0201EFA4(*(void **)(p+0x1EA4),0,*(u16 *)(elem+0x10),3,0,1);
    func_0201F250(*(void **)(p+0x1EA4),buf,text);
    otherWidth=func_0201D304(buf,*(u32 *)(*(u8 **)p+12),0);
    context=*(void **)(p+0x1EAC);
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F90)),(s16)(x-otherWidth),0,(u32)buf,*(u32 *)(*(u8 **)p+12),0x2120);
    *(u8 *)(p+0x1F94)=1;
    func_02045808(text);
    func_02045808(buf);
    text=func_02045EC0(*(void **)(p+0x1EA0),0x28);
    buf=func_020457B0(8,*(u16 *)(*(u8 **)p+16));
    func_0201EFA4(*(void **)(p+0x1EA4),0,*(u16 *)(elem+0x12),3,0,1);
    func_0201F250(*(void **)(p+0x1EA4),buf,text);
    context=*(void **)(p+0x1EAC);
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F90)),(s16)(x+width),0,(u32)buf,*(u32 *)(*(u8 **)p+12),0x2120);
    *(u8 *)(p+0x1F94)=1;
    func_02045808(text);
    func_02045808(buf);
}
