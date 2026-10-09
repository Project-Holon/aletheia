/*
 * file:     btl_server_p102.c
 * unit:     yes
 * function: func_021CA5CC, func_021CA6C4, func_021CA6FC, func_021CA738, func_021CA748, func_021CA7C4, func_021CA7D4, func_021CA7F4
 * address:  0x021CA5CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021C5418 0x021C5418 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021C6F34 0x021C6F34 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C70E4 0x021C70E4 thumb ov093
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021D66D8  0x021D66D8  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021CB214 0x021CB214 thumb ov093
 *   func_021CA8C8 0x021CA8C8 thumb ov093
 *   func_021CAA58 0x021CAA58 thumb ov093
 *   func_021CACF4 0x021CACF4 thumb ov093
 *   func_021CA8F8 0x021CA8F8 thumb ov093
 *   func_021CA8D8 0x021CA8D8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CA8E8 0x021CA8E8 thumb ov093
 *   func_021CAFD8 0x021CAFD8 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj18348.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09976.h"

struct Unk021D62A8;
struct UtilWork;
struct Slot;
struct Msg;
struct R5;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Cmd { u32 a:8; u32 id:5; u32 b:19; };

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

struct Q {
    u32 lo : 23;
    u32 f : 1;
    u32 hi : 8;
    u8 pad4[0];
};

typedef struct {
    u8 unk0[0x4A8];
    u8 *state;          /* 0x4A8 */
} BattleCtx_021CA7C4;

typedef struct {
    u8 unk0[5];
    u8 flag : 1;
    u8 unk5 : 7;
} BattleState;

typedef struct {
    u8 unk0[0x4A8];
    BattleState *state; /* 0x4A8 */
} BattleCtx_021CA7D4;

struct Flags { u32 a:1; u32 b:31; };

extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021C5418(u8 *, u8 *, int);
extern u8 func_021D69AC(u8 *, int);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_021C6F34(u8 *, u8 *, int);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021CD64C(void *, u8, ...);
extern int func_021D5B68(void *);
extern int func_021C99A0(void *, const struct Msg *);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C70E4(u8 *, int, int, int, int, u32);
extern int func_021D6D54(struct R5 *p);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021D66D8(void *m, int v);
extern void func_021C5A34(u8 *p, u8 *a);
extern u32 func_021B8588(void **p);
extern u8 func_021CB214(u8 *p, u8 *a, u8 *b);
extern void func_021CA8C8(void *);
extern int func_021CAA58(u8 *p, u8 *a, u16 move, u8 *q, int id, void *out);
extern int func_021CACF4(u8 *p, u8 *a, u16 move, u8 *q, long id, void *out);
extern int func_021CA8F8(u8 *p, u8 *a, int unused, u8 *q, int id, void *out);
extern u8 *func_021CA8D8(void *, int);
extern u8 func_021D5440(u8 *p);
extern u8 func_021CA8E8(void *, u8);
extern int func_021CAFD8(u8 *, u32, u8 *, const u8 *, u16, void *);
int func_021CA5CC(const u8 *p, const struct Cmd *q);
int func_021CA6C4(u8 *p, const u8 *q);
int func_021CA6FC(u8 *p, const u8 *q);
int func_021CA738(u8 *p);
int func_021CA748(u8 *p, const struct Q *q);
u8 func_021CA7C4(BattleCtx_021CA7C4 *s, u8 *cmd);
u8 func_021CA7D4(BattleCtx_021CA7D4 *s, void *cmd);
int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out);


/*
 * lever: C7F68 returns its normalized u8 j, and u8 n restores the count reload.
 */
int func_021CA5CC(const u8 *p, const struct Cmd *q)
{
    u8 buf[8];
    u8 n;
    u8 i;
    u8 *a;
    int changed;
    u8 t;
    n = func_021C7F68((int *)p, (u16)(func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, (u8)q->id) | 0x800), buf);
    i = 0;
    if (i >= n) goto done;
