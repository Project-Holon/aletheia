/*
 * function: ENCEFF_BuildModelSceneKind35
 * address: 0x021F52B0
 * packet: pkt_ov076_021F52B0
 * region: ov076
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ENCEFF_StartModelScene 0x021F52D8 thumb ov076
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_GetWork 0x021CF560 thumb ov021
 */
typedef unsigned int u32;
extern void *ENCEFF_StartModelScene(void *, u32, u32, u32, int);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 ENCEFF_GetWork(u32 *);
void *ENCEFF_BuildModelSceneKind35(void *a, u32 b, int c) {
    void *h;
    h = ENCEFF_StartModelScene(a,b,11,10,c);
    *(u32 *)(ENCEFF_GetWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)b)) + 0x40) = 0x7F3;
    return h;
}
