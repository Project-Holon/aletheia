/*
 * file:     dwc_rap.c
 * unit:     yes
 * function: func_02155160, func_02155168, func_021551B0, func_021551DC, func_02155204, func_02155234, func_0215523C, func_02155244, func_02155264, func_02155280, func_0215528C, func_02155294, func_021552AC, func_021552DC, func_021552E8, func_02155330, func_02155338, func_0215536C, func_02155374, func_02155388, func_0215539C, func_021554A0, func_021554C8, func_02155648, func_02155664, func_02155674, func_02155678, func_0215568C, func_0215580C, func_02155904, func_0215592C, func_02155A80, func_02155B00, func_02155B14, func_02155B68, func_02155B98, func_02155BDC, func_02155C0C, func_02155C24, func_02155C28, func_02155C6C, func_02155C70, func_02155C8C, func_02155D2C, func_02155D3C, func_02155D7C, func_02155D80, func_02155DA4, func_02155DCC, func_02155E9C, func_02155F58, func_0215610C, func_0215615C, func_021561C0, func_021562EC, func_02156330, func_02156344, func_021563C0, func_021563D0, func_021563EC, func_02156400, func_0215642C, func_02156460, func_02156690, func_02156730, func_0215677C, func_021567B8, func_0215683C, func_02156860, func_02156874, func_02156888, func_02156A3C, func_02156A58, func_02156B18, func_02156B3C, func_02156B68, func_02156B70, func_02156B8C, func_02156BA8, func_02156BC4, func_02156BD8, func_02156C00, func_02156C60, func_02156C84, func_02156C98, func_02156CAC, func_02156CD0, func_02156CF4, func_02156D84, func_02156DC4, func_02156DE0, func_02156DFC, func_02156E24, func_02156E30, func_02156ED0, func_02156F14, func_02156F50, func_02156F5C, func_02156FDC, func_02157048, func_021570B8, func_02157108, func_02157138, func_02157160, func_02157170
 * address:  0x02155160
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_02030734  0x02030734  arm
 *   d_021A8260     0x021A8260  data  ov009  a4
 *   d_021A1C4C     0x021A1C4C  data  ov009  a1
 *   func_0203D5EC 0x0203D5EC arm
 *   func_0203D610 0x0203D610 arm
 *   func_020307B0  0x020307B0  arm
 *   func_0216B908 0x0216B908 arm ov009
 *   func_0205CCD8  0x0205CCD8  arm
 *   func_02059E38  0x02059E38  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0203CA98  0x0203CA98  arm
 *   g_021A1B80  0x021A1B80  data
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   d_021A1C60     0x021A1C60  data  ov009  a1
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_02034714  0x02034714  arm
 *   func_020597C8  0x020597C8  arm
 *   func_02059760  0x02059760  arm
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02059F18 0x02059F18 arm
 *   d_021A8264_obj 0x021A8264  data  ov009  a4
 *   d_021A1C6C     0x021A1C6C  data  ov009  a1
 *   func_0205C6AC  0x0205C6AC  arm
 *   func_0205C758  0x0205C758  arm
 *   func_0205C88C  0x0205C88C  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0205C8E0  0x0205C8E0  arm
 *   func_0216AB20  0x0216AB20  arm
 *   func_02087C88  0x02087C88  arm
 *   func_0216B0E0  0x0216B0E0  arm
 *   func_0216AE88  0x0216AE88  arm
 *   func_0216B1E0  0x0216B1E0  arm
 *   func_02168994  0x02168994  arm
 *   d_021A1C74     0x021A1C74  data  ov009  a1
 *   d_021A1974     0x021A1974  data  ov009  a1
 *   func_0216CA04  0x0216CA04  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02094530  0x02094530  arm
 *   func_0203F004  0x0203F004  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0216B284  0x0216B284  arm
 *   func_02177138  0x02177138  arm
 *   func_02177160  0x02177160  arm
 *   func_0216B634  0x0216B634  arm
 *   func_02177188  0x02177188  arm
 *   func_0216B65C  0x0216B65C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02176FD4  0x02176FD4  arm
 *   func_0216B838  0x0216B838  arm
 *   func_0205984C  0x0205984C  arm
 *   func_02059870  0x02059870  arm
 *   func_02177270  0x02177270  arm
 *   func_021AEF44  0x021AEF44  thumb  ov013
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0216B804  0x0216B804  arm  ov009
 *   func_0203A338  0x0203A338  arm
 *   func_0205CC20  0x0205CC20  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_0216AD50  0x0216AD50  arm  ov009
 *   func_021C5B80  0x021C5B80  arm  ov114
 *   DWC_GdbShutdown  0x021E1340  arm
 *   func_0216B94C  0x0216B94C  arm  ov009
 *   func_02176DEC  0x02176DEC  arm  ov009
 *   func_021AEE14  0x021AEE14  thumb  ov013
 *   func_021AF238  0x021AF238  thumb  ov013
 *   func_021AEF6C  0x021AEF6C  thumb  ov013
 *   func_021AF18C  0x021AF18C  thumb  ov013
 *   func_021AF13C  0x021AF13C  thumb  ov013
 *   func_021AF1A0 0x021AF1A0 thumb ov013
 *   func_021AF2AC 0x021AF2AC thumb ov013
 *   func_021AF30C 0x021AF30C thumb ov013
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0205912C  0x0205912C  arm
 *   func_02168848  0x02168848  arm  ov009
 *   func_021688FC 0x021688FC arm ov009
 *   func_0216B354  0x0216B354  arm  ov009
 *   func_0216B408  0x0216B408  arm  ov009
 *   func_0216B7E0  0x0216B7E0  arm  ov009
 *   func_021AF210 0x021AF210 thumb ov013
 *   func_021770EC  0x021770EC  arm  ov009
 *   abs_id_11  0x00000011  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021B6100  0x021B6100  thumb  ov017
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02060C5C  0x02060C5C  arm
 *   func_02060F18  0x02060F18  arm
 *   func_02060F40  0x02060F40  arm
 *   func_02060C94  0x02060C94  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02060CA0  0x02060CA0  arm
 *   func_0200FB6C  0x0200FB6C  thumb
 *   func_02060F98  0x02060F98  arm  arm9
 *   func_02060E30  0x02060E30  arm
 *   d_021A1C8C  0x021A1C8C  data  ov009  a1
 *   func_02059F6C  0x02059F6C  arm
 *   MIi_CpuClearFast    0x02082AC0  arm
 *   func_02059718       0x02059718  arm
 *   DWC_CreateUserData  0x020596FC  arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203C968 0x0203C968 arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200FB4C  0x0200FB4C  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0203C554  0x0203C554  arm
 */
#include "dwc_rap_types.h"

struct DWCstAccUserData;
struct OSOwnerInfo;
struct ExpHeap;
typedef signed short   s16;

typedef void (*Fn)(void);

typedef struct {
    u8 language, favoriteColor, month, day;
    u16 nickName[11], nickNameLength, comment[27], commentLength;
} OSOwnerInfo;

typedef struct Status {
    int f0;
    int f4;
    int f8;
    int fC;
} Status;

