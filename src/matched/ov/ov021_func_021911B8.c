/*
 * function: FIELD_MSGBG_SetupTalkWin
 * address:  0x021911B8
 * packet:   pkt_ov021_021911B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb  arm9
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb  ov021
 *   FIELD_MSGBG_LoadMenuGraphicsUpper  0x02193170  thumb  ov021
 *   FIELD_MSGBG_KeyWaitReset  0x02193200  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetCharWait  0x02193210  thumb  ov021
 *   FIELD_MSGBG_InitCursor  0x021927C0  thumb  ov021
 *   TALKMSGWIN_SetupUpperBalloon  0x02194848  thumb  ov021
 *   TALKMSGWIN_SetupLowerBalloon  0x02194888  thumb  ov021
 *   TALKMSGWIN_SetupAutoBalloon  0x021948CC  thumb  ov021
 *   TALKMSGWIN_Open  0x02194940  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 x, y, z; } V3;

typedef struct { u32 f0; u32 f4; } S15C;
typedef struct A { u16 h[4]; u8 pad[0x15C - 8]; S15C s; } A;

typedef struct B {
    u8 f00;
    u8 mode;
    u16 f02;
    u32 f04;
    u32 f08;
    u32 f0c[2];
    A *a;
    V3 *v;
    V3 pos;
} B;

extern void FIELD_MSGBG_LoadMenuGraphicsUpper(u32);
extern void FIELD_MSGBG_SetBlend(u32);
extern u32 FIELD_MSGBG_KeyWaitGetCharWait(u8 *p);
extern int FIELD_MSGBG_KeyWaitReset(u32 a);
struct Fx;
struct G;
extern void TALKMSGWIN_SetupUpperBalloon(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
extern void TALKMSGWIN_SetupLowerBalloon(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
extern void TALKMSGWIN_SetupAutoBalloon(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x);
extern void TALKMSGWIN_Open(u8 *p, int i);
extern void FIELD_MSGBG_InitCursor(struct G *g, struct Fx *a);
extern void func_020061E4(u32);

void FIELD_MSGBG_SetupTalkWin(A *a, B *b, u8 mode, V3 *v, u32 d, u32 e, u32 f)
{
    b->v = v;
    b->pos = *v;
    a->h[3] = 11;
    b->a = a;
    b->f08 = a->s.f0;
    b->mode = mode;
    FIELD_MSGBG_LoadMenuGraphicsUpper(a->h[0]);
    FIELD_MSGBG_SetBlend(0);
    switch (mode) {
    case 0:
        TALKMSGWIN_SetupUpperBalloon((u8 *)b->f08, 0, (u32)v, d, 15, e, f, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)((u32)&a->s.f4)));
        break;
    case 1:
        TALKMSGWIN_SetupLowerBalloon((u8 *)b->f08, 1, (u32)v, d, 15, e, f, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)((u32)&a->s.f4)));
        break;
    default:
        TALKMSGWIN_SetupAutoBalloon((u8 *)b->f08, 2, (u32)v, d, 15, e, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)((u32)&a->s.f4)));
        break;
    }
    FIELD_MSGBG_KeyWaitReset((u32)a + 0x160);
    TALKMSGWIN_Open((u8 *)b->f08, b->mode);
    FIELD_MSGBG_InitCursor((struct G *)b->f0c, (struct Fx *)a->h);
    if (e == 1) {
        b->f02 = 8;
        func_020061E4(0x72C);
    }
}
