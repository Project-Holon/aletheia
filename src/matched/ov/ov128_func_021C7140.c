/*
 * function: func_021C7140
 * address: 0x021C7140
 * packet: pkt_ov128_021C7140
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C63AC 0x021C63AC thumb ov128
 *   func_020457B0 0x020457B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_02045808 0x02045808 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C63AC(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
struct MsgBank;
struct R;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(u32,u32,u32);
extern void func_021B6AE4(u8 *,u32,u16,u16,u32,u32,u16,u32);
extern void func_021CA4B4(char *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02049EF4(void *,u32,u32,void **,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
struct P {
    u8 pad00[44];
    void *buf;
    void *text1;
    u16 color1;
    u16 pad36;
    u32 flag1;
    void *text2;
    u16 color2;
    u16 pad42;
    u32 flag2;
    void *menu;
};
void func_021C7140(struct P *p, u8 *a, u8 *ctx, u16 heap)
{
    int i;
    void *buf;
    void *text;
    u32 width;
    func_021C63AC(ctx,(u32 *)((u8 *)p+12),3,4,5,24,20,10,1,0);
    func_021C63AC(ctx,(u32 *)((u8 *)p+28),1,2,19,27,4,10,172,0);
    p->buf=func_020457B0(128,heap);
    buf=func_020457B0(128,heap);
    text=func_020457B0(128,heap);
    func_0201F02C(*(void **)ctx,0,func_02012944(*(void **)(a+4)));
    for(i=0;i<3;i++) {
        func_02045CAC(*(void **)(ctx+4),i+1,text);
        func_0201F250(*(void **)ctx,buf,text);
        width=func_0201D304((u32)buf,*(u32 *)(ctx+0x17c),0);
        func_021B6AE4((u8 *)p+12,*(u32 *)(ctx+52),(192-width)/2,i*40+8,(u32)buf,*(u32 *)(ctx+0x17c),0x440,0);
    }
    func_021CA4B4(*(void **)((u8 *)p+12));
    func_02045808(buf);
    func_02045808(text);
    *(void **)((u8 *)p+20)=func_02049EF4(*(void **)(ctx+8),13,0,(void **)((u8 *)p+24),heap);
    p->text1=func_02045EC0(*(void **)(ctx+4),66);
    p->color1=0x39e3;
    p->flag1=0;
    p->text2=func_02045EC0(*(void **)(ctx+4),67);
    p->color2=0x39e3;
    p->flag2=0;
    p->menu=func_02027F60(1,14,*(u32 *)(ctx+0x17c),*(u32 *)(ctx+52),heap);
}
