/*
 * file:     fldmmdl_poslog.c
 * unit:     yes
 * function: func_0216E474, func_0216E47C, func_0216E490, func_0216E4B0, func_0216E4EC, func_0216E51C, func_0216E544, func_0216E57C, func_0216E5B0, func_0216E5FC, func_0216E618, func_0216E62C
 * address:  0x0216E474
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trcard_sys.c (it held four originals); __FILE__ anchors: event_battle.c 0x0216E95C, trcard_sys.c 0x0216F0AC, waza_oshie.c 0x0216F918.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   d_02172A70 0x02172A70 data a2
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   d_02172554  0x02172554  data  ov010  a2
 *   d_02172556  0x02172556  data  ov010  a2
 */

struct Actor;
struct VecFx32;
struct ZukanSave;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } MovedPos;

typedef struct
{
    char pad00[44];
    unsigned int movedPosTable;
} ObjContext;

typedef short s16;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    u16 x;
    u16 y;
    int z;
} Pos;

typedef struct {
    u8 pad00[0x18];
    int state;
    Pos pos;
} PosRecord;

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern u16 func_0216D598(void *p);
extern u16 func_0216D590(void *p);
extern u16 func_0216D588(void *p);
extern void *func_0216D67C(void *);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
int func_0216E51C();
int func_0216E544(void *mmdl, MovedPos *out);
void func_0216E57C(void *a, int a1);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern void *func_0200CA1C(void *a);
extern unsigned int func_02017E1C(void *a, unsigned int b, unsigned int c);
extern u32 func_02017988(void *p, u32 a);
extern void func_0200CFA0(struct ZukanSave *p, void *m);
int func_0216E5B0(void *map, const VecFx32 *pos);
int func_0216E5FC(u16 id);
void func_0216E618(PosRecord *rec, u16 x, u16 y, int z);
void func_0216E62C(void *saveData, void *mon, int placeId);
u32 func_0216E474(void);
void func_0216E47C(void *block);
int func_0216E490(const MovedPos *pos);
int func_0216E4B0(int a, int b);
int func_0216E4EC(int a0, int a1);
extern const u16 d_02172A70[][4];
extern u16 d_02172554[][2];
extern u16 d_02172556[][2];


/*
 * Save-table size callback: returns 0x168, the size of the block that
 * func_0216E47C fills.  Pointer word 0x0216E475 at arm9 0x0209DC90.
 */
u32 func_0216E474(void)
{
    return 0x168;
}






/*
 * Save-table init callback: fills the 0x168-byte block with 0xFF bytes
 * (tail call to MIi_CpuClear32 through the pool word at 0x0216E48C).
 * Pointer word 0x0216E47D at arm9 0x0209DC94.
 */
void func_0216E47C(void *block)
{
    MIi_CpuClear32(0xFFFFFFFF, block, 0x168);
}








int func_0216E490(const MovedPos *pos)
{
    if (pos->x != -1 || pos->y != -1 || pos->z != -1)
        return 1;
    return 0;
}






/*
 * lever: declaring x and y before the unsigned-long index restores the
 * table base, sentinel and index register allocation. The once300
 * permuter found this ordering; explicit-region one resolves both pools.
 */
int func_0216E4B0(int gridX, int gridZ)
{
    int rowX;
    int rowZ;
    unsigned long i;
    i = 0;
    do
    {
        rowX = d_02172A70[i][0];
        rowZ = d_02172A70[i][1];
        if ((rowX == gridX) && (rowZ == gridZ))
            return d_02172A70[i][2];
        i++;
    }
    while ((rowX != 65535) && (rowZ != 65535));
    return 30;
}






int func_0216E4EC(int mmdl, int unused)
{
    int slot = 30;

    if (func_0216E5FC(func_0216D598((void *)mmdl)) == 1)
        slot = func_0216E4B0(func_0216D590((void *)mmdl), func_0216D588((void *)mmdl));
    return slot;
}





int func_0216E51C(mmdl, unused)
void *mmdl;
int unused;
{
    int slot;
    ObjContext *ctx;

    slot = func_0216E4EC((int)mmdl, unused);
    if (slot != 30) {
        ctx = func_0216D67C(mmdl);
        return func_0216E490((const MovedPos *)(ctx->movedPosTable + slot * 12));
    }
    return 0;
}

int func_0216E544(void *mmdl, MovedPos *out)
{
    int slot;
    MovedPos *entry;
    ObjContext *ctx;

    slot = func_0216E4EC((int)mmdl, (int)out);
    if (slot != 30) {
        ctx = func_0216D67C(mmdl);
        entry = (MovedPos *)(ctx->movedPosTable + slot * 12);
        if (func_0216E490(entry)) {
            *out = *entry;
            return 1;
        }
    }
    return 0;
}


/*
 * lever: binding the getter's pointer result to tmp restores the base
 * load before the stride, while retaining the unsigned raw address sum.
 * ObjContext shape: matched CC58 allocates 0x48 and stores input c at +44.
 * E4EC returns 30 unless E4FA compares equal to 1, then returns E4B0's
 * halfword or 30. Thus i <=65535 and i*12 <=786420; no Vec array bound
 * is assumed. D88C unconditionally initializes all 12 bytes of v.
 */
void func_0216E57C(void *mmdl, int unused)
{
    int slot;
    MovedPos *entry;
    MovedPos curPos;
    ObjContext *ctx;
    slot = func_0216E4EC((int)mmdl, unused);
    if (slot != 30)
    {
        ctx = func_0216D67C(mmdl);
        entry = (MovedPos *) (ctx->movedPosTable + (slot * 12));
        func_0216D88C(mmdl, (struct VecFx32 *)&curPos);
        *entry = curPos;
    }
}




/*
 * Whether the map cell under pos (x, z in whole tiles of 16 units) holds a
 * hit whose check returns 1.
 */
int func_0216E5B0(void *map, const VecFx32 *pos)
{
    void *mmdl = func_0216DDDC((u32)map, (s16)((pos->x >> 4) / 4096), (s16)((pos->z >> 4) / 4096), pos->y, 0x20000, (int)0);

    if (mmdl != 0 && func_0216E51C(mmdl) == 1)
        return 1;
    return 0;
}




/*
 * True for kind 0x6D and 0x2003..0x2005. The range test must be written
 * as `(u16)(id + 0xDFFD) <= 2`: `id >= 0x2003 && id <= 0x2005` keeps two
 * compares, `(u16)(id - 0x2003)` pools 0x2003 and subtracts.
 */
int func_0216E5FC(u16 objCode)
{
    if (objCode == 0x6D || (u16)(objCode + 0xDFFD) <= 2)
        return 1;
    return 0;
}




/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C758): clears the word
 * at +0x18 and fills the {u16, u16, int} record at +0x1C.
 */
void func_0216E618(PosRecord *rec, u16 x, u16 y, int z)
{
    Pos *pos;

    rec->state = 0;
    pos = &rec->pos;
    pos->x = x;
    pos->y = y;
    pos->z = z;
}




void func_0216E62C(void *saveData, void *mon, int placeId)
{
    struct ZukanSave *zukan;
    int species;
    int i;

    zukan = func_0200CA1C(saveData);
    species = func_02017E1C(mon, 5, 0);
    for (i = 0; i < 25; i++) {
        if (placeId == d_02172554[i][0]) {
            int form = d_02172556[i][0];
            if (species == 0x19c) {
                func_02017988(mon, (u16)form);
                func_0200CFA0(zukan, mon);
            }
            return;
        }
    }
}
