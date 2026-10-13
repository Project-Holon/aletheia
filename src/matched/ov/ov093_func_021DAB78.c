/*
 * function: func_021DAB78
 * address:  0x021DAB78
 * packet:   pkt_ov093_021DAB78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DAB78(int unused, void *a, int id)
{
    u8 *r;

    if (id == func_021D775C(4)) {
        if (WAZA_TOOL_GetFlag(func_021D775C(0x12), 8) != 0 && func_021D76BC(0x40, 1) != 0) {
            func_021C88B4(a, 2, id);
            r = (u8 *)func_021C88A4(a, 4, id);
            func_021C8838(r + 4, 2, 0xd2);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
            func_021C88B4(a, 3, id);
        }
    }
}
