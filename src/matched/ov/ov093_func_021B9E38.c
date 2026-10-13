/*
 * function: BTL_TRAINER_SLOT_InitPlayer
 * address:  0x021B9E38
 * packet:   pkt_ov093_021B9E38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008510  0x02008510  thumb
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 */
#include "../include/Obj01371.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *MYSTATUS_Create(int a);
extern void MYSTATUS_Copy(void *src, void *dst);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02008510(void *a, int tag);
extern void PMSI_PARAM_ClearSentence(void *a);

void BTL_TRAINER_SLOT_InitPlayer(char *p, int a, int b)
{
    u16 f;

    void *h = MYSTATUS_Create(a);

    ((struct Obj01371 *)p)->f0 = h;
    MYSTATUS_Copy((void *)b, h);
    f = 0;
    ((struct Obj01371 *)p)->fA = 0;
    if (func_02008550(((struct Obj01371 *)p)->f0))
        f = 1;
    ((struct Obj01371 *)p)->f8 = f;
    ((struct Obj01371 *)p)->f4 = (int)func_02008510(((struct Obj01371 *)p)->f0, 0x12);
    PMSI_PARAM_ClearSentence(p + 0x18);
    PMSI_PARAM_ClearSentence(p + 0x20);
}
