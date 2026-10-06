/*
 * function: func_021B6790
 * address:  0x021B6790
 * packet:   pkt_ov071_021B6790
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 */

typedef unsigned int   u32;
typedef unsigned short u16;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct WordSet;
void func_021B6790(int *p)
{
    void func_0201DD78(u32 r, u32 g, u32 b);
    struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
    struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
    u32 func_0201C440(void *p);
    struct WordSet *func_0201EC64(u32 heap);
    struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

    func_0201DD78(0xf, 2, 0);
    p[6] = (int)func_0203101C(0x61, 0x61, 4, 0x20);
    p[3] = (int)func_0201D7EC(0x17, 0, 0, 0, 0x61);
    p[2] = func_0201C440((void *)0x61);
    p[4] = (int)func_0201EC64(0x61);
    p[7] = (int)func_02045B38(0, 2, 0x43, 0x61);
    p[8] = (int)func_02045B38(0, 2, 0xa0, 0x61);
    p[9] = (int)func_02045B38(0, 2, 0xa1, 0x61);
    p[10] = (int)func_02045B38(0, 2, 0x45, 0x61);
}
