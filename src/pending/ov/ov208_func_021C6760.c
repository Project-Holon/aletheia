/*
 * function: ov208_func_021C6760
 * address: 0x021C6760
 * packet: pkt_ov208_021C6760
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-03): 4 bytes out, both rect tests: image compares `cmp byte, x; bhi` (byte loaded
 *   first into r1), compiled `cmp x, byte; blo` with the same loads. Tried: operand order, !(), continue
 *   chains, else-if chains, struct point local, u32 casts, inline helper, separate loop vars.
 * symbols:
 *   ov208_func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   ov208_func_021BDC48 0x021BDC48 thumb ov208
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B8C4 0x0204B8C4 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ov208_func_021BC3B4(int key);
extern u32 func_0204B3F4(void *obj);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern int func_02035D20(u32 *x, u32 *y);
extern void func_020355D8(int v);
extern void ov208_func_021BDC48(void *scene, u32 on);
extern void func_0204B878(void *obj, u16 v);
extern void func_020061E4(u32 v);
extern void func_0204B92C(void *obj, int v);
extern void func_0204B8C4(void *obj, int v);

#define F32(b, o) (*(u32 *)((b) + (o)))

int ov208_func_021C6760(void *unused, u8 *p, int key)
{
    void *sys;
    enum { HIT_NONE = 5 } hit;
    u32 type;
    u32 x;
    u32 y;
    u8 i;
    u8 *b;
    u8 *c;
    u8 j;
    int partner;
    int o;
    u8 *q;
    sys = ov208_func_021BC3B4(key);
    hit = HIT_NONE;
    if (hit == 5) {
        for (i = 0; i < 4; i++) {
            b = p + i * 0x28;
            if (func_0204B3F4((void *)F32(b, 0x618)) != 0) {
                if ((func_020362DC() & F32(b, 0x60c)) != 0) {
                    type = 0;
                    hit = i;
                    break;
                }
                if (i == 2 || i == 3) {
                    if ((func_0203633C() & F32(b, 0x60c)) != 0) {
                        type = 0;
                        hit = i;
                        break;
                    }
                }
            }
        }
    }
    if (hit == 5) {
        if (func_02035D20(&x, &y) != 0) {
            for (j = 0; j < 4; j++) {
                c = p + j * 0x28;
                if (func_0204B3F4((void *)F32(c, 0x618)) != 0) {
                    if ((u32)c[0x604] <= x && x < (u32)c[0x604] + c[0x606]
                        && (u32)c[0x605] <= y && y < (u32)c[0x605] + c[0x607]) {
                        type = 1;
                        hit = j;
                        break;
                    }
                }
            }
        }
    }
    if (hit != 5) {
        if (F32(p, 0x694) != 5) {
            hit = 6;
        } else {
            func_020355D8(type);
            ov208_func_021BDC48(sys, 0);
            o = hit * 0x28;
            *(u32 *)(p + 0x614 + o) = 1;
            func_0204B878((void *)*(u32 *)(p + 0x618 + o), *(u8 *)(p + 0x609 + o));
            func_020061E4(*(u32 *)(p + 0x610 + o));
            partner = 5;
            if (hit == 2)
                partner = 3;
            else if (hit == 3)
                partner = 2;
            if (partner != 5) {
                q = p + 0x618;
                func_0204B92C((void *)F32(q, partner * 0x28), 0);
                func_0204B8C4((void *)F32(q, partner * 0x28), 0);
            }
            F32(p, 0x694) = hit;
        }
    }
    return hit;
}







