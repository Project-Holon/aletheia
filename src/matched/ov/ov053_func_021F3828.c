/*
 * function: FIELD_GIMMICK_SOUND_OBJS_CreateSoundObjs
 * address:  0x021F3828
 * packet:   pkt_ov053_021F3828
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     the five-word loop stores 0 (copied once from the zero in r4), not i.
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
 *   SOUND_OBJ_CreateNoSource  0x021C4D7C  thumb  ov021
 *   SOUND_OBJ_SetAnime  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits  0x021F3978  thumb  ov053
 *   FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade  0x021F39BC  thumb  ov053
 *   FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe  0x021F3B30  thumb  ov053
 */

typedef unsigned short u16;

typedef struct O {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int w[5];
    char pad30[0x34];
    int f64;
    char f68[1];
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
extern int SOUND_OBJ_CreateNoSource(int, int);
extern void SOUND_OBJ_SetAnime(int, int, int, int);
extern u32 func_020307B0(void *p);
extern void FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits(char *a);
extern void FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade(char *a);
extern void FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe(void *);

void FIELD_GIMMICK_SOUND_OBJS_CreateSoundObjs(O *o, u32 q)
{
    int i;
    int a;
    int t8;
    int s0;
    int s1;
    int *p;
    int r;

    a = FIELDMAP_GetHeapId((u8 *)q);
    t8 = FIELDMAP_GetExpObj((int *)q);
    i = 0;
    o->h0 = a;
    o->f64 = 0;
    o->f4 = func_0202B57C((void *)GAMESYSTEM_GetIssSystem((unsigned int *)FIELDMAP_GetGameSystem((void *)q)));
    p = ARC_TOOL_LoadMember(0x94, 1, a);
    s0 = (int)SOUND_OBJ_Create(q, FLD_EXP_OBJ_GetModelStatus((char *)t8, 0, 0), 8, p[0] << 12, p[1]);
    SOUND_OBJ_SetAnime(s0, 0x94, 3, 10);
    o->f8 = s0;
    func_020307B0(p);
    r = SOUND_OBJ_CreateNoSource(q, FLD_EXP_OBJ_GetModelStatus((char *)t8, 0, 1));
    SOUND_OBJ_SetAnime(r, 0x94, 5, 10);
    o->fc = r;
    p = ARC_TOOL_LoadMember(0x94, 6, a);
    s1 = (int)SOUND_OBJ_Create(q, FLD_EXP_OBJ_GetModelStatus((char *)t8, 0, 2), 9, p[0] << 12, p[1]);
    SOUND_OBJ_SetAnime(s1, 0x94, 8, 10);
    o->f10 = s1;
    func_020307B0(p);
    r = SOUND_OBJ_CreateNoSource(q, FLD_EXP_OBJ_GetModelStatus((char *)t8, 0, 3));
    SOUND_OBJ_SetAnime(r, 0x94, 10, 10);
    o->f14 = r;
    p = ARC_TOOL_LoadMember(0x94, 12, a);
    r = (int)SOUND_OBJ_Create(q, FLD_EXP_OBJ_GetModelStatus((char *)t8, 0, 4), 7, p[0] << 12, p[1]);
    SOUND_OBJ_SetAnime(r, 0x94, 11, 10);
    o->f18 = r;
    func_020307B0(p);
    for (i = 0; i < 5; i++)
        o->w[i] = 0;
    FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits((char *)o);
    FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade((char *)o);
    FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe(o->f68);
}
