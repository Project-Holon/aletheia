/*
 * function: INTRUDE_SUBDISP_CreateButtonActors
 * address:  0x0217DD48
 * packet:   pkt_ov018_0217DD48
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   d_021836AA     0x021836AA  data   a2
 *   d_021836F4     0x021836F4  data   a4
 */

typedef unsigned char u8;

typedef struct {
    void *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
} Tmpl;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    int f0c;
    void *f10;
    u8 pad14[0x1c - 0x14];
    void *f1c;
    u8 pad20[0x28 - 0x20];
    void *f28;
    void *f2c;
    u8 pad30[0x54 - 0x30];
    void *f54;
    u8 pad58[0x9c - 0x58];
    void *f9c;
    u8 padA0[0xb0 - 0xa0];
    void *fb0;
    void *fb4[3];
    void *fc0[2];
    u8 padC8[0x168 - 0xc8];
    u8 f168;
} Work;

typedef unsigned int   u32;
struct BigObj;
struct Bmp;
struct Ctx;
struct MsgBank;
struct Obj;
struct U16Vec;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
typedef unsigned short u16;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Grid;
struct Param;
struct Sys;
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern const unsigned short d_021836AA[];
extern const Tmpl d_021836F4;

void INTRUDE_SUBDISP_CreateButtonActors(Work *p)
{
    void *sys;
    int i;
    void *str;
    Tmpl a;
    Tmpl t;

    sys = GAMESYSTEM_GetGameData(p->f00);
    p->f9c = CLACT_CreateActor(p->f54, (unsigned int)p->f04, (unsigned int)p->f08, (unsigned int)p->f10, d_021836AA, 0, 0x70);
    func_0204B3DC(p->f9c, 0);
    t = d_021836F4;
    for (i = 0; i < 2; i++) {
        a = t;
        p->fb4[i] = BMP_Create(6, 2, 0x20, 0x70);
        a.f00 = p->fb4[i];
        a.f08 = p->f0c;
        p->fc0[i] = BMP_OAM_Create(p->fb0, (const struct Param *)(&a));
        BMP_OAM_SetEnabled(p->fc0[i], 0);
        str = func_02045EC0(p->f2c, i + 0x45);
        PRINTSYS_PrintQueColor(p->f28, (u32)p->fb4[i], 0, 0, (u32)str, (u32)p->f1c, 0x3c40);
        STRBUF_Delete(str);
    }
    if (p->f168 == 0 && GAME_DATA_GetIntrudeCount(sys) == 0) {
        func_0204B3DC(p->f9c, 1);
        BMP_OAM_SetEnabled(p->fc0[1], 1);
    }
}
