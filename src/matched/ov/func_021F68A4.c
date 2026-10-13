/*
 * function: func_021F68A4
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
 *   func_021F6748  0x021F6748  thumb
 *   func_021F67A8  0x021F67A8  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0200785C  0x0200785C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02034714  0x02034714  arm
 *   func_02049238  0x02049238  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F6DB4  0x021F6DB4  thumb
 *   func_021F6754  0x021F6754  thumb
 *   str_02203B54   0x02203B54  data  a1
 *
 * Build the 30 Pokemon icon slots of the screen from box `box` of the
 * storage (+0xC of the context) or, for box 0xFF, from the party (+8),
 * blanking the slots past the party size. Icon records (0x3D68 bytes,
 * +0xEB8) are uploaded later by func_021F6754, installed at +0xEBC.
 * Any other box reports through func_02034714 (raw 0x02203B68). Kind 6
 * then runs func_021F6DB4 against the current entry's key.
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
extern void func_021F6748(u32 a, u8 *q);
extern void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, Info *info, IconRec *rec);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0200785C(void *save, u32 box, void *dest);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *list, u32 i);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02049238(void *h);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_021F6DB4(Info *recs, u32 *unused, void *key, IconRec *ent);
extern void func_021F6754(Work *p);

void func_021F68A4(Work *p, int box)
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
            func_021F6748((u32)func_02007A18(storage, box, i), (u8 *)(&p->info[i]));
        }
        for (i = 0; i < 30; i++) {
            p->info[i].species = 0;
            func_021F67A8(func_02007A18(storage, box, i), p->icon[i], p->item[i], &species[i], i, arc, &p->info[i], &icons[i]);
            if (i < 6) {
                func_0204B3DC((struct Obj *)p->mark[i], 0);
            }
        }
        func_0200785C(storage, box, p->fB80);
    } else if (box == 0xff) {
        int n = func_0201AA18(p->ctx->party);

        for (i = 0; i < n; i++) {
            void *mon = POKE_TOOL_GetBoxParam(func_0201AB28(p->ctx->party, i));

            func_021F6748((u32)mon, (u8 *)(&p->info[i]));
            func_021F67A8(mon, p->icon[i], p->item[i], &species[i], i, arc, &p->info[i], &icons[i]);
            func_0204B3DC((struct Obj *)p->mark[i], 0);
        }
        for (; i < 30; i++) {
            p->info[i].species = 0;
            func_0204B3DC((struct Obj *)p->icon[i], 0);
            func_0204B3DC((struct Obj *)p->item[i], 0);
            icons[i].spr = 0;
            if (i < 6) {
                func_0204B3DC((struct Obj *)p->mark[i], 0);
            }
        }
        func_02045CAC(p->fB6C, 0x62, p->fB80);
    } else {
        func_02034714((void *)0x02203B68, 0, (void *)0x02203B68);
    }
    func_02049238(arc);
    func_02043B5C(func_02045770(p->fD4C), 0);
    func_021F91A0(p->fD4C, (u32)p->fB80, 0, 5, 1, 0x440, (u32)p->fFA0);
    if (p->kind == 6) {
        func_021F6DB4(p->info, p->icon, p->arr[p->cur].key, icons);
    }
    p->vblank = (void (*)(void *))func_021F6754;
}
