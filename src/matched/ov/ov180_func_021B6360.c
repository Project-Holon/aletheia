/*
 * function: HALL_OF_FAME_LoadBackgroundGraphics
 * address:  0x021B6360
 * packet:   pkt_021B6360
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(u8 *p);

void HALL_OF_FAME_LoadBackgroundGraphics(void)
{
    u8 *p = func_020490F4(0xd8, 0x8d);
    func_02049B68(p, 1, 2, 0x6000, 0x20, 0x8d);
    func_02049B68(p, 1, 6, 0x6000, 0x20, 0x8d);
    func_02049658(p, 0x16, 3, 0, 0, 0, 0x8d);
    func_02049658(p, 0x16, 7, 0, 0, 0, 0x8d);
    func_020498F4(p, 0x1c, 3, 0, 0, 0, 0x8d);
    func_020498F4(p, 0x1c, 7, 0, 0, 0, 0x8d);
    ARC_TOOL_DeleteHandle(p);
}
