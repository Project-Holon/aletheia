/*
 * function: MCSS_Exit
 * address:  0x02014BA8
 * packet:   pkt_02014808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_CloseHandle   0x02014CD4  thumb
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02030EAC   0x02030EAC  arm
 *   MCSS_Del   0x02015BA4  thumb
 *
 * Tear-down of a "list of arrays" record: close the open sub-object at +0xC
 * (three frees through the handle returned by TCBL_IsDeletePending, then the handle
 * itself), then walk the +0x14 array of +0x10 entries and release each live
 * one through MCSS_Del, finally the array and the record itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_Exit.c \
 *       --func MCSS_Exit --addr 0x02014BA8 --cc 1.1p1 --thumb
 */
#include "../include/Obj03429.h"
#include "../include/Obj11255.h"
#include "../include/Obj15656.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Node;
struct Sub02014CB8Obj;
extern void MCSS_CloseHandle(struct Sub02014CB8Obj *o);
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void  MCSS_Del(void *a0, void *a1);

void MCSS_Exit(u8 *a0)
{
    int i;

    MCSS_CloseHandle((struct Sub02014CB8Obj *)a0);
    if (*(u8 * *)&((struct Obj03429 *)a0)->fC != 0) {
        u8 *p = (u8 *)TCBL_IsDeletePending((struct S02030EE8 *)(*(u8 * *)&((struct Obj03429 *)a0)->fC));

        func_020307B0(*(u8 * *)&((struct Obj15656 *)(*(u8 * *)&((struct Obj11255 *)p)->f4))->fC);
        func_020307B0(*(u8 * *)&((struct Obj11255 *)p)->f4);
        func_020307B0(p);
        func_02030EAC((struct Node *)(*(u8 * *)&((struct Obj03429 *)a0)->fC));
        *(u8 * *)&((struct Obj03429 *)a0)->fC = 0;
    }
    for (i = 0; i < ((struct Obj03429 *)a0)->f10; i++) {
        u32 *arr = *(u32 * *)&((struct Obj03429 *)a0)->f14;
        u32 e = arr[i];

        if (e != 0) {
            MCSS_Del(a0, (u8 *)e);
        }
    }
    func_020307B0(*(u8 * *)&((struct Obj03429 *)a0)->f14);
    func_020307B0(a0);
}