loop:
    {
        a = (u8 *)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, buf[i]);
        changed = 0;
        if (func_021D5BDC((struct UtilWork *)a, 3)) {
            func_021C5418((u8 *)p, a, 3);
            t = func_021D69AC(a, 4);
            if (!(t && (t = (u8)(t - 1)) < 24)) t = 31;
            if (t != 31) func_0203EFC8(p, a, 1);
            changed = 1;
        }
        if (func_021C6F34((u8 *)p, a, 1)) changed = 1;
        if (func_021D62C4((struct Unk021D62A8 *)a, 30)) {
            func_021C5620((u8 *)p, a, 30, 0);
            changed = 1;
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 32)) {
            func_021C5620((u8 *)p, a, 32, 0);
            changed = 1;
        }
        if (changed) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x43b, buf[i], 0xffff0000);
    }
    i++;
    if (i < n) goto loop;
done:
    return 1;
}


int func_021CA6C4(u8 *p, const u8 *q)
{
    u8 *m = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    if (!func_021D5B68(m) && func_021C5418(p, m, *(const int *)(q + 8))) {
        func_021C99A0(p, (const struct Msg *)(q + 12));
        return 1;
    }
    return 0;
}


int func_021CA6FC(u8 *p, const u8 *q)
{
    if (q[11]) func_021CD4B0(((struct Obj00003 *)p)->fC, 86, 0);
    func_021C70E4(p, *(const u16 *)(q + 4), q[6], q[7], q[10], *(const u16 *)(q + 8));
    func_021C99A0(p, (const struct Msg *)(q + 12));
    return 1;
}



/* 021CA738  3-arg call on field 0xc, then returns 1 */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0xc]; movs r1, #0x56; movs r2, #0; bl func_021CD4B0; movs r0, #1; pop {r3, pc}.
 */
int func_021CA738(u8 *p)
{
    func_021CD4B0((void *)(((struct Obj18348 *)p)->fC), 0x56, 0);
    return 1;
}





/*
 * The listing extent (172 bytes) runs on into func_021CA7C4 and func_021CA7D4,
 * which are filed separately.
 */
int func_021CA748(u8 *p, const struct Q *q)
{
    u8 t;
    void *m = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, ((u8 *)q)[4]);
    if (!func_021D5B68(m) && !func_021D6D54(m)) {
        t = func_021D59B4(m, 0x13);
        if (t != ((u8 *)q)[5]) {
            if (q->f) func_021C5A1C(p, m);
            func_021D66D8(m, ((u8 *)q)[5]);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x4f, ((u8 *)q)[4], ((u8 *)q)[5]);
            func_021C99A0(p, (const struct Msg *)((u8 *)q + 8));
            if (q->f) func_021C5A34(p, m);
            return 1;
        }
    }
    return 0;
}






/* command handler: copy the argument byte of the command into the state block */
u8 func_021CA7C4(BattleCtx_021CA7C4 *s, u8 *cmd)
{
    s->state[4] = cmd[4];
    return 1;
}






/* command handler: latch the state flag once */
u8 func_021CA7D4(BattleCtx_021CA7D4 *s, void *cmd)
{
    BattleState *st = s->state;

    if (!st->flag)
        st->flag = 1;
    return 1;
}



int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out)
{
    u32 mode = func_021B8588(((struct Obj09976 *)p)->f4);
    u32 id = 31;
    if (!((struct Flags *)(q + 16))->a) id = func_021CB214(p, a, (u8 *)q);
    func_021CA8C8(out);
    p[0x77f] = 6;
    switch (mode) {
    case 0: default:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    case 1:
        id = func_021CAA58(p, a, b, (u8 *)q, id, out);
        break;
    case 2:
        id = func_021CACF4(p, a, b, (u8 *)q, id, out);
        break;
    case 3:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    }
    if (id == 1) {
        u8 *m = func_021CA8D8(out, 0);
        if (m) p[0x77f] = func_021CA8E8(p + 0x1ab8, func_021D5440(m));
        if (!func_021CAFD8(p, mode, a, q, b, out)) id = 0;
    }
    return id;
}