void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203D5EC(void);
extern u32 func_0203D610(void);
u32 func_020307B0(void *p);
extern int func_0216B908(void);
extern int func_0205CCD8(void);
int func_02059E38(int *a, int *b);
void func_0203C9AC(int a, u32 b, u32 c, u32 d);
u32 func_0203CA98(void);
void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
void func_02034714(const char *expr, u32 line, const char *file);
int func_020597C8(struct DWCstAccUserData *userdata);
int func_02059760(struct DWCstAccUserData *userdata);
extern void func_0203D7FC(void *);
extern void func_02059F18(void);
void func_0205C6AC(void *p, u16 a, u16 b, u16 c);
void func_0205C758(void);
int func_0205C88C(void);
int func_0205CA20(void);
void func_0205C8E0(void);
void func_0216AB20(void *a, int b, char *c, int d, int e, void *f, int g);
void func_02087C88(struct OSOwnerInfo *info);
int func_0216B0E0(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);
void func_0216AE88(void);
int func_0216B1E0(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
int func_02168994(void (*callback)(int, void *), void *param);
u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc);
void func_02082BCC(void *p, int v, int n);
u32 func_02094530(char *dst, u32 n, ...);
u32 func_0203F004(const u8 *s);
u32 func_0203D650(void);
int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_02177138(int a, int b);
int func_02177160(int a, int b);
int func_0216B634(int a, int b);
int func_02177188(int a, int b);
int func_0216B65C(void);
void func_02082D44(void *src, void *dst, int n);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
unsigned char func_0216B838(void);
int func_0205984C(void *userdata);
void func_02059870(int h);
int func_02177270(u8 a, int b);
int func_021AEF44(int a, int b, int c);
extern int func_0216B804(void);
extern void func_0203A338(u32);
extern void func_0205CC20(void);
extern u32 func_020111E8(void);
extern void func_0216AD50(void);
extern int func_021C5B80(void);
extern void DWC_GdbShutdown(void);
extern int func_0216B94C(u8);
extern int func_02176DEC(int a);
void func_021AEE14(int);
int func_021AF238(u32 mask, int n);
extern void func_021AEF6C(void *, int, int);
extern void func_021AF18C(void (*cb)(void));
extern void func_021AF1A0(void);
extern int func_021AF2AC(int);
extern void func_021AF30C(int);
extern int _s32_div_f(int, int);
extern void func_021AF13C(void);
extern int func_0205912C(u8 *);
extern unsigned char func_02168848(void *p, int a, int b);
extern int func_021688FC(char *, unsigned long);
int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_0216B408(int, int, void *, u32, void *, u32, void *, int *, u32);
extern void func_0216B7E0(u8);
extern int func_021AF210(void);
extern void func_021770EC(u8, u32, u32);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int id);
extern void func_021B6100(void);
extern void *func_02060C5C(void *start, u32 size, u16 attr);
extern u32 func_02060F18(char *p, u32 v);
extern u16 func_02060F40(char *p, u16 v);
extern void func_02060C94(void *heap);
extern void func_020306F0(u32 heap);
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, int align);
extern void func_0200FB6C(void);
extern u8 func_02060F98(char *p);
extern void func_02060E30(struct ExpHeap *heap, void *block);
extern int func_02059F6C(void *a, u32 b, void *c, void *d);
extern void MIi_CpuClearFast(unsigned int data, void *destp, unsigned int size);
extern int func_02059718(struct DWCstAccUserData *userdata);
extern void DWC_CreateUserData(void *userdata);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern int func_0203CD98(void);
extern u32 func_0200FB24(void);
extern void func_0200F83C(void);
extern void func_0200FBA0(void);
extern void func_0200FB38(void);
extern void func_0200FB4C(unsigned int x);
extern void func_0200F7C0(u32 value);
extern void func_0200FAAC(void);
extern void func_0203C554(u32 a);
void func_02155160(int a);
int func_02155168(int a, int b);
int func_021551B0(void (*cb)(int));
int func_021551D4(int a);
int func_021551DC(void *p);
int func_02155204(void (*cb)(int));
int func_02155234(void *a0, int n, int a2, int a3);
int func_0215523C(int a, int b, int c);
int func_02155244(int x);
int func_02155264(int a, int b, int c, void (*cb)(int));
int func_02155280(int a);
int func_0215528C(void);
int func_02155294(void);
int func_021552AC(void);
int func_021552C4(void);
int func_021552CC(void);
int func_021552D4(void);
int func_021552DC(void);
int func_021552E8(void);
void func_02155330(u32 v);
int func_02155338(int n);
s16 func_0215534C(void);
int func_02155354(void);
void func_0215535C(u32 v);
int func_02155364(void);
void *func_0215536C(void);
void func_02155374(int v);
int func_02155388(void);
int func_0215539C(int a0, int a1);
void func_021554A0(void);
int func_021554C8(void);
void func_02155648(int a, int b);
void func_02155664(void (*callback)(void));
void func_02155674(void);
u8 func_02155678(void);
int func_0215568C(void *a0, int n, int a2, int a3);
int func_0215580C(int a0, int n, int a2, int a3);
void func_02155904(void);
int func_0215592C(int a);
int func_02155A80(void *src, int len, int c);
int func_02155B00(int a, int b);
int func_02155B14(int a, int b);
void func_02155B68(void);
void func_02155B98(int a);
void func_02155BDC(unsigned int n);
void func_02155C0C(int a);
void func_02155C24(void);
void func_02155C28(int a, int b);
void func_02155C6C(void);
void func_02155C70(void);
void func_02155C8C(void);
void func_02155D2C(int e);
void func_02155D3C(int a, int b, int c, int d, int e);
int func_02155D7C(void);
void func_02155D80(int a, u32 i);
void func_02155DA4(unsigned int v);
void func_02155DCC(u32 a, u8 *p, int c);
void func_02155E9C(int a, int b, int c, u32 d);
int func_02155F58(void);
int func_0215610C(void);
int func_0215615C(u32 idx);
int func_021561C0(void);
int func_021562EC(void);
void func_0215631C(void);
void func_02156330(void);
void func_02156344(void *a);
void func_021563C0(int a);
void func_021563D0(void);
int func_021563EC(void);
void func_02156400(void);
void func_0215642C(int flag);
int func_02156460(int err, int kind);
int func_02156690(int a);
int func_02156730(void);
void func_0215677C(void);
void func_021567B8(void);
int func_0215683C(char *a, int b);
int func_02156860(int i);
unsigned char func_02156874(int i);
int func_02156888(int a, int b, int c);
int func_02156A3C(void);
void func_02156A58(int a, int b, int c, int d, int e);
void func_02156B18(int a, int b, int c, int d, int e);
void func_02156B3C(int a);
int func_02156B68(char *a0);
s16 func_02156B70(void);
int func_02156B8C(void);
int func_02156BA8(void);
void func_02156BC4(int v);
void func_02156BD8(u32 i);
void func_02156C00(u32 a);
void func_02156C60(void);
unsigned char func_02156C84(void);
void func_02156C98(int unused);
int func_02156CAC(void);
int func_02156CD0(void);
void func_02156CF4(void);
u32 func_02156D5C(void);
void func_02156D70(u32 v);
int func_02156D84(void);
void func_02156DB0(u32 v);
void func_02156DC4(int (*cb)(u32, u32, u32, int), u32 arg);
void func_02156DE0(int (*cb)(u32, u32, u32, int), u32 arg);
void func_02156DFC(int a);
void func_02156E24(int a, int b, int c);
void func_02156E30(u32 a, u32 b, u32 c, u32 d);
void func_02156ED0(void);
void func_02156F14(void);
void func_02156F50(int a);
u32 func_02156F5C(u32 a, u32 b, u32 c);
void func_02156FDC(u32 a, void *p, int b);
void func_02157048(u32 a, u32 b);
void func_021570B8(void);
int func_02157108(u16 a);
void func_02157138(void *userdata);
void func_02157160(void);
int func_02157170(int a0, int a1);
extern int *d_021A8260;
extern char d_021A1C4C[];
extern DwcRapWork *d_021A8264;
extern char g_021A1B80[];
extern char d_021A1C5C[];
extern char d_021A1C60[];
/* stand-in: second name for the address of d_021A8264; with one name the compiler shares the literal-pool word and the bytes change. */
extern char d_021A8264_obj[];
extern char d_021A1C6C[];
extern char d_021A1C74[];
extern char d_021A1974[];
extern unsigned char abs_id_11[];
extern RapHeap *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];
extern char d_021A1C8C[];





























void func_02155160(int a)
{
    func_02156DFC(a);
}





























int func_02155168(int a, int b)
{
    RapCtx *p;

    if (d_021A8260 != 0)
        return 0;
    p = func_0203D798();
    func_02157048(p->heap2, p->heap_size);
    d_021A8260 = func_02030734(a, 8, 1, d_021A1C4C, 0xba);
    *d_021A8260 = b;
    return 1;
}




























int func_021551B0(void (*cb)(int))
{
    u32 a;
    int r;
    a = func_0203D5EC();
    r = func_0215539C(a, func_0203D610());
    if (cb) cb(1);
    return r;
}




























int func_021551D4(int a)
{
    return func_0215592C(a);
}




























/*
 * Null-pointer guard through func_02156690, then either func_02156730 or func_0215592C.
 */
