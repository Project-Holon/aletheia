/*
 * function: GTSNEGO_DISP_DrawSystem
 * address: 0x021D5F98
 * packet: pkt_ov120_021D5F98
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BLINK_PALANM_Update 0x0202EA40 thumb
 *   GTSNEGO_MSG_StepIdleFade 0x021D75F4 thumb ov120
 */
#include "../include/Obj04488.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_DrawSystem(void);
struct Row;
typedef signed int     s32;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void GTSNEGO_MSG_StepIdleFade(char *p);
void GTSNEGO_DISP_DrawSystem(u8 *p){CLACT_DrawSystem();if(((struct Obj04488 *)p)->fF8)BLINK_PALANM_Update(((struct Obj04488 *)p)->fF8);if(((struct Obj04488 *)p)->fFC)BLINK_PALANM_Update(((struct Obj04488 *)p)->fFC);GTSNEGO_MSG_StepIdleFade((char *)p);}
