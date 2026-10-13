/*
 * file:     comm_player.c
 * unit:     yes
 * function: func_02167380, func_02167394, func_021673A8, func_021673C4, func_021673E0, func_0216742C, func_02167444, func_0216745C, func_0216747C, func_0216749C, func_02167518, func_0216754C, func_02167590, func_021675D0, func_02167658, func_02167688, func_021676E4, func_02167794, func_021677E4, func_02167810, func_02167848, func_0216786C, func_021679A4, func_021679C4, func_02167A14, func_02167A54, func_02167A74
 * address:  0x02167380
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02171F5F  0x02171F5F  data  a1
 *   d_02171F3C 0x02171F3C data a1
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E024  0x0200E024  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02030734 0x02030734 arm
 *   d_02172A18 0x02172A18 data a1
 *   func_02012114  0x02012114  thumb
 *   func_021942C8  0x021942C8  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_020307B0  0x020307B0  arm
 *   d_02172A28  0x02172A28  data  ov010  a4
 *   func_021BB5C8  0x021BB5C8  thumb
 *   func_02194300  0x02194300  thumb  ov021
 *   func_02194354 0x02194354 thumb ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02194284  0x02194284  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B38  0x02012B38  thumb
 *   FIELD_STATUS_GetSeasonDispFlag  0x02014484  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02194384   0x02194384  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021943EC  0x021943EC  thumb  ov021
 *   func_021BB578  0x021BB578  thumb
 */
#include "../../matched/include/Obj00020.h"
struct Entry32;
struct Ctx;
struct BigObj;
struct Rec44;
struct SaveBlock;
struct Sub02014444Obj;
struct Obj00020;
struct Tbl;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

typedef unsigned long long u64;

typedef int fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

/*
 * One remote player as comm_player.c keeps it. The position is a two-word
 * block (u64 + u32): copying it as one aggregate gives the ldm/stm runs the
 * image has.
 */
typedef struct CommPlayerPos {
    u64 xy;
    u32 z;
} CommPlayerPos;

typedef struct CommPlayerEntry {
    CommPlayerPos pos;      /* 0x00 */
    u32 vanish;             /* 0x0C */
    u16 zoneId;             /* 0x10 */
    u16 objCode;            /* 0x12 */
    u8 used : 1;            /* 0x14 */
    u8 pending : 1;
    u8 dir : 4;
    u8 pad15[3];
    u32 effect;             /* 0x18 */
} CommPlayerEntry;

/* Last own position sent to the other players. */
typedef struct CommPlayerLastPos {
    VecFx32 pos;            /* 0x00 */
    u16 zoneId;             /* 0x0C */
    u8 dir : 4;             /* 0x0E */
    u8 vanish : 1;
} CommPlayerLastPos;

#include "comm_player_types.h"

typedef struct CommPlayerWork {
    void *gameSystem;           /* 0x00 */
    void *playerSys;            /* 0x04 */
    CommPlayerEntry entries[4]; /* 0x08 */
    CommPlayerLastPos last;     /* 0x78 */
    u8 pad88[4];
    u16 heapId;                 /* 0x8C */
    u8 playerMax;               /* 0x8E */
    u8 updateStopped;           /* 0x8F */
    u8 sysOption;               /* 0x90 */
} CommPlayerWork;

/* Flag byte of entry i seen from base + 0x1C (stride 0x1C); see func_02167658. */
typedef struct CommPlayerFlagView {
    u8 used : 1;
    u8 pending : 1;
    u8 dir : 4;
    u8 pad[3];
    u32 effect;
    u8 tail[20];
} CommPlayerFlagView;

/* Entry i seen from base + i * 0x1C (flags at +0x1C); see func_021677E4. */
typedef struct CommPlayerRowView {
    u8 head[28];
    CommPlayerFlagView flags;
} CommPlayerRowView;

