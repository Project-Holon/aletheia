/*
 * function: EVENT_TRAINER_EYE_Create
 * address:  0x021AE454
 * packet:   pkt_ov021_021AE454
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   sEventTrainerEyeFileName     0x021DE138  data  a4
 */
#include "../include/Obj07517.h"

extern int sEventTrainerEyeFileName;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);

typedef struct { int w[6]; } S24;

void *EVENT_TRAINER_EYE_Create(int a, int b, S24 *src, int c)
{
    char *p = (char *)func_02030734(a, 0x38, 1, (const char *)&sEventTrainerEyeFileName, 0x1fa);

    *(S24 *)(p + 8) = *src;
    ((struct Obj07517 *)p)->f20 = 0;
    ((struct Obj07517 *)p)->f24 = c;
    ((struct Obj07517 *)p)->f30 = b;
    ((struct Obj07517 *)p)->f34 = FIELDMAP_GetFieldPlayer((void *)b);
    return p;
}
