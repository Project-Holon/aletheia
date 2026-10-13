/*
 * function: func_021D7B70
 * address: 0x021D7B70
 * packet: pkt_ov116_021D7B70
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: incoming heap in r1 is forwarded unchanged to 021D821C.
 * evidence: 0203101C's second parameter is wide here: original 021D7C26
 * copies full r6 to r1 with no truncation; its definition stores the low halfword.
 * symbols:
 *   func_021D821C 0x021D821C thumb ov116
 *   func_021D7D0C 0x021D7D0C thumb ov116
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_Create 0x0203101C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj10342.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D821C(int, u32);
extern void func_021D7D0C(u8 *, u32);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *TCBL_Create(u32, u32, u32, u32);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
#define P(k) (*(void **)(p + (k)))
void func_021D7B70(u8 *p, u32 heap)
{
    P(8) = func_021D821C(1, heap);
    ((struct Obj10342 *)p)->f4 = heap;
    func_021D7D0C(p, heap);
    P(0x97c) = (void *)BMP_WIN_Create(1, 1, 19, 30, 4, 12, 1);
    func_0201F73C(P(0x97c), 1, (u16)(((struct Obj10342 *)p)->f984), 13);
    BMP_Clear(BMP_WIN_GetBmp(P(0x97c)), 15);
    BMP_WIN_MakeScreen(P(0x97c));
    BMP_WIN_TransferChars(P(0x97c));
    func_02041B6C(1);
    P(0x990) = func_02045B38(0, 2, 206, heap);
    P(0x994) = func_0201EC64(heap);
    P(0x998) = GF_FONT_Create(23, 0, 0, 0, heap);
    P(0x99c) = STRBUF_Create(128, heap);
    P(0x9a0) = STRBUF_Create(128, heap);
    P(0x9a8) = TCBL_Create(heap, heap, 1, 0);
    ((struct Obj10342 *)p)->f0 = 1;
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RestartWithDefaultTimeout(1, heap);
}
