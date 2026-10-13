/*
 * function: NAMEIN_SETUP_InitHostProc
 * address:  0x0216C888
 * packet:   pkt_0216C888
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   PROCSYS_Create  0x02031324  arm
 */
#include "../include/Obj12055.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);
extern int PROCSYS_AllocProcWork();
extern void *PROCSYS_Create(int a0);

int NAMEIN_SETUP_InitHostProc(int a0, int a1, int a2)
{
    int t4;

a2 = 1;
t4 = a0 + 0;
a0 = 1;
a1 = 0x76;
a2 = a2 << 0xe;
    GFL_HEAP_CreateChildHeap(a0, a1, a2);
loc_0216C898:
a0 = t4 + 0;
a1 = 4;
a2 = 0x76;
    a0 = PROCSYS_AllocProcWork(a0, a1, a2);
loc_0216C8A2:
t4 = a0 + 0;
a0 = 0x76;
    a0 = (int)PROCSYS_Create(a0);
loc_0216C8AA:
((struct Obj12055 *)((char *)t4))->f0 = a0;
a0 = 1;
    return a0;}
