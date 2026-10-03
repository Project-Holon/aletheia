/*
 * function: func_0220B584
 * address: 0x0220B584
 * packet: pkt_ov197_0220B584
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: parenthesised byte-pointer plus page keeps the page load before the far-field add; a flat offset sum differs in two bytes.
 * Width: original narrows x to signed 16 bits before each 0201C724 call; s16 extern preserves those caller truncations despite owner u32 x.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
extern void *func_02045770(void *);
extern u8 func_02045738(void *);
extern void func_02043B5C(void *,u8);
extern void *func_02045EC0(void *,u32);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void func_0201EF40(void *,u32,u32);
extern void func_0201F250(void *,void *,void *);
extern void func_0201C724(void *,void *,s16,s16,void *,u32,u16);
extern void func_02045808(void *);
extern void func_02045334(void *);
extern u32 func_0201D304(void *,u32,u32);
void func_0220B584(char *p)
{
    void *handle=*(void **)(p+0x118);
    void *surface=func_02045770(handle);
    void *text;
    u32 width;
    u32 x;
    void *font;
    void *lastSurface;
    func_02043B5C(surface,0);
    text=func_02045EC0(*(void **)(p+0xC),28);
    width=func_0201D304(text,*(u32 *)(*(char **)p+4),0);
    x=(func_02045738(handle)*8-width)/2;
    func_0201C724(*(void **)(p+0x18),surface,x,4,text,*(u32 *)(*(char **)p+4),0x3C40);
    func_02045808(text);
    text=func_02045EC0(*(void **)(p+0xC),29);
    func_0201EFA4(*(void **)(p+0x10),0,((u8 *)p+((u8 *)p)[0x533])[0x539]+1,2,0,1);
    func_0201F250(*(void **)(p+0x10),*(void **)(p+0x14),text);
    func_0201C724(*(void **)(p+0x18),surface,x+width,4,*(void **)(p+0x14),*(u32 *)(*(char **)p+4),0x3C40);
    func_02045808(text);
    text=func_02045EC0(*(void **)(p+0xC),30);
    func_0201EFA4(*(void **)(p+0x10),0,*(s16 *)(*(char **)p+((u8 *)p)[0x533]*2+0x38)+1,2,0,1);
    func_0201F250(*(void **)(p+0x10),*(void **)(p+0x14),text);
    width=func_0201D304(*(void **)(p+0x14),*(u32 *)(*(char **)p+4),0);
    font=*(void **)(p+0x18);
    lastSurface=func_02045770(*(void **)(p+0x118));
    func_0201C724(font,lastSurface,x-width,4,*(void **)(p+0x14),*(u32 *)(*(char **)p+4),0x3C40);
    ((u8 *)p)[0x11C]=1;
    func_02045808(text);
}
