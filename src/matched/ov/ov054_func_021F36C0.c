/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov054_021F36C0
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GIMMICK54_CreateSoundObjs  0x021F37B4  thumb  ov054
 *   GIMMICK54_ExitSoundObjs  0x021F38E4  thumb  ov054
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   d_021F39A0     0x021F39A0  data  a4
 */

extern char d_021F39A0[];

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_AddUnit(unsigned a, void *b, int c);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
struct O;
extern void GIMMICK54_CreateSoundObjs(struct O *o, u32 q);
extern void GIMMICK54_ExitSoundObjs(char *p, int a);
extern void ISS_3DS_SYS_SetVolume(struct Obj *o, u32 v);

void func_021F36C0(unsigned a)
{
    unsigned r5;
    int *p;

    r5 = FIELDMAP_GetHeapId((u8 *)a);
    FLD_EXP_OBJ_AddUnit(FIELDMAP_GetExpObj((int *)a), d_021F39A0, 0);
    p = FIELDMAP_AllocCommonWork((unsigned char *)a, 0, r5, 0x28);
    GIMMICK54_CreateSoundObjs((struct O *)p, a);
    GIMMICK54_ExitSoundObjs((char *)p, a);
    ISS_3DS_SYS_SetVolume((struct Obj *)p[1], 0x7f);
}
