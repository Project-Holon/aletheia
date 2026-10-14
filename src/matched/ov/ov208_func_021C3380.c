/*
 * function: ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer
 * address: 0x021C3380
 * packet: pkt_ov208_021C3380
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   _s32_div_f 0x0209C0A4 arm
 *   ov208_func_021C3208 0x021C3208 thumb ov208
 *   ov208_func_021C337C 0x021C337C thumb ov208
 *   ov208_func_021C3378 0x021C3378 thumb ov208
 *   ov208_func_021C2DE0 0x021C2DE0 thumb ov208
 */
#include "../include/Obj02256.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern u64 func_020870D0(void);
extern void ov208_func_021C3208(u16 *heap, u8 *p, int key);
extern void ov208_func_021C337C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C3378(u16 *heap, u8 *p, int key, int first, u16 second);
extern void ov208_func_021C2DE0(u16 *heap, u8 *p, int key, int first, u16 second);

void ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer(u16 *heap, u8 *p, int key)
{
    u64 now;
    u64 start;
    u64 diff;
    u64 ms;
    u16 cur;
    u16 secs;
    u16 rem;
    u16 hund;
    if (((struct Obj02256 *)p)->f68 != 0) {
        now = func_020870D0();
        start = *(u64 *)(p + 0x6c);
        if (now >= start)
            diff = now - start;
        else
            diff = now + (0xFFFFFFFFFFFFFFFFULL - start);
        ms = (diff * 64) / 33514;
        if (ms > 9990)
            ms = 9990;
        ((struct Obj02256 *)p)->f74 = (u16)ms;
        if (((struct Obj02256 *)p)->f74 >= ((struct Obj02256 *)p)->f38) {
            ((struct Obj02256 *)p)->f74 = ((struct Obj02256 *)p)->f38;
            ((struct Obj02256 *)p)->f68 = 0;
            ov208_func_021C3208(heap, p, key);
        }
    }
    cur = ((struct Obj02256 *)p)->f74;
    if (cur != ((struct Obj02256 *)p)->f76) {
        secs = cur / 1000;
        rem = cur % 1000;
        hund = rem / 10 + ((rem % 10) >= 5 ? 1 : 0);
        ov208_func_021C337C(heap, p, key);
        ov208_func_021C3378(heap, p, key, secs, hund);
        ov208_func_021C2DE0(heap, p, key, secs, hund);
        ((struct Obj02256 *)p)->f76 = ((struct Obj02256 *)p)->f74;
    }
}