int func_021551DC(void *p)
{
    int func_02156690(int);
    int func_02156730(void);
    int func_0215592C(int a);
    int t;
    if (p == 0) t = 1;
    else t = 0;
    if (func_02156690(t)) {
        func_02156730();
        return 1;
    }
    func_0215592C((int)p);
    return 1;
}



























int func_02155204(void (*cb)(int))
{
    if (d_021A8260 != 0) {
        func_0215677C();
        if (cb != 0)
            cb(1);
        func_020307B0(d_021A8260);
        d_021A8260 = 0;
    }
    func_021570B8();
    return 1;
}




























int func_02155234(void *a0, int n, int a2, int a3)
{
    return func_0215568C(a0, n, a2, a3);
}



























int func_0215523C(int a, int b, int c)
{
    return func_02156888(a, b, c);
}




























int func_02155244(int x)
{
    int func_02156690(int);
    int func_02156730(void);
    int t;
    if (x == 0) t = 1;
    else t = 0;
    if (func_02156690(t)) {
        func_02156730();
        return 1;
    }
    return 0;
}



























int func_02155264(int a, int b, int c, void (*cb)(int))
{
    if (func_02155B14(a, b)) {
        if (cb) cb(1);
        return 1;
    }
    return 0;
}



























/*
 * Calls func_02155648 on the argument twice and returns 1.
 */
int func_02155280(int a)
{
    func_02155648(a, a);

    return 1;
}



























int func_0215528C(void)
{
    return func_02155388();
}


























/*
 * False when the word call returns -1.
 */
int func_02155294(void)
{
    if (func_021562EC() != -1) {
        return 1;
    }

    return 0;
}


























/*
 * Follower func_021552C4 resolves through the verified ov009 02156CAC leaf;
 * ov010's same-address allocator is a different function.
 */
int func_021552AC(void)
{
    int r;
    r = func_02156D84();
    if (!func_02155388()) r |= 1;
    return r;
}


























int func_021552C4(void)
{
    return func_02156CAC();
}


























int func_021552CC(void)
{
    return func_0216B908();
}


























int func_021552D4(void)
{
    return func_021562EC();
}



























/*
 * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns.
 */
int func_021552DC(void)
{
    return 3 - func_0205CCD8();
}



























int func_021552E8(void)
{
    int a, b, r;

    r = func_02059E38(&a, &b);
    if (r != 0)
        func_0203C9AC(a, b, r, 0);
    if (r == 0)
        return 0;
    if (a == 0)
        return -10000;
    r = ((int *)func_0203CA98())[3];
    if (r == 0)
        r = a;
    return r;
}


























void func_02155330(u32 v)
{
    func_02156DB0(v);
}
























/*
 * Follower func_0215535C resolves through the verified existing 02156CF4
 * unit after its function inventory was corrected to include 02156D70.
 */
int func_02155338(int n)
{
    if (func_02156874(n) == 6) return 1;
    return 0;
}
























s16 func_0215534C(void)
{
    return func_02156B70();
}
























int func_02155354(void)
{
    return func_02156B8C();
}
























void func_0215535C(u32 v)
{
    func_02156D70(v);
}
























int func_02155364(void)
{
    return func_02156CD0();
}

























/*
 * Address of the module state object.
 */
void *func_0215536C(void)
{
    return g_021A1B80;
}

























/*
 * Stores a word at +0x754 of the block the pointer holds.
 */
void func_02155374(int v)
{
    d_021A8264->state = v;
}

























/*
 * True when the block pointer is set.
 */
int func_02155388(void)
{
    return d_021A8264 != 0;
}

























/*
 * Allocates the 0x7AC-byte ov009 work block into d_021A8264 (asserting it
 * was empty) and initialises it.  func_0203D7C8's last two arguments look
 * like a file/line pair (d_021A1C60, 302).
 */
