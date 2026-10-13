/*
 * file:     field_rail.c
 * unit:     yes
 * function: func_021B7884, func_021B791C, func_021B7934, func_021B7954, func_021B7970, func_021B79AC, func_021B79C4, func_021B79CC, func_021B79D4, func_021B79E4, func_021B79F0, func_021B7A84, func_021B7C04, func_021B7C38, func_021B7C58, func_021B7C90, func_021B7CD8, func_021B7D38, func_021B7D50, func_021B7D68, func_021B7DC0, func_021B7DE0, func_021B7E60, func_021B7ED4, func_021B7EE4, func_021B8028, func_021B8038, func_021B8040, func_021B8048, func_021B8050, func_021B80D8, func_021B80E0, func_021B810C, func_021B821C, func_021B8220, func_021B8224, func_021B8230, func_021B823C, func_021B8248, func_021B824C, func_021B8250, func_021B82F0, func_021B82F4, func_021B82F8, func_021B82FC, func_021B8300, func_021B8304, func_021B8308, func_021B830C, func_021B8314, func_021B8328, func_021B833C, func_021B834C, func_021B835C, func_021B836C, func_021B8378, func_021B83B0, func_021B83FC, func_021B8484, func_021B8514, func_021B854C, func_021B8658, func_021B8674, func_021B868C, func_021B86A4, func_021B87BC, func_021B87C8, func_021B87D8, func_021B87FC, func_021B8820, func_021B8848, func_021B8870, func_021B8894, func_021B88B8, func_021B88DC, func_021B9164, func_021B919C, func_021B91A8, func_021B91AC, func_021B91C8, func_021B91F8, func_021B9238, func_021B9278, func_021B9280, func_021B9338, func_021B9368, func_021B93D4, func_021B9404, func_021B9434, func_021B9464, func_021B9478, func_021B949C, func_021B94C0, func_021B94D8, func_021B9510, func_021B9530, func_021B95C0, func_021B960C, func_021B963C, func_021B96AC, func_021B9768, func_021B976C, func_021B977C, func_021B97D0, func_021B97FC, func_021B9828, func_021B9A50, func_021B9B24, func_021B9B7C, func_021B9C28, func_021B9D60, func_021B9E84, func_021B9FC8, func_021BA25C, func_021BA2B4, func_021BA310, func_021BA348, func_021BA494, func_021BA4C4, func_021BA4FC, func_021BA550, func_021BA6E8, func_021BA7B0, func_021BA7E0, func_021BA8E0, func_021BA9B4, func_021BAA30, func_021BAA9C, func_021BAB30, func_021BABB4, func_021BABDC, func_021BAC04, func_021BAC74, func_021BACA8, func_021BAE7C, func_021BB014
 * address:  0x021B7884
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field rail system: the rail manager and rail works, the line shape functions and the rail camera functions.
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021B9164  0x021B9164  thumb
 *   g_021DE2A0     0x021DE2A0  data  a1
 *   func_021B9464  0x021B9464  thumb  ov021
 *   func_021B91A8  0x021B91A8  thumb ov021
 *   func_021B91AC  0x021B91AC  thumb
 *   func_021B8870  0x021B8870  thumb
 *   func_021B9510  0x021B9510  thumb  ov021
 *   func_021B8848  0x021B8848  thumb  ov021
 *   func_021B88B8  0x021B88B8  thumb  ov021
 *   func_021B9828  0x021B9828  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   d_021D9A00     0x021D9A00  data   a4
 *   func_021B94C0  0x021B94C0  thumb ov021
 *   func_021B9478  0x021B9478  thumb ov021
 *   func_021B949C  0x021B949C  thumb ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021B9278  0x021B9278  thumb ov021
 *   func_021B9280  0x021B9280  thumb ov021
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021B919C  0x021B919C  thumb  ov021
 *   func_021B91F8  0x021B91F8  thumb  ov021
 *   func_021B9238  0x021B9238  thumb  ov021
 *   func_021B9368  0x021B9368  thumb  ov021
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_021B88DC  0x021B88DC  thumb  ov021
 *   func_021B977C  0x021B977C  thumb  ov021
 *   d_021DE298     0x021DE298  data
 *   func_021B91C8  0x021B91C8  thumb
 *   func_021B95C0  0x021B95C0  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B963C  0x021B963C  thumb
 *   func_021B9434  0x021B9434  thumb
 *   func_021B9404  0x021B9404  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021D9A0C     0x021D9A0C  data  a4
 *   d_021D9A30     0x021D9A30  data  a4
 *   func_021B8514  0x021B8514  thumb  ov021
 *   func_021B854C  0x021B854C  thumb  ov021
 *   func_021B8674  0x021B8674  thumb  ov021
 *   func_021B868C  0x021B868C  thumb  ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 *   func_021B8820  0x021B8820  thumb  ov021
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 *   func_021B87FC  0x021B87FC  thumb
 *   func_021B86A4  0x021B86A4  thumb
 *   d_021DE2B0     0x021DE2B0  data  a4
 *   d_021DE2B4     0x021DE2B4  data  a4
 *   d_021DE2BC     0x021DE2BC  data  a4
 *   VEC_Mag          0x0207CBD0  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   FX_Div           0x0207C768  arm
 *   _ll_mul          0x0209C054  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   VEC_Add          0x0207C9D0  arm
 *   func_020520A4    0x020520A4  arm
 *   d_020A1B38       0x020A1B38  data   a2
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_021B82F4  0x021B82F4  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B8300  0x021B8300  thumb  ov021
 *   func_021B8308  0x021B8308  thumb  ov021
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_021D9A54     0x021D9A54  data  ov021  a4
 *   func_021B835C  0x021B835C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   d_021D9A60     0x021D9A60  data  a4
 *   func_021B8224  0x021B8224  thumb  ov021
 *   func_021B8230  0x021B8230  thumb  ov021
 *   func_021B823C  0x021B823C  thumb  ov021
 *   func_021B8248  0x021B8248  thumb  ov021
 *   func_021B8250  0x021B8250  thumb  ov021
 *   func_021B8378  0x021B8378  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021B824C  0x021B824C  thumb  ov021
 *   func_021B8304  0x021B8304  thumb  ov021
 *   func_0207CA68  0x0207CA68  arm
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B8314  0x021B8314  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_021B836C  0x021B836C  thumb  ov021
 *   func_021B82F0  0x021B82F0  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_0207CC30  0x0207CC30  arm
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   VEC_Distance      0x0207CF3C  arm
 *   func_021B8328  0x021B8328  thumb  ov021
 *   d_021DE2C4     0x021DE2C4  data  a4
 *   func_0204A298  0x0204A298  arm
 *   func_021B7884  0x021B7884  thumb  ov021
 *   func_0219EF44  0x0219EF44  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 *   func_021B791C  0x021B791C  thumb  ov021
 *   func_0219EF6C  0x0219EF6C  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 *   func_02049030  0x02049030  arm
 *   func_0219EF7C  0x0219EF7C  thumb  ov021
 *   func_0219F018  0x0219F018  thumb  ov021
 *   func_021B7934  0x021B7934  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 *   func_020490A8  0x020490A8  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021B7954  0x021B7954  thumb  ov021
 *   func_0219EFFC  0x0219EFFC  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021B79E4  0x021B79E4  thumb  ov021
 *   func_021B79F0  0x021B79F0  thumb  ov021
 *   func_021B7970  0x021B7970  thumb
 *   func_021B79AC  0x021B79AC  thumb
 *   func_021B79C4  0x021B79C4  thumb  ov021
 *   func_021B79CC  0x021B79CC  thumb  ov021
 *   func_021B7D68  0x021B7D68  thumb ov021
 *   func_021B7C04  0x021B7C04  thumb  ov021
 *   func_02013C9C  0x02013C9C  thumb
 *   func_021B7C58  0x021B7C58  thumb  ov021
 *   d_021DE2E8     0x021DE2E8  data  a4
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 *   d_021D9A6C     0x021D9A6C  data  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021BB778  0x021BB778  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A7C     0x021D9A7C  data  a4
 *   func_021BB088  0x021BB088  thumb  ov021
 *   func_021BB0A4  0x021BB0A4  thumb  ov021
 *   func_021BB0B4  0x021BB0B4  thumb  ov021
 *   func_021BB11C  0x021BB11C  thumb  ov021
 *   func_021BB13C  0x021BB13C  thumb  ov021
 *   func_021BB188  0x021BB188  thumb  ov021
 *   func_021BB1A0  0x021BB1A0  thumb  ov021
 *   func_021BB1AC  0x021BB1AC  thumb  ov021
 *   func_021BB1B8  0x021BB1B8  thumb  ov021
 *   func_021BB1C4  0x021BB1C4  thumb  ov021
 *   func_021BB1D0  0x021BB1D0  thumb  ov021
 *   func_021BB1DC  0x021BB1DC  thumb  ov021
 *   func_021BB1E8  0x021BB1E8  thumb  ov021
 *   func_021BB1F4  0x021BB1F4  thumb  ov021
 *   func_021BB240  0x021BB240  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_021BB278  0x021BB278  thumb  ov021
 *   func_021BB2F8  0x021BB2F8  thumb  ov021
 *   func_021BB348  0x021BB348  thumb  ov021
 *   func_021BB36C  0x021BB36C  thumb  ov021
 *   func_021BB388  0x021BB388  thumb  ov021
 *   func_021BB394  0x021BB394  thumb  ov021
 *   func_021BB3A0  0x021BB3A0  thumb  ov021
 *   func_021BB3AC  0x021BB3AC  thumb  ov021
 *   func_021BB3B8  0x021BB3B8  thumb  ov021
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_021BB3D0  0x021BB3D0  thumb  ov021
 *   func_021BB3DC  0x021BB3DC  thumb  ov021
 *   func_021BB3E8  0x021BB3E8  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021BB484  0x021BB484  thumb  ov021
 *   func_021BB4A8  0x021BB4A8  thumb  ov021
 *   func_021BB4BC  0x021BB4BC  thumb  ov021
 *   func_021BB504  0x021BB504  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 */
#include "field_rail_types.h"

#define FX32_ONE ((int)0x00001000L)
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *mem);
extern s32 func_0203EFC8(const void *a, const void *b, u32 size);
extern void func_02082BCC(void *dst, u32 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern fx32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);

extern void func_021B9164(RailWork *work, FieldRailSetting *setting, RailManager *manager);
extern void func_021B919C(RailWork *work, FieldRailSetting *setting);
extern u16 func_021B91A8(RailWork *work);
extern int func_021B91AC(RailWork *work);
extern RailCamera *func_021B91C8(RailWork *work);
extern void func_021B91F8(RailWork *work, VecFx32 *outPos);
extern void func_021B9238(const RailWork *work, RailLocation *outLocation);
extern int func_021B9278(const RailLine *line, int unitScale, const FieldRailSetting *setting);
extern int func_021B9280(const RailLine *line, u32 offset, u32 length, const FieldRailSetting *setting);
extern int func_021B9368(RailManager *manager, RailLocation *location, u32 key, int steps, VecFx32 *outPos);
extern int func_021B93D4(int key);
extern int func_021B9404(int key);
extern int func_021B9434(int key);
extern RailClosedLines *func_021B9464(RailClosedLines *closedLines);
extern void func_021B9478(RailClosedLines *closedLines, u16 lineIndex);
extern void func_021B949C(RailClosedLines *closedLines, u16 lineIndex);
extern int func_021B94C0(RailClosedLines *closedLines, u16 lineIndex);
extern RailLine *func_021B9510(RailClosedLines *closedLines, FieldRailSetting *setting, u32 lineIndex);
extern int func_021B95C0(RailClosedLines *closedLines, RailLine *line, int lineOffset, int widthOffset,
                         FieldRailSetting *setting, int unitScale);
extern int func_021B963C(RailLine *line, FieldRailSetting *setting);
extern void func_021B977C(RailWork *work);
extern int func_021B9828(VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *d, VecFx32 *e, VecFx32 *out);
extern int func_021B88DC(RailWork *work, int key, int step);

RailManager *func_021B7884(u16 heapId, u32 workMax, struct FieldCamera *fieldCamera);
void func_021B791C(RailManager *manager);
void func_021B7934(RailManager *manager, FieldRailSetting *setting);
u32 func_021B7954(RailManager *manager);
void func_021B7970(RailManager *manager);
int func_021B79AC(RailManager *manager, RailWork *work);
void func_021B79C4(RailManager *manager, RailWork *work);
void func_021B79CC(RailManager *manager);
void func_021B79D4(RailManager *manager, VecFx32 *outPos);
void func_021B79E4(RailManager *manager);
int func_021B79F0(RailManager *manager, int force);
int func_021B7A84(RailManager *manager, const VecFx32 *startPos, const VecFx32 *endPos, RailLocation *outLocation,
                  VecFx32 *outPos);
void func_021B7C04(RailManager *manager, int lineIndex, int enable);
int func_021B7C38(RailManager *manager);
void func_021B7C58(RailManager *manager, FieldRailSetting *setting, u16 railIndex, u16 lineGrid, u16 widthPos,
                   RailLocation *outLocation);
