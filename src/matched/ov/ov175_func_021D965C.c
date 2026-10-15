/*
 * function: func_021D965C
 * address:  0x021D965C
 * packet:   pkt_021D965C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02012944  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BATTLE_COMPETITION_GetFromSave  0x0200B358  thumb
 *   REGULATION_GetParty  0x0200B204  thumb
 *   REGULATION_Card_GetCupName  0x0200B074  thumb
 *   REGULATION_Card_GetValue  0x0200B078  thumb
 *   func_02008554  0x02008554  thumb
 *   BSUBWAY_SAVEDATA_GetStat  0x0200DFD8  thumb
 *   func_021E5548  0x021E5548  thumb  ov177
 *   func_021E5D68  0x021E5D68  thumb  ov177
 *
 * Opens the +0x1c profile exchange when none is open: builds a 0xac-byte
 *     profile (0x92 bytes copied from the +0x108 block, three packed byte
 *     triples, the play-time words from the +0x104 save), then hands it to
 *     0x021E5D68 with the +0x04..+0x18 words.
 *
 * The three calls to 0x0200DFD8 resolve since seeds_2 labelled and matched
 *     it (src/matched/unit_0200DFD8.c).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Save {
    u32 f00;
    u32 f04;
    u32 *f08;
    u32 f0c;
    u32 f10;
};

struct Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8 pad20[0xe4];
    struct Save *f104;
    u32 f108;
};

struct Profile {
    u8 name[0x94];
    u32 f94;
    u32 f98;
    u32 f9c;
    u16 fa0;
    u16 fa2;
    u32 fa4;
    u16 fa8;
    u16 faa;
};

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
typedef signed int     s32;
struct Big;
struct Rec1E;
struct RecBig;
struct Reg2;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_COMPETITION_GetFromSave(void *sys);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32 index);
extern u8 *REGULATION_Card_GetCupName(struct Reg2 *p);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32 BSUBWAY_SAVEDATA_GetStat(u32 a, u32 b, u32 c);
extern int func_021E5548(int *p);
extern char *func_021E5D68(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);

void func_021D965C(struct Obj *obj)
{
    struct Profile prof;
    u32 sys;
    u32 id;
    u32 kind;
    u32 a;
    u32 b;
    u32 data;
    u32 c;

    if (obj->f1c == 0) {
        data = obj->f108;
        sys = (u32)func_02012944((void *)(*obj->f104->f08));
        id = func_021E5548((int *)obj->f00);
        kind = (u32)REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*obj->f104->f08))), 0);
        MI_CpuFill8(&prof, 0, sizeof(prof));
        MI_CpuCopy8(REGULATION_Card_GetCupName((struct Reg2 *)data), &prof, 0x92);
        a = REGULATION_Card_GetValue((struct Reg2 *)data, 6);
        b = REGULATION_Card_GetValue((struct Reg2 *)data, 5);
        c = REGULATION_Card_GetValue((struct Reg2 *)data, 4);
        prof.f94 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        a = REGULATION_Card_GetValue((struct Reg2 *)data, 9);
        b = REGULATION_Card_GetValue((struct Reg2 *)data, 8);
        c = REGULATION_Card_GetValue((struct Reg2 *)data, 7);
        prof.f98 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        prof.f9c = func_02008554((const struct Sub0200852CObj *)sys);
        prof.fa0 = BSUBWAY_SAVEDATA_GetStat(obj->f104->f10, 10, 0);
        a = BSUBWAY_SAVEDATA_GetStat(obj->f104->f10, 10, 1);
        prof.fa4 = a + BSUBWAY_SAVEDATA_GetStat(obj->f104->f10, 10, 2);
        prof.faa = REGULATION_Card_GetValue((struct Reg2 *)data, 11);
        if (prof.fa4 == 0 && prof.fa0 == 0)
            prof.fa0 = 1500;
        obj->f1c = (u32)func_021E5D68((char *)(&prof), 0, (void *)sys, (void *)id, (void *)obj->f04, obj->f08, (void *)obj->f10, (void *)obj->f14, (void *)obj->f18, (void *)kind, 0, 0x57);
    }
}
