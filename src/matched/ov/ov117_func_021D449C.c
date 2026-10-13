/*
 * function: func_021D449C
 * address:  0x021D449C
 * packet:   pkt_ov117_021D449C
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E3BB0  0x021E3BB0  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D4290  0x021D4290  thumb  ov117
 *   func_021D4520  0x021D4520  thumb  ov117
 *   func_021D4544  0x021D4544  thumb  ov117
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_021E3BB0(char *p);
extern void func_021E3230(void *p);
extern int func_021D8A24(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_021D8E84(void *p, int next);
extern void func_021D4290(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
extern void func_021D4520(u8 *p);
extern void func_021D4544(u8 *p);

void func_021D449C(u8 *p)
{
    func_021E3BB0((char *)p);
    if (((struct Obj00001 *)p)->f854 == 1) {
        func_021D4290(p, p + 0x11ED, p + 0x11EF, ((struct Obj00001 *)p)->f834, 1);
        func_021D4290(p, p + 0x11EE, p + 0x11F0, ((struct Obj00001 *)p)->f830, 0);
        func_021E3230(p);
        if (func_021D8A24(p) != 0) {
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8);
            func_021D8E84(p, (int)func_021D4520);
        } else {
            func_021D8E84(p, (int)func_021D4544);
        }
    }
}
