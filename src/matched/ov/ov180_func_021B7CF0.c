/*
 * function: HALL_OF_FAME_CreateMonSceneObjects
 * address: 0x021B7CF0
 * packet: pkt_ov180_021B7CF0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HALL_OF_FAME_LoadUiResources 0x021B7C78 thumb ov180
 *   HALL_OF_FAME_LoadUiPalette 0x021B7750 thumb ov180
 *   HALL_OF_FAME_CreateActorFromTemplate 0x021B75A4 thumb ov180
 *   HALL_OF_FAME_SetActorVisible 0x021B746C thumb ov180
 *   HALL_OF_FAME_CreateMonPlates 0x021B7814 thumb ov180
 *   gHallOfFamePlateLeftTemplate 0x021B81BC data a4
 *   gHallOfFamePlateRightTemplate 0x021B81D4 data a4
 *   gHallOfFameVoiceMarkTemplate 0x021B81A4 data a4
 */
#include "../include/Obj00547.h"
typedef struct { unsigned short a, b; unsigned c; int d, e, f; unsigned short g, h; } S24;
extern S24 gHallOfFamePlateLeftTemplate, gHallOfFamePlateRightTemplate, gHallOfFameVoiceMarkTemplate;
extern void HALL_OF_FAME_LoadUiResources(char *);
extern void HALL_OF_FAME_LoadUiPalette(char *);
struct Obj;
extern struct Obj *HALL_OF_FAME_CreateActorFromTemplate(char *p, const char *q);
extern void HALL_OF_FAME_SetActorVisible(int *, int, int);
extern void HALL_OF_FAME_CreateMonPlates(char *);
void HALL_OF_FAME_CreateMonSceneObjects(char *p)
{
    HALL_OF_FAME_LoadUiResources(p);
    HALL_OF_FAME_LoadUiPalette(p);
    ((struct Obj00547 *)p)->f9050 = (int)HALL_OF_FAME_CreateActorFromTemplate(p, (const char *)(&gHallOfFamePlateLeftTemplate));
    ((struct Obj00547 *)p)->f9054 = (int)HALL_OF_FAME_CreateActorFromTemplate(p, (const char *)(&gHallOfFamePlateRightTemplate));
    ((struct Obj00547 *)p)->f9058 = (int)HALL_OF_FAME_CreateActorFromTemplate(p, (const char *)(&gHallOfFameVoiceMarkTemplate));
    HALL_OF_FAME_SetActorVisible((int *)p, 4, 0);
    HALL_OF_FAME_CreateMonPlates(p);
}
