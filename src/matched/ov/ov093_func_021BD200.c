/*
 * function: BTL_SERVER_FLOW_SetupTurnState
 * address:  0x021BD200
 * packet:   pkt_ov093_021BD200
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD264  0x021BD264  thumb  ov093
 *   func_021BD274  0x021BD274  thumb  ov093
 *   func_021BD284  0x021BD284  thumb  ov093
 *   func_021BD294  0x021BD294  thumb  ov093
 *   PLACE_NAME_LETTER_DeleteBmpOam  0x021BD2A4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021BD200 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021BD264(int t);
extern u8 func_021BD274(u8 *p, u8 x);
extern int func_021BD284(int t);
extern u8 *func_021BD294(int t, int k);
extern u8 PLACE_NAME_LETTER_DeleteBmpOam(u8 *p, u8 x);

void BTL_SERVER_FLOW_SetupTurnState(struct Unk021BD200 *p, u8 *q, u8 *a, int t)
{
    int r = func_021BD264(t);
    p->f2 = func_021BD274(q + 0x1ab8, BTL_POKEPARAM_GetPokeId(a));
    p->f3 = 6;
    p->b0 = 0;
    p->b1 = 0;
    if (r == 1 && func_021BD284(t)) {
        p->f3 = PLACE_NAME_LETTER_DeleteBmpOam(q + 0x1ab8, BTL_POKEPARAM_GetPokeId(func_021BD294(t, 0)));
    }
}
