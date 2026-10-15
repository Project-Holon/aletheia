/*
 * function: MB_SEQ_ClearMailDetailText
 * address: 0x021C7360
 * packet: pkt_ov136_021C7360
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02024450 has no witness outside this caller.
 *   2026-10-02: src/matched/arm9/PMSI_PARAM_IsEnabled.c exists (EXACT) but has no shard yet.
 *   After the integrator runs manifest on it, re-run: expect EXACT.
 *   Verified Thumb C is preserved here; ARM9 filing belongs to the integrator.
 *   typedef unsigned short u16;
 *   int PMSI_PARAM_IsEnabled(const u16 *p)
 *   {
 *       if (*p != 0xFFFF) return 1;
 *       return 0;
 *   }
 * symbols:
 *   func_02008FC8 0x02008FC8 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   PMS_DRAW_Clear  0x0202DC9C  thumb  arm9
 */
#include "../include/Obj01066.h"
#include "../include/Obj23643.h"
#include "../include/Obj23644.h"
#include "../include/Obj23645.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj0202DC98;
struct Sub02008F80Entry;
struct Sub02008F80Obj;
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PMS_DRAW_Clear(struct Obj0202DC98 *o, int i, u32 a1);
extern void BG_SYS_ClearSlot(u32);
void MB_SEQ_ClearMailDetailText(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled((const u16 *)func_02008FC8(*(void **)(*(u8 * *)&((struct Obj01066 *)p)->f8 + p[0x1F]*4 + 0x298), (u8)i)) != 0) {
            PMS_DRAW_Clear(((struct Obj23643 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f35C, (u8)i, (int)0);
        }
    }
    if (((struct Obj23644 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f364 != 0) {
        PMS_DRAW_Clear(((struct Obj23645 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f35C, (u8)i, (int)0);
    }
    BG_SYS_ClearSlot(4);
    BG_SYS_ClearSlot(5);
}
