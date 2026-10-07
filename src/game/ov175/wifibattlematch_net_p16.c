/*
 * file:     wifibattlematch_net_p16.c
 * unit:     yes
 * function: func_021D9EEC, func_021D9F04, func_021DA044, func_021DA054, func_021DA0D4, func_021DA1E4, func_021DA36C, func_021DA384, func_021DA390, func_021DA434, func_021DA45C, func_021DA470
 * address:  0x021D9EEC
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
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02006210  0x02006210  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02012E08  0x02012E08  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   func_02157170  0x02157170  thumb
 *   func_021DCE60  0x021DCE60  thumb
 *   func_021DCEE0  0x021DCEE0  thumb
 *   func_021DCFDC  0x021DCFDC  thumb
 *   func_0203C968  0x0203C968  arm
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200FA84  0x0200FA84  thumb
 *   func_021DCFFC  0x021DCFFC  thumb
 *   func_021DB3A4 0x021DB3A4 thumb ov175
 *   func_021DB478 0x021DB478 thumb ov175
 *   func_021DBFA4 0x021DBFA4 thumb ov175
 *   func_021DBFB4 0x021DBFB4 thumb ov175
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   func_021DA4B8                0x021DA4B8  thumb
 *   STD_TSPrintf                 0x0208D7E0  arm
 *   MI_CpuFill8                  0x02082BCC  arm
 *   func_02034714                0x02034714  arm
 *   func_021DA4E8                0x021DA4E8  thumb
 *   func_021DA4F0                0x021DA4F0  thumb
 *   func_021DA4F8                0x021DA4F8  thumb
 *   d_021E2EF8                   0x021E2EF8  data
 *   d_021E2EFC                   0x021E2EFC  data
 *   func_0215580C  0x0215580C  thumb
 *   func_0203C304  0x0203C304  arm
 *   func_02156BC4  0x02156BC4  thumb
 *   func_0203C554  0x0203C554  arm
 *   func_0203C3EC  0x0203C3EC  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_02039338  0x02039338  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_02039C68  0x02039C68  arm
 *   func_020399EC  0x020399EC  arm
 *   func_0203D378  0x0203D378  arm
 *   func_021D9ED4  0x021D9ED4  thumb
 *   func_02156CD0  0x02156CD0  thumb  ov009
 *   g_021E2C8C     0x021E2C8C  data
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj24327.h"
#include "../../matched/include/Obj08279.h"
#include "../../matched/include/Obj14332.h"
#include "../../matched/include/Obj00629.h"
#include "../../matched/include/Obj05458.h"
#include "../../matched/include/Obj00839.h"
#include "../../matched/include/Obj24329.h"
#include "../../matched/include/Obj02513.h"
#include "../../matched/include/Obj14333.h"

struct Entry;
struct Link;
typedef unsigned long u32_021D9EEC;

typedef unsigned long u32_021D9F04;

typedef unsigned char  u8;

typedef enum { RES_NONE, RES_1, RES_2, RES_3, RES_4 } Res;

typedef unsigned int u32_021DA044;

typedef unsigned long u32_021DA0D4;

typedef int (*EvalFn)(int index, void *param);

typedef unsigned long u32_021DA1E4;

typedef unsigned short u16;

typedef unsigned int   u32_021DA36C;

typedef unsigned long u32_021DA384;

typedef unsigned long u32_021DA390;

typedef unsigned long u32_021DA434;

typedef unsigned long u32_021DA45C;

extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *tick, unsigned int value, unsigned int line);
extern int func_0203CD98(void);
extern u32_021D9F04 func_0200FB24(void);
extern void func_0203D7B0(int a);
extern void func_0203D7BC(int a);
extern void func_02006210(void);
extern u8 func_02012E40(const u8 *o);
extern void func_02012E08(char *p);
extern void func_0200F7C0(u32_021D9F04 value);
extern int func_02157170(void *a, void *b);
extern u32_021D9F04 func_021DCE60(int a);
extern u32_021D9F04 func_021DCEE0(int a, int b, int c);
extern u32_021D9F04 func_021DCFDC(u32_021D9F04 v);
extern void func_0203C968(void);
extern void func_0203CA04(void);
extern void func_0200F83C(void);
extern void func_0200FBA0(void);
extern void func_0203C9AC(int a, u32_021D9F04 b, u32_021D9F04 c, u32_021D9F04 d);
extern void func_0200FAAC(void);
extern void func_0200FB38(void);
extern void func_0200FA84(void);
extern void func_021DCFFC(void *p);
extern void func_021DB3A4(char *, unsigned long, int, unsigned long);
extern int func_021DB478(char *);
extern void func_021DBFA4(char *);
extern int func_021DBFB4(char *);
extern void DWC_CloseAllConnectionsHard(void);
extern void func_021DA4B8(char *obj, int i, int value);
extern int STD_TSPrintf(char *dst, const char *fmt, ...);
extern void MI_CpuFill8(void *dst, u8 val, u32_021DA0D4 size);
extern void func_02034714(const char *expr, u32_021DA0D4 line, const char *file);
extern int func_021DA4E8(int index, void *param);
extern int func_021DA4F0(int index, void *param);
extern int func_021DA4F8(int index, void *param);
extern int func_0215580C(char *filter, int n, void *cb, char *obj);
extern u32_021DA1E4 func_0203C304(void);
extern void func_02156BC4(int v);
extern void func_0203C554(u32_021DA1E4 a);
extern int func_0203C3EC(void);
extern u32_021DA1E4 func_0203CA98(void);
extern u16 func_02039338(void);
extern int func_02039ACC(void);
extern void func_02039C68(struct Link *h, unsigned int a, unsigned int b);
extern int func_020399EC(void);
extern u32_021DA1E4 func_0203D378(void);
extern void func_021D9ED4(char *obj, u32_021DA390 v);
extern int func_02156CD0(void);
extern int func_0203D3A8(struct Entry *a, u32_021DA434 b, u32_021DA434 c, u32_021DA434 d);
extern int func_02167ED8(void *date, void *time);
extern void func_02082BCC(void *, int, int);
int func_021D9EEC(char *obj);
int func_021D9F04(char *ctx, void *a, void *b);
void func_021DA044(u8 *p);
int func_021DA054(char *ctx);
void func_021DA0D4(char *obj, int mode, int extra, int group, int *rec);
int func_021DA1E4(char *obj);
void func_021DA36C(void);
void func_021DA384(char *obj);
int func_021DA390(char *obj);
int func_021DA434(void);
u32_021DA45C func_021DA45C(char *obj);
void func_021DA470(unsigned char *dest);
extern const char d_021E2EF8[];
extern const char d_021E2EFC[];
extern u32_021DA434 g_021E2C8C[];


/*
 * Flush partner of func_021D9ED4: sends the byte the object kept at
 *     +0x14 to 0x02039CB4 with the tick/state and line 0x24.
 */
