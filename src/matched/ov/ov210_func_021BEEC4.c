/*
 * function: func_021BEEC4
 * address:  0x021BEEC4
 * packet:   pkt_ov210_021BEEC4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterCharacter(void *arc, u32 idx, u32 a, u32 b, u16 heap);
extern int CLACT_RegisterPalette(void *arc, u32 idx, u32 a, u32 b, u16 heap);
extern int CLACT_RegisterCellAnim(void *arc, u32 a, u32 b, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern u32 func_020275E4(void);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);

struct Res021BEEC4 {
    u8 pad[0x10C];
    int a[6];
    int b[6];
    int c[4];
};

void func_021BEEC4(struct Res021BEEC4 *p)
{
    u32 i;
    void *arc;
    void *arc2;

    for (i = 0; i < 6; i++)
        p->a[i] = -1;
    for (i = 0; i < 6; i++)
        p->b[i] = -1;
    for (i = 0; i < 4; i++)
        p->c[i] = -1;

    arc = func_020490F4(0x9F, 0x807B);
    p->a[1] = CLACT_RegisterCharacter(arc, 0x4E, 0, 0, 0x7B);
    p->b[1] = CLACT_RegisterPalette(arc, 0x4B, 0, 0, 0x7B);
    p->c[1] = CLACT_RegisterCellAnim(arc, 0x54, 0x64, 0x7B);
    p->a[2] = CLACT_RegisterCharacter(arc, 0x4E, 0, 1, 0x7B);
    p->b[2] = CLACT_RegisterPalette(arc, 0x4B, 1, 0, 0x7B);
    p->a[5] = CLACT_RegisterCharacter(arc, 0x4D, 0, 0, 0x7B);
    p->b[5] = CLACT_RegisterPalette(arc, 0x48, 0, 0x60, 0x7B);
    p->c[3] = CLACT_RegisterCellAnim(arc, 0x53, 0x63, 0x7B);
    p->a[3] = CLACT_RegisterCharacter(arc, 0x52, 0, 0, 0x7B);
    p->b[3] = CLACT_RegisterPalette(arc, 0x4C, 0, 0x80, 0x7B);
    p->c[2] = CLACT_RegisterCellAnim(arc, 0x55, 0x65, 0x7B);
    p->a[4] = CLACT_RegisterCharacter(arc, 0x52, 0, 1, 0x7B);
    p->b[4] = CLACT_RegisterPalette(arc, 0x4C, 1, 0x60, 0x7B);
    ARC_TOOL_DeleteHandle(arc);

    arc2 = func_020490F4(func_020275E4(), 0x807B);
    p->a[0] = CLACT_RegisterCharacter(arc2, func_02027618(), 0, 0, 0x7B);
    p->b[0] = CLACT_RegisterPalette(arc2, func_02027614(), 0, 0xA0, 0x7B);
    p->c[0] = CLACT_RegisterCellAnim(arc2, func_0202761C(2), func_02027620(2), 0x7B);
    ARC_TOOL_DeleteHandle(arc2);
}
