/*
 * function: func_021C24A4
 * address:  0x021C24A4
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_SetPlayerVolumes  0x02005CBC  thumb
 *   PM_VOICE_SetMasterVolume  0x02006734  thumb
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x1340];
    u8 f1340;
    u8 f1341;
    u8 f1342;
    u8 f1343;
} Work;

typedef unsigned int   u32;
extern void GFL_USE_SetPlayerVolumes(u32 value, u32 mask);
extern void PM_VOICE_SetMasterVolume(int v);

void func_021C24A4(Work *w, int v)
{
    if (w->f1342 != v) {
        w->f1341 = w->f1340;
        w->f1343 = 6;
        w->f1342 = v;
        GFL_USE_SetPlayerVolumes(v, 0x3f);
        PM_VOICE_SetMasterVolume(v);
    }
}
