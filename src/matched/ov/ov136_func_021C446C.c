/*
 * function: MAILSYS_IsMessageIncomplete
 * address:  0x021C446C
 * packet:   pkt_ov136_021C446C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * note:     2026-10-02 only unresolved witness PMSI_PARAM_IsEnabled (file exists in src/matched/arm9, no shard yet)
 *
 * symbols:
 *   MAILSYS_IsMessageIncomplete 0x021C446C thumb
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   d_021C77A0 0x021C77A0 data a1
 */
#include "../include/Obj14184.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 d_021C77A0[][3];
typedef unsigned int   u32;
struct T;
extern int PMSI_PARAM_IsComplete(struct T *p, u32 a1);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
int MAILSYS_IsMessageIncomplete(void *a)
{
    int t = 1;
    int n = 0;
    int c0 = 0;
    int c1 = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (d_021C77A0[((u8 *)((struct Obj14184 *)a)->f1C)[0xb]][i] != 0xFF) n++;
    }
    if (n == 3) t = 0;
    for (i = 0; i < 3; i++) {
        u8 *x = *(u8 * *)&((struct Obj14184 *)a)->f1C;
        if (d_021C77A0[x[0xb]][i] != 0xFF) {
            if (PMSI_PARAM_IsComplete((struct T *)(x + 0x16 + i * 8), 0x64)) c1++;
        } else {
            if (PMSI_PARAM_IsEnabled((u16 *)(x + 0x16 + i * 8))) c0++;
        }
    }
    if (c0 < t || c1 < n) return 1;
    return 0;
}
