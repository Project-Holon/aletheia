/*
 * function: EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore
 * address:  0x021BF518
 * packet:   pkt_ov021_021BF518
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes 0x021BF564 thumb ov021
 *   EVENT_FIELDMAP_CONTROL_ResetBgAffine 0x021BF584 thumb ov021
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 */

extern void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(int);
typedef unsigned char  u8;
extern void EVENT_FIELDMAP_CONTROL_ResetBgAffine(u8 *a0);
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);

int EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore(int a, int *s, int *q)
{
    switch (s[0]) {
    case 0:
        FADE_Start(q[3], 16, 0, q[4]);
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(q[1]);
        EVENT_FIELDMAP_CONTROL_ResetBgAffine((u8 *)q[1]);
        s[0] = s[0] + 1;
        break;
    case 1:
        if (q[5] == 1) {
            return 1;
        }
        if (FADE_IsActive() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
