/*
 * file:     comm_player_p16.c
 * unit:     yes
 * function: func_02168F54, func_02169004, func_02169068, func_021690A4, func_021690B4, func_021690D0
 * address:  0x02168F54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02089004  0x02089004  arm
 *   func_02088F58  0x02088F58  arm
 *   _ll_sdiv       0x0209BE5C  arm
 *   func_02169138  0x02169138  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020143F0  0x020143F0  thumb
 *   func_0200D440  0x0200D440  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201B100  0x0201B100  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008E30  0x02008E30  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200952C  0x0200952C  thumb
 *   func_021862A8  0x021862A8  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E518  0x0200E518  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200AB04  0x0200AB04  thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_0216A2EC 0x0216A2EC thumb ov010
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3C0 0x0200C3C0 thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_020113F0  0x020113F0  thumb
 */
#include "../../matched/include/Obj17735.h"
#include "../../matched/include/Obj17736.h"

struct RTCDate;
struct RTCTime;
struct BigObj;
struct Tally;
struct Big;
struct Rec0200AB04;
struct Sub02009470Obj;
struct Blk34;
struct Sub02008AECSession;
typedef unsigned int u32;

typedef long long s64;

typedef struct { u32 a, b, c, d; } Date;

typedef struct { u32 a, b, c; } Time;

typedef struct {
    int f0;
    Date date;
    Time time;
    int f20;
} A;

typedef signed int     s32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern s32 func_02088F58(struct RTCDate *date);
extern int func_02169138(int a0);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_020143F0(u8 *a);
extern void func_0200D440(void *sys);
extern void *func_02012934(const struct BigObj *p);
extern void func_0201B100(void *, int);
extern void *func_02012F2C(int *p);
extern void func_02008E30(void *a0);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void func_0200952C(struct Sub02009470Obj *obj);
extern void func_021862A8(int, int, int);
extern void *func_0200E394(void *a0);
extern void func_0200E518(struct Tally *t);
extern void *func_0200A8A0(void *sys);
extern void func_0200AB04(struct Rec0200AB04 *o);
extern void *func_0201AD0C(void *sys);
extern u8 func_02012984(const struct BigObj *p);
extern int func_0216A2EC(int,int,int,int *,int);
extern void *func_0200C0F0(void *sys);
extern void func_0200C3C0(struct Blk34 *p, u16 v);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_020113F0(int row, int col);
int func_02168F54(A *a, Date *b, Time *c, int *d, int *e);
void func_02169004(int a, int b);
void func_02169068(int a,int b,int *c);
void *func_021690A4(int a0);
int func_021690B4(int a0);
int func_021690D0(int a0);


int func_02168F54(A *a, Date *b, Time *c, int *d, int *e)
{
    s64 sa = func_02089004((struct RTCDate *)(&a->date), (struct RTCTime *)(&a->time));
    s64 sb = func_02089004((struct RTCDate *)b, (struct RTCTime *)c);
    int day = func_02088F58((struct RTCDate *)b);
    int q;
    *d = 0;
    *e = 0;
    if (sb < sa) {
        a->date = *b;
        a->time = *c;
        a->f20 = day;
        return 0;
    }
    q = (int)((sb - sa) / 60);
    if (q > 0) {
        int dd;
        *e = q;
        a->date = *b;
        a->time = *c;
        dd = day - a->f20;
        if (dd != 0) {
            *d = dd;
            a->f20 = day;
        }
    }
    return 1;
}


/*
 * evidence: 0x0200E518 is an unlabelled ARM9 leaf ("push {r4, r5, r6, r7}",
 * no lr, right after the "pop {r4, pc}" at 0x0200E516) that the prologue
 * sweep misses.  The bl at +0x52 is its only reference in the image; its
 * start is seeded in layout/function_starts.txt, and the callee itself is
 * matched EXACT* (src/matched/arm9/func_0200E518.c), so +0x52 attests as
 * `matched`.
 */
void func_02169004(int a, int b)
{
    int x;
    func_02169138(a);
    x = (int)func_02012EBC((struct Big *)a);
    func_020143F0((u8 *)func_0201296C((const struct BigObj *)a));
    func_0200D440((void *)x);
    func_0201B100(func_02012934((void *)a), b);
    func_02008E30(func_02012F2C((int *)a));
    func_0200952C(func_02009470((void *)x));
    func_021862A8(a, b, 4);
    func_0200E518(func_0200E394((void *)x));
    func_0200AB04(func_0200A8A0((void *)x));
}

/*
 * extent: trailing two-byte alignment padding.
 * interface: final u16 argument follows the original lsls/lsrs #16 pair.
 */
void func_02169068(int a,int b,int *c) { int t=(int)func_0201AD0C(func_02012EBC((struct Big *)a)); func_0216A2EC(a,t,b,c,func_02012984((const struct BigObj *)a)); func_0200C3C0((struct Blk34 *)((int)func_0200C0F0(func_02012EBC((struct Big *)a))),b); }


void *func_021690A4(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690AA:
    s = func_02008B14(big);
loc_021690AE:
    return (char *)s + 4;}


int func_021690B4(int a0)
{
    int a1;
    struct Sub02008AECSession *t4;
    void *big;
    int t5;

t5 = a0 + 0;
    big = func_02012EBC((struct Big *)a0);
loc_021690BC:
    t4 = func_02008B14(big);
loc_021690C0:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_021690C8:
a1 = ((struct Obj17735 *)t4)->f14;
    a0 = func_020113F0(a0, a1);
loc_021690CE:
    return a0;}


int func_021690D0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690D6:
    s = func_02008B14(big);
loc_021690DA:
a0 = ((struct Obj17736 *)s)->f8;
    return a0;}
