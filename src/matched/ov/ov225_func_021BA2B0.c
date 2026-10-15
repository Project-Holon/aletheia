/*
 * function: MANUAL_COMMON_DrawTouchbarStart
 * address: 0x021BA2B0
 * packet: pkt_ov225_021BA2B0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MANUAL_COMMON_UpdateTouchbarSlots 0x021BA240 thumb ov225
 */
#include "../include/Obj04652.h"
#include "../include/Obj26154.h"
#include "../include/Obj26155.h"
#include "../include/Obj26156.h"
#include "../include/Obj26157.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct PrintSys;struct Descriptor;struct CharBuf;struct MsgBank;struct U16Vec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern void PRINTSYS_PrintQueColor(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void STRBUF_Delete(struct U16Vec *);
extern void MANUAL_COMMON_UpdateTouchbarSlots(char *);
void MANUAL_COMMON_DrawTouchbarStart(char *p)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26154 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj26155 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f1C,2);
    PRINTSYS_PrintQueColor(((struct Obj26156 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18,(unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0,4,(unsigned)s,((struct Obj26157 *)(*(char * *)&((struct Obj04652 *)p)->f0))->fC,0x3c40);
    STRBUF_Delete(s);((struct Obj04652 *)p)->f1C=1;MANUAL_COMMON_UpdateTouchbarSlots(p);
}
