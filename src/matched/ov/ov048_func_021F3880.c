/*
 * function: FIELD_GIMMICK_GATE_CreateWork
 * address:  0x021F3880
 * packet:   pkt_ov048_021F3880
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_GetModelObject  0x021BE4C4  thumb  ov021
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GIMMICK_OBJ_ELBOARD_Create  0x021F4698  thumb  ov048
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    u16 f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
} Obj;

typedef struct Cfg {
    u16 a;
    u8 b;
    u8 c;
    u8 d;
    int w;
} Cfg;

struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void *FLD_EXP_OBJ_GetModelObject(int a, int b, int c);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *GIMMICK_OBJ_ELBOARD_Create(unsigned char *p);

Obj *FIELD_GIMMICK_GATE_CreateWork(int a)
{
    u16 r5;
    int r7;
    Obj *o;
    int v;
    Cfg c;

    r5 = FIELDMAP_GetHeapId((u8 *)a);
    r7 = FIELDMAP_GetExpObj((int *)a);
    o = FIELDMAP_AllocCommonWork((unsigned char *)a, 0, r5, 0x68);
    MI_CpuFill8(o, 0, 0x68);
    o->f00 = r5;
    o->f04 = a;
    v = (int)FIELDMAP_GetGameSystem((void *)a);
    o->f0C = v;
    o->f08 = (int)ICA_ANIME_GetField1C((const struct Ctx *)v);
    o->f10 = 0;
    c.a = r5;
    c.b = 7;
    c.c = 8;
    c.d = 3;
    c.w = (int)FLD_EXP_OBJ_GetModelObject(r7, 1, 0);
    o->f14 = (int)GIMMICK_OBJ_ELBOARD_Create((unsigned char *)(&c));
    return o;
}
