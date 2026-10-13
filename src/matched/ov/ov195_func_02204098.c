/*
 * function: func_02204098
 * address: 0x02204098
 * packet: pkt_ov195_02204098
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x022040DE, then a function prologue.
 * symbols:
 *   func_02204D5C 0x02204D5C thumb ov195
 *   func_02204DDC 0x02204DDC thumb ov195
 *   PROCSYS_Delete 0x0203133C arm
 *   sub_02030EAC 0x02030EAC arm
 *   sub_020307B0 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj08345.h"
struct S020314B8;
struct S020315D4;
struct Node;
struct U16Vec;
extern void func_02204D5C(int, int *);
extern void func_02204DDC(int, int *);
extern void PROCSYS_Delete(struct S020314B8 *);
extern void sub_02030EAC(struct Node *);
typedef unsigned int   u32;
extern u32 sub_020307B0(void *p);
extern void STRBUF_Delete(struct U16Vec *);
extern void PROCSYS_FreeProcWork(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
int func_02204098(struct S020315D4 *a, int unused, int b, int *p)
{
    func_02204D5C(b, p);
    PROCSYS_Delete(*(struct S020314B8 * *)&((struct Obj08345 *)p)->f11C);
    sub_02030EAC(*(struct Node * *)&((struct Obj08345 *)p)->f38);
    func_02204DDC(b, p);
    sub_020307B0(((struct Obj08345 *)p)->f100);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj08345 *)p)->f14);
    PROCSYS_FreeProcWork(a);
    func_020306F0(0x94);
    return 1;
}
