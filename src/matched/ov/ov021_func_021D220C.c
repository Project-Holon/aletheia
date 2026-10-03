/*
 * function: func_021D220C
 * address:  0x021D220C
 * packet:   pkt_ov021_021D220C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Shows the milestone message for the counter read from the save block when
 * it equals one of the five table entries at 0x021DD6BC, or message 0x28E1
 * once it passes 500; returns 0 otherwise.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02188C84  0x02188C84  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   data_021DD6BC  0x021DD6BC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Milestone {
    u16 count;
    u16 msg;
};

extern const struct Milestone data_021DD6BC[5];

struct Big;
struct Ctx;
struct Sub02008828Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern u16 func_02188C84(u8 *p);
extern int func_02158768(void *a0, u32 a1, int a2, u16 a3);

int func_021D220C(void *msg, u8 *pos)
{
    u16 n = func_02008990(func_02008854(func_02012EBC(func_020120F4(msg))));
    u32 i;

    for (i = 0; i < 5; i++) {
        if (n == data_021DD6BC[i].count)
            return func_02158768(msg, data_021DD6BC[i].msg, 0, func_02188C84(pos));
    }
    if (n > 500)
        return func_02158768(msg, 0x28E1, 0, func_02188C84(pos));
    return 0;
}
