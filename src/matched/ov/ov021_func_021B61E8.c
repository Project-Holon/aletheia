/*
 * function: SCRCMD_POKEMON_FLD_SelectTutorMon
 * address:  0x021B61E8
 * packet:   pkt_ov021_021B61E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   EVENT_POKE_STATUS_CreatePokeSelectMoveEvent  0x0215A0E8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_POKEMON_FLD_FindTutorCandidates  0x021B6048  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *EVENT_POKE_STATUS_CreatePokeSelectMoveEvent(void *t, u16 *o1, u16 *o2, u8 c, u32 v);
extern void SCRIPT_SYS_CallEvent(void *s, void *v);
extern int SCRCMD_POKEMON_FLD_FindTutorCandidates(u32 a, u32 b, u32 key, u8 *mask, u32 flag);

int SCRCMD_POKEMON_FLD_SelectTutorMon(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    void *s;
    void *t;
    u32 v;
    u8 c;

    mode = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o1 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    o2 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    s = SCRCMD_WORK_GetScriptWork((void *)b);
    t = SCRCMD_WORK_GetGameSystem((void *)b);
    if (SCRCMD_POKEMON_FLD_FindTutorCandidates(a, b, mode, &c, 0)) {
        *o1 = 0;
    } else {
        switch (mode) {
        case 1:
            v = 0xfffe;
            break;
        case 2:
            v = 0xfffd;
            break;
        case 0:
            v = 0x1b2;
            break;
        default:
            v = 0xa5;
            break;
        }
        SCRIPT_SYS_CallEvent(s, EVENT_POKE_STATUS_CreatePokeSelectMoveEvent(t, o1, o2, c, v));
    }
    return 1;
}
