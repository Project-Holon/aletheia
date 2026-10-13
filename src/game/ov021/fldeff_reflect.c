/*
 * file:     fldeff_reflect.c
 * unit:     yes
 * function: func_021BBF78, func_021BBF9C, func_021BBFB0, func_021BBFB4, func_021BBFB8, func_021BBFF4, func_021BC030, func_021BC048, func_021BC10C, func_021BC138, func_021BC338, func_021BC340
 * address:  0x021BBF78
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
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_020508C4  0x020508C4  arm
 *   d_021DE320     0x021DE320  data  a4
 *   func_020307B0  0x020307B0  arm
 *   d_021D9B64  0x021D9B64  data
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0219C98C  0x0219C98C  thumb  ov021
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219C928  0x0219C928  thumb  ov021
 *   func_0219C9E0  0x0219C9E0  thumb  ov021
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020507D0  0x020507D0  arm
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0204F5E4  0x0204F5E4  arm
 *   func_0204F604  0x0204F604  arm
 *   func_0204F654  0x0204F654  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F684  0x0204F684  arm
 *   func_0204F794  0x0204F794  arm
 *   func_0204F748  0x0204F748  arm
 *   func_0204F764  0x0204F764  arm
 *   d_021D9B40     0x021D9B40  data  a4
 *   d_021D9B58     0x021D9B58  data  a4
 *   d_021D9B4C     0x021D9B4C  data  a4
 *   func_02030734  0x02030734  arm
 */
struct Actor;
struct BbBoard;

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int fx32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

/* Reflection effect work (FLDEFF_CTRL effect slot 6). */
typedef struct ReflectEffectWork {
    u32 fieldEffectCtrl;
} ReflectEffectWork;

/* Add-task header copied into every reflection task. */
typedef struct ReflectTaskHead {
    ReflectEffectWork *effWork;
    u32 type;
    u32 mmdl;
    u32 mmdlSys;
    u32 bbActSys;
} ReflectTaskHead;

typedef struct ReflectTaskWork {
    int baseAngle;
    int angleY;
    int swayAngle;
    int swaySpeed;
    u8 actorAdded;
    u8 angleSet;
    u8 pad12[2];
    ReflectTaskHead head;
    u16 actorReq;
    u16 actorId;
    u8 checkInfo[4];
} ReflectTaskWork;

/* Object code parameters (FLDMMDL_GetObjCodeParam). */
typedef struct ObjCodeParam {
    u16 code;
    u8 drawType;
    u8 drawProcNo;
    u8 shadowType;
    u8 footmarkType;
    u8 reflectType;
    u8 mdlSize;
} ObjCodeParam;

int func_021ABEA0(u32 fieldEffectCtrl, u32 procId);
void func_021ABFA8(int fieldEffectCtrl, void *taskHeader, VecFx32 *pos, int param, ReflectTaskHead *head, int pri);
extern int func_021AC1AC(u32 task);
extern void func_021AC154(int task);
extern u32 func_02050080(u32 *bbActSys);
extern u32 func_020508C4(u32 bbActSys, u16 actId);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
extern u32 func_0216D520(void *mmdlSys);
extern u32 func_0219C9DC(u8 *blActCont);
extern int func_0216E1A4(int mmdl, int checkInfo);
extern void func_0219C98C(u32 mmdlSys, u16 *actorReq);
extern int func_0216E1C4(int mmdl, int checkInfo);
extern int func_0216DC34(void *mmdl);
extern int func_0216D7A8(void *mmdl, unsigned int v);
extern void *func_0216E3C4(void *mmdl);
extern int func_0219C928(u32 mmdlSys, const u8 *objCodeParam, u16 *actorReq, VecFx32 *pos, u32 initProc, u32 initWork);
extern void func_0219C9E0(u32 mmdl, u16 *angleX, u16 *angleY);
extern u32 func_021ABE14(u8 *fieldEffectCtrl);
extern u16 func_02188C9C(u8 *fieldmap);
extern int func_020507D0(u32 bbActSys, u16 actId);
extern int func_020507A0(void *bbActSys, int actId, u32 resIdx);
extern void func_020507F0(void *bbActSys, int actId, u32 v);
extern void func_0216D8B0(u8 *mmdl, u8 *out);
extern int func_02163E58(u32 mmdl, VecFx32 *pos, int *height);
extern void func_0216D8D0(u8 *mmdl, u8 *out);
extern u32 func_0216D7DC(void *mmdl);
extern u16 func_021AB0F8(u32 attr);
extern void *func_02188C58(void *fieldmap);
extern u32 func_0218EC2C(u8 *fieldCamera);
extern void func_02048B30(u32 cam, VecFx32 *out);
extern void func_0204F638(u8 *board, int elem, VecFx32 *pos);
extern void func_0204F5E4(u8 *board, u32 elem, u16 *out);
extern void func_0204F604(void *board, u32 elem, u16 *src);
extern void func_0204F654(u32 board, u32 elem, s16 *v);
extern void func_0204F66C(int board, int elem, int v);
extern void func_0204F684(struct BbBoard *board, int elem, const s16 *rotX, const s16 *rotY);
extern void func_0204F794(void *board, u32 elem, u32 *val);
extern u32 func_0204F748(u8 *board, int elem);
extern void func_0204F764(void *board, u32 elem, u32 *val);
ReflectEffectWork *func_021BBF78(int fieldEffectCtrl, int heapId);
void func_021BBF9C(u32 fieldEffectCtrl, u8 *effWork);
void func_021BBFB0(void);
void func_021BBFB4(void *effWork);
void func_021BBFB8(u32 mmdlSys, u32 mmdl, u32 fieldEffectCtrl, u32 type);
void func_021BBFF4(u32 task, ReflectTaskWork *work);
void func_021BC030(int task, ReflectTaskWork *work);
void func_021BC048(u32 task, ReflectTaskWork *work);
void func_021BC10C(int task, ReflectTaskWork *work);
void func_021BC138(u16 actId, ReflectTaskWork *work);
int func_021BC338(u32 zoneId);
int func_021BC340(int zoneId, int mdlSize);

