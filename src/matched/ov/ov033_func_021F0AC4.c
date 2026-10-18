/*
 * function: DOWSING_UpdateCloseButton
 * address:  0x021F0AC4
 * packet:   pkt_ov033_021F0AC4
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   FIELD_SUBSCREEN_RequestMode 0x021A0F30 thumb ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
typedef unsigned short u16;
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);

typedef struct {
    unsigned f00;
    unsigned f04;
    char pad[0x1C];
    unsigned f24;
    unsigned f28;
} T;

void DOWSING_UpdateCloseButton(T *p)
{
    unsigned x;
    unsigned y;
    int hit;

    switch (p->f28) {
    case 0:
        hit = 0;
        if (TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
            if (x >= 0xE8 && x < 0x100 && y >= 0xA8 && y < 0xC0) {
                UI_SetInputMode(1);
                hit = 1;
            }
        }
        if (hit == 0) {
            if (KEY_GetTrg() & 0x400) {
                UI_SetInputMode(0);
                hit = 1;
            }
        }
        if (hit != 0) {
            p->f28 = 1;
            CLACT_SetActorAnimSeq((struct Obj *)p->f24, 8);
            GFL_USE_PlaySeDefaultVolume(0x556);
            return;
        }
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct Actor *)p->f24) == 0) {
            p->f28 = 2;
            CLACT_SetActorAnimSeq((struct Obj *)p->f24, 0);
            return;
        }
        break;
    case 2:
        FIELD_SUBSCREEN_RequestMode(p->f04, 0);
        p->f28 = 3;
        break;
    case 3:
        break;
    }
}
