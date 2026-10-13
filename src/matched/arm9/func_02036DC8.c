/*
 * function: GFL_NET_WM_ICON_GetCharName
 * address:  0x02036DC8
 * packet:   pkt_02036DC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Maps the display control word of the requested engine onto the icon
 * render scale: the OBJ bank bits (20-21) and the OBJ-character mapping
 * bit (4) together pick 4x, 2x or 1x, and anything else is a fatal
 * configuration error.  The mask 0x00300010 is shared by both arms, so
 * the compiler hoists it out of the if and the DISPCNT read happens
 * inside; the switch then binary-searches the three sparse case values
 * with 0x00100010 as the middle.
 *
 * Wave 14: the balanced tree needs a FOURTH case label.  The switch is
 * over the SDK's GXOBJVRamModeChar values (1D_32K 0x10, 1D_64K 0x00100010,
 * 1D_128K 0x00200010, 1D_256K 0x00300010); 256K shares the default's
 * fatal arm, and with four labels mwcc switches from a linear chain to the
 * binary search the image has (docs/notes/pkt_02036DC8.c.txt measured
 * three labels only).
 *
 * symbols:
 *   str_020A79F0  0x020A79F0  data
 *   str_020A79FC  0x020A79FC  data
 *   GX_GetBankForOBJ     0x02080C24  arm
 *   GX_GetBankForSubOBJ  0x02080C64  arm
 *   func_02034714        0x02034714  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_GetCharName.c  *       --func GFL_NET_WM_ICON_GetCharName --addr 0x02036DC8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef volatile unsigned int vu32;

extern const char str_020A79F0[];
extern const char str_020A79FC[];

extern u32  GX_GetBankForOBJ(void);
extern u32  GX_GetBankForSubOBJ(void);
extern void func_02034714(const char *expr, u32 line, const char *file);

u32 GFL_NET_WM_ICON_GetCharName(u32 engine, u32 b)
{
    int m;

    if (engine == 1) {
        GX_GetBankForOBJ();
        m = *(vu32 *)0x04000000 & 0x00300010;
    } else {
        GX_GetBankForSubOBJ();
        m = *(vu32 *)0x04001000 & 0x00300010;
    }

    switch (m) {
    case 0x10:
        return b * 4;
    case 0x00100010:
        return b * 2;
    case 0x00200010:
        return b;
    case 0x00300010:
    default:
        func_02034714(str_020A79F0, 0xfb, str_020A79FC);
        return b;
    }
}
