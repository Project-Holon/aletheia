/*
 * function: MYSTERY_UTIL_CreateBmpList
 * address: 0x021DA338
 * packet: pkt_ov121_021DA338
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: heap is u16 in this function and the two callees receiving it.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   BMP_GetTileBytes 0x02043994 arm
 *   BMP_Create 0x02043678 arm
 *   d_021DFBA0 0x021DFBA0 data a4
 */
#include "../include/Obj13952.h"
#include "../include/Obj13953.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern char d_021DFBA0[];
typedef unsigned char  u8;
struct Bmp;
struct Descriptor;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern u8 BMP_GetTileBytes(struct Bmp *b);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
void *MYSTERY_UTIL_CreateBmpList(char *p,u16 heap)
{
    u32 i;
    int size=((struct Obj13952 *)p)->f4*4+8;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x42e);
    MI_CpuFill8(out,0,size);
    *(char * *)&((struct Obj13953 *)out)->f4=p;
    ((struct Obj13953 *)out)->f0=heap;
    for(i=0;i<((struct Obj13952 *)p)->f4;i++) {
        void *win=BMP_WIN_GetBmp(*(void **)(*(char **)(p+16+i*4)+12));
        u32 x=BMP_GetWidth(win);
        u32 y=BMP_GetHeight(win);
        u32 type=BMP_GetTileBytes(win);
        *(void **)(out+i*4+8)=BMP_Create(x/8,y/8,type,heap);
    }
    return out;
}
