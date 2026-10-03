/*
 * function: func_021F4BF8
 * address: 0x021F4BF8
 * packet: pkt_ov135_021F4BF8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021F5008 0x021F5008 thumb ov135
 *   str_02203B08 0x02203B08 data
 *   data_02202BC8 0x02202BC8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *text; u32 b,c; } Item;
typedef struct { Item item[2]; } Items;
typedef struct { u32 heap; u8 count,pad[3]; Item *items; u32 mode; u8 a,b,c,d; } Menu;
extern const char str_02203B08[];
extern const Items data_02202BC8;
struct MsgBank;
struct R;
struct U16Vec;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *,u32,u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02027778(Menu *,void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_021F5008(u32 x);
void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag)
{
    Items items;
    Menu menu;
    int on;
    if (*(u32 *)(p+0xE04)) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)(p+0xE08)) func_02034714(str_02203B08,0,str_02203B08);
    *(void **)(p+0xE04)=func_02027F60((u8)c,(u8)a,*(u32 *)(p+0xFA0),*(u32 *)(p+0xFAC),0x48);
    items=data_02202BC8;
    on=0;
    func_02082BCC(&menu,0,20);
    items.item[0].text=func_02045EC0(*(void **)(p+0xB6C),63);
    items.item[1].text=func_02045EC0(*(void **)(p+0xB6C),64);
    menu.heap=0x48;
    menu.count=2;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=8;
    menu.d=3;
    *(void **)(p+0xE08)=func_02027778(&menu,*(void **)(p+0xE04));
    func_02045808(items.item[0].text);
    func_02045808(items.item[1].text);
    if (flag) {
        if(c<=3) on=1;
        func_021F5008(on);
    }
}
