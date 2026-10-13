/*
 * function: FIELD_GIMMICK_PLATE_DOORS_Exit
 * address: 0x021F39B4
 * packet: pkt_ov038_021F39B4
 * region: ov038
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 */
typedef unsigned short u16;
extern int FIELDMAP_GetExpObj(int *);
extern int *FIELDMAP_GetCommonWork(char *, int);
extern void FIELDMAP_FreeCommonWork(unsigned char *, int);
extern void FLD_EXP_OBJ_RemoveUnit(unsigned char *, u16);
void FIELD_GIMMICK_PLATE_DOORS_Exit(void *p)
{
    int h = FIELDMAP_GetExpObj(p);
    FIELDMAP_GetCommonWork(p, 1);
    FIELDMAP_FreeCommonWork(p, 1);
    FLD_EXP_OBJ_RemoveUnit((unsigned char *)h, 0);
}
