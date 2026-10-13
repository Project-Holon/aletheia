/*
 * function: func_021E4828
 * address:  0x021E4828
 * packet:   pkt_ov093_021E4828
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
 *   BTL_POKEPARAM_GetLastSelectedMoveId  0x021D67B8  thumb  ov093
 *   BTL_POKEPARAM_HasMove  0x021D5750  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *q);
extern int BTL_POKEPARAM_HasMove(u8 *q, int w);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
typedef struct Word { u32 v; } Word;
typedef enum { K_0 } KType;
struct Rec { u32 f0; u32 f4; Word f8; u8 fc; u8 fd; u8 fe; u8 ff; };

extern Word BTLV_CORE_MakeSlotKind2(int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E4828(int a0, u8 *s, int k)
{
    KType c;
    u8 v;
    u8 *q;
    int w;
    struct Rec *e;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(6);
        q = func_021C7CF4((int *)s, v);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)q, 0xd) == 0) {
            w = BTL_POKEPARAM_GetLastSelectedMoveId(q);
            if (w != 0 && w != 0xa5 && BTL_POKEPARAM_HasMove(q, w) != 0) {
                c = 4;
                if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)q, 1) != 0)
                    c = (u8)(c + 1);
                e = (struct Rec *)func_021C88A4((char *)s, 12, k);
                e->f4 = 0xd;
                e->f8 = BTLV_CORE_MakeSlotKind2(c, w);
                e->ff = v;
                func_021C88C8(s, (u8 *)e);
            }
        }
    }
}