int func_021D9EEC(char *obj)
{
    return func_02039CB4((struct Link *)func_020399A8(), (unsigned char)((struct Obj24327 *)obj)->f14, 0x24);
}


/*
 * Error poll: while the link is up, classifies the transport error through 0x02157170 (0..4); otherwise classifies the stored error record by its kind, and on a nonzero class shuts the screens down, runs the class action (1 reset, 2 fatal screen, 3 retry) and clears the record.
 */
int func_021D9F04(char *ctx, void *a, void *b)
{
    u32_021D9F04 *rec = (u32_021D9F04 *)(ctx + 0x18);
    Res r = RES_NONE;

    if (func_0203CD98()) {
        if (func_0200FB24()) {
            func_0203D7B0(r);
            func_0203D7BC(r);
            func_02006210();
            if (func_02012E40((const u8 *)(((struct Obj08279 *)ctx)->f8))) {
                func_02012E08((char *)(((struct Obj08279 *)ctx)->f8));
                func_0200F7C0(0x29);
            }
        }
        switch (func_02157170(a, b)) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = RES_1;
            break;
        case 2:
            r = RES_2;
            break;
        case 3:
            r = RES_3;
            break;
        case 4:
            r = RES_4;
            break;
        }
        return r;
    }
    if (r == RES_NONE) {
        switch (rec[7]) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = func_021DCE60(rec[0]);
            break;
        case 2:
            r = func_021DCEE0(rec[1], rec[2], rec[3]);
            break;
        case 3:
        case 4:
            r = RES_NONE;
            break;
        case 5:
            r = func_021DCFDC(rec[6]);
            break;
        default:
            r = RES_NONE;
            break;
        }
        if (r != RES_NONE) {
            func_0203D7B0(0);
            func_0203D7BC(0);
            func_02006210();
            if (func_02012E40((const u8 *)(((struct Obj08279 *)ctx)->f8))) {
                func_02012E08((char *)(((struct Obj08279 *)ctx)->f8));
                func_0200F7C0(0x29);
            }
        }
        switch (r) {
        case RES_1:
            func_0203C968();
            func_0203CA04();
            func_0200F83C();
            func_0200FBA0();
            break;
        case RES_2:
            if (!func_0200FB24()) {
                func_0203C9AC(0, 0, 0, 0x3F7);
                func_0200FAAC();
            }
            func_0200FB38();
            break;
        case RES_3:
            func_0200FA84();
            break;
        }
        if (r != RES_NONE)
            func_021DCFFC(rec);
    }
    return r;
}

