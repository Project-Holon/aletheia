/*
 * file:     fldeff_gyoe.c
 * unit:     yes
 * function: func_021BB484, func_021BB4A8, func_021BB4BC, func_021BB504, func_021BB528
 * address:  0x021BB484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Split by lane CL115 from field_nogrid_mapper.c at the __FILE__ anchor cuts.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
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
 */
#include "../ov010/fldmmdl_types.h"

typedef unsigned short u16;
typedef unsigned int   u32;

#define FLDEFF_GYOE_RES_MAX 4

/* Exclamation-mark ("gyoe") effect resources (0x38 bytes, fldeff_gyoe.c
 * line 0x6F allocation): one model resource, render object and object per
 * mark kind. */
typedef struct FldeffGyoe {
    void *fieldEffectCtrl;                 /* 0x00 */
    void *resource[FLDEFF_GYOE_RES_MAX];   /* 0x04 */
    void *renderObj[FLDEFF_GYOE_RES_MAX];  /* 0x14 */
    void *object[FLDEFF_GYOE_RES_MAX];     /* 0x24 */
    u16 resourceCount;                     /* 0x34 */
} FldeffGyoe;

/* Parameters handed to the effect task (copied by the task create call). */
typedef struct FldeffGyoeTaskParam {
    u32 type;                  /* 0x00: which mark */
    u32 sePlay;                /* 0x04: 1 plays the mark's sound */
    u32 gyoe;                  /* 0x08: the FldeffGyoe of the effect control */
    Mmdl *mmdl;                /* 0x0C: model the mark appears over */
    MmdlCheckInfo mmdlInfo;    /* 0x10: identity check of that model */
    u32 fieldMap;              /* 0x18 */
} FldeffGyoeTaskParam;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_020307B0(void *p);
extern void *func_021ABE24(void *fieldEffectCtrl);
extern void *func_02046E24(void *g3dHeap, u32 resId);
extern int func_02046FF8(void *resource);
extern void *func_02047400(void *resource, u32 index, void *texResource);
extern void *func_0204767C(void *renderObj, u32 *anime, int animeCount);
extern void func_02047738(void *object);
extern void func_02047504(void *renderObj);
extern void func_02046EFC(void *resource);
extern u32 func_021ABEA0(void *fieldEffectCtrl, u32 effectId);
extern void func_0216E1A4(Mmdl *mmdl, MmdlCheckInfo *info);
extern u32 func_021ABE14(void *fieldEffectCtrl);
extern void func_021BB778(int type);
extern void *func_021ABFA8(void *fieldEffectCtrl, const void *taskHeader, int a2, int a3, FldeffGyoeTaskParam *param, int a5);

FldeffGyoe *func_021BB484(void *fieldEffectCtrl, int heapId);
void func_021BB4A8(void *fieldEffectCtrl, FldeffGyoe *gyoe);
void func_021BB4BC(FldeffGyoe *gyoe);
void func_021BB504(FldeffGyoe *gyoe);

extern u32 d_021D9A6C[FLDEFF_GYOE_RES_MAX];
extern int d_021D9A7C;
extern int d_021DE2E8;

FldeffGyoe *func_021BB484(void *fieldEffectCtrl, int heapId)
{
    FldeffGyoe *gyoe = func_02030734(heapId, sizeof(FldeffGyoe), 1, (const char *)&d_021DE2E8, 0x6F);
    gyoe->fieldEffectCtrl = fieldEffectCtrl;
    func_021BB4BC(gyoe);
    return gyoe;
}

void func_021BB4A8(void *fieldEffectCtrl, FldeffGyoe *gyoe)
{
    func_021BB504(gyoe);
    func_020307B0(gyoe);
}

void func_021BB4BC(FldeffGyoe *gyoe)
{
    void *g3dHeap = func_021ABE24(gyoe->fieldEffectCtrl);
    int i;
    for (i = 0; i < FLDEFF_GYOE_RES_MAX; i++) {
        gyoe->resource[i] = func_02046E24(g3dHeap, d_021D9A6C[i]);
        func_02046FF8(gyoe->resource[i]);
        gyoe->renderObj[i] = func_02047400(gyoe->resource[i], 0, gyoe->resource[i]);
        gyoe->object[i] = func_0204767C(gyoe->renderObj[i], 0, 0);
    }
    gyoe->resourceCount = FLDEFF_GYOE_RES_MAX;
}

void func_021BB504(FldeffGyoe *gyoe)
{
    int i;
    for (i = 0; i < FLDEFF_GYOE_RES_MAX; i++) {
        func_02047738(gyoe->object[i]);
        func_02047504(gyoe->renderObj[i]);
        func_02046EFC(gyoe->resource[i]);
    }
}

void *func_021BB528(void *fieldEffectCtrl, Mmdl *mmdl, u32 type, u32 sePlay)
{
    FldeffGyoeTaskParam param;
    param.type = type;
    param.sePlay = sePlay;
    param.gyoe = func_021ABEA0(fieldEffectCtrl, 4);
    param.mmdl = mmdl;
    func_0216E1A4(mmdl, &param.mmdlInfo);
    param.fieldMap = func_021ABE14(fieldEffectCtrl);
    if (sePlay == 1)
        func_021BB778(type);
    return func_021ABFA8(fieldEffectCtrl, &d_021D9A7C, 0, 0, &param, 0);
}
