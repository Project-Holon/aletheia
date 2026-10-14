/*
 * function: BTLV_EFFECT_CreateSetupFromBattleMain
 * address: 0x021F745C
 * packet: pkt_ov094_021F745C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   BTL_MAIN_IsOwnClientSecondTeam 0x021B8FE4 thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_GetOwnPartnerClient 0x021B9000 thumb ov093
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   BTL_MAIN_GetOwnOpponentClient 0x021B904C thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetFieldSituation 0x021B8714 thumb ov093
 *   BTLV_EFFECT_CreateSetup 0x021F73F0 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int w[4]; } Q;
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern u8 BTL_MAIN_IsOwnClientSecondTeam(u8 *p);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern u8 BTL_MAIN_GetOwnPartnerClient(u8 *p);
extern u16 BTL_MAIN_GetTrainerType(char *, int);
extern u8 BTL_MAIN_GetOwnOpponentClient(u8 *p, int k);
extern u32 BTL_MAIN_GetRule(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern char *BTL_MAIN_GetFieldSituation(char **);
extern void *BTLV_EFFECT_CreateSetup(int, int, Q *, int, u16 *, int, int, u16);

void *BTLV_EFFECT_CreateSetupFromBattleMain(u8 *p, int a, u16 heap)
{
    u16 h[4];
    unsigned int i;
    int side, idx, other;
    int mode, type;
    Q *q;
    for (i = 0; i < 4; i++) h[i] = 0;
    if (BTL_MAIN_IsMultiMode((unsigned char **)p) == 1) {
        side = BTL_MAIN_IsOwnClientSecondTeam(p);
        idx = BTL_MAIN_GetOwnClientId(p);
        other = BTL_MAIN_GetOwnPartnerClient(p);
        h[side * 2] = BTL_MAIN_GetTrainerType((char *)p, idx);
        if (other != 4) h[(side ^ 1) * 2] = BTL_MAIN_GetTrainerType((char *)p, other);
        h[1] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnOpponentClient(p, 0));
        h[3] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnOpponentClient(p, 1));
    } else {
        h[0] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnClientId(p));
        h[1] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnOpponentClient(p, 0));
        h[2] = 0;
        h[3] = 0;
    }
    mode = BTL_MAIN_GetRule((void **)p);
    type = (int)BTL_MAIN_GetCompetitor((void ***)p);
    q = (Q *)BTL_MAIN_GetFieldSituation((char **)p);
    return BTLV_EFFECT_CreateSetup(mode, type, q, BTL_MAIN_IsMultiMode((unsigned char **)p), h, (int)p, a, heap);
}
