/*
 * function: SHINKA_DEMO_Destroy
 * address: 0x02204098
 * packet: pkt_ov195_02204098
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x022040DE, then a function prologue.
 * symbols:
 *   SHINKA_DEMO_DeleteScene 0x02204D5C thumb ov195
 *   SHINKA_DEMO_Noop 0x02204DDC thumb ov195
 *   PROCSYS_Delete 0x0203133C arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj08345.h"
struct S020314B8;
struct Proc;
struct Node;
struct U16Vec;
extern void SHINKA_DEMO_DeleteScene(int, int *);
extern void SHINKA_DEMO_Noop(int, int *);
extern void PROCSYS_Delete(struct S020314B8 *);
extern void TCB_DeleteTask(struct Node *);
typedef unsigned int   u32;
extern u32 GFL_HEAP_Free(void *p);
extern void STRBUF_Delete(struct U16Vec *);
extern void PROCSYS_FreeProcWork(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int SHINKA_DEMO_Destroy(struct Proc *a, int unused, int b, int *p)
{
    SHINKA_DEMO_DeleteScene(b, p);
    PROCSYS_Delete(*(struct S020314B8 * *)&((struct Obj08345 *)p)->f11C);
    TCB_DeleteTask(*(struct Node * *)&((struct Obj08345 *)p)->f38);
    SHINKA_DEMO_Noop(b, p);
    GFL_HEAP_Free(((struct Obj08345 *)p)->f100);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj08345 *)p)->f14);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(0x94);
    return 1;
}
