/*
 * function: func_021DB3A4
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
 *   func_021DD02C  0x021DD02C  thumb
 *   func_021DD034  0x021DD034  thumb
 *   func_021DD038  0x021DD038  thumb
 *   func_021DD040  0x021DD040  thumb
 *   func_021DB7C0  0x021DB7C0  thumb
 *   func_021DBA00  0x021DBA00  thumb
 *   func_021DBB00  0x021DBB00  thumb
 *   func_021DBB54  0x021DBB54  thumb
 *   func_021DBBAC  0x021DBBAC  thumb
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

extern char *func_021DD02C(void);
extern u32 func_021DD034(void);
extern char *func_021DD038(void);
extern u32 func_021DD040(void);
struct Field;
extern void func_021DB7C0(int count, struct Field **fields, char *p, int n);
extern void func_021DBA00(int count, struct Field **fields, u8 *p, int n);
extern void func_021DBB00(int count, char **rows, int *out, int width);
extern void func_021DBB54(int count, struct Field **recs, void *dst, int nfields);
extern void func_021DBBAC(int count, struct Field **recs, void *dst, int nfields);
extern char d_021E2DF4[];
extern char d_021E2DEC[];
extern char d_021E2DF0[];

void func_021DB3A4(char *obj, u32 target, int kind, u32 arg)
{
    ((struct Obj01170 *)obj)->f12C = 0;
    ((struct Obj01170 *)obj)->f178 = arg;
    ((struct Obj01170 *)obj)->f1B0 = target;
    switch (kind) {
    case 0:
        *(char * *)&((struct Obj01170 *)obj)->f194 = func_021DD02C();
        ((struct Obj01170 *)obj)->f198 = func_021DD034();
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DB7C0;
        break;
    case 1:
        *(char * *)&((struct Obj01170 *)obj)->f194 = func_021DD038();
        ((struct Obj01170 *)obj)->f198 = func_021DD040();
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBA00;
        break;
    case 2:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DF4;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBB00;
        break;
    case 3:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DEC;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBB54;
        break;
    case 4:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DF0;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBBAC;
        break;
    }
}
