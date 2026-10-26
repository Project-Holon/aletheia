#ifndef GAME_TWL_NWM_STARTSCAN_H
#define GAME_TWL_NWM_STARTSCAN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_startscan.c, prototypes copied from their definitions. */

struct ApInfo;
typedef struct ApInfo ApInfo;

#include "../types.h"
#include "../twl/nwm_callback_types.h"

u32 NWM_StartScanEx(NWMCallbackFunc callback, const ApInfo *param);
u8 *NWM_GetInfoElements(u8 *bssDesc, u8 elementId);
u8 *NWM_GetVenderInfoElements(u8 *bssDesc, u32 elementId, void *oui);
/* END mkheaders: generated region */

#endif
