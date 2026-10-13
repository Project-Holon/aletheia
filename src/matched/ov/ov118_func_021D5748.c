/*
 * function: func_021D5748
 * address:  0x021D5748
 * packet:   pkt_ov118_021D5748
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   MCSS_GetPosition  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   d_021D7CB4     0x021D7CB4  data
 *   d_021D7FEC     0x021D7FEC  data
 *   d_021D80C4     0x021D80C4  data
 *   d_021D8790     0x021D8790  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00672.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 v[4];
} Quad;

extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u32 PM_VOICE_Play(u32, u32, u32, u32, u32, u32, u32, u32);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void func_021DFD24(u32 *p);
extern void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern const Quad d_021D7CB4;
extern const u8 d_021D7FEC[];
extern const u8 d_021D80C4[];
extern u8 d_021D8790[];

void func_021D5748(u8 *p, int idx)
{
    void *x;
    u32 buf[3];

    x = func_021D8FA4(p, 1 - func_021D8AA8(p));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj00672 *)p)->f11EE == 0) {
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00672 *)p)->f868));
        if (((struct Obj00672 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x14, buf, d_021D8790, ((struct Obj00672 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x28, buf, (void *)d_021D80C4, ((struct Obj00672 *)p)->f5F4);
        }
    } else {
        Quad t = d_021D7CB4;
        u32 obj = ((u32 *)(p + 0x844))[t.v[idx]];
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00672 *)p)->f868));
        if (((struct Obj00672 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x14, buf, d_021D8790, ((struct Obj00672 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x12, buf, (void *)d_021D7FEC, ((struct Obj00672 *)p)->f5F4);
        }
    }
}
