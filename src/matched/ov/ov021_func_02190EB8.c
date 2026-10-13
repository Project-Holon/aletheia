/*
 * function: FIELD_MSGBG_SysWinPrintStr
 * address:  0x02190EB8
 * packet:   pkt_ov021_02190EB8
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

typedef struct P {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    Fx *f14;
} P;

extern int FIELD_MSGBG_DeleteMsgStream(void *a);
extern u32 FIELD_MSGBG_KeyWaitGetCharWait(u8 *p);
extern u32 *FIELD_MSGBG_CreateMsgStream(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f);

void FIELD_MSGBG_SysWinPrintStr(P *p, u32 b, u16 c, u32 d)
{
    if (p->f04 != 0)
        FIELD_MSGBG_DeleteMsgStream((void *)p->f04);
    p->f04 = (u32)FIELD_MSGBG_CreateMsgStream((u32 *)p->f14, d, p->f00, b, c, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)p->f14 + 0x160));
}
