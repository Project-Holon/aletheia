/*
 * function: func_021F8B0C
 * address:  0x021F8B0C
 * packet:   pkt_021F8B0C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   DPW_TR_Main  0x021C7C1C  arm
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *
 * 18-slot switch on the 0x021C86A8 index (case value = index + 15, bound 17):
 * index 14 returns 1, and four separate case groups (15, 13+16, 0+3, 1+12)
 * each call func_021F4FC4 and archive n at +0x38 before returning 2; the
 * remaining indexes fall through to the shared tail (one more func_021F4FC4)
 * and the function returns 0.  DPW_TR_Main(p) runs first, unconditionally.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
*/
#include "../include/Obj04905.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void *DPW_TR_Main(u8 *p);
extern u32 DPW_TR_IsAsyncEnd(void *p);
extern s32 DPW_TR_GetAsyncResult(void);
extern void func_021F513C(u8 *p);
extern void func_021F4FC4(u8 *p);

int func_021F8B0C(u8 *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd(DPW_TR_Main(p)) != 0) {
        n = DPW_TR_GetAsyncResult();
        ((struct Obj04905 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            return 1;
        case 16:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 14:
        case 17:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 0:
        case 3:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 1:
        case 13:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        }
        func_021F4FC4(p);
        func_021F513C(p);
    } else {
        if (++((struct Obj04905 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 0;
}
