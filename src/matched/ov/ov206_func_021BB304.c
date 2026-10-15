/*
 * function: func_021BB304
 * address: 0x021BB304
 * packet: pkt_ov206_021BB304
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} Rect;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Actor;
struct Node;
struct Obj;
extern u32 APP_ICON_GetTouchBarFileId(void);
extern u8 APP_ICON_GetTypePaletteOffset(int i);
extern u32 APP_ICON_GetTypeCellFileId(u32 a);
extern u32 APP_ICON_GetTypePaletteFileId(u32 a);
extern u32 APP_ICON_GetTypeAnimFileId(u32 a);
typedef signed int     s32;
typedef unsigned short u16;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

typedef struct {
    unsigned short f0;
    char pad02[0x18 - 2];
    int f18;
    int f1c;
    char pad20[4];
    void *f24;
    char pad28[0xb8 - 0x28];
    int m[2][2];
    void *fc8;
    void *fcc;
    char padd0[0xe0 - 0xd0];
    int fe0;
    int fe4;
    void *a[0x11];
    void *b[0x11];
    unsigned char f170;
    unsigned char f171;
    char pad172[0x1d0 - 0x172];
    void *f1d0;
} Ent;

void func_021BB304(Ent *p)
{
    unsigned char a, b, i;
    int flag;
    int sh;
    void *u;
    void *arc;
    Rect r;

    u = (void *)p->f1c;
    flag = (int)u == 0 ? B_FALSE : B_TRUE;
    sh = 0;
    if (u != 0) sh = 1;
    arc = p->f1d0;
    for (a = 0; a < 2; a++) {
        for (b = 0; b < 2; b++) {
            p->m[a][b] = -1;
        }
    }
    p->fe0 = 0;
    p->fc8 = (void *)CLACT_RegisterPaletteEx(arc, APP_ICON_GetTouchBarFileId(), flag, 0x40, 0, 3, p->f0);
    p->fcc = (void *)CLACT_RegisterCellAnim(arc, APP_ICON_GetTypePaletteFileId(2), APP_ICON_GetTypeAnimFileId(2), p->f0);
    if (p->f18 == 2 && p->f1c == 0) {
        r.a = 0; r.b = 0; r.c = 0; r.d = 0; r.e = 0;
        p->fe4 = 1;
        p->f170 = 0x11;
        p->f171 = 0x11;
        for (i = 0; i < 0x11; i++) {
            p->a[i] = (void *)CLACT_RegisterCharacter(arc, APP_ICON_GetTypeCellFileId(i), 0, flag, p->f0);
            p->b[i] = CLACT_CreateActor(p->f24, (unsigned int)p->a[i], (unsigned int)p->fc8, (unsigned int)p->fcc, &r, sh, p->f0);
            CLACT_SetActorPaletteOffset(p->b[i], APP_ICON_GetTypePaletteOffset(i), 1);
            CLACT_SetActorDrawPriority(p->b[i], 2);
            CLACT_SetActorObjMode(p->b[i], 1);
            CLACT_SetActorDrawEnable(p->b[i], 0);
        }
    } else {
        p->fe4 = 0;
    }
}
