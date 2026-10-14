/*
 * function: COMM_TVT_SYS_ClearAndTransferNameWindows
 * address: 0x021BE1E4
 * packet: pkt_ov172_021BE1E4
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void COMM_TVT_SYS_ClearAndTransferNameWindows(u8 *p)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8))), 0);
        BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8));
    }
}
