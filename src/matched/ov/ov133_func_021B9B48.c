/*
 * function: func_021B9B48
 * address: 0x021B9B48
 * packet: pkt_ov133_021B9B48
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern u32 func_0201C440(void *p);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
void func_021B9B48(u8 *p)
{
    *(void **)(p + 0x18e4) = func_0201D7EC(23, 0, 0, 0, *(u16 *)p);
    *(void **)(p + 0x18d8) = func_02045B38(0, 2, 33, *(u16 *)p);
    *(void **)(p + 0x18dc) = func_02045B38(0, 2, 79, *(u16 *)p);
    *(void **)(p + 0x18e0) = func_02045B38(0, 2, 75, *(u16 *)p);
    func_02049B40(23, 5, 4, 448, 32, *(u16 *)p);
    *(void **)(p + 0x18e8) = (void *)func_0201C440((void *)(*(u16 *)p));
    func_0201F5BC(7, 128, 12, 0, *(u16 *)p);
}
