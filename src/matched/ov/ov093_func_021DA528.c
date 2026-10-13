/*
 * function: HAND_TOKUSEI_AnticipationOnMemberIn
 * address:  0x021DA528
 * packet:   pkt_ov093_021DA528
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C7D54   0x021C7D54  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   HAND_TOKUSEI_AnticipationFoeIsThreat   0x021DA5BC  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int HAND_TOKUSEI_AnticipationFoeIsThreat(void *a, void *b);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void HAND_TOKUSEI_AnticipationOnMemberIn(int a, int b, int c)
{
    u8 buf[4];
    u8 n;
    u8 i;
    void *q;
    u8 *p;

    if (c != BTL_EVENT_GetVar(2))
        return;
    n = func_021C7D54((u8 *)b, (u8 *)c, buf);
    q = func_021C7CF4((int *)b, c);
    for (i = 0; i < n; i++) {
        if (HAND_TOKUSEI_AnticipationFoeIsThreat(q, func_021C7CF4((int *)b, buf[i])) != 0)
            break;
    }
    if (i == n)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 4, c);
    func_021C8838(p + 4, 2, 0x1b4);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}
