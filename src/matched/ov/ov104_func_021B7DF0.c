/*
 * function: func_021B7DF0
 * address: 0x021B7DF0
 * packet: pkt_ov104_021B7DF0
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021B80B8 0x021B80B8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    void *f0;
    void *f4;
    u8 f8;
    u8 pad_9[3];
    void *fC;
    u16 f10;
} Rec;
extern void func_02082BCC(void *,int,int);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_021B80B8(Rec *p);
void func_021B7DF0(Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 size)
{
    void *q;
    func_02082BCC(p, 0, 0x14);
    p->f10 = 15;
    p->f0 = (void *)func_020450F0(a, b, c, d, e, f, 1);
    p->fC = func_020457B0(0xff, size);
    p->f4 = p->f0;
    p->f8 = 0;
    func_021B80B8(p);
    q = p->f0;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}