extern void func_0200E06C(char *p);
extern void func_0200E024(void *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern unsigned int func_02012114(const struct Ctx *a);
extern void func_021942C8(void *obj);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern int func_021BB5C8(u32 v);
extern void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f);
extern void func_02194354(void *, u32);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(u8 *p);
extern void *func_02194284(int a, void *b, int heap, int c);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void *func_02012B38(const struct BigObj *p);
extern u8 FIELD_STATUS_GetSeasonDispFlag(struct Sub02014444Obj *o);
extern int func_02188BE8(void *proc);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern int func_021A34EC(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_02197CCC(u8 *p, fx32 *out);
extern u16 func_021A3050(u8 *p);
extern VecFx32 *func_02012AA0(void *pl);
extern u16 func_02012AE4(void *pl);
extern fx32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_02194384(void *playerSys, int, int, int, int, int);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021943EC(struct Tbl *t, u32 key);
extern u32 func_021BB578(void *a, void *b, int c, int d);
u8 func_02167380(u32 id);
u8 func_02167394(u32 i);
u8 func_021673A8(u8 *p);
u8 func_021673C4(u8 *p);
u8 func_021673E0(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count);
u16 func_0216742C(Entry32 *list, Entry32 *out, u32 cap, u8 *count);
int func_02167444(Entry32 *list, Entry32 *out, u32 cap, u8 *count);
u16 func_0216745C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 func_0216747C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
void *func_02167518(int playerMax, void *gameSystem, u16 heapId, int sysOption);
void func_0216754C(void *gameSystem, CommPlayerWork *work);
void func_02167590(void *gameSystem, CommPlayerWork *work);
void func_021675D0(CommPlayerWork *work, int index, int objCode, CommPlayerPackage *package);
void func_02167658(CommPlayerWork *work, int index);
void func_02167688(CommPlayerWork *work);
void func_021676E4(CommPlayerWork *work);
void func_02167794(CommPlayerWork *work);
int func_021677E4(CommPlayerWork *work, int index);
u16 func_02167810(CommPlayerWork *work, int index);
void func_02167848(CommPlayerWork *work, int index, CommPlayerPackage *package);
int func_0216786C(CommPlayerWork *work, CommPlayerPackage *out);
int func_021679A4(CommPlayerWork *work, int index, int a2, int a3, int a4, int a5);
int func_021679C4(CommPlayerWork *work, int index);
u32 func_02167A14(CommPlayerWork *work, int index);
int func_02167A54(CommPlayerWork *work, int index);
void func_02167A74(void *gameSystem, CommPlayerWork *work);
extern u8 d_02171F5F[];
extern const u8 d_02171F3C[];
extern const char d_02172A18[];
extern const char d_02172A28[];





/*
 * Record-field accessor (third of the four-leaf run 0x02167358..0x021673A8):
 * returns byte 3 of the 4-byte record for id, 0 when id > 0x1d.  The record
 * table starts at 0x02171F5C; the pool word names the field address itself.
 * Unlabelled in the listing (no lr-saving prologue, callers all in arm9).
 */
u8 func_02167380(u32 id)
{
    if (id > 0x1d)
        return 0;
    return d_02171F5F[id * 4];
}





u8 func_02167394(u32 i) { if (i > 29) return 0; return d_02171F3C[i]; }






/*
 * Reads the byte at +0x848 of the shared state under its lock
 * (func_0200E06C / func_0200E024).
 */
u8 func_021673A8(u8 *p)
{
    u8 v;

    func_0200E06C((char *)p);
    v = p[0x848];
    func_0200E024(p);
    return v;
}






/*
 * Reads the byte at +0x849 of the shared state under its lock
 * (func_0200E06C / func_0200E024).
 */
u8 func_021673C4(u8 *p)
{
    u8 v;

    func_0200E06C((char *)p);
    v = p[0x849];
    func_0200E024(p);
    return v;
}






/*
 * Copies `count` 4-byte entries starting at index `start` out of the
 * shared list under its lock into a cleared buffer of `cap` entries, and
 * answers how many leading entries are in use (non-zero 11-bit id).
 */
u8 func_021673E0(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count)
{
    int i;

    i = 0;
    MI_CpuFill8(out, 0, cap * 4);
    func_0200E06C((char *)list);
    MI_CpuCopy8(&list[start], out, count * 4);
    func_0200E024(list);
    for (i = 0; i < count; i++) {
        if (out[i].id == 0)
            break;
    }
    return i;
}






/* The first ten entries of page 0. */
u16 func_0216742C(Entry32 *list, Entry32 *out, u32 cap, u8 *count)
{
    *count = func_021673E0(list, out, cap, 0, 10);
    return 0;
}






/* The second ten entries of page 0. */
int func_02167444(Entry32 *list, Entry32 *out, u32 cap, u8 *count)
{
    *count = func_021673E0(list, out, cap, 10, 10);
    return 10;
}






/*
 * One of the three 10-entry pages from index 20.
 */
u16 func_0216745C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n)
{
    u16 start;

    start = page * 10 + 20;
    *n = func_021673E0(list, out, cap, start, 10);
    return start;
}






