/*
 * file:     fldmmdl_blact.c
 * unit:     yes
 * function: func_0219C4AC, func_0219C52C, func_0219C554, func_0219C5D0, func_0219C5FC, func_0219C624, func_0219C630, func_0219C648, func_0219C658, func_0219C680, func_0219C6B8, func_0219C74C, func_0219C780, func_0219C7B4, func_0219C7EC, func_0219C814, func_0219C880, func_0219C8D4, func_0219C928, func_0219C98C, func_0219C9D0, func_0219C9DC, func_0219C9E0, func_0219CA00, func_0219CA34, func_0219CA40, func_0219CA6C, func_0219CA98, func_0219CAD8, func_0219CAF4, func_0219CB24, func_0219CB64, func_0219CB98, func_0219CBD4, func_0219CBE0, func_0219CC80, func_0219CCF0, func_0219CD68, func_0219CDAC, func_0219CE60, func_0219CEAC, func_0219CF00, func_0219CF54, func_0219CFB0, func_0219D064, func_0219D0F4, func_0219D144, func_0219D184, func_0219D1F8, func_0219D208, func_0219D2CC, func_0219D2F4, func_0219D324, func_0219D390, func_0219D3B4, func_0219D3E4, func_0219D3F0
 * address:  0x0219C4AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_blact.c at 0x0219D448 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02046FF8  0x02046FF8  arm
 *   func_02050080  0x02050080  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0204F044  0x0204F044  arm
 *   func_02050238  0x02050238  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021D75C4     0x021D75C4  data  a4
 *   d_021D8064     0x021D8064  data  a4
 *   func_02050330  0x02050330  arm
 *   func_02050304  0x02050304  arm
 *   func_0204F214  0x0204F214  arm
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D51C  0x0216D51C  thumb  ov010
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DDD70     0x021DDD70  data  a1
 *   d_021D8058     0x021D8058  data  a4
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_0216E2E0  0x0216E2E0  thumb  ov010
 *   func_0216E2AC  0x0216E2AC  thumb  ov010
 *   func_02050340  0x02050340  arm
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   d_021D75D0     0x021D75D0  data  a4
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_02050894  0x02050894  arm
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02050468  0x02050468  arm
 *   func_02030734  0x02030734  arm
 *   func_0216E3C8  0x0216E3C8  thumb  ov010
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   d_021D7F68  0x021D7F68  data  ov021
 *   func_020500F0  0x020500F0  arm
 */
#include "fldmmdl_blact_types.h"

extern int func_02046FF8(void *res);
extern struct BbBoard *func_02050080(struct BbActSys *sys);
extern u32 func_02047388(void *res);
extern u32 func_020473B8(void *res);
extern int func_0204F044(struct BbBoard *board, int texKey, int plttKey, int a3, u32 texFmt, u8 cellWidth, u8 cellHeight);
extern u32 func_02050238(struct BbActSys *sys, u32 imageId, u32 c);
extern void func_02046EFC(void *res);
extern u16 func_02050330(struct BbActSys *sys, int slotIndex);
extern int func_02050304(struct BbActSys *sys, int slotIndex);
extern void func_0204F214(struct BbBoard *board, int imageId);
extern u32 func_0216D4F8(MmdlSys *sys);
extern void func_0216D51C(MmdlSys *sys, BlactSys *cont);
extern void func_0204ED70(struct BbBoard *board, VecFx32 *scale);
extern void func_0204EDB0(struct BbBoard *board, u8 *polyIdBase);
extern BlactSys *func_0216D520(MmdlSys *sys);
extern u32 func_020307B0(void *p);
extern MmdlSys *func_0216D67C(Mmdl *mmdl);
extern void func_0216E2E8(MmdlSys *sys, u32 code, MmdlObjCodeParam *out);
extern u16 func_0216E2E0(MmdlSys *sys);
extern void func_0216E2AC(MmdlSys *sys, int index, MmdlObjCodeParam *out);
extern u16 func_02050340(struct BbActSys *sys, u16 base, const struct BbActDesc *desc, u32 count, u32 mode);
extern void func_02050804(struct BbActSys *sys, int entryIndex, void *cmdLists, u16 listCount);
extern void func_0205082C(struct BbActSys *sys, int entryIndex, u32 listIndex);
extern void func_020507F0(struct BbActSys *sys, int entryIndex, u32 enabled);
extern MmdlObjCodeParam *func_0216E3C4(Mmdl *mmdl);
extern void func_02197CCC(Mmdl *mmdl, VecFx32 *out);
extern int func_02050894(struct BbActSys *sys, int entryIndex, int slotIndex);
extern u32 func_020508D8(struct BbActSys *sys, u32 entryIndex);
extern void func_02050278(struct BbActSys *sys, u32 first, u32 count);
extern int func_0216DFC4(Mmdl *mmdl, u32 code);
extern u16 func_0216D598(Mmdl *mmdl);
extern void func_02050468(struct BbActSys *sys, u16 first, u32 count);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short line);
extern u16 *func_0216E3C8(const MmdlObjCodeParam *param);
extern void *func_0216D518(MmdlSys *sys);
extern void *func_02046E24(void *arcHandle, u32 dataId);
extern u16 func_0216D4F0(MmdlSys *sys);
extern void func_0216D758(Mmdl *mmdl);
extern void func_02082BCC(void *p, u32 value, u32 size);
extern int func_0216D7A8(Mmdl *mmdl, unsigned int kind);
extern void func_0216E204(Mmdl *mmdl, u32 code);
extern int func_0216DA30(Mmdl *mmdl, BlactCodeChange *change);
extern u16 func_020500F0(struct BbActSys *sys, const struct BbActRec *recs, u32 count);

