/*
 * function: func_021E3CB0
 * address:  0x021E3CB0
 * packet:   pkt_ov093_021E3CB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   func_021E3F08  0x021E3F08  thumb  ov093
 */
#include "../include/Obj13515.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int);
extern void *func_021C88A4(char *p, int a, int b);
typedef unsigned int   u32;
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
typedef struct Word { unsigned int v; } Word;
extern Word BTLV_CORE_MakeSlotKind1Value(unsigned int a);
extern void func_021C88C8(void *a, void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C83DC(char *p, int x);
extern void func_021E3F08(void *a, int c, int *w);

void func_021E3CB0(int u, void *a, int c, int *w)
{
    char *p;

    if (c == BTL_EVENT_GetVar(2)) {
        switch (w[0]) {
        case 0:
            p = func_021C88A4(a, 0xc, c);
            ((struct Obj13515 *)p)->f4 = 0x19;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind1Value(BTL_EVENT_GetFactorKey((void *)u));
            p[0xf] = c;
            func_021C88C8(a, p);
            BTL_EVENT_OverwriteVar(0x3e, 2);
            w[6] = 1;
            w[0] = 1;
            w[1] = 0;
            break;
        case 1:
            BTL_EVENT_OverwriteVar(0x3e, 2);
            w[0] = 2;
            break;
        case 2:
        default:
            func_021C83DC(a, 1);
            func_021E3F08(a, c, w);
            break;
        }
    }
}
