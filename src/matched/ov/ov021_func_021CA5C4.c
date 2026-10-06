/*
 * function: func_021CA5C4
 * address:  0x021CA5C4
 * packet:   pkt_ov021_021CA5C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command dispatcher: reads a command id and two arguments from the
 * script, then runs one of 137 cases on the work area, the save blocks
 * 0x39/0x3A/0x3B and the result slot. Returns 1 when the case started a task
 * the script must wait for.  One 4376-byte function (0x021CA5C4..0x021CB6DC,
 * see layout/far_branch_functions.txt); every concrete byte matches.
 *
 * Shape notes (2026-10-01), all measured:
 * - The switch tree only reproduces with one more empty case label inside the
 *   0..113 jump table (any of 9, 10, 46..99, 102; its entry is the break, so
 *   the value is invisible).  Without it the top group becomes one 359..416
 *   table instead of compares for 358/359 and a 400..416 table.
 * - cmd, p1, p2 and s28 are u16 (u16 returns): u32 makes the tree unsigned,
 *   and u32 p1 truncates before each bitfield insert.
 * - Case 334's counter is an enum local: an int counter folds `i + n + 1` and
 *   the loop's entry guard.
 * - Case 351 writes the result in each arm (cross-jumped tail leaves the
 *   `b` to the next instruction); case 404 sets ret after the call (it is
 *   still scheduled into the argument stores); case 45/322 read the table
 *   row through a pointer and pass its three words as separate arguments.
 *
 * Witnesses (closed 2026-10-02, gA2): func_021542C0 (ov007), func_02167AB0
 *   and func_02167CF4 (ov010) were seeded in layout/function_starts.txt and
 *   filed EXACT; data_021BB474 (ov214) and data_021BB6A4 (ov100) are
 *   hand-declared proc tables in layout/data_objects.txt, and
 *   attest_xwin_loaded() no longer counts ov021's own start at 0x021BB474
 *   as a third-overlay contest.
 *
 * symbols:
 *   data_021DAD24  0x021DAD24  data
 *   data_021DAD36  0x021DAD36  data
 *   data_021DAD70  0x021DAD70  data
 *   data_021DAD88  0x021DAD88  data
 *   data_021DADAC  0x021DADAC  data
 *   data_021DAE50  0x021DAE50  data
 *   func_020071CC  0x020071CC  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0200B424  0x0200B424  thumb
 *   func_0200B5CC  0x0200B5CC  thumb
 *   func_0200BA38  0x0200BA38  thumb
 *   func_0200BA58  0x0200BA58  thumb
 *   func_0200BA68  0x0200BA68  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0200D85C  0x0200D85C  thumb
 *   func_0200D87C  0x0200D87C  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D9E8  0x0200D9E8  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DA28  0x0200DA28  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 *   func_0200DB30  0x0200DB30  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200DE5C  0x0200DE5C  thumb
 *   func_0200DE64  0x0200DE64  thumb
 *   func_0200DE94  0x0200DE94  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0200DF94  0x0200DF94  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_02011330  0x02011330  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02012134  0x02012134  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0201289C  0x0201289C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   ov007_id       0x00000007  data  a1
 *   ov100_id       0x00000064  data  a1
 *   ov214_id       0x000000D6  data  a1
 *   func_0201296C  0x0201296C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_020130B4  0x020130B4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02014314  0x02014314  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_02014808  0x02014808  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   func_0201A354  0x0201A354  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_0202C0D0  0x0202C0D0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02039338  0x02039338  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087BCC  0x02087BCC  arm
 *   func_021542C0  0x021542C0  thumb  ov007
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02167AB0  0x02167AB0  thumb  ov010
 *   func_02167B00  0x02167B00  thumb  ov010
 *   func_02167B24  0x02167B24  thumb  ov010
 *   func_02167BFC  0x02167BFC  thumb  ov010
 *   func_02167CF4  0x02167CF4  thumb  ov010
 *   func_0216C538  0x0216C538  thumb  ov010
 *   func_0216C640  0x0216C640  thumb  ov010
 *   func_0216C6E8  0x0216C6E8  thumb  ov010
 *   func_0216C860  0x0216C860  thumb  ov010
 *   func_0216CB48  0x0216CB48  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A30B0  0x021A30B0  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   data_021BB474  0x021BB474  data  ov214
 *   data_021BB6A4  0x021BB6A4  data  ov100
 *   func_021C9B78  0x021C9B78  thumb  ov021
 *   func_021C9BCC  0x021C9BCC  thumb  ov021
 *   func_021C9C54  0x021C9C54  thumb  ov021
 *   func_021C9CAC  0x021C9CAC  thumb  ov021
 *   func_021C9D30  0x021C9D30  thumb  ov021
 *   func_021C9D70  0x021C9D70  thumb  ov021
 *   func_021C9DB0  0x021C9DB0  thumb  ov021
 *   func_021C9E8C  0x021C9E8C  thumb  ov021
 *   func_021C9F44  0x021C9F44  thumb  ov021
 *   func_021C9FD0  0x021C9FD0  thumb  ov021
 *   func_021C9FFC  0x021C9FFC  thumb  ov021
 *   func_021CA048  0x021CA048  thumb  ov021
 *   func_021CA05C  0x021CA05C  thumb  ov021
 *   func_021CA150  0x021CA150  thumb  ov021
 *   func_021CA164  0x021CA164  thumb  ov021
 *   func_021CA1E4  0x021CA1E4  thumb  ov021
 *   func_021CA234  0x021CA234  thumb  ov021
 *   func_021CA23C  0x021CA23C  thumb  ov021
 *   func_021CA250  0x021CA250  thumb  ov021
 *   func_021CA270  0x021CA270  thumb  ov021
 *   func_021CA338  0x021CA338  thumb  ov021
 *   func_021CB6DC  0x021CB6DC  thumb  ov021
 *   func_021CB700  0x021CB700  thumb  ov021
 *   func_021CB754  0x021CB754  thumb  ov021
 *   func_021CB7E8  0x021CB7E8  thumb  ov021
 *   func_021CB86C  0x021CB86C  thumb  ov021
 *   func_021CB914  0x021CB914  thumb  ov021
 *   func_021CB9BC  0x021CB9BC  thumb  ov021
 *   func_021CB9E4  0x021CB9E4  thumb  ov021
 *   func_021CBBA0  0x021CBBA0  thumb  ov021
 *   func_021CBBAC  0x021CBBAC  thumb  ov021
 *   func_021CBBD0  0x021CBBD0  thumb  ov021
 *   func_021CBC14  0x021CBC14  thumb  ov021
 *   func_021CBC94  0x021CBC94  thumb  ov021
 *   func_021CBCC4  0x021CBCC4  thumb  ov021
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021D024C  0x021D024C  thumb  ov021
 *   func_021D028C  0x021D028C  thumb  ov021
 *   func_021EEE78  0x021EEE78  thumb  ov188
 *   func_021F37C0  0x021F37C0  thumb  ov052
 *   func_021F380C  0x021F380C  thumb  ov052
 *   func_021F388C  0x021F388C  thumb  ov052
 */