int func_0219C4AC(struct BbActSys *sys, void *res, u32 mdlSize, u32 texSize);
void func_0219C52C(struct BbActSys *sys, u32 slotIndex);
void func_0219C554(MmdlSys *mmdlSys, struct BbActSys *bbdActSys, u32 resMax);
void func_0219C5D0(MmdlSys *mmdlSys);
void func_0219C5FC(MmdlSys *mmdlSys);
void func_0219C624(MmdlSys *mmdlSys);
int func_0219C630(MmdlSys *mmdlSys);
int func_0219C648(Mmdl *mmdl);
void func_0219C658(MmdlSys *mmdlSys, u32 code);
void func_0219C680(MmdlSys *mmdlSys);
u32 func_0219C6B8(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex);
u32 func_0219C74C(Mmdl *mmdl, u16 slotIndex);
u32 func_0219C780(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex, u16 paletteSlot);
u32 func_0219C7B4(Mmdl *mmdl, u16 slotIndex, u16 paletteSlot);
u32 func_0219C7EC(Mmdl *mmdl, u32 code);
int func_0219C814(Mmdl *mmdl, u16 *outBlactId);
void func_0219C880(BlactSys *cont, Mmdl *mmdl, u32 blactId, u16 code);
void func_0219C8D4(Mmdl *mmdl, u32 blactId);
int func_0219C928(MmdlSys *mmdlSys, const MmdlObjCodeParam *param, u16 *actor, VecFx32 *pos, BlactAddActorHook hook, u32 hookArg);
void func_0219C98C(MmdlSys *mmdlSys, u16 *actor);
void func_0219C9D0(struct BbActSys *sys, int entryIndex, u32 arg);
struct BbActSys *func_0219C9DC(BlactSys *cont);
void func_0219C9E0(Mmdl *mmdl, u16 *width, u16 *height);
void func_0219CA00(BlactResTable *table, u32 count, u32 heapId);
void func_0219CA34(BlactResTable *table);
void func_0219CA40(BlactResTable *table, u16 code, u16 slotIndex, u16 flags);
void func_0219CA6C(BlactResTable *table, u16 code);
int func_0219CA98(BlactResTable *table, u32 code, u16 *slotIndex, u16 *flags);
void func_0219CAD8(BlactSys *cont, u32 count);
void func_0219CAF4(BlactSys *cont);
void func_0219CB24(BlactSys *cont, void *resHandle, u16 code, u32 mdlSize, u8 texSize, u32 flags);
void func_0219CB64(BlactSys *cont, const MmdlObjCodeParam *param, u32 flags);
void func_0219CB98(BlactSys *cont, u16 code);
int func_0219CBD4(BlactSys *cont, u32 code, u16 *slotIndex, u16 *flags);
void func_0219CBE0(BlactSys *cont);
void func_0219CC80(BlactSys *cont);
int func_0219CCF0(BlactSys *cont);
void func_0219CD68(BlactSys *cont, u16 code, u8 mdlSize, u8 texSize, u16 resId, u32 flags);
void func_0219CDAC(BlactSys *cont);
int func_0219CE60(BlactSys *cont, u32 code, u32 mdlSize, u32 texSize, u16 resId, u32 flags);
void func_0219CEAC(BlactSys *cont);
int func_0219CF00(BlactSys *cont, unsigned int code, unsigned short *outFlags);
int func_0219CF54(BlactSys *cont, unsigned int code);
void func_0219CFB0(BlactSys *cont, Mmdl *mmdl, const MmdlObjCodeParam *param, u16 *outBlactId, BlactAddActorHook hook, u32 hookArg, VecFx32 *pos);
void func_0219D064(BlactSys *cont, BlactEntry *entry);
void func_0219D0F4(BlactSys *cont);
int func_0219D144(BlactSys *cont, unsigned int code, Mmdl *mmdl);
void func_0219D184(BlactSys *cont, Mmdl *mmdl);
void func_0219D1F8(BlactEntry *entry);
void func_0219D208(Mmdl *mmdl, unsigned int code);
void func_0219D2CC(BlactSys *cont);
void func_0219D2F4(BlactSys *cont);
void func_0219D324(BlactSys *cont, BlactCodeChange *change);
void func_0219D390(BlactSys *cont);
int func_0219D3B4(BlactSys *cont, Mmdl *mmdl, u16 blactId);
BlactAnimeTable *func_0219D3E4(int animId);
unsigned short func_0219D3F0(BlactSys *cont, int code, int mdlSize, int texSize, void *resHandle, int kind);

extern u16 d_021D75C4[][2];       /* cell width and height per model size */
extern u16 d_021D8064[];          /* texture format per texture size */
extern unsigned char d_021DDD70[]; /* allocation site name */
extern VecFx32 d_021D8058;        /* board scale */
extern u16 d_021D75D0[][2];       /* billboard width and height per model size */
extern BlactAnimeTable d_021D7F68[];

