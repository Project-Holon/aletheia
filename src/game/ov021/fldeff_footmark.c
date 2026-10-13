/*
 * file:     fldeff_footmark.c
 * unit:     yes
 * function: func_021BBDD4, func_021BBE84, func_021BBEF4, func_021BBF10, func_021BBF74
 * address:  0x021BBDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BBF78 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5FC  0x0216D5FC  thumb  ov010
 *   func_021BBD84  0x021BBD84  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9AF8     0x021D9AF8  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_02050080  0x02050080  arm
 *   func_020508C4  0x020508C4  arm
 *   func_0204F6B4  0x0204F6B4  arm
 */
struct Actor;
struct BbActDesc;
struct BbActSys;

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Footmark effect work (FLDEFF_CTRL effect slot 5). */
typedef struct FootmarkEffectWork {
    int fieldEffectCtrl;
    int bbActSys;
    u16 resIdx[26];
    int snowHeightOffset;
} FootmarkEffectWork;

/* Add-task header copied into every footmark task. */
typedef struct FootmarkTaskHead {
    FootmarkEffectWork *effWork;
    u16 resNo;
    u16 padResNo;
} FootmarkTaskHead;

typedef struct FootmarkTaskWork {
    FootmarkTaskHead head;
    u16 actId;
    u16 seq;
    u16 padSeq;
    s16 alpha;
    int frame;
} FootmarkTaskWork;

/* Billboard actor add parameters. */
typedef struct FootmarkBbActAdd {
    u16 resIdx, scaleX, scaleY;
    s8 alpha;
    int drawEnable, lightEnable;
} FootmarkBbActAdd;

/* Field effect task draw-object setup. */
typedef struct FootmarkTaskObj {
    int reserved[3];
    int g3dObj;
    FootmarkTaskWork *work;
} FootmarkTaskObj;

int func_021ABEA0(u32 fieldEffectCtrl, u32 procId);
u16 func_0216D5F8(void *mmdl);
u16 func_0216D5FC(void *mmdl);
int func_021BBD84(int effWork, int type, int dir, int oldDir);
void func_0216D88C(const struct Actor *mmdl, struct VecFx32 *out);
int func_0216D804(void *mmdl);
int func_0216D81C(void *mmdl);
void func_02164280(int gridX, int gridZ, int *pos);
void func_021ABFA8(int fieldEffectCtrl, void *taskHeader, VecFx32 *pos, int param, FootmarkTaskHead *head, int pri);
extern int func_021AC1AC(u32 task);
extern void func_021AC1B8(int task, FootmarkTaskObj *obj);
extern void func_021AC154(int task);
extern u16 func_02050340(struct BbActSys *sys, u16 base, const struct BbActDesc *desc, u32 count, u32 mode);
extern void func_02050468(struct BbActSys *sys, u16 first, u32 count);
extern u32 func_02050080(u32 *sys);
extern u32 func_020508C4(u32 sys, u16 actId);
extern void func_0204F6B4(u8 *board, int elem, u8 *alpha);
void func_021BBDD4(int mmdl, int fieldEffectCtrl, int type);
void func_021BBE84(int task, FootmarkTaskWork *work);
void func_021BBEF4(int task, FootmarkTaskWork *work);
void func_021BBF10(int task, FootmarkTaskWork *work);
void func_021BBF74(void);

extern int d_021D9AF8;

void func_021BBDD4(int mmdl, int fieldEffectCtrl, int type)
{
    int effWork;
    int dir;
    int oldDir;
    int resNo;
    VecFx32 pos;
    FootmarkTaskHead head;

    effWork = func_021ABEA0(fieldEffectCtrl, 5);
    head.effWork = (FootmarkEffectWork *)effWork;
    dir = func_0216D5F8((void *)mmdl);
    oldDir = func_0216D5FC((void *)mmdl);
    resNo = (u16)func_021BBD84(effWork, type, dir, oldDir);
    func_0216D88C((const struct Actor *)mmdl, (struct VecFx32 *)&pos);
    dir = func_0216D804((void *)mmdl);
    func_02164280(dir, func_0216D81C((void *)mmdl), (int *)(&pos));
    if (type == 0 && (u16)(resNo + 0xFFFE) <= 1) {
        pos.z -= 0x2000;
    } else if (type == 4 && (u16)(resNo + 0xFFFE) <= 1) {
        pos.z -= 0x2000;
    }
    if (type == 4) {
        pos.y -= ((FootmarkEffectWork *)effWork)->snowHeightOffset;
    }
    head.resNo = resNo;
    func_021ABFA8(fieldEffectCtrl, &d_021D9AF8, &pos, 0, &head, 0);
}

void func_021BBE84(int task, FootmarkTaskWork *work)
{
    FootmarkTaskObj obj;
    FootmarkBbActAdd add;
    FootmarkTaskHead *head = (FootmarkTaskHead *)func_021AC1AC(task);

    work->head = *head;
    work->alpha = 0x1f;
    add.resIdx = work->head.effWork->resIdx[work->head.resNo];
    add.scaleX = 0x1000;
    add.scaleY = 0x1000;
    add.alpha = work->alpha;
    add.drawEnable = 1;
    add.lightEnable = 1;
    obj.g3dObj = 0;
    obj.work = work;
    func_021AC1B8(task, &obj);
    work->actId = func_02050340((void *)work->head.effWork->bbActSys, 0, (const struct BbActDesc *)(&add), 1, 3);
    if (work->actId == 0xFFFF) {
        func_021AC154(task);
    }
}

void func_021BBEF4(int task, FootmarkTaskWork *work)
{
    int bbActSys = work->head.effWork->bbActSys;
    u16 actId = work->actId;

    if (actId != 0xFFFF) {
        func_02050468((struct BbActSys *)bbActSys, actId, 1);
    }
}

/*
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 */
void func_021BBF10(int task, FootmarkTaskWork *work)
{
    u8 alpha;
    int bbActSys, board;
    u16 elem;

    switch (work->seq) {
    case 0:
        work->frame = work->frame + 1;
        if (work->frame >= 0x10) {
            work->seq = work->seq + 1;
        }
        break;
    case 1:
        work->alpha = work->alpha - 2;
        if (work->alpha < 0) {
            func_021AC154(task);
            return;
        }
        alpha = work->alpha;
        bbActSys = work->head.effWork->bbActSys;
        board = func_02050080((u32 *)bbActSys);
        elem = (int)func_020508C4((u32)bbActSys, (u16)work->actId);
        func_0204F6B4((u8 *)board, elem, &alpha);
        break;
    }
}

void func_021BBF74(void) {}