int func_021B7C90(RailManager *manager, RailLocation *location, u16 key, VecFx32 *outPos);
int func_021B7CD8(RailManager *manager, const RailLocation *location, u8 key, RailLocation *outLocation);
void func_021B7D38(RailManager *manager, RailLocation *location, VecFx32 *outPos);
int func_021B7D50(RailManager *manager, RailLocation *location);
void func_021B7D68(RailManager *manager, RailLocation *location);
void func_021B7DC0(RailWork *work, RailLocation * __restrict outLocation);
int func_021B7DE0(RailWork *work, RailLocation *location);
u8 func_021B7E60(RailWork *work, u8 key, RailLocation *outLocation, VecFx32 *outPos);
void func_021B7ED4(RailWork *work, VecFx32 *outPos);
void func_021B7EE4(RailWork *work, const RailLocation *location);
void func_021B8028(RailWork *work, VecFx32 *outPos);
u8 func_021B8038(RailWork *work);
u8 func_021B8040(RailWork *work);
u8 func_021B8048(RailWork *work);
void func_021B8050(RailWork *work, s16 *outStep);
u32 func_021B80D8(RailWork *work);
int func_021B80E0(RailWork *work, u32 speedIndex, u32 stepKey);
void func_021B810C(RailWork *work);
struct FieldCamera *func_021B821C(RailManager *manager);
RailWork *func_021B8220(RailManager *manager);
RailPoint *func_021B8224(RailManager *manager, u32 pointIndex);
RailLine *func_021B8230(RailManager *manager, u32 lineIndex);
RailLinePos *func_021B823C(RailManager *manager, int linePosIndex);
u32 func_021B8248(RailManager *manager);
RailWork *func_021B824C(RailManager *manager);
void func_021B8250(const RailManager *manager, const RailLocation *location, RailLocation *outLocation);
u16 func_021B82F0(RailWork *work);
RailSpot *func_021B82F4(RailWork *work);
u32 func_021B82F8(RailWork *work);
u32 func_021B82FC(RailWork *work);
u32 func_021B8300(RailWork *work);
u32 func_021B8304(RailWork *work);
u32 func_021B8308(RailWork *work);
RailCamera *func_021B830C(RailWork *work);
void func_021B8314(RailWork *work, VecFx32 *outPos);
void func_021B8328(RailWork *work, int lineOffset, VecFx32 *outPos);
RailPoint *func_021B833C(RailWork *work);
RailPoint *func_021B834C(RailWork *work);
RailLinePos *func_021B835C(RailWork *work);
RailCamera *func_021B836C(RailWork *work, RailPoint *point);
int func_021B8378(int x);
int func_021B83B0(const s32 *a, const s32 *b, s32 r);
void func_021B83FC(RailWork *work, u16 *outRailIndex, u16 *outLineGrid, u16 *outWidthGrid);
void func_021B8484(RailWork *work, u32 railIndex, u32 lineGrid, int widthPos);
RailLine *func_021B8514(RailPoint *point, u32 key, FieldRailSetting *setting, RailClosedLines *closedLines, int checkClosed);
int func_021B854C(RailWork *work, RailLine *line, u32 key, int lineOffset, int widthOffset, int lineLength, int widthMax);
void func_021B8658(RailWork *work, RailLine *line, u32 key, u32 lineOffset, u32 widthOffset, u32 lineEnd, u32 widthLimit);
int func_021B8674(FieldRailSetting *setting, RailLine *line, RailPoint *point);
int func_021B868C(FieldRailSetting *setting, RailLine *line, RailPoint *point);
void func_021B86A4(FieldRailSetting *setting, const RailLine *line, int *outLengthLimit, int *outWidthLimit,
                   RailClosedLines *closedLines, int unitScale);
void func_021B87BC(FieldRailSetting *setting);
void func_021B87C8(FieldRailSetting *dst, const FieldRailSetting *src);
RailPoint *func_021B87D8(FieldRailSetting *setting, u32 pointIndex);
RailLine *func_021B87FC(FieldRailSetting *setting, u32 lineIndex);
RailCamera *func_021B8820(FieldRailSetting *setting, u32 cameraIndex);
extern RailLinePos *func_021B8848(FieldRailSetting *setting, u32 linePosIndex);
extern RailCameraFunc func_021B8870(FieldRailSetting *setting, u32 funcIndex);
extern RailLineFunc func_021B88B8(FieldRailSetting *setting, u32 funcIndex);

extern const char g_021DE2A0[];
extern const VecFx32 d_021D9A00;
extern const u8 d_021DE298[];

extern void func_020520A4(const VecFx32 *v, int scale, VecFx32 *dst);
extern void func_0207CEE4(int scale, VecFx32 *a, VecFx32 *b, VecFx32 *c);
extern int func_0207CFB8(int a, int b);
extern int func_0207CC30(s16 *v);
extern fx32 VEC_Mag(const VecFx32 *v);
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
extern u16 FX_AcosIdx(int x);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void func_0218E124(struct FieldCamera *camera, u32 mode);
extern void func_0218ECF4(struct FieldCamera *camera, const VecFx32 *eye);
extern void func_0218EC60(struct FieldCamera *camera);
extern void func_0218ED48(struct FieldCamera *camera, u32 yaw);
extern void func_0218ED34(struct FieldCamera *camera, u16 pitch);
extern void func_0218ED58(struct FieldCamera *camera, u32 distance);
extern void func_0218EC54(struct FieldCamera *camera);
extern void func_0218EC90(struct FieldCamera *camera, const VecFx32 *target);
extern void func_0218ECD4(struct FieldCamera *camera, const VecFx32 *shift);
extern void func_0218F05C(struct FieldCamera *camera);
extern s16 d_020A1B38[];
extern VecFx32 d_021D9A54;
extern VecFx32 d_021D9A60;
extern const char d_021DE2B0[];
extern const char d_021DE2B4[];
extern const char d_021DE2BC[];

RailLinePos *func_021B8848(FieldRailSetting *setting, u32 linePosIndex);
RailCameraFunc func_021B8870(FieldRailSetting *setting, u32 funcIndex);
RailLinePosFunc func_021B8894(FieldRailSetting *setting, u32 funcIndex);
RailLineFunc func_021B88B8(FieldRailSetting *setting, u32 funcIndex);
int func_021B9338(RailWork *work, RailLine *line, u32 lineEnd, int key);
int func_021B94D8(RailClosedLines *closedLines, RailLine *line, FieldRailSetting *setting);
void func_021B9530(RailClosedLines *closedLines, RailWork *work, int lineDelta, int widthDelta, int key);
u32 func_021B960C(RailPoint *point, RailLine *line, FieldRailSetting *setting);
int func_021B96AC(RailPoint *point, FieldRailSetting *setting);
void func_021B9768(const char *label, VecFx32 *pos);
void func_021B976C(const char *prefix, RailPoint *point, const char *suffix);
int func_021B97D0(FieldRailSetting *setting, RailPoint *point);
int func_021B97FC(FieldRailSetting *setting, RailLine *line);
void func_021B9A50(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t);
void func_021B9B24(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t);
void func_021B9B7C(RailWork *work, VecFx32 *outPos);
void func_021B9C28(RailWork *work, VecFx32 *outPos);
void func_021B9D60(RailWork *work, VecFx32 *outPos);
int func_021B9E84(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos);
int func_021B9FC8(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos);
void func_021BA25C(RailManager *manager);
void func_021BA2B4(RailManager *manager);
void func_021BA310(RailManager *manager);
void func_021BA348(RailManager *manager);
void func_021BA494(RailManager *manager);
void func_021BA4C4(RailManager *manager);
void func_021BA4FC(RailManager *manager);
void func_021BA550(RailManager *manager);
void func_021BA6E8(RailManager *manager);
void func_021BA7B0(RailManager *manager);
void func_021BA7E0(RailManager *manager, u16 pitch, int distance, VecFx32 *point);
void func_021BA8E0(RailManager *manager);
void func_021BA9B4(RailManager *manager);
void func_021BAA30(RailManager *manager);
void func_021BAA9C(RailManager *manager);
void func_021BAB30(RailManager *manager);
void func_021BABB4(RailManager *manager);
void func_021BABDC(RailManager *manager);
void func_021BAC04(RailManager *manager);
void func_021BAC74(RailManager *manager);
void func_021BACA8(RailManager *manager);
int func_021BAE7C(RailPoint *startPoint, RailPoint *endPoint, const VecFx32 *pos, VecFx32 *outHit, fx32 *outDist,
                  VecFx32 *outAxis);
void func_021BB014(RailManager *manager, RailWork *work, RailPoint *point);

RailManager *func_021B7884(u16 heapId, u32 workMax, struct FieldCamera *fieldCamera)
{
    u32 i;
    RailManager *manager;

    manager = func_02030734(heapId, 0x74, 1, g_021DE2A0, 302);
    manager->heapId = heapId;
    manager->dataLoaded = 0;
    manager->running = 1;
    manager->fieldCamera = fieldCamera;
    manager->focusWork = 0;
    manager->works = func_02030734(heapId, 0x7c * workMax, 1, g_021DE2A0, 311);
    manager->workCount = workMax;
    for (i = 0; i < workMax; i++)
        func_021B9164(&manager->works[i], &manager->setting, manager);
    manager->probeWork = func_02030734(heapId, 0x7c, 1, g_021DE2A0, 319);
    func_021B9164(manager->probeWork, &manager->setting, manager);
    manager->probeWork->inUse = 1;
    return manager;
}

void func_021B791C(RailManager *manager)
{
    func_020307B0(manager->probeWork);
    func_020307B0(manager->works);
    func_020307B0(manager);
}

void func_021B7934(RailManager *manager, FieldRailSetting *setting)
{
    manager->dataLoaded = 1;
    func_021B9464(&manager->closedLines);
    func_021B87C8(&manager->setting, setting);
}

u32 func_021B7954(RailManager *manager)
{
    manager->dataLoaded = 0;
    func_021B87BC(&manager->setting);
    return (u32)func_021B9464(&manager->closedLines);
}

void func_021B7970(RailManager *manager)
{
    RailWork *found = 0;
    int i;

    for (i = 0; i < manager->workCount; i++) {
        if (func_021B91A8(&manager->works[i]) == 0) {
            found = &manager->works[i];
            break;
        }
    }
    found->inUse = 1;
}

int func_021B79AC(RailManager *manager, RailWork *work)
{
    func_021B9164(work, &manager->setting, manager);
    work->inUse = 0;
    return 0;
}

void func_021B79C4(RailManager *manager, RailWork *work)
{
    manager->focusWork = work;
    manager->forceCamera = 1;
}

void func_021B79CC(RailManager *manager)
{
    manager->focusWork = 0;
}

void func_021B79D4(RailManager *manager, VecFx32 *outPos)
{
    if (manager->focusWork != 0) {
        func_021B8028(manager->focusWork, outPos);
    }
}

void func_021B79E4(RailManager *manager)
{
    if (manager->dataLoaded == 0)
        return;
    if (manager->running)
        return;
}

int func_021B79F0(RailManager *manager, int force)
{
    RailWork *work;
    u32 index;
    RailCameraFunc cameraFunc;

    cameraFunc = 0;
    work = manager->focusWork;
    if (manager->dataLoaded == 0)
        return 0;
    if (manager->running == 0)
        return 0;
    if (work == 0)
        return 0;
    if (func_021B91AC(work) == 0)
        return 0;
    if (func_021B8048(work) == 0 && manager->forceCamera == 0 && force == 0)
        return 0;
    switch (work->mode) {
    case RAIL_WORK_ON_POINT:
        index = work->spot->point.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = func_021B8870(work->setting, func_021B8820(work->setting, index)->funcIndex);
        break;
    case RAIL_WORK_ON_LINE:
        index = work->spot->line.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = func_021B8870(work->setting, func_021B8820(work->setting, index)->funcIndex);
        break;
    }
    if (cameraFunc)
        cameraFunc(manager);
    manager->forceCamera = 0;
    return 1;
}

int func_021B7A84(RailManager *manager, const VecFx32 *startPos, const VecFx32 *endPos, RailLocation *outLocation,
                  VecFx32 *outPos)
{
    VecFx32 hitPos;
    VecFx32 lineDir;
    VecFx32 lineNormal;
    VecFx32 upAxis;
    VecFx32 bestPos;
    VecFx32 segStart;
    VecFx32 segEnd;
    RailLocation bestLocation;
    int i;
    fx32 bestDist;
    int found;
    RailLine *line;
    RailPoint *startPoint;
    RailPoint *endPoint;
    RailLinePos *linePos;
    RailLineFunc lineFunc;
    fx32 dist;

    upAxis = d_021D9A00;
    segStart = *startPos;
    segEnd = *endPos;
    found = 0;
    for (i = 0; i < manager->setting.lineCount; i++) {
        line = func_021B9510(&manager->closedLines, &manager->setting, i);
        if (line == 0) {
            continue;
        }
        startPoint = func_021B87D8(&manager->setting, line->startPoint);
        endPoint = func_021B87D8(&manager->setting, line->endPoint);
        linePos = func_021B8848(&manager->setting, line->linePosIndex);
        VEC_Subtract(&startPoint->pos, &endPoint->pos, &lineDir);
        VEC_CrossProduct(&lineDir, &upAxis, &lineNormal);
        if (func_021B9828(&lineDir, &lineNormal, &endPoint->pos, &segStart, &segEnd, &hitPos) == 0) {
            continue;
        }
        lineFunc = func_021B88B8(&manager->setting, linePos->funcIndex);
        if (lineFunc == 0) {
            continue;
        }
        if (lineFunc(i, manager, &hitPos, outLocation, outPos) == 0) {
            continue;
        }
        if (!found) {
            bestLocation = *outLocation;
            bestPos = *outPos;
            bestDist = VEC_Distance(&segStart, outPos);
            found = 1;
        } else {
            dist = VEC_Distance(&segStart, outPos);
            if (dist < bestDist) {
                bestLocation = *outLocation;
                bestPos = *outPos;
                bestDist = dist;
            }
        }
    }
    if (found) {
        *outLocation = bestLocation;
        *outPos = bestPos;
    }
    return found;
}

void func_021B7C04(RailManager *manager, int lineIndex, int enable)
{
    if (enable == 0) {
        if (func_021B94C0(&manager->closedLines, lineIndex) == 0) {
            func_021B9478(&manager->closedLines, lineIndex);
        }
    } else {
        func_021B949C(&manager->closedLines, lineIndex);
    }
}

int func_021B7C38(RailManager *manager)
{
    return (int)(((s64)manager->setting.unitScale * 0x10000 + 0x800) >> 12);
}

void func_021B7C58(RailManager *manager, FieldRailSetting *setting, u16 railIndex, u16 lineGrid, u16 widthPos,
                   RailLocation *outLocation)
{
    RailWork *probe = manager->probeWork;
    probe->setting = setting;
    outLocation->railIndex = railIndex;
    outLocation->type = 1;
    outLocation->widthGrid = 0;
    outLocation->lineGrid = lineGrid;
    func_021B7EE4(probe, outLocation);
    outLocation->widthGrid = widthPos - probe->widthLimit / 16;
    probe->setting = &manager->setting;
}

