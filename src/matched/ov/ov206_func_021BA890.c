/*
 * unit: yes
 * function: func_021BA890
 * address: 0x021BA890
 * packet: pkt_ov206_021BA890
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   func_02049B68 0x02049B68 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   d_021BC174 0x021BC174 data a1
 */
#include "../include/Obj00022.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tab16 { u8 b[16]; };
extern const struct Tab16 d_021BC174;
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
struct CharBuf;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
void func_021BA890(char *p)
{
    struct Tab16 tab;
    int out;
    int r6;
    int i;
    ((struct Obj00022 *)p)->f2B0 = (int)ARC_UTIL_LoadHandleMemberWithSize(((struct Obj00022 *)p)->f1C8, 0, 0, ((struct Obj00022 *)p)->f0, (u32 *)(&out));
    r6 = 0;
    if (*(int *)&((struct Obj00022 *)p)->f1C != 0) r6 = 4;
    func_02049B68(((struct Obj00022 *)p)->f1CC, 5, r6, 0x60, 0x20, ((struct Obj00022 *)p)->f0);
    tab = d_021BC174;
    for (i = 0; i < 4; i++) {
        *(void **)(p+i*4+0x6c) = (void *)BMP_WIN_Create(((struct Obj00022 *)p)->f4C, tab.b[i*4], tab.b[i*4+1], tab.b[i*4+2], tab.b[i*4+3], 3, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp(*(void **)(p+i*4+0x6c))), 0);
    }
    for (i = 0; i < 4; i++) {
        *(int *)(p+i*4+0x7c) = 1;
    }
}
