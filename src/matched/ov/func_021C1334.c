/*
 * function: WIFICLUB_RecvRuleId
 * address:  0x021C1334
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   WIFICLUB_ApplyRuleId  0x021BCC58  thumb  ov099
 *
 * When the fifth argument matches the arm9 predicate, applies the first word of the third to the fourth.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void WIFICLUB_ApplyRuleId(char *p, u32 x);

void WIFICLUB_RecvRuleId(int a, int b, int *p, void *q, int e)
{
    if (e == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        WIFICLUB_ApplyRuleId(q, *p);
    }
}