int func_021B7C90(RailManager *manager, RailLocation *location, u16 key, VecFx32 *outPos)
{
    func_021B7EE4(manager->probeWork, location);
    func_021B80E0(manager->probeWork, 4, key);
    func_021B810C(manager->probeWork);
    func_021B8028(manager->probeWork, outPos);
    if (func_0203EFC8(location, &manager->probeWork->location, 8) == 0)
        return 0;
    return func_021B7DE0(manager->probeWork, &manager->probeWork->location);
}

int func_021B7CD8(RailManager *manager, const RailLocation *location, u8 key, RailLocation *outLocation)
{
    RailLocation startLocation = *location;
    func_021B7EE4(manager->probeWork, location);
    func_021B80E0(manager->probeWork, 4, key);
    func_021B810C(manager->probeWork);
    func_021B7DC0(manager->probeWork, outLocation);
    if (func_0203EFC8(&startLocation, outLocation, 8) == 0)
        return 0;
    return func_021B7DE0(manager->probeWork, outLocation);
}

void func_021B7D38(RailManager *manager, RailLocation *location, VecFx32 *outPos)
{
    func_021B7EE4(manager->probeWork, location);
    func_021B8028(manager->probeWork, outPos);
}

int func_021B7D50(RailManager *manager, RailLocation *location)
{
    func_021B7EE4(manager->probeWork, location);
    return manager->probeWork->widthLimit / 16;
}

void func_021B7D68(RailManager *manager, RailLocation *location)
{
    RailCameraFunc cameraFunc;
    RailWork *prevFocus;
    RailWork *work;
    u32 index;

    cameraFunc = 0;
    func_021B7EE4(manager->probeWork, location);
    prevFocus = manager->focusWork;
    work = manager->probeWork;
    manager->focusWork = work;
    switch (work->mode) {
    case RAIL_WORK_ON_POINT:
        index = work->spot->point.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = func_021B8870(work->setting, func_021B8820(work->setting, index)->funcIndex);
        break;
    case RAIL_WORK_ON_LINE:
        index = work->spot->line.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = func_021B8870(work->setting, func_021B8820(work->setting, index)->funcIndex);
        break;
    }
    if (cameraFunc)
        cameraFunc(manager);
    manager->focusWork = prevFocus;
}

/*
 * The out parameter is __restrict: it lets the scheduler pair the last two
 * halfword loads ahead of their stores (see docs/idioms/a-restrict-table-parameter-
 * hoists-a-load-above-a-store-only-at-a-different-offset.md).
 */
void func_021B7DC0(RailWork *work, RailLocation * __restrict outLocation)
{
    *outLocation = work->location;
}

int func_021B7DE0(RailWork *work, RailLocation *location)
{
    FieldRailSetting *setting;
    u8 *lines;
    int off;
    int x;
    int y;
    int length;
    int width;
    int pad;

    if (location->type == 0) {
        if (location->railIndex >= work->setting->pointCount) {
            return 0;
        }
    } else {
        setting = work->setting;
        if (location->railIndex >= setting->lineCount) {
            return 0;
        }
        lines = (u8 *)setting->lines;
        off = location->railIndex * 0x48;
        pad = 0;
        x = location->lineGrid << 4;
        y = location->widthGrid << 4;
        length = func_021B9278((RailLine *)(lines + (off + pad)), work->unitScale, setting);
        width = func_021B9280((RailLine *)(lines + off), x, length, work->setting);
        if (-width > y || y > width) {
            return 0;
        }
        if (x > length || x < 0) {
            return 0;
        }
    }
    return 1;
}

u8 func_021B7E60(RailWork *work, u8 key, RailLocation *outLocation, VecFx32 *outPos)
{
    if (work->queryValid == 0 || key != work->queryKey) {
        work->queryResult = func_021B7CD8(work->manager, &work->location, key, &work->queryLocation);
        func_021B7D38(work->manager, &work->queryLocation, &work->queryPos);
        work->queryValid = 1;
        work->queryKey = key;
    }
    if (outLocation != 0)
        MI_CpuCopy8(&work->queryLocation, outLocation, 8);
    if (outPos != 0)
        *outPos = work->queryPos;
    return work->queryResult;
}

void func_021B7ED4(RailWork *work, VecFx32 *outPos)
{
    *outPos = work->prevPos;
}

void func_021B7EE4(RailWork *work, const RailLocation *location)
{
    RailLine *line;
    int i;
    u32 lineLength;
    u32 lineOffset;
    u32 widthOffset;
    u32 key;
    u32 lineGrid;

    line = 0;
    func_021B919C(work, work->setting);
    if (location->type == 0) {
        work->mode = RAIL_WORK_ON_POINT;
        work->spot = (RailSpot *)&work->setting->points[location->railIndex];
        work->widthLimit = work->spot->point.lineWidth[0];
        for (i = 0; i < 4; i++) {
            if (work->spot->point.lineIndex[i] != RAIL_NONE_INDEX && line == 0) {
                line = &work->setting->lines[work->spot->point.lineIndex[i]];
                if (line->startPoint == location->railIndex) {
                    lineOffset = 0;
                    widthOffset = 0;
                    key = work->spot->point.lineKey[i];
                } else if (line->endPoint == location->railIndex) {
                    lineOffset = func_021B9278(line, work->unitScale, work->setting);
                    widthOffset = 0;
                    key = work->spot->point.lineKey[i];
                }
            }
        }
    } else {
        line = &work->setting->lines[location->railIndex];
        lineGrid = location->lineGrid;
        if (lineGrid >= line->length) {
            lineGrid--;
        }
        lineOffset = lineGrid << 4;
        widthOffset = location->widthGrid << 4;
        key = location->key;
    }
    lineLength = func_021B9278(line, work->unitScale, work->setting);
    func_021B8658(work, line, key, lineOffset, widthOffset, lineLength,
                  func_021B9280(line, lineOffset, lineLength, work->setting));
    work->lastSpeedIndex = 1;
    work->lastKey = key;
    work->located = 1;
    func_021B91F8(work, &work->pos);
    work->location = *location;
    work->prevLocation = *location;
    work->prevPos = work->pos;
}

void func_021B8028(RailWork *work, VecFx32 *outPos)
{
    *outPos = work->pos;
}

u8 func_021B8038(RailWork *work)
{
    return work->lastKey;
}

u8 func_021B8040(RailWork *work)
{
    return work->moving;
}

u8 func_021B8048(RailWork *work)
{
    return work->stepped;
}