extern int d_021DE320;
extern u8 d_021D9B64[];
extern const fx32 d_021D9B40[];
extern const fx32 d_021D9B58[];
extern const fx32 d_021D9B4C[];

ReflectEffectWork *func_021BBF78(int fieldEffectCtrl, int heapId)
{
    ReflectEffectWork *effWork = func_02030734(heapId, 4, 1, (const char *)&d_021DE320, 0x78);

    effWork->fieldEffectCtrl = fieldEffectCtrl;
    func_021BBFB0();
    return effWork;
}

void func_021BBF9C(u32 fieldEffectCtrl, u8 *effWork)
{
    func_021BBFB4(effWork);
    func_020307B0(effWork);
}

void func_021BBFB0(void)
{
}

void func_021BBFB4(void *effWork)
{
}

void func_021BBFB8(u32 mmdlSys, u32 mmdl, u32 fieldEffectCtrl, u32 type)
{
    ReflectTaskHead head;

    head.type = type;
    head.mmdl = mmdl;
    head.mmdlSys = mmdlSys;
    head.bbActSys = func_0219C9DC((u8 *)func_0216D520((void *)mmdlSys));
    head.effWork = (ReflectEffectWork *)func_021ABEA0(fieldEffectCtrl, 6);
    func_021ABFA8(fieldEffectCtrl, d_021D9B64, (VecFx32 *)0, 0, &head, 0);
}

void func_021BBFF4(u32 task, ReflectTaskWork *work)
{
    ReflectTaskHead *head = (ReflectTaskHead *)func_021AC1AC(task);

    work->head = *head;
    work->swaySpeed = 0x40;
    work->baseAngle = 0;
    work->swayAngle = 0;
    if (work->head.type == 2) {
        work->swaySpeed = 0;
    }
    func_0216E1A4(head->mmdl, (int)work->checkInfo);
}

void func_021BC030(int task, ReflectTaskWork *work)
{
    if (work->actorAdded) {
        work->actorAdded = 0;
        func_0219C98C(work->head.mmdlSys, &work->actorReq);
    }
}

/*
 * The zeroed VecFx32 is a block-scope declaration with an initialiser: that is
 * what materialises `add r6, sp, #0xc` before the three stores and keeps r6
 * across the func_0216E3C4 call (plain element stores fold to sp-relative).
 */
void func_021BC048(u32 task, ReflectTaskWork *work)
{
    u16 angle[2];
    int mmdlActId;

    if (func_0216E1C4(work->head.mmdl, (int)work->checkInfo) == 0 || func_0216DC34((void *)work->head.mmdl) == 0) {
        func_021AC154((int)task);
        return;
    }
    mmdlActId = func_0216D7A8((void *)work->head.mmdl, 0);
    if (work->actorAdded == 0) {
        if (mmdlActId == 0xFFFF) return;
        {
            VecFx32 pos = {0, 0, 0};
            func_0219C928(work->head.mmdlSys, func_0216E3C4((void *)work->head.mmdl), &work->actorReq, &pos,
                          (u32)func_021BC138, (u32)work);
        }
        work->actorAdded = 1;
    }
    if (work->actorId == 0xFFFF) return;
    if (work->angleSet == 0) {
        int angleX;
        func_0219C9E0(work->head.mmdl, &angle[1], &angle[0]);
        angleX = angle[1];
        work->baseAngle = angleX;
        work->angleY = angle[0];
        work->swayAngle = angleX;
        work->angleSet = 1;
    }
    work->swayAngle += work->swaySpeed;
    if (work->swayAngle >= work->baseAngle + 0x400) {
        work->swayAngle = work->baseAngle + 0x400;
        work->swaySpeed = -work->swaySpeed;
        return;
    }
    if (work->swayAngle <= work->baseAngle - 0x400) {
        work->swayAngle = work->baseAngle - 0x400;
        work->swaySpeed = -work->swaySpeed;
    }
}

