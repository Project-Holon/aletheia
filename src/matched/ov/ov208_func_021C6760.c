/*
 * function: ov208_func_021C6760
 * address: 0x021C6760
 * packet: pkt_ov208_021C6760
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (D4-11): EXACT. The rect offset is a local (`k = 0x604`, then c[k],
 *   c[k + 1], c[k + 2], c[k + 3]); the byte load then evaluates before x, as in the image.
 * symbols:
 *   ov208_func_021BC3B4 0x021BC3B4 thumb ov208
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   ov208_func_021BDC48 0x021BDC48 thumb ov208
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ov208_func_021BC3B4(int key);
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetRepeat(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void func_020355D8(int v);
extern void ov208_func_021BDC48(void *scene, u32 on);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void GFL_USE_PlaySeDefaultVolume(u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

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
    int k;
    sys = ov208_func_021BC3B4(key);
    hit = HIT_NONE;
    if (hit == 5) {
        for (i = 0; i < 4; i++) {
            b = p + i * 0x28;
            if (CLACT_GetActorDrawEnable((void *)F32(b, 0x618)) != 0) {
                if ((KEY_GetTrg() & F32(b, 0x60c)) != 0) {
                    type = 0;
                    hit = i;
                    break;
                }
                if (i == 2 || i == 3) {
                    if ((KEY_GetRepeat() & F32(b, 0x60c)) != 0) {
                        type = 0;
                        hit = i;
                        break;
                    }
                }
            }
        }
    }
    if (hit == 5) {
        if (TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
            k = 0x604;
            for (j = 0; j < 4; j++) {
                c = p + j * 0x28;
                if (CLACT_GetActorDrawEnable((void *)F32(c, 0x618)) != 0) {
                    if ((u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                        && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
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
            CLACT_SetActorAnimSeq((void *)*(u32 *)(p + 0x618 + o), *(u8 *)(p + 0x609 + o));
            GFL_USE_PlaySeDefaultVolume(*(u32 *)(p + 0x610 + o));
            partner = 5;
            if (hit == 2)
                partner = 3;
            else if (hit == 3)
                partner = 2;
            if (partner != 5) {
                q = p + 0x618;
                CLACT_SetActorAutoAnim((void *)F32(q, partner * 0x28), 0);
                CLACT_SetActorAnimFrame((void *)F32(q, partner * 0x28), 0);
            }
            F32(p, 0x694) = hit;
        }
    }
    return hit;
}







