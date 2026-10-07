/*
 * file:     scrcmd_screeneffects_p39.c
 * unit:     yes
 * function: func_021B20B0, func_021B2104, func_021B2154, func_021B21AC, func_021B2218, func_021B229C, func_021B2380, func_021B23B8, func_021B23E0, func_021B23F0, func_021B240C, func_021B2444, func_021B247C, func_021B24B8, func_021B24F4, func_021B252C, func_021B2568, func_021B25A4, func_021B25DC, func_021B2614, func_021B2650, func_021B268C, func_021B269C, func_021B26AC, func_021B26E4, func_021B271C, func_021B273C, func_021B277C, func_021B27B4, func_021B27F8, func_021B2830, func_021B2860, func_021B2874, func_021B2890, func_021B28E0, func_021B2910, func_021B2940, func_021B2970, func_021B29A0, func_021B29D0, func_021B2A00, func_021B2A30, func_021B2A60, func_021B2A90, func_021B2AA0, func_021B2AB0, func_021B2ADC, func_021B2B24, func_021B2B5C, func_021B2B94, func_021B2BD8, func_021B2BEC, func_021B2C08, func_021B2C5C, func_021B2CA0, func_021B2CE8, func_021B2D34, func_021B2D98, func_021B2DBC, func_021B2E08, func_021B2E3C, func_021B2E60, func_021B2E80, func_021B2EBC, func_021B2F18, func_021B2FB0, func_021B2FD8, func_021B30C8
 * address:  0x021B20B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B83FC  0x021B83FC  thumb  ov021
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_021C474C  0x021C474C  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021B1E74  0x021B1E74  thumb  ov021
 *   func_021B8484  0x021B8484  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021C7878  0x021C7878  thumb  ov021
 *   func_021C7220  0x021C7220  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021C7684  0x021C7684  thumb  ov021
 *   d_021D9424     0x021D9424  data   a4
 *   func_02011330  0x02011330  thumb
 *   func_021F3E24  0x021F3E24  thumb  ov039
 *   func_021F4134  0x021F4134  thumb  ov039
 *   func_021F3D74  0x021F3D74  thumb  ov039
 *   func_0201210C  0x0201210C  thumb
 *   func_021F37A4  0x021F37A4  thumb  ov040
 *   func_021F37C8  0x021F37C8  thumb  ov040
 *   func_021F37EC  0x021F37EC  thumb  ov040
 *   func_021F3834  0x021F3834  thumb
 *   func_021F3888  0x021F3888  thumb  ov042
 *   func_021F4184  0x021F4184  thumb  ov039
 *   func_021F41B0  0x021F41B0  thumb  ov038
 *   func_021F41DC  0x021F41DC  thumb  ov038
 *   func_021F398C  0x021F398C  thumb  ov043
 *   func_021F3A28  0x021F3A28  thumb  ov043
 *   func_021F3770  0x021F3770  thumb  ov044
 *   func_021F42A8  0x021F42A8  thumb  ov043
 *   func_021F3970  0x021F3970  thumb  ov044
 *   func_021F384C  0x021F384C  thumb  ov045
 *   func_021F38C4  0x021F38C4  thumb  ov045
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_021F3B5C  0x021F3B5C  thumb  ov046
 *   func_021F3AD0  0x021F3AD0  thumb  ov046
 *   func_021F3B18  0x021F3B18  thumb  ov046
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02189A24  0x02189A24  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   sub_020113D0   0x020113D0  thumb
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_021C0AA0  0x021C0AA0  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021C0820  0x021C0820  thumb  ov021
 *   func_021C978C  0x021C978C  thumb  ov021
 *   func_021C9828  0x021C9828  thumb  ov021
 *   func_021C98F4  0x021C98F4  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   func_0218C54C  0x0218C54C  thumb  ov021
 *   func_0218C574  0x0218C574  thumb  ov021
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218BACC  0x0218BACC  thumb  ov021
 *   func_0218BA98  0x0218BA98  thumb  ov021
 *   func_0218C860  0x0218C860  thumb
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_0218C990  0x0218C990  thumb  ov021
 *   func_0218C89C  0x0218C89C  thumb  ov021
 *   d_021EE720     0x021EE720  data  a2
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_0218C9A4  0x0218C9A4  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02189A1C  0x02189A1C  thumb  ov021
 *   d_021DE14C     0x021DE14C  data  a4
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_02188DB0 0x02188DB0 thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5A0  0x021BC5A0  thumb  ov021
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020127C4  0x020127C4  thumb
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_02012F08  0x02012F08  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_021B3158  0x021B3158  thumb  ov021
 *   func_021655D4  0x021655D4  thumb  ov010
 *   d_021DE210     0x021DE210  data   ov021  a1
 *   func_0218F1B4  0x0218F1B4  thumb
 *   func_0218F1AC  0x0218F1AC  thumb
 *   func_0218F848  0x0218F848  thumb
 *   func_021A3050  0x021A3050  thumb
 *   func_0218ECE4  0x0218ECE4  thumb
 *   func_0218ECB4  0x0218ECB4  thumb
 *   func_0218EC54  0x0218EC54  thumb
 *   func_0218F918  0x0218F918  thumb
 *   d_021D9708     0x021D9708  data
 */
