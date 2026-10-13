/*
 * file:     field_door_anime.c
 * unit:     yes
 * function: func_021C96CC, func_021C978C, func_021C97B8, func_021C9828, func_021C9854, func_021C98F4
 * address:  0x021C96CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C96CC: door open/close tasks called from scrcmd_screeneffects.c (file name guess, no anchor).
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006224  0x02006224  thumb
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C638  0x0218C638  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 */
struct Desc;
struct Obj;
struct Obj00020;
struct VecFx32;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

/* SE ids: door open, door hold, door close. */
#define SE_DOOR_OPEN  0x55B
#define SE_DOOR_HOLD  0x55C
#define SE_DOOR_CLOSE 0x55D

/* Work of the door tasks (0x14 bytes, allocated by the task system). */
typedef struct DoorAnimeWork {
    u32 gameSys;   /* +0x00: owner passed to the task system */
    u32 fieldmap;  /* +0x04: field map; gives the player and the build-model manager */
    u32 door;      /* +0x08: build model found around the player, 0 if none */
    u32 pad0C;     /* +0x0C: not used by these tasks */
    u32 silent;    /* +0x10: close without the close SE */
} DoorAnimeWork;

extern int func_02006148(u32 a0);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_02006224(u32 a0);
extern void func_020061E4(u32 id);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C638(int a, int b, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
int func_021C96CC(u32 task, u32 *seq, DoorAnimeWork *work);
u32 func_021C978C(u32 prio, u32 gameSys, u32 fieldmap);
int func_021C97B8(u32 task, u32 *seq, DoorAnimeWork *work);
u32 func_021C9828(u32 prio, u32 gameSys, u32 fieldmap);
int func_021C9854(u32 task, u32 *seq, DoorAnimeWork *work);
u32 func_021C98F4(u32 prio, u32 gameSys, u32 fieldmap, u32 silent);

/*
 * Door open task: plays the open SE and the open animation (0) of the build
 * model within one tile of the player, waits for the SE, then plays the hold
 * SE and animation 1.
 */
int func_021C96CC(u32 task, u32 *seq, DoorAnimeWork *work)
{
    int pos[3];
    int area[4];
    u32 bmodelMan;
    u32 door;

    switch (seq[0]) {
    case 0:
        func_020061E4(SE_DOOR_OPEN);
        func_021A3038(func_02188CB4((struct Obj00020 *)work->fieldmap), (struct VecFx32 *)pos);
        area[0] = pos[2] - 0x10000;
        area[1] = pos[2] + 0x10000;
        area[2] = pos[0] - 0x10000;
        area[3] = pos[0] + 0x10000;
        bmodelMan = func_0218DC6C((u8 *)func_02188C98((void *)work->fieldmap));
        door = func_0218C638(bmodelMan, 4, (int)area);
        if (door != 0) {
            work->door = door;
            func_0218C69C((unsigned char *)bmodelMan, door, 0, 0);
        }
        seq[0]++;
        break;
    case 1:
        if (func_02006224(func_02006148(SE_DOOR_OPEN)) == 0) {
            seq[0]++;
        }
        break;
    case 2:
        func_020061E4(SE_DOOR_HOLD);
        if (work->door != 0) {
            bmodelMan = func_0218DC6C((u8 *)func_02188C98((void *)work->fieldmap));
            func_0218C69C((unsigned char *)bmodelMan, work->door, 1, 2);
        }
        seq[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

u32 func_021C978C(u32 prio, u32 gameSys, u32 fieldmap)
{
    u32 task = (u32)func_020122C0((void *)gameSys, (void *)prio, func_021C96CC, 0x14);
    DoorAnimeWork *work = func_020124E8((struct Obj *)task);
    work->gameSys = gameSys;
    work->fieldmap = fieldmap;
    work->door = 0;
    return task;
}

/* Sets the door near the player to its open state (animation 1) at once, no SE. */
int func_021C97B8(u32 task, u32 *seq, DoorAnimeWork *work)
{
    int pos[3];
    int area[4];
    u32 bmodelMan;
    u32 door;

    switch (seq[0]) {
    case 0:
        func_021A3038(func_02188CB4((struct Obj00020 *)work->fieldmap), (struct VecFx32 *)pos);
        area[0] = pos[2] - 0x10000;
        area[1] = pos[2] + 0x10000;
        area[2] = pos[0] - 0x10000;
        area[3] = pos[0] + 0x10000;
        bmodelMan = func_0218DC6C((u8 *)func_02188C98((void *)work->fieldmap));
        door = func_0218C638(bmodelMan, 4, (int)area);
        if (door != 0) {
            work->door = door;
            func_0218C69C((unsigned char *)bmodelMan, door, 1, 2);
        }
        seq[0]++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

u32 func_021C9828(u32 prio, u32 gameSys, u32 fieldmap)
{
    u32 task = (u32)func_020122C0((void *)gameSys, (void *)prio, func_021C97B8, 0x14);
    DoorAnimeWork *work = func_020124E8((struct Obj *)task);
    work->gameSys = gameSys;
    work->fieldmap = fieldmap;
    work->door = 0;
    return task;
}

/* Door close task: close SE (unless silent) and close animation (2), waits for the SE. */
int func_021C9854(u32 task, u32 *seq, DoorAnimeWork *work)
{
    int pos[3];
    int area[4];
    u32 bmodelMan;
    u32 door;

    switch (seq[0]) {
    case 0:
        if (work->silent == 0)
            func_020061E4(SE_DOOR_CLOSE);
        func_021A3038(func_02188CB4((struct Obj00020 *)work->fieldmap), (struct VecFx32 *)pos);
        area[0] = pos[2] - 0x10000;
        area[1] = pos[2] + 0x10000;
        area[2] = pos[0] - 0x10000;
        area[3] = pos[0] + 0x10000;
        bmodelMan = func_0218DC6C((u8 *)func_02188C98((void *)work->fieldmap));
        door = func_0218C638(bmodelMan, 4, (int)area);
        if (door != 0) {
            work->door = door;
            func_0218C69C((unsigned char *)bmodelMan, door, 2, 0);
        }
        seq[0]++;
        break;
    case 1:
        if (work->silent == 0) {
            if (func_02006224(func_02006148(SE_DOOR_CLOSE)) == 0) {
                seq[0]++;
            }
        } else {
            seq[0]++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

u32 func_021C98F4(u32 prio, u32 gameSys, u32 fieldmap, u32 silent)
{
    u32 task = (u32)func_020122C0((void *)gameSys, (void *)prio, func_021C9854, 0x14);
    DoorAnimeWork *work = func_020124E8((struct Obj *)task);
    work->gameSys = gameSys;
    work->fieldmap = fieldmap;
    work->door = 0;
    work->silent = silent;
    return task;
}
