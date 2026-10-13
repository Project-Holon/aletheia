/*
 * function: INTRUDE_SUBDISP_UpdateInfoIcon
 * address:  0x0217E524
 * packet:   pkt_ov018_0217E524
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   INTRUDE_SUBDISP_IsInfoActive  0x0217F1E8  thumb  ov018
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   INTRUDE_SUBDISP_ClearInfoPanel  0x0217F214  thumb  ov018
 *   INTRUDE_SUBDISP_DrawInfoPanel  0x0217F240  thumb  ov018
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 */

typedef unsigned char u8;
typedef short s16;

typedef struct {
    u8 pad00[0x14];
    u8 *f14;
} Gfx;

typedef struct {
    int f00;
    u8 pad04[0xAC - 0x04];
    int fAC;
    u8 padB0[0xCC - 0xB0];
    Gfx *fCC;
    u8 *fD0;
    u8 padD4[0xDC - 0xD4];
    int fDC;
    int fE0;
    u8 padE4[0x10A - 0xE4];
    s16 f10A;
    u8 pad10C[0x10F - 0x10C];
    u8 f10F;
} Obj;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int INTRUDE_SUBDISP_IsInfoActive(u8 *p);
struct Obj;
extern unsigned int func_0204B3F4(struct Obj *p);
struct Obj;
extern void func_0204B3DC(struct Obj *a0, unsigned int a1);
extern void INTRUDE_SUBDISP_ClearInfoPanel(void);
extern void INTRUDE_SUBDISP_DrawInfoPanel(u8 *p, int mode);
extern void *GAME_DATA_GetLastBattleRecSlot(void *p);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);

void INTRUDE_SUBDISP_UpdateInfoIcon(Obj *p)
{
    int h;
    int v;
    int i;
    int rem;
    u8 *base;

    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)p->f00);
    if (INTRUDE_SUBDISP_IsInfoActive((u8 *)p) == 0) {
        if (func_0204B3F4((struct Obj *)p->fAC) == 1) {
            func_0204B3DC((struct Obj *)p->fAC, 0);
            INTRUDE_SUBDISP_ClearInfoPanel();
        }
        return;
    }
    if (func_0204B3F4((struct Obj *)p->fAC) == 0) {
        func_0204B3DC((struct Obj *)p->fAC, 1);
        INTRUDE_SUBDISP_DrawInfoPanel((u8 *)p, 1);
    }
    GAME_DATA_GetLastBattleRecSlot((void *)h);
    v = p->fE0;
    if (p->f10A != -1 && p->f10A != v && v <= 5 && p->fDC == 3) {
        func_020061E4(0x550);
    }
    if (p->f10A == v) {
        return;
    }
    base = p->fCC->f14;
    p->f10A = v;
    for (i = 0; i < 3; i++) {
        rem = v % 10;
        v = v / 10;
        MIi_CpuCopy32(base + rem * 0x40, p->fD0 + (2 - i) * 0x40, 0x40);
        MIi_CpuCopy32(base + (rem * 0x40 + 0x280), p->fD0 + ((2 - i) * 0x40 + 0x100), 0x40);
    }
    p->f10F = 1;
}
