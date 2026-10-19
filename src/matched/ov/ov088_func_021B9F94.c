/*
 * function: STARTMENU_MenuInit
 * address:  0x021B9F94
 * packet:   pkt_ov088_021B9F94
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02008730  0x02008730  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   func_02009210  0x02009210  thumb
 *   GAME_DATA_GetEventWorkFromSave  0x02012FE4  thumb
 */

extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
typedef unsigned int   u32;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, int);
struct Sub02007084Ctrl;
struct Sub0200852CObj;
struct Sub02009210Obj;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void *MISC_GetBlock(void *sys);
extern struct Sub02009210Obj *func_02009210(void *sys);
struct Sub020071CCCtrl;
extern void *GAME_DATA_GetEventWorkFromSave(struct Sub020071CCCtrl *a0);

int STARTMENU_MenuInit(struct Proc *a)
{
    int *p;
    GFL_HEAP_CreateChildHeap(1, 0xb, 0x80000);
    p = PROCSYS_AllocProcWork(a, 0x150, 0xb);
    MI_CpuFill8(p, 0, 0x150);
    p[0] = (int)func_020070A4();
    p[1] = (int)func_02008730((void *)p[0]);
    p[2] = (int)MISC_GetBlock((void *)p[0]);
    p[3] = (int)func_02009210((void *)p[0]);
    p[4] = (int)GAME_DATA_GetEventWorkFromSave((struct Sub020071CCCtrl *)p[0]);
    return 1;
}
