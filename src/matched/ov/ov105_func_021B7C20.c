/*
 * function: func_021B7C20
 * address: 0x021B7C20
 * packet: pkt_ov105_021B7C20
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * func_02082BCC 0x02082BCC arm
 * func_0201DD60 0x0201DD60 thumb
 * func_0201D7EC 0x0201D7EC thumb
 * func_0201C440 0x0201C440 thumb
 * func_02045B38 0x02045B38 arm
 * func_0201EC64 0x0201EC64 thumb
 */
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct WordSet;
extern void func_02082BCC(void *, int, unsigned);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
void func_021B7C20(u32 *p, int flag, int heap) {
 func_02082BCC(p, 0, 0x10);
 func_0201DD60();
 if (flag == 0) {
  p[0] = (u32)func_0201D7EC(0x17, 0, 0, 0, heap);
 }
 p[2] = func_0201C440((void *)heap);
 p[1] = (u32)func_02045B38(0, 2, 0x33, heap);
 p[3] = (u32)func_0201EC64(heap);
}
