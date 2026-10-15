/*
 * function: WIFIBATTLEMATCH_NET_SetupCompCard
 * address: 0x021D9874
 * packet: pkt_ov175_021D9874
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera 0x021E5548 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreatePartyWindow 0x021E7E3C thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 */
#include "../include/Obj00013.h"
#include "../include/Obj24305.h"
extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *);
extern void *WIFIBATTLEMATCH_VIEW_CreatePartyWindow(void *, int, int, int, int, int, int);
void WIFIBATTLEMATCH_NET_SetupCompCard(char *ctx)
{
    int window;
    if (((struct Obj00013 *)ctx)->f24 == 0) {
        window = WIFIBATTLEMATCH_GRAPHIC_GetCamera(*(int * *)&((struct Obj00013 *)ctx)->f0);
        ((struct Obj00013 *)ctx)->f24 = WIFIBATTLEMATCH_VIEW_CreatePartyWindow(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj24305 *)(*(char * *)&((struct Obj00013 *)ctx)->f104))->f8)), window, *(int *)&((struct Obj00013 *)ctx)->f4, ((struct Obj00013 *)ctx)->fC, *(int *)&((struct Obj00013 *)ctx)->f10, *(int *)&((struct Obj00013 *)ctx)->f14, 87);
    }
}
