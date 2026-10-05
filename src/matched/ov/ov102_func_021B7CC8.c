/*
 * function: func_021B7CC8
 * address: 0x021B7CC8
 * packet: pkt_ov102_021B7CC8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: sibling of func_021B7D38 (same window builder, slot 1, chr 0xF); narrow u8 c parameter places its reload immediately before the call.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct {
    u32 win;     /* +0x00 */
    u32 win2;    /* +0x04 */
    u8  f8;      /* +0x08 */
    u8  pad9[3];
    u32 que;     /* +0x0C */
    u16 chr;     /* +0x10 */
} Rec;
extern void func_02082BCC(void *, int, int);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
void func_021B7CC8(Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 heap)
{
    int win;
    func_02082BCC(p, 0, 20);
    p->chr = 0xF;
    p->win = func_020450F0(a, b, c, d, e, f, 1);
    p->que = (int)func_020457B0(255, heap);
    p->win2 = p->win;
    p->f8 = 0;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->win)), p->chr);
    win = p->win;
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}
