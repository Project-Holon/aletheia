/*
 * function: FLDEFF_GRASS_Update
 * address:  0x021AC900
 * packet:   pkt_ov021_021AC900
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compiled 212 of a 216-byte extent: the follower at 0x021AC9D4 is an
 * unlabelled `bx lr` stub.
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDEFF_GRASS_IsModelOnTile  0x021AC9D8  thumb  ov021
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 *   sGrassEndsOnLeave     0x021D90C0  data
 *   sGrassCommandCursor     0x021D90C8  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blk { u32 w[9]; } Blk;

typedef struct B {
    u32 f0;
    Blk blk;
    u16 f28[4];
    u16 f30;
} B;

extern int FLDMMDL_CheckCheckInfo(int a0, int a1);
extern int FLDEFF_GRASS_IsModelOnTile(u8 *p);
extern u16 FLDMMDL_GetDirMove(void *p);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out);
extern void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v);
extern u8 sGrassEndsOnLeave[];
extern u16 sGrassCommandCursor[];

void FLDEFF_GRASS_Update(u32 a, B *b)
{
    u32 h = *(u32 *)(b->blk.w[0] + 4);
    u32 m;
    u16 tmp;

    switch (b->f0) {
    case 0:
        if (sGrassEndsOnLeave[b->blk.w[8]] == 1) {
            m = b->blk.w[1];
            if (FLDMMDL_CheckCheckInfo(m, (int)b->f28) == 1 && FLDEFF_GRASS_IsModelOnTile((u8 *)b) == 0 && FLDMMDL_GetDirMove((void *)m) == 1) {
                FIELD_EFFECT_DeleteObject(a);
                return;
            }
        }
        if (BILLBOARD_ACT_GetEntryLastCommand((u8 *)h, b->f30, &tmp) != 0)
            b->f0++;
        break;
    case 1:
        if (FLDMMDL_CheckCheckInfo(b->blk.w[1], (int)b->f28) == 0) {
            FIELD_EFFECT_DeleteObject(a);
            return;
        }
        BILLBOARD_ACT_SetEntryCursor((void *)h, b->f30, sGrassCommandCursor[b->blk.w[8]]);
        b->f0++;
        break;
    case 2:
        b->f0++;
    case 3:
        if (FLDMMDL_CheckCheckInfo(b->blk.w[1], (int)b->f28) == 0) {
            FIELD_EFFECT_DeleteObject(a);
            return;
        }
        if (FLDEFF_GRASS_IsModelOnTile((u8 *)b) == 0)
            FIELD_EFFECT_DeleteObject(a);
        break;
    }
}
