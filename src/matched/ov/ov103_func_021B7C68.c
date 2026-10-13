/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_Init3D
 * address: 0x021B7C68
 * packet: pkt_ov103_021B7C68
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay 0x021B7D58 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_InitModel 0x021B7DFC thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_CameraPosition 0x021B9228 data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_CameraTarget 0x021B9234 data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_CameraUp 0x021B9240 data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds 0x021B9218 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, void *);
extern int G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay(void);
extern void IRC_COMPATIBLE_TOUCH_TEST_InitModel(u8 *p, int a, const u16 *t, int c, int a4);
extern u8 IRC_COMPATIBLE_TOUCH_TEST_CameraPosition[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_CameraTarget[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_CameraUp[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds[];

void IRC_COMPATIBLE_TOUCH_TEST_Init3D(u8 *p, int heap)
{
    void *arc;
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, (void *)IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay);
    *(int *)p = G3D_CAMERA_Create(2, 6 << 14, 0xFFFE8000, 0xFFFE0000, 1 << 17, 1 << 12, 250 << 14, 0,
                              IRC_COMPATIBLE_TOUCH_TEST_CameraPosition, IRC_COMPATIBLE_TOUCH_TEST_CameraTarget, IRC_COMPATIBLE_TOUCH_TEST_CameraUp, heap);
    arc = func_020490F4(0x5e, heap);
    IRC_COMPATIBLE_TOUCH_TEST_InitModel(p + 4, (int)arc, (const u16 *)IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds, 1, heap);
    IRC_COMPATIBLE_TOUCH_TEST_InitModel(p + 0x64, (int)arc, (const u16 *)IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds, 2, heap);
    ARC_TOOL_DeleteHandle(arc);
}