int func_0215539C(int a0, int a1)
{
    RapCtx *ctx;
    int i;

    ctx = func_0203D798();
    if (d_021A8264 != 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    d_021A8264 = func_0203D7C8(ctx->heap, sizeof(DwcRapWork), d_021A1C60, 302);
    for (i = 0; i < 32; i++)
        d_021A8264->arr[i] = -1;
    func_02155374(0);
    d_021A8264->w77C = 0;
    d_021A8264->idx = -1;
    d_021A8264->n = ctx->b60;
    d_021A8264->f774 = -1;
    d_021A8264->s782 = 0;
    d_021A8264->b79e = 0;
    d_021A8264->h794 = 1;
    d_021A8264->f790 = 1;
    d_021A8264->h796 = 1;
    d_021A8264->userdata = (void *)a0;
    d_021A8264->friend_list = (u8 *)a1;
    d_021A8264->b7a1 = 1;
    for (i = 0; i < 32; i++)
        d_021A8264->bytes[i] = 0;
    if (func_020597C8((struct DWCstAccUserData *)d_021A8264->userdata) == 0)
        return 1;
    if (func_02059760((struct DWCstAccUserData *)d_021A8264->userdata) == 0)
        return 2;
    return 0;
}
























/*
 * func_02156C60 receives the preceding call's live r0 result; its older
 * source declares no arguments. This caller preserves that register payload.
 */
void func_021554A0(void)
{
    if (d_021A8264) {
        func_0203D798();
        func_02156C60();
        func_0203D7FC(d_021A8264);
        d_021A8264 = 0;
    }
    func_02059F18();
}
























/*
 * checks: 1 SDK bodies confirm arities and payloads, case6 returns observed r0=0x3EF; 2 ov009 neighbours no complete twin; 3 u16/u8 flag both unchanged DIFF10; 4 block-local u16 name[2]={0,0} fixes address lifetime, MATCH384; 5 fresh idioms/neighbours and stack-storage idiom reread.
 * EXACT after verified ov009 leaves02155C24/02155C6C attest +170/+178. TU suggest-split diagnostic completed before leaf shards: MATCH, no viable cut. Prior once300 consumed, never repeated.
 * Fresh retry: 10 one runs plus TU; assignment-return85, constant local return10, raw name/pair/union and flag widths10; initializer closes concrete bytes. No volatile or input-domain restriction.
 */
int func_021554C8(void)
{
    OSOwnerInfo info;
    void *m;
    int flag;
    int ret;

    switch (d_021A8264->state) {
    case 0:
        func_0203D798();
        func_0205C6AC(d_021A8264->x10C, 2, 1, 0x14);
        func_0205C758();
        func_02155374(1);
        d_021A8264->f76c = 0;
    case 1:
        if (func_0205C88C() != 0) {
            if (func_0205CA20() == 4)
                func_02155374(2);
            else
                func_02155374(14);
        } else {
            func_0205C8E0();
            break;
        }
    case 2:
        ret = func_02155F58();
        if (ret != 0)
            return ret;
        flag = 0;
        m = d_021A8264->friend_list;
        if (m != 0)
            flag = 0x20;
        func_0216AB20(d_021A8264->userdata, 0x2FC6, d_021A1C6C, 0, 0, m, flag);
        d_021A8264->b7a9 = 1;
        { u16 name[2] = {0, 0};
        func_02087C88((struct OSOwnerInfo *)(&info));
        func_0216B0E0(name, 0, (void (*)(int,  int,  void *))((Fn)func_02155B98), 0);
        }
        func_02155374(3);
    case 3:
        func_0216AE88();
        break;
    case 4:
        if (d_021A8264->friend_list != 0) {
            if (func_0216B1E0(0, func_02155C0C, d_021A8264->userdata,
                              func_02155C24, d_021A8264_obj, func_02155C28,
                              d_021A8264_obj) == 0) {
                func_0203C9AC(0, 0, 0, 0x3EE);
            } else {
                func_02168994((void (*)(int,  void *))func_02155C6C, 0);
                func_0216AE88();
            }
        }
        func_02155374(5);
        break;
    case 5:
        func_0216AE88();
        if (d_021A8264->friend_list == 0)
            func_02155374(6);
        break;
    case 6:
        func_0216AE88();
        { int code = 0x3EF; d_021A8264->err = code; return code; }
    }
    return func_02155F58();
}
























/*
 * Stores two words at +0x27C and +0x280 of the block the module pointer holds.
 */
void func_02155648(int a, int b)
{
    d_021A8264->cb0 = (RapRecvCb)a;
    d_021A8264->cb1 = (RapRecvCb)b;
}























/*
 * evidence: caller ov099021BEEC4 BL targets this word-run start; full
 *   Thumb decode stores the original callback R0 at global +0x2a4 and returns.
 */
void func_02155664(void (*callback)(void))
{
    d_021A8264->cb2A4 = (int (*)(int, u32))callback;
}






















/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a callback by func_0215568C / func_0215580C.
 */
void func_02155674(void)
{
}























/*
 * Unlabelled leaf (no lr save, so disasm.py prints it as .word data); its
 * address is taken as a callback by func_02156888 / func_0215568C.
 */
u8 func_02155678(void)
{
    return d_021A8264->b7a5;
}























/*
 * Sibling of func_0215580C: in state 6, formats a 0x80-byte name at +0x2AC,
 * resets n slots, enters state 7 and hands func_0216B284 (mode 2) and three
 * registrars the ov009 callbacks.
 *
 * The four callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 */
int func_0215568C(void *a0, int n, int a2, int a3)
{
    int i;

    if (d_021A8264 == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (d_021A8264->state != 6)
        return 0;
    func_02156C60();
    if (func_0216CA04(0, d_021A1C74, a0) == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    func_02082BCC(d_021A8264->name, 0, 0x80);
    func_02094530(d_021A8264->name, (u32)d_021A1974, d_021A1C74, a0);
    if ((int)func_0203F004((const u8 *)d_021A8264->name) >= 0x80)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a2)
        func_0216CA04(1, d_021A8264->name, d_021A8264->name);
    for (i = 0; i < n; i++)
        func_02156C00(i);
    func_02155374(7);
    d_021A8264->n = n;
    if (func_0216B284(2, n, d_021A8264->name, (Fn)func_02155D3C,
                      (void *)func_0203D650(), func_02155674,
                      (void *)func_0203D650(), (Fn)func_02155D7C,
                      (void *)func_0203D650(), (Fn)func_02155678,
                      &d_021A8264->w750, (void *)func_0203D650()) == 0)
        return 0;
    d_021A8264->mode = 0;
    func_02177138((int)((Fn)func_02155D80), 0);
    func_02177160((int)((Fn)func_02155DCC), 0);
    func_0216B634((int)((Fn)func_02155E9C), 0);
    func_02177188((int)((Fn)func_02155BDC), 0);
    d_021A8264->f760 = 0;
    d_021A8264->b7a1 = 1;
    return 1;
}























/*
 * In state 6 of the ov009 work block: resets n slots, enters state 7 and
 * hands func_0216B284 and three registrars the ov009 callbacks.
 *
 * The two callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 */
int func_0215580C(int a0, int n, int a2, int a3)
{
    int i;

    if (d_021A8264 == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (d_021A8264->state != 6)
        return 0;
    func_02156C60();
    for (i = 0; i < n; i++)
        func_02156C00(i);
    func_02155374(7);
    d_021A8264->n = n;
    if (func_0216B284(1, n, (char *)a0, (Fn)func_02155D3C, 0, func_02155674, 0, (void *)a2, (void *)a3,
                      0, 0, 0) == 0)
        return 0;
    d_021A8264->mode = 0;
    func_02177138((int)((Fn)func_02155D80), 0);
    func_02177160((int)((Fn)func_02155DCC), 0);
    func_0216B634((int)((Fn)func_02155E9C), 0);
    func_02177188((int)((Fn)func_02155BDC), 0);
    d_021A8264->f760 = 0;
    d_021A8264->b7a1 = 1;
    d_021A8264->err = 0x3EF;
    return 1;
}






















/*
 * Sets 0xd through func_02155374 when the word at +0x754 is 0xc, else 0xb.
 */
void func_02155904(void)
{
        void func_02155374(int v);
    if (d_021A8264->state == 0xc) {
        func_02155374(0xd);
        return;
    }
    func_02155374(0xb);
}




















static inline int SetErr(int e)
{
    d_021A8264->err = e;
    return e;
}




















int func_0215592C(int a)
{
    func_02155B68();
    switch (d_021A8264->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return func_021554C8();
    case 7:
        if (a != 0)
            func_02155374(8);
        if (d_021A8264->mode == 2 && d_021A8264->idx >= 0
            && d_021A8264->bytes[d_021A8264->idx] != 6)
            func_02155374(12);
        break;
    case 8:
    case 12:
        func_0216B65C();
        func_02155904();
        break;
    case 9: {
        RapCtx *p = func_0203D798();
        if (d_021A8264->s782 != 0)
            func_02156344((void *)p->heap);
        d_021A8264->h794 = 0;
        func_02155374(10);
        return SetErr(1000);
    }
    case 11:
        func_02155374(6);
        d_021A8264->f760 = 0;
        d_021A8264->f774 = -1;
        return SetErr(0x3e9);
    case 13:
        func_02155374(6);
        d_021A8264->f760 = 0;
        d_021A8264->f774 = -1;
        return SetErr(0x3ea);
    case 14:
        return func_02155F58();
    case 18:
        if (d_021A8264->f76c == 0) {
            func_0216B65C();
            func_02155374(0x13);
            break;
        }
    case 6: {
        int r = func_021561C0();
        if (r == 0)
            return SetErr(0x3ef);
        return r;
    }
    }
    return func_021561C0();
}




















int func_02155A80(void *src, int len, int c)
{
    int r;

    if (len >= 0x100)
        return 0;
    if (d_021A8264->f760 != 0)
        return 0;
    d_021A8264->pkt.hdr = c | (d_021A8264->h794 << 8);
    d_021A8264->seq = d_021A8264->seq + 1;
    d_021A8264->pkt.b[2] = d_021A8264->seq;
    func_02082D44(src, d_021A8264->pktdata, len);
    d_021A8264->f760 = 1;
    r = (u16)func_0216B908();
    if (r != func_02176FD4(r, d_021A8264, len + 4)) {
        d_021A8264->f760 = 0;
        return 0;
    }
    return 1;
}




















/*
 * Flag test on the three-argument call.
 */
int func_02155B00(int a, int b)
{
    if (func_02155A80((void *)a, b, 3) != 0) {
        return 1;
    }

    return 0;
}


















int func_02155B14(int a, int b)
{
    if (d_021A8264->b7a6 == 0)
        return 0;
    if (func_02155A80((void *)a, b, 1) == 0)
        return 0;
    d_021A8264->b7a6 = 0;
    if (d_021A8264->cb1 != 0) {
        int r = func_0216B838();
        d_021A8264->cb1(r, (u8 *)a, (u16)b);
    }
    return 1;
}
















void func_02155B68(void)
{
    int value;
    if (d_021A8264->b7a7) {
        value = 0;
        if (func_02155B00((int)&value, 4))
            d_021A8264->b7a7 = 0;
    }
}
















void func_02155B98(int a)
{
    if (func_0205984C((void *)d_021A8264->userdata) != 0) {
        func_02059870((int)d_021A8264->userdata);
        d_021A8264->b7a2 = 1;
    }
    if (a == 0)
        func_02155374(4);
    else
        func_02155374(14);
}
















void func_02155BDC(unsigned int n)
{
    if (n < 2 && d_021A8264->b7a8) {
        func_0216B65C();
        d_021A8264->f774 = -1;
        func_02155374(20);
    }
}

















void func_02155C0C(int a)
{
    if (a == 0) {
        func_02155374(6);
        return;
    }

    func_02155374(0xe);
}
















/*
 * Unlabelled empty callback leaf for func_021554C8. Reads no arguments.
 */
void func_02155C24(void)
{
}

















/*
 * Stores a and b into every one of 0x20 slots at +0x17C and +0x1FC whose first word is -1.
 */
void func_02155C28(int a, int b)
{
    int i;

    func_0203D798();
    for (i = 0; i < 0x20; i++) {
        if (d_021A8264->arr[i] == -1) {
            d_021A8264->arr[i] = a;
            d_021A8264->arr2[i] = b;
        }
    }
}
















void func_02155C6C(void)
{
}















/*
 * Clears the eight bytes at +0x784 of the block the module pointer holds.
 */
void func_02155C70(void)
{
    func_02082BCC((char *)d_021A8264->cnt, 0, 8);
}















void func_02155C8C(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
        func_02177270(i, 0);
    if (func_0216B838() == 0) {
        for (j = 0; j < d_021A8264->n; j++) {
            if (j != func_0216B838() && (func_0216B908() & (1 << j)) != 0) {
                if (func_02177270(j, 10000) == 0)
                    func_02034714(d_021A1C5C, 0, d_021A1C5C);
            }
        }
    } else {
        if (func_02177270(0, 10000) == 0)
            func_02034714(d_021A1C5C, 0, d_021A1C5C);
    }
    d_021A8264->b7a8 = 1;
    func_02155C70();
}















/*
 * Enables slot 9 then calls the wakeup.
 */
void func_02155D2C(int e)
{
    func_02155374(9);
    func_02155C8C();
}













void func_02155D3C(int a, int b, int c, int d, int e)
{
    DwcRapWork *g;

    if (a == 0) {
        if (b == 0)
            func_02155D2C(e);
        else
            func_02155904();
    } else {
        func_02155374(14);
    }
    g = d_021A8264;
    if (g->cb29C != 0) {
        int r = func_0216B838();
        d_021A8264->cb29C(r, g->arg2A0);
    }
}












/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a callback by func_0215568C / func_0215580C.
 */
int func_02155D7C(void)
{
    return 1;
}













/*
 * Unlabelled leaf (no lr save, so disasm.py prints it as .word data); its
 * address is taken as a callback by func_02156888 / func_0215568C.
 */
void func_02155D80(int a, u32 i)
{
    if (i < 2) {
        d_021A8264->f760 = 0;
        d_021A8264->cnt[i] = 0;
    }
}










void func_02155DA4(unsigned int v)
{
    if (v & 0x100) {
        d_021A8264->f790 = 1;
    } else {
        d_021A8264->f790 = 0;
    }
}











void func_02155DCC(u32 a, u8 *p, int c)
{
    u32 x = p[0] | ((p[3] << 24) | (p[2] << 16) | (p[1] << 8));

    if (a >= 2)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a < 2) {
        d_021A8264->b7a8 = 1;
        if ((u8)x == 1) {
            func_02155DA4(x);
            d_021A8264->b79d = p[2];
            d_021A8264->b7a7 = 1;
        } else if ((u8)x == 3) {
            d_021A8264->b7a6 = 1;
            return;
        } else {
            if (func_021AEF44(a, (int)p, c) == 0)
                return;
            return;
        }
        if (func_0216B838() == 0) {
            if (d_021A8264->cb0 != 0)
                d_021A8264->cb0(a, p + 4, (u16)(c - 4));
        } else {
            if (d_021A8264->cb1 != 0)
                d_021A8264->cb1(a, p + 4, (u16)(c - 4));
        }
    }
}











void func_02155E9C(int a, int b, int c, u32 d)
{
    if (d < 2) {
        d_021A8264->f760 = 0;
        d_021A8264->cnt[2] = 0;
        d_021A8264->f778 = 0;
        if (a == 0) {
            if (d_021A8264->b7a1 == 1 && func_0216B804() == 1) {
                if (d_021A8264->state != 8) {
                    func_02155374(0x12);
                }
                if (d_021A8264->f76c != 0) {
                    func_02156400();
                }
            }
            if (b == 0) {
                func_02155374(0x12);
            }
        }
        if (d_021A8264->b7a3 != 0) {
            u32 *q = (u32 *)func_0203CA98();
            if (q[3] == 0) {
                func_0203C9AC(q[0], q[1], q[2], 0x3f1);
            }
        }
        func_0203A338(d);
        {
            void (*cb)(u32, u32) = d_021A8264->cb284;
            if (cb != 0) {
                cb(d, d_021A8264->arg288);
            }
        }
    }
}












/*
 * Handle a network error: run the error callbacks, then react by error kind.
 * stand-in: `goto L` enters case 4's if-body; with the copy `ret = v` there the
 * r == 0 branch keeps the original short beq (accepted as the source form).
 */
int func_02155F58(void)
{
    int a, b;
    int r;
    u32 ret;
    u32 v = 0;
    int (*cb)(u32, u32, u32, int);

    r = func_02059E38(&a, &b);
    if (r == 0) goto L;
    cb = d_021A8264->cb294;
    if (cb != 0) {
        if (cb(d_021A8264->arg298, a, b, r) == 1)
            return v;
    }
    cb = d_021A8264->cb28C;
    if (cb != 0)
        cb(d_021A8264->arg290, a, b, r);
    v = a;
    if (a == 0 || b == 1)
        v = r;
    ret = v;
    switch (b) {
    case 1:
        func_02059F18();
        if (d_021A8264 != 0 && d_021A8264->state == 0xE)
            func_02155374(6);
        break;
    case 2:
        if (a <= -40000 && a >= -41999)
            DWC_GdbShutdown();
        if (d_021A8264 != 0 && d_021A8264->state == 0xE)
            func_02155374(6);
        break;
    case 4:
        if (a <= -40000 && a >= -41999) {
            DWC_GdbShutdown();
        L:
            ret = v;
        }
        break;
    case 5:
        func_021C5B80();
        break;
    case 3:
    case 6:
        if (d_021A8264 != 0) {
            switch (d_021A8264->state) {
            case 3: case 6: case 7: case 8: case 9: case 10: case 11:
            case 14: case 18: case 19: case 20:
                if (d_021A8264->b7a9 == 1) {
                    func_0216AD50();
                    d_021A8264->b7a9 = 0;
                }
                /* fall through */
            case 0: case 1: case 2:
                func_0205CC20();
                break;
            default:
                break;
            }
        }
        if (d_021A8264 != 0)
            func_02155374(0x10);
        break;
    case 7:
        if (d_021A8264 != 0) {
            func_02155374(0x11);
            if (d_021A8264->cb2A8 != 0)
                d_021A8264->cb2A8(-a);
        }
        break;
    default:
        break;
    }
    if (d_021A8264->b79e != 0) {
        ret = 0x3EE;
        func_0203C9AC(a, b, r, ret);
    } else if (d_021A8264->state == 0x14) {
        ret = 0x3F0;
        func_0203C9AC(a, b, r, ret);
    } else if (r != 0) {
        func_0203C9AC(a, b, r, 0);
        func_020111E8();
    }
    return ret;
}












int func_0215610C(void)
{
    int i;
    int found = 0;
    for (i = 0; i < d_021A8264->n; i++) {
        if (i != func_0216B838() && func_0216B94C(i)) {
            found = 1;
            if (func_02176DEC((u8)i) == 0) {
                return 0;
            }
        }
    }
    return found;
}












int func_0215615C(u32 idx)
{
    if (d_021A8264->f760 == 0 && func_0215610C() != 0
        && (func_0216B908() & 0xFFFE) != 0) {
        d_021A8264->f760 = 1;
        d_021A8264->pkt.hdr = ((u32)d_021A8264->h794 << 8) | 2;
        func_02176FD4(func_0216B908(), d_021A8264, 4);
        d_021A8264->cnt[idx] = 0;
        return 1;
    }
    return 0;
}












int func_021561C0(void)
{
    DwcRapWork *g;
    int i;

    func_02156CF4();
    func_0216AE88();
    func_021567B8();
    if (d_021A8264->f76c != 0) {
        int v;
        if (d_021A8264->h794 == 1 && d_021A8264->f790 == 1 && d_021A8264->h796 == 1)
            v = 0;
        else
            v = 1;
        func_021AEE14(v);
        g = d_021A8264;
        if (g->aid != func_0216B908() && g->b79f == 0 && g->s782 != 0) {
            if (func_021AF238(func_0216B908(), func_0216B838()) != 0)
                d_021A8264->aid = func_0216B908();
        }
    }
    if (d_021A8264->state == 0x14) {
        int r = func_02155F58();
        if (r == 0)
            return 0x3eb;
        return r;
    }
    if (d_021A8264->state == 0x13)
        return 0x3ec;
    if (d_021A8264->state == 9 || d_021A8264->state == 10) {
        for (i = 0; i < d_021A8264->n; i++) {
            if (d_021A8264->cnt[i]++ >= 0xf0 && d_021A8264->f760 == 0 && func_0215615C(i) != 0) {
                func_02155C70();
                break;
            }
        }
    }
    return func_02155F58();
}












/*
 * Three functions: 0x021562EC, 0x0215631C, 0x02156330.
 */
int func_021562EC(void)
{
    DwcRapWork *g = d_021A8264;
    if (g != 0) {
        u32 s = g->state;
        if (s == 9 || s == 10 || s == 0x12) {
            return func_0216B838();
        }
    }
    return -1;
}












void func_0215631C(void)
{
    d_021A8264->f76c = 0;
}












void func_02156330(void)
{
    d_021A8264->h794 = 1;
}












/*
 * Start the session: set the ready flags and register the setter callback.
 */
void func_02156344(void *a)
{
    u32 v;
    d_021A8264->h794 = 1;
    d_021A8264->f790 = 1;
    d_021A8264->h796 = 1;
    if (d_021A8264->f76c == 0) {
        v = 1;
        switch (d_021A8264->w77C) {
        case 2:
            v = 1;
            break;
        case 3:
            v = 2;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 4;
            break;
        default:
            v = 4;
            break;
        }
        func_021AEF6C(a, v, 1);
        func_021AF18C(func_0215631C);
        d_021A8264->f76c = 1;
    }
}












/*
 * Halfword at +0x56 of the block func_0203D798 returns, passed on.
 */
void func_021563C0(int a)
{
    func_02156344((void *)func_0203D798()->heap);
}











/*
 * Calls the ov013 routine when the word at +0x76c of the module pointer is set.
 */
void func_021563D0(void)
{
        void func_021AF13C(void);
    if (d_021A8264->f76c) func_021AF13C();
}










/*
 * Unlabelled accessor blocking owned ov099 caller 021BFDA8.
 */
int func_021563EC(void) {
 return d_021A8264->f76c;
}










void func_02156400(void)
{
    func_021AF1A0();
    if (d_021A8264) {
        d_021A8264->f76c = 0;
        d_021A8264->aid = 0;
        d_021A8264->h794 = 0;
    }
}








/*
 * Retains the live result of func_0216B838 as func_021AF2AC's argument.
 */
void func_0215642C(int flag)
{
    if (flag) {
        func_021AF2AC(func_0216B838());
        d_021A8264->b79f = 1;
    } else {
        d_021A8264->b79f = 0;
    }
    func_021AF30C(d_021A8264->b79f);
}









/*
 * Classify a network error code (and its error kind) into a message class.
 */
int func_02156460(int err, int kind)
{
    int d100 = err / 100;
    int d1000 = err / 1000;

    if (err == 20101)
        return 1;
    if (d1000 == 23)
        return 1;
    if (err == 20108)
        return 2;
    if (err == 20110)
        return 3;
    if (d100 == 512)
        return 4;
    if (d100 == 500)
        return 5;
    if (err == 51103)
        return 6;
    if (d100 == 510)
        return 6;
    if (d100 == 511)
        return 6;
    if (d100 == 513)
        return 6;
    if (err >= 52000 && err <= 52003)
        return 8;
    if (err >= 52010 && err <= 52012)
        return 8;
    if (err >= 52100 && err <= 52103)
        return 8;
    if (err >= 52110 && err <= 52112)
        return 8;
    if (err >= 52200 && err <= 52203)
        return 8;
    if (err >= 52210 && err <= 52212)
        return 8;
    if (err >= 52400 && err <= 52403)
        return 8;
    if (err >= 52410 && err <= 52412)
        return 8;
    if (err >= 52500 && err <= 52503)
        return 8;
    if (err >= 52510 && err <= 52512)
        return 8;
    if (err >= 52700 && err <= 52703)
        return 8;
    if (err >= 52710 && err <= 52712)
        return 8;
    if (err == 80430)
        return 9;
    if (d1000 == 20)
        return 0;
    if (d100 == 520)
        return 0;
    if (d100 == 521)
        return 0;
    if (d100 == 522)
        return 0;
    if (d100 == 523)
        return 0;
    if (d100 == 530)
        return 0;
    if (d100 == 531)
        return 0;
    if (d100 == 532)
        return 0;
    if (err < 10000)
        return 14;
    if (d1000 == 31)
        return 12;
    switch (kind) {
    case 0:
    case 1:
        return 14;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return 11;
    default:
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
        break;
    case 7:
        return 15;
    }
    return -1;
}









int func_02156690(int a)
{
    u32 x, y;
    if (func_02059E38((int *)(&x), (int *)(&y)) != 0) {
        func_02059F18();
    }
    if (a == 0) {
        switch (d_021A8264->state) {
        case 7:
        case 9:
        case 10:
            if (d_021A8264->f76c != 0) {
                func_021AF13C();
            }
            func_02155374(0x12);
            break;
        case 6:
        case 16:
        case 19:
        case 20:
            return 1;
        default:
            break;
        }
    } else {
        switch (d_021A8264->state) {
        case 6:
        case 0x13:
        case 0x14:
            return 1;
        default:
            break;
        }
    }
    return 0;
}









int func_02156730(void)
{
    u32 s = d_021A8264->state;
    if (s == 0x13 || s == 0x14 || s == 0x10 || s == 6) {
        u32 v = 6;
        func_02155374(v);
        d_021A8264->err = 0x3ef;
        d_021A8264->f774 = v - 7;
        return 1;
    }
    return 0;
}








void func_0215677C(void)
{
    if (d_021A8264 != 0) {
        func_02059F18();
        if (d_021A8264->b7a9 != 0)
            func_0216AD50();
        d_021A8264->b7a9 = 0;
        func_0205CC20();
        func_02156400();
        func_021554A0();
    }
}









void func_021567B8(void)
{
    if (d_021A8264->friend_list != 0) {
        u32 i = d_021A8264->w74C & 0x1f;
        u32 o = i * 12;
        int n;
        if (func_0205912C(d_021A8264->friend_list + o) != 0) {
            u32 r = func_02168848(d_021A8264->friend_list + o,
                                  (int)d_021A8264->ent[i], (int)(&n));
            if (n < 1) {
                d_021A8264->bytes[i] = 0;
                func_02082BCC(d_021A8264->ent[i], 0, 0x20);
            } else {
                d_021A8264->bytes[i] = r;
            }
        }
        d_021A8264->w74C += 1;
    }
}







int func_0215683C(char *a, int b)
{
    if (b > 32)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    return func_021688FC(a, b);
}








/*
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C23B8 +0004.
 * Coherent Thumb code only in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), so the ov009 shard makes that site attest as `matched`.
 */
int func_02156860(int i)
{
    return (int)d_021A8264->ent[i];
}








/*
 * Byte at +0x32c past the index of the block the module pointer holds.
 */
unsigned char func_02156874(int i)
{
    return d_021A8264->bytes[i];
}








int func_02156888(int a, int b, int c)
{
    int n = b;
    int r;
    int i;

    if (func_02156C84() != 0)
        return -4;
    if (d_021A8264->state != 6) {
        d_021A8264->cnt[2]++;
        if (d_021A8264->cnt[2] > 0x78)
            return -3;
        return -1;
    }
    func_02156C60();
    d_021A8264->f798 = 0;
    d_021A8264->b7a1 = 1;
    d_021A8264->idx = a;
    d_021A8264->n = b;
    d_021A8264->s780 = -1;
    if (c != 0)
        n = 2;
    d_021A8264->f778 = 1;
    if (a < 0) {
        r = func_0216B354(2, n, func_02156A58, (void *)func_0203D650(), func_02156B3C,
                          (void *)func_0203D650(), func_02155678, &d_021A8264->w750,
                          (void *)func_0203D650());
        d_021A8264->mode = 1;
    } else {
        r = func_0216B408(2, a, func_02156B18, 0, func_02156B3C,
                          func_0203D650(), func_02155678, &d_021A8264->w750,
                          func_0203D650());
        d_021A8264->mode = 2;
    }
    if (r == 0) {
        d_021A8264->cnt[2]++;
        if (d_021A8264->cnt[2] > 0x78)
            func_0203C9AC(0, 0, 0, 0x3f1);
        return -2;
    }
    d_021A8264->cnt[2] = 0;
    for (i = 0; i < b; i++)
        func_02156C00(i);
    func_02155374(7);
    func_02177138((int)func_02155D80, 0);
    func_02177160((int)func_02155DCC, 0);
    func_0216B634((int)func_02155E9C, 0);
    func_02177188((int)func_02155BDC, 0);
    d_021A8264->f760 = 0;
    return 0;
}








int func_02156A3C(void)
{
    if (d_021A8264 != 0)
        return d_021A8264->idx;
    return -1;
}








void func_02156A58(int a, int b, int c, int d, int e)
{
    int flag = 0;
    d_021A8264->f778 = 0;
    if (a == 0) {
        if (b == 0) {
            if (d_021A8264->b7a4 != 0 && e == -1) {
                flag = 1;
            }
            if (d_021A8264->cb2A4 != 0) {
                if (d_021A8264->cb2A4(e, func_0203D650()) == 0) {
                    flag = 1;
                }
            }
            if (d_021A8264->b7a0 != 0 || flag != 0) {
                if (e != -1) {
                    func_0216B7E0(e);
                }
            }
            d_021A8264->idx = e;
            d_021A8264->f798 = func_0216B908();
            if (d_021A8264->f798 == 1) {
                func_02155374(8);
                return;
            }
            func_02155D2C(e);
            return;
        }
        if (c == 0) {
            d_021A8264->s780 = e;
            d_021A8264->f774 = flag - 1;
        }
    }
}







/*
 * The fifth input is visibly loaded into r0 before the call.
 */
void func_02156B18(int a, int b, int c, int d, int e)
{
    d_021A8264->f778 = 0;
    if (a == 0 && b == 0)
        func_02155D2C(e);
}







/*
 * Extent follower 02156B68 already has its own matched file.
 */
void func_02156B3C(int a)
{
    d_021A8264->f774 = a;
    if (d_021A8264->cb29C != 0)
        d_021A8264->cb29C((u16)a, d_021A8264->arg2A0);
}







/*
 * extent: 8-byte thunk; larger accessor followers 02156B70 and 02156B8C excluded.
 */
int func_02156B68(char *a0)
{
    return func_021AF210();
}








/*
 * Reads the signed halfword at +0x782 of the ov009 work block held in the
 * bss pointer at 0x021A8264, or 0 when no block is allocated.  A leaf with
 * no lr-saving prologue whose only caller is in arm9 (sub_0200F698), so
 * the listing emits it as data words.
 */
s16 func_02156B70(void)
{
    if (d_021A8264 != 0)
        return d_021A8264->s782;
    return 0;
}








/*
 * Word at +0x774 of the work block, or 0 when none is allocated.
 */
int func_02156B8C(void)
{
    if (d_021A8264 != 0)
        return d_021A8264->f774;
    return 0;
}









/*
 * evidence: BL sites in ov099021BF6E0 target this Thumb word-run start;
 *   full body reads nullable global +0x780 as a signed halfword, else -1.
 */
int func_02156BA8(void)
{
    if (d_021A8264)
        return d_021A8264->s780;
    return -1;
}










/*
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C0C7C +0008.
 * Coherent Thumb code only in ov009 (ov010 decodes to a pop with no push), so
 * the ov009 shard makes that site attest as `matched`.
 */
void func_02156BC4(int v)
{
    d_021A8264->s782 = v;
}








void func_02156BD8(u32 i)
{
    void *p;
    p = d_021A8264->buf[i];
    if (p != 0) {
        func_0203D7FC(p);
        d_021A8264->buf[i] = 0;
    }
}








void func_02156C00(u32 a)
{
    RapCtx *p = func_0203D798();
    func_02156BD8(a);
    if (d_021A8264->buf[a] == 0) {
        u32 n = 0x1000;
        d_021A8264->buf[a] =
            func_0203D7C8(p->heap, n, (const char *)d_021A1C60, 0xb74);
        func_021770EC(a, (u32)d_021A8264->buf[a], n);
    }
}








/*
 * Resets the two slots and marks the flag at +0x7a6.
 */
void func_02156C60(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_02156BD8(i);
    }

    d_021A8264->b7a6 = 1;
}









/*
 * Byte at +0x7a2 of the block the module pointer holds.
 */
unsigned char func_02156C84(void)
{
    return d_021A8264->b7a2;
}








/*
 * leaf: sole unresolved overlay blocker of concrete-correct ov115/021D43CC;
 * no ARM9 blocker. Parent confirmed no active assignment owns this leaf.
 * Caller leaves its previous integer result in r0; parameter retained.
 */
void func_02156C98(int unused) { d_021A8264->b7a2 = 0; }








int func_02156CAC(void)
{
    if (d_021A8264) {
        if (d_021A8264->state == 6) return 1;
        return 0;
    }
    return 0;
}







/*
 * Recursive MATCH unblocker: callee of func_021DA434 (ov175) +0002. Coherent
 * Thumb code only in ov009 (ov010 holds the tail of another function), so the
 * ov009 shard makes that site attest as `matched`.
 */
int func_02156CD0(void)
{

    if (d_021A8264 != 0) {
        if ((u32)(d_021A8264->state - 9) <= 1)
            return 1;
    }
    return 0;
}





void func_02156CF4(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_021A8264->arr[i] != -1) {
            RapCtx *p = func_0203D798();
            if (p->cb3C != 0) {
                DwcRapWork *q = (DwcRapWork *)((int *)d_021A8264 + i);
                u32 r = func_0203D650();
                p->cb3C(q->arr[0], q->arr2[0], r);
            }
            d_021A8264->arr[i] = -1;
        }
    }
}





