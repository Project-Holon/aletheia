/*
 * file:     unit_021E06DC.c
 * function: func_021E06DC, func_021E0720
 * address:  0x021E06DC
 * packet:   pkt_ov093_021E06DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F29B8     0x021F29B8  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
typedef struct { unsigned v; } Word;
extern Word BTLV_CORE_MakeSlotKind3(int a);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E06DC(int a, void *b, int c)
{
    int *p;

    if (c == BTL_EVENT_GetVar(3)) {
        p = func_021C88A4(b, 0x1b, c);
        p[1] = 5;
        *(Word *)(p + 2) = BTLV_CORE_MakeSlotKind3(c);
        func_021C8838(p + 4, 1, 0x73);
        func_021C88C8(b, p);
    }
}


extern int d_021F29B8[];
int *func_021E0720(int *p);

int *func_021E0720(int *p)
{
    *p = 2;
    return d_021F29B8;
}
