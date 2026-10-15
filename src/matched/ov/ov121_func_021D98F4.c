/*
 * function: MYSTERY_GRAPHIC_InitCamera
 * address: 0x021D98F4
 * packet: pkt_ov121_021D98F4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   MYSTERY_SetupDisplay3d 0x021D9580 thumb ov121
 *   d_021DF574 0x021DF574 data a4
 *   d_021DF58C 0x021DF58C data a4
 *   d_021DF580 0x021DF580 data a4
 */
typedef unsigned int u32;
extern void MYSTERY_SetupDisplay3d(void);
extern void G3D_SYSTEM_Init(int, int, int, int, int, u32, void (*)(void *));
extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, const void *, const void *, const void *, u32);
extern const u32 d_021DF574[];
extern const u32 d_021DF58C[];
extern const u32 d_021DF580[];
void MYSTERY_GRAPHIC_InitCamera(u32 *p, u32 heap)
{
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, (void (*)(void *))MYSTERY_SetupDisplay3d);
    p[0] = (u32)G3D_CAMERA_Create(2, 0x18000, -0x18000, -0x20000, 0x20000, 0x1000, 0x400000, 0,
                         d_021DF574, d_021DF58C, d_021DF580, heap);
    p[1] = 1;
}
