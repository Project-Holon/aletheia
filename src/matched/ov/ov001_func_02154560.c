/*
 * function: EVENT_GTSNEGO_InitWork
 * address:  0x02154560
 * packet:   pkt_02154560
 * region:   ov001
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builder: guard + allocator, then a straight slab/field layout.
 *
 * symbols:
 *   ICA_ANIME_GetField1C   0x020120F4  thumb
 *   ICA_ANIME_GetField24   0x02012138  thumb
 *   func_020124E8   0x020124E8  thumb
 *   GAME_COMM_GetKind   0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback   0x02026400  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   MI_CpuFill8   0x02082BCC  arm
 *   MYSTATUS_GetSize   0x02008468  thumb
 *   func_02030734   0x02030734  arm
 *   GAME_DATA_GetMyStatus   0x02012944  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 *   d_021546A0      0x021546A0  data  ov001  a4
 */
#include "../include/Obj01477.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Comm;
struct Ctx;
struct Party;
void *ICA_ANIME_GetField1C(const struct Ctx *p);
struct Ctx;
struct Obj;
u32 ICA_ANIME_GetField24(const struct Ctx *p);
void *func_020124E8(struct Obj *p);
u32 GAME_COMM_GetKind(void *obj);
void GAME_COMM_RequestExitNoCallback(struct Comm *p);
struct Party *POKEPARTY_Create(u32 heap);
void MI_CpuFill8(void *p, int c, int n);
int MYSTATUS_GetSize(void);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u8 *GAME_DATA_GetMyStatus(void *p);
void MI_CpuCopy8(u32 a, void *p, u32 b);

extern char d_021546A0[];

void *EVENT_GTSNEGO_InitWork(void *obj_in, void *p, int a, int b)
{
    void *obj;

    if (GAME_COMM_GetKind((void *)ICA_ANIME_GetField24(p)))
        GAME_COMM_RequestExitNoCallback((struct Comm *)ICA_ANIME_GetField24(p));
    obj = func_020124E8(obj_in);
    ((struct Obj01477 *)obj)->f17C = (int)p;
    ((struct Obj01477 *)obj)->f3B0 = b;
    ((struct Obj01477 *)obj)->f3AC = (int)POKEPARTY_Create(4);
    ((struct Obj01477 *)obj)->f354 = ((struct Obj01477 *)obj)->f3AC;
    MI_CpuFill8((char *)obj + 0x184, 0, 0x1b4);
    ((struct Obj01477 *)obj)->f184 = (int)ICA_ANIME_GetField1C(p);
    ((struct Obj01477 *)obj)->f198 = (int)func_02030734(4, MYSTATUS_GetSize(), 1, d_021546A0, 0x123);
    ((struct Obj01477 *)obj)->f19C = (int)func_02030734(4, MYSTATUS_GetSize(), 1, d_021546A0, 0x124);
    MI_CpuCopy8((u32)GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(p)), (void *)((struct Obj01477 *)obj)->f198, MYSTATUS_GetSize());
    MI_CpuFill8((char *)obj + 0x368, 0, 0x28);
    ((struct Obj01477 *)obj)->f368 = (int)ICA_ANIME_GetField1C(p);
    ((struct Obj01477 *)obj)->f36C = 0;
    ((struct Obj01477 *)obj)->f370 = 1;
    ((struct Obj01477 *)obj)->f390 = (int)ICA_ANIME_GetField1C(p);
    ((struct Obj01477 *)obj)->f394 = 0;
    ((struct Obj01477 *)obj)->f398 = 1;
    return obj;
}