/* Adds a slot whose image stays in VRAM; the archive resource is freed. */
int func_0219C4AC(struct BbActSys *sys, void *res, u32 mdlSize, u32 texSize)
{
    int slotIndex = -1;
    if (func_02046FF8(res) == 1) {
        struct BbBoard *board = func_02050080(sys);
        u16 *cellSize = d_021D75C4[mdlSize];
        u32 texKey = func_02047388(res);
        slotIndex = func_02050238(sys, func_0204F044(board, texKey, func_020473B8(res), 0, d_021D8064[texSize], (u8)cellSize[0], (u8)cellSize[1]), 0);
        func_02046EFC(res);
    }
    return slotIndex;
}

void func_0219C52C(struct BbActSys *sys, u32 slotIndex)
{
    u32 imageId = func_02050330(sys, slotIndex);
    struct BbBoard *board = func_02050080(sys);
    func_02050304(sys, slotIndex);
    func_0204F214(board, imageId);
}

void func_0219C554(MmdlSys *mmdlSys, struct BbActSys *bbdActSys, u32 resMax)
{
    BlactSys *cont = func_02030734(func_0216D4F8(mmdlSys), 0x24, 1, (const char *)d_021DDD70, 360);
    struct BbBoard *board;
    VecFx32 scale;
    u8 polyIdBase;
    cont->mmdlSys = mmdlSys;
    cont->bbdActSys = bbdActSys;
    cont->resMax = resMax;
    func_0216D51C(mmdlSys, cont);
    func_0219CAD8(cont, resMax);
    func_0219CBE0(cont);
    func_0219D2CC(cont);
    board = func_02050080(bbdActSys);
    scale = d_021D8058;
    func_0204ED70(board, &scale);
    polyIdBase = 0;
    func_0204EDB0(board, &polyIdBase);
}

void func_0219C5D0(MmdlSys *mmdlSys)
{
    BlactSys *cont = func_0216D520(mmdlSys);
    func_0219D2F4(cont);
    func_0219CC80(cont);
    func_0219CAF4(cont);
    func_020307B0(cont);
    func_0216D51C(mmdlSys, 0);
}

void func_0219C5FC(MmdlSys *mmdlSys)
{
    BlactSys *cont = func_0216D520(mmdlSys);
    if (cont != 0) {
        if (cont->reserve != 0) {
            func_0219D0F4(cont);
            func_0219CDAC(cont);
        }
        func_0219D390(cont);
        cont->entryHookFlag = 0;
    }
}

void func_0219C624(MmdlSys *mmdlSys)
{
    func_0219CEAC(func_0216D520(mmdlSys));
}

int func_0219C630(MmdlSys *mmdlSys)
{
    if (func_0219CCF0(func_0216D520(mmdlSys)) == 1) {
        return 1;
    }
    return 0;
}

int func_0219C648(Mmdl *mmdl)
{
    return func_0216D520(func_0216D67C(mmdl))->entryHookFlag;
}

void func_0219C658(MmdlSys *mmdlSys, u32 code)
{
    MmdlObjCodeParam param;
    BlactSys *cont = func_0216D520(mmdlSys);
    func_0216E2E8(mmdlSys, code, &param);
    func_0219CB64(cont, &param, 0);
}

void func_0219C680(MmdlSys *mmdlSys)
{
    MmdlObjCodeParam param;
    BlactSys *cont = func_0216D520(mmdlSys);
    int count = func_0216E2E0(mmdlSys);
    int i;
    for (i = 0; i < count; i++) {
        func_0216E2AC(mmdlSys, i, &param);
        func_0219CB64(cont, &param, 0);
    }
}

u32 func_0219C6B8(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex)
{
    BlactSys *cont = func_0216D520(mmdlSys);
    struct BbActDesc desc;
    u32 blactId;
    BlactAnimeTable *anime;
    u16 *size = d_021D75D0[mdlSize];
    struct BbActSys *sys;
    desc.slot = slotIndex;
    desc.width = d_021D75D0[mdlSize][0];
    desc.height = size[1];
    desc.pos = *pos;
    desc.layer = 0x1f;
    desc.flags = 1;
    desc.color = 1;
    desc.hook = func_0219C9D0;
    desc.hookArg = (u32)cont;
    blactId = func_02050340(cont->bbdActSys, cont->slotBase, &desc, 1, 0);
    anime = func_0219D3E4(animId);
    if (anime->cmdLists != 0) {
        func_02050804(cont->bbdActSys, blactId, anime->cmdLists, (u16)anime->listCount);
        sys = cont->bbdActSys;
        func_0205082C(sys, blactId, 0);
        func_020507F0(sys, blactId, 1);
    }
    return blactId;
}

u32 func_0219C74C(Mmdl *mmdl, u16 slotIndex)
{
    MmdlSys *mmdlSys = func_0216D67C(mmdl);
    MmdlObjCodeParam *param = func_0216E3C4(mmdl);
    VecFx32 pos;
    func_02197CCC(mmdl, &pos);
    return func_0219C6B8(mmdlSys, &pos, param->mdlSize, param->animId, slotIndex);
}

u32 func_0219C780(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex, u16 paletteSlot)
{
    u32 blactId = func_0219C6B8(mmdlSys, pos, mdlSize, animId, slotIndex);
    if (paletteSlot != 0xFFFF) {
        func_02050894(func_0216D520(mmdlSys)->bbdActSys, blactId, paletteSlot);
    }
    return blactId;
}

