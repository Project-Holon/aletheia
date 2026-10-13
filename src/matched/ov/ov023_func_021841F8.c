/*
 * function: OEKAKI_RecvCanvasChunk
 * address:  0x021841F8
 * packet:   pkt_ov023_021841F8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   OEKAKI_SendCanvasChunk  0x021844D8  thumb  ov023
 *   OEKAKI_QueueCommand  0x02186860  thumb  ov023
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01674.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void MIi_CpuCopyFast(void *src, void *dst, u32 n);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 OEKAKI_SendCanvasChunk(char *p, int x, int y);
extern void OEKAKI_QueueCommand(char *p, int x, int y);

void OEKAKI_RecvCanvasChunk(int a, int b, u8 *c, u8 *d, int e)
{
    int n;
    int off;
    u32 t;

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        off = c[0x3ec] * 0x3e8;
        if (off > 0x3840) {
            MIi_CpuCopyFast(c, d + 0x4290 + off, 0x190);
        } else {
            MIi_CpuCopyFast(c, d + 0x4290 + off, 0x3e8);
        }
        MIi_CpuCopyFast(d + 0x4290,
                      BMP_GetPixels(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01674 *)d)->f118)),
                      0x3840);
        t = ((struct Obj01674 *)d)->f118;
        BMP_WIN_TransferChars((struct Descriptor *)t);
        BMP_WIN_MakeScreen((struct Cfg *)t);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)t));
    } else {
        n = ((struct Obj01674 *)d)->f428C;
        if (n * 1000 < 0x3840) {
            ((struct Obj01674 *)d)->f428C += 1;
            OEKAKI_SendCanvasChunk((char *)d, ((struct Obj01674 *)d)->f428C, e);
        } else {
            OEKAKI_QueueCommand((char *)d, 0x2904, 0);
        }
    }
}
