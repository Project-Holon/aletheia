/*
 * function: func_0202C0D0
 * address:  0x0202C0D0
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolves the object through ISS_SWITCH_SYS_GetActiveSet and, when found, forwards the
 * argument through ISS_SWITCH_SET_SwitchOn.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0D0.c \
 *       --func func_0202C0D0 --addr 0x0202C0D0 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_SWITCH_SYS_GetActiveSet  0x0202C24C  thumb
 *   ISS_SWITCH_SET_SwitchOn  0x0202C328  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj0202C244;
extern u32 ISS_SWITCH_SYS_GetActiveSet(struct Obj0202C244 *p);
extern u32 ISS_SWITCH_SET_SwitchOn(void *p, u32 idx);

void func_0202C0D0(u8 *p, u32 a)
{
    u32 r = ISS_SWITCH_SYS_GetActiveSet((struct Obj0202C244 *)p);

    if (r != 0) {
        ISS_SWITCH_SET_SwitchOn((void *)r, a);
    }
}
