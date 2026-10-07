/*
 * file:     wifibattlematch_net_p20.c
 * unit:     yes
 * function: func_021DB378, func_021DB3A4, func_021DB478, func_021DB6A0, func_021DB6A8, func_021DB72C
 * address:  0x021DB378
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
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
 *   DWC_GdbInitialize         0x021E10CC  arm
 *   DWC_GdbGetMyRecordsAsync  0x021E1618  arm
 *   DWC_GdbGetRecordsAsync    0x021E16F0  arm
 *   DWC_GdbProcess            0x021E1414  arm
 *   DWC_GdbGetState           0x021E1434  arm
 *   DWC_GdbGetAsyncResult     0x021E1454  arm
 *   DWC_GdbCancelRequest      0x021E11F0  arm
 *   func_021DCE08             0x021DCE08  thumb
 *   func_021DCE40             0x021DCE40  thumb
 *   func_021DCE48             0x021DCE48  thumb
 *   func_021DCE50             0x021DCE50  thumb
 *   func_02034714             0x02034714  arm
 *   d_021E2EF8                0x021E2EF8  data
 *   d_021E2F1C                0x021E2F1C  data
 *   DWC_GdbShutdown  0x021E1340  arm
 *   func_02012944 0x02012944 thumb
 *   func_021DA470 0x021DA470 thumb ov175
 *   func_021DD020 0x021DD020 thumb ov175
 *   d_021E2F2C 0x021E2F2C data a4
 *   d_021E2F38 0x021E2F38 data a4
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 *   func_0203F028  0x0203F028  arm
 *   d_021E2F70     0x021E2F70  data
 */
#include "../../matched/include/Obj14340.h"
#include "../../matched/include/Obj01170.h"
#include "../../matched/include/Obj00840.h"
#include "../../matched/include/Obj01171.h"
#include "../../matched/include/Obj24341.h"
#include "../../matched/include/Obj24342.h"
#include "../../matched/include/Obj24343.h"
#include "../../matched/include/Obj24344.h"
#include "../../matched/include/Obj24345.h"
#include "../../matched/include/Obj24346.h"
#include "../../matched/include/Obj24347.h"
#include "../../matched/include/Obj24348.h"
#include "../../matched/include/Obj24349.h"
#include "../../matched/include/Obj24350.h"
#include "../../matched/include/Obj24351.h"
#include "../../matched/include/Obj24352.h"
#include "../../matched/include/Obj24353.h"
#include "../../matched/include/Obj24354.h"
#include "../../matched/include/Obj06574.h"

struct Entry;
struct Link;
struct Field;
typedef unsigned long u32_021DB378;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_021DB3A4;

typedef void (*StepFn)(void);

typedef unsigned long u32_021DB478;

typedef unsigned int   u32_021DB6A8;

typedef unsigned long u32_021DB72C;

struct Field {
    const char *name;
    u32_021DB72C type;
    u32_021DB72C value;
    u32_021DB72C pad;
};

typedef void (*RecordsFn)(int count, struct Field **recs, u32_021DB72C a, int nfields);

