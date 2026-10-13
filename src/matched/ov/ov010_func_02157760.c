/*
 * function: func_02157760
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
 *   func_02177B2C  0x02177B2C  thumb  ov014
 *   func_02177BAC  0x02177BAC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   NET_WHPIPE_SelectEntry  0x021780C4  thumb  ov014
 *   func_02082D44  0x02082D44  arm
 *   func_02177BCC  0x02177BCC  thumb  ov014
 */
#include "../include/Obj04145.h"
#include "../include/Obj04913.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_02177B2C(int);
extern void func_02177BAC(u32 idx);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void NET_WHPIPE_SelectEntry(u32 i);
extern void func_02082D44(void *, void *, u32);
extern void func_02177BCC(void);

typedef struct P {
    u8 pad00[0x31B8];
    u8 sel;
} P;

void func_02157760(u8 *q)
{
    P *p = (P *)q;
    u8 *base;

    int i;
    u8 *e;
    int idx;
    u32 crc;

    base = q + 0x7C;

    for (i = 0; i < 16; i++) {
        e = func_02177B2C(i);
        if (e == 0)
            continue;
        if (e[0x5F] != ((struct Obj04145 *)q)->f10) {
            func_02177BAC(i);
        } else if ((((struct Obj04913 *)e)->f60 & ((struct Obj04145 *)q)->f14) == 0) {
            func_02177BAC(i);
        } else if (e[0x5E] != p->sel && p->sel != 0xFF) {
            func_02177BAC(i);
        } else {
            idx = e[0x5C] - 1;
            if (idx >= 0x12)
                continue;
            if (q[idx * 100 + 0xD8] != 0)
                continue;
            crc = func_0203F1FC(e + 8, 0x54);
            if (crc != ((struct Obj04913 *)e)->f0) {
                func_02177BAC(i);
            } else {
                if (p->sel == 0xFF)
                    p->sel = e[0x5E];
                NET_WHPIPE_SelectEntry(i);
                func_02082D44(e, base + idx * 100, 100);
                func_02177BCC();
            }
        }
    }
}
