/*
 * function: OEKAKI_SendCanvasChunk
 * address:  0x021844D8
 * packet:   pkt_ov023_021844D8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The extent runs long: 0x0218454C is an unlabelled leaf,
 * char *f(int i, char *p) { return p + 0x7ec0 + i * 0x3f0; }
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   func_02082B0C  0x02082B0C  arm
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_COMMAND_SetSendSlot  0x0203AA94  arm
 */
#include "../include/Obj01674.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
typedef signed int     s32;
struct Bmp;
struct Entry;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void func_02082B0C(u32 src, char *dst, u32 n);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_COMMAND_SetSendSlot(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

u32 OEKAKI_SendCanvasChunk(char *p, int x, int y)
{
    int i;
    u32 *q;
    u32 t;
    u32 sum;
    u8 c;

    t = (u32)BMP_GetPixels((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01674 *)p)->f118)));
    func_02082B0C(t + x * 1000, p + 0x7ad0, 1000);
    q = (u32 *)(p + 0x7ad0);
    sum = 0;
    for (i = 0; i < 250; i++)
        sum ^= q[i];
    ((struct Obj01674 *)p)->f7EB8 = sum;
    ((struct Obj01674 *)p)->f7EBC = x;
    c = (u32)UNION_APP_GetJoinedBits((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj01674 *)p)->f4));
    return GFL_NET_COMMAND_SetSendSlot((u32)GFL_NET_HANDLE_GetNetHandle(0xff), c, 0x2900, 0x3f0, (u32)(p + 0x7ad0));
}