u32 func_02156D5C(void)
{
    return d_021A8264->err;
}





void func_02156D70(u32 v)
{
    d_021A8264->b7a5 = v;
}





/*
 * Two functions: 0x02156D84, 0x02156DB0.
 */
int func_02156D84(void)
{
    DwcRapWork *g = d_021A8264;
    if (g == 0) {
        return 1;
    }
    {
        u32 s = g->state;
        if (s == 0x13 || s == 0x10 || s == 0x14) {
            return 1;
        }
    }
    return 0;
}





void func_02156DB0(u32 v)
{
    d_021A8264->b7a3 = v;
}









/*
 * Recursive MATCH unblocker: callee of func_021DA5D0 (ov123) +004A. Coherent
 * Thumb code in ov009 (ov010 holds the tail of another function), so the ov009
 * shard makes that site attest as `matched`.
 */
void func_02156DC4(int (*cb)(u32, u32, u32, int), u32 arg)
{
    d_021A8264->cb28C = cb;
    d_021A8264->arg290 = arg;
}








/*
 * leaf: sole blocker of owned ov123 021D920C; parent ownership audit passed.
 * extent: next labelled function 02156DFC follows the 28-byte leaf.
 */
void func_02156DE0(int (*cb)(u32, u32, u32, int), u32 arg)
{
    d_021A8264->cb294 = cb;
    d_021A8264->arg298 = arg;
}









