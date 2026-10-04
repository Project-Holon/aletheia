/*
 * function: func_0220C398
 * address: 0x0220C398
 * packet: pkt_ov198_0220C398
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_022110D4(u8 *,int);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
void func_0220C398(u8 *p,int slot,int index)
{
    char *elem=(char *)(p+4)+func_022110D4(p,index)*0x4C;
    u32 buf=(u32)func_020457B0(16,*(u16 *)(*(char **)p+0x10));
    void *text=func_02045EC0(*(void **)(p+0x1EA0),14);
    u32 context;
    u32 surface;
    func_0201EF8C(*(void **)(p+0x1EA4),0,*(u16 *)(elem+0x18));
    func_0201F250(*(void **)(p+0x1EA4),(void *)buf,text);
    context=*(u32 *)(p+0x1EAC);
    surface=(u32)func_02045770(*(void **)(p+slot*8+0x1F70));
    func_0201C724(context,surface,0,0,buf,*(u32 *)(*(char **)p+0xC),0x3DC0);
    (p+slot*8)[0x1F74]=1;
    func_02045808(text);
    func_02045808((void *)buf);
}
