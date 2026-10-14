/*
 * function: BTLV_EFFECT_SequenceTaskMain
 * address:  0x021F8CB0
 * packet:   pkt_ov094_021F8CB0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gBtlvEff 0x0220AF20 data ov094 a4
 *   BTLV_EFFVM_StartScript 0x021F94F8 thumb ov094
 *   BTLV_MCSS_GetSpriteAttrFlags 0x021FFF38 thumb ov094
 *   BTLV_MCSS_StartAlphaTween 0x021FF924 thumb ov094
 *   BTLV_MCSS_StartMosaicTween 0x021FFBBC thumb ov094
 *   BTLV_EFFVM_StartSePlayTask 0x021F9858 thumb ov094
 *   BTLV_EFFVM_StartSeVolumeTask 0x021F9948 thumb ov094
 *   BTLV_MCSS_IsSpriteBusy 0x021FFCB0 thumb ov094
 *   BTLV_MCSS_ReloadSpriteResource 0x022001DC thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char *gBtlvEff;
extern void BTLV_EFFVM_StartScript(void *, int, u32, u16, void *);
extern int BTLV_MCSS_GetSpriteAttrFlags(char *p, int key);
extern void BTLV_MCSS_StartAlphaTween(char *w, int key, int kind, int value, int a, int b, int c);
extern void BTLV_MCSS_StartMosaicTween(char *w, int key, int kind, int value, int a, int b, int c);
extern void BTLV_EFFVM_StartSePlayTask(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);
extern void BTLV_EFFVM_StartSeVolumeTask(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);
extern int BTLV_MCSS_IsSpriteBusy(void *, int);
extern void BTLV_MCSS_ReloadSpriteResource(void *, int, int *);
extern void BTLV_EFFECT_DeleteTask(void *);
#define FIELD(k) (*(void **)(gBtlvEff + (k)))
#define READY (*(int *)(gBtlvEff + 0x1e8))

void BTLV_EFFECT_SequenceTaskMain(void *h, int *p)
{
    switch (p[1]) {
    case 0:
        BTLV_EFFVM_StartScript(FIELD(0x188), p[0], 0xff, 0x253, 0);
        READY = 1;
        p[1]++;
        break;
    case 1:
        if (READY == 0) {
            if (BTLV_MCSS_GetSpriteAttrFlags(FIELD(0x190), p[0]) & 1) {
                BTLV_EFFVM_StartScript(FIELD(0x188), p[0], 0xff, 0x264, 0);
                READY = 1;
            }
            p[1]++;
        }
        break;
    case 2:
        if (READY == 0) {
            BTLV_MCSS_StartAlphaTween(FIELD(0x190), p[0], 0, 16, 0, 0, 0);
            BTLV_MCSS_StartMosaicTween(FIELD(0x190), p[0], 1, 8, 8, 1, 0);
            BTLV_EFFVM_StartSePlayTask(FIELD(0x188), 0x5aa, 1, 14, -500, 127, 0, 0, 0);
            BTLV_EFFVM_StartSeVolumeTask(FIELD(0x188), 1, 0, 1, 127, 0, 30, 10, 0, 0);
            p[1]++;
        }
        break;
    case 3:
        if (BTLV_MCSS_IsSpriteBusy(FIELD(0x190), p[0]) == 0) {
            BTLV_MCSS_ReloadSpriteResource(FIELD(0x190), p[0], &p[2]);
            p[1]++;
        }
        break;
    case 4:
        BTLV_MCSS_StartMosaicTween(FIELD(0x190), p[0], 1, 0, 8, 1, 0);
        p[1]++;
        break;
    case 5:
        if (BTLV_MCSS_IsSpriteBusy(FIELD(0x190), p[0]) == 0) {
            BTLV_EFFVM_StartSePlayTask(FIELD(0x188), 0x560, 1, 14, 0, 0, 0, 0, 0);
            BTLV_MCSS_StartAlphaTween(FIELD(0x190), p[0], 0, 31, 0, 0, 0);
            if (BTLV_MCSS_GetSpriteAttrFlags(FIELD(0x190), p[0]) & 1) {
                BTLV_EFFVM_StartScript(FIELD(0x188), p[0], 0xff, 0x265, 0);
                READY = 1;
            }
            p[1]++;
        }
        break;
    case 6:
        if (READY == 0) {
            BTLV_EFFVM_StartScript(FIELD(0x188), p[0], 0xff, 0x254, 0);
            READY = 1;
            p[1]++;
        }
        break;
    case 7:
        if (READY == 0)
            BTLV_EFFECT_DeleteTask(h);
        break;
    }
}
