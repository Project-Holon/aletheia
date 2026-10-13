/*
 * function: FIELD_MSGBG_PlainWinPrintStream
 * address:  0x021916A8
 * packet:   pkt_ov021_021916A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_CreateMsgStream  0x02190D2C  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgStream  0x02190D48  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetCharWait  0x02193210  thumb  ov021
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

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

extern int FIELD_MSGBG_DeleteMsgStream(void *a);
extern u32 FIELD_MSGBG_KeyWaitGetCharWait(u8 *p);
extern u32 *FIELD_MSGBG_CreateMsgStream(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f);

void FIELD_MSGBG_PlainWinPrintStream(R *r, u32 b, u16 c, u32 d)
{
    if (r->f1c != 0)
        FIELD_MSGBG_DeleteMsgStream((void *)r->f1c);
    r->f1c = (u32)FIELD_MSGBG_CreateMsgStream((u32 *)r->f0c, d, r->f18, b, c, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)r->f0c + 0x160));
}
