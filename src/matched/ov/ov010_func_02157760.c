/*
 * function: DELIVERY_BEACON_StepCollectPieces
 * address:  0x02157760
 * packet:   pkt_ov010_02157760
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wave 75: ov014 leaves 0x021780C4 and 0x02177BCC filed and verified;
 *   all six relocations resolve. 0x02177BAC was already matched.
 * levers (lane R1): the old 3-slot frame miss was the `sel`/`sel2` locals, which
 *   copy-propagate into one; the original writes p->sel directly and the two stack
 *   slots are the loop-hoisted 0x31B8 address. `(e+0x60) & (q+0x14)` operand order,
 *   and the CRC result in a named local for `cmp r0, r1`.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = q;` before `base = q + 0x7C;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   NET_WHPIPE_GetEntryBeaconData  0x02177B2C  thumb  ov014
 *   NET_WHPIPE_ReleaseEntrySlot  0x02177BAC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   NET_WHPIPE_SelectEntry  0x021780C4  thumb  ov014
 *   MI_CpuCopy8  0x02082D44  arm
 *   NET_WHPIPE_ReleaseAllEntrySlots  0x02177BCC  thumb  ov014
 */
#include "../include/Obj04145.h"
#include "../include/Obj04913.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *NET_WHPIPE_GetEntryBeaconData(int);
extern void NET_WHPIPE_ReleaseEntrySlot(u32 idx);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void NET_WHPIPE_SelectEntry(u32 i);
extern void MI_CpuCopy8(void *, void *, u32);
extern void NET_WHPIPE_ReleaseAllEntrySlots(void);

typedef struct P {
    u8 pad00[0x31B8];
    u8 sel;
} P;

void DELIVERY_BEACON_StepCollectPieces(u8 *q)
{
    P *p = (P *)q;
    u8 *base;

    int i;
    u8 *e;
    int idx;
    u32 crc;

    base = q + 0x7C;

    for (i = 0; i < 16; i++) {
        e = NET_WHPIPE_GetEntryBeaconData(i);
        if (e == 0)
            continue;
        if (e[0x5F] != ((struct Obj04145 *)q)->f10) {
            NET_WHPIPE_ReleaseEntrySlot(i);
        } else if ((((struct Obj04913 *)e)->f60 & ((struct Obj04145 *)q)->f14) == 0) {
            NET_WHPIPE_ReleaseEntrySlot(i);
        } else if (e[0x5E] != p->sel && p->sel != 0xFF) {
            NET_WHPIPE_ReleaseEntrySlot(i);
        } else {
            idx = e[0x5C] - 1;
            if (idx >= 0x12)
                continue;
            if (q[idx * 100 + 0xD8] != 0)
                continue;
            crc = func_0203F1FC(e + 8, 0x54);
            if (crc != ((struct Obj04913 *)e)->f0) {
                NET_WHPIPE_ReleaseEntrySlot(i);
            } else {
                if (p->sel == 0xFF)
                    p->sel = e[0x5E];
                NET_WHPIPE_SelectEntry(i);
                MI_CpuCopy8(e, base + idx * 100, 100);
                NET_WHPIPE_ReleaseAllEntrySlots();
            }
        }
    }
}
