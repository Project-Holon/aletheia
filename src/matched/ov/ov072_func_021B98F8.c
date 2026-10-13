/*
 * function: TOWNMAP_Update
 * address: 0x021B98F8
 * packet: pkt_ov072_021B98F8
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   TOWNMAP_ProcRun 0x021B9944 thumb ov072
 *   TOWNMAP_GRH_DrawSprites 0x021BB758 thumb ov072
 *   TOWNMAP_ProcIsFinished 0x021B9958 thumb ov072
 */
#include "../include/Obj20772.h"
extern void TOWNMAP_ProcRun(void *);
extern void TOWNMAP_GRH_DrawSprites(char *);
extern int TOWNMAP_ProcIsFinished(int *);
int TOWNMAP_Update(int a, int b, int c, char *p) {
    TOWNMAP_ProcRun(p + 4);
    TOWNMAP_GRH_DrawSprites(*(char * *)&((struct Obj20772 *)p)->f0);
    return TOWNMAP_ProcIsFinished((int *)(p + 4)) != 0;
}
