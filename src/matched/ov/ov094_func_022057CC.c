/*
 * function: func_022057CC
 * address: 0x022057CC
 * packet: pkt_ov094_022057CC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0220A50C 0x0220A50C data a4
 *   d_0220A392 0x0220A392 data a2
 *   d_0220AEB0 0x0220AEB0 data a1
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0220684C 0x0220684C thumb ov094
 *   func_02204BCC 0x02204BCC thumb ov094
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct Pair { void *obj; u32 pad; } Pair;
typedef struct Main {
    unsigned char pad00[0x50];
    int mode;
    unsigned char pad54[0x64 - 0x54];
    void *pal;
    unsigned char pad68[0x1b0 - 0x68];
    u32 h1b0[3];
    u32 h1bc;
    u32 h1c0;
    u32 h1c4;
    Pair h1c8[3];
    unsigned char pad1e0[0x240 - 0x1e0];
    u16 heap;
} Main;
typedef struct Info {
    unsigned char pad00[0x98];
    u32 species[3];
    u32 form[3];
    u32 gender[3];
    int sel;
} Info;
extern const Point d_0220A50C[][3];
extern const u16 d_0220A392[];
extern const char d_0220AEB0[];
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
struct PalAnmSlot;
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern int func_0201BC3C(void);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_020056A0(void *cb, void *ctx, int a);
extern void func_0220684C(char *p, int a, int b);
extern void func_02204BCC(void *a0, int *c);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void ARC_TOOL_DeleteHandle(void *);
void func_022057CC(Main *m, Info *q)
{
    int n;
    void *arc;
    int i;
    int k;
    void **r;
    const Point *pt;
    s16 x, y;

    n = (m->mode == 3) ? 2 : m->mode + 1;
    k = 0;
    if (m->mode == 0 || m->mode == 3)
        return;
    arc = func_020490F4(7, (u16)((m->heap & 0x7fff) | 0x8000));
    m->h1c0 = CLACT_RegisterCellAnim(arc, func_0201BC78(), func_0201BCEC(), m->heap);
    m->h1bc = CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 1, 0x160, m->heap);
    PALANM_CopyHwPaletteToSlot(m->pal, 3, (u16)(CLACT_GetPaletteVramAddress(m->h1bc, 1) >> 1), 0x60);
    *(volatile u16 *)0x04001040 = 0x100;
    *(volatile u16 *)0x04001044 = 0;
    *(volatile u16 *)0x04001042 = 0x100;
    *(volatile u16 *)0x04001046 = 0;
    if (n > 1) {
        r = func_02030734((u16)((m->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x1145);
        r[0] = m;
        r[1] = (void *)n;
        func_0220684C((char *)m, (int)func_020056A0((void *)func_02204BCC, r, 0), 0);
    }
    for (i = 0; i < n; i++) {
        if (q->species[i] != 0) {
            m->h1b0[i] = CLACT_RegisterCharacter(arc, POKE_TOOL_CalcGraphicIndex(q->species[i], q->form[i], q->gender[i], 0), 0, 1, m->heap);
            m->h1c8[i].obj = CLACT_CreateActor((void *)m->h1c4, m->h1b0[i], m->h1bc, m->h1c0, d_0220A392, 1, m->heap);
            func_0204B404(m->h1c8[i].obj, (const struct Vec2 *)(&d_0220A50C[m->mode][i]), 1);
            func_0204B92C(m->h1c8[i].obj, 1);
            if (q->sel == i) {
                CLACT_SetActorAnimSeq(m->h1c8[i].obj, 1);
            } else if (k == 0) {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001040 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001044 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
                k++;
            } else {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001042 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001046 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
            }
            func_0204B6F4(m->h1c8[i].obj, func_0201BB5C(q->species[i], q->form[i], q->gender[i], 0), 0);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}
