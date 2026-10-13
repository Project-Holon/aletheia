/*
 * function: func_021DE6EC
 * address: 0x021DE6EC
 * packet: pkt_ov137_021DE6EC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E1AF8 0x021E1AF8 data a1
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj23736.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 d_021E1AF8[];
extern void GX_LoadOBJPltt(void *, int, int);
typedef unsigned int   u32;
struct Sub0204A9D0;
extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
void func_021DE6EC(u8 *p, u8 *q, int i, int j, int unused)
{
    void *r;
    int n;
    GX_LoadOBJPltt(*(u8 * *)&((struct Obj23736 *)q)->fC + d_021E1AF8[j] * 32, i * 32, 32);
    r = ARC_UTIL_LoadScreenDataFromArchive(32, j + 1, 0, (u32)(&n), 114);
    CLACT_TransferCharacter((int)(*(void **)(p + (i + 5) * 4 + 0x6c)), (struct Sub0204A9D0 *)n);
    func_020307B0(r);
}
