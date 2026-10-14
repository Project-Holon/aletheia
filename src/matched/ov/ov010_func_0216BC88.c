/*
 * function: SCRCMD_EVENT_MON_CmdMoveSpPokeGimmick
 * address:  0x0216BC88
 * packet:   pkt_ov010_0216BC88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SP_POKE_GIMMICK_ShowAndPlay  0x021F3AA0  thumb  ov059
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void SP_POKE_GIMMICK_ShowAndPlay();

int SCRCMD_EVENT_MON_CmdMoveSpPokeGimmick(int c, int vm)
{
    void *p;
    int a1;
    int a2;
    int a3;
    int a4;
    int vec[3];

    p = SCRCMD_WORK_GetGameSystem((void *)vm);
    a1 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a2 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a3 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    a4 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    SP_POKE_GIMMICK_ShowAndPlay(p, a1, vec);
    return 0;
}
