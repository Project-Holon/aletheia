/*
 * function: PMSI_PARAM_SetResult
 * address:  0x020241E0
 * packet:   pkt_020241E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PMSI_PARAM_IsSameInput  0x0202419C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct T {
    u8  pad00[1];
    u8  f01;
    u8  f02;
    u8  pad03[0xd];
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1a;
};

struct Obj;
extern u32 PMSI_PARAM_IsSameInput(struct Obj *p, u16 *q, u32 a);

void PMSI_PARAM_SetResult(struct T *p, u16 *a1, u16 *a2)
{
    int i;

    p->f02 = (PMSI_PARAM_IsSameInput((struct Obj *)p, a1, (u32)a2) == 0);
    p->f01 = 0;
    for (i = 0; i < 2; i++) {
        *(u16 *)((char *)p + i * 2 + 0x18) = a1[i];
    }
    p->f10 = a2[0];
    p->f12 = a2[1];
    p->f14 = a2[2];
    p->f16 = a2[3];
}