struct Obj;
struct Stream;
struct Ctx;
struct BigObj;
struct Obj00020;
struct Node;
struct Big;
struct Sub020071CCCtrl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16_021B229C;

typedef struct { int x, y, z; } Vec;

typedef signed short   s16_021B23E0;

typedef signed char    s8;

typedef signed short   s16_021B23F0;

typedef signed short   s16_021B268C;

typedef signed short   s16_021B269C;

typedef signed short   s16_021B271C;

typedef signed int     s32;

typedef signed short   s16_021B2860;

typedef signed short   s16_021B2874;

typedef signed short   s16_021B2BD8;

typedef struct Work {
    u8  state;
    u8  sub;
    u8  b2;
    u8  b3;
    u32 f04;
    u8  f08;
    u8  pad09[3];
    u16 f0C;
    u16 pad0E;
    u32 f10;
    u32 f14;
    void *f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Work;

typedef struct { s32 x, y, z; } Vec3;

typedef struct {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 e[5];
    s32 f;
} Param;

extern void *func_0215A5EC(void *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0216DE94(void *map, u32 id);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern void *func_0219E348(void *a);
extern void func_021B83FC(struct Obj *o, u16 *out0, u16 *out1, u16 *out2);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_021C474C(void *a, u32 b, u32 c);
extern void func_0215897C(void *vm, void *task);
extern int func_021B1E74(u32 a);
extern void func_021B8484(u8 *p, u32 a, u32 b, int c);
extern void func_021B7DC0(u32, void *);
extern void func_0219E2C0(void *a, void *r);
extern u32 func_02188D38(u8 *p);
extern void func_020061E4(u32);
extern u32 func_021C7878(u32, u32, void *, u32);
extern void *func_021C7220(u32 a, u16 b, int c, u32 d);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern int func_02163E58(u32 m, Vec *pos, int *h);
extern void func_0216E084(u32 m, s16_021B229C x, s16_021B229C y, s16_021B229C z, u32 e);
extern void func_0216D89C(u32, Vec *);
extern void func_0216D8C0(u32, Vec *);
extern void *func_021C7684(u32 a, u32 b, int c, int d);
extern u16 func_02011330(struct Stream *s);
extern int func_021F3E24(void *a, u32 b);
extern void func_021F4134(void *p, u32 i);
extern void func_021F3D74(u32 a);
extern void *func_0201210C(const struct Ctx *p);
extern void func_021F37A4(u8 *p);
extern int func_021F37C8(u8 *p);
extern void *func_021F37EC(void *p, u32 i);
extern u32 func_021F3834(void *, u8, u32);
extern int func_021F3888(void *a, u32 b);
extern u32 func_021F4184(void *, u16);
extern void *func_021F41B0(void *p, int v);
extern void *func_021F41DC(void *p, int v);
extern int func_021F398C(void *a, int b);
extern u32 func_021F3A28(void *, u32);
extern u32 func_021F3770(void *, u32);
extern void func_021F42A8(void *p);
extern void func_021F3970(void *a);
extern void *func_021F384C(void *a, int b);
extern void func_021F38C4(void *a0, int a1);
extern int func_021F3A88(int a0, int a1, int a2);
extern void *func_021F3B5C(void *a, int b);
extern int func_021F3AD0(void *a, int b, int c);
extern u32 func_021F3B18(void *, u32);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_02189A24(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012984(const struct BigObj *p);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_020113D0(char *p, int val);
extern void sub_020113D0(char *p, int val);
extern void *func_02158F50(void *p);
extern void *func_021C0AA0(void *p, int a1);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021C0820(void *p, int a1, u32 n);
extern u32 func_021C978C(u32 a, u32 b, u32 c);
extern u32 func_021C9828(u32, u32, u32);
extern u32 func_021C98F4(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C654(int a, int b, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
extern void func_0218C54C(int a, int b);
extern void func_0218C574(int a, int b, int c);
extern int func_0218C7D8(void *p, int b, int c);
extern int func_0218BACC(int a, int b);
extern u32 func_0218BA98(u32, u32);
extern void func_0218C860(u32);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern int func_0218C990(unsigned char *p, int v);
extern void func_0218C89C(unsigned char *p, int v);
extern int func_0218C8D8(void *p);
extern int func_0218C9A4(void *p);
extern u32 func_02188D30(u8 *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02030DA8(int, void (*)(), u32 *, u32);
extern void func_02189A1C(u8 *p, u32 v);
extern unsigned int func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(unsigned int planes);
extern void func_02188DB0(u8 *a);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
extern u32 func_02188D20(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern void func_021BC5A0(void *p, int v);
extern void *func_02158FB4(void *p);
extern u32 func_02188C54(u8 *p);
extern u8 *func_020127C4(void *p);
extern u32 func_021904AC(u8 *p);
extern void *func_02012F08(int *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02012F2C(int *p);
extern int func_021B3158(u32 a, u32 b);
extern void func_021655D4(void);
extern u8 func_0218F1B4(u8 *p);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218F848(u8 *a);
extern u16 func_021A3050(u8 *p);
extern void func_0218ECE4(void *h, Vec3 *out);
extern void func_0218ECB4(void *h, Vec3 *out);
extern void func_0218EC54(u8 *p);
extern void func_0218F918(void *h, Param *p, int n);
int func_021B20B0(u32 a, u32 b);
int func_021B2104(u32 a, u32 b);
int func_021B2154(u32 a, u32 b);
int func_021B21AC(u32 a, u32 b);
int func_021B2218(u32 a, u32 b);
int func_021B229C(u32 a, u32 b);
int func_021B2380(u32 a, u32 b);
int func_021B23B8(u32 a, u32 b);
int func_021B23E0(u32 a, u32 b, u32 c, u32 d);
int func_021B23F0(u32 a, u32 b, u32 c, u32 d);
int func_021B240C(u32 a, u32 b);
int func_021B2444(u32 a, u32 b);
int func_021B247C(u32 a, u32 b);
int func_021B24B8(u32 a, u32 b);
int func_021B24F4(u32 a, u32 b);
int func_021B252C(u32 a, u32 b);
int func_021B2568(u32 a, u32 b);
int func_021B25A4(u32 a, u32 b);
int func_021B25DC(u32 a, u32 b);
int func_021B2614(u32 a, u32 b);
int func_021B2650(u32 a, u32 b);
int func_021B268C(u32 a, u32 b, u32 c, u32 d);
int func_021B269C(u32 a, u32 b, u32 c, u32 d);
int func_021B26AC(u32 a, u32 b);
int func_021B26E4(u32 a, u32 b);
int func_021B271C(u32 a, u32 b, u32 c, u32 d);
int func_021B273C(int a, int b);
int func_021B277C(u32 a, u32 b);
int func_021B27B4(int a, int b);
int func_021B27F8(u32 a, u32 b);
int func_021B2830(u32 a);
int func_021B2860(u32 a, u32 b, u32 c, u32 d);
int func_021B2874(u32 a, u32 b, u32 c, u32 d);
int func_021B2890(u32 a, u32 b);
int func_021B28E0(u32 a, u32 b);
int func_021B2910(u32 a, u32 b);
int func_021B2940(u32 a, u32 b);
int func_021B2970(u32 a, u32 b);
int func_021B29A0(u32 a, u32 b);
int func_021B29D0(u32 a, u32 b);
int func_021B2A00(u32 a, u32 b);
int func_021B2A30(u32 a, u32 b);
int func_021B2A60(u32 a, u32 b);
int func_021B2A90(u32 a);
int func_021B2AA0(void *p);
int func_021B2AB0(u32 a, u32 b);
int func_021B2ADC(int a, int b);
int func_021B2B24(u32 a, u32 b);
int func_021B2B5C(u32 a, u32 b);
int func_021B2B94(int a, int b);
int func_021B2BD8(u32 a);
int func_021B2BEC(int a, int b, int c, int d);
int func_021B2C08(int a, int b);
int func_021B2C5C(int a, int b);
int func_021B2CA0(int a, int b);
int func_021B2CE8(int a, int b);
int func_021B2D34(int a, int b);
int func_021B2D98(u32 a, u32 b);
int func_021B2DBC(int a, int b);
int func_021B2E08(u32 a, u32 b);
int func_021B2E3C(u32 a, u32 b);
int func_021B2E60(u32 a, u32 b);
int func_021B2E80(u32 a, u32 b);
void func_021B2EBC(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021B2F18(int p, int *q);
int func_021B2FB0(u32 a, u32 b);
int func_021B2FD8(u32 a, u32 b);
void func_021B30C8(u32 *p, u32 b, void *h);
extern const Vec d_021D9424;
extern u16 d_021EE720;
extern u8 d_021DE14C;
extern u8 d_021DE210[];
extern Vec3 d_021D9708[];


int func_021B20B0(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = (u32)func_0216DE94(func_0215A5EC((void *)b), func_02159B10((void *)a, (void *)b));
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    func_021B83FC(func_0219E348((void *)h), x, y, z);
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B2104(u32 a, u32 b)
{
    void *t;
    u32 v;
    u32 m;
    u32 o;
    void *w;

    w = func_0215A5DC((void *)b);
    t = func_0215A5F4((void *)b);
    m = (u32)func_0215A5EC((void *)b);
    o = (u32)func_0216DE94((void *)m, func_02159B10((void *)a, (void *)b));
    v = (u32)func_021C474C(w, ((u32 *)func_02158F58((int)t))[1], o);
    func_0215897C(t, (void *)v);
    return 1;
}


int func_021B2154(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = func_021B1E74(b);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0219E348((void *)h);
    func_021B8484((u8 *)o, x, y, z);
    func_021B7DC0(o, buf);
    func_0219E2C0((void *)h, buf);
    return 0;
}


int func_021B21AC(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = (u32)func_0216DE94(func_0215A5EC((void *)b), func_02159B10((void *)a, (void *)b));
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0219E348((void *)h);
    func_021B8484((u8 *)o, x, y, z);
    func_021B7DC0(o, buf);
    func_0219E2C0((void *)h, buf);
    return 0;
}


int func_021B2218(u32 a, u32 b)
{
    int v[3];
    void *t;
    u32 o;
    u32 e;
    u32 g;
    u32 p;

    t = func_0215A5F4((void *)b);
    o = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0216DE94(func_0215A5EC((void *)b), o);
    e = ((u32 *)func_02158F58((int)t))[1];
    g = func_02188D38((u8 *)e);
    func_020061E4(0x676);
    v[0] = 0;
    v[1] = 0x96 << 12;
    v[2] = 0;
    p = func_021C7878(e, 0x18, v, o);
    func_021C6DE0((u8 *)g, (u32 *)func_021C7220(e, 0x18, 3, o), 0);
    func_021C6DE0((u8 *)g, (u32 *)p, 0);
    return 0;
}


int func_021B229C(u32 a, u32 b)
{
    Vec pos;
    Vec rot;
    int h;
    u32 k0, k1, k2, k3, o, e, g;
    void *t;

    t = func_0215A5F4((void *)b);
    k0 = func_02159B10((void *)a, (void *)b);
    k1 = func_02159B10((void *)a, (void *)b);
    k2 = func_02159B10((void *)a, (void *)b);
    k3 = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0216DE94(func_0215A5EC((void *)b), k0);
    e = ((u32 *)func_02158F58((int)t))[1];
    g = func_02188D38((u8 *)e);
    if (o == 0) {
        return 0;
    }
    h = 0;
    pos.x = (k1 << 16) + 0x8000;
    pos.y = 0xFA000;
    pos.z = (k2 << 16) + 0x8000;
    func_02163E58(o, &pos, &h);
    pos.y = h;
    func_0216E084(o, k1, (pos.y >> 4) / 0x1000, k2, k3);
    func_0216D89C(o, &pos);
    rot = d_021D9424;
    func_0216D8C0(o, &rot);
    func_021C6DE0((u8 *)g, (u32 *)func_021C7684(e, o, 0x28, 0xfa), 0);
    return 0;
}


int func_021B2380(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = func_021F3E24(d, k);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B23B8(u32 a, u32 b)
{
    void *d;
    u8 k;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    k = func_02011330((struct Stream *)a);
    func_021F4134(d, k);
    return 0;
}


int func_021B23E0(u32 a, u32 b, u32 c, u32 d)
{
func_021F3D74((u32)func_0215A5DC((void *)b));
return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B23F0(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4((void *)b);
func_021F37A4(func_0201210C(func_0215A5DC((void *)b)));
return 0;
}


int func_021B240C(u32 a, u32 b)
{
    void *w;
    u16 *o;

    func_0215A5F4((void *)b);
    w = func_0201210C(func_0215A5DC((void *)b));
    o = func_02159AE8((void *)a, (void *)b);
    if (func_021F37C8(w) != 0) {
        *o = 1;
    } else {
        *o = 0;
    }
    return 0;
}


int func_021B2444(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = (u32)func_021F37EC(d, k);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B247C(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 flag = 1;
    u32 r = func_021F3834(d, k, flag);

    if (r == 0) {
        return flag;
    }
    func_0215897C(s, (void *)r);
    return flag;
}


int func_021B24B8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = func_021F3834(d, k, 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B24F4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = func_021F3888(d, k);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B252C(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F4184(d, *func_02159AE8((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B2568(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F41B0(d, *func_02159AE8((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B25A4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F41DC(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B25DC(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F398C(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B2614(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3A28(d, func_02011330((struct Stream *)a) ? 1 : 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B2650(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3770(d, func_02011330((struct Stream *)a) ? 1 : 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B268C(u32 a, u32 b, u32 c, u32 d)
{
func_021F42A8(func_0215A5DC((void *)b));
return 0;
}


int func_021B269C(u32 a, u32 b, u32 c, u32 d)
{
func_021F3970(func_0215A5DC((void *)b));
return 0;
}


int func_021B26AC(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F384C(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B26E4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3888(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B271C(u32 a, u32 b, u32 c, u32 d)
{
func_021F38C4(func_0215A5DC((void *)b), func_02011330((struct Stream *)a));
return 0;
}


int func_021B273C(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int p = func_02011330((struct Stream *)a);
    int q = func_02011330((struct Stream *)a);
    int r = func_021F3A88((int)y, p, q);

    if (r == 0) {
        return 1;
    }
    func_0215897C(x, (void *)r);
    return 1;
}


int func_021B277C(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F3B5C(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B27B4(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = func_021F3AD0(y, p, q);

    if (r == 0) {
        return 1;
    }
    func_0215897C(x, (void *)r);
    return 1;
}


int func_021B27F8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3B18(d, func_02159B10((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}


int func_021B2830(u32 a)
{
    u32 w = func_02011330((struct Stream *)a);
    u32 x = func_02011330((struct Stream *)a);
    u32 y = func_02011330((struct Stream *)a);
    u32 z = func_02011330((struct Stream *)a);

    func_0204E720(w, x, y, z);
    return 0;
}


int func_021B2860(u32 a, u32 b, u32 c, u32 d)
{
if (func_0204E804() != 1) {
    return 1;
}
return 0;
}


int func_021B2874(u32 a, u32 b, u32 c, u32 d)
{
if (func_02189A24(func_0201210C(func_0215A5DC((void *)b))) != 1) {
    return 1;
}
return 0;
}


/*
 * func_021BE92C reads its last two stack arguments with ldrb, so they are
 * u8 parameters: the narrowing then happens once at the call, scheduled
 * the way the original has it. A (u8) cast at the call site or a u8 local
 * feeding int parameters schedules the zero store after the shift pair.
 * Addresses are Black-image addresses.
 */
int func_021B2890(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 p;
    void *q;
    u32 z;

    x = func_0215A5F4((void *)b);
    y = func_0215A5DC((void *)b);
    p = (u32)func_020120F4(y);
    q = func_0201210C((void *)y);
    z = func_02012984((const struct BigObj *)p);
    func_0215897C(x, (void *)func_021BE92C(y, (int)q, 3, 0, 0, z, z));
    return 0;
}


int func_021B28E0(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 0, 0, 0);
    return 0;
}


int func_021B2910(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 0, 0, 0);
    return 0;
}


int func_021B2940(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 1, 0, 0);
    return 0;
}


int func_021B2970(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 0, 1, 0);
    return 0;
}


int func_021B29A0(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 1, 1, 0);
    return 0;
}


int func_021B29D0(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 2, 0, 0);
    return 0;
}


int func_021B2A00(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 3, 0, 0);
    return 0;
}


int func_021B2A30(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 2, 1, 0);
    return 0;
}


int func_021B2A60(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((void *)d), 3, 1, 0);
    return 0;
}


int func_021B2A90(u32 a)
{
    func_020113D0((char *)a, (u32)func_021B2860);
    return 1;
}


int func_021B2AA0(void *p)
{
    sub_020113D0(p, (int)func_021B2874);
    return 1;
}


int func_021B2AB0(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);

    func_0215897C(s, func_021C0AA0(d, (int)func_02158F50((void *)s)));
    return 1;
}


int func_021B2ADC(int a, int b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);
    int p = (int)func_02159B10((void *)a, (void *)b);

    func_02188CB4(func_0201210C((void *)y));
    func_0215897C(x, func_021C0820(y, (int)func_02158F50((void *)x), (unsigned char)p));
    return 1;
}


int func_021B2B24(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);
    void *w = func_0201210C((void *)d);

    func_0215897C(s, (void *)func_021C978C((u32)func_02158F50((void *)s), (u32)d, (u32)w));
    return 1;
}


int func_021B2B5C(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);
    void *w = func_0201210C((void *)d);

    func_0215897C(s, (void *)func_021C9828((u32)func_02158F50((void *)s), (u32)d, (u32)w));
    return 1;
}


int func_021B2B94(int a, int b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);
    void *t = func_0201210C((void *)y);
    int p = (int)func_02159B10((void *)a, (void *)b);

    func_0215897C(x, (void *)func_021C98F4((u32)func_02158F50((void *)x), (u32)y, (u32)t, p));
    return 1;
}


int func_021B2BD8(u32 a)
{
return func_0218DC6C((u8 *)func_02188C98(func_0201210C(func_0215A5DC((void *)a))));
}


/*
 * Leaf filed for lane S20 (blocker of 021B2C08 and friends).
 *
 * Addresses are Black-image addresses.
 */
int func_021B2BEC(int a, int b, int c, int d)
{
    int buf[3];

    buf[0] = c << 16;
    buf[1] = 0;
    buf[2] = d << 16;
    return func_0218C654(a, b, (int)buf);
}


int func_021B2C08(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C69C((unsigned char *)h, t, 0, 1);
        func_0218C69C((unsigned char *)h, t, 0, 3);
    }
    return 0;
}


int func_021B2C5C(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C69C((unsigned char *)h, t, 0, 2);
    }
    return 0;
}


int func_021B2CA0(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int s = (int)func_02159B10((void *)a, (void *)b);
    int t = func_021B2BEC(func_021B2BD8(b), p, q, r);

    if (t) {
        func_0218C54C(t, s);
    }
    return 0;
}


int func_021B2CE8(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int s = (int)func_02159B10((void *)a, (void *)b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C574(h, t, s);
    }
    return 0;
}


int func_021B2D34(int a, int b)
{
    unsigned short *out = func_02159AE8((void *)a, (void *)b);
    int f = func_02159B10((void *)a, (void *)b);
    int x = func_02159B10((void *)a, (void *)b);
    int y = func_02159B10((void *)a, (void *)b);
    int h;
    int buf[3];

    h = func_0218DC6C((u8 *)func_02188C98(func_0201210C(func_0215A5DC((void *)b))));
    buf[0] = x << 16;
    buf[1] = 0;
    buf[2] = y << 16;
    *out = func_0218BACC(h, func_0218C7D8((void *)h, f, (int)buf));
    return 0;
}


int func_021B2D98(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 o = func_0218BA98(func_021B2BD8(b), x);

    if (o != 0) {
        func_0218C860(o);
    }
    return 0;
}


int func_021B2DBC(int a, int b)
{
    unsigned short v;
    int p = func_02159B10((void *)a, (void *)b);
    int q = func_02159B10((void *)a, (void *)b);
    int h = func_0218BA98(func_021B2BD8(b), p);

    if (h) {
        func_0218C88C((unsigned char *)h, q, 0);
        if (func_0218C990((unsigned char *)h, (int)(&v))) {
            func_020061E4(v);
        }
    }
    return 0;
}


int func_021B2E08(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 y = func_02159B10((void *)a, (void *)b);
    u32 o = func_0218BA98(func_021B2BD8(b), x);

    if (o != 0) {
        func_0218C88C((unsigned char *)o, y, 2);
    }
    return 0;
}


int func_021B2E3C(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 o = func_0218BA98(func_021B2BD8(b), x);

    if (o != 0) {
        func_0218C89C((unsigned char *)o, 3);
    }
    return 0;
}


int func_021B2E60(u32 a, u32 b)
{
    d_021EE720 = func_02159B10((void *)a, (void *)b);
    func_020113D0((char *)a, (u32)func_021B2E80);
    return 1;
}


int func_021B2E80(u32 a, u32 b)
{
    u32 o = func_0218BA98(func_021B2BD8(b), d_021EE720);

    if (o == 0) {
        return 1;
    }
    if (func_0218C8D8((void *)o) == 0) {
        return 0;
    }
    if (func_0218C9A4((void *)o) == 0) {
        return 1;
    }
    return 0;
}


void func_021B2EBC(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    int h = func_02188D30((u8 *)b);
    u32 *w = func_02030734(4, 0x18, 1, (const char *)&d_021DE14C, 0x369);

    func_02030DA8(h, func_021B2F18, w, 0);
    func_02189A1C((u8 *)b, 1);
    w[5] = 0;
    w[0] = a;
    w[1] = b;
    w[2] = d;
    w[3] = e;
    w[4] = c;
}


void func_021B2F18(int p, int *q)
{
    int x;
    int y;
    int z;
    int w;
    int c;
    void *t;

    switch (q[5]) {
    case 0:
        if ((unsigned int)q[4] <= 1) {
            x = -1;
        } else {
            x = 4;
        }
        if (q[4] == 0 || q[4] == 2) {
            y = 16;
            z = 0;
            t = (void *)func_02043658();
            func_02188DA0();
            func_02043534((unsigned int)t);
            func_02188DB0((u8 *)q[1]);
        } else {
            y = 0;
            z = 16;
        }
        if (q[2] == 0) {
            w = 3;
        } else {
            w = 12;
        }
        func_0204E720(w, y, z, x);
        q[5] = q[5] + 1;
        break;
    case 1:
        c = 0;
        if (q[3] == 1) {
            c = 1;
        }
        if (func_0204E804() == 0) {
            c = 1;
        }
        if (c) {
            func_02189A1C((u8 *)q[1], 0);
            func_02030EAC((struct Node *)p);
            func_020307B0(q);
        }
        break;
    }
}


int func_021B2FB0(u32 a, u32 b)
{
    void *w = func_0201210C(func_0215A5DC((void *)b));
    u32 x = func_02188D20(w);

    func_021BC5A0((void *)x, func_02188C9C(w));
    return 0;
}


int func_021B2FD8(u32 a, u32 b)
{
    u32 v;
    void *t;
    u32 s;
    void *x;
    Work **slot;
    u32 y;
    u32 z;
    Work *w;

    v = func_02159B10((void *)a, (void *)b);
    func_02159AE8((void *)a, (void *)b);
    t = func_0215A5DC((void *)b);
    s = (u32)func_020120F4(t);
    x = func_0201210C((void *)t);
    slot = func_02158FB4(func_0215A5F4((void *)b));
    y = func_02188C54(x);
    z = (u32)func_020127C4((void *)s);
    w = func_02030734(4, 0x214, 1, (const char *)d_021DE210, 0xFC);
    *slot = w;
    w->f10 = func_021904AC((u8 *)y);
    w->f14 = (u32)func_02012F08((int *)s);
    w->f0C = 0x15;
    w->f18 = func_0201292C((const struct BigObj *)s);
    w->f20 = (u32)func_020071CC((struct Sub020071CCCtrl *)func_02012EBC((struct Big *)s), 0x3a);
    w->f1C = (u32)func_02012F2C((int *)s);
    w->f24 = z;
    switch (v) {
    case 0xFF:
        w->b2 = v;
        break;
    case 0xFE:
        w->b2 = v;
        break;
    case 0xFD:
        w->b2 = v;
        break;
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
        w->b2 = v;
        break;
    default:
        w->b2 = (u8)v;
        w->b3 = (u8)v;
        break;
    }
    func_020113D0((char *)a, (int)func_021B3158);
    if (v != 0xFE && v != 0xFD) {
        func_021655D4();
    }
    return 1;
}


void func_021B30C8(u32 *p, u32 b, void *h)
{
    Param s;
    int i;

    p[1] = func_0218F1B4(h);
    func_0218F1AC(h, 0);
    func_0218F848(h);
    i = func_021A3050(func_02188CB4((void *)b));
    func_0218ECE4(h, &s.a);
    func_0218ECB4(h, &s.b);
    func_0218EC54(h);
    s.b.x += d_021D9708[i].x;
    s.b.y += d_021D9708[i].y;
    s.b.z += d_021D9708[i].z;
    s.e[0] = 0;
    s.e[1] = 0;
    s.e[2] = 0;
    s.e[3] = 0;
    s.e[4] = 0;
    s.f = 1;
    func_0218F918(h, &s, 10);
}
