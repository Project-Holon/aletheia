/*
 * function: SP_POKE_GIMMICK_Exit
 * address:  0x021F3980
 * packet:   pkt_ov059_021F3980
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 */

extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void FIELDMAP_FreeCommonWork(unsigned char *p, int id);
extern void FLD_EXP_OBJ_RemoveUnit(unsigned char *p, unsigned short i);

void SP_POKE_GIMMICK_Exit(unsigned char *p)
{
    void *s;
    int *o;
    s = (void *)FIELDMAP_GetExpObj((int *)p);
    o = FIELDMAP_GetCommonWork((char *)p, 1);
    func_020307B0((void *)o[9]);
    FIELDMAP_FreeCommonWork(p, 1);
    FLD_EXP_OBJ_RemoveUnit(s, 0);
}