u32 func_0219C7B4(Mmdl *mmdl, u16 slotIndex, u16 paletteSlot)
{
    MmdlSys *mmdlSys = func_0216D67C(mmdl);
    MmdlObjCodeParam *param = func_0216E3C4(mmdl);
    VecFx32 pos;
    func_02197CCC(mmdl, &pos);
    return func_0219C780(mmdlSys, &pos, param->mdlSize, param->animId, slotIndex, paletteSlot);
}

u32 func_0219C7EC(Mmdl *mmdl, u32 code)
{
    u16 res[2]; /* [0] flags, [1] slot index */
    func_0219CBD4(func_0216D520(func_0216D67C(mmdl)), code, &res[1], &res[0]);
    return func_0219C74C(mmdl, res[1]);
}

/* Adds the model's actor now, or reserves it when the resource is not ready. */
int func_0219C814(Mmdl *mmdl, u16 *outBlactId)
{
    BlactSys *cont = func_0216D520(func_0216D67C(mmdl));
    MmdlObjCodeParam *param = func_0216E3C4(mmdl);
    u16 res[2]; /* [0] flags, [1] slot index */
    func_0219CBD4(cont, param->code, &res[1], &res[0]);
    if (res[1] != 0xFFFF && (FLDMMDL_BLACT_RESBIT_TRANS & res[0]) == 0) {
        *outBlactId = func_0219C7EC(mmdl, param->code);
        return 1;
    }
    *outBlactId = 0xFFFF;
    func_0219CFB0(cont, mmdl, param, outBlactId, 0, 0, 0);
    return 0;
}

void func_0219C880(BlactSys *cont, Mmdl *mmdl, u32 blactId, u16 code)
{
    u16 res[2]; /* [0] flags, [1] slot index */
    if (func_0219CBD4(cont, code, &res[1], &res[0]) == 1) {
        if (res[0] & FLDMMDL_BLACT_RESBIT_TRANS) {
            u32 slotIndex = func_020508D8(cont->bbdActSys, blactId);
            func_02050278(cont->bbdActSys, slotIndex, 1);
        }
        if (res[0] & FLDMMDL_BLACT_RESBIT_GUEST) {
            if (func_0216DFC4(mmdl, code) == 0)
                func_0219CB98(cont, code);
        }
    }
}

void func_0219C8D4(Mmdl *mmdl, u32 blactId)
{
    u16 code = func_0216D598(mmdl);
    BlactSys *cont = func_0216D520(func_0216D67C(mmdl));
    if (blactId == 0xFFFF) {
        func_0219D184(cont, mmdl);
        return;
    }
    if (func_0219D3B4(cont, mmdl, blactId) != 1) {
        func_0219C880(cont, mmdl, (u16)blactId, code);
        func_02050468(cont->bbdActSys, blactId, 1);
    }
}

/* actor: [0] resource flags, [1] actor id.
 * param is const: that is what lets the mdlSize/animId loads schedule above
 * the outgoing stack-argument store of slotIndex. */
int func_0219C928(MmdlSys *mmdlSys, const MmdlObjCodeParam *param, u16 *actor, VecFx32 *pos, BlactAddActorHook hook, u32 hookArg)
{
    u16 slotIndex;
    BlactSys *cont = func_0216D520(mmdlSys);
    func_0219CBD4(cont, param->code, &slotIndex, actor);
    if (!(*actor & FLDMMDL_BLACT_RESBIT_TRANS)) {
        actor[1] = func_0219C6B8(mmdlSys, pos, param->mdlSize, param->animId, slotIndex);
        return 1;
    }
    actor[1] = 0xFFFF;
    func_0219CFB0(cont, 0, param, &actor[1], hook, hookArg, pos);
    return 0;
}

void func_0219C98C(MmdlSys *mmdlSys, u16 *actor)
{
    BlactSys *cont = func_0216D520(mmdlSys);
    if (actor[1] != 0xFFFF) {
        if (actor[0] & FLDMMDL_BLACT_RESBIT_TRANS) {
            u32 slotIndex = func_020508D8(cont->bbdActSys, actor[1]);
            func_02050278(cont->bbdActSys, slotIndex, 1);
        }
        func_02050468(cont->bbdActSys, actor[1], 1);
    }
    actor[0] = 0;
    actor[1] = 0xFFFF;
}

/* Entry hook of every actor (BbActDesc.hook); arg is the container. */
void func_0219C9D0(struct BbActSys *sys, int entryIndex, u32 arg)
{
    ((BlactSys *)arg)->entryHookFlag |= 1;
}

struct BbActSys *func_0219C9DC(BlactSys *cont)
{
    return cont->bbdActSys;
}

void func_0219C9E0(Mmdl *mmdl, u16 *width, u16 *height)
{
    MmdlObjCodeParam *param = func_0216E3C4(mmdl);
    u16 *size = d_021D75D0[param->mdlSize];
    *width = size[0];
    *height = size[1];
}

void func_0219CA00(BlactResTable *table, u32 count, u32 heapId)
{
    BlactResIndex *entry = func_02030734(heapId, count * sizeof(BlactResIndex), 1, (const char *)d_021DDD70, 0x484);
    table->count = count;
    table->entries = entry;
    do {
        entry->code = 0xFFFF;
        entry->slotIndex = 0xFFFF;
        entry++;
    } while (--count);
}

