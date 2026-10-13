/*
 * function: BAG_PARAM_Create
 * address:  0x0202E474
 * packet:   pkt_0202E474
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_020A77C4  0x020A77C4  data
 *   GAME_DATA_GetMapMatrix  0x02012924  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *
 * Allocates and fills one record of a per-something description list,
 * followed by eight "read the sub-object" calls.  The fifth argument to
 * func_02030734 is the pool-relative caller tag (0x37 here, the same 0x3c/
 * 0x3d/0x83/0x84 tags in the neighbours are the same convention).
 *
 * Argument order of func_02082D44 is (src, dst, n): the original loads r1
 * with `p + 0x14` *before* r0 with a1, so r1 - the second slot - is the
 * destination.  Writing the copy as `func_02082D44(dst, src, n)` reverses the
 * two registers and costs seven bytes.
 *
 * The pool word 0x020A77C4 is a `string` site: it is the `__FILE__`-style
 * name run whose start is pinned by the terminator of the string before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BAG_PARAM_Create.c \
 *       --func BAG_PARAM_Create --addr 0x0202E474 --cc 1.1p1 --thumb
 */
#include "../include/Obj04060.h"

typedef unsigned char  u8;
struct Big;
struct BigObj;
struct SaveBlock;
struct Sub02008700Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_02030734(unsigned int a0, unsigned int a1, int a2, const char *a3, unsigned short a4);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern unsigned int GAME_DATA_GetMapMatrix(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void  func_02082D44(void *src, void *dst, int n);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
typedef unsigned int   u32;
struct Rec44;
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);

extern char data_020A77C4[];

void *BAG_PARAM_Create(const struct BigObj *a0, int a1, int a2, int a3)
{
    int   v = (int)GAME_DATA_GetSaveControl((struct Big *)a0);
    char *p = func_02030734(a3, 0x3c, 1, data_020A77C4, 0x37);

    ((struct Obj04060 *)p)->f0 = (int)a0;
    ((struct Obj04060 *)p)->f4 = (int)func_0200873C((void *)v);
    ((struct Obj04060 *)p)->f8 = (int)GAME_DATA_GetMyStatus((void *)a0);
    ((struct Obj04060 *)p)->fC = GAME_DATA_GetMapMatrix(a0);
    ((struct Obj04060 *)p)->f10 = GAME_DATA_GetMyItem((const struct BigObj *)a0);
    if (a1 != 0) {
        func_02082D44((void *)a1, p + 0x14, 0x18);
    }
    ((struct Obj04060 *)p)->f2C = a2;
    ((struct Obj04060 *)p)->f30 = GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)a0)) == 1;
    return p;
}
