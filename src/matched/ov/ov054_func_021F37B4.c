/*
 * function: GIMMICK54_CreateSoundObjs
 * address:  0x021F37B4
 * packet:   pkt_ov054_021F37B4
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   SOUND_OBJ_Create  0x021C4D14  thumb  ov021
 *   SOUND_OBJ_SetAnime  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   GIMMICK54_LoadWaitLimits  0x021F3874  thumb  ov054
 */

typedef unsigned short u16;

typedef struct O {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int fc;
    int w[2];
} O;

typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern unsigned int GAMESYSTEM_GetIssSystem(unsigned int *p);
extern unsigned int func_0202B57C(void *obj);
typedef unsigned int   u32;
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void *SOUND_OBJ_Create(int a, int b, int c, int d, int e);
extern void SOUND_OBJ_SetAnime(int, int, int, int);
extern u32 func_020307B0(void *p);
extern void GIMMICK54_LoadWaitLimits(char *p);

void GIMMICK54_CreateSoundObjs(O *o, u32 q)
{
    int i;
    int t8;
    int s0;
    int a;
    int *p;
    int r;

    a = FIELDMAP_GetHeapId((u8 *)q);
    t8 = FIELDMAP_GetExpObj((int *)q);
    o->h0 = a;
    o->f4 = func_0202B57C((void *)GAMESYSTEM_GetIssSystem((unsigned int *)FIELDMAP_GetGameSystem((void *)q)));
    p = ARC_TOOL_LoadMember(0x7f, 1, a);
    i = 0;
    s0 = (int)SOUND_OBJ_Create(q, FLD_EXP_OBJ_GetModelStatus((char *)t8, 0, 0), 8, p[0] << 12, p[1]);
    SOUND_OBJ_SetAnime(s0, 0x7f, 3, 10);
    o->f8 = s0;
    func_020307B0(p);
    p = ARC_TOOL_LoadMember(0x7f, 2, a);
    r = (int)SOUND_OBJ_Create(q, FLD_EXP_OBJ_GetModelStatus((char *)t8, 0, 1), 9, p[0] << 12, p[1]);
    SOUND_OBJ_SetAnime(r, 0x7f, 4, 10);
    o->fc = r;
    func_020307B0(p);
    for (i = 0; i < 2; i++)
        o->w[i] = 0;
    GIMMICK54_LoadWaitLimits((char *)o);
}
