/*
 * function: BOX2_MAIN_Check09E0
 * address: 0x021E09E0
 * packet: pkt_ov170_021E09E0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   BOX2_MAIN_SwapWithNeighbour 0x021DE428 thumb ov170
 *   BOX2_MAIN_WaitBoxScroll 0x021DDAE8 thumb ov170
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj08234.h"
#include "../include/Obj23878.h"
extern void BOX2_SEQ_SetCursorFrame(char *p, int a);
extern void BOX2_MAIN_SwapWithNeighbour(unsigned char *p, unsigned a, unsigned b);
extern int BOX2_MAIN_WaitBoxScroll(unsigned char *p);
extern void BOX2_MAIN_SetMoverEntry(char *p, void *a);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int BOX2_MAIN_Check09E0(char *p)
{
    char *s;
    s = *(char * *)&((struct Obj00000 *)p)->f2C + 0x58;
    switch (((struct Obj08234 *)s)->fC) {
    case 0:
        BOX2_SEQ_SetCursorFrame(p, 7);
        BOX2_MAIN_SwapWithNeighbour((unsigned char *)p, ((struct Obj00000 *)p)->f16, ((struct Obj23878 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA17E);
        ((struct Obj08234 *)s)->fC = 1;
        break;
    case 1:
        if (BOX2_MAIN_WaitBoxScroll((unsigned char *)p) == 0) {
            BOX2_MAIN_SetMoverEntry(p, ((struct Obj08234 *)s)->f8);
            BOX2_SEQ_SetCursorFrame(p, 6);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((struct Obj08234 *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}
