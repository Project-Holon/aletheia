/*
 * file:     bag_param.c
 * unit:     yes
 * function: BAG_PARAM_Create
 * address:  0x0202E474
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   BagParamFileName  0x020A77C4  data
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_GetField114  0x020127A4  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_shared_types.h"

struct Big;

struct SaveBlock;

struct Sub02008700Obj;

struct Rec44;

struct BagParam {
    void *gameData;
    void *myStatus;
    void *myItem;
    u32   saveWork;
    void *config;
    u8    itemCheck[0x18];
    int   mode;
    int   cycleFlag;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern struct Sub02008700Obj *func_0200873C(void *sys);

extern u8 *GAME_DATA_GetMyStatus(void *p);

extern unsigned int GAME_DATA_GetMapMatrix(const struct BigObj *p);

extern void *GAME_DATA_GetMyItem(const struct BigObj *p);

extern void  MI_CpuCopy8(void *src, void *dst, int n);

extern void *GAME_DATA_GetField114(struct SaveBlock *p);

extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);

void *BAG_PARAM_Create(const struct BigObj *gameData, int itemCheck, int mode, int heapId);

extern char BagParamFileName[];

/*
 * Allocates and fills one record of a per-something description list,
 * followed by eight "read the sub-object" calls.  The fifth argument to
 * GFL_HEAP_Alloc is the pool-relative caller tag (0x37 here, the same 0x3c/
 * 0x3d/0x83/0x84 tags in the neighbours are the same convention).
 *
 * Argument order of MI_CpuCopy8 is (src, dst, n): the original loads r1
 * with `p + 0x14` *before* r0 with a1, so r1 - the second slot - is the
 * destination.  Writing the copy as `MI_CpuCopy8(dst, src, n)` reverses the
 * two registers and costs seven bytes.
 *
 * The pool word 0x020A77C4 is a `string` site: it is the `__FILE__`-style
 * name run whose start is pinned by the terminator of the string before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BAG_PARAM_Create.c \
 *       --func BAG_PARAM_Create --addr 0x0202E474 --cc 1.1p1 --thumb
 */
void *BAG_PARAM_Create(const struct BigObj *gameData, int itemCheck, int mode, int heapId)
{
    int   saveControl = (int)GAME_DATA_GetSaveControl((struct Big *)gameData);
    struct BagParam *param = GFL_HEAP_Alloc(heapId, 0x3c, 1, BagParamFileName, 0x37);

    param->gameData = (void *)gameData;
    param->myStatus = func_0200873C((void *)saveControl);
    param->myItem = GAME_DATA_GetMyStatus((void *)gameData);
    param->saveWork = GAME_DATA_GetMapMatrix(gameData);
    param->config = GAME_DATA_GetMyItem((const struct BigObj *)gameData);
    if (itemCheck != 0) {
        MI_CpuCopy8((void *)itemCheck, param->itemCheck, 0x18);
    }
    param->mode = mode;
    param->cycleFlag = GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetField114((struct SaveBlock *)gameData)) == 1;
    return param;
}
