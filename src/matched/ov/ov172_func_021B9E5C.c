/*
 * function: CTVT_TALK_DrawWaveform
 * address:  0x021B9E5C
 * packet:   pkt_ov172_021B9E5C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Renders idx*0x7b/v steps of a waveform bar by bar with CTVT_TALK_DrawLine, advancing the counters at +0x30/+0x31.
 *
 * symbols:
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   CTVT_TALK_DrawLine  0x021B9AB8  thumb  ov172
 *   d_021C6F6E     0x021C6F6E  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04553.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern int func_0209C0A4(int a, u16 b);
struct Bmp;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void CTVT_TALK_DrawLine(int a0, char *obj, void *dev, int a3, u8 s0, u8 s1, u8 s2, u8 s3);
extern u8 d_021C6F6E[];

void CTVT_TALK_DrawWaveform(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v)
{
    u32 n;
    void *dev;
    int flag;
    u32 c;
    int h;
    int x;
    u32 c1;

    if (idx < 0)
        return;
    n = func_0209C0A4(idx * 0x7B, v);
    dev = BMP_GetPixels(BMP_WIN_GetBmp(((struct Obj04553 *)obj)->f2C));
    flag = 0;
    c = ((struct Obj04553 *)obj)->f30;
    if (c < n) {
        flag = 1;
        while (c < n) {
            c1 = c + 1;
            x = c1 * v;
            h = ((tbl[x / 128 / 2] + 0x8000) << 6) / 0x10000;
            if (c < 0xB) {
                u32 t = 0x20 - d_021C6F6E[c - 3];
                if (h < t)
                    h = t;
            }
            if (c > 0x72) {
                u32 t = 0x20 - d_021C6F6E[(u8)(0x7A - c)];
                if (h < t)
                    h = t;
            }
            CTVT_TALK_DrawLine(a0, obj, dev, c, ((struct Obj04553 *)obj)->f31, (u8)c1, (u8)h, a3);
            ((struct Obj04553 *)obj)->f30 += 1;
            ((struct Obj04553 *)obj)->f31 = (u8)h;
            c = ((struct Obj04553 *)obj)->f30;
        }
    }
    if (flag == 1)
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)&((struct Obj04553 *)obj)->f2C);
}