void func_021DA044(u8 *p) { ((struct Obj14332 *)p)->f12C=0; ((struct Obj14332 *)p)->f128=0; }

int func_021DA054(char *ctx)
{
    int result;
    switch (((struct Obj00629 *)ctx)->f128) {
    case 0:
        func_021DB3A4(ctx, -1, 2, *(unsigned long *)&((struct Obj00629 *)ctx)->f1464);
        ((struct Obj00629 *)ctx)->f128 = 1;
        break;
    case 1:
        result = func_021DB478(ctx);
        if (result == 1) {
            if (**(int * *)&((struct Obj00629 *)ctx)->f1464 != 0) ((struct Obj00629 *)ctx)->f128 = 4;
            else ((struct Obj00629 *)ctx)->f128 = 2;
        } else if (result == 2) return 2;
        break;
    case 2:
        func_021DBFA4(ctx);
        ((struct Obj00629 *)ctx)->f128 = 3;
        break;
    case 3:
        result = func_021DBFB4(ctx);
        if (result == 1) ((struct Obj00629 *)ctx)->f128 = 4;
        else if (result == 2) return 2;
        break;
    case 4: return 1;
    }
    return 0;
}


/*
 * Sets up a matchmaking attempt: closes any connection, publishes the eight match keys (player count, group, 1, four record words, version 0x20015), formats the filter string and picks the evaluation callback for the mode (1 asserts).
 */
void func_021DA0D4(char *obj, int mode, int extra, int group, int *rec)
{
    int count = mode;

    if (mode == 1)
        count += extra;
    if (!func_0203CD98())
        func_0200FA84();
    DWC_CloseAllConnectionsHard();
    func_021DA4B8(obj, 0, count);
    func_021DA4B8(obj, 1, group);
    func_021DA4B8(obj, 2, 1);
    func_021DA4B8(obj, 3, rec[0]);
    func_021DA4B8(obj, 5, rec[1]);
    func_021DA4B8(obj, 4, rec[2]);
    func_021DA4B8(obj, 6, rec[3]);
    func_021DA4B8(obj, 7, 0x20015);
    STD_TSPrintf(obj + 0x44, d_021E2EFC, count, group, 1);
    ((struct Obj05458 *)obj)->f40 = 0;
    ((struct Obj05458 *)obj)->f1A0 = 0;
    ((struct Obj05458 *)obj)->f1A4 = 0;
    MI_CpuFill8(obj + 0x138, 0, 0x18);
    switch (mode) {
    case 0:
        *(EvalFn *)&((struct Obj05458 *)obj)->f1218 = func_021DA4F8;
        break;
    case 1:
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
        break;
    case 2:
        *(EvalFn *)&((struct Obj05458 *)obj)->f1218 = func_021DA4E8;
        break;
    case 3:
        *(EvalFn *)&((struct Obj05458 *)obj)->f1218 = func_021DA4F0;
        break;
    default:
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
        break;
    }
}


/*
 * Matchmaking step (state at +0x40): 0 starts the search with the evaluation callback, then waits for the match, the peer handshake (with a 3600-tick timeout counted at +0x1a4) and the link check; returns 1 when done, 2 on a fatal error and 0 while still running.
 */
