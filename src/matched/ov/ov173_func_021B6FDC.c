/*
 * function: func_021B6FDC
 * address: 0x021B6FDC
 * packet: pkt_ov173_021B6FDC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C158 0x0201C158 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void *func_02045770(void *);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_02041B6C(u32);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern u8 func_0201C158(u16,u32);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void func_0201F250(void *,void *,void *);
static inline void flush(void *win)
{
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(func_02045730(win));
}
void func_021B6FDC(char *p,u8 first,u8 row)
{
    int y;
    int index;
    u32 value;
    y=row*24;
    index=first+row;
    if(index>=*(u8 *)(p+0x1b8)) return;
    func_0201C7D0(func_02045770(*(void **)(p+0x30)),0,y,*(void **)(*(char **)(p+0x58)+index*8),*(void **)(p+0x60),0x3c40);
    flush(*(void **)(p+0x30));
    func_0201C7D0(func_02045770(*(void **)(p+0x30)),96,y,*(void **)(p+0x50),*(void **)(p+0x60),0x440);
    flush(*(void **)(p+0x30));
    value=func_0201C158(*(u32 *)(*(char **)(p+0x58)+index*8+4),0);
    func_0201EFA4(*(void **)(p+0x48),0,value,2,1,1);
    func_0201EFA4(*(void **)(p+0x48),1,value,2,0,1);
    func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),*(void **)(p+0x54));
    func_0201C7D0(func_02045770(*(void **)(p+0x30)),120,y,*(void **)(p+0x4c),*(void **)(p+0x60),0x440);
    flush(*(void **)(p+0x30));
}
