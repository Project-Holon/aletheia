/*
 * function: IRC_RHYTHM_InitMessageWindow
 * address: 0x021B7DF0
 * packet: pkt_ov104_021B7DF0
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   IRC_RHYTHM_ClearTextWindow 0x021B80B8 thumb
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
extern void MI_CpuFill8(void *,int,int);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32);
extern void IRC_RHYTHM_ClearTextWindow(u8 *p);
void IRC_RHYTHM_InitMessageWindow(Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 size)
{
    void *q;
    MI_CpuFill8(p, 0, 0x14);
    p->f10 = 15;
    p->f0 = (void *)BMP_WIN_Create(a, b, c, d, e, f, 1);
    p->fC = STRBUF_Create(0xff, size);
    p->f4 = p->f0;
    p->f8 = 0;
    IRC_RHYTHM_ClearTextWindow((u8 *)p);
    q = p->f0;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_020409B4(BMP_WIN_GetBgLayer(q));
}
