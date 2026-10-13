/*
 * function: func_021E6294
 * address: 0x021E6294
 * packet: pkt_ov119_021E6294
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020275E4 0x020275E4 thumb
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020275E4(void);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
void func_021E6294(char *p, int n, u32 x) {
    int offset = n * 32;
    func_02049B40(23,5,x,offset,32,((struct Obj00001 *)p)->f5F4);
    ARC_UTIL_UploadPaletteFromArchive(func_020275E4(),31,x,28,offset+28,4,((struct Obj00001 *)p)->f5F4);
}
