/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow
 * address: 0x021B800C
 * packet: pkt_ov103_021B800C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_ClearWindow 0x021B831C thumb ov103
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec { u32 f0; u32 f4; u8 f8; u8 pad9[3]; u32 fC; u16 f10; };
struct Cfg;
struct Descriptor;
struct U16Vec;
extern void IRC_COMPATIBLE_TOUCH_TEST_ClearWindow(u8 *p);
extern void MI_CpuFill8(void *, int, int);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
void IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g)
{
    int q;
    MI_CpuFill8(p, 0, 20);
    p->f10 = 15;
    p->f0 = BMP_WIN_Create(a, b, c, d, e, f, 1);
    p->fC = (u32)STRBUF_Create(255, g);
    p->f4 = p->f0;
    p->f8 = 0;
    IRC_COMPATIBLE_TOUCH_TEST_ClearWindow((u8 *)p);
    q = p->f0;
    BMP_WIN_TransferChars((void *)q);
    BMP_WIN_MakeScreen((struct Cfg *)q);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)q));
}
