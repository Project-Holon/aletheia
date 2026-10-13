/*
 * function: EVENT_FIELDMAP_CONTROL_RunWipeInEffect8
 * address:  0x021BF4A4
 * packet:   pkt_ov021_021BF4A4
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
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */

extern void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(void);
extern void EVENT_FIELDMAP_CONTROL_ResetBgAffine(unsigned char *a0);
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);

int EVENT_FIELDMAP_CONTROL_RunWipeInEffect8(int a, int *s, int *q)
{
    int k = s[0];
    int v = q[1];

    switch (k) {
    case 0:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
        EVENT_FIELDMAP_CONTROL_ResetBgAffine((unsigned char *)q[1]);
        FADE_Start(q[3], 16, 0, -1);
        s[0] = s[0] + 1;
        break;
    case 1:
        WIPE_SYS_Start((void *)3, 11, 11, 0, 6, 1, FIELDMAP_GetHeapId((u8 *)v));
        s[0] = s[0] + 1;
        break;
    case 2:
        if (WIPE_SYS_EndCheck() != 0) {
            s[0] = s[0] + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
