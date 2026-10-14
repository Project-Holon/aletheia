/*
 * function: MAILSYS_CreateMessage
 * address: 0x021C409C
 * packet: pkt_ov136_021C409C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_02008F80 0x02008F80 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02008F84 0x02008F84 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_02008FB0 0x02008FB0 thumb
 *   func_02008FB8 0x02008FB8 thumb
 *   func_02008FC0 0x02008FC0 thumb
 *   func_02008FC8 0x02008FC8 thumb
 *   PMSI_PARAM_Copy 0x02024570 thumb
 *   d_021C7EEC 0x021C7EEC data a1
 */
#include "../include/Obj03834.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021C7EEC[];
extern void *func_02030734(unsigned heapId, unsigned size, int clear, const char *site, u16 tag);
extern void MIi_CpuClearFast(unsigned, void *, unsigned);
typedef unsigned int   u32;
struct Sub02008F80Obj;
extern u32 func_02008F80(const struct Sub02008F80Obj *obj);
extern void *STRBUF_Create(unsigned, u16);
extern u8 *func_02008F84(struct Sub02008F80Obj *obj);
struct Rec8;
struct Strbuf;
struct Sub02008F80Entry;
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u8 func_02008FB0(const struct Sub02008F80Obj *obj);
extern u8 func_02008FB8(const struct Sub02008F80Obj *obj);
extern u16 func_02008FC0(const struct Sub02008F80Obj *obj);
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
void *MAILSYS_CreateMessage(void *a, unsigned heap)
{
    u8 *p;
    u16 i;
    i = 0;
    p = func_02030734((u16)heap, 0x34, 0, d_021C7EEC, 0x147);
    MIi_CpuClearFast(0, p, 0x34);
    ((struct Obj03834 *)p)->f0 = i;
    ((struct Obj03834 *)p)->f4 = func_02008F80(a);
    ((struct Obj03834 *)p)->fC = STRBUF_Create(0x10, heap);
    STRBUF_SetString(((struct Obj03834 *)p)->fC, (const u16 *)func_02008F84(a));
    p[0xB] = func_02008FA4(a);
    p[9] = func_02008FB0(a);
    p[0xA] = func_02008FB8(a);
    ((struct Obj03834 *)p)->f32 = func_02008FC0(a);
    for (; i < 3; i++) PMSI_PARAM_Copy((struct Rec8 *)(p + 0x16 + i * 8), (const struct Rec8 *)func_02008FC8(a, (u8)i));
    return p;
}
