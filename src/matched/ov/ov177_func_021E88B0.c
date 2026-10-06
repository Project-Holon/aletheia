/*
 * function: func_021E88B0
 * address: 0x021E88B0
 * packet: pkt_ov177_021E88B0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wP8 W6): EXACT. Twin shape from ov121 021DA038. Lever: heap parameter u16 with u16 heap parameters on 02030734, 0201F81C, 0201F878 (5th), 0201FF30 (4th) and 02020CF8; x/y/width/height u8 with u8 450F0 prototype; if/else for the 02020D10 flag.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_02020D10 0x02020D10 thumb
 *   d_021E8DD4 0x021E8DD4 data a1
 *   d_021E8D68 0x021E8D68 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 word[13];} Config;
typedef struct {void *win;u32 mgr;void *win2;u8 flag,pad[3];void *menu;void *entries;u32 counter;} Work;
typedef struct {u32 x0,x1,x2;u32 items[4];u32 count;u16 a,b,c,d;int enabled;u16 kind,pad;} Desc;
extern const char d_021E8DD4[];
extern const Config d_021E8D68;
struct Descriptor;
struct Cfg;
struct Obj;
struct Slot;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void *func_0201F81C(u32,u16);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_0201FF30(Config *,u16,u16,u16);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02020D10(u8 *p, u32 v);
Work *func_021E88B0(const Desc *p,u8 x,u8 y,u8 width,u8 height,u16 heap)
{
    Work *out;
    void *q;
    u32 i;
    Config cfg;
    out=func_02030734((u16)heap,28,0,d_021E8DD4,0x1a2);
    func_02082BCC(out,0,28);
    out->mgr=p->x2;
    out->counter=p->kind;
    out->win=(void *)func_020450F0((u8)p->a,(u8)x,(u8)y,(u8)width,height,p->b,1);
    func_0201F73C(out->win,2,p->d,(u8)p->c);
    q=out->win;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    out->win2=out->win;
    out->flag=0;
    out->entries=func_0201F81C(p->count,heap);
    for(i=0;i<p->count;i++)
        func_0201F878(out->entries,p->x0,p->items[i],i,(u16)heap);
    cfg=d_021E8D68;
    cfg.word[0]=(u32)out->entries;
    *(u16 *)((u8 *)&cfg+0x10)=p->count;
    *(u16 *)((u8 *)&cfg+0x12)=p->count;
    cfg.word[3]=(u32)out->win;
    cfg.word[9]=p->x0;
    cfg.word[10]=(u32)&out->win2;
    cfg.word[11]=p->x2;
    cfg.word[12]=p->x1;
    out->menu=func_0201FF30(&cfg,0,p->pad,heap);
    func_02020CF8(out->menu,(u16)heap);
    if(p->enabled)
        func_02020D10(out->menu,0);
    else
        func_02020D10(out->menu,1);
    return out;
}