/*
 * The pooled 0x11 is the overlay id of ov017 (absolute linker symbol, see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): load
 * ov017, run func_021B6100 there, unload it.
 */
void func_02156DFC(int a)
{
    if (func_02157108(a) == 3) {
        func_02034AC4((int)abs_id_11);
        func_021B6100();
        func_02034A5C((int)abs_id_11);
    }
}








/*
 * Calls func_02156E30 with a zero third argument.
 */
void func_02156E24(int a, int b, int c)
{
    func_02156E30(a, b, 0, c);
}







/*
 * 2026-10-05 (wave D7 lane 18): the blocker func_02060F18 is now EXACT in
 *   src/matched/arm9/func_02060F18.c (old bit read first, two stores through a u16 pointer local).
 *   This file stays MATCH only until the integrator regenerates the matched-label layout; then the
 *   0x02060F18 relocation resolves and this file can be filed EXACT unchanged.
 * 2026-10-05 (wave D6 lane 19): still MATCH, blocked only by arm9 func_02060F18 (DIFF). New finding on
 *   that leaf: a u16 (or u8) RETURN type with `u32 old = *(u16 *)(p + 0x36); ... return old & 1;` stops the
 *   and-sink (gives `and; ...; mov r0,rX` as in the image), but the colours move (old in ip, v&1 in r2;
 *   image old r3, v&1 in r1). Early `old = x & 1` with u32 return still sinks. Compound `&= ~1` / `|=`
 *   on a u16 lvalue gives a 0xFFFE pool mask and lsl/lsr. Not filed.
 * 2026-10-05 (wave D5 lane 02): re-verified MATCH; the only open site is func_02060F18 (arm9), still DIFF by 13 bytes (see src/pending/arm9/func_02060F18.c).
 * 2026-10-04: 0x02060F40 now EXACT in src/matched/arm9/func_02060F40.c. 0x02060F18 (an
 * ARM setter, bit 0 of the halfword at +0x36) is parked DIFF in
 * src/pending/arm9/func_02060F18.c (13 bytes: and-sink scheduling). Bytes here are correct.
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Only open reloc is THM_CALL func_02060F18 (arm9 setter, parked DIFF in
 * src/pending/arm9/func_02060F18.c); it needs that arm9 leaf filed EXACT.
 */
