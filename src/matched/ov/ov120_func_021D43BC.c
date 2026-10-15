/*
 * function: GTSNEGO_DISP_MoveRowCursor
 * address: 0x021D43BC
 * packet: pkt_ov120_021D43BC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_CycleRowA 0x021D439C thumb ov120
 *   GTSNEGO_DISP_CycleRowB 0x021D435C thumb ov120
 *   GTSNEGO_DISP_CycleRowC 0x021D437C thumb ov120
 *   GTSNEGO_MSG_RedrawRowA 0x021D7E88 thumb ov120
 *   GTSNEGO_MSG_RedrawRowB 0x021D7E9C thumb ov120
 *   GTSNEGO_MSG_RedrawRowC 0x021D7EB0 thumb ov120
 *   GTSNEGO_MSG_SetActorMode 0x021D6B84 thumb ov120
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj01150.h"
typedef unsigned int   u32;
extern void GTSNEGO_DISP_CycleRowA(int n, char *p);
extern void GTSNEGO_DISP_CycleRowB(int n, char *p);
extern void GTSNEGO_DISP_CycleRowC(int n, char *p);
typedef unsigned char  u8;
extern void GTSNEGO_MSG_RedrawRowA(char *p, int i);
extern void GTSNEGO_MSG_RedrawRowB(char *p, int i);
extern void GTSNEGO_MSG_RedrawRowC(char *p, int i);
extern void GTSNEGO_MSG_SetActorMode(u8 *p, u32 n);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int GTSNEGO_DISP_MoveRowCursor(int n, char *p) {
    int result=0;
    switch(n) {
    case 0:GTSNEGO_DISP_CycleRowA(-1,p);result=2;GTSNEGO_MSG_RedrawRowA((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f144);break;
    case 1:GTSNEGO_DISP_CycleRowA(1,p);result=2;GTSNEGO_MSG_RedrawRowA((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f144);break;
    case 2:GTSNEGO_DISP_CycleRowB(-1,p);result=3;GTSNEGO_MSG_RedrawRowB((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f13C);break;
    case 3:GTSNEGO_DISP_CycleRowB(1,p);result=3;GTSNEGO_MSG_RedrawRowB((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f13C);break;
    case 4:GTSNEGO_DISP_CycleRowC(-1,p);result=4;GTSNEGO_MSG_RedrawRowC((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f140);break;
    case 5:GTSNEGO_DISP_CycleRowC(1,p);result=4;GTSNEGO_MSG_RedrawRowC((char *)(((struct Obj01150 *)p)->f40),((struct Obj01150 *)p)->f140);break;
    }
    if(n>=0 && n<=5) {GFL_USE_PlaySeDefaultVolume(0x548);GTSNEGO_MSG_SetActorMode((u8 *)(((struct Obj01150 *)p)->f3C),n);}
    return result;
}
