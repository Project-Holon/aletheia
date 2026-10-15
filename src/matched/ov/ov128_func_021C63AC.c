/*
 * function: Wf2dmapFriend_CreateWindow
 * address: 0x021C63AC
 * packet: pkt_ov128_021C63AC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   WF2DMAP_TOUCH_AddSlot 0x021CA458 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void WF2DMAP_TOUCH_AddSlot(char *p, void *q);
void Wf2dmapFriend_CreateWindow(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g)
{
    *out=BMP_WIN_Create(a,b,c,d,e,f,1);
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*out),g);
    BMP_WIN_TransferChars((struct Descriptor *)*out);
    WF2DMAP_TOUCH_AddSlot(p,out);
}
