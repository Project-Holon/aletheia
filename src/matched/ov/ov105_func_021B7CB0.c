/*
 * function: func_021B7CB0
 * address: 0x021B7CB0
 * packet: pkt_ov105_021B7CB0
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec { u32 f0; u32 f4; u8 f8; u8 pad9[3]; u32 fC; u16 f10; };
extern void func_02082BCC(void *, int, int);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
void func_021B7CB0(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g)
{
    int q;
    func_02082BCC(p, 0, 20);
    p->f10 = 15;
    p->f0 = BMP_WIN_Create(a, b, c, d, e, f, 1);
    p->fC = (u32)STRBUF_Create(255, g);
    p->f4 = p->f0;
    p->f8 = 0;
    BMP_Clear(func_02045770((struct Descriptor *)p->f0), p->f10);
    q = p->f0;
    BMP_WIN_TransferChars((void *)q);
    BMP_WIN_MakeScreen((struct Cfg *)q);
    func_020409B4(func_02045730((struct Descriptor *)q));
}
