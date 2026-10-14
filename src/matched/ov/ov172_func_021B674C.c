/*
 * function: CTVT_CAMERA_AllocFrames
 * address: 0x021B674C
 * packet: pkt_ov172_021B674C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CTVT_CAMERA_GetWidth 0x021B6938 thumb ov172
 *   CTVT_CAMERA_GetHeight 0x021B6944 thumb ov172
 *   func_02030734 0x02030734 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   d_021C71C0 0x021C71C0 data a4
 */
#include "../include/Obj01264.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 CTVT_CAMERA_GetWidth(void *);
extern u16 CTVT_CAMERA_GetHeight(void *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GFL_NET_AllocAligned(unsigned int, unsigned int, const char *, unsigned short);
extern const char d_021C71C0[];
void CTVT_CAMERA_AllocFrames(char *p, int count, u16 heap)
{
    u32 width = CTVT_CAMERA_GetWidth(p);
    u32 height = CTVT_CAMERA_GetHeight(p);
    u8 i;
    if (*(u32 *)&((struct Obj01264 *)p)->f4 == 0) {
        ((struct Obj01264 *)p)->f4 = func_02030734(((struct Obj01264 *)p)->f0, count * 4, 0, d_021C71C0, 0x1D7);
        ((struct Obj01264 *)p)->f8 = count;
        for (i = 0; i < count; i++)
            (*(void ***)(p + 4))[i] = GFL_NET_AllocAligned(heap, height * (width * 2), d_021C71C0, 0x1DC);
        ((struct Obj01264 *)p)->fC = 1;
    }
}