void func_0219CA34(BlactResTable *table)
{
    func_020307B0(table->entries);
}

void func_0219CA40(BlactResTable *table, u16 code, u16 slotIndex, u16 flags)
{
    int i;
    BlactResIndex *entry = table->entries;
    i = 0;
    do {
        if (entry->code == 0xFFFF) {
            entry->code = code;
            entry->slotIndex = slotIndex;
            entry->flags = flags;
            return;
        }
        i++;
        entry++;
    } while (i < table->count);
}

void func_0219CA6C(BlactResTable *table, u16 code)
{
    int i;
    BlactResIndex *entry = table->entries;
    i = 0;
    do {
        if (entry->code == code) {
            entry->code = 0xFFFF;
            entry->slotIndex = 0xFFFF;
            entry->flags = 0;
            return;
        }
        i++;
        entry++;
    } while (i < table->count);
}

int func_0219CA98(BlactResTable *table, u32 code, u16 *slotIndex, u16 *flags)
{
    int i = 0;
    BlactResIndex *entry = table->entries;
    if (slotIndex) *slotIndex = 0xFFFF;
    do {
        if (entry->code == code) {
            if (slotIndex) *slotIndex = entry->slotIndex;
            if (flags) *flags = entry->flags;
            return 1;
        }
        i++;
        entry++;
    } while (i < table->count);
    return 0;
}

void func_0219CAD8(BlactSys *cont, u32 count)
{
    func_0219CA00(&cont->resTable, count, func_0216D4F8(cont->mmdlSys));
}

void func_0219CAF4(BlactSys *cont)
{
    int i;
    BlactResIndex *entry = cont->resTable.entries;
    i = 0;
    do {
        if (entry->code != 0xFFFF) {
            func_0219CB98(cont, entry->code);
        }
        i++;
        entry++;
    } while (i < cont->resTable.count);
    func_0219CA34(&cont->resTable);
}

void func_0219CB24(BlactSys *cont, void *resHandle, u16 code, u32 mdlSize, u8 texSize, u32 flags)
{
    int kind = FLDMMDL_BLACT_SLOT_VRAM;
    u16 slotIndex;
    if (flags & FLDMMDL_BLACT_RESBIT_TRANS) kind = 2;
    slotIndex = func_0219D3F0(cont, code, mdlSize, texSize, resHandle, kind);
    func_0219CA40(&cont->resTable, code, slotIndex, (u16)flags);
}

void func_0219CB64(BlactSys *cont, const MmdlObjCodeParam *param, u32 flags)
{
    u16 *resId = func_0216E3C8(param);
    func_0219CB24(cont, func_02046E24(func_0216D518(cont->mmdlSys), *resId), param->code, param->mdlSize, param->texSize, flags);
}

void func_0219CB98(BlactSys *cont, u16 code)
{
    u16 res[2]; /* [0] slot index, [1] flags */
    func_0219CA98(&cont->resTable, code, &res[0], &res[1]);
    if (res[1] & FLDMMDL_BLACT_RESBIT_TRANS) {
        func_02050278(cont->bbdActSys, res[0], 1);
    } else {
        func_0219C52C(cont->bbdActSys, res[0]);
    }
    func_0219CA6C(&cont->resTable, code);
}

int func_0219CBD4(BlactSys *cont, u32 code, u16 *slotIndex, u16 *flags)
{
    return func_0219CA98(&cont->resTable, code, slotIndex, flags);
}

void func_0219CBE0(BlactSys *cont)
{
    u32 heapId = func_0216D4F8(cont->mmdlSys);
    BlactReserve *reserve = func_02030734(heapId, sizeof(BlactReserve), 1, (const char *)d_021DDD70, 1491);
    BlactResReserve *res;
    int i;
    reserve->resReserveMax = cont->resMax;
    reserve->actReserveMax = func_0216D4F0(cont->mmdlSys);
    reserve->addResMax = 1;
    res = func_02030734(heapId, sizeof(BlactResReserve) * reserve->resReserveMax, 1, (const char *)d_021DDD70, 1498);
    reserve->resReserve = res;
    i = 0;
    if (i < reserve->resReserveMax) {
        for (; i < reserve->resReserveMax; i++, res++)
            res->code = 0xFFFF;
    }
    reserve->addRes = func_02030734(heapId, sizeof(BlactAddRes) * reserve->addResMax, 1, (const char *)d_021DDD70, 1511);
    reserve->actReserve = func_02030734(heapId, sizeof(BlactEntry) * reserve->actReserveMax, 1, (const char *)d_021DDD70, 1513);
    reserve->isActive = 1;
    cont->reserve = reserve;
}

void func_0219CC80(BlactSys *cont)
{
    BlactReserve *reserve = cont->reserve;
    u32 i;
    BlactAddRes *addRes;
    BlactEntry *entry;
    if (reserve == 0) return;
    i = 0;
    reserve->isActive = i;
    func_020307B0(reserve->resReserve);
    addRes = reserve->addRes;
    if (i < reserve->addResMax) {
        for (; i < reserve->addResMax; i++, addRes++) {
            if (addRes->resHandle != 0)
                func_02046EFC(addRes->resHandle);
        }
    }
    func_020307B0(reserve->addRes);
    i = 0;
    entry = reserve->actReserve;
    if (i < reserve->actReserveMax) {
        for (; i < reserve->actReserveMax; i++, entry++) {
            if (entry->outBlactId != 0 && entry->resHandle != 0)
                func_02046EFC(entry->resHandle);
        }
    }
    func_020307B0(reserve->actReserve);
    func_020307B0(reserve);
    cont->reserve = 0;
}

