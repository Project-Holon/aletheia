/*
 * function: WEATHER_TASK_PrewarmParticles
 * address:  0x021A2254
 * packet:   pkt_ov021_021A2254
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_IsParticleLinked  0x021A2BC4  thumb  ov021
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02702.h"
#include "../include/Obj12713.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int WEATHER_TASK_IsParticleLinked(u32 a);

void WEATHER_TASK_PrewarmParticles(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w)
{
    int j;
    u8 *cur;
    int cnt;
    int i;
    u8 *next;

    fn(p, n, w);
    cnt = 0;
    cur = *(u8 * *)&((struct Obj02702 *)p)->f774;
    if (cur == 0) {
        return;
    }
    next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        j = 0;
        if (cnt > 0) {
            do {
                ((void (*)(u8 *))(*(u32 *)(*(u32 *)(p + 0x20) + 0x48)))(cur);
                if (WEATHER_TASK_IsParticleLinked((u32)cur) == 0) {
                    break;
                }
                j++;
            } while (j < cnt);
        }
        cur = next;
        next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
        if (i >= m) {
            if (i % m == 0) {
                cnt += k;
            }
        }
        if (cur == *(u8 * *)&((struct Obj02702 *)p)->f774) {
            break;
        }
        i++;
    } while (i < n);
}