int func_021DA1E4(char *obj)
{
    switch (((struct Obj00839 *)obj)->f40) {
    case 0:
        if (func_0215580C(obj + 0x44, 2, ((struct Obj00839 *)obj)->f1218, obj)) {
            func_0203C304();
            func_02156BC4(0);
            ((struct Obj00839 *)obj)->f40 = 1;
        } else {
            func_0203C554(1);
            return 2;
        }
        break;
    case 1:
        ((struct Obj00839 *)obj)->f40 = 2;
        break;
    case 2:
        switch (func_0203C3EC()) {
        case 0:
            if ((u32_021DA1E4)(*(u32_021DA1E4 *)(func_0203CA98() + 0xc) - 0x3f0) > 1)
                break;
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        case 1:
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 3;
            func_0203D7B0(1);
            func_0203D7BC(1);
            break;
        default:
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        }
        break;
    case 3:
        if (func_02039338()) {
            if (func_02039ACC())
                ((struct Obj00839 *)obj)->f40 = 4;
            if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
                func_021DA384(obj);
                ((struct Obj00839 *)obj)->f40 = 7;
            }
        } else {
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 5;
        }
        break;
    case 4:
        func_02039C68((struct Link *)func_020399A8(), 0xf, 0x24);
        ((struct Obj00839 *)obj)->f1A4 = 0;
        ((struct Obj00839 *)obj)->f40 = 6;
        break;
    case 5:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (func_020399EC() && func_02039ACC()) {
            func_02039C68((struct Link *)func_020399A8(), 0xf, 0x24);
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 6;
        }
        break;
    case 6:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (func_02039CB4((struct Link *)func_020399A8(), 0xf, 0x24)) {
            ((struct Obj00839 *)obj)->f40 = 8;
        }
        break;
    case 7:
        if (func_021DA390(obj)) {
            if ((u32_021DA1E4)(*(u32_021DA1E4 *)(func_0203CA98() + 0xc) - 0x3f0) <= 1) {
                func_0203CA04();
                func_0203C968();
                func_0200FBA0();
                func_0203C554(1);
            }
            return 2;
        }
        break;
    case 8:
        func_0203D378();
        return 1;
    }
    return 0;
}


/*
 * Three-call init/reset sequence: 0x0203D7B0(0), 0x0203D7BC(0) and
 *     0x0203C554(1).
 */
void func_021DA36C(void)
{
    func_0203D7B0(0);
    func_0203D7BC(0);
    func_0203C554(1);
}


/*
 * Leaf: clears the word at +0x154.
 */
void func_021DA384(char *obj)
{
    ((struct Obj24329 *)obj)->f154 = 0;
}


/*
 * Link shutdown sequence stepped by the word at +0x154: sync 0x18, wait for the sync (600 frame timeout on +0x1a0), stop the two link services, wait 30 frames on +0x134, restart the parent service, then report done (1).
 */
int func_021DA390(char *obj)
{
    switch (((struct Obj02513 *)obj)->f154) {
    case 0:
        func_021D9ED4(obj, 0x18);
        ((struct Obj02513 *)obj)->f1A0 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 1:
        if (func_021D9EEC(obj) != 0)
            (((struct Obj02513 *)obj)->f154)++;
        else if ((((struct Obj02513 *)obj)->f1A0)++ > 600)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 2:
        func_0203D7B0(0);
        func_0203D7BC(0);
        ((struct Obj02513 *)obj)->f134 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 3:
        if ((((struct Obj02513 *)obj)->f134)++ > 30)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 4:
        func_0203C554(1);
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}


int func_021DA434(void)
{
    if (func_02156CD0() != 0)
        return func_0203D3A8(func_020399A8(), 0x2402, 4, (u32_021DA434)g_021E2C8C);
    return 1;
}


u32_021DA45C func_021DA45C(char *obj)
{
    u32_021DA45C v = ((struct Obj14333 *)obj)->f140;

    if (v != 0)
        ((struct Obj14333 *)obj)->f140 = 0;
    return v;
}

/*
 * stack: four date words (including weekday), three time words.
 */
void func_021DA470(unsigned char *dest)
{
    int date[4];
    int time[3];
    if (!func_0203CD98()) func_0200FA84();
    if (!func_02167ED8(date, time)) func_0200FA84();
    func_02082BCC(dest, 0, 6);
    dest[0] = date[0];
    dest[1] = date[1];
    dest[2] = date[2];
    dest[3] = time[0];
    dest[4] = time[1];
    dest[5] = time[2];
}
