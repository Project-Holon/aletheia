/*
 * function: DEMO3D_DATA_CreateTask
 * address: 0x021BE9F8
 * packet: pkt_ov203_021BE9F8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   func_02080C54 0x02080C54 arm
 *   func_020056A0 0x020056A0 thumb
 *   DEMO3D_DATA_ApplyCapture 0x021BEAB8 thumb ov203
 *   DEMO3D_DATA_FinishTask 0x021BEAF8 thumb ov203
 *   DEMO3D_DATA_StartCapture 0x021BEB48 thumb ov203
 */
#include "../include/Obj10864.h"
typedef struct Config { unsigned words[11]; } Config;
struct CaptureConfig;
extern void DEMO3D_DATA_ApplyCapture(void *task, const int *ctx);
struct S02030FB4;
extern void DEMO3D_DATA_FinishTask(void *node, int *s);
extern void *TCBL_AddTask(void *, void (*)(void *, void *), unsigned, unsigned);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern unsigned short func_02080C54(void);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void DEMO3D_DATA_StartCapture(struct CaptureConfig *s);
void *DEMO3D_DATA_CreateTask(void *manager, const Config *source)
{
    void *task;
    char *ctx;
    task = TCBL_AddTask(manager, (void (*)(void *, void *))DEMO3D_DATA_ApplyCapture, 56, 5);
    ctx = TCBL_GetWork(task);
    *(Config *)(ctx + 4) = *source;
    ((struct Obj10864 *)ctx)->f34 = task;
    ((struct Obj10864 *)ctx)->f30 = 0;
    ((struct Obj10864 *)ctx)->f0 = func_02080C54();
    DEMO3D_DATA_StartCapture((struct CaptureConfig *)(ctx + 4));
    func_020056A0((unsigned)DEMO3D_DATA_FinishTask, (unsigned)ctx, 0);
    return ctx;
}
