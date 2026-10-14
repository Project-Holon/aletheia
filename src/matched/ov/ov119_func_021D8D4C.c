/*
 * function: POKETRADE_PROC_LoadSlotMon
 * address:  0x021D8D4C
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02007A18  0x02007A18  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj08050.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
struct Mon;
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern u32 POKEPARTY_GetCount(void *m);
extern void *POKEPARTY_GetMember(void *m, u32 c);
extern void *POKE_TOOL_Create(u16 species, u16 level, unsigned long long id, u16 heap);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void MI_CpuCopy8(void *dst, const void *src, int n);

void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p)
{
    int n;
    void *res = 0;

    if (b == -1)
        goto out;
    n = ((struct Obj08050 *)p)->f630;
    if (b > n)
        return 0;
    if (b != n && c != -1) {
        res = POKE_TOOL_CreateFromBoxParam((struct Mon *)func_02007A18(a, b, c), ((struct Obj08050 *)p)->f5F4);
    } else {
        void *m = ((struct Obj08050 *)p)->f838;
        if (c >= (int)POKEPARTY_GetCount(m))
            goto out;
        if (c == -1)
            goto out;
        {
            void *mon = POKE_TOOL_Create(1, 1, 1, ((struct Obj08050 *)p)->f5F4);
            int sz = POKE_TOOL_GetPartyParamSize();
            MI_CpuCopy8(POKEPARTY_GetMember(m, c), mon, sz);
            res = mon;
        }
    }
out:
    return res;
}
