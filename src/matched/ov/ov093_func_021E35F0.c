/*
 * function: func_021E35F0
 * address:  0x021E35F0
 * packet:   pkt_ov093_021E35F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E35F0(int u, void *p, int key, int *o)
{
    u8 t = BTL_EVENT_GetVar(3);
    if (t != key) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 5) != 0) {
            if (BTL_POKEPARAM_HasSick(func_021C7CF4(p, key), 0x21) == 0) {
                if (BTL_EVENT_OverwriteVar(2, key) != 0) {
                    BTL_EVENT_OverwriteVar(4, key);
                    *o = 1;
                }
            }
        }
    }
}
