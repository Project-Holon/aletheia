/*
 * function: WIFIBATTLEMATCH_NET_GdbRequest
 * address:  0x021DB3A4
 * packet:   pkt_021DB3A4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_GetRegNameA  0x021DD02C  thumb
 *   WIFIBATTLEMATCH_NET_GetRegKindA  0x021DD034  thumb
 *   WIFIBATTLEMATCH_NET_GetRegNameB  0x021DD038  thumb
 *   WIFIBATTLEMATCH_NET_GetRegKindB  0x021DD040  thumb
 *   WIFIBATTLEMATCH_NET_GdbCopyFieldsA  0x021DB7C0  thumb
 *   WIFIBATTLEMATCH_NET_GdbCopyFieldsB  0x021DBA00  thumb
 *   WIFIBATTLEMATCH_NET_GdbCopyFieldC  0x021DBB00  thumb
 *   WIFIBATTLEMATCH_NET_GdbCopyFieldD  0x021DBB54  thumb
 *   WIFIBATTLEMATCH_NET_GdbCopyFieldE  0x021DBBAC  thumb
 *   d_021E2DF4     0x021E2DF4  data
 *   d_021E2DEC     0x021E2DEC  data
 *   d_021E2DF0     0x021E2DF0  data
 *
 * Selects a request kind 0..4: stores the table and its count at +0x194/+0x198 and the step callback at +0x17c, after resetting the step word at +0x12c and storing the two arguments.
 */
#include "../include/Obj01170.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef void (*StepFn)(void);

extern char *WIFIBATTLEMATCH_NET_GetRegNameA(void);
extern u32 WIFIBATTLEMATCH_NET_GetRegKindA(void);
extern char *WIFIBATTLEMATCH_NET_GetRegNameB(void);
extern u32 WIFIBATTLEMATCH_NET_GetRegKindB(void);
struct Field;
extern void WIFIBATTLEMATCH_NET_GdbCopyFieldsA(int count, struct Field **fields, char *p, int n);
extern void WIFIBATTLEMATCH_NET_GdbCopyFieldsB(int count, struct Field **fields, u8 *p, int n);
extern void WIFIBATTLEMATCH_NET_GdbCopyFieldC(int count, char **rows, int *out, int width);
extern void WIFIBATTLEMATCH_NET_GdbCopyFieldD(int count, struct Field **recs, void *dst, int nfields);
extern void WIFIBATTLEMATCH_NET_GdbCopyFieldE(int count, struct Field **recs, void *dst, int nfields);
extern char d_021E2DF4[];
extern char d_021E2DEC[];
extern char d_021E2DF0[];

void WIFIBATTLEMATCH_NET_GdbRequest(char *obj, u32 target, int kind, u32 arg)
{
    ((struct Obj01170 *)obj)->f12C = 0;
    ((struct Obj01170 *)obj)->f178 = arg;
    ((struct Obj01170 *)obj)->f1B0 = target;
    switch (kind) {
    case 0:
        *(char * *)&((struct Obj01170 *)obj)->f194 = WIFIBATTLEMATCH_NET_GetRegNameA();
        ((struct Obj01170 *)obj)->f198 = WIFIBATTLEMATCH_NET_GetRegKindA();
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldsA;
        break;
    case 1:
        *(char * *)&((struct Obj01170 *)obj)->f194 = WIFIBATTLEMATCH_NET_GetRegNameB();
        ((struct Obj01170 *)obj)->f198 = WIFIBATTLEMATCH_NET_GetRegKindB();
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldsB;
        break;
    case 2:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DF4;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldC;
        break;
    case 3:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DEC;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldD;
        break;
    case 4:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DF0;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldE;
        break;
    }
}
