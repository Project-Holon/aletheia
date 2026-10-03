/*
 * function: func_021C692C
 * address: 0x021C692C
 * packet: pkt_ov128_021C692C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 */
typedef unsigned char u8;
extern void func_0201DD68(void);
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0203101C(unsigned,unsigned,unsigned,unsigned);
extern void *func_0201C440(unsigned);
void func_021C692C(u8 *p,unsigned heap)
{
    func_0201DD68();
    *(void **)p=func_0201EC64(heap);
    *(void **)(p+4)=func_02045B38(0,2,211,heap);
    *(void **)(p+0x17c)=func_0201D7EC(23,0,0,0,heap);
    *(void **)(p+0x28)=func_0203101C(heap,heap,3,256);
    *(void **)(p+0x2c)=0;
    *(void **)(p+0x34)=func_0201C440(heap);
}
