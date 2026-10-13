/*
 * function: FLDEFF_GRASS_Init
 * address:  0x021AC810
 * packet:   pkt_ov021_021AC810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FIELD_EFFECT_GetObjectMode  0x021AC1A0  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   sGrassAnimeCommands     0x021DE050  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19872.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V3 { int x, y, z; } V3;
typedef struct Blk { u32 w[9]; } Blk;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct B {
    u32 f0;
    Blk blk;
    u16 f28[4];
    u16 f30;
} B;

struct BbActDesc;
struct BbActSys;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern int FLDMMDL_GetCheckInfo(int a0, int a1);
extern void FIELD_EFFECT_SetObjectPos(u32 a, u8 *b);
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern void BILLBOARD_ACT_SetEntryCommands(void *p, int idx, u32 v, u16 h);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v);
extern int FIELD_EFFECT_GetObjectMode(u32 a);
extern void FIELD_EFFECT_UpdateObject(u32 a);
extern u32 sGrassAnimeCommands[];

void FLDEFF_GRASS_Init(u32 a, B *b)
{
    u8 *p = (u8 *)FIELD_EFFECT_GetObjectParam(a);
    Desc s;
    u16 idx;
    u32 h;
    u16 r;

    b->blk = *(Blk *)p;
    FLDMMDL_GetCheckInfo(((struct Obj19872 *)p)->f4, (int)b->f28);
    FIELD_EFFECT_SetObjectPos(a, p + 0x14);
    idx = b->blk.w[8];
    s.slot = *(u16 *)(b->blk.w[0] + idx * 2 + 8);
    s.v12 = 0x2000;
    s.v14 = 0x2000;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.pos = *(V3 *)(p + 0x14);
    s.f1c = 0;
    s.f20 = (u32)b;
    h = *(u32 *)(b->blk.w[0] + 4);
    b->f30 = BILLBOARD_ACT_CreateEntries((struct BbActSys *)h, 0, (const struct BbActDesc *)(&s), 1, 0);
    if (b->f30 == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    BILLBOARD_ACT_SetEntryCommands((void *)h, b->f30, sGrassAnimeCommands[idx], 1);
    r = b->f30;
    BILLBOARD_ACT_SetEntryList((void *)h, r, 0);
    BILLBOARD_ACT_SetEntryEnabled((void *)h, r, 1);
    if (FIELD_EFFECT_GetObjectMode(a) == 0)
        b->f0 = 1;
    FIELD_EFFECT_UpdateObject(a);
}
