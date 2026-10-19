/*
 * function: INTRUDE_SUBDISP_UpdateTownActors
 * address:  0x0217DE68
 * packet:   pkt_ov018_0217DE68
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   INTRUDE_SUBDISP_IsAlone  0x0217F284  thumb  ov018
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   PALANM_BlendColors  0x02021F64  thumb
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    void *f00;
    u8 pad04[0x5c - 0x04];
    void *f5c[8];
    void *f7c;
    u8 pad80[0xd8 - 0x80];
    u8 fd8;
    u8 padD9[0x113 - 0xd9];
    u8 f113;
    u8 f114;
    u8 f115;
    u8 pad116[2];
    s16 f118;
    s8 f11a;
    u8 f11b;
    u8 f11c;
    u8 pad11D[3];
    u16 f120[4];
    u16 f128[4];
    u16 f130[4];
} Work;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int INTRUDE_SUBDISP_IsAlone(u8 *p);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void MIi_CpuCopy16(const void *, void *, int);
extern void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);

void INTRUDE_SUBDISP_UpdateTownActors(Work *p)
{
    void *sys;
    int i;
    int c;
    int q;
    void *act;

    sys = GAMESYSTEM_GetGameData(p->f00);
    if (INTRUDE_SUBDISP_IsAlone((u8 *)p) == 1) {
        for (i = 0; i <= 7; i++) {
            CLACT_SetActorDrawEnable(p->f5c[i], 0);
        }
        CLACT_SetActorDrawEnable(p->f7c, 0);
    } else if (p->fd8 == GAME_DATA_GetOwnNetId(sys) || GAME_DATA_GetIntrudeCount(sys) == 0) {
        for (i = 0; i <= 7; i++) {
            CLACT_SetActorDrawEnable(p->f5c[i], 0);
        }
        CLACT_SetActorDrawEnable(p->f7c, 0);
    } else {
        for (i = 0; i <= 7; i++) {
            CLACT_SetActorDrawEnable(p->f5c[i], 1);
        }
        CLACT_SetActorDrawEnable(p->f7c, 1);
    }
    for (i = 6; i <= 8; i++) {
        MIi_CpuCopy16((void *)(0x05000602 + (p->fd8 + 1) * 32), (void *)(0x0500060C + i * 32), 2);
    }
    if (p->f114 == 1) {
        if (p->f115 % 2 == 0) {
            if (((unsigned)p->f115 >> 1) & 1) {
                c = 6;
            } else {
                c = 7;
            }
            q = p->f113;
            if (q != 8) {
                act = p->f5c[q];
            } else {
                act = p->f7c;
            }
            CLACT_SetActorPaletteOffset(act, (u8)c, (int)1);
        }
        if (p->f115 < 10) {
            p->f115++;
        }
        return;
    }
    if (p->f11b == 0xff) {
        return;
    }
    if (p->f11a == 0) {
        p->f118 += 0x100;
        if (p->f118 >= 0x1100) {
            p->f118 = 0x2000 - p->f118;
            p->f11a = 1;
        }
    } else {
        p->f118 -= 0x100;
        if (p->f118 < 0) {
            p->f118 = 0x100 - p->f118;
            p->f11a = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        PALANM_BlendColors(&p->f120[i], &p->f130[i], 1, p->f118 >> 8, p->f128[i]);
    }
    p->f11c = 1;
}
