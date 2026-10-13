/*
 * function: FIELDMAP_VBlankTask
 * address:  0x02189108
 * packet:   pkt_ov021_02189108
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005C8C  0x02005C8C  thumb
 *   FLDMMDL_UpdateSysBlAct  0x0216CD78  thumb  ov010
 *   FIELD_G3DOBJ_Update  0x021C6470  thumb  ov021
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   FLD_VREQ_VBlank  0x021D31AC  thumb  ov021
 */
#include "../include/Obj04980.h"

int func_02005C8C(void);
int FLDMMDL_UpdateSysBlAct(int a0);
void FIELD_G3DOBJ_Update(int h);
void CLACT_VBlankSystem(void);
void FLD_VREQ_VBlank(int h);

void FIELDMAP_VBlankTask(int unused, unsigned char *p)
{
    if (func_02005C8C() == 0) {
        if (((struct Obj04980 *)p)->f38 != 0)
            FLDMMDL_UpdateSysBlAct(((struct Obj04980 *)p)->f38);
        if (((struct Obj04980 *)p)->f130 != 0)
            FIELD_G3DOBJ_Update(((struct Obj04980 *)p)->f130);
    }
    CLACT_VBlankSystem();
    if (((struct Obj04980 *)p)->f14C != 0)
        FLD_VREQ_VBlank(((struct Obj04980 *)p)->f14C);
}
