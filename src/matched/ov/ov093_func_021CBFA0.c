/*
 * function: func_021CBFA0
 * address:  0x021CBFA0
 * packet:   pkt_ov093_021CBFA0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021CBFF8  0x021CBFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern unsigned char func_021B9A40(unsigned int x);
typedef struct Word { u32 v; } Word;
extern Word BTLV_CORE_MakeSlotKind2Index(int v);
extern int func_021CBFF8(int a, int b, Word c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

int func_021CBFA0(u8 *p, u8 *q)
{
    int m;
    u8 *w;
    Word t;
    m = func_021B9A40(BTL_POKEPARAM_GetPokeId(q));
    t = BTLV_CORE_MakeSlotKind2Index(5);
    if (func_021CBFF8(m, 3, t)) {
        w = func_021C88A4((char *)p, 4, 0x1f);
        func_021C8838(w + 4, 1, 0x88);
        func_021C8860((struct S *)(w + 4), m);
        func_021C88C8(p, w);
        return 1;
    }
    return 0;
}