/*
 * One of the 20-entry pages from index 50.
 */
u16 func_0216747C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n)
{
    u16 start;

    start = page * 20 + 50;
    *n = func_021673E0(list, out, cap, start, 20);
    return start;
}






/*
 * Fetches list page `page` (0: the first twenty entries, 1..3: ten-entry
 * pages, 4 and up: twenty-entry pages); answers its start index and the
 * number of used entries in *n.
 */
u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n)
{
    u8 more;
    u16 start;

    more = 0;
    MI_CpuFill8(out, 0, cap * 4);
    if (page == 0) {
        start = func_0216742C(list, out, cap, n);
        out += 10;
        cap -= 10;
        func_02167444(list, out, cap, &more);
        *n += more;
    } else if (page >= 1 && page < 4) {
        start = func_0216745C(list, out, cap, page - 1, n);
    } else {
        start = func_0216747C(list, out, cap, page - 4, n);
    }
    return start;
}





void *func_02167518(int playerMax, void *gameSystem, u16 heapId, int sysOption) {
    CommPlayerWork *work;
    work = func_02030734(heapId, sizeof(CommPlayerWork), 1, d_02172A18, 97);
    work->playerMax = playerMax;
    work->gameSystem = gameSystem;
    work->heapId = heapId;
    work->sysOption = sysOption;
    return work;
}

void func_0216754C(void *gameSystem, CommPlayerWork *work)
{
    int i;
    if (work->playerSys != 0) {
        for (i = 0; i < 4; i++)
            func_02167658(work, i);
        if (func_02012114(gameSystem) == 1)
            func_021942C8(work->playerSys);
        else
            func_02034714(d_02172A28, 0, d_02172A28);
    }
    func_020307B0(work);
}

void func_02167590(void *gameSystem, CommPlayerWork *work)
{
    int i;
    func_02167A74(gameSystem, work);
    if (func_02012114(work->gameSystem) == 1) {
        for (i = 0; i < 4; i++) {
            if (work->entries[i].used == 1 && work->entries[i].effect != 0 && func_021BB5C8(work->entries[i].effect) == 1)
                work->entries[i].effect = 0;
        }
    }
}

static inline void CopyPos(CommPlayerPos *dst, CommPlayerPos *src)
{
    *dst = *src;
}

void func_021675D0(CommPlayerWork *work, int index, int objCode, CommPlayerPackage *package)
{
    if (work->playerSys != 0 && work->entries[index].used != 1) {
        CopyPos(&work->entries[index].pos, (CommPlayerPos *)&package->pos);
        /* row view as in func_02167848: entries[index] here changes the bytes */
        ((CommPlayerWork *)((char *)work + index * 0x1C))->entries[0].zoneId = package->zoneId;
        ((CommPlayerWork *)((char *)work + index * 0x1C))->entries[0].vanish = package->vanish;
        work->entries[index].objCode = objCode;
        work->entries[index].pending = 0;
        work->entries[index].used = 1;
        work->entries[index].effect = 0;
        func_02194300(work->playerSys, index, objCode, &work->entries[index].zoneId, (int)(&work->entries[index]), (int)(&work->entries[index].vanish));
    }
}

/*
 * lever: test the one-bit field directly; == 1 inserts an extra cmp.
 * domain: no index bound assumed; flag base and unsigned scaled offset use modulo-32 address arithmetic, with no fixed-array subscript.
 * address lever: separate flags base and off locals preserve the original base/offset registers; a combined raw address folds i+1, while the CommPlayerFlagView accesses share the scaled pointer.
 */
