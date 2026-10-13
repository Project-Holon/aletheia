/*
 * function: func_021E6994
 * address:  0x021E6994
 * packet:   pkt_ov093_021E6994
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
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   BTLV_CORE_SetSlotFlag  0x021E8BD0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int BTLV_CORE_MakeSlotKind2(u32 a, u32 b);
union U;
extern void BTLV_CORE_SetSlotFlag(union U *p, int v);

struct S { int w0; int w4; int w8; u8 bc; u8 bd; u8 be; u8 bf; };

void func_021E6994(int x, void *a, int c)
{
    struct S *p;
    int t = 2;
    int r;
    int *q;

    if (c == BTL_EVENT_GetVar(2)) {
        p = func_021C88A4(a, 12, c);
        p->bf = c;
        p->bd = 1;
        p->w4 = 0x18;
        r = BTLV_CORE_MakeSlotKind2(1, t);
        q = &p->w8;
        *q = r;
        BTLV_CORE_SetSlotFlag((union U *)q, 1);
        func_021C88C8(a, p);
    }
}