/*
 * The reserve pointers are const: mwcc then rereads each u16 count inside its
 * loop and keeps the record pointer in r0 instead of hoisting the count into
 * a register.
 */
int func_0219CCF0(BlactSys *cont)
{
    const BlactReserve *reserve = cont->reserve;
    u32 i;
    const BlactResReserve *res;
    const BlactAddRes *addRes;
    const BlactEntry *entry;
    res = reserve->resReserve;
    for (i = 0; i < reserve->resReserveMax; i++, res++) {
        if (res->code != 0xFFFF) {
            return 1;
        }
    }
    addRes = reserve->addRes;
    for (i = 0; i < reserve->addResMax; i++, addRes++) {
        if (addRes->resHandle != 0) {
            return 1;
        }
    }
    entry = reserve->actReserve;
    for (i = 0; i < reserve->actReserveMax; i++, entry++) {
        if (entry->outBlactId != 0 && entry->resHandle != 0) {
            return 1;
        }
    }
    return 0;
}

void func_0219CD68(BlactSys *cont, u16 code, u8 mdlSize, u8 texSize, u16 resId, u32 flags)
{
    BlactReserve *reserve = cont->reserve;
    u32 i;
    u32 count = reserve->resReserveMax;
    /* stand-in: the record cursor reuses the variable of the first parameter
     * (the image keeps it in that parameter's register, copied to r4); a
     * separate cursor variable is allocated to other registers. */
    cont = (BlactSys *)reserve->resReserve;
    for (i = 0; i < count; i++, cont = (BlactSys *)((BlactResReserve *)cont + 1)) {
        BlactResReserve *res = (BlactResReserve *)cont;
        if (res->code == 0xFFFF) {
            res->code = code;
            res->mdlSize = mdlSize;
            res->texSize = texSize;
            res->resId = resId;
            res->flags = flags;
            return;
        }
    }
}

