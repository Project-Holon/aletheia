/*
 * function: func_021E3D98
 * address:  0x021E3D98
 * packet:   pkt_ov093_021E3D98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E3D98(int u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2)) {
        if (*p >= 2) {
            if (p[1] == 0)
                BTL_EVENT_OverwriteVar(0x22, 0x1a);
            else if (p[2] == 0x1f)
                BTL_EVENT_OverwriteVar(0x22, 0x1a);
            *p = 3;
        }
    }
}
