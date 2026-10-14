/*
 * function: WORLDTRADE_BOX_LoadBoxIcons
 * address:  0x021F68A4
 * packet:   pkt_021F68A4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02007A18  0x02007A18  thumb
 *   WORLDTRADE_BOX_CalcLevel  0x021F6748  thumb
 *   WORLDTRADE_BOX_SetupIconActor  0x021F67A8  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   func_0200785C  0x0200785C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_02034714  0x02034714  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_BOX_ScoreMatchingRecords  0x021F6DB4  thumb
 *   WORLDTRADE_BOX_TransferIconPalette  0x021F6754  thumb
 *   str_02203B54   0x02203B54  data  a1
 *
 * Build the 30 Pokemon icon slots of the screen from box `box` of the
 * storage (+0xC of the context) or, for box 0xFF, from the party (+8),
 * blanking the slots past the party size. Icon records (0x3D68 bytes,
 * +0xEB8) are uploaded later by WORLDTRADE_BOX_TransferIconPalette, installed at +0xEBC.
 * Any other box reports through func_02034714 (raw 0x02203B68). Kind 6
 * then runs WORLDTRADE_BOX_ScoreMatchingRecords against the current entry's key.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 species;
    s8 f2;
    u8 f3;
} Info;

typedef struct {
    u32 vram;
    u32 pal;
    u32 spr;
    u8 pixels[0x200];
} IconRec;

typedef struct {
    u8 pad0[0xF0];
    u8 key[0x128 - 0xF0];
} Entry;

typedef struct {
    u8 pad0[8];
    void *party;
    void *storage;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0xC8 - 0x24];
    u32 nbox;
    u8 padCC[0xD4 - 0xCC];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry arr[8];
    u8 padB4C[0xB6C - 0xB4C];
    void *fB6C;
    u8 padB70[0xB80 - 0xB70];
    void *fB80;
    u8 padB84[0xC00 - 0xB84];
    u32 icon[30];
    u32 item[30];
    u32 mark[6];
    u8 padD08[0xD4C - 0xD08];
    void *fD4C;
    u8 padD50[0xEAC - 0xD50];
    Info *info;
    u8 padEB0[0xEB8 - 0xEB0];
    IconRec *icons;
    void (*vblank)(void *);
    u8 padEC0[0xFA0 - 0xEC0];
    u8 fFA0[4];
} Work;

extern char str_02203B54[];

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub020079BCEntry;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void WORLDTRADE_BOX_CalcLevel(u32 a, u8 *q);
extern void WORLDTRADE_BOX_SetupIconActor(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, Info *info, IconRec *rec);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void func_0200785C(void *save, u32 box, void *dest);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *list, u32 i);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void WORLDTRADE_BOX_ScoreMatchingRecords(Info *recs, u32 *unused, void *key, IconRec *ent);
extern void WORLDTRADE_BOX_TransferIconPalette(Work *p);

void WORLDTRADE_BOX_LoadBoxIcons(Work *p, int box)
{
    void *storage = p->ctx->storage;
    u16 species[30];
    void *arc;
    IconRec *icons;
    u16 i;

    icons = func_02030734(0x8001, 0x3D68, 0, str_02203B54, 0x892);
    p->icons = icons;
    arc = func_020490F4(7, 0x48);
    if (box >= 0 && box < p->nbox) {
        for (i = 0; i < 30; i++) {
            WORLDTRADE_BOX_CalcLevel((u32)func_02007A18(storage, box, i), (u8 *)(&p->info[i]));
        }
        for (i = 0; i < 30; i++) {
            p->info[i].species = 0;
            WORLDTRADE_BOX_SetupIconActor(func_02007A18(storage, box, i), p->icon[i], p->item[i], &species[i], i, arc, &p->info[i], &icons[i]);
            if (i < 6) {
                CLACT_SetActorDrawEnable((struct Obj *)p->mark[i], 0);
            }
        }
        func_0200785C(storage, box, p->fB80);
    } else if (box == 0xff) {
        int n = POKEPARTY_GetCount(p->ctx->party);

        for (i = 0; i < n; i++) {
            void *mon = POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(p->ctx->party, i));

            WORLDTRADE_BOX_CalcLevel((u32)mon, (u8 *)(&p->info[i]));
            WORLDTRADE_BOX_SetupIconActor(mon, p->icon[i], p->item[i], &species[i], i, arc, &p->info[i], &icons[i]);
            CLACT_SetActorDrawEnable((struct Obj *)p->mark[i], 0);
        }
        for (; i < 30; i++) {
            p->info[i].species = 0;
            CLACT_SetActorDrawEnable((struct Obj *)p->icon[i], 0);
            CLACT_SetActorDrawEnable((struct Obj *)p->item[i], 0);
            icons[i].spr = 0;
            if (i < 6) {
                CLACT_SetActorDrawEnable((struct Obj *)p->mark[i], 0);
            }
        }
        MSGDATA_ReadString(p->fB6C, 0x62, p->fB80);
    } else {
        func_02034714((void *)0x02203B68, 0, (void *)0x02203B68);
    }
    ARC_TOOL_DeleteHandle(arc);
    BMP_Clear(BMP_WIN_GetBmp(p->fD4C), 0);
    WORLDTRADE_INPUT_PrintStringAlignedLine(p->fD4C, (u32)p->fB80, 0, 5, 1, 0x440, (u32)p->fFA0);
    if (p->kind == 6) {
        WORLDTRADE_BOX_ScoreMatchingRecords(p->info, p->icon, p->arr[p->cur].key, icons);
    }
    p->vblank = (void (*)(void *))WORLDTRADE_BOX_TransferIconPalette;
}
