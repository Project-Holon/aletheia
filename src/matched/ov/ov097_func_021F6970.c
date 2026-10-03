/*
 * function: func_021F6970
 * address:  0x021F6970
 * packet:   pkt_ov097_021F6970
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C450  0x0201C450  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct GfFont;
struct MsgBank;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_0201C450(u16 n, u32 heap);

void func_021F6970(u8 *p)
{
    *(void **)(p + 0x14) = func_02045B38(0, 2, 0x12, 0x71);
    *(void **)(p + 0xc) = func_0201D7EC(0x17, 0, 0, 0, 0x71);
    *(void **)(p + 0x10) = func_0201D7EC(0x17, 3, 0, 0, 0x71);
    *(void **)(p + 0x18) = func_0201EC64(0x71);
    *(void **)(p + 0x1c) = func_0201C450(0x800, 0x71);
}
