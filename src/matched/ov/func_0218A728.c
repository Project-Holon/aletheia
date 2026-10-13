/*
 * function: FIELD_EVENT_CHECK_AddStepRecord
 * address:  0x0218A728
 * packet:   pkt_0218A728
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Sub02008C20Obj;
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *GAME_DATA_GetTrainerRecord(int *p);

int FIELD_EVENT_CHECK_AddStepRecord(void *a)
{
return func_02008DF0((struct Sub02008C20Obj *)GAME_DATA_GetTrainerRecord((int *)a), 0);
}

