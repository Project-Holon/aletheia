/*
 * function: IRC_COMPATIBLE_MENU_InitTitleWindow
 * address: 0x021B7CC8
 * packet: pkt_ov102_021B7CC8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: sibling of IRC_COMPATIBLE_MENU_InitWindow (same window builder, slot 1, chr 0xF); narrow u8 c parameter places its reload immediately before the call.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
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
extern void MI_CpuFill8(void *, int, int);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
void IRC_COMPATIBLE_MENU_InitTitleWindow(Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 heap)
{
    int win;
    MI_CpuFill8(p, 0, 20);
    p->chr = 0xF;
    p->win = BMP_WIN_Create(a, b, c, d, e, f, 1);
    p->que = (int)STRBUF_Create(255, heap);
    p->win2 = p->win;
    p->f8 = 0;
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)p->win)), p->chr);
    win = p->win;
    BMP_WIN_TransferChars((struct Descriptor *)win);
    BMP_WIN_MakeScreen((struct Cfg *)win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)win));
}
