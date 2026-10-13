/*
 * function: func_021E25FC
 * address:  0x021E25FC
 * packet:   pkt_ov093_021E25FC
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Word { unsigned int v; } Word;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern Word BTLV_CORE_MakeSlotKind2(int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E25FC(void *a, void *b, int c, int *d)
{
    void *v;
    int *p;

    if (c == BTL_EVENT_GetVar(2)) {
        v = func_021C7CF4(b, c);
        if (BTL_POKEPARAM_HasSick(v, 0x19) == 0 && BTL_POKEPARAM_HasSick(v, 2) == 0 && d[6] == 0) {
            p = func_021C88A4(b, 12, c);
            p[1] = 0x19;
            *(Word *)(p + 2) = BTLV_CORE_MakeSlotKind2(5, BTL_EVENT_GetFactorKey(a));
            ((u8 *)p)[12] = 0;
            ((u8 *)p)[15] = c;
            func_021C88C8(b, p);
            d[0] = 0;
            d[1] = 5;
            d[6] = 1;
        }
    }
}