#include "../include/Obj00335.h"
#include "../include/Obj02400.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

#define NULL ((void *)0)

typedef struct {
    u16 b0  : 1;
    u16 f1  : 2;
    u16 f3  : 2;
    u16 f5  : 3;
    u16 b8  : 1;
    u16 b9  : 1;
    u16 f10 : 2;
    u16 b12 : 1;
    u16 f13 : 3;
} Flags;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Trip;

typedef struct {
    u32 w[7];
} Rec1C;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec;

typedef struct {
    u32 val;
    u16 *dst;
} Wait;

typedef enum {
    SLOT_0
} Slot;

#define FLAGS(w) ((Flags *)((w) + 0xc))

typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk1AC;
struct Blk3C;
struct Buf3FC;
struct Ctx;
struct L0200ED54;
struct Pair;
struct RecSlot;
struct SaveBlock;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_02158F54(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012ED8(struct Big *p);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Desc;
struct Obj;
struct Rec1C;
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern u16 func_02159B10(void *a, u32 b);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern void func_0215897C(void *h, void *task);

extern int func_021CBCC4(void *a);
extern void func_02087BCC(u32 a);
extern void func_0200D85C(struct Blk3C *p);
extern u32 func_0200D87C(struct Blk3C *p);
extern void *func_02188CB4(unsigned char *p);
extern u16 func_021A3050(u8 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *a, struct VecFx32 *t);
extern u16 func_02188C9C(u8 *p);
extern void func_02014184(Rec1C *out, u32 id, s16 n, u32 a, u32 b, u32 c);
extern void func_0201289C(struct BigObj *p, const struct Rec1C *src);
extern void func_02014314(char *a0, int a1);
extern void func_0201433C(char *a0, int a1);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern u32 func_021C9D30(u32 a);
extern u32 func_021A30B0(void *a);
extern u16 func_021A3190(int i, int j);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *a, u32 id);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern u16 func_0200DA54(struct Blk3C *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern void func_021F37C0(void *a, int b, int c);
extern int func_021F380C(int a);
extern void func_021D024C(void *o, u32 v);
extern void func_021D028C(void *o, u32 v);
struct Actor;
extern void func_0216D88C(const struct Actor *o, struct VecFx32 *v);
extern u16 func_0216D5F8(void *p);
extern void func_0216E014(void *a, int *p, int b);
extern void func_0216DB4C(void *o, u32 v);
extern u32 func_021CBBA0(void *o);
extern int func_021CA164(void *a, int unused, int mode);
extern u16 func_0200DB80(struct Blk1AC *p, u32 i);
extern void *func_020127A4(struct SaveBlock *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int func_021A31A4(int i, int v);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216DAF8(void *o);
extern int func_0216D63C(char *a0, int a1);
extern void *func_0216CB48(u32 x, u32 v, u32 id);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u32 func_021CBBAC(u8 *w, u32 v);
extern void func_021CBBD0(u8 *w, u32 v, u16 *a, u16 *b, u16 *c);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern u32 func_0200DF94(struct Buf3FC *b);
extern void func_020307B0(void *p);
extern void *func_021CB9BC(void *a, u32 owner, u32 result, u32 arg);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int func_021542C0(int x, struct Pair *p);
extern u8 func_0200DE94(struct RecSlot *p);
extern u8 func_0200DE5C(struct RecSlot *p);
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u8 func_0200DE64(struct RecSlot *p);
extern void *func_0216C860(void *a);
extern int func_0200DF40(struct RecSlot *p);
extern u8 func_0200DF4C(struct RecSlot *p);
struct PartyCaller;
extern void *func_0216C538(struct PartyCaller *c, void *sys, u8 useOwn);
extern u32 func_021C9F44(u8 *w, u32 x);
extern int func_021C9FD0(u8 *w);
extern void func_021C9D70(u32 x, u8 *w);
extern void func_021C9FFC(u8 *w, u32 x);
extern void func_021C9BCC(u8 *w);
extern void func_021CA05C(u8 *w);
extern u32 func_021CA150(u8 *w, u32 i);
extern void *func_0216C640(u8 *w, u32 x, void *s);
extern u32 func_021C9DB0(u8 *w);
extern void func_021C9E8C(u8 *w);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir);
extern void func_021C9CAC(u8 *w);
extern void func_021C9C54(u8 *w, u32 x);
extern void func_021C9B78(u8 *w);
extern void func_021CB9E4(u8 *p, void *a1, void *a2, void *a3);
extern int func_021CA048(u32 a, u32 b);
extern u32 func_02012134(u32 x);
extern u32 func_0202B578(u32 *p);
extern void func_0202C0D0(u8 *p, u32 a);
extern void func_021CA338(u8 *w, u8 alt);
extern int func_021CBC94(u32 kind);
extern void *func_0201A354(int a, int b);
extern void *func_0200BAF4(int a0, int a1);
extern void *func_02012934(const struct BigObj *p);
extern int func_02019ED4(void *ctx, void *q);
extern void func_021CA1E4(u8 *w);
extern u32 func_021CA270(u16 kind);
extern u32 func_0200B5CC(void *a, u32 heap, u32 *dp, u32 id);
extern void func_0200BA58(void);
extern void func_021EEE78(void *p);
extern void func_0200BA68(void);
extern void func_020113D0(char *p, int val);
extern void func_0200B424(void);
extern int func_020130B4(int a0);
extern u16 func_021CA234(u8 *w);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0200DA14(struct Blk3C *p);
extern void func_0200DB1C(struct Blk1AC *p, u32 i);
extern void func_021F388C(int a);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_0200D9E8(struct Blk3C *p, s32 a, s32 b, s32 c);
extern void func_0200DA28(struct Blk3C *p);
extern void func_021CA23C(u8 *w);
extern void func_0200DB30(struct Blk1AC *p, u32 i);
extern int func_021CA250(u32 a);
extern void func_02167B00(u32 a);
extern void func_02167AB0(void *p);
extern void *func_021CB914(void *a, u32 owner);
extern void func_02167B24(u32 v);
extern u32 func_021CD48C(u32 a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_02167BFC(struct Obj *o, u32 cmd, u32 arg);
extern void func_02167CF4(u8 *w, u8 v);
extern u16 func_02039338(void);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void *func_0200ED48(void *p);
extern void func_0200FB38(void);
extern void func_02012124(struct Ctx *p, u32 v);
extern u32 func_0200FB24(void);
extern u32 func_0200BA38(u32 v);

extern int func_021CB700(u32 unused, u32 a);
extern int func_021CB754(u32 unused, u32 a);
extern int func_021CB7E8(u32 unused, u32 a);
extern int func_021CB6DC(void *task, void *p);
extern int func_021CB86C(u32 unused, u32 a);
extern int func_021CBC14(u32 unused, u32 a);
extern u8 data_021BB474[];
extern u8 data_021BB6A4[];
extern char ov007_id[];
extern char ov100_id[];
extern char ov214_id[];

extern const u16 data_021DAD36[];
extern const u32 data_021DAD88[];
extern const Trip data_021DAD70[];
extern const Trip data_021DAE50[];
extern const u32 data_021DADAC[];
extern const u16 data_021DAD24[];

int func_021CA5C4(void *a, u32 b)
{
    Trip t;
    Rec1C r4;
    Vec v;
    Rec1C r45;
    Rec1C r322;
    Wait st;
    u32 out;
    u16 a40, b40, c40;
    u16 a41, b41, c41;
    u16 a42, b42, c42;
    u8 t108;
    u8 t324;
    int ret;
    void *h;
    u32 x;
    u32 s4c;
    u32 s48;
    u32 s44;
    u8 *w;
    u32 s40;
    u32 s3c;
    u32 s38;
    u32 s34;
    void *s30;
    u16 p1;
    u16 p2;
    u16 s28;
    u16 *dst;
    u16 cmd;

    ret = 0;
    h = func_0215A5F4((void *)b);
    func_02158F58((int)h);
    x = (u32)func_02158F54(h);
    s4c = (u32)func_020120F4((const struct Ctx *)x);
    s48 = (u32)func_02012EBC((struct Big *)s4c);
    s44 = func_0201296C((const struct BigObj *)s4c);
    w = func_02012ED8((struct Big *)s4c);
    s40 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x39);
    s3c = func_0200D884((struct Blk3C *)s40, 0, 0);
    s38 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x3a);
    s34 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x3b);
    s30 = func_0201210C((void *)x);
    cmd = func_02011330(a);
    p1 = func_02159B10(a, b);
    p2 = func_02159B10(a, b);
    s28 = func_02011330(a);
    dst = func_02158FE0(h, (void *)s4c, s28);

    if (w == NULL && cmd >= 300)
        return ret;

    switch (cmd) {
    case 0:
        *dst = func_021CBCC4(s30);
        break;
    case 1:
        func_02087BCC(0);
        break;
    case 2:
        func_0200D85C((struct Blk3C *)s40);
        break;
    case 3:
        *dst = func_0200D87C((struct Blk3C *)s40);
        break;
    case 4: {
        void *o = func_02188CB4((void *)s30);
        u32 k = func_021A3050(o);
        int n;
        func_021A3038(o, (struct VecFx32 *)&t);
        switch (k) {
        case 0:
            n = 1;
            break;
        case 1:
            n = 2;
            break;
        case 2:
            n = 3;
            break;
        case 3:
            n = 4;
            break;
        default:
            n = 0;
            break;
        }
        func_02014184(&r4, func_02188C9C(s30), n, t.a, t.b, t.c);
        func_0201289C((struct BigObj *)s4c, (const struct Rec1C *)(&r4));
        func_02014314((char *)s44, 0x966);
        break;
    }
    case 5:
        func_0201433C((char *)s44, 0x966);
        break;
    case 6:
        *dst = func_0200DAC4((struct Blk1AC *)s38, p1);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 7:
        *dst = func_021C9D30(x);
        break;
    case 12:
        *dst = func_021A3190(func_021A30B0(func_02188CB4((void *)s30)), 0);
        break;
    case 13: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216DAC8(o, p2);
        break;
    }
    case 8:
        *dst = func_0200DA54((struct Blk3C *)s40) + 1;
        break;
    case 11:
        *dst = func_0200DA54((struct Blk3C *)(((struct Obj00335 *)w)->f70));
        *dst += 1;
        break;
    case 14:
        if (data_021DAD36[p1] == 11)
            *dst = 1;
        else
            *dst = func_0200DBA0((struct Blk1AC *)s38, data_021DAD36[p1], 0);
        break;
    case 15:
        if (data_021DAD36[p1] != 11)
            func_0200DBA0((struct Blk1AC *)s38, data_021DAD36[p1], 1);
        break;
    case 16:
        *dst = func_0200DBA0((struct Blk1AC *)s38, 10, 0);
        break;
    case 17:
        func_0200DBA0((struct Blk1AC *)s38, 10, 1);
        break;
    case 18:
        func_021F37C0(s30, data_021DAD88[p1], (int)(&data_021DAD70[p2]));
        break;
    case 19:
        func_021D024C((void *)func_021F380C((int)s30), p1);
        break;
    case 20:
        func_021D028C((void *)func_021F380C((int)s30), p1);
        break;
    case 21:
        *dst = func_0200D884((struct Blk3C *)s40, 0, 0);
        break;
    case 22:
        *dst = 0;
        switch (p1) {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            *dst = 1;
            break;
        }
        break;
    case 23: {
        u32 y = p2 << 16;
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0) {
            func_0216D88C(o, (struct VecFx32 *)&v);
            v.y = y;
            func_0216E014(o, (int *)(&v), func_0216D5F8(o));
            func_0216DB4C(o, 1);
        }
        break;
    }
    case 24: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216DB4C(o, 0);
        break;
    }
    case 25: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        *dst = 0;
        if (o != 0)
            *dst = 1;
        break;
    }
    case 26: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        *dst = 0;
        if (o != 0)
            *dst = func_021CBBA0(o);
        break;
    }
    case 27:
        *dst = func_021CA164((void *)s38, x, 0);
        if ((s16)*dst <= 0)
            *dst = 1;
        break;
    case 28:
        *dst = func_021CA164((void *)s38, x, 3);
        break;
    case 29:
        *dst = func_021CA164((void *)s38, x, 4);
        break;
    case 30:
        *dst = func_0200DB80((struct Blk1AC *)s38, p1);
        break;
    case 31:
        *dst = func_021A31A4(func_02008550((const struct Sub0200852CObj *)((u8 *)func_020127A4((struct SaveBlock *)s4c) + 0x20)) == 0 ? 1 : 0, 0);
        break;
    case 32: {
        u32 o = (u32)func_0200BAC8((void *)s48);
        *dst = 0;
        if (func_0200BBA8((void *)o) == 1)
            *dst = 1;
        break;
    }
    case 33:
        *dst = 0;
        break;
    case 34:
        func_021F37C0(s30, 7, (int)data_021DAD70);
        break;
    case 35: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216D5E0((int)o, p2);
        break;
    }
    case 36: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216DAF8(o);
        break;
    }
    case 37:
        func_0215897C(h, func_0216CB48(x, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), p1));
        ret = 1;
        break;
    case 38:
        *dst = func_0200DB44((struct Blk1AC *)s38, p1);
        break;
    case 39: {
        u32 o = func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0);
        *dst = 0;
        if (func_021CBBAC(w, o) == 1)
            *dst = 1;
        break;
    }
    case 40:
        func_021CBBD0(w, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), &a40, &b40, &c40);
        *dst = a40;
        break;
    case 41:
        func_021CBBD0(w, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), &a41, &b41, &c41);
        *dst = b41;
        break;
    case 42:
        func_021CBBD0(w, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), &a42, &b42, &c42);
        *dst = c42;
        break;
    case 43: {
        void *l = func_0200DF58((struct RecSlot *)s34, 4);
        *dst = func_0200DF94(l);
        func_020307B0(l);
        break;
    }
    case 44: {
        u32 f = 0;
        if (p1 == 1)
            f = 1;
        func_0215897C(h, func_021CB9BC((void *)x, b, (u32)dst, f));
        ret = 1;
        break;
    }
    case 45: {
        u16 i = func_021CBCC4(s30);
        const Trip *e = &data_021DAE50[i];
        func_02014184(&r45, data_021DADAC[i], 4, e->a, e->b, e->c);
        func_0201289C((struct BigObj *)s4c, (const struct Rec1C *)(&r45));
        func_02014314((char *)s44, 0x966);
        break;
    }
    case 100:
        if (p1 == 0)
            func_0200DBA0((struct Blk1AC *)s38, 1, 2);
        else
            func_0200DBA0((struct Blk1AC *)s38, 1, 1);
        break;
    case 101:
        *dst = func_0200DBA0((struct Blk1AC *)s38, 1, 0);
        break;
    case 103:
        st.val = 0;
        st.dst = dst;
        func_0215897C(h, func_020124AC((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&st)));
        ret = 1;
        break;
    case 104:
        ret = 1;
        st.val = 1;
        st.dst = dst;
        func_0215897C(h, func_020124AC((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&st)));
        break;
    case 105:
        st.val = 2;
        st.dst = dst;
        func_0215897C(h, func_020124AC((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&st)));
        ret = 1;
        break;
    case 106:
        *dst = func_0200DE94((struct RecSlot *)s34);
        break;
    case 107:
        *dst = func_0200DE5C((struct RecSlot *)s34);
        break;
    case 108:
        t108 = p1;
        func_0200D914((struct Blk3C *)s40, 11, &t108);
        break;
    case 109:
        *dst = func_0200D884((struct Blk3C *)s40, 11, 0);
        break;
    case 110:
        *dst = func_0200DE64((struct RecSlot *)s34);
        break;
    case 111:
        func_0215897C(h, func_0216C860((void *)x));
        ret = 1;
        break;
    case 112:
        *dst = func_0200DF40((struct RecSlot *)s34);
        break;
    case 113:
        *dst = func_0200DF4C((struct RecSlot *)s34);
        break;
    case 200:
        *dst = 0;
        break;
    case 102:
    case 201:
    case 202:
        break;
    case 203:
        *dst = 0;
        break;
    case 322:
        if (s3c < 9) {
            const Trip *e = &data_021DAE50[s3c];
            func_02014184(&r322, data_021DADAC[s3c], 4, e->a, e->b, e->c);
            func_0201289C((struct BigObj *)s4c, (const struct Rec1C *)(&r322));
            func_02014314((char *)s44, 0x966);
        }
        break;
    case 300:
        {
            u8 v = func_0200D884((struct Blk3C *)s40, 10, 0);
            func_0215897C(h, func_0216C538((struct PartyCaller *)w, (void *)x, v));
        }
        ret = 1;
        break;
    case 301:
        *dst = func_021C9F44(w, x);
        break;
    case 302:
        *dst = 0;
        break;
    case 303:
        if (func_021C9FD0(w) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 304:
        func_021C9D70(x, w);
        break;
    case 305:
        func_021C9FFC(w, x);
        break;
    case 306:
        func_021C9BCC(w);
        break;
    case 307:
        func_021CA05C(w);
        break;
    case 308:
        *dst = func_021CA150(w, p1);
        break;
    case 309:
        func_0215897C(h, func_0216C640(w, x, s30));
        ret = 1;
        break;
    case 310:
        *dst = w[9];
        break;
    case 311:
        FLAGS(w)->f1 = p1;
        break;
    case 312:
        *dst = FLAGS(w)->f1;
        break;
    case 313:
        *dst = func_021C9DB0(w);
        break;
    case 314:
        FLAGS(w)->f5 = p1;
        break;
    case 315:
        *dst = FLAGS(w)->f5;
        break;
    case 316:
        func_021C9E8C(w);
        break;
    case 317:
        *dst = *(w + p1 + 0x1e);
        break;
    case 319:
        w[0x724] = 0;
        func_02082BCC(w + 0x6ae, 0, 0x46);
        break;
    case 320:
        func_0215897C(h, func_0216C6E8(w, (void *)x, p1, p2, 5));
        ret = 1;
        break;
    case 321:
        func_021C9CAC(w);
        break;
    case 323:
        func_021C9C54(w, x);
        break;
    case 324:
        t324 = p1;
        func_0200D914((struct Blk3C *)s40, 10, &t324);
        break;
    case 325:
        func_021C9B78(w);
        break;
    case 326:
        if (s3c - 5 <= 3)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 329:
        func_021CB9E4(w, (void *)s4c, func_02188C7C((void *)s30), s30);
        break;
    case 330:
        FLAGS(w)->b8 = p1;
        break;
    case 331:
        *dst = FLAGS(w)->b8;
        break;
    case 332: {
        u8 *e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e == NULL)
            *dst = 0;
        else if (((struct Obj02400 *)e)->f8C == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    }
    case 333:
        func_021CA048((u32)w, x);
        break;
    case 334: {
        Slot i = 0;
        u16 n = func_0200DA54((struct Blk3C *)s40);
        if (n != 0) {
            void *p = (void *)func_0202B578((u32 *)func_02012134(x));
            n = i + n + 1;
            for (; i < n; i++) {
                if (i < 9 && i != 0)
                    func_0202C0D0(p, i);
            }
        }
        break;
    }
    case 335:
        func_021CA338(w, func_02008550((const struct Sub0200852CObj *)((u8 *)func_020127A4((struct SaveBlock *)s4c) + 0x20)) == 0 ? 1 : 0);
        break;
    case 336:
        *dst = *(u16 *)(w + p1 * 2 + 0x22);
        break;
    case 337:
        FLAGS(w)->b9 = p1;
        break;
    case 338:
        *dst = FLAGS(w)->b9;
        break;
    case 339: {
        void *p4 = NULL;
        u32 mode;
        void *rules;
        void *party;
        u32 res;
        *dst = 0;
        mode = func_0200D884((struct Blk3C *)s40, 10, 0);
        rules = func_0201A354(func_021CBC94(s3c), 4);
        if (mode == 1) {
            p4 = func_0200BAF4((u32)func_0200BAC8((void *)s48), 4);
            party = p4;
        } else {
            party = func_02012934((void *)s4c);
        }
        res = func_02019ED4(rules, party);
        func_020307B0(rules);
        if (p4 != NULL)
            func_020307B0(p4);
        if (res <= 1)
            *dst = 1;
        break;
    }
    case 340:
        func_021CA1E4(w);
        break;
    case 341:
        *dst = func_021CBC94(s3c);
        break;
    case 342:
        *dst = func_021CA270(s3c);
        break;
    case 343:
        if (FLAGS(w)->f10 == 0) {
            FLAGS(w)->f10 = 1;
            if (func_0200B5CC((void *)s48, 4, &out, 0) == 1)
                FLAGS(w)->f10 = 2;
        }
        break;
    case 344:
        if (FLAGS(w)->f10 == 1)
            *dst = 0;
        else
            *dst = 1;
        break;
    case 345:
        func_0200BA58();
        func_021EEE78((void *)(*(u32 *)&((struct Obj00335 *)w)->f7CC));
        func_0200BA68();
        break;
    case 346:
        ((struct Obj00335 *)w)->f7E8 = 0;
        ((struct Obj00335 *)w)->f7EA = 0;
        ((struct Obj00335 *)w)->f10 = p1;
        func_020113D0(a, (int)func_021CBC14);
        FLAGS(w)->f10 = 2;
        ret = 1;
        break;
    case 347:
        if (*(u32 *)&((struct Obj00335 *)w)->f7CC != 0) {
            func_0200B424();
            func_020130B4(*(u32 *)&((struct Obj00335 *)w)->f7CC);
            *(u32 *)&((struct Obj00335 *)w)->f7CC = 0;
        }
        break;
    case 348:
        func_02082BCC(w + 0x7d0, 0, 0x18);
        ((struct Obj00335 *)w)->f7D0 = s4c;
        ((struct Obj00335 *)w)->f7D4 = 1;
        ((struct Obj00335 *)w)->f7D8 = 0;
        ((struct Obj00335 *)w)->f7DC = 1;
        ((struct Obj00335 *)w)->f7E0 = data_021DAD24[s3c];
        ((struct Obj00335 *)w)->f7E4 = func_021CA234(w);
        if (((struct Obj00335 *)w)->f7E4 > 9999)
            ((struct Obj00335 *)w)->f7E4 = 9999;
        func_0215897C(h, func_02014808((char *)x, (int)s30, (u32)ov214_id, (int)data_021BB474, (int)(w + 0x7d0), 0, 0));
        ret = 1;
        break;
    case 349:
        func_0200DA14((struct Blk3C *)s40);
        func_0200DB1C((struct Blk1AC *)s38, s3c);
        break;
    case 350:
        func_021F388C((int)s30);
        break;
    case 351: {
        u32 n = func_0200DA54((struct Blk3C *)s40);
        switch (s3c) {
        case 2:
        case 3:
        case 7:
        case 8:
            *dst = *(u16 *)(w + (n * 2 + p1) * 2 + 0x32);
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        default:
            *dst = *(u16 *)(w + n * 2 + 0x32);
            break;
        }
        break;
    }
    case 352:
        func_0215897C(h, func_0216C6E8(w, (void *)x, p1, p2, 6));
        ret = 1;
        break;
    case 353: {
        u8 *e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e != NULL) {
            u32 kb6 = e[0xb6];
            u32 kbf = e[0xbf];
            int cnt;
            void *party = ((struct Obj02400 *)e)->f24;
            int i;
            int sa;
            int sb;
            cnt = func_0201AA18(party);
            sa = 0;
            sb = 0;
            for (i = 0; i < cnt; i++) {
                void *mon = func_0201AB28(party, i);
                int a1 = func_02017E1C(mon, 0xa0, 0);
                int b1 = func_02017E1C(mon, 0xa1, 0);
                sa += a1;
                sb += b1;
            }
            func_0200D9E8((struct Blk3C *)s40, kbf, kb6, (u16)(sb - sa));
        }
        break;
    }
    case 354:
        FLAGS(w)->b12 = p1;
        break;
    case 355:
        *dst = FLAGS(w)->b12;
        break;
    case 356:
        *dst = func_0200D884((struct Blk3C *)s40, 10, 0);
        break;
    case 357:
        func_0200DA28((struct Blk3C *)s40);
        func_021CA23C(w);
        *dst = func_021CA234(w);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 358:
        *dst = func_021CA234(w);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 359:
        if (func_0200DB44((struct Blk1AC *)s38, s3c) == 0) {
            func_0200DB30((struct Blk1AC *)s38, s3c);
            func_0200DA14((struct Blk3C *)s40);
            func_021CA250((u32)w);
        }
        break;
    case 400:
        if (FLAGS(w)->b9 == 1)
            func_02167B00((u32)w);
        else
            func_02167AB0(w);
        break;
    case 401:
        func_0215897C(h, func_021CB914((void *)x, (u32)w));
        ret = 1;
        break;
    case 402:
        w[0x727] = p1;
        ((struct Obj00335 *)w)->f72A = s28;
        func_02167B24(w[0x727]);
        func_020113D0(a, (int)func_021CB700);
        ret = 1;
        break;
    case 403:
        *(u16 * *)&((struct Obj00335 *)w)->f720 = dst;
        ((struct Obj00335 *)w)->f71C = func_021CD48C((u32)func_02012944((void *)s4c), s30, 2, 2, 4, 0, 2, 0);
        func_020113D0(a, (int)func_021CB754);
        ret = 1;
        break;
    case 404:
        *(u16 * *)&((struct Obj00335 *)w)->f720 = dst;
        ((struct Obj00335 *)w)->f71C = func_021CD48C((u32)func_02012944((void *)s4c), s30, 2, 2, 4, 1, 2, 0);
        ret = 1;
        func_020113D0(a, (int)func_021CB7E8);
        break;
    case 405:
        func_02167BFC((struct Obj *)w, p1, p2);
        func_020113D0(a, (int)func_021CB6DC);
        ret = 1;
        break;
    case 406:
        func_02167CF4(w, p1);
        ((struct Obj00335 *)w)->f72A = s28;
        func_020113D0(a, (int)func_021CB86C);
        ret = 1;
        break;
    case 407:
        *dst = func_02039338();
        break;
    case 408:
        func_02082BCC(w + 0x7a4, 0, 0x24);
        ((struct Obj00335 *)w)->f7A4 = s4c;
        ((struct Obj00335 *)w)->f7C0 = 11;
        func_0215897C(h, func_02014808((char *)x, (int)s30, (u32)ov100_id, (int)data_021BB6A4, (int)(w + 0x7a4), 0, 0));
        ret = 1;
        break;
    case 409:
        switch (((struct Obj00335 *)w)->f7C0) {
        case 11:
            *dst = 0;
            break;
        case 12:
            *dst = 1;
            break;
        case 13:
            *dst = 2;
            break;
        default:
            *dst = 1;
            break;
        }
        break;
    case 410:
        func_0200ED54(func_0200ED48((void *)s48), ((struct Obj00335 *)w)->f73C);
        break;
    case 411:
        *dst = func_021A3190(func_02039338() == 0 ? func_021A30B0(func_02188CB4((void *)s30)) : w[0x749], 0);
        break;
    case 412:
        *dst = func_021A3190(func_02039338() == 0 ? w[0x749] : func_021A30B0(func_02188CB4((void *)s30)), 0);
        break;
    case 413:
        func_0200FB38();
        break;
    case 414:
        func_02012124((struct Ctx *)x, 1);
        break;
    case 415:
        *dst = 0;
        if (func_0200FB24() != 0)
            *dst = 1;
        break;
    case 416: {
        u8 *e;
        *dst = 0;
        e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e != NULL && func_0200BA38(e[0x91]) == 1)
            *dst = 1;
        break;
    }
    case 501:
        break;
    }
    return ret;
}