extern struct Entry *func_020399A8(void);
extern u32_021DB378 func_0203D1A4(struct Link *p);
extern char *func_021DD02C(void);
extern u32_021DB3A4 func_021DD034(void);
extern char *func_021DD038(void);
extern u32_021DB3A4 func_021DD040(void);
extern void func_021DB7C0(int count, struct Field **fields, char *p, int n);
extern void func_021DBA00(int count, struct Field **fields, u8 *p, int n);
extern void func_021DBB00(int count, char **rows, int *out, int width);
extern void func_021DBB54(int count, struct Field **recs, void *dst, int nfields);
extern void func_021DBBAC(int count, struct Field **recs, void *dst, int nfields);
extern int DWC_GdbInitialize(u32_021DB478 gameId, u32_021DB478 user, int ssl);
extern int DWC_GdbGetMyRecordsAsync(const char *table, void *fields, int nfields, void *cb, void *param);
extern int DWC_GdbGetRecordsAsync(const char *table, int *ids, int nids, void *fields, int nfields, void *cb, void *param);
extern void DWC_GdbProcess(void);
extern int DWC_GdbGetState(void);
extern int DWC_GdbGetAsyncResult(void);
extern int DWC_GdbCancelRequest(void);
extern void func_021DCE08(char *ctx, u32_021DB478 v, int line);
extern void func_021DCE40(char *ctx, u32_021DB478 v, int line);
extern void func_021DCE48(char *ctx, u32_021DB478 v, int line);
extern void func_021DCE50(char *ctx, u32_021DB478 v, int line);
extern void func_02034714(const char *expr, u32_021DB478 line, const char *file);
extern void DWC_GdbShutdown(void);
extern u8 *func_02012944(void *p);
extern void func_021DA470(unsigned char *);
extern u32_021DB6A8 func_021DD020(char *obj);
extern int func_0203F028(const char *s1, const char *s2);
void func_021DB378(u32_021DB378 a, u32_021DB378 b, u32_021DB378 *c, char *d, u32_021DB378 e);
void func_021DB3A4(char *obj, u32_021DB3A4 target, int kind, u32_021DB3A4 arg);
int func_021DB478(char *obj);
void func_021DB6A0(char *obj);
void func_021DB6A8(char *ctx);
void func_021DB72C(int count, struct Field **recs, char *obj);
extern char d_021E2DF4[];
extern char d_021E2DEC[];
extern char d_021E2DF0[];
extern const char d_021E2EF8[];
extern const char d_021E2F1C[];
extern char d_021E2F2C[], d_021E2F38[], d_021E2F4C[], d_021E2F60[];
extern const char d_021E2F70[];


/*
 * Same guard as func_021DB300 but it moves the word the third argument
 *     points at into the +0x150 slot of the fourth argument and sets +0x14c.
 */
void func_021DB378(u32_021DB378 a, u32_021DB378 b, u32_021DB378 *c, char *d, u32_021DB378 e)
{
    u32_021DB378 v = *c;

    if (e != (u32_021DB378)func_020399A8())
        return;
    if (a == func_0203D1A4((struct Link *)((u32_021DB378)func_020399A8())))
        return;
    ((struct Obj14340 *)d)->f150 = v;
    ((struct Obj14340 *)d)->f14C = 1;
}


/*
 * Selects a request kind 0..4: stores the table and its count at +0x194/+0x198 and the step callback at +0x17c, after resetting the step word at +0x12c and storing the two arguments.
 */
void func_021DB3A4(char *obj, u32_021DB3A4 target, int kind, u32_021DB3A4 arg)
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


