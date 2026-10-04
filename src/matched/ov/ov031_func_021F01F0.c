/*
 * function: func_021F01F0
 * address: 0x021F01F0
 * packet: pkt_ov031_021F01F0
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 */
typedef unsigned int u32;
typedef unsigned char  u8;
struct Bank;
struct GfFont;
struct MsgBank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void func_021F01F0(char *p)
{
    *(void **)(p + 0x14) = func_0204B100(12, 5, 21);
    *(u32 *)(p + 0x40) = func_0201C440((void *)21);
    *(void **)(p + 0x44) = func_0201D7EC(23, 0, 0, 0, 21);
    *(void **)(p + 0x48) = func_02045B38(0, 2, 201, 21);
}
