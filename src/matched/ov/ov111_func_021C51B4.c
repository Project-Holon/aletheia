/*
 * function: VIEWER_MAIN_SetRowState
 * address:  0x021C51B4
 * packet:   pkt_ov111_021C51B4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_TEXT_SetActorAnim  0x021C6FA0  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
} Info;

typedef struct {
    u8 pad0[4];
    void *f4;
    u32 f8;
} Sub24;

typedef struct {
    u8 pad0[0x98];
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Sub24 *f24;
    Info *info;
    u8 pad2C[0x305E - 0x2C];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim anim;
    u8 pad3108[0x32F6 - 0x3108];
    u8 b32F6;
} Work;

extern void VIEWER_TEXT_SetActorAnim(Anim *a, int idx, u8 x, u8 y);

void VIEWER_MAIN_SetRowState(Work *p, int flag, int v)
{
    if (flag == 0) {
        VIEWER_TEXT_SetActorAnim(&p->anim, 2, 10, v);
    } else {
        VIEWER_TEXT_SetActorAnim(&p->anim, 2, 12, v);
    }
}