int func_021DB478(char *obj)
{
    int r;

    switch (((struct Obj00840 *)obj)->f12C) {
    case 0:
        r = DWC_GdbInitialize(0xb5f, ((struct Obj00840 *)obj)->f0, 0);
        if (r != 0) {
            func_021DCE40(obj + 0x18, r, 0xdef);
            func_021DB6A0(obj);
            return 2;
        }
        ((struct Obj00840 *)obj)->f12C = 1;
        break;
    case 1:
        if (((struct Obj00840 *)obj)->f198 >= 0x26)
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
        if (((struct Obj00840 *)obj)->f1B0 == -1)
            r = DWC_GdbGetMyRecordsAsync(d_021E2F1C, ((struct Obj00840 *)obj)->f194, ((struct Obj00840 *)obj)->f198, func_021DB72C, obj);
        else
            r = DWC_GdbGetRecordsAsync(d_021E2F1C, (int *)(obj + 0x1b0), 1, ((struct Obj00840 *)obj)->f194, ((struct Obj00840 *)obj)->f198, func_021DB72C, obj);
        if (r != 0) {
            func_021DCE40(obj + 0x18, r, 0xe0a);
            func_021DB6A0(obj);
            return 2;
        }
        ((struct Obj00840 *)obj)->f12C = 2;
        ((struct Obj00840 *)obj)->f1A0 = 0;
        break;
    case 2:
        if ((((struct Obj00840 *)obj)->f1A0)++ > 0xe10) {
            func_021DCE08(obj + 0x18, 1, 0xe17);
            ((struct Obj00840 *)obj)->f12C = 6;
            break;
        }
        DWC_GdbProcess();
        r = DWC_GdbGetState();
        if (r == 0 || r == 4) {
            func_021DCE48(obj + 0x18, r, 0xe26);
            ((struct Obj00840 *)obj)->f12C = 6;
        } else if (r == 1) {
            ((struct Obj00840 *)obj)->f12C = 3;
        }
        break;
    case 3:
        r = DWC_GdbGetAsyncResult();
        if (r == 0) {
            func_021DCE50(obj + 0x18, r, 0xe39);
            ((struct Obj00840 *)obj)->f12C = 6;
        } else if (r != 1) {
            func_021DCE50(obj + 0x18, r, 0xe3f);
            func_021DB6A0(obj);
            return 2;
        } else {
            ((struct Obj00840 *)obj)->f12C = 4;
        }
        break;
    case 4:
        func_021DB6A0(obj);
        ((struct Obj00840 *)obj)->f12C = 5;
        break;
    case 5:
        return 1;
    case 6:
        r = DWC_GdbCancelRequest();
        if (r == 0) {
            ((struct Obj00840 *)obj)->f1A0 = 0;
            ((struct Obj00840 *)obj)->f12C = 7;
        } else {
            func_021DCE40(obj + 0x18, r, 0xe5e);
            func_021DB6A0(obj);
            return 2;
        }
        break;
    case 7:
        if ((((struct Obj00840 *)obj)->f1A0)++ > 0xe10) {
            func_021DCE08(obj + 0x18, 1, 0xe6a);
            func_021DB6A0(obj);
            return 2;
        }
        DWC_GdbProcess();
        r = DWC_GdbGetState();
        if (r == 0 || r == 4) {
            func_021DB6A0(obj);
            return 2;
        }
        if (r == 1)
            ((struct Obj00840 *)obj)->f12C = 8;
        break;
    case 8:
        func_021DB6A0(obj);
        return 2;
    }
    return 0;
}


/*
 * Shuts the storage-server database client down (unlabelled; reached by bl from func_021DB478).
 */
void func_021DB6A0(char *obj)
{
    DWC_GdbShutdown();
}

void func_021DB6A8(char *ctx)
{
    void *record;
    record = func_02012944(((struct Obj01171 *)ctx)->f8);
    *(char * *)&((struct Obj24341 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f0 = d_021E2F2C;
    ((struct Obj24342 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f4 = 8;
    ((struct Obj24343 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f8 = record;
    ((struct Obj24344 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->fC = 32;
    func_021DA470((unsigned char *)ctx + 0x38);
    *(char * *)&((struct Obj24345 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f10 = d_021E2F38;
    ((struct Obj24346 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f14 = 8;
    *(char * *)&((struct Obj24347 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f18 = ctx + 0x38;
    ((struct Obj24348 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f1C = 6;
    *(char * *)&((struct Obj24349 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f20 = d_021E2F4C;
    ((struct Obj24350 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f24 = 2;
    ((struct Obj24351 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f28 = ((struct Obj01171 *)ctx)->fC;
    *(char * *)&((struct Obj24352 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f30 = d_021E2F60;
    ((struct Obj24353 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f34 = 2;
    ((struct Obj24354 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f38 = func_021DD020(ctx);
    ((struct Obj01171 *)ctx)->f198 = 4;
}


/*
 * Storage-server records callback: forwards the records to the user callback at +0x17c, then, when no record id is pending (+0x1b0 == -1), scans every field of every record for the id field and stores its value through the pointer at +0x1464.
 */
void func_021DB72C(int count, struct Field **recs, char *obj)
{
    int i, j;
    struct Field *f;

    (*(RecordsFn *)(obj + 0x17c))(count, recs, ((struct Obj06574 *)obj)->f178, ((struct Obj06574 *)obj)->f198);
    if (((struct Obj06574 *)obj)->f1B0 != -1)
        return;
    for (i = 0; i < count; i++) {
        for (j = 0; j < ((struct Obj06574 *)obj)->f198; j++) {
            f = &recs[i][j];
            if (func_0203F028(f->name, d_021E2F70) == 0)
                **(u32_021DB72C * *)&((struct Obj06574 *)obj)->f1464 = f->value;
        }
    }
}
