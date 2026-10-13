/*
 * function: FLDMMDL_MOVE_GetFootMarkKind
 * address:  0x02163464
 * packet:   pkt_02163464
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AB4EC  0x021AB4EC  thumb
 *   func_021AB4F8  0x021AB4F8  thumb
 *   func_021AB434  0x021AB434  thumb
 *   func_021AB428  0x021AB428  thumb
 *   MAP_ATTR_IsGrassDouble  0x021AB250  thumb
 *   MAP_ATTR_IsTallGrassSingle  0x021AB264  thumb
 *   MAP_ATTR_IsTallGrassDouble  0x021AB270  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AB4EC();
extern int func_021AB4F8();
extern int func_021AB434();
extern int func_021AB428();
extern int MAP_ATTR_IsGrassDouble();
extern int MAP_ATTR_IsTallGrassSingle();
extern int MAP_ATTR_IsTallGrassDouble();

int FLDMMDL_MOVE_GetFootMarkKind(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = func_021AB4EC(a0);
loc_02163470:
    if (a0 == 0) goto loc_02163478;
loc_02163474:
t4 = 6;
    goto loc_021634D4;
loc_02163478:
a0 = t5 + 0;
    a0 = func_021AB4F8(a0);
loc_0216347E:
    if (a0 == 0) goto loc_02163486;
loc_02163482:
t4 = 7;
    goto loc_021634D4;
loc_02163486:
a0 = t5 + 0;
    a0 = func_021AB434(a0);
loc_0216348C:
    if (a0 == 0) goto loc_0216349A;
loc_02163490:
t4 = 1;
    if (t6 != 3) goto loc_021634D4;
loc_02163496:
t4 = 5;
    goto loc_021634D4;
loc_0216349A:
a0 = t5 + 0;
    a0 = func_021AB428(a0);
loc_021634A0:
    if (a0 == 0) goto loc_021634AC;
loc_021634A4:
    if (t6 != 3) goto loc_021634D4;
loc_021634A8:
t4 = 4;
    goto loc_021634D4;
loc_021634AC:
a0 = t5 + 0;
    a0 = MAP_ATTR_IsGrassDouble(a0);
loc_021634B2:
    if (a0 == 0) goto loc_021634BA;
loc_021634B6:
t4 = 1;
    goto loc_021634D4;
loc_021634BA:
a0 = t5 + 0;
    a0 = MAP_ATTR_IsTallGrassSingle(a0);
loc_021634C0:
    if (a0 == 0) goto loc_021634C8;
loc_021634C4:
t4 = 2;
    goto loc_021634D4;
loc_021634C8:
a0 = t5 + 0;
    a0 = MAP_ATTR_IsTallGrassDouble(a0);
loc_021634CE:
    if (a0 == 0) goto loc_021634D4;
loc_021634D2:
t4 = 3;
loc_021634D4:
a0 = t4 + 0;
    return a0;}
