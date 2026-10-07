/*
 * file:     event_poke_status_p22.c
 * unit:     yes
 * function: func_0215AA50, func_0215AA60, func_0215AA90, func_0215AABC, func_0215AADC, func_0215AAF4, func_0215AB18, func_0215AB3C, func_0215AB60, func_0215AB98, func_0215ABD0, func_0215ABEC
 * address:  0x0215AA50
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
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_020083EC  0x020083EC  thumb
 *   func_02159B10   0x02159B10  thumb  ov010
 *   func_020056EC   0x020056EC  thumb
 *   func_0215A610  0x0215A610  thumb  ov010
 *   func_0216F830  0x0216F830  thumb  ov010
 *   func_021690B4  0x021690B4  thumb  ov010
 *   func_021690F0  0x021690F0  thumb  ov010
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   func_02169100  0x02169100  thumb  ov010
 *   func_02169110  0x02169110  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02087D28 0x02087D28 arm
 */
struct Big;
struct Sub02008700Obj;
struct BigObj;
struct OSOwnerInfoEx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Info { u8 language, color, month, day; u16 name[11], nameLength, comment[27], commentLength; u8 country, padding; } Info;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
extern int func_020083EC();
extern unsigned int func_02159B10(void *a0, void *a1);
extern u32 func_020056EC(u32 range);
extern u16 func_0215A610(void *p);
extern int func_0216F830(void *save);
extern int func_021690B4(int a0);
extern int func_021690F0(int a0);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern int func_02169100(int a0);
extern int func_02169110(int a0);
extern u8 func_02012984(const struct BigObj *p);
extern void func_02087D28(struct OSOwnerInfoEx *info);
int func_0215AA50(int a0, int a1);
int func_0215AA60(int a0, int a1);
int func_0215AA90(int a0, int a1);
int func_0215AABC(void *a0, void *a1);
int func_0215AADC(int a0, int a1);
int func_0215AAF4(int a0, int a1);
int func_0215AB18(int a0, int a1);
int func_0215AB3C(int a0, int a1);
int func_0215AB60(int a0, int a1);
int func_0215AB98(int a0, int a1);
int func_0215ABD0(int a0, int a1);
int func_0215ABEC(int a, int b);


int func_0215AA50(int a0, int a1)
{
    u16 *q;

    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AA56:
a1 = 0x15;
*q = a1;
a0 = 0;
    return a0;}


/*
 * blocked:  listing 48 compiled 46
 */
int func_0215AA60(int a0, int a1)
{
    void *p;
    struct Sub02008700Obj *t4;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AA68:
    p = func_02012EBC((struct Big *)v0);
loc_0215AA6C:
    t4 = func_0200873C(p);
loc_0215AA70:
    a0 = func_020083E4((short unsigned int *)t4);
loc_0215AA76:
a1 = a0 + 0;
    if (a1 != 0) goto loc_0215AA7E;
loc_0215AA7A:
a1 = 1;
    goto loc_0215AA84;
loc_0215AA7E:
    if (a1 != 1) goto loc_0215AA84;
loc_0215AA82:
a1 = 0;
loc_0215AA84:
    a0 = func_020083EC(t4, a1);
loc_0215AA8A:
a0 = 0;
    return a0;}


/*
 * blocked:
 */
int func_0215AA90(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    struct Sub02008700Obj *t4;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AA9C:
    p = func_02012EBC((struct Big *)v0);
loc_0215AAA0:
    t4 = func_0200873C(p);
loc_0215AAA4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AAAE:
    a0 = func_020083E4((short unsigned int *)t4);
loc_0215AAB6:
*q = a0;
a0 = 0;
    return a0;}


/*
 * Same slot overwrite, keyed off the second index helper and the
 * caller's second argument.
 */
int func_0215AABC(void *a0, void *a1)
{
    u16 *p = func_02159AE8(a0, a1);

    *p = (u16)func_020056EC(func_02159B10(a0, a1));

    return 0;
}


int func_0215AADC(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AAE4:
a0 = t5 + 0;
    a0 = func_0215A610((void *)a0);
loc_0215AAEC:
*q = a0;
a0 = 0;
    return a0;}


int func_0215AAF4(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB00:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB0A:
    a0 = func_0216F830(v0);
loc_0215AB12:
*q = a0;
a0 = 0;
    return a0;}


int func_0215AB18(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB24:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB2E:
    a0 = func_021690B4((int)v0);
loc_0215AB36:
*q = a0;
a0 = 0;
    return a0;}


int func_0215AB3C(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB48:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB52:
    a0 = func_021690F0((int)v0);
loc_0215AB5A:
*q = a0;
a0 = 0;
    return a0;}


int func_0215AB60(int a0, int a1)
{
    int t4;
    int t7;
    u16 *q;
    u16 *dst;
    void *v0;

t7 = a1 + 0;
t4 = a0 + 0;
a0 = t7 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB6C:
a0 = t4 + 0;
a1 = t7 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB76:
a0 = t4 + 0;
a1 = t7 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB80:
    a0 = func_021690D0((int)v0);
loc_0215AB88:
*q = a0;
    a0 = func_021690E0((int)v0);
loc_0215AB90:
*dst = a0;
a0 = 0;
    return a0;}


int func_0215AB98(int a0, int a1)
{
    int t4;
    int t7;
    u16 *q;
    u16 *dst;
    void *v0;

t7 = a1 + 0;
t4 = a0 + 0;
a0 = t7 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ABA4:
a0 = t4 + 0;
a1 = t7 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABAE:
a0 = t4 + 0;
a1 = t7 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABB8:
    a0 = func_02169100((int)v0);
loc_0215ABC0:
*q = a0;
    a0 = func_02169110((int)v0);
loc_0215ABC8:
*dst = a0;
a0 = 0;
    return a0;}


int func_0215ABD0(int a0, int a1)
{
    int t5;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABD8:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ABE0:
    a0 = func_02012984(v0);
loc_0215ABE4:
*q = a0;
a0 = 0;
    return a0;}

/*
 * extent: compiled 46 bytes; trailing 0x0215AC1A..0x0215AC1C is zero alignment.
 */
int func_0215ABEC(int a, int b) {
 u16 *p, *q;
 Info info;
 p = func_02159AE8((void *)a, (void *)b);
 q = func_02159AE8((void *)a, (void *)b);
 func_02087D28((struct OSOwnerInfoEx *)(&info));
 *p = info.month;
 *q = info.day;
 return 0;
}
