/*
 * function: BSUBWAY_RECORD_LIST_Exit
 * address:  0x021B9680
 * packet:   pkt_ov069_021B9680
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BSUBWAY_RECORD_LIST_DeleteCursor  0x021B9F58  thumb  ov069
 *   BSUBWAY_RECORD_LIST_ExitText  0x021B9DE8  thumb  ov069
 *   BSUBWAY_RECORD_LIST_DeleteWindows  0x021B9CD8  thumb  ov069
 *   BSUBWAY_RECORD_LIST_DeleteActors  0x021B9BF0  thumb  ov069
 *   BSUBWAY_RECORD_LIST_DeleteFrames  0x021B9A44  thumb  ov069
 *   BSUBWAY_RECORD_LIST_ReleaseBgLayers  0x021B9888  thumb  ov069
 *   BSUBWAY_RECORD_LIST_FreeWork  0x021B9784  thumb  ov069
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern int BSUBWAY_RECORD_LIST_DeleteCursor(char *p);
extern void BSUBWAY_RECORD_LIST_ExitText(u8 *p);
extern void BSUBWAY_RECORD_LIST_DeleteWindows(u8 *p);
extern void BSUBWAY_RECORD_LIST_DeleteActors(char *p);
extern void BSUBWAY_RECORD_LIST_DeleteFrames(void *p);
extern void BSUBWAY_RECORD_LIST_ReleaseBgLayers(void *p);
extern void BSUBWAY_RECORD_LIST_FreeWork(u8 *p);
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void *func_0203084C(u32 heapId);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);

int BSUBWAY_RECORD_LIST_Exit(u32 a, u32 b, u32 c, void *p)
{
    BSUBWAY_RECORD_LIST_DeleteCursor(p);
    BSUBWAY_RECORD_LIST_ExitText(p);
    BSUBWAY_RECORD_LIST_DeleteWindows(p);
    BSUBWAY_RECORD_LIST_DeleteActors(p);
    BSUBWAY_RECORD_LIST_DeleteFrames(p);
    BSUBWAY_RECORD_LIST_ReleaseBgLayers(p);
    BSUBWAY_RECORD_LIST_FreeWork(p);
    func_020315D4((struct Proc *)a);
    func_0203084C(0x80);
    GFL_HEAP_DeleteChecked(0x80);
    return 1;
}