static inline void storeVecS16(s16 *dst, int x, int y, int z)
{
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

void func_021B8050(RailWork *work, s16 *outStep)
{
    VecFx32 curPos;
    VecFx32 nextPos;
    RailLocation nextLocation;
    s32 lineOffset;
    s32 lineEnd;
    s32 endOffset;
    u32 savedWidthOffset;

    savedWidthOffset = work->widthOffset;
    work->widthOffset = 0;
    func_021B91F8(work, &curPos);
    lineOffset = work->lineOffset;
    work->widthOffset = savedWidthOffset;
    lineEnd = work->lineEnd;
    endOffset = lineOffset + 0x10;
    if (endOffset < lineEnd) {
        work->lineOffset += 0x10;
        work->widthOffset = 0;
        func_021B91F8(work, &nextPos);
        work->widthOffset = savedWidthOffset;
        work->lineOffset = lineOffset;
    } else {
        func_021B9238(work, &nextLocation);
        nextLocation.widthGrid = 0;
        func_021B9368(work->manager, &nextLocation, work->spot->line.key, endOffset - lineEnd, &nextPos);
    }
    VEC_Subtract(&nextPos, &curPos, &nextPos);
    VEC_Normalize(&nextPos, &nextPos);
    storeVecS16(outStep, nextPos.x, nextPos.y, nextPos.z);
}

u32 func_021B80D8(RailWork *work)
{
    RailSpot *spot = work->spot;
    return spot->line.key;
}

int func_021B80E0(RailWork *work, u32 speedIndex, u32 stepKey)
{
    if (work->moving == 0) {
        work->moving = 1;
        work->stepProgress = 0;
        work->stepKey = stepKey;
        work->speedIndex = speedIndex;
        return 1;
    }
    return 0;
}

/*
 * The table byte is also func_021B88DC's third argument: the callee's
 * matched prototype is (p, dir, d), and the image leaves the ldrb value in
 * r2 untouched up to the call. That extra use keeps the byte live across
 * the stepProgress update, so its sign extension lands in a fresh register (r3).
 * See docs/idioms/a-byte-kept-live-into-a-call-argument-register-pushes-its-sign-extension-to-a-fresh-register.md.
 */
void func_021B810C(RailWork *work)
{
    int newKey;
    u16 prevMode;
    u16 stepKey;
    u8 stepSize;
    s32 remainder;

    if (work->manager->dataLoaded == 0)
        return;
    if (work->located == 0)
        return;
    if (func_021B91AC(work) == 0)
        return;
    newKey = 0;
    work->stepped = 0;
    if (work->moving == 0)
        return;
    prevMode = work->mode;
    stepKey = work->stepKey;
    stepSize = d_021DE298[work->speedIndex];
    work->stepProgress += (s8)stepSize;
    if (prevMode == RAIL_WORK_ON_LINE)
        newKey = func_021B88DC(work, stepKey, stepSize);
    if (newKey != 0) {
        work->lastKey = newKey;
        work->lastSpeedIndex = work->speedIndex;
        work->stepped = 1;
        func_021B91F8(work, &work->pos);
    }
    if (prevMode != work->mode)
        func_021B977C(work);
    if (work->stepProgress < 0x10 && newKey != 0)
        return;
    work->moving = 0;
    work->queryValid = 0;
    work->prevLocation = work->location;
    func_021B9238(work, &work->location);
    work->prevPos = work->pos;
    remainder = work->lineOffset % 16;
    if (remainder == 0)
        return;
    if (remainder > 8)
        work->lineOffset = work->lineOffset + (16 - remainder);
    else
        work->lineOffset = work->lineOffset - remainder;
}

struct FieldCamera *func_021B821C(RailManager *manager)
{
    return manager->fieldCamera;
}

RailWork *func_021B8220(RailManager *manager)
{
    return manager->focusWork;
}

RailPoint *func_021B8224(RailManager *manager, u32 pointIndex)
{
    return func_021B87D8(&manager->setting, pointIndex);
}

RailLine *func_021B8230(RailManager *manager, u32 lineIndex)
{
    return func_021B87FC(&manager->setting, lineIndex);
}

RailLinePos *func_021B823C(RailManager *manager, int linePosIndex)
{
    return func_021B8848(&manager->setting, linePosIndex);
}

u32 func_021B8248(RailManager *manager)
{
    return manager->setting.unitScale;
}

RailWork *func_021B824C(RailManager *manager)
{
    return manager->probeWork;
}

/*
 * Twin of func_021B7DE0. The first call adds a zero-valued local to off,
 * which gives the early multiply, the spilled offset and the
 * `adds r0,r3,#0` copy. `const RailManager *manager` lets the base load schedule into the
 * struct copy (`ldr r7,[r6,#0x34]` between the stores to location).
 */
void func_021B8250(const RailManager *manager, const RailLocation *location, RailLocation *outLocation)
{
    RailLocation loc;
    u8 *lines;
    s32 off;
    s32 x;
    s32 y;
    s32 length;
    s32 width;
    s32 pad;

    loc = *location;
    lines = (u8 *)manager->setting.lines;
    *outLocation = loc;
    off = loc.railIndex * 0x48;
    pad = 0;
    y = loc.lineGrid << 4;
    x = loc.widthGrid << 4;
    length = func_021B9278((RailLine *)(lines + (off + pad)), manager->setting.unitScale, &manager->setting);
    width = func_021B9280((RailLine *)(lines + off), y, length, &manager->setting);
    if (y >= length)
        outLocation->lineGrid = (length - 1) / 16;
    if ((x < 0 ? -x : x) > width) {
        if (x > 0)
            outLocation->widthGrid = width / 16;
        else
            outLocation->widthGrid = -width / 16;
    }
}

u16 func_021B82F0(RailWork *work)
{
    return work->mode;
}

RailSpot *func_021B82F4(RailWork *work)
{
    return work->spot;
}

u32 func_021B82F8(RailWork *work)
{
    return work->lineOffset;
}

u32 func_021B82FC(RailWork *work)
{
    return work->lineEnd;
}

u32 func_021B8300(RailWork *work)
{
    return work->widthOffset;
}

u32 func_021B8304(RailWork *work)
{
    return work->widthLimit;
}

u32 func_021B8308(RailWork *work)
{
    return work->unitScale;
}

RailCamera *func_021B830C(RailWork *work)
{
    return func_021B91C8(work);
}

void func_021B8314(RailWork *work, VecFx32 *outPos)
{
    int savedWidthOffset = work->widthOffset;
    work->widthOffset = 0;
    func_021B91F8(work, outPos);
    work->widthOffset = savedWidthOffset;
}

void func_021B8328(RailWork *work, int lineOffset, VecFx32 *outPos)
{
    int savedLineOffset = work->lineOffset;
    work->lineOffset = lineOffset;
    func_021B91F8(work, outPos);
    work->lineOffset = savedLineOffset;
}

RailPoint *func_021B833C(RailWork *work)
{
    return func_021B87D8(work->setting, work->spot->line.startPoint);
}

RailPoint *func_021B834C(RailWork *work)
{
    return func_021B87D8(work->setting, work->spot->line.endPoint);
}

RailLinePos *func_021B835C(RailWork *work)
{
    return func_021B8848(work->setting, work->spot->line.linePosIndex);
}

RailCamera *func_021B836C(RailWork *work, RailPoint *point)
{
    return func_021B8820(work->setting, point->cameraIndex);
}

int func_021B8378(int x)
{
    u32 ax = x < 0 ? -x : x;
    if ((ax & 15) >= 8) {
        if (x >= 0) {
            return x / 16 + 1;
        } else {
            return x / 16 - 1;
        }
    }
    return x / 16;
}

int func_021B83B0(const s32 *a, const s32 *b, s32 r)
{
    s32 dx, dz, dy, rr, d2, r2;
    dx = (a[0] >> 12) - (b[0] >> 12);
    dz = (a[2] >> 12) - (b[2] >> 12);
    d2 = dx * dx + dz * dz;
    dy = a[1] - b[1];
    if (dy < 0)
        dy = -dy;
    rr = (r >> 12) * 2;
    r2 = rr * rr;
    if (dy < 0x8000 && d2 < r2)
        return 1;
    return 0;
}

void func_021B83FC(RailWork *work, u16 *outRailIndex, u16 *outLineGrid, u16 *outWidthGrid)
{
    s32 index, i, width, widthEnd;
    width = func_021B9280((RailLine *)work->spot, 0, work->lineEnd, work->setting);
    widthEnd = func_021B9280((RailLine *)work->spot, work->lineEnd, work->lineEnd, work->setting);
    if (width < widthEnd)
        width = widthEnd;
    index = 0;
    for (i = 0; i < work->setting->lineCount; i++) {
        if ((RailLine *)work->spot == work->setting->lines + i)
            index = i;
    }
    *outRailIndex = index;
    *outLineGrid = work->lineOffset / 16;
    *outWidthGrid = work->widthOffset / 16 + width / 16;
}

void func_021B8484(RailWork *work, u32 railIndex, u32 lineGrid, int widthPos)
{
    RailLocation location;

    func_021B7DC0(work, &location);
    location.railIndex = railIndex;
    location.widthGrid = 0;
    location.lineGrid = lineGrid;
    func_021B7EE4(work, &location);
    location.widthGrid = widthPos - work->widthLimit / 16;
    func_021B91F8(work, &work->pos);
    work->location = location;
    work->prevLocation = location;
    work->prevPos = work->pos;
}

RailLine *func_021B8514(RailPoint *point, u32 key, FieldRailSetting *setting, RailClosedLines *closedLines, int checkClosed)
{
    int i;
    /* stand-in: the point is indexed as one word array (key at i + 4, line at i);
     * the field form point->lineKey[i] folds into a strided pointer and is 4 bytes shorter. */
    for (i = 0; i < 4; i++) {
        if (key == ((u32 *)point)[i + 4]) {
            if (checkClosed)
                return func_021B9510(closedLines, setting, ((u32 *)point)[i]);
            return func_021B87FC(setting, ((u32 *)point)[i]);
        }
    }
    return 0;
}

/*
 * closed 2026-09-27 (tree_ov018): the early exit is one guard,
 * if (lineOffset < lineLength && lineOffset >= 0) goto tail; ahead of a plain if/else for the
 * two row lookups, and lineLength is reassigned in place of a separate local.
 */
int func_021B854C(RailWork *work, RailLine *line, u32 key, int lineOffset, int widthOffset, int lineLength, int widthMax)
{
    RailLine *nextLine;
    if (func_021B95C0(work->closedLines, line, lineOffset, widthOffset, work->setting, work->unitScale) == 0)
        return 0;
    if ((widthOffset < 0 ? -widthOffset : widthOffset) > widthMax)
        return 0;
    if (lineOffset < lineLength && lineOffset >= 0)
        goto tail;
    if (lineOffset >= lineLength) {
        RailPoint *point = func_021B87D8(work->setting, line->endPoint);
        nextLine = func_021B8514(point, line->key, work->setting, work->closedLines, 1);
    } else {
        RailPoint *point = func_021B87D8(work->setting, line->startPoint);
        nextLine = func_021B8514(point, func_021B93D4(line->key), work->setting, work->closedLines, 1);
    }
    if (nextLine == 0) {
        if (lineOffset > lineLength)
            return 0;
        goto tail;
    }
    line = nextLine;
    if (lineOffset >= lineLength) {
        lineOffset -= lineLength;
        lineLength = func_021B9278(nextLine, work->unitScale, work->setting);
        widthMax = func_021B9280(nextLine, lineOffset, lineLength, work->setting);
    } else if (lineOffset < 0) {
        lineLength = func_021B9278(nextLine, work->unitScale, work->setting);
        lineOffset += lineLength;
        widthMax = func_021B9280(nextLine, lineOffset, lineLength, work->setting);
    }
    if (lineOffset >= lineLength)
        return 0;
    if ((widthOffset < 0 ? -widthOffset : widthOffset) > widthMax)
        return 0;
tail:
    func_021B8658(work, line, key, lineOffset, widthOffset, lineLength, widthMax);
    func_021B963C(line, work->setting);
    return key;
}

void func_021B8658(RailWork *work, RailLine *line, u32 key, u32 lineOffset, u32 widthOffset, u32 lineEnd, u32 widthLimit)
{
    work->mode = RAIL_WORK_ON_LINE;
    work->spot = (RailSpot *)line;
    work->widthOffset = widthOffset;
    work->lineEnd = lineEnd;
    work->moveKey = key;
    work->lineOffset = lineOffset;
    work->widthLimit = widthLimit;
}

int func_021B8674(FieldRailSetting *setting, RailLine *line, RailPoint *point)
{
    return func_021B87D8(setting, line->startPoint) == point;
}

int func_021B868C(FieldRailSetting *setting, RailLine *line, RailPoint *point)
{
    return func_021B87D8(setting, line->endPoint) == point;
}

/*
 * Scores three neighbouring cells (row from func_021B87D8, then one
 * func_021B8514 lookup per direction) against the start cell line.
 * line is read through a const pointer: with a plain pointer the outgoing
 * flag store `str r6, [sp]` lands before `adds r2, r5` in the first two
 * func_021B8514 calls (8 bytes).  Declaration order of point/lengthLimit sets their
 * stack slots (lengthLimit at sp+0xc, point at sp+0x10).
 */
void func_021B86A4(FieldRailSetting *setting, const RailLine *line, int *outLengthLimit, int *outWidthLimit,
                   RailClosedLines *closedLines, int unitScale)
{
    RailPoint *point;
    int lengthLimit;
    RailLine *oppositeLine;
    RailLine *previousLine;
    RailLine *nextLine;
    int widthLimit;
    int length;
    int limit;

    lengthLimit = 0;
    point = func_021B87D8(setting, line->startPoint);
    oppositeLine = func_021B8514(point, func_021B93D4(line->key), setting, closedLines, 1);
    previousLine = func_021B8514(point, func_021B9434(line->key), setting, closedLines, 1);
    nextLine = func_021B8514(point, func_021B9404(line->key), setting, closedLines, 1);
    widthLimit = func_021B9280(line, 0, func_021B9278(line, unitScale, setting), setting);
    if (oppositeLine) {
        length = func_021B9278(oppositeLine, unitScale, setting);
        limit = func_021B9280(oppositeLine, length, length, setting);
        if (limit > widthLimit)
            widthLimit = limit;
    }
    if (previousLine) {
        length = func_021B9278(previousLine, unitScale, setting);
        if (func_021B8674(setting, previousLine, point))
            limit = func_021B9280(previousLine, 0, length, setting);
        else
            limit = func_021B9280(previousLine, length, length, setting);
        if (limit > lengthLimit)
            lengthLimit = limit;
    }
    if (nextLine) {
        length = func_021B9278(nextLine, unitScale, setting);
        if (func_021B8674(setting, nextLine, point))
            limit = func_021B9280(nextLine, 0, length, setting);
        else
            limit = func_021B9280(nextLine, length, length, setting);
        if (limit > lengthLimit)
            lengthLimit = limit;
    }
    *outLengthLimit = lengthLimit;
    *outWidthLimit = widthLimit;
}

void func_021B87BC(FieldRailSetting *setting)
{
    func_02082BCC(setting, 0, 48);
}

void func_021B87C8(FieldRailSetting *dst, const FieldRailSetting *src)
{
    MI_CpuCopy8(src, dst, 0x30);
}

RailPoint *func_021B87D8(FieldRailSetting *setting, u32 pointIndex)
{
    if (setting->pointCount > pointIndex)
        return &setting->points[pointIndex];
    if (pointIndex == RAIL_NONE_INDEX)
        return 0;
    return setting->points;
}

RailLine *func_021B87FC(FieldRailSetting *setting, u32 lineIndex)
{
    if (setting->lineCount > lineIndex)
        return &setting->lines[lineIndex];
    if (lineIndex == RAIL_NONE_INDEX)
        return 0;
    return setting->lines;
}

RailCamera *func_021B8820(FieldRailSetting *setting, u32 cameraIndex)
{
    if (setting->cameraCount > cameraIndex) {
        return &setting->cameras[cameraIndex];
    }
    if (cameraIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return &d_021D9A0C;
}

RailLinePos *func_021B8848(FieldRailSetting *setting, u32 linePosIndex)
{
    if (setting->linePosCount > linePosIndex) {
        return &setting->linePoses[linePosIndex];
    }
    if (linePosIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return &d_021D9A30;
}

RailCameraFunc func_021B8870(FieldRailSetting *setting, u32 funcIndex)
{
    if (setting->cameraFuncCount > funcIndex) {
        return setting->cameraFuncs[funcIndex];
    }
    if (funcIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return setting->cameraFuncs[0];
}

RailLinePosFunc func_021B8894(FieldRailSetting *setting, u32 funcIndex)
{
    if (setting->linePosFuncCount > funcIndex) {
        return setting->linePosFuncs[funcIndex];
    }
    if (funcIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return setting->linePosFuncs[0];
}

RailLineFunc func_021B88B8(FieldRailSetting *setting, u32 funcIndex)
{
    if (setting->lineFuncCount > funcIndex) {
        return setting->lineFuncs[funcIndex];
    }
    if (funcIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return setting->lineFuncs[0];
}

/*
 * closed 2026-10-02 (share-A lane A2-09).  Three source facts turned the
 * 2026-09-27 near miss (lineEnd spilled, frame 0x54) into the image's allocation
 * (lineEnd in r7 for the whole body, frame 0x6c):
 *  - arm 93D4: reachedEnd = 0 is assigned after the 9404 call, through a local
 *    (r = 9404(dir); reachedEnd = 0; e1 = 8514(row, r, ...)); with reachedEnd = 0 ahead
 *    of the nested call, reachedEnd takes r6 and lineEnd is spilled.
 *  - arm 93D4: the lineTurnB probe is two sequential ifs (8674, then 868C), not an
 *    else-if as in the other two-way probes of arms f08/93D4.
 *  - arms 9404/9434: each half has its own point/line locals; in arm 9434 the two
 *    spilled 8674-path lengths are block-level locals declared second-half
 *    first (the image has the first half's at the lower slot).
 * Arm-subset compiles (only f08, f08+9404, f08+9434) matched the image's
 * allocation exactly, which isolated the 93D4 arm as the cause.
 */
int func_021B88DC(RailWork *work, int key, int step)
{
    int lineEnd;
    RailLine *line;
    int result;

    line = &work->spot->line;
    lineEnd = work->lineEnd;
    if (key == line->key) {
        RailPoint *point;
        RailLine *lineAhead;
        RailLine *lineTurnA;
        RailLine *lineTurnB;
        int reachedEnd;

        point = func_021B87D8(work->setting, line->endPoint);
        reachedEnd = 0;
        lineAhead = func_021B8514(point, key, work->setting, work->closedLines, reachedEnd);
        lineTurnA = func_021B8514(point, func_021B9434(key), work->setting, work->closedLines, reachedEnd);
        lineTurnB = func_021B8514(point, func_021B9404(key), work->setting, work->closedLines, reachedEnd);
        func_021B9530(work->closedLines, work, step, 0, key);
        if (work->lineOffset < lineEnd) {
            result = func_021B9280(line, work->lineOffset, lineEnd, work->setting);
            if (result >= (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset)) {
                return key;
            }
            reachedEnd = 1;
        }
        if (lineAhead != 0 && reachedEnd == 0) {
            int lineLength;
            int widthMax;
            func_021B96AC(point, work->setting);
            lineLength = func_021B9278(lineAhead, work->unitScale, work->setting);
            widthMax = func_021B9280(lineAhead, work->lineOffset - lineEnd, lineLength, work->setting);
            result = func_021B854C(work, lineAhead, key, work->lineOffset - lineEnd, work->widthOffset, lineLength, widthMax);
            if (result != 0) {
                return result;
            }
        }
        if (lineTurnA != 0 && work->widthOffset <= 0) {
            if (func_021B8674(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnA, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnA, -work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnA, key, -work->widthOffset, work->lineOffset - lineEnd, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            } else if (func_021B868C(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnA, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnA, lineLength + work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnA, key, lineLength + work->widthOffset, -(work->lineOffset - lineEnd), lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (lineTurnB != 0 && work->widthOffset >= 0) {
            if (func_021B8674(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnB, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnB, work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnB, key, work->widthOffset, -(work->lineOffset - lineEnd), lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            } else if (func_021B868C(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnB, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnB, lineLength - work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnB, key, lineLength - work->widthOffset, work->lineOffset - lineEnd, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (reachedEnd) {
            return func_021B9338(work, line, lineEnd, key);
        }
        if (work->lineOffset <= lineEnd) {
            return key;
        }
        work->lineOffset = work->lineOffset - step;
        return 0;
    } else if (key == func_021B93D4(line->key)) {
        RailPoint *point;
        RailLine *lineTurnA;
        RailLine *lineTurnB;
        RailLine *lineAhead;
        int reachedEnd;

        point = func_021B87D8(work->setting, line->startPoint);
        result = func_021B9404(key);
        reachedEnd = 0;
        lineTurnA = func_021B8514(point, result, work->setting, work->closedLines, reachedEnd);
        lineTurnB = func_021B8514(point, func_021B9434(key), work->setting, work->closedLines, reachedEnd);
        lineAhead = func_021B8514(point, key, work->setting, work->closedLines, reachedEnd);
        func_021B9530(work->closedLines, work, -step, 0, key);
        if (work->lineOffset >= 0) {
            result = func_021B9280(line, work->lineOffset, lineEnd, work->setting);
            if (result >= (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset)) {
                return key;
            }
            reachedEnd = 1;
        }
        if (lineAhead != 0 && reachedEnd == 0) {
            int lineLength;
            int widthMax;
            func_021B96AC(point, work->setting);
            lineLength = func_021B9278(lineAhead, work->unitScale, work->setting);
            widthMax = func_021B9280(lineAhead, lineLength - (work->lineOffset < 0 ? -work->lineOffset : work->lineOffset), lineLength, work->setting);
            result = func_021B854C(work, lineAhead, key, lineLength - (work->lineOffset < 0 ? -work->lineOffset : work->lineOffset), work->widthOffset, lineLength, widthMax);
            if (result != 0) {
                return result;
            }
        }
        if (lineTurnA != 0 && work->widthOffset <= 0) {
            if (func_021B8674(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnA, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnA, -work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnA, key, -work->widthOffset, work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            } else if (func_021B868C(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnA, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnA, lineLength + work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnA, key, lineLength + work->widthOffset, -work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (lineTurnB != 0 && work->widthOffset >= 0) {
            if (func_021B8674(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnB, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnB, work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnB, key, work->widthOffset, -work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
            if (func_021B868C(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                func_021B96AC(point, work->setting);
                lineLength = func_021B9278(lineTurnB, work->unitScale, work->setting);
                widthMax = func_021B9280(lineTurnB, lineLength - work->widthOffset, lineLength, work->setting);
                result = func_021B854C(work, lineTurnB, key, lineLength - work->widthOffset, work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (reachedEnd) {
            return func_021B9338(work, line, lineEnd, key);
        }
        work->lineOffset = work->lineOffset + step;
        return 0;
    } else if (key == func_021B9404(line->key)) {
        func_021B9530(work->closedLines, work, 0, step, key);
        if (work->widthOffset > 0 && work->widthOffset % 16 == 0) {
            RailPoint *point;
            RailLine *lineAhead;
            RailPoint *farPoint;
            RailLine *farLine;

            point = func_021B87D8(work->setting, line->startPoint);
            lineAhead = func_021B8514(point, key, work->setting, work->closedLines, 0);
            if (lineAhead != 0) {
                if (func_021B8674(work->setting, lineAhead, point)) {
                    int lineLength;
                    int widthMax;
                    func_021B96AC(point, work->setting);
                    lineLength = func_021B9278(lineAhead, work->unitScale, work->setting);
                    widthMax = func_021B9280(lineAhead, work->widthOffset, lineLength, work->setting);
                    result = func_021B854C(work, lineAhead, key, work->widthOffset, -work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (func_021B868C(work->setting, lineAhead, point)) {
                    int lineLength;
                    int widthMax;
                    func_021B96AC(point, work->setting);
                    lineLength = func_021B9278(lineAhead, work->unitScale, work->setting);
                    widthMax = func_021B9280(lineAhead, lineLength - work->widthOffset, lineLength, work->setting);
                    result = func_021B854C(work, lineAhead, key, lineLength - work->widthOffset, work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
            farPoint = func_021B87D8(work->setting, line->endPoint);
            farLine = func_021B8514(farPoint, key, work->setting, work->closedLines, 0);
            if (farLine != 0) {
                if (func_021B8674(work->setting, farLine, farPoint)) {
                    int lineLength;
                    int widthMax;
                    func_021B96AC(farPoint, work->setting);
                    lineLength = func_021B9278(farLine, work->unitScale, work->setting);
                    widthMax = func_021B9280(farLine, work->widthOffset, lineLength, work->setting);
                    result = func_021B854C(work, farLine, key, work->widthOffset, lineEnd - work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (func_021B868C(work->setting, farLine, farPoint)) {
                    int lineLength;
                    int widthMax;
                    func_021B96AC(farPoint, work->setting);
                    lineLength = func_021B9278(farLine, work->unitScale, work->setting);
                    widthMax = func_021B9280(farLine, lineLength - work->widthOffset, lineLength, work->setting);
                    result = func_021B854C(work, farLine, key, lineLength - work->widthOffset, -(lineEnd - work->lineOffset), lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
        }
        if (work->widthOffset > 0 && work->widthOffset <= work->widthLimit) {
            return func_021B9338(work, line, lineEnd, key);
        }
        return key;
    } else if (key == func_021B9434(line->key)) {
        func_021B9530(work->closedLines, work, 0, -step, key);
        if (work->widthOffset < 0 && (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset) % 16 == 0) {
            RailPoint *point;
            RailLine *lineAhead;
            RailPoint *farPoint;
            RailLine *farLine;
            int farLength;
            int aheadLength;

            point = func_021B87D8(work->setting, line->startPoint);
            lineAhead = func_021B8514(point, key, work->setting, work->closedLines, 0);
            if (lineAhead != 0) {
                if (func_021B8674(work->setting, lineAhead, point)) {
                    int widthMax;
                    func_021B96AC(point, work->setting);
                    aheadLength = func_021B9278(lineAhead, work->unitScale, work->setting);
                    widthMax = func_021B9280(lineAhead, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), aheadLength, work->setting);
                    result = func_021B854C(work, lineAhead, key, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), work->lineOffset, aheadLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (func_021B868C(work->setting, lineAhead, point)) {
                    int lineLength;
                    int widthMax;
                    func_021B96AC(point, work->setting);
                    lineLength = func_021B9278(lineAhead, work->unitScale, work->setting);
                    widthMax = func_021B9280(lineAhead, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), lineLength, work->setting);
                    result = func_021B854C(work, lineAhead, key, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), -work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
            farPoint = func_021B87D8(work->setting, line->endPoint);
            farLine = func_021B8514(farPoint, key, work->setting, work->closedLines, 0);
            if (farLine != 0) {
                if (func_021B8674(work->setting, farLine, farPoint)) {
                    int widthMax;
                    func_021B96AC(farPoint, work->setting);
                    farLength = func_021B9278(farLine, work->unitScale, work->setting);
                    widthMax = func_021B9280(farLine, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), farLength, work->setting);
                    result = func_021B854C(work, farLine, key, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), -(lineEnd - work->lineOffset), farLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (func_021B868C(work->setting, farLine, farPoint)) {
                    int lineLength;
                    int widthMax;
                    func_021B96AC(farPoint, work->setting);
                    lineLength = func_021B9278(farLine, work->unitScale, work->setting);
                    widthMax = func_021B9280(farLine, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), lineLength, work->setting);
                    result = func_021B854C(work, farLine, key, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), lineEnd - work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
        }
        if (work->widthOffset < 0 && (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset) <= work->widthLimit) {
            return func_021B9338(work, line, lineEnd, key);
        }
        return key;
    }
    return 0;
}

/*
 * The mode value 2 is an enum-typed local initialised at declaration: the enum
 * keeps it out of constant propagation, so it is materialised at entry, overlaps
 * setting and the loaded unitScale (r1) and takes r3, which the later zero then reuses.
 */
void func_021B9164(RailWork *work, FieldRailSetting *setting, RailManager *manager)
{
    RailWorkMode mode = RAIL_WORK_UNSET;
    work->setting = setting;
    work->unitScale = setting->unitScale;
    work->mode = mode;
    work->lastSpeedIndex = 0;
    work->lastKey = 0;
    work->moving = 0;
    work->manager = manager;
    work->spot = 0;
    work->lineOffset = 0;
    work->widthOffset = 0;
    work->moveKey = 0;
    work->closedLines = &manager->closedLines;
    work->queryValid = 0;
    work->located = 0;
}

void func_021B919C(RailWork *work, FieldRailSetting *setting)
{
    func_021B9164(work, setting, work->manager);
}

u16 func_021B91A8(RailWork *work)
{
    return work->inUse;
}

int func_021B91AC(RailWork *work)
{
    if (work->mode < 2) {
        if (work->spot != 0) {
            if (work->inUse != 0) {
                return 1;
            }
        }
    }
    return 0;
}

RailCamera *func_021B91C8(RailWork *work)
{
    switch (work->mode) {
    case 0:
        return func_021B8820(work->setting, work->spot->point.cameraIndex);
    case 1:
        return func_021B8820(work->setting, work->spot->line.cameraIndex);
    }
    return &d_021D9A0C;
}

void func_021B91F8(RailWork *work, VecFx32 *outPos)
{
    RailLinePosFunc linePosFunc;

    if (work->mode == 0) {
        *outPos = work->spot->point.pos;
        return;
    }
    if (work->mode == 1) {
        RailLinePos *linePos = func_021B8848(work->setting, work->spot->line.linePosIndex);
        linePosFunc = func_021B8894(work->setting, linePos->funcIndex);
        if (linePosFunc)
            linePosFunc(work, outPos);
    }
}

void func_021B9238(const RailWork *work, RailLocation *outLocation)
{
    int railIndex;
    u32 mode;

    mode = work->mode;
    outLocation->type = mode;
    if (mode == 0)
        railIndex = func_021B97D0(work->setting, &work->spot->point);
    else
        railIndex = func_021B97FC(work->setting, &work->spot->line);
    outLocation->railIndex = railIndex;
    outLocation->lineGrid = work->lineOffset / 16;
    outLocation->widthGrid = work->widthOffset / 16;
    outLocation->key = work->moveKey;
}

int func_021B9278(const RailLine *line, int unitScale, const FieldRailSetting *setting)
{
    return (line->length << 4);
}

int func_021B9280(const RailLine *line, u32 offset, u32 length, const FieldRailSetting *setting)
{
    RailPoint *startPoint = &setting->points[line->startPoint];
    RailPoint *endPoint = &setting->points[line->endPoint];
    int startWidth;
    int endWidth;
    int width;
    int i;

    endWidth = -1;
    startWidth = -1;
    for (i = 0; i < 4; i++) {
        u32 startLineIndex = startPoint->lineIndex[i];
        if (startLineIndex != RAIL_NONE_INDEX) {
            if (line == setting->lines + startLineIndex)
                startWidth = startPoint->lineWidth[i];
        }
        {
            u32 endLineIndex = endPoint->lineIndex[i];
            if (endLineIndex != RAIL_NONE_INDEX) {
                if (line == setting->lines + endLineIndex)
                    endWidth = endPoint->lineWidth[i];
            }
        }
    }
    if (startWidth < 0)
        startWidth = endWidth;
    if (endWidth < 0)
        endWidth = startWidth;
    if (offset > length - 0x10)
        offset = length - 0x10;
    width = endWidth - startWidth;
    if (length - 0x10 != 0)
        width = (int)((u32)width * offset) / (int)(length - 0x10);
    return width + startWidth;
}

int func_021B9338(RailWork *work, RailLine *line, u32 lineEnd, int key)
{
    int limit = func_021B9280(line, work->lineOffset, lineEnd, work->setting);
    int width = work->widthOffset;

    work->widthLimit = limit;
    if ((width < 0 ? -width : width) >= limit) {
        if (width > 0)
            work->widthOffset = limit;
        else
            work->widthOffset = -limit;
    }
    return key;
}

int func_021B9368(RailManager *manager, RailLocation *location, u32 key, int steps, VecFx32 *outPos)
{
    int i;

    func_021B7EE4(manager->probeWork, location);
    func_021B80E0(manager->probeWork, 4, key);
    func_021B810C(manager->probeWork);
    func_021B80E0(manager->probeWork, 0, key);
    for (i = 0; i < 16; i++) {
        if (steps == i)
            func_021B8028(manager->probeWork, outPos);
        func_021B810C(manager->probeWork);
    }
    if (func_0203EFC8(location, &manager->probeWork->location, 8) == 0)
        return 0;
    return func_021B7DE0(manager->probeWork, &manager->probeWork->location);
}

int func_021B93D4(int key)
{
    switch (key) {
    case 1: return 3;
    case 3: return 1;
    case 4: return 2;
    case 2: return 4;
    }
    return 0;
}

int func_021B9404(int key)
{
    switch (key) {
    case 1: return 2;
    case 3: return 4;
    case 4: return 1;
    case 2: return 3;
    }
    return 0;
}

int func_021B9434(int key)
{
    switch (key) {
    case 1: return 4;
    case 3: return 2;
    case 4: return 3;
    case 2: return 1;
    }
    return 0;
}

RailClosedLines *func_021B9464(RailClosedLines *closedLines)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        closedLines->lineIndex[i] = RAIL_NONE_INDEX;
    }
    return closedLines;
}

void func_021B9478(RailClosedLines *closedLines, u16 lineIndex)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (closedLines->lineIndex[i] == RAIL_NONE_INDEX) {
            closedLines->lineIndex[i] = lineIndex;
            return;
        }
    }
}

void func_021B949C(RailClosedLines *closedLines, u16 lineIndex)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (lineIndex == closedLines->lineIndex[i]) {
            closedLines->lineIndex[i] = RAIL_NONE_INDEX;
            return;
        }
    }
}

int func_021B94C0(RailClosedLines *closedLines, u16 lineIndex)
{
    int i;
    for (i = 0; i < 0x12; i++)
        if (closedLines->lineIndex[i] == lineIndex)
            return 1;
    return 0;
}

/*
 * The line count is a volatile u16: the original reads it once for the
 * loop entry guard and again on every bottom test, while the array base is
 * hoisted.  A plain u16 count is CSEd into one register (6 bytes shorter).
 */
int func_021B94D8(RailClosedLines *closedLines, RailLine *line, FieldRailSetting *setting)
{
    int i;
    int found = 0;
    for (i = 0; i < setting->lineCount; i++) {
        if (line == &setting->lines[i])
            found = i;
    }
    return func_021B94C0(closedLines, found);
}

RailLine *func_021B9510(RailClosedLines *closedLines, FieldRailSetting *setting, u32 lineIndex)
{
    if (func_021B94C0(closedLines, (u16)lineIndex) == 0)
        return func_021B87FC(setting, lineIndex);
    return 0;
}

void func_021B9530(RailClosedLines *closedLines, RailWork *work, int lineDelta, int widthDelta, int key)
{
    if (func_021B94D8(closedLines, &work->spot->line, work->setting) != 0) {
        RailPoint *point = func_021B87D8(work->setting, work->spot->line.startPoint);
        RailLine *nextLine = func_021B8514(point, key, work->setting, closedLines, 0);
        int lengthLimit, widthLimit;

        func_021B86A4(work->setting, &work->spot->line, &lengthLimit, &widthLimit, closedLines, work->unitScale);
        work->lineOffset += lineDelta;
        work->widthOffset += widthDelta;
        if (work->lineOffset > lengthLimit)
            work->lineOffset = lengthLimit;
        if (nextLine == 0) {
            int width = work->widthOffset;
            int absWidth = width < 0 ? -width : width;
            if (absWidth > widthLimit) {
                if (width > 0)
                    work->widthOffset = widthLimit;
                else
                    work->widthOffset = -widthLimit;
            }
        }
        return;
    }
    work->lineOffset += lineDelta;
    work->widthOffset += widthDelta;
}

int func_021B95C0(RailClosedLines *closedLines, RailLine *line, int lineOffset, int widthOffset,
                  FieldRailSetting *setting, int unitScale)
{
    int lengthLimit, widthLimit;

    if (func_021B94D8(closedLines, line, setting) == 0)
        goto ok;
    func_021B86A4(setting, line, &lengthLimit, &widthLimit, closedLines, unitScale);
    if (lineOffset > lengthLimit)
        goto fail;
    if (widthOffset < 0)
        widthOffset = -widthOffset;
    if (widthOffset > widthLimit)
        goto fail;
    return 1;
fail:
    return 0;
ok:
    return 1;
}

u32 func_021B960C(RailPoint *point, RailLine *line, FieldRailSetting *setting)
{
    int i;
    RailLine *pointLine;
    for (i = 0; i < 4; i++) {
        pointLine = func_021B87FC(setting, point->lineIndex[i]);
        if (pointLine == line)
            return point->lineKey[i];
    }
    return 0;
}

int func_021B963C(RailLine *line, FieldRailSetting *setting)
{
    RailPoint *startPoint, *endPoint;
    u32 startKey, endKey;

    if (line->startPoint == RAIL_NONE_INDEX || line->endPoint == RAIL_NONE_INDEX)
        return 0;
    startPoint = func_021B87D8(setting, line->startPoint);
    endPoint = func_021B87D8(setting, line->endPoint);
    startKey = func_021B960C(startPoint, line, setting);
    if (startKey == 0)
        return 0;
    if (startKey != line->key)
        return 0;
    endKey = func_021B960C(endPoint, line, setting);
    if (endKey == 0)
        return 0;
    if (endKey != (u32)func_021B93D4(line->key))
        return 0;
    return 1;
}

int func_021B96AC(RailPoint *point, FieldRailSetting *setting)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        u32 lineKey = point->lineKey[i];
        u32 lineIndex = point->lineIndex[i];
        RailLine *line;
        RailPoint *startPoint;
        RailPoint *endPoint;

        if ((lineKey == 0) != (lineIndex == RAIL_NONE_INDEX))
            return 0;
        if (lineIndex == RAIL_NONE_INDEX)
            continue;
        line = func_021B87FC(setting, lineIndex);
        startPoint = func_021B87D8(setting, line->startPoint);
        endPoint = func_021B87D8(setting, line->endPoint);
        if (startPoint != point && endPoint != point)
            return 0;
        if (point->lineKey[i] == 0)
            continue;
        for (j = i + 1; j < 4; j++) {
            if (point->lineKey[i] == (u32)func_021B93D4(point->lineKey[j])) {
                if (line->key != func_021B87FC(setting, point->lineIndex[j])->key)
                    return 0;
            }
        }
    }
    return 1;
}

void func_021B9768(const char *label, VecFx32 *pos)
{
}

void func_021B976C(const char *prefix, RailPoint *point, const char *suffix)
{
    if (point != 0) {
        func_021B9768(prefix, &point->pos);
    }
}

void func_021B977C(RailWork *work)
{
    RailPoint *startPoint;
    RailPoint *endPoint;

    if (work->mode == 0) {
        func_021B976C(0, &work->spot->point, d_021DE2B0);
    } else if (work->mode == 1) {
        startPoint = func_021B87D8(work->setting, work->spot->line.startPoint);
        endPoint = func_021B87D8(work->setting, work->spot->line.endPoint);
        func_021B976C(d_021DE2B4, startPoint, 0);
        func_021B976C(d_021DE2BC, endPoint, d_021DE2B0);
    }
}

int func_021B97D0(FieldRailSetting *setting, RailPoint *point)
{
    int i;

    for (i = 0; i < setting->pointCount; i++) {
        if (point == &setting->points[i]) {
            return i;
        }
    }
    return 0;
}

/*
 * 2026-10-02: the per-iteration reload of the count (ldrh in the loop) that
 * kept the earlier draft at DIFF comes from a volatile count field; every
 * non-volatile spelling hoists it like func_021B97D0.
 */
int func_021B97FC(FieldRailSetting *setting, RailLine *line)
{
    int i;

    for (i = 0; i < setting->lineCount; i++) {
        if (line == &setting->lines[i]) {
            return i;
        }
    }
    return 0;
}

static inline int FX_Mul(int a, int b)
{
    return (int)(((long long)a * b + 0x800LL) >> 12);
}

static inline void VEC_Set(VecFx32 *v, fx32 x, fx32 y, fx32 z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

/*
 * Segment/plane intersection: the plane through planePoint spanned by dirA and
 * dirB, the segment from segStart to segEnd; writes the hit point to out and
 * returns 1.
 * The hit point is computed z, y, x and stored x, y, z: an inline VEC_Set
 * evaluates its arguments last to first
 * (docs/idioms/an-inline-wrappers-arguments-are-evaluated-last-to-first.md).
 *
 * Addresses are Black-image addresses.
 */
int func_021B9828(VecFx32 *dirA, VecFx32 *dirB, VecFx32 *planePoint, VecFx32 *segStart, VecFx32 *segEnd,
                  VecFx32 *out)
{
    VecFx32 normal;
    VecFx32 segDir;
    VecFx32 unitA;
    VecFx32 unitB;
    int segLength;
    int numerator;
    int denominator;
    int hitDist;

    VEC_Subtract(segEnd, segStart, &segDir);
    segLength = VEC_Mag(&segDir);
    VEC_Normalize(&segDir, &segDir);
    VEC_Normalize(dirA, &unitA);
    VEC_Normalize(dirB, &unitB);
    VEC_CrossProduct(&unitA, &unitB, &normal);
    VEC_Normalize(&normal, &normal);
    numerator = (FX_Mul(normal.x, planePoint->x) + FX_Mul(normal.y, planePoint->y) + FX_Mul(normal.z, planePoint->z))
        - (FX_Mul(normal.x, segStart->x) + FX_Mul(normal.y, segStart->y) + FX_Mul(normal.z, segStart->z));
    denominator = FX_Mul(normal.x, segDir.x) + FX_Mul(normal.y, segDir.y) + FX_Mul(normal.z, segDir.z);
    if (denominator == 0) {
        return 0;
    }
    hitDist = FX_Div(numerator, denominator);
    if (hitDist > segLength) {
        return 0;
    }
    if (hitDist <= 0x1000) {
        return 0;
    }
    VEC_Set(out, segStart->x + FX_Mul(segDir.x, hitDist), segStart->y + FX_Mul(segDir.y, hitDist),
            segStart->z + FX_Mul(segDir.z, hitDist));
    return 1;
}

void func_021B9A50(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t)
{
    VecFx32 unitFrom;
    VecFx32 unitTo;
    u16 angle;
    int sinAngle;
    int angleFx;

    VEC_Normalize(from, &unitFrom);
    VEC_Normalize(to, &unitTo);
    angle = FX_AcosIdx(VEC_DotProduct(&unitFrom, &unitTo));
    sinAngle = ((u16 *)d_020A1B38)[(angle >> 4) * 2];
    if (sinAngle == 0) {
        *out = unitTo;
        return;
    }
    angleFx = angle << 12;
    func_020520A4(&unitFrom, FX_Div(((u16 *)d_020A1B38)[(FX_Mul(angleFx, FX32_ONE - t) >> 16) * 2], sinAngle), &unitFrom);
    func_020520A4(&unitTo, FX_Div(((u16 *)d_020A1B38)[(FX_Mul(angleFx, t) >> 16) * 2], sinAngle), &unitTo);
    VEC_Add(&unitFrom, &unitTo, out);
    VEC_Normalize(out, out);
}

void func_021B9B24(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t)
{
    VecFx32 origin = {0, 0, 0};
    int lengthFrom;
    int lengthTo;
    int lengthDiff;

    func_021B9A50(out, from, to, t);
    lengthFrom = VEC_Mag(from);
    lengthTo = VEC_Mag(to);
    lengthDiff = lengthTo - lengthFrom;
    func_0207CEE4(lengthFrom + (int)(((s64)lengthDiff * t + 0x800) >> 12), out, &origin, out);
}

void func_021B9B7C(RailWork *work, VecFx32 *outPos)
{
    VecFx32 delta;
    VecFx32 up;
    VecFx32 side;
    int progress;
    RailPoint *startPoint;
    RailPoint *endPoint;
    VecFx32 *startPos;
    int widthOffset;
    int unitScale;

    func_021B82F4(work);
    progress = FX_Div(func_021B82F8(work) << 12, func_021B82FC(work) << 12);
    startPoint = func_021B833C(work);
    endPoint = func_021B834C(work);
    startPos = &startPoint->pos;
    VEC_Subtract(&endPoint->pos, startPos, &delta);
    func_0207CEE4(progress, &delta, startPos, outPos);
    up = d_021D9A54;
    widthOffset = func_021B8300(work);
    unitScale = func_021B8308(work);
    VEC_CrossProduct(&delta, &up, &side);
    VEC_Normalize(&side, &side);
    func_0207CEE4((int)(((s64)(widthOffset << 12) * unitScale + 0x800) >> 12), &side, outPos, outPos);
}

void func_021B9C28(RailWork *work, VecFx32 *outPos)
{
    VecFx32 centre;
    VecFx32 fromStart;
    VecFx32 fromEnd;
    VecFx32 axis;
    VecFx32 dir;
    VecFx32 radial;
    VecFx32 side;
    int progress;
    int lineEnd;
    int lineOffset;
    VecFx32 *startPos;
    VecFx32 *endPos;
    RailLinePos *linePos;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int offset;

    func_021B82F4(work);
    startPoint = func_021B833C(work);
    endPoint = func_021B834C(work);
    startPos = &startPoint->pos;
    endPos = &endPoint->pos;
    lineOffset = func_021B82F8(work);
    lineEnd = func_021B82FC(work);
    progress = FX_Div((int)((u32)lineOffset << 12), (int)((u32)lineEnd << 12));
    outPos->y = endPos->y - startPos->y;
    outPos->y = FX_Div(FX_Mul(outPos->y, lineOffset << 12), lineEnd << 12);
    outPos->y += startPos->y;
    linePos = func_021B835C(work);
    centre.x = linePos->pos.x;
    centre.y = outPos->y;
    centre.z = linePos->pos.z;
    VEC_Subtract(startPos, &centre, &fromStart);
    VEC_Subtract(endPos, &centre, &fromEnd);
    fromStart.y = 0;
    fromEnd.y = 0;
    VEC_Subtract(&fromEnd, &fromStart, &dir);
    dir.y = 0;
    VEC_Normalize(&dir, &dir);
    func_021B9B24(&axis, &fromStart, &fromEnd, progress);
    VEC_Add(&centre, &axis, outPos);
    offset = (int)(((s64)((int)func_021B8300(work) << 12) * (int)func_021B8308(work) + 0x800) >> 12);
    VEC_Normalize(&axis, &radial);
    VEC_CrossProduct(&radial, &dir, &side);
    if (side.y < 0) {
        func_0207CEE4(-offset, &radial, outPos, outPos);
    } else {
        func_0207CEE4(offset, &radial, outPos, outPos);
    }
}

void func_021B9D60(RailWork *work, VecFx32 *outPos)
{
    VecFx32 centre;
    VecFx32 fromStart;
    VecFx32 fromEnd;
    VecFx32 axis;
    VecFx32 dir;
    VecFx32 radial;
    VecFx32 side;
    VecFx32 up;
    int progress;
    VecFx32 *startPos;
    VecFx32 *endPos;
    RailLinePos *linePos;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int offset;

    func_021B82F4(work);
    startPoint = func_021B833C(work);
    endPoint = func_021B834C(work);
    startPos = &startPoint->pos;
    endPos = &endPoint->pos;
    progress = FX_Div(func_021B82F8(work) << 12, func_021B82FC(work) << 12);
    linePos = func_021B835C(work);
    centre.x = linePos->pos.x;
    centre.y = linePos->pos.y;
    centre.z = linePos->pos.z;
    VEC_Subtract(startPos, &centre, &fromStart);
    VEC_Subtract(endPos, &centre, &fromEnd);
    VEC_Subtract(&fromEnd, &fromStart, &dir);
    VEC_Normalize(&dir, &dir);
    func_021B9B24(&axis, &fromStart, &fromEnd, progress);
    VEC_Add(&centre, &axis, outPos);
    offset = (int)(((s64)((int)func_021B8300(work) << 12) * (int)func_021B8308(work) + 0x800) >> 12);
    if (axis.x != 0 && axis.z != 0) {
        axis.y = 0;
    } else {
        up = d_021D9A60;
        VEC_Subtract(endPos, startPos, &axis);
        VEC_CrossProduct(&axis, &up, &axis);
    }
    VEC_Normalize(&axis, &radial);
    VEC_CrossProduct(&radial, &dir, &side);
    if (side.y < 0) {
        func_0207CEE4(-offset, &radial, outPos, outPos);
    } else {
        func_0207CEE4(offset, &radial, outPos, outPos);
    }
}

/*
 * Builds the 8-byte location on line `lineIndex` at pos between the two points of the
 * line (func_021B8230): horizontal distance and height offset scaled by
 * func_021B8248 and rounded by func_021B8378; returns 0 when out of range,
 * else 1 when the location round-trips unchanged through func_021B8250 and
 * func_021B7D38.
 * pos->x and pos->z go through locals: stored straight into flatPos, the y = 0
 * stores interleave with them and the loads split; the out-of-range
 * `return 0` is the fall-out of an if around the rest (it sits after the
 * final epilogue). The spill slots follow startWidth, endWidth, length, dist, diff declared
 * in that order.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9E84(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos)
{
    VecFx32 hitPos;
    VecFx32 axis;
    VecFx32 flatPos;
    VecFx32 flatHit;
    int hitDist;
    RailLocation checkLocation;
    RailLine *line;
    int unitScale;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int startWidth;
    int endWidth;
    u32 length;
    u32 dist;
    int diff;
    int i;
    int x;
    int z;

    line = func_021B8230(manager, lineIndex);
    startPoint = func_021B8224(manager, line->startPoint);
    endPoint = func_021B8224(manager, line->endPoint);
    unitScale = func_021B8248(manager);
    if (func_021BAE7C(startPoint, endPoint, pos, &hitPos, &hitDist, &axis) == 0) {
        return 0;
    }
    x = pos->x;
    z = pos->z;
    flatPos.x = x;
    flatHit.x = hitPos.x;
    flatPos.z = z;
    flatHit.z = hitPos.z;
    flatPos.y = 0;
    flatHit.y = 0;
    dist = FX_Div(VEC_Distance(&flatPos, &flatHit), unitScale) >> 12;
    func_021B823C(manager, line->linePosIndex);
    length = line->length << 4;
    diff = length - (FX_Div(hitDist, unitScale) >> 12);
    for (i = 0; i < 4; i++) {
        if (lineIndex == startPoint->lineIndex[i]) {
            startWidth = startPoint->lineWidth[i];
        }
        if (lineIndex == endPoint->lineIndex[i]) {
            endWidth = endPoint->lineWidth[i];
        }
    }
    if (dist <= startWidth + (endWidth - startWidth) * diff / length + 0x10) {
        outLocation->railIndex = lineIndex;
        outLocation->type = 1;
        outLocation->key = 3;
        if (axis.y >= 0) {
            outLocation->widthGrid = func_021B8378(dist);
        } else {
            outLocation->widthGrid = -func_021B8378(dist);
        }
        outLocation->lineGrid = func_021B8378(diff);
        func_021B8250(manager, outLocation, &checkLocation);
        func_021B7D38(manager, &checkLocation, outPos);
        if (func_0203EFC8(outLocation, &checkLocation, 8) == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int func_021B9FC8(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos)
{
    VecFx32 curPos;
    VecFx32 prevPos;
    VecFx32 segment;
    VecFx32 toPos;
    VecFx32 segmentDir;
    VecFx32 hitPos;
    VecFx32 axis;
    VecFx32 flatPos;
    VecFx32 flatHit;
    VecFx32 unitSegment;
    VecFx32 unitToPos;
    int hitDist;
    RailLocation checkLocation;
    int segmentLength;
    u32 widthLimit;
    u32 cellCount;
    int unitScale;
    u32 cell;
    RailLine *line;
    RailPoint *startPoint;
    RailPoint *endPoint;
    RailWork *probe;
    int toPosLength;
    int ratio;
    int along;
    int alongScaled;
    u32 dist;
    int x;
    int z;

    line = func_021B8230(manager, lineIndex);
    startPoint = func_021B8224(manager, line->startPoint);
    endPoint = func_021B8224(manager, line->endPoint);
    if (func_021BAE7C(startPoint, endPoint, pos, &hitPos, &hitDist, &axis) == 0) {
        return 0;
    }
    outLocation->railIndex = lineIndex;
    outLocation->type = 1;
    outLocation->key = 3;
    outLocation->widthGrid = 0;
    outLocation->lineGrid = 0;
    probe = func_021B824C(manager);
    func_021B7EE4(probe, outLocation);
    cellCount = func_021B82FC(probe) >> 4;
    func_021B8028(probe, &curPos);
    prevPos.x = curPos.x;
    prevPos.y = curPos.y;
    prevPos.z = curPos.z;
    unitScale = func_021B8248(manager);
    for (cell = 1; cell < cellCount; cell++) {
        outLocation->lineGrid = cell;
        func_021B7EE4(probe, outLocation);
        func_021B8028(probe, &curPos);
        widthLimit = func_021B8304(probe);
        VEC_Subtract(&prevPos, &curPos, &segment);
        VEC_Subtract(pos, &curPos, &toPos);
        VEC_Normalize(&segment, &segmentDir);
        segmentLength = VEC_Mag(&segment);
        VEC_Normalize(&segment, &unitSegment);
        VEC_Normalize(&toPos, &unitToPos);
        VEC_CrossProduct(&unitSegment, &unitToPos, &axis);
        segment = segmentDir;
        toPosLength = VEC_Mag(&toPos);
        VEC_Normalize(&toPos, &toPos);
        ratio = FX_Div(toPosLength, segmentLength);
        toPos.x = FX_Mul(toPos.x, ratio);
        toPos.y = FX_Mul(toPos.y, ratio);
        toPos.z = FX_Mul(toPos.z, ratio);
        along = VEC_DotProduct(&segment, &toPos);
        if (along <= 0x1000 && along >= 0) {
            alongScaled = FX_Mul(along, segmentLength);
            hitPos.x = FX_Mul(segmentDir.x, alongScaled);
            hitPos.y = FX_Mul(segmentDir.y, alongScaled);
            hitPos.z = FX_Mul(segmentDir.z, alongScaled);
            VEC_Add(&curPos, &hitPos, &hitPos);
            x = pos->x;
            z = pos->z;
            flatPos.x = x;
            flatPos.z = z;
            flatPos.y = 0;
            flatHit.x = hitPos.x;
            flatHit.y = 0;
            flatHit.z = hitPos.z;
            dist = FX_Div(VEC_Distance(&flatPos, &flatHit), unitScale) >> 12;
            widthLimit += 0x10;
            if (widthLimit >= dist) {
                if (axis.y >= 0) {
                    outLocation->widthGrid = func_021B8378(dist);
                } else {
                    outLocation->widthGrid = -func_021B8378(dist);
                }
                func_021B8250(manager, outLocation, &checkLocation);
                func_021B7D38(manager, outLocation, outPos);
                if (func_0203EFC8(outLocation, &checkLocation, 8) == 0) {
                    return 1;
                }
                return 0;
            }
        }
        prevPos.x = curPos.x;
        prevPos.y = curPos.y;
        prevPos.z = curPos.z;
    }
    return 0;
}

void func_021BA25C(RailManager *manager)
{
    VecFx32 eye;
    RailCamera *camera;

    camera = func_021B830C(func_021B8220(manager));
    func_021B79D4(manager, &eye);
    func_0218E124(func_021B821C(manager), 2);
    eye.x += camera->param[0];
    eye.y += camera->param[1];
    eye.z += camera->param[2];
    func_0218ECF4(func_021B821C(manager), &eye);
    func_0218EC60(func_021B821C(manager));
}

void func_021BA2B4(RailManager *manager)
{
    VecFx32 focusPos;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;
    u16 pitch, yaw;
    u32 distance;

    fieldCamera = func_021B821C(manager);
    camera = func_021B830C(func_021B8220(manager));
    func_0218E124(fieldCamera, 0);
    func_0218EC60(func_021B821C(manager));
    func_021B79D4(manager, &focusPos);
    pitch = camera->param[0];
    yaw = camera->param[1];
    distance = camera->param[2];
    func_0218ED48(fieldCamera, yaw);
    func_0218ED34(fieldCamera, pitch);
    func_0218ED58(fieldCamera, distance);
}

void func_021BA310(RailManager *manager)
{
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    VecFx32 centrePos;

    focusWork = func_021B8220(manager);
    fieldCamera = func_021B821C(manager);
    func_021BA2B4(manager);
    func_0218EC54(fieldCamera);
    func_021B8314(focusWork, &centrePos);
    func_0218EC90(fieldCamera, &centrePos);
}

/*
 * Twin of func_021BACA8 without the vector part.  The angle and scalar
 * locals are int with explicit (u16) casts: as u16 locals the camera0 loads
 * reorder and the ratio stays in a register pair instead of its
 * [sp]/[sp+4] spill.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA348(RailManager *manager)
{
    RailCamera *camera0;
    RailCamera *camera1;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    struct FieldCamera *fieldCamera;
    int ratio;
    int lineEnd;
    int lineOffset;
    int pitch0;
    int yaw0;
    int distance0;
    int yaw1;
    int distance1;
    int pitchDelta;
    int yawDelta;
    u16 pitch;
    u16 yaw;

    focusWork = func_021B8220(manager);
    startPoint = func_021B833C(focusWork);
    endPoint = func_021B834C(focusWork);
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 0);
    func_0218EC60(func_021B821C(manager));
    camera0 = func_021B836C(focusWork, startPoint);
    camera1 = func_021B836C(focusWork, endPoint);
    lineEnd = func_021B82FC(focusWork);
    lineOffset = func_021B82F8(focusWork);
    ratio = FX_Div(lineOffset << 12, lineEnd << 12);
    pitch0 = (u16)camera0->param[0];
    yaw0 = (u16)camera0->param[1];
    distance0 = camera0->param[2];
    yaw1 = (u16)camera1->param[1];
    distance1 = camera1->param[2];
    pitchDelta = (u16)camera1->param[0] - pitch0;
    if (pitchDelta >= 0x8000)
        pitchDelta -= 0x10000;
    else if (pitchDelta <= -0x8000)
        pitchDelta += 0x10000;
    pitch = pitch0 + (FX_Mul(pitchDelta << 12, ratio) >> 12);
    yawDelta = yaw1 - yaw0;
    if (yawDelta >= 0x8000)
        yawDelta -= 0x10000;
    else if (yawDelta <= -0x8000)
        yawDelta += 0x10000;
    yaw = yaw0 + (FX_Mul(yawDelta << 12, ratio) >> 12);
    func_0218ED48(fieldCamera, yaw);
    func_0218ED34(fieldCamera, pitch);
    func_0218ED58(fieldCamera, distance0 + FX_Mul(distance1 - distance0, ratio));
}

void func_021BA494(RailManager *manager)
{
    struct FieldCamera *fieldCamera = func_021B821C(manager);
    VecFx32 focusPos;

    func_021BA348(manager);
    func_0218EC54(fieldCamera);
    func_021B79D4(manager, &focusPos);
    func_0218EC90(fieldCamera, &focusPos);
}

void func_021BA4C4(RailManager *manager)
{
    VecFx32 centrePos;
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;

    focusWork = func_021B8220(manager);
    fieldCamera = func_021B821C(manager);
    func_021BA348(manager);
    func_0218EC54(fieldCamera);
    func_021B8314(focusWork, &centrePos);
    func_0218EC90(fieldCamera, &centrePos);
}

void func_021BA4FC(RailManager *manager)
{
    VecFx32 eye;
    VecFx32 target;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;

    camera = func_021B830C(func_021B8220(manager));
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 2);
    func_0218EC54(func_021B821C(manager));
    eye.x = camera->param[0];
    eye.y = camera->param[1];
    eye.z = camera->param[2];
    target.x = camera->param[3];
    target.y = camera->param[4];
    target.z = camera->param[5];
    func_0218ECF4(fieldCamera, &eye);
    func_0218EC90(fieldCamera, &target);
}

void func_021BA550(RailManager *manager)
{
    VecFx32 eye;
    VecFx32 target;
    RailCamera *camera0;
    RailCamera *camera1;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    struct FieldCamera *fieldCamera;
    int lineEnd;
    int lineOffset;

    focusWork = func_021B8220(manager);
    fieldCamera = func_021B821C(manager);
    startPoint = func_021B833C(focusWork);
    endPoint = func_021B834C(focusWork);
    camera0 = func_021B836C(focusWork, startPoint);
    camera1 = func_021B836C(focusWork, endPoint);
    func_0218E124(fieldCamera, 2);
    func_0218EC54(func_021B821C(manager));
    lineEnd = func_021B82FC(focusWork);
    lineOffset = func_021B82F8(focusWork);
    eye.x = FX_Div(FX_Mul(camera1->param[0] - camera0->param[0], lineOffset << 12), lineEnd << 12);
    eye.y = FX_Div(FX_Mul(camera1->param[1] - camera0->param[1], lineOffset << 12), lineEnd << 12);
    eye.z = FX_Div(FX_Mul(camera1->param[2] - camera0->param[2], lineOffset << 12), lineEnd << 12);
    target.x = FX_Div(FX_Mul(camera1->param[3] - camera0->param[3], lineOffset << 12), lineEnd << 12);
    target.y = FX_Div(FX_Mul(camera1->param[4] - camera0->param[4], lineOffset << 12), lineEnd << 12);
    target.z = FX_Div(FX_Mul(camera1->param[5] - camera0->param[5], lineOffset << 12), lineEnd << 12);
    eye.x += camera0->param[0];
    eye.y += camera0->param[1];
    eye.z += camera0->param[2];
    target.x += camera0->param[3];
    target.y += camera0->param[4];
    target.z += camera0->param[5];
    func_0218ECF4(fieldCamera, &eye);
    func_0218EC90(fieldCamera, &target);
}

void func_021BA6E8(RailManager *manager)
{
    VecFx32 point;
    RailCamera *camera0;
    RailCamera *camera1;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int lineEnd;
    int lineOffset;
    u16 pitch;
    int pitch0;
    int distance;

    focusWork = func_021B8220(manager);
    func_021B821C(manager);
    if (func_021B82F0(focusWork) == 1) {
        startPoint = func_021B833C(focusWork);
        endPoint = func_021B834C(focusWork);
        camera0 = func_021B836C(focusWork, startPoint);
        camera1 = func_021B836C(focusWork, endPoint);
        lineEnd = func_021B82FC(focusWork);
        lineOffset = func_021B82F8(focusWork);
    } else {
        camera0 = func_021B830C(focusWork);
        camera1 = func_021B830C(focusWork);
        lineEnd = 1;
        lineOffset = 0;
    }
    pitch0 = camera0->param[0];
    pitch = pitch0 + (camera1->param[0] - pitch0) * lineOffset / lineEnd;
    distance = camera0->param[1] + FX_Div(FX_Mul(camera1->param[1] - camera0->param[1], lineOffset << 12), lineEnd << 12);
    point.x = camera0->param[2];
    point.y = camera0->param[3];
    point.z = camera0->param[4];
    func_021BA7E0(manager, pitch, distance, &point);
}

void func_021BA7B0(RailManager *manager)
{
    RailCamera *camera;
    u16 pitch;
    int distance;
    VecFx32 point;

    camera = func_021B830C(func_021B8220(manager));
    pitch = camera->param[0];
    distance = camera->param[1];
    point.x = camera->param[2];
    point.y = camera->param[3];
    point.z = camera->param[4];
    func_021BA7E0(manager, pitch, distance, &point);
}

void func_021BA7E0(RailManager *manager, u16 pitch, int distance, VecFx32 *point)
{
    VecFx32 toFocus;
    VecFx32 anchor;
    VecFx32 dir;
    VecFx32 eye;
    struct FieldCamera *fieldCamera;
    int anchorY;
    int i;
    int horizontalDist;

    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 2);
    func_0218EC54(fieldCamera);
    anchor = *point;
    anchorY = anchor.y;
    anchor.y = 0;
    func_021B79D4(manager, &toFocus);
    toFocus.y = 0;
    VEC_Subtract(&toFocus, &anchor, &toFocus);
    VEC_Normalize(&toFocus, &dir);
    i = (pitch >> 4) * 2;
    eye.y = FX_Mul(d_020A1B38[i], distance);
    horizontalDist = FX_Mul(d_020A1B38[i + 1], distance);
    eye.x = FX_Mul(dir.x, horizontalDist);
    eye.z = FX_Mul(dir.z, horizontalDist);
    eye.x += anchor.x;
    eye.y += anchorY;
    eye.z += anchor.z;
    func_0218EC90(fieldCamera, point);
    func_0218ECF4(fieldCamera, &eye);
}

void func_021BA8E0(RailManager *manager)
{
    VecFx32 point;
    RailCamera *camera;
    RailWork *focusWork;
    int lineEnd;
    int lineOffset;
    u16 pitch;
    int distance;

    focusWork = func_021B8220(manager);
    func_021B82F0(focusWork);
    lineEnd = func_021B82FC(focusWork);
    lineOffset = func_021B82F8(focusWork);
    camera = func_021B830C(focusWork);
    pitch = camera->param[0];
    distance = camera->param[1];
    point.x = camera->param[2] + FX_Div(FX_Mul(camera->param[5] - camera->param[2], lineOffset << 12), lineEnd << 12);
    point.y = camera->param[3] + FX_Div(FX_Mul(camera->param[6] - camera->param[3], lineOffset << 12), lineEnd << 12);
    point.z = camera->param[4] + FX_Div(FX_Mul(camera->param[7] - camera->param[4], lineOffset << 12), lineEnd << 12);
    func_021BA7E0(manager, pitch, distance, &point);
}

void func_021BA9B4(RailManager *manager)
{
    VecFx32 anchor;
    VecFx32 toFocus;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;
    int yaw;

    camera = func_021B830C(func_021B8220(manager));
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 0);
    func_0218EC60(func_021B821C(manager));
    func_021B79D4(manager, &toFocus);
    toFocus.y = 0;
    anchor.x = camera->param[2];
    anchor.y = 0;
    anchor.z = camera->param[3];
    VEC_Subtract(&toFocus, &anchor, &toFocus);
    VEC_Normalize(&toFocus, &toFocus);
    yaw = func_0207CFB8(toFocus.x, toFocus.z);
    func_0218ED34(fieldCamera, camera->param[0]);
    func_0218ED58(fieldCamera, camera->param[1]);
    func_0218ED48(fieldCamera, yaw);
}

void func_021BAA30(RailManager *manager)
{
    s16 stepVec[4];
    RailCamera *camera;
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    int heading;

    focusWork = func_021B8220(manager);
    camera = func_021B830C(focusWork);
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 0);
    func_0218EC60(func_021B821C(manager));
    func_021B8050(focusWork, stepVec);
    heading = func_0207CFB8(-stepVec[0], -stepVec[2]);
    func_0218ED34(fieldCamera, camera->param[1]);
    func_0218ED58(fieldCamera, camera->param[2]);
    func_0218ED48(fieldCamera, (u16)(heading + camera->param[0]));
}

void func_021BAA9C(RailManager *manager)
{
    s16 stepVec[6];
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    RailCamera *camera;
    int heading, slope;

    focusWork = func_021B8220(manager);
    camera = func_021B830C(focusWork);
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 0);
    func_0218EC60(func_021B821C(manager));
    func_021B8050(focusWork, &stepVec[3]);
    heading = func_0207CFB8(-stepVec[3], -stepVec[5]);
    stepVec[0] = stepVec[3];
    stepVec[2] = stepVec[5];
    stepVec[1] = 0;
    slope = func_0207CFB8(-stepVec[4], func_0207CC30(stepVec));
    func_0218ED34(fieldCamera, slope + camera->param[1]);
    func_0218ED58(fieldCamera, camera->param[2]);
    func_0218ED48(fieldCamera, (u16)(heading + camera->param[0]));
}

void func_021BAB30(RailManager *manager)
{
    s16 stepVec[4];
    VecFx32 centrePos;
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    RailCamera *camera;
    int heading;

    focusWork = func_021B8220(manager);
    camera = func_021B830C(focusWork);
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 0);
    func_0218EC54(func_021B821C(manager));
    func_021B8050(focusWork, stepVec);
    heading = func_0207CFB8(-stepVec[0], -stepVec[2]);
    func_0218ED34(fieldCamera, camera->param[1]);
    func_0218ED58(fieldCamera, camera->param[2]);
    func_0218ED48(fieldCamera, (u16)(heading + camera->param[0]));
    func_021B8314(focusWork, &centrePos);
    func_0218EC90(func_021B821C(manager), &centrePos);
}

void func_021BABB4(RailManager *manager)
{
    RailWork *focusWork = func_021B8220(manager);
    int mode = func_021B82F0(focusWork);
    RailPoint *startPoint = func_021B833C(focusWork);

    if (mode == 1) {
        func_021BB014(manager, focusWork, startPoint);
    }
}

void func_021BABDC(RailManager *manager)
{
    RailWork *focusWork = func_021B8220(manager);
    int mode = func_021B82F0(focusWork);
    RailPoint *endPoint = func_021B834C(focusWork);

    if (mode == 1) {
        func_021BB014(manager, focusWork, endPoint);
    }
}

void func_021BAC04(RailManager *manager)
{
    VecFx32 focusPos;
    VecFx32 shift;
    struct FieldCamera *fieldCamera;
    RailCamera *camera;
    u16 pitch, yaw;
    u32 distance;

    fieldCamera = func_021B821C(manager);
    camera = func_021B830C(func_021B8220(manager));
    func_0218E124(fieldCamera, 0);
    func_0218EC60(func_021B821C(manager));
    func_021B79D4(manager, &focusPos);
    pitch = camera->param[0];
    yaw = camera->param[1];
    distance = camera->param[2];
    func_0218ED48(fieldCamera, yaw);
    func_0218ED34(fieldCamera, pitch);
    func_0218ED58(fieldCamera, distance);
    shift.x = camera->param[3];
    shift.y = camera->param[4];
    shift.z = camera->param[5];
    func_0218ECD4(fieldCamera, &shift);
}

void func_021BAC74(RailManager *manager)
{
    VecFx32 focusPos;
    struct FieldCamera *fieldCamera = func_021B821C(manager);

    func_021BAC04(manager);
    func_0218EC54(fieldCamera);
    func_021B79D4(manager, &focusPos);
    func_0218EC90(fieldCamera, &focusPos);
    func_0218F05C(fieldCamera);
}

/*
 * Keyframe lerp between two func_021B836C records: two wrapped 16-bit
 * angles (param 0 and 1), a scalar (param 2) and a vector (param 3 to 5).  The
 * angle and scalar locals are int with explicit (u16) casts: as u16
 * locals the pitch0 load sinks below the camera1 loads and every spill slot moves.
 * camera1 is declared before camera0 to put camera0 in r5.
 *
 * Addresses are Black-image addresses.
 */
void func_021BACA8(RailManager *manager)
{
    VecFx32 shift;
    RailCamera *camera1;
    RailCamera *camera0;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    struct FieldCamera *fieldCamera;
    int ratio;
    int lineEnd;
    int lineOffset;
    int pitch0;
    int yaw0;
    int distance0;
    int yaw1;
    int distance1;
    int pitchDelta;
    int yawDelta;
    u16 pitch;
    u16 yaw;

    focusWork = func_021B8220(manager);
    startPoint = func_021B833C(focusWork);
    endPoint = func_021B834C(focusWork);
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 0);
    func_0218EC60(func_021B821C(manager));
    camera0 = func_021B836C(focusWork, startPoint);
    camera1 = func_021B836C(focusWork, endPoint);
    lineEnd = func_021B82FC(focusWork);
    lineOffset = func_021B82F8(focusWork);
    ratio = FX_Div(lineOffset << 12, lineEnd << 12);
    pitch0 = (u16)camera0->param[0];
    yaw0 = (u16)camera0->param[1];
    distance0 = camera0->param[2];
    yaw1 = (u16)camera1->param[1];
    distance1 = camera1->param[2];
    pitchDelta = (u16)camera1->param[0] - pitch0;
    if (pitchDelta >= 0x8000)
        pitchDelta -= 0x10000;
    else if (pitchDelta <= -0x8000)
        pitchDelta += 0x10000;
    pitch = pitch0 + (FX_Mul(pitchDelta << 12, ratio) >> 12);
    yawDelta = yaw1 - yaw0;
    if (yawDelta >= 0x8000)
        yawDelta -= 0x10000;
    else if (yawDelta <= -0x8000)
        yawDelta += 0x10000;
    yaw = yaw0 + (FX_Mul(yawDelta << 12, ratio) >> 12);
    func_0218ED48(fieldCamera, yaw);
    func_0218ED34(fieldCamera, pitch);
    func_0218ED58(fieldCamera, distance0 + FX_Mul(distance1 - distance0, ratio));
    shift.x = camera0->param[3] + FX_Mul(camera1->param[3] - camera0->param[3], ratio);
    shift.y = camera0->param[4] + FX_Mul(camera1->param[4] - camera0->param[4], ratio);
    shift.z = camera0->param[5] + FX_Mul(camera1->param[5] - camera0->param[5], ratio);
    func_0218ECD4(fieldCamera, &shift);
}

/*
 * EXACT*: 406 bytes compiled against a 408-byte extent (trailing pad).
 * The result vector is written through the SDK's inline VEC_Set, whose
 * arguments are evaluated z, y, x before the three stores.
 *
 * Addresses are Black-image addresses.
 */
int func_021BAE7C(RailPoint *startPoint, RailPoint *endPoint, const VecFx32 *pos, VecFx32 *outHit, fx32 *outDist,
                  VecFx32 *outAxis)
{
    VecFx32 segment;
    VecFx32 toPos;
    VecFx32 segmentDir;
    VecFx32 unitSegment;
    VecFx32 unitToPos;
    fx32 segmentLength;
    fx32 toPosLength;
    fx32 ratio;
    fx32 hitDist;
    fx32 heightDiff;

    VEC_Subtract(&startPoint->pos, &endPoint->pos, &segment);
    VEC_Subtract(pos, &endPoint->pos, &toPos);
    VEC_Normalize(&segment, &segmentDir);
    segmentLength = VEC_Mag(&segment);
    segment = segmentDir;
    toPosLength = VEC_Mag(&toPos);
    VEC_Normalize(&toPos, &toPos);
    ratio = FX_Div(toPosLength, segmentLength);
    toPos.x = FX_MUL(toPos.x, ratio);
    toPos.y = FX_MUL(toPos.y, ratio);
    toPos.z = FX_MUL(toPos.z, ratio);
    *outDist = VEC_DotProduct(&segment, &toPos);
    if (*outDist > 0x1000) {
        return 0;
    }
    if (*outDist < 0) {
        return 0;
    }
    *outDist = FX_MUL(*outDist, segmentLength);
    VEC_Normalize(&segment, &unitSegment);
    VEC_Normalize(&toPos, &unitToPos);
    VEC_CrossProduct(&unitSegment, &unitToPos, outAxis);
    hitDist = *outDist;
    VEC_Set(outHit, FX_MUL(segmentDir.x, hitDist), FX_MUL(segmentDir.y, hitDist), FX_MUL(segmentDir.z, hitDist));
    VEC_Add(&endPoint->pos, outHit, outHit);
    if (VEC_Distance(pos, outHit) >= 0x100000) {
        return 0;
    }
    heightDiff = pos->y - outHit->y;
    if (heightDiff < 0) {
        heightDiff = -heightDiff;
    }
    if (heightDiff > 0x8000) {
        return 0;
    }
    return 1;
}

void func_021BB014(RailManager *manager, RailWork *work, RailPoint *point)
{
    VecFx32 centrePos;
    u32 lineOffset;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;
    RailPoint *startPoint;

    startPoint = func_021B833C(work);
    if (startPoint == point)
        lineOffset = 0;
    else
        lineOffset = func_021B82FC(work);
    func_021B8328(work, lineOffset, &centrePos);
    camera = func_021B836C(work, point);
    fieldCamera = func_021B821C(manager);
    func_0218E124(fieldCamera, 0);
    func_0218EC54(fieldCamera);
    func_0218EC90(fieldCamera, &centrePos);
    func_0218ED34(fieldCamera, camera->param[0]);
    func_0218ED48(fieldCamera, (u16)camera->param[1]);
    func_0218ED58(fieldCamera, camera->param[2]);
}
