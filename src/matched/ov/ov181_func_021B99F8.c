/*
 * function: STAFF_ROLL_LoadGraphics
 * address:  0x021B99F8
 * packet:   pkt_021B99F8
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049B68  0x02049B68  arm
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(u8 *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);

void STAFF_ROLL_LoadGraphics(void)
{
    u8 *p = func_020490F4(0x1a, 0x808e);
    func_02049658(p, 0, 3, 0, 0, 1, 0x8e);
    func_020498F4(p, 1, 3, 0, 0, 1, 0x8e);
    ARC_TOOL_DeleteHandle(p);
    p = func_020490F4(0xdc, 0x808e);
    func_02049B68(p, 0xc, 0, 0x1e0, 0x20, 0x8e);
    func_02049B68(p, 0xc, 4, 0x1e0, 0x20, 0x8e);
    ARC_TOOL_DeleteHandle(p);
    BG_SYS_LoadPlttEntry(1, 0);
    BG_SYS_LoadPlttEntry(5, 0);
}
