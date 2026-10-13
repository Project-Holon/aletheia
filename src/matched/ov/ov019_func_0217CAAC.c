/*
 * function: UNION_ONESELF_TalkPlayingMain
 * address: 0x0217CAAC
 * packet: pkt_ov019_0217CAAC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_CHARA_GetBeaconIndex 0x0217AEFC thumb ov019
 *   func_0217ED04 0x0217ED04 thumb ov019
 *   func_0217ED10 0x0217ED10 thumb ov019
 *   func_0217ECE8 0x0217ECE8 thumb ov019
 *   func_0217ED80 0x0217ED80 thumb ov019
 *   func_0217ED8C 0x0217ED8C thumb ov019
 *   func_0217ED64 0x0217ED64 thumb ov019
 *   func_0217ED98 0x0217ED98 thumb ov019
 *   func_0217ED2C 0x0217ED2C thumb ov019
 *   func_0217ED48 0x0217ED48 thumb ov019
 *   func_0217EDA4 0x0217EDA4 thumb ov019
 *   func_0217EE28 0x0217EE28 thumb ov019
 *   func_0217EDBC 0x0217EDBC thumb ov019
 *   func_0217EDB0 0x0217EDB0 thumb ov019
 *   func_0217EE04 0x0217EE04 thumb ov019
 *   func_0217EDD4 0x0217EDD4 thumb ov019
 *   func_0217EDC8 0x0217EDC8 thumb ov019
 *   func_0217EDE0 0x0217EDE0 thumb ov019
 *   UNION_MSG_GetCategoryTableValue 0x0217F060 thumb ov019
 *   UNION_MSG_SetupPrintTalkMsg 0x0217F210 thumb ov019
 *   UNION_MSG_CheckTalkPrintEnd 0x0217F1EC thumb ov019
 *   UNION_MSG_CheckRegulationPrintEnd 0x0217F794 thumb ov019
 *   UNION_MSG_DeleteRegulationWindow 0x0217F7B8 thumb ov019
 *   UNION_MSG_SetupRegulationWindow 0x0217F640 thumb ov019
 *   UNION_MSG_SetupYesNo 0x0217F22C thumb ov019
 *   UNION_MSG_SelectYesNo 0x0217F268 thumb ov019
 *   UNION_MSG_DeleteYesNo 0x0217F24C thumb ov019
 *   UNION_ONESELF_SetNextPlayCategory 0x0217B8E4 thumb ov019
 *   UNION_ONESELF_LoadRegulation 0x0217BA10 thumb ov019
 *   UNION_ONESELF_GetRegulationFlag 0x0217B974 thumb ov019
 *   UNION_ONESELF_CheckEntryParties 0x0217BAA8 thumb ov019
 *   KEY_GetTrg 0x020362DC arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetBadEggCount 0x0201AAD4 thumb
 *   POKEPARTY_GetEggCount 0x0201AA88 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[7]; u8 lo:3; u8 flag:1; } Sub;
typedef struct {
    u8 pad00[0x14]; Sub *f14;
    u8 pad18[0x2d-0x18]; u8 f2d, f2e;
    u8 pad2f[0x58-0x2f]; u16 f58;
    u8 pad5a[0x64-0x5a]; int f64, f68;
} Obj;
typedef struct { u8 count:3; u8 flag:1; } Bits;
u16 UNION_CHARA_GetBeaconIndex(u32);
u16 func_0217ED04(int); u16 func_0217ED10(int); u16 func_0217ECE8(int);
u16 func_0217ED80(int); u16 func_0217ED8C(int); u16 func_0217ED64(int);
u16 func_0217ED98(int); u16 func_0217ED2C(int); u16 func_0217ED48(int);
u16 func_0217EDA4(int); u16 func_0217EE28(int); u16 func_0217EDBC(int);
u16 func_0217EDB0(int); u16 func_0217EE04(int); u16 func_0217EDD4(int);
u16 func_0217EDC8(int); u16 func_0217EDE0(int);
int UNION_MSG_GetCategoryTableValue(int i);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b); u32 UNION_MSG_CheckTalkPrintEnd(u8 *);
struct Self;
u32 UNION_MSG_CheckRegulationPrintEnd(char *p, u32 a); void UNION_MSG_DeleteRegulationWindow(u8 *);
void UNION_MSG_SetupRegulationWindow(struct Self *self, u32 a1, u32 mask, int mode, int msg);
void UNION_MSG_SetupYesNo(u8 *, u32); int UNION_MSG_SelectYesNo(u8 *, u32 *);
void UNION_MSG_DeleteYesNo(u8 *); int UNION_ONESELF_SetNextPlayCategory(u8 *, char);
void UNION_ONESELF_LoadRegulation(char *p, int x); int UNION_ONESELF_GetRegulationFlag(int);
int UNION_ONESELF_CheckEntryParties(int a, int b, int *p, int *q);
u32 KEY_GetTrg(void); void *GAME_DATA_GetMyParty(void *);
u32 POKEPARTY_GetBadEggCount(void *p); int POKEPARTY_GetEggCount(void *);
int UNION_ONESELF_TalkPlayingMain(u8 *ctx, Obj *obj, u8 *a, u8 *state)
{
    int offset, id;
    u32 selected, selected2;
    void *save;
    offset = UNION_CHARA_GetBeaconIndex(obj->f58) * 0x8c;
    id = (ctx + offset)[0x291b];
    switch (*state) {
    case 0:
        obj->f2d = id;
        switch (id) {
        case 1: UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED04(obj->f14->flag)); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        case 2: UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED10(obj->f14->flag)); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
            UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ECE8(obj->f14->flag)); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        case 20: case 21: case 22: case 23:
            if ((int)((Bits *)((ctx + offset) + 0x2916))->count < UNION_MSG_GetCategoryTableValue(id)) {
                UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED80(obj->f14->flag));
                UNION_ONESELF_LoadRegulation((char *)ctx,id);
                UNION_MSG_SetupRegulationWindow((struct Self *)ctx,(int)a,(int)0,UNION_ONESELF_GetRegulationFlag(id),0);
                *state = 3;
                goto done;
            }
            UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ECE8(obj->f14->flag));
            UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        case 25:
            if ((int)((Bits *)(ctx + 0x2916 + offset))->count < UNION_MSG_GetCategoryTableValue(id) &&
                ((Bits *)(ctx + 0x2916 + offset))->flag == 0) {
                UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED8C(obj->f14->flag));
                *state = 10;
                goto done;
            }
            UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED64(obj->f14->flag)); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        case 3:
            if ((int)((Bits *)((ctx + offset) + 0x2916))->count < UNION_MSG_GetCategoryTableValue(id)) {
                UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED98(obj->f14->flag));
                *state = 10;
                goto done;
            }
            UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED2C(obj->f14->flag)); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        case 24: UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217ED48(obj->f14->flag)); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        case 0: default: UNION_MSG_SetupPrintTalkMsg(ctx,a,0x151); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state=2; goto done;
        }
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) == 1 && (KEY_GetTrg() & 0xf3)) return 1;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) == 1) return 1;
        break;
    case 3:
        if (UNION_MSG_CheckRegulationPrintEnd((char *)ctx,(u32)a) == 1) *state = 4;
        break;
    case 4:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) == 1) {
            UNION_MSG_DeleteRegulationWindow(ctx); UNION_MSG_SetupYesNo(ctx,(u32)a); (*state)++;
        }
        break;
    case 5:
        if (UNION_MSG_SelectYesNo(ctx,&selected) == 1) {
            UNION_MSG_DeleteYesNo(ctx);
            if (selected == 0) {
                UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EDA4(obj->f14->flag));
                UNION_ONESELF_SetNextPlayCategory(ctx,0); *state = 2;
            } else if (UNION_ONESELF_CheckEntryParties((int)ctx,obj->f2d,&obj->f64,&obj->f68) == 0) {
                UNION_MSG_SetupPrintTalkMsg(ctx,a,0x13e); UNION_ONESELF_SetNextPlayCategory(ctx,0); *state = 6;
            } else {
                obj->f2e = selected; UNION_ONESELF_SetNextPlayCategory(ctx,0x26);
                UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EE28(obj->f14->flag)); *state = 1;
            }
        }
        break;
    case 6:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) == 1) return 1;
        UNION_MSG_SetupRegulationWindow((struct Self *)ctx,(int)a,(int)obj->f64,UNION_ONESELF_GetRegulationFlag(obj->f2d),1); (*state)++;
        break;
    case 7:
        if (UNION_MSG_CheckRegulationPrintEnd((char *)ctx,(u32)a) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(ctx);
            if (obj->f68 == -1) *state = 1; else (*state)++;
        }
        break;
    case 8:
        UNION_MSG_SetupRegulationWindow((struct Self *)ctx,(int)a,(int)obj->f64,UNION_ONESELF_GetRegulationFlag(obj->f2d),2); (*state)++;
        break;
    case 9:
        if (UNION_MSG_CheckRegulationPrintEnd((char *)ctx,(u32)a) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(ctx); *state = 1;
        }
        break;
    case 10:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) == 1) {
            UNION_MSG_SetupYesNo(ctx,(u32)a); (*state)++;
        }
        break;
    case 11:
        if (UNION_MSG_SelectYesNo(ctx,&selected2) == 1) {
            UNION_MSG_DeleteYesNo(ctx);
            if (selected2 == 0) {
                switch (obj->f2d) {
                case 3: UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EDBC(obj->f14->flag)); break;
                case 25: UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EDB0(obj->f14->flag)); break;
                }
                UNION_ONESELF_SetNextPlayCategory(ctx,0); *state = 2;
            } else {
                obj->f2e = selected2; UNION_ONESELF_SetNextPlayCategory(ctx,0x26); *state = 1;
                switch (obj->f2d) {
                case 3: UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EE04(obj->f14->flag)); break;
                case 25:
                    save = GAME_DATA_GetMyParty((void *)(*(u32 **)ctx)[2]);
                    if ((int)POKEPARTY_GetBadEggCount(save) > 0) {
                        UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EDD4(obj->f14->flag));
                        UNION_ONESELF_SetNextPlayCategory(ctx,0); *state = 2;
                    } else if (POKEPARTY_GetEggCount(save) == 0) {
                        UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EDC8(obj->f14->flag));
                        UNION_ONESELF_SetNextPlayCategory(ctx,0); *state = 2;
                    } else UNION_MSG_SetupPrintTalkMsg(ctx,a,func_0217EDE0(obj->f14->flag));
                    break;
                }
            }
        }
        break;
    }
done:
    return 0;
}
