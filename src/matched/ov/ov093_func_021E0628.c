/*
 * function: func_021E0628
 * address:  0x021E0628
 * packet:   pkt_ov093_021E0628
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
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 */
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int key);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern void *func_021C88A4(char *p, int a, int b);
typedef unsigned int   u32;
extern int BTLV_CORE_MakeSlotKind2Index(u32 a);
extern void func_021C88C8(void *a, void *b);
extern void func_021C88B4(void *a, int k, int b);

struct S {
    int f0;
    int f4;
    int f8;
    int fC;
    u16 f10;
    u16 f12;
};

void func_021E0628(int a, void *b, int c)
{
    struct S *p;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_FIELD_GetStaticSlotObject(2) == 0) {
            p = func_021C88A4(b, 0x1b, c);
            p->f4 = 2;
            p->f8 = BTLV_CORE_MakeSlotKind2Index(5);
            p->f12 = (p->f12 & ~0xff) | 1;
            p->f10 = 0x75;
            func_021C88C8(b, p);
            func_021C88B4(b, 0x35, c);
        }
    }
}
