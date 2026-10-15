/*
 * function: UNION_SUBDISP_MoveChatLine
 * address: 0x021F0A04
 * packet: pkt_ov031_021F0A04
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: enum byte-offset locals, product by 0xE0 then separate <<= 1, recover sequential source/destination scaling and entry copies; integer offsets and enum halfword indexes do not.
 * extent: 154 instruction bytes followed by two zero alignment bytes; UNION_SUBDISP_ScrollChatLines is separately matched.
 * symbols:
 *   UNION_SUBDISP_MoveChatLine  0x021F0A04  thumb
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02041B6C  0x02041B6C  arm
 *   PMS_DRAW_Copy  0x0202DD24  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_CopyPixels  0x02043814  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   UNION_CHAT_LOG_GetLine  0x021BBC2C  thumb  ov021
 *   UNION_SUBDISP_DrawChatLine  0x021F07AC  thumb  ov031
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef enum { RowZero } RowOffset;

typedef struct {
    char pad[0x4C];
    u32 h[3];
    int k[3];
    char pad2[0x7C - 0x64];
    int f7c;
} O;

struct Bmp;
struct PmsDraw;
extern u32 BG_SYS_GetBuf(int channel);
extern void MI_CpuCopy8(void *dst, const void *src, int n);
extern void func_02041B6C(u32 bit);
extern void PMS_DRAW_Copy(struct PmsDraw *p, u32 i, u32 j);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u8 *UNION_CHAT_LOG_GetLine(void *, int);
extern void UNION_SUBDISP_DrawChatLine(O *, u8 *, int);

void UNION_SUBDISP_MoveChatLine(O *o, int a, int b, void *c, int d)
{
    u16 *base;
    u16 *src;
    u16 *dst;
    RowOffset sourceOffset;
    RowOffset destOffset;

    base = (u16 *)BG_SYS_GetBuf(6);
    sourceOffset = b * 0xE0;
    sourceOffset <<= 1;
    destOffset = a * 0xE0;
    destOffset <<= 1;
    src = (u16 *)((u32)base + sourceOffset);
    dst = (u16 *)((u32)base + destOffset);
    MI_CpuCopy8(dst, src, 0x1C0);
    func_02041B6C(6);
    if (o->k[a] == 0 && o->k[b] == 0) {
        PMS_DRAW_Copy((struct PmsDraw *)o->f7c, a, b);
        return;
    }
    if (o->k[a] == 1 && o->k[b] == 1) {
        BMP_CopyPixels((struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)o->h[a])), (const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)o->h[b])));
        BMP_WIN_TransferChars((struct Descriptor *)o->h[b]);
        return;
    }
    UNION_SUBDISP_DrawChatLine(o, UNION_CHAT_LOG_GetLine(c, d - 2 + a), b);
}
