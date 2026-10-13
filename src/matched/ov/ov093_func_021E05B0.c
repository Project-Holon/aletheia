/*
 * function: func_021E05B0
 * address:  0x021E05B0
 * packet:   pkt_ov093_021E05B0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern void *func_021C88A4(char *p, int a, int b);
typedef unsigned int   u32;
extern int BTLV_CORE_MakeSlotKind2Index(u32 a);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E05B0(int a, void *b, int c)
{
    int *p;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_FIELD_GetStaticSlotObject(1) == 0) {
            p = func_021C88A4(b, 0x1b, c);
            p[1] = 1;
            p[2] = BTLV_CORE_MakeSlotKind2Index(5);
            func_021C8838(p + 4, 2, 0x359);
            func_021C8860((struct S *)(p + 4), c);
            func_021C88C8(b, p);
        } else {
            p = func_021C88A4(b, 0x1c, c);
            p[1] = 1;
            func_021C88C8(b, p);
        }
    }
}
