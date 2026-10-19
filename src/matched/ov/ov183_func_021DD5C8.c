/*
 * function: BR_CODEIN_ListSetupText
 * address: 0x021DD5C8
 * packet: pkt_ov183_021DD5C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const record array at the table address restores early argument loads;
 *        a scalar record and const pointer local remained 22 bytes DIFF.
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BSUBWAY_SCOREDATA_GetBattlePoints 0x0200DABC thumb
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_CODEIN_ListCreateActor 0x021DE084 thumb ov183
 *   d_021E3350 0x021E3350 data a4
 */
#include "../include/Obj00631.h"
#include "../include/Obj00632.h"
typedef unsigned short u16;
typedef unsigned char u8;
struct Record { u8 a, b, c, d; int value; };
struct Triple { int a, b, c; };
extern const struct Record d_021E3350[];
typedef unsigned int   u32;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
typedef signed short   s16;
struct Blk1AC;
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void *BR_UTIL_Create(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern void BR_UTIL_SetTextFromMessage(char *p, void *a, void *b, void *font, unsigned short value);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern u16 BSUBWAY_SCOREDATA_GetBattlePoints(struct Blk1AC *p);
extern int BR_RES_GetSprite(int, int, struct Triple *);
extern void BR_CODEIN_ListCreateActor(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap);
void BR_CODEIN_ListSetupText(char *p, char *q)
{
    int first, second, v;
    struct Triple triple;
    const struct Record *rec;
    u8 a, b, c, d;
    first = BR_RES_GetFont(*(char * *)&((struct Obj00632 *)q)->f8);
    second = BR_RES_GetMsgData(*(char * *)&((struct Obj00632 *)q)->f8);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj00632 *)q)->f8), 14, ((struct Obj00631 *)p)->f7C);
    rec = &d_021E3350[0];
    d = rec->d;
    a = rec->a;
    b = rec->b;
    c = rec->c;
    ((struct Obj00631 *)p)->f34 = BR_UTIL_Create(1, a, b, c, d, 14, ((struct Obj00631 *)p)->f4, ((struct Obj00631 *)p)->f7C);
    BR_UTIL_SetTextLayout(((struct Obj00631 *)p)->f34, 0, 1, 0);
    BR_UTIL_SetTextFromMessage(((struct Obj00631 *)p)->f34, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
    ((struct Obj00631 *)p)->f1C = BR_UTIL_CreateTextWin(*(int *)&((struct Obj00632 *)q)->f8, (void *)(*(int *)&((struct Obj00631 *)p)->f4), ((struct Obj00631 *)p)->f7C);
    BR_UTIL_SetWindowText(((struct Obj00631 *)p)->f1C, (char *)(*(int *)&((struct Obj00632 *)q)->f8), (void *)0x86);
    v = BSUBWAY_SCOREDATA_GetBattlePoints((struct Blk1AC *)(((struct Obj00632 *)q)->f10));
    BR_RES_GetSprite(*(int *)&((struct Obj00632 *)q)->f8, 13, &triple);
    BR_CODEIN_ListCreateActor((void *)(p + 8), (void *)(*(int *)&((struct Obj00632 *)q)->f4), (const char *)(&triple), v, 0x68, 0x58, ((struct Obj00631 *)p)->f7C);
}
