/*
 * function: func_021E1AA4
 * address:  0x021E1AA4
 * packet:   pkt_ov093_021E1AA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021E1AE4  0x021E1AE4  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Ent { u16 a; u16 b; u8 c; u8 d; u8 e; u8 f; } Ent;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021E1AE4(void *m, int x, Ent *out);
extern u32 BTL_CALC_MulRatio(u32 a, u32 b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E1AA4(void *p, int id, int u, int x, int arg)
{
    Ent e;
    if (id == BTL_EVENT_GetVar(3)) {
        if (func_021E1AE4(func_021C7CF4(p, id), x, &e)) {
            BTL_EVENT_OverwriteVar(0x37, BTL_CALC_MulRatio(e.b, arg));
        }
    }
}
