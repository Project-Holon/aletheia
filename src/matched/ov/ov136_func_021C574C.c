/*
 * function: MB_SEQ_LoadFrameCharData
 * address: 0x021C574C
 * packet: pkt_ov136_021C574C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MB_SEQ_LoadFrameCharData 0x021C574C thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   MIi_CpuCopyFast 0x02082B0C arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14188.h"
#include "../include/Obj23503.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void MIi_CpuCopyFast(void *, const void *, u32);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);

void MB_SEQ_LoadFrameCharData(u8 *p)
{
    void *h;
    void *buf;
    u8 *out;
    u8 *dst;
    h = func_020490F4(0x9B, 0x66);
    func_02049658(h, 0x2A, 7, 0, 0, 1, 0x66);
    func_020498F4(h, 0x29, 7, 0, 0, 1, 0x66);
    func_02049B68(h, 0x2B, 4, 0, 0, 0x66);
    func_02049658(h, 0x26, 3, 0, 0, 1, 0x66);
    func_02049658(h, 0x26, 1, 0, 0, 1, 0x66);
    func_020498F4(h, 0x25, 3, 0, 0, 1, 0x66);
    func_02049B68(h, 0x27, 0, 0, 0, 0x66);
    buf = ARC_UTIL_LoadBgCharDataFromHandle(h, 0x26, 1, (u32)(&out), 0x66);
    dst = *(u8 * *)&((struct Obj23503 *)out)->f14;
    MIi_CpuCopyFast(dst + 0x100, *(u8 * *)&((struct Obj14188 *)p)->f8 + 4, 0x20);
    MIi_CpuCopyFast(dst + 0x100, *(u8 * *)&((struct Obj14188 *)p)->f8 + 0x24, 0x20);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(h);
}
