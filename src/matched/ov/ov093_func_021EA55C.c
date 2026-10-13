/*
 * function: func_021EA55C
 * address:  0x021EA55C
 * packet:   pkt_ov093_021EA55C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_FormatWithSide  0x021EEE80  thumb  ov093
 *   BTL_MSG_DispatchTagged  0x021EEEF4  thumb  ov093
 *   BTL_MSG_GetUiString  0x021EF694  thumb  ov093
 *   BTL_MSG_BuildUiString  0x021EF6A8  thumb  ov093
 *   BTL_MSG_BuildTrainerString  0x021EF6E8  thumb  ov093
 *   BTL_MSG_BuildItemUse  0x021EF5E8  thumb  ov093
 *   BTL_MSG_BuildPlainEntry  0x021EF664  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct H {
    u16 h0;
    u8 b2;
    u8 op : 4;
    u8 hi : 4;
    int f4;
    int f8;
};

extern void BTL_MSG_FormatWithSide(u32 a, u16 k, u32 *p);
extern void BTL_MSG_DispatchTagged(u32 a, u16 b, u32 c);
extern void BTL_MSG_GetUiString(u32 a, u32 b);
extern void BTL_MSG_BuildUiString(u32 a, u32 b, u32 c);
extern void BTL_MSG_BuildTrainerString(u32 a, u32 b, u32 c);
extern void BTL_MSG_BuildItemUse(u32 a, u8 b, u16 c);
extern void BTL_MSG_BuildPlainEntry(int a, u16 b, int c);

void func_021EA55C(struct H *p, int a)
{
    switch (p->op) {
    case 1:
        BTL_MSG_FormatWithSide(a, p->h0, (u32 *)(&p->f4));
        break;
    case 2:
        BTL_MSG_DispatchTagged(a, p->h0, (u32)(&p->f4));
        break;
    case 3:
        BTL_MSG_GetUiString(a, p->h0);
        break;
    case 5:
        BTL_MSG_BuildUiString(a, p->h0, (u32)(&p->f4));
        break;
    case 6:
        BTL_MSG_BuildTrainerString(a, p->h0, (u32)(&p->f4));
        break;
    case 4:
        BTL_MSG_BuildItemUse(a, p->f4, p->f8);
        break;
    case 7:
        BTL_MSG_BuildPlainEntry(a, p->f4, p->f8);
        break;
    }
}