void func_02156E30(u32 a, u32 b, u32 c, u32 d)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->sub_mem != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->sub_heap != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    d_021A8268->sub_mem = (u32)func_02030734(d, b - 0x80, 0, d_021A1C7C, 0x62);
    d_021A8268->sub_heap = (u32)func_02060C5C((void *)((d_021A8268->sub_mem + 0x1f) & ~0x1f), b - 0xc0, 0);
    d_021A8268->sub_id = a;
    func_02060F18((char *)d_021A8268->sub_heap, 1);
    func_02060F40((char *)d_021A8268->sub_heap, 0xea);
    d_021A8268->sub_limit = c;
}






void func_02156ED0(void)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->sub_users != 0) {
        func_0203C9AC(0, 0, 0, 0x3EE);
        d_021A8268->failed = 1;
        return;
    }
    func_02156F14();
}





void func_02156F14(void)
{
    if (d_021A8268->sub_mem != 0) {
        func_02060C94((void *)d_021A8268->sub_heap);
        func_020307B0((void *)d_021A8268->sub_mem);
        d_021A8268->sub_heap = 0;
        d_021A8268->sub_mem = 0;
        if (d_021A8268->tag != 0) {
            func_020306F0(d_021A8268->tag);
            d_021A8268->tag = 0;
        }
    }
}






