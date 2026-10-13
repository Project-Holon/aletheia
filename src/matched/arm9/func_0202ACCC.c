/*
 * function: ISS_CITY_SYS_UpdateByMode
 * address:  0x0202ACCC
 * packet:   pkt_0202ACCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Dispatches on the state word returned by ISS_CITY_SYS_GetMode over a three-way
 * state machine.  One `switch` on the call result is what puts the result
 * straight into r0 for all three `cmp`s: a named local would have stored it.
 *
 * symbols:
 *   ISS_CITY_SYS_GetMode  0x0202ABF8  thumb
 *   ISS_CITY_SYS_UpdateSteady  0x0202ACFC  thumb
 *   ISS_CITY_SYS_UpdateFadeIn  0x0202AD10  thumb
 *   ISS_CITY_SYS_UpdateFadeOut  0x0202AD44  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_UpdateByMode.c \
 *       --func ISS_CITY_SYS_UpdateByMode --addr 0x0202ACCC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 ISS_CITY_SYS_GetMode(void *obj);
extern int ISS_CITY_SYS_UpdateSteady(int a0);
extern void ISS_CITY_SYS_UpdateFadeIn(void *obj);
extern void ISS_CITY_SYS_UpdateFadeOut(void *obj);

void ISS_CITY_SYS_UpdateByMode(u8 *p)
{
    switch (ISS_CITY_SYS_GetMode(p)) {
    case 0:
        ISS_CITY_SYS_UpdateSteady((int)p);
        break;
    case 1:
        ISS_CITY_SYS_UpdateFadeIn(p);
        break;
    case 2:
        ISS_CITY_SYS_UpdateFadeOut(p);
        break;
    }
}