/* Loads the reserved resources, then moves the free records to the end. */
void func_0219CDAC(BlactSys *cont)
{
    BlactReserve *reserve = cont->reserve;
    u32 j = 0;
    u32 k = 0;
    BlactResReserve *res = reserve->resReserve;
    BlactResReserve *base;
    for (; j < reserve->resReserveMax; j++, res++) {
        if (res->code != 0xFFFF) {
            if (func_0219CE60(cont, res->code, res->mdlSize, res->texSize, res->resId, res->flags) == 0)
                break;
            res->code = 0xFFFF;
            k++;
            if (k >= reserve->addResMax)
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = reserve->resReserve;
        for (; j < (u32)reserve->resReserveMax - 1; j++) {
            BlactResReserve *free = &base[j];
            if (free->code == 0xFFFF) {
                for (k = j + 1; k < reserve->resReserveMax; k++) {
                    if (base[k].code != 0xFFFF) {
                        *free = base[k];
                        base[k].code = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}

int func_0219CE60(BlactSys *cont, u32 code, u32 mdlSize, u32 texSize, u16 resId, u32 flags)
{
    BlactReserve *reserve = cont->reserve;
    BlactAddRes *addRes = reserve->addRes;
    u32 i;
    for (i = 0; i < reserve->addResMax; i++, addRes++) {
        if (addRes->resHandle == 0) {
            addRes->isReady = 0;
            addRes->code = code;
            addRes->mdlSize = mdlSize;
            addRes->texSize = texSize;
            addRes->flags = flags;
            addRes->resHandle = func_02046E24(func_0216D518(cont->mmdlSys), resId);
            addRes->isReady = 1;
            return 1;
        }
    }
    return 0;
}

/* Registers the loaded resources in billboard slots. */
void func_0219CEAC(BlactSys *cont)
{
    unsigned int i;
    BlactAddRes *addRes;
    BlactReserve *reserve;
    reserve = cont->reserve;
    if (reserve != 0 && reserve->isActive == 1) {
        i = 0;
        addRes = reserve->addRes;
        if (!(i < reserve->addResMax)) {
            return;
        }
        for (; i < reserve->addResMax; i++, addRes++) {
            if (addRes->resHandle != 0 && addRes->isReady == 1) {
                addRes->isReady = 0;
                func_0219CB24(cont, addRes->resHandle, addRes->code, addRes->mdlSize,
                              addRes->texSize, addRes->flags);
                addRes->resHandle = 0;
            }
        }
    }
}

int func_0219CF00(BlactSys *cont, unsigned int code, unsigned short *outFlags)
{
    unsigned int i;
    BlactResReserve *res;
    unsigned int resCount;
    unsigned int j;
    BlactAddRes *addRes;
    unsigned int addCount;
    BlactReserve *reserve = cont->reserve;
    i = 0;
    resCount = reserve->resReserveMax;
    res = reserve->resReserve;
    for (; i < resCount; i++, res++) {
        if (res->code == code) {
            *outFlags = res->flags;
            return 1;
        }
    }
    addCount = reserve->addResMax;
    j = 0;
    addRes = reserve->addRes;
    for (; j < addCount; j++, addRes++) {
        if (addRes->code == code && addRes->resHandle != 0) {
            *outFlags = addRes->flags;
            return 1;
        }
    }
    return 0;
}

int func_0219CF54(BlactSys *cont, unsigned int code)
{
    unsigned int i;
    BlactResReserve *res;
    unsigned int resCount;
    unsigned int j;
    BlactAddRes *addRes;
    unsigned int addCount;
    BlactReserve *reserve = cont->reserve;
    i = 0;
    resCount = reserve->resReserveMax;
    res = reserve->resReserve;
    for (; i < resCount; i++, res++) {
        if (res->code == code) {
            res->code = 0xFFFF;
            return 1;
        }
    }
    addCount = reserve->addResMax;
    j = 0;
    addRes = reserve->addRes;
    for (; j < addCount; j++, addRes++) {
        if (addRes->resHandle != 0 && addRes->code == code) {
            addRes->isReady = 0;
            func_02046EFC(addRes->resHandle);
            addRes->resHandle = 0;
            return 1;
        }
    }
    return 0;
}

/* Reserves an actor; its resource is reserved too when nobody has it yet. */
void func_0219CFB0(BlactSys *cont, Mmdl *mmdl, const MmdlObjCodeParam *param, u16 *outBlactId, BlactAddActorHook hook, u32 hookArg, VecFx32 *pos)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    unsigned short res[2]; /* [0] flags, [1] slot index */
    u16 *resId;
    i = 0;
    count = func_0216D4F0(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    for (; i < count; i++, entry++) {
        if (entry->outBlactId == 0) {
            entry->isWaiting = 0;
            entry->mmdl = mmdl;
            entry->outBlactId = outBlactId;
            entry->code = param->code;
            entry->mdlSize = param->mdlSize;
            entry->texSize = param->texSize;
            entry->animId = param->animId;
            func_0219CBD4(cont, entry->code, &res[1], &res[0]);
            if (res[1] == 0xFFFF && func_0219CF00(cont, entry->code, &res[0]) == 0) {
                resId = func_0216E3C8(param);
                res[0] = FLDMMDL_BLACT_RESBIT_GUEST;
                func_0219CD68(cont, entry->code, entry->mdlSize,
                              entry->texSize, *resId, FLDMMDL_BLACT_RESBIT_GUEST);
            }
            entry->hook = hook;
            entry->hookArg = hookArg;
            if (pos != 0) {
                entry->pos = *pos;
            }
            entry->isWaiting = 1;
            return;
        }
    }
}

void func_0219D064(BlactSys *cont, BlactEntry *entry)
{
    unsigned short slot[3]; /* [0] palette slot, [1] flags, [2] image slot */
    u32 blactId;
    slot[0] = 0xFFFF;
    entry->isWaiting = 0;
    if (entry->resHandle != 0) {
        slot[2] = func_0219D3F0(cont, entry->code, entry->mdlSize,
                                entry->texSize, entry->resHandle, 1);
        entry->resHandle = 0;
        func_0219CBD4(cont, entry->code, &slot[0], &slot[1]);
    } else {
        func_0219CBD4(cont, entry->code, &slot[2], &slot[1]);
    }
    if (entry->mmdl != 0) {
        blactId = func_0219C7B4(entry->mmdl, slot[2], slot[0]);
    } else {
        blactId = func_0219C780(cont->mmdlSys, &entry->pos, entry->mdlSize,
                                entry->animId, slot[2], slot[0]);
    }
    *entry->outBlactId = blactId;
    if (entry->hook != 0) {
        entry->hook(*entry->outBlactId, entry->hookArg);
    }
    if (entry->mmdl != 0) {
        func_0216D758(entry->mmdl);
    }
}

/* Adds the reserved actors whose resource is now registered. */
void func_0219D0F4(BlactSys *cont)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    unsigned short res[2]; /* [0] slot index, [1] flags */
    i = 0;
    count = func_0216D4F0(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    if (count == 0) {
        return;
    }
    for (; i < count; i++, entry++) {
        if (entry->outBlactId != 0 && entry->isWaiting == 1) {
            if (func_0219CBD4(cont, entry->code, &res[0], &res[1]) == 1) {
                func_0219D064(cont, entry);
                func_0219D1F8(entry);
            }
        }
    }
}

int func_0219D144(BlactSys *cont, unsigned int code, Mmdl *mmdl)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    i = 0;
    count = func_0216D4F0(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    for (; i < count; i++, entry++) {
        if (entry->outBlactId != 0 && entry->mmdl != 0 && entry->mmdl != mmdl && entry->code == code) {
            return 1;
        }
    }
    return 0;
}

void func_0219D184(BlactSys *cont, Mmdl *mmdl)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    unsigned short flags;
    i = 0;
    count = func_0216D4F0(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    for (; i < count; i++, entry++) {
        if (entry->outBlactId != 0 && entry->mmdl == mmdl) {
            entry->isWaiting = 0;
            if (func_0219CF00(cont, entry->code, &flags) == 1 && (flags & FLDMMDL_BLACT_RESBIT_GUEST)) {
                if (func_0219D144(cont, entry->code, entry->mmdl) == 0) {
                    func_0219CF54(cont, entry->code);
                }
            }
            if (entry->resHandle != 0) {
                func_02046EFC(entry->resHandle);
                entry->resHandle = 0;
            }
            func_0219D1F8(entry);
            return;
        }
    }
}

void func_0219D1F8(BlactEntry *entry)
{
    entry->isWaiting = 0;
    func_02082BCC(entry, 0, sizeof(BlactEntry));
}

/*
 * Changes the object code of a model and keeps its old actor until the new
 * one is drawn. The search for a free record never advances the record
 * pointer, so only the first record is ever used (original code).
 */
void func_0219D208(Mmdl *mmdl, unsigned int code)
{
    BlactSys *cont;
    int i;
    BlactCodeChange *change;
    unsigned short oldBlactId;
    unsigned short res[2]; /* [0] flags, [1] slot index */
    cont = func_0216D520(func_0216D67C(mmdl));
    change = cont->codeChanges;
    func_0219CBD4(cont, code, &res[1], &res[0]);
    if (res[1] != 0xFFFF && !(res[0] & FLDMMDL_BLACT_RESBIT_TRANS)) {
        func_0216E204(mmdl, code);
        return;
    }
    i = 0;
    oldBlactId = func_0216D7A8(mmdl, 0);
    if (oldBlactId == 0xFFFF) {
        func_0216E204(mmdl, code);
        return;
    }
    for (; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++) {
        if (change->mmdl == 0) {
            break;
        }
    }
    if (i >= FLDMMDL_BLACT_CODE_CHANGE_MAX) {
        func_0216E204(mmdl, code);
        return;
    }
    change->mmdl = mmdl;
    change->oldBlactId = oldBlactId;
    change->oldCode = func_0216D598(mmdl);
    change->newCode = code;
    func_0216E204(mmdl, code);
    i = 0;
    if (func_0216D7A8(mmdl, 0) != 0xFFFF) {
        func_0219C880(cont, mmdl, change->oldBlactId, change->oldCode);
        func_02050468(cont->bbdActSys, change->oldBlactId, 1);
        change->mmdl = 0;
    }
}

void func_0219D2CC(BlactSys *cont)
{
    cont->codeChanges =
        func_02030734(func_0216D4F8(cont->mmdlSys), sizeof(BlactCodeChange) * FLDMMDL_BLACT_CODE_CHANGE_MAX, 1, (const char *)d_021DDD70, 0x979);
}

void func_0219D2F4(BlactSys *cont)
{
    BlactCodeChange *change = cont->codeChanges;
    int i;
    if (change != 0) {
        for (i = 0; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++, change++) {
            if (change->mmdl != 0) {
                func_02050468(cont->bbdActSys, change->oldBlactId, 1);
                change->mmdl = 0;
            }
        }
        func_020307B0(cont->codeChanges);
    }
}

/* Deletes the old actor once the model is gone or its new actor exists. */
void func_0219D324(BlactSys *cont, BlactCodeChange *change)
{
    Mmdl *mmdl;
    unsigned short oldCode;
    mmdl = change->mmdl;
    if (func_0216DA30(mmdl, change) == 0) {
        func_0219C880(cont, mmdl, change->oldBlactId, change->oldCode);
        func_02050468(cont->bbdActSys, change->oldBlactId, 1);
        change->mmdl = 0;
        return;
    }
    if ((unsigned short)func_0216D7A8(mmdl, 0) != 0xFFFF) {
        oldCode = change->oldCode;
        if (oldCode != func_0216D598(mmdl)) {
            func_0219C880(cont, mmdl, change->oldBlactId, oldCode);
        }
        func_02050468(cont->bbdActSys, change->oldBlactId, 1);
        change->mmdl = 0;
    }
}

void func_0219D390(BlactSys *cont)
{
    BlactCodeChange *change = cont->codeChanges;
    int i;
    if (change != 0) {
        for (i = 0; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++, change++) {
            if (change->mmdl != 0) {
                func_0219D324(cont, change);
            }
        }
    }
}

int func_0219D3B4(BlactSys *cont, Mmdl *mmdl, u16 blactId)
{
    BlactCodeChange *change = cont->codeChanges;
    int i;
    if (change != 0) {
        for (i = 0; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++, change++) {
            if (change->mmdl != 0 && change->mmdl == mmdl && change->oldBlactId == blactId) {
                return 1;
            }
        }
    }
    return 0;
}

BlactAnimeTable *func_0219D3E4(int animId)
{
    return &d_021D7F68[animId];
}

/* Adds an image slot for a resource: kept in VRAM (kind -1) or by request record. */
unsigned short func_0219D3F0(BlactSys *cont, int code, int mdlSize, int texSize, void *resHandle, int kind)
{
    u16 *cellSize;
    struct BbActRec rec;
    if (kind == FLDMMDL_BLACT_SLOT_VRAM) {
        return (unsigned short)func_0219C4AC(cont->bbdActSys, resHandle, mdlSize, texSize);
    }
    rec.resource = (u32)resHandle;
    rec.format = 0;
    rec.sizeS = d_021D8064[texSize];
    cellSize = d_021D75C4[mdlSize];
    rec.sizeT = cellSize[0];
    rec.paletteId = cellSize[1];
    rec.kind = kind;
    return func_020500F0(cont->bbdActSys, &rec, 1);
}
