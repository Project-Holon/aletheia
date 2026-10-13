/*
 * function: func_022056E8
 * address:  0x022056E8
 * packet:   pkt_022056E8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gSpeciesNameBank 0x020A7370 data a4
 *   d_02208F40 0x02208F40 data a4
 *   GAME_DATA_GetMyItem 0x0201292C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AA14 0x0201AA14 thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   POKE_TOOL_ChangeSpecies 0x020178D8 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   MAIL_Create 0x02008F08 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_02030734 0x02030734 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06644.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 gSpeciesNameBank;
extern u32 d_02208F40[];
struct BigObj;
struct Blk37;
struct MsgBank;
struct RecDC;
struct Sub02008C20Obj;
struct U16Vec;
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 func_0201AA18(void *);
extern u32 func_0201AA14(void *p);
typedef unsigned char  u8;
struct Party;
struct PartyMon;
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void POKE_TOOL_ChangeSpecies(void *p, u32 a);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *MAIL_Create(int a0);
extern u32 func_020307B0(void *p);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0200CA1C(void *a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

void func_022056E8(u32 *a, char *b)
{
    void *save;
    u32 p, q, v;
    int i;

    save = GAME_DATA_GetMyItem((const struct BigObj *)a[0]);
    if ((int)func_0201AA18((void *)a[1]) >= (int)func_0201AA14((void *)a[1]))
        return;
    if (func_02007F68(save, 4, 1, ((struct Obj06644 *)b)->f0) == 0)
        return;
    p = (u32)func_02030734(((struct Obj06644 *)b)->f0, POKE_TOOL_GetPartyParamSize(), 1, (const char *)d_02208F40, 0xaf5);
    func_02019CE0((const struct RecDC *)(((struct Obj06644 *)b)->f10), (struct RecDC *)p);
    POKE_TOOL_ChangeSpecies((void *)p, 0x124);
    POKE_TOOL_SetPartyValue((void *)p, 0x98, 4);
    POKE_TOOL_SetPartyValue((void *)p, 6, 0);
    POKE_TOOL_SetPartyValue((void *)p, 0xb, 0);
    for (i = 0x19; i < 0x36; i++)
        POKE_TOOL_SetPartyValue((void *)p, i, 0);
    for (i = 0x4d; i < 0x6d; i++)
        POKE_TOOL_SetPartyValue((void *)p, i, 0);
    for (i = 0x78; i < 0x8d; i++)
        POKE_TOOL_SetPartyValue((void *)p, i, 0);
    v = (u32)func_02045EC0((struct MsgBank *)gSpeciesNameBank, POKE_TOOL_GetPartyValue((void *)p, 5, 0));
    POKE_TOOL_SetPartyValue((void *)p, 0x73, v);
    STRBUF_Delete((struct U16Vec *)v);
    POKE_TOOL_SetPartyValue((void *)p, 0x9d, 0);
    v = (u32)MAIL_Create(((struct Obj06644 *)b)->f0);
    POKE_TOOL_SetPartyValue((void *)p, 0xa7, v);
    func_020307B0((void *)v);
    POKE_TOOL_SetPartyValue((void *)p, 0x9f, 0);
    func_0201A98C((void *)a[1], (void *)p);
    func_02007F1C(save, 4, 1, ((struct Obj06644 *)b)->f0);
    func_020307B0((void *)p);
    q = (u32)func_0200CA1C((void *)a[0]);
    func_0200CFA0((struct Blk37 *)q, (void *)p);
    func_0200CDE0((struct Blk37 *)q, (void *)p);
    q = (u32)GAME_DATA_GetTrainerRecord((int *)a[0]);
    func_02008DF0((struct Sub02008C20Obj *)q, 10);
    func_02008DF0((struct Sub02008C20Obj *)q, 0x58);
}
