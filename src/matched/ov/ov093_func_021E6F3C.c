/*
 * function: func_021E6F3C
 * address:  0x021E6F3C
 * packet:   pkt_ov093_021E6F3C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8114  0x021C8114  thumb  ov093
 *   func_021E6F7C  0x021E6F7C  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern u16 func_021C8114(u8 *p);
extern int func_021E6F7C(int id);
extern int func_021C8030(u8 *p, int v, u16 k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E6F3C(int x, int a, int c)
{
    u16 id;
    int r;

    if (c == BTL_EVENT_GetVar(2)) {
        id = func_021C8114((u8 *)a);
        if (id != 0 && func_021E6F7C(id) == 0) {
            r = func_021C8030((u8 *)a, c, id);
            BTL_EVENT_OverwriteVar(0x12, id);
            BTL_EVENT_OverwriteVar(0xd, r);
        }
    }
}
