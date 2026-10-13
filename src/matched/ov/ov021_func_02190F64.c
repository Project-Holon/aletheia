/*
 * function: FIELD_MSGBG_CreateBottomSysWin
 * address:  0x02190F64
 * packet:   pkt_ov021_02190F64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_CreateSysWin  0x02190DCC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

struct Obj2;
extern struct Obj2 *FIELD_MSGBG_CreateSysWin(struct Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f);

struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(Fx *a, u32 b)
{
    return FIELD_MSGBG_CreateSysWin(a, b, 1, 0x13, 0x1E, 4);
}