void func_02167658(CommPlayerWork *work, int index) {
    CommPlayerFlagView *flags;
    u32 offset;
    flags = (CommPlayerFlagView *)((u32)work + 28u);
    offset = (u32)index * 28u;
    if (((CommPlayerFlagView *)((u32)flags + offset))->used && work->playerSys != 0) {
        *(u32 *)((u32)work + offset + 32u) = 0;
        func_02194354(work->playerSys, index);
        ((CommPlayerFlagView *)((u32)flags + offset))->used = 0;
    }
}

void func_02167688(CommPlayerWork *work)
{
    CommPlayerFlagView *flags;
    int i;
    if (func_02012114(work->gameSystem) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->playerSys != 0) {
        i = 0;
        flags = (CommPlayerFlagView *)((char *)work + 0x1C);
        for (; i < 4; i++) {
            if (flags[i].used == 1) {
                func_02167658(work, i);
                *(u8 *)&flags[i] |= 2;
            }
        }
        func_021942C8(work->playerSys);
        work->playerSys = 0;
    }
}

void func_021676E4(CommPlayerWork *work)
{
    CommPlayerPackage package;
    CommPlayerFlagView *flags;
    int i;
    if (func_02012114(work->gameSystem) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->playerSys != 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    work->playerSys = func_02194284(work->playerMax, func_02188C7C(func_0201210C(work->gameSystem)), work->heapId, work->sysOption);
    func_02082BCC(&package, 0, 0x14);
    flags = (CommPlayerFlagView *)work;
    flags = (CommPlayerFlagView *)((char *)flags + 0x1C);
    for (i = 0; i < 4; i++) {
        if (flags[i].pending == 1) {
            package.pos = *(VecFx32 *)&work->entries[i].pos;
            package.zoneId = work->entries[i].zoneId;
            package.vanish = 0;
            package.dir = flags[i].dir;
            func_021675D0(work, i, work->entries[i].objCode, &package);
        }
    }
}

void func_02167794(CommPlayerWork *work)
{
    CommPlayerFlagView *flags;
    int i;
    if (func_02012114(work->gameSystem) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->playerSys != 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    i = 0;
    flags = (CommPlayerFlagView *)((char *)work + 0x1C);
    for (; i < 4; i++) {
        if (flags[i].pending == 1)
            flags[i].pending = 0;
    }
}

/*
 * domain: the signed index>=4 guard admits negative indices; raw unsigned scaling preserves the original modulo-32 address arithmetic without a fixed-array bound.
 * address lever: CommPlayerRowView supplies the +28 load offset after unsigned scaling; combining +28 with the scaled index folds index+1 and changes the instructions.
 */
int func_021677E4(CommPlayerWork *work, int index) {
    if (work == 0 || index >= 4) func_02034714(d_02172A28, 0, d_02172A28);
    return ((CommPlayerRowView *)((u32)work + (u32)index * 28u))->flags.used;
}

u16 func_02167810(CommPlayerWork *work, int index)
{
    if (work == 0 || index >= 4 || work->entries[index].used != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return work->entries[index].objCode;
}

/*
 * Recursive MATCH unblocker: callee of func_0217FF78 (ov019) +005C.  An
 * unlabelled Thumb leaf inside ov010: `disasm.py` emitted its body as the
 * `pool_02167844` word run because its `push {r4, r5}` prologue saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  ov009 holds
 * ARM data at the address, ov011/ov018/ov019 only call it, so ov010 is the
 * region it lives in.
 *
 * The byte shape turns on the 12-byte aggregate copy: writing the position
 * as one `struct { u64; u32; }` assignment is what makes mwcc evaluate the
 * destination address first (dst in r3, the package kept in r2) and emit the
 * exact `ldm r5!`/`stm r4!` run.  Splitting it into a `u64` store plus a `u32`
 * store makes the allocator compute the source address first.
 * See docs/notes/recursive-match-unblocker-ov010-0215.c.txt and
 * docs/idioms/a-twelve-byte-aggregate-copy-pins-the-destination-first.md.
 */
void func_02167848(CommPlayerWork *work, int index, CommPlayerPackage *package)
{
    /* row = the work shifted by index entries, so entries[0] of row is entry
     * index; &work->entries[index] folds the +8 and changes the bytes. */
    CommPlayerWork *row = (CommPlayerWork *)((char *)work + index * 0x1C);
    row->entries[0].pos = *(CommPlayerPos *)&package->pos;
    row->entries[0].zoneId = package->zoneId;
    row->entries[0].vanish = package->vanish;
}

/*
 * Report the player's position, zone and facing (from the saved copy
 * while flying, from the ov021 rail object, or from the player object),
 * returning 1 only when it differs from the last report. One lever: the
 * change test written positively so the update block comes before the
 * `return 0`.
 */
int func_0216786C(CommPlayerWork *work, CommPlayerPackage *out)
{
    VecFx32 pos;
    void *railPlayer;
    void *player;
    void *gameData;
    CommPlayerLastPos *last;
    void *rail;
    u32 vanish;
    u32 dir;
    u16 zoneId;
    gameData = func_020120F4(work->gameSystem);
    last = &work->last;
    vanish = 0;
    if (work->updateStopped == 1)
        return 0;
    player = func_020127A4(gameData);
    dir = func_02012B28(player);
    if (FIELD_STATUS_GetSeasonDispFlag(func_02012B38(gameData)) == 2) {
        zoneId = last->zoneId;
        pos = last->pos;
        vanish = 1;
        dir = last->dir;
    } else if (func_02012114(work->gameSystem) == 1 && func_02188BE8(func_0201210C(work->gameSystem)) == 1) {
        rail = func_02188CB4(func_0201210C(work->gameSystem));
        railPlayer = func_021A3074(rail);
        if (func_021A34EC(rail) == 4)
            func_021A3038(rail, &pos);
        else
            func_02197CCC(railPlayer, (fx32 *)(&pos));
        zoneId = func_021A3050(rail);
    } else {
        pos = *func_02012AA0(player);
        zoneId = func_02012AE4(player);
    }
    out->zoneId = zoneId;
    out->pos = pos;
    out->vanish = vanish;
    out->dir = dir;
    if (zoneId != last->zoneId || dir != last->dir || vanish != last->vanish
        || func_0203EFC8((const u8 *)(&pos), (const u8 *)last, sizeof(VecFx32)) != 0) {
        last->zoneId = zoneId;
        last->pos = pos;
        last->dir = dir;
        last->vanish = vanish;
        return 1;
    }
    return 0;
}

/*
 * Forwards a five-argument request for one player to the ov021 player
 * system, with a zero bail when that system is not created.
 */
int func_021679A4(CommPlayerWork *work, int index, int a2, int a3, int a4, int a5)
{
    void *playerSys = work->playerSys;
    if (playerSys == 0)
        return 0;
    return func_02194384(playerSys, index, a2, a3, a4, a5);
}

int func_021679C4(CommPlayerWork *work, int index)
{
    CommPlayerEntry *entry;
    void *effectSys;
    entry = &work->entries[index];
    if (work->playerSys == 0 || entry->used == 0 || entry->effect != 0)
        return 0;
    effectSys = (void *)func_02188CD0(func_0201210C(work->gameSystem));
    entry->effect = func_021BB578(effectSys, (void *)func_021943EC(work->playerSys, index), 0, 0);
    return 1;
}

u32 func_02167A14(CommPlayerWork *work, int index)
{
    if (work->playerSys == 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->entries[index].used != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return func_021943EC(work->playerSys, index);
}

/*
 * Unlabelled leaf (sole blocker of ov018 func_0217FCAC).
 */
int func_02167A54(CommPlayerWork *work, int index)
{
    if (work == 0 || work->playerSys == 0 || !((CommPlayerFlagView *)((char *)work + index * 0x1c + 0x1c))->used) {
        return 0;
    }
    return 1;
}

void func_02167A74(void *gameSystem, CommPlayerWork *work)
{
    void *fieldmap;
    if (work->playerSys == 0) {
        fieldmap = func_0201210C(gameSystem);
        if (fieldmap != 0 && func_02188BE8(fieldmap) != 0)
            work->playerSys = func_02194284(work->playerMax, func_02188C7C(fieldmap), work->heapId, work->sysOption);
    }
}
