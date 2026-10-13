/*
 * function: func_021BC430
 * address:  0x021BC430
 * packet:   pkt_ov088_021BC430
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   CONFIG_GetBattleFlag  0x02008448  thumb
 *   func_0200C31C  0x0200C31C  thumb
 *   SAVE_CONTROL_Reload  0x020070C8  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_ApplyAppliedFlag  0x02008414  thumb
 *   func_0200890C  0x0200890C  thumb
 *   GAMESYSTEM_SetupInitWork  0x02011EEC  thumb
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *   func_0200C324  0x0200C324  thumb
 *   func_020315D4  0x020315D4  arm
 *   d_0209DF9C     0x0209DF9C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct Rec12 {
    u32 a, b, c;
} Rec12;

typedef struct S1C {
    u16 f0;
    u16 pad;
    Rec12 rec;
    u32 x, y;
    s16 f18;
    s16 f1a;
} S1C;

struct Blk34;
struct Flags02008414;
struct Flags02008450;
struct Sub02007084Ctrl;
struct Sub02008700Obj;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern unsigned int CONFIG_GetBattleFlag(int a0);
extern u8 func_0200C31C(struct Blk34 *p);
extern int SAVE_CONTROL_Reload(char *self);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 CONFIG_ApplyAppliedFlag(const struct Flags02008414 *p);
struct Sub02008828Rec;
extern void func_0200890C(void *sys, struct Sub02008828Rec *dest);
extern void *GAMESYSTEM_SetupInitWork(u32, u16, Rec12 *, int);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern void CONFIG_SetBattleFlag(struct Flags02008450 *p, int on);
extern void func_0200C324(struct Blk34 *p, u8 v);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern char d_0209DF9C[];

int func_021BC430(int a, int b, int c, u32 *q)
{
    S1C s;
    void *r;
    u32 t;
    u8 h;

    r = func_020070A4();
    t = CONFIG_GetBattleFlag((int)((void *)q[1]));
    h = func_0200C31C((void *)q[3]);
    SAVE_CONTROL_Reload(r);
    CONFIG_ApplyAppliedFlag((const struct Flags02008414 *)func_0200873C(r));
    func_0200890C(r, (struct Sub02008828Rec *)(&s));
    PROCSYS_ReplaceGlobal(-1, (u32)d_0209DF9C, (u32)GAMESYSTEM_SetupInitWork(1, s.f0, &s.rec, s.f18));
    CONFIG_SetBattleFlag((void *)q[1], t);
    func_0200C324((void *)q[3], h);
    func_020315D4((struct S020315D4 *)a);
    return 1;
}