void func_021BC10C(int task, ReflectTaskWork *work)
{
    if (func_0216E1C4((int)work->head.mmdl, (int)work->checkInfo) == 1 && work->actorAdded != 0 && work->actorId != 0xFFFF) {
        func_021BC138(work->actorId, work);
    }
}

/*
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 *
 * The u16 mmdlElem local is what truncates func_020507D0's result straight
 * into r2 (a (u16) cast or a u16 parameter adds a copy first).
 */
void func_021BC138(u16 actId, ReflectTaskWork *work)
{
    VecFx32 pos;
    VecFx32 offset;
    VecFx32 camUp;
    int height;
    u32 flag;
    s16 rot[4];
    u16 zoneId;
    u32 bbActSys;
    u32 board;
    int mmdlActId;
    u32 mmdl;
    ObjCodeParam *objCode;
    u32 mmdlBoardElem;
    u32 boardElem;
    u16 mmdlElem;

    bbActSys = work->head.bbActSys;
    board = func_02050080((u32 *)bbActSys);
    mmdlActId = func_0216D7A8((void *)work->head.mmdl, 0);
    if (actId == 0xFFFF) {
        return;
    }
    zoneId = func_02188C9C((u8 *)func_021ABE14((u8 *)work->head.effWork->fieldEffectCtrl));
    mmdlElem = func_020507D0(bbActSys, mmdlActId);
    func_020507A0((void *)bbActSys, actId, mmdlElem);
    func_020507F0((void *)bbActSys, actId, 0);
    mmdl = work->head.mmdl;
    objCode = func_0216E3C4((void *)mmdl);
    func_0216D88C((const struct Actor *)mmdl, (struct VecFx32 *)&pos);
    pos.z += d_021D9B40[objCode->mdlSize];
    func_0216D8B0((u8 *)mmdl, (u8 *)(&offset));
    pos.x += offset.x;
    pos.z -= offset.z;
    if (func_02163E58(mmdl, &pos, &height) == 1) {
        pos.y = height;
    }
    pos.y += d_021D9B58[work->head.type];
    func_0216D8D0((u8 *)mmdl, (u8 *)(&offset));
    pos.x += offset.x;
    pos.y -= offset.y;
    pos.z -= offset.z;
    pos.y += d_021D9B4C[objCode->mdlSize];
    if (objCode->mdlSize == 2) {
        if (func_021AB0F8(func_0216D7DC((void *)mmdl)) & 0x40) {
            pos.y -= 0x3800;
        } else {
            pos.y -= 0x8000;
        }
    }
    pos.y += func_021BC340(zoneId, objCode->mdlSize);
    func_02048B30(func_0218EC2C(func_02188C58((void *)func_021ABE14((u8 *)work->head.effWork->fieldEffectCtrl))), &camUp);
    pos.x += (pos.x / 4096 - camUp.x / 4096) * 298;
    func_0204F638((u8 *)board, actId, &pos);
    flag = 1;
    mmdlBoardElem = func_020508C4(bbActSys, mmdlActId);
    boardElem = func_020508C4(bbActSys, actId);
    rot[3] = work->swayAngle;
    rot[2] = work->angleY;
    rot[2] += (s16)func_021BC338(zoneId);
    rot[1] = 0;
    rot[0] = 0;
    func_0204F5E4((u8 *)board, mmdlBoardElem, (u16 *)(&rot[1]));
    func_0204F604((void *)board, boardElem, (u16 *)(&rot[1]));
    func_0204F654(board, mmdlBoardElem, &rot[0]);
    func_0204F66C(board, boardElem, (int)(&rot[0]));
    func_0204F684((struct BbBoard *)board, boardElem, &rot[3], &rot[2]);
    func_0204F794((void *)board, boardElem, &flag);
    flag = func_0204F748((u8 *)board, mmdlBoardElem);
    func_0204F764((void *)board, boardElem, &flag);
}

int func_021BC338(u32 zoneId)
{
    return (~255);
}

int func_021BC340(int zoneId, int mdlSize)
{
    int ofs = 0;

    if (zoneId == 0x71 || zoneId == 0x159) {
        if (mdlSize == 0) {
            ofs = -0x800;
        }
    } else if (zoneId == 0x8f) {
        if (mdlSize == 0) {
            ofs = 2 << 10;
        }
    } else if (zoneId == 0x159 + 0x12) {
        if (mdlSize == 0) {
            ofs = -0x5800;
        }
    } else {
        if (mdlSize == 0) {
            ofs = 6 << 10;
        }
    }
    return ofs;
}
