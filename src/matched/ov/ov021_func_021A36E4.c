/*
 * function: FIELD_PLAYER_CORE_Create
 * address:  0x021A36E4
 * packet:   pkt_ov021_021A36E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   GAME_DATA_GetPlayerPalaceZoneId  0x02012B34  thumb
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb  ov021
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   FLDMMDL_SetGridNowX  0x0216D844  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetGridNowZ  0x0216D874  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FIELD_PLAYER_CORE_ApplyFormCodeModel  0x021A3998  thumb  ov021
 *   FLDMMDL_SetStatusBitZoneDeleteOff  0x0216DB80  thumb  ov010
 *   gFieldPlayerCoreFileName     0x021DDEB8  data  a1
 *   gFieldPlayerAvatarHeaderTemplate     0x021D89A0  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A36E4;

typedef struct {
    s16 x;
    s16 z;
    int y;
} Pos021A36E4;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x18];
    Pos021A36E4 pos;
} Tmpl021A36E4;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u8 pad10[8];
    u32 f18;
    void *f1c;
    u16 f20;
    u16 f22;
} Obj021A36E4;

extern const char gFieldPlayerCoreFileName[];
extern Tmpl021A36E4 gFieldPlayerAvatarHeaderTemplate;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Rec44;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void *FLDMMDL_SysSearchObjId(void *a, u32 b);
extern u16 GAME_DATA_GetPlayerPalaceZoneId(const struct Rec44 *p);
extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
extern void *FLDMMDL_AddMmdl(void *a, Tmpl021A36E4 *b, int c);
extern void FLDMMDL_SetGridNowX(void *h, s16 v);
extern void FLDMMDL_SetGridNowY(void *p, int v);
extern void FLDMMDL_SetGridNowZ(int a0, int a1);
extern void FLDMMDL_SetPos(void *h, const Vec021A36E4 *v);
extern int FIELD_PLAYER_CORE_ApplyFormCodeModel(u8 *a);
extern void FLDMMDL_SetStatusBitZoneDeleteOff(unsigned int *p, unsigned int v);

Obj021A36E4 *FIELD_PLAYER_CORE_Create(u32 a, u32 b, const Vec021A36E4 *pos, u32 d, u16 heap)
{
    Obj021A36E4 *o;
    void *m;
    int k;
    void *h;

    o = func_02030734(heap, 0x34, 1, gFieldPlayerCoreFileName, 0x97);
    o->fc = a;
    o->f8 = b;
    o->f4 = (u32)FIELDMAP_GetGameSystem((void *)b);
    o->f20 = 9;
    o->f22 = 9;
    m = FIELDMAP_GetMmdlSys((void *)b);
    o->f1c = FLDMMDL_SysSearchObjId(m, 0xff);
    o->f18 = d;
    k = GAME_DATA_GetPlayerPalaceZoneId((const struct Rec44 *)o->fc);
    h = o->f1c;
    if (h == 0) {
        Tmpl021A36E4 t = gFieldPlayerAvatarHeaderTemplate;
        Pos021A36E4 *ps = &t.pos;
        ps->x = (pos->x >> 4) / 4096;
        ps->z = (pos->z >> 4) / 4096;
        ps->y = pos->y;
        if (k == 0xFFFF)
            t.f2 = FIELD_PLAYER_GetObjCodeOfFormCode(d, FIELD_PLAYER_CORE_GetFormCode((u8 *)o));
        else
            t.f2 = k;
        o->f1c = FLDMMDL_AddMmdl(m, &t, 0);
    } else {
        int y;
        int z;
        y = (pos->y >> 4) / 4096;
        z = (pos->z >> 4) / 4096;
        FLDMMDL_SetGridNowX(h, (pos->x >> 4) / 4096);
        FLDMMDL_SetGridNowY(h, (s16)y);
        FLDMMDL_SetGridNowZ((int)h, (s16)z);
        FLDMMDL_SetPos(h, pos);
        if (k == 0xFFFF)
            FIELD_PLAYER_CORE_ApplyFormCodeModel((u8 *)o);
    }
    FLDMMDL_SetStatusBitZoneDeleteOff(o->f1c, 1);
    return o;
}
