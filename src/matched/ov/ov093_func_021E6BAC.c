/*
 * function: func_021E6BAC
 * address:  0x021E6BAC
 * packet:   pkt_ov093_021E6BAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E6BAC(int x, int a, int c)
{
    void *p;
    u16 id;

    if (c == BTL_EVENT_GetVar(2)) {
        p = (void *)BTL_EVENT_GetVar(0x3f);
        id = BTL_EVENT_GetVar(0x12);
        func_021C8838(p, 1, 0x79);
        func_021C8860(p, id);
        BTL_EVENT_OverwriteVar(0x51, 1);
    }
}
