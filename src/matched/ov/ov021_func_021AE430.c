/*
 * function: EVENT_TRAINER_EYE_CreatePairEvent
 * address:  0x021AE430
 * packet:   pkt_ov021_021AE430
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_TRAINER_EYE_UpdatePairEvent  0x021AE754  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int EVENT_TRAINER_EYE_UpdatePairEvent(u32 a, u32 b, u32 *c);

u32 EVENT_TRAINER_EYE_CreatePairEvent(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, EVENT_TRAINER_EYE_UpdatePairEvent, 8);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}
