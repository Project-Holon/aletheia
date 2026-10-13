/*
 * function: func_02012DD0
 * address:  0x02012DD0
 * packet:   pkt_02012DD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012DD0.c \
 *       --func func_02012DD0 --addr 0x02012DD0 --cc 1.1p1 --thumb
 *
 * symbols:
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   WIH_DWC_ResumeTimers  0x02010444  thumb
 */
#include "../include/Obj11252.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern int  func_02005C64(void);
struct Sub02007168;
extern u32 SAVE_CONTROL_MainSave(struct Sub02007168 *p);
extern int func_020351A0(u32 v);
extern void WIH_DWC_ResumeTimers(void);

int func_02012DD0(u8 *p)
{
    int r;

    if (func_02005C64() == 1) {
        return 0;
    }
    r = SAVE_CONTROL_MainSave((struct Sub02007168 *)(((struct Obj11252 *)p)->f0));
    if ((u32)(r - 2) <= 1) {
        func_020351A0(2);
        WIH_DWC_ResumeTimers();
        ((struct Obj11252 *)p)->f1CE = 0;
    }
    return r;
}
