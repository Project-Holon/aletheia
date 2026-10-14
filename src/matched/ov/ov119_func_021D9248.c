/*
 * function: POKETRADE_PROC_RecvTradeSummary
 * address:  0x021D9248
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02008574  0x02008574  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_0202EB7C  0x0202EB7C  thumb
 */
#include "../include/Obj22714.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
struct Big;
struct Sub02009470Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void MI_CpuCopy8(void *dst, const void *src, int n);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern u32 func_0202EB7C(u32 a0, u32 a1);

void POKETRADE_PROC_RecvTradeSummary(void *p, int a1, void *a2, char *a3, int a4)
{
    u8 buf[0x28];
    u8 x, y;
    u32 r1, r2;
    void *saved;

    if (a4 != (int)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (p == (void *)GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    saved = func_02009470(GAME_DATA_GetSaveControl(((struct Obj22714 *)a3)->f82C));
    MI_CpuCopy8(a2, buf, 0x28);
    x = func_0200856C((const struct Sub0200852CObj *)buf);
    y = func_02008570((const struct Sub0200852CObj *)buf);
    r1 = func_02025C1C(x, y, func_02008564((const struct Sub0200852CObj *)buf));
    r2 = func_02025C30(x, y, func_02008564((const struct Sub0200852CObj *)buf));
    if (x == r1 && y == r2)
        func_02008574((struct Sub0200852CObj *)buf, x, y);
    else
        func_02008574((struct Sub0200852CObj *)buf, 0, 0);
    func_0202EB7C((u32)saved, (u32)buf);
}