/*
 * Setter after the function ending at pool 0x02156F4C, which stores to the
 * same halfword: writes its argument to +0x20 of the object d_021A8268
 * points to. Called from the ov175 root func_021D7E18 (0x021D85E0).
 */
void func_02156F50(int a)
{
    d_021A8268->tag = a;
}






u32 func_02156F5C(u32 a, u32 b, u32 c)
{
    u32 h;
    u32 r;

    if (d_021A8268->sub_heap != 0 && a == d_021A8268->sub_id && b > d_021A8268->sub_limit) {
        h = func_02087988();
        r = (u32)func_02060CA0((struct ExpHeap *)d_021A8268->sub_heap, b, c);
        func_0208799C(h);
        d_021A8268->sub_users++;
    } else {
        h = func_02087988();
        r = (u32)func_02060CA0((struct ExpHeap *)d_021A8268->heap, b, c);
        func_0208799C(h);
    }
    if (r == 0) {
        func_0200FB6C();
        func_0203C9AC(0, 0, 0, 0x3EE);
        return 0;
    }
    return r;
}




/*
 * witness:  callee 0x02060F98 is witnessed by its ARM9 entry
 *           (src/matched/arm9/func_02060F98.c, pkt_02060F98).
 */
void func_02156FDC(u32 a, void *p, int b)
{
    u32 h;

    if (p == 0) {
        return;
    }
    if (func_02060F98(p) == 0xEA) {
        if (d_021A8268->sub_heap != 0) {
            h = func_02087988();
            func_02060E30((struct ExpHeap *)d_021A8268->sub_heap, p);
            func_0208799C(h);
            d_021A8268->sub_users--;
            return;
        }
        func_0203C9AC(0, 0, 0, 0x3EE);
        return;
    }
    h = func_02087988();
    func_02060E30((struct ExpHeap *)d_021A8268->heap, p);
    func_0208799C(h);
}




void func_02157048(u32 a, u32 b)
{
    if (d_021A8268 != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    d_021A8268 = (RapHeap *)func_02030734(0, 0x24, 1, d_021A1C7C, 0x14C);
    d_021A8268->mem = (u32)func_02030734(a, b - 0x80, 0, d_021A1C7C, 0x14D);
    d_021A8268->heap = (u32)func_02060C5C((void *)((d_021A8268->mem + 0x1f) & ~0x1f), b - 0xc0, 0);
    d_021A8268->tag = 0;
}




void func_021570B8(void)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->failed == 1 || d_021A8268->sub_mem != 0) {
        func_02156F14();
    }
    func_02060C94((void *)d_021A8268->heap);
    func_020307B0((void *)d_021A8268->mem);
    func_020307B0(d_021A8268);
    d_021A8268 = 0;
}



int func_02157108(u16 a)
{
    int r;
    func_02157048(a, 0x40000);
    r = func_02059F6C(d_021A1C8C, 0x4952414A, func_02156F5C, func_02156FDC);
    func_021570B8();
    return r;
}




/*
 * Clears the 0x40-byte DWC account user-data block, then rebuilds it when
 * the check at func_02059718 (CRC validation) fails: DWC_CreateUserData,
 * then the veneer at 0x02059870 into DWCi_Acc_ClearDirty (func_0205987C).
 * Called from arm9 sub_02009800 (bl at 0x0200982C), the save-table
 * constructor at 0x0209DB98.
 */
void func_02157138(void *userdata)
{
    MIi_CpuClearFast(0, userdata, 0x40);
    if (func_02059718(userdata) == 0) {
        DWC_CreateUserData(userdata);
        func_02059870((int)userdata);
    }
}



void func_02157160(void)
{
    func_0203CA04();
    func_0203C968();
    func_02059F18();
}




/*
 * padding); the three THM_CALL sites to func_0200FB4C stay wildcarded
 * because 0x0200FB4C is an unlabelled arm9 Thumb leaf (it prints as .word
 * data after func_0200FB38), so no class attests it. The leaf verifies
 * EXACT (literal x2) as pkt_0200FB4C / src/matched/arm9/func_0200FB4C.c
 * with this body, outside this lane's write set:
 *
 *   typedef struct State { u8 pad00[0x2C]; int f2C; u8 pad30[0x29];
 *                          u8 f59; u8 f5A; u8 pad5B[5]; int f60; } State;
 *   extern State g_0214617C;           symbols: 0x0214617C data a4
 *   void func_0200FB4C(int x)
 *   {
 *       if (g_0214617C.f2C != 2) {
 *           g_0214617C.f60 = x;
 *           g_0214617C.f5A = 1;
 *           g_0214617C.f59 = 1;
 *           g_0214617C.f2C = 2;
 *       }
 *   }
 *
 * Filing that leaf makes this file (and ov135 func_022010BC) EXACT.
 */
int func_02157170(int a0, int a1)
{
    Status *st;
    int v;

    if (func_0203CD98() != 0) {
        st = (Status *)func_0203CA98();
        if (func_0200FB24() != 0) {
            switch (st->f4) {
            case 0:
                break;
            case 1:
            case 2:
                if (a0 == 0) {
                    func_02157160();
                    func_0200F83C();
                    func_0200FBA0();
                    return 1;
                }
                func_02059F18();
            case 3:
            case 4:
            case 5:
                func_0200FB38();
                func_0200FB4C(13);
                return 2;
            case 6:
                func_0200FB38();
                return 2;
            case 7:
                func_0200F7C0(15);
                return 3;
            }
        }
        v = st->fC;
        if (v == 0x3F0 || v == 0x3F1) {
            if (a1 != 0) {
                func_0200FAAC();
                func_02157160();
                func_0203C554(1);
                func_0200F83C();
                func_0200FBA0();
                return 4;
            }
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            func_0203C554(1);
            return 0;
        }
        if (v == 0x3F2 || v == 0x3F3 || v == 0x3F4 || v == 0x3F6) {
            if (a0 == 0) {
                func_02157160();
                func_0200F83C();
                func_0200FBA0();
                return 1;
            }
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
        if (v == 0x3EE || v == 0x3F7) {
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
    }
    return 0;
}
