/*
 * file:     field_player_grid_event.c
 * unit:     yes
 * function: func_021BEE74, func_021BEEB4, func_021BEF08, func_021BEF8C, func_021BF0A4, func_021BF0E4, func_021BF130, func_021BF19C, func_021BF208, func_021BF274, func_021BF2E0, func_021BF348, func_021BF3BC, func_021BF430, func_021BF4A4, func_021BF518, func_021BF564, func_021BF584, func_021BF58C, func_021BF5B4, func_021BF5E8, func_021BF61C, func_021BF644, func_021BF66C, func_021BF694, func_021BF76C, func_021BF7F8, func_021BF860, func_021BF874, func_021BF898, func_021BF8DC, func_021BF8EC, func_021BF978, func_021BF9E0, func_021BF9F4, func_021BFA18, func_021BFA5C, func_021BFA6C, func_021BFB90, func_021BFC98, func_021BFD34, func_021BFD70, func_021BFDA0, func_021BFDD0, func_021BFE00, func_021BFE2C, func_021C00C8, func_021C0140, func_021C017C, func_021C01E4, func_021C01F8, func_021C021C, func_021C029C, func_021C02F8, func_021C0360, func_021C0374, func_021C0398, func_021C04C0, func_021C0598, func_021C05D4, func_021C0628, func_021C0674, func_021C0688, func_021C068C, func_021C06A8, func_021C06B4, func_021C06C0, func_021C06CC, func_021C06E0, func_021C0780, func_021C0808, func_021C080C, func_021C0810, func_021C0820, func_021C0844, func_021C0904, func_021C0988, func_021C09A8, func_021C09B0, func_021C0A10, func_021C0A48, func_021C0A70, func_021C0AA0, func_021C0AC0, func_021C0B3C, func_021C0BD8, func_021C0BE8, func_021C0C48, func_021C0C80, func_021C0C94, func_021C0CA4, func_021C0CE4, func_021C0D08, func_021C0DDC, func_021C0E4C, func_021C0E98, func_021C1024, func_021C1094, func_021C10A0, func_021C10B4, func_021C1228, func_021C12C4, func_021C12D0, func_021C12E4, func_021C1318, func_021C146C, func_021C14F8, func_021C157C, func_021C161C, func_021C1670, func_021C16AC
 * address:  0x021BEE74
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
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_0208068C  0x0208068C  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_02166B0C  0x02166B0C  thumb  ov010
 *   d_021D9F50     0x021D9F50  data  ov021  a4
 *   func_02189A58  0x02189A58  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02166B2C  0x02166B2C  thumb  ov010
 *   func_02188DF0  0x02188DF0  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021903CC  0x021903CC  thumb  ov021
 *   func_021902AC  0x021902AC  thumb  ov021
 *   func_0218774C  0x0218774C  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_021877A8  0x021877A8  thumb  ov020
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_02043658  0x02043658  arm
 *   func_02043668  0x02043668  arm
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_02188DB0  0x02188DB0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021C7684  0x021C7684  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   d_021DA080     0x021DA080  data   a4
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218FE80 0x0218FE80 thumb ov021
 *   func_0218FEA0 0x0218FEA0 thumb ov021
 *   func_0218FEA4 0x0218FEA4 thumb ov021
 *   func_0218FE78 0x0218FE78 thumb ov021
 *   func_0218FEC0 0x0218FEC0 thumb ov021
 *   func_0218FF00 0x0218FF00 thumb ov021
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_021C72AC  0x021C72AC  thumb  ov021
 *   func_021BE9A0 0x021BE9A0 thumb ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454 0x0216D454 thumb ov010
 *   func_0216D480 0x0216D480 thumb ov010
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C584  0x0218C584  thumb  ov021
 *   func_0218C724  0x0218C724  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021C754C  0x021C754C  thumb  ov021
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7814  0x021C7814  thumb  ov021
 *   func_020061F8  0x020061F8  thumb
 *   func_0218C860  0x0218C860  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021C7D28  0x021C7D28  thumb  ov021
 *   func_021C77D8  0x021C77D8  thumb  ov021
 *   sub_02030734  0x02030734  arm
 *   d_021DE3A0  0x021DE3A0  data  ov021  a1
 *   d_021DA08C  0x021DA08C  data
 *   ov021_id  0x00000015  data
 *   func_0200FB38  0x0200FB38  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02012124  0x02012124  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02164FC4  0x02164FC4  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0218C6D0  0x0218C6D0  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218C7F0  0x0218C7F0  thumb  ov021
 *   d_021DA098  0x021DA098  data  ov021  a4
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   d_021DA0E0     0x021DA0E0  data  a4
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_021A5728  0x021A5728  thumb  ov021
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A44BC  0x021A44BC  thumb  ov021
 *   func_021A448C  0x021A448C  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0216D91C  0x0216D91C  thumb  ov010
 *   func_0216D924  0x0216D924  thumb  ov010
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 *   func_021C19B4  0x021C19B4  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_021A3990  0x021A3990  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5408  0x021A5408  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216E57C  0x0216E57C  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DE3AC     0x021DE3AC  data  ov021  a4
 *   func_021A3068  0x021A3068  thumb  ov021
 *   func_021A36E0  0x021A36E0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EE8  0x02030EE8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021A2F8C  0x021A2F8C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AAB1C  0x021AAB1C  thumb  ov021
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBB8  0x021ACBB8  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A35A0  0x021A35A0  thumb  ov021
 *   func_021C1988  0x021C1988  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021AD564  0x021AD564  thumb  ov021
 *   func_021C6B18  0x021C6B18  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021AD5CC  0x021AD5CC  thumb  ov021
 *   func_021ABE64  0x021ABE64  thumb  ov021
 */
#include "../../matched/include/Obj12906.h"
#include "../../matched/include/Obj06060.h"
#include "../../matched/include/Obj20152.h"
#include "../../matched/include/Obj01504.h"
#include "../../matched/include/Obj07553.h"
#include "../../matched/include/Obj05067.h"
#include "../../matched/include/Obj12907.h"
#include "../../matched/include/Obj12908.h"
#include "../../matched/include/Obj12909.h"
#include "../../matched/include/Obj12910.h"
#include "../../matched/include/Obj12911.h"
#include "../../matched/include/Obj09668.h"
#include "../../matched/include/Obj12121.h"
#include "../../matched/include/Obj01860.h"
#include "../../matched/include/Obj12122.h"
#include "../../matched/include/Obj01861.h"
#include "../../matched/include/Obj02723.h"
#include "../../matched/include/Obj12123.h"
#include "../../matched/include/Obj05073.h"
#include "../../matched/include/Obj20154.h"
#include "../../matched/include/Obj02724.h"
#include "../../matched/include/Obj12124.h"
#include "../../matched/include/Obj01863.h"
#include "../../matched/include/Obj18267.h"
#include "../../matched/include/Obj18268.h"
#include "../../matched/include/Obj18269.h"
#include "../../matched/include/Obj18270.h"
#include "../../matched/include/Obj00707.h"
#include "../../matched/include/Obj02394.h"
#include "../../matched/include/Obj20159.h"
#include "../../matched/include/Obj00959.h"
#include "../../matched/include/Obj01505.h"
#include "../../matched/include/Obj06070.h"
#include "../../matched/include/Obj00235.h"
#include "../../matched/include/Obj05075.h"
#include "../../matched/include/Obj18274.h"
#include "../../matched/include/Obj03610.h"
#include "../../matched/include/Obj18276.h"
#include "../../matched/include/Obj01665.h"
#include "../../matched/include/Obj01359.h"
#include "../../matched/include/Obj01506.h"
#include "../../matched/include/Obj00657.h"
#include "../../matched/include/Obj04270.h"
#include "../../matched/include/Obj04271.h"
#include "../../matched/include/Obj00129.h"

struct DispConfig;
struct Evt;
struct Desc;
struct Obj;
struct Obj00020;
struct VecFx32;
struct BigObj;
struct Ctx;
struct IcaAnime;
struct Mtx33;
struct Blk;
struct Actor;
struct S02030EE8;
struct Self;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { u32 w[4]; } S16;

typedef struct {
    void *x0;
    u32 x4;
} Work_021BF58C;

typedef struct {
    int f0;
    int f4;
    unsigned char pad8[0x54];
    int f5C;
    int f60;
    int f64;
} Work_021BF5B4;

typedef struct { u32 f0; u32 f4; u32 pad[21]; u32 f5C; u32 f60; u32 f64; } X;

typedef struct {
    int f0;
    int f4;
} Work_021BEE74;

typedef struct {
    int f0;
    int f4;
} Ent;

typedef struct { int x, y, z; } Vec;

typedef struct {
    int w[8];
} V8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    V8 v10;
    V8 v30;
    int f50;
    int f54;
    int f58;
} Q;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } V3;

typedef struct { u32 w[8]; } Blk32;

typedef struct { int x, y, w, h, f10, active; } Rect;

typedef struct {
    u32 n;
    u8 *e;
} Tab;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int used;
    int f18;
} Slot;

typedef struct {
    int n;
    Slot *e;
} SlotTable;

typedef struct {
    int pad[4];
    int v;
    int pad2[2];
} E;

typedef struct { int x, y, z; } Vec3;

typedef struct {
    u16 state;
    s16 count;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 padA;
    u32 fC;
    u8 *f10;
    u32 f14;
} Work_021C0810;

extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_0208068C(u32 a);
extern void func_02087AE4(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207FDCC(u32 a);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02166B0C(void);
extern void func_02189A58(u8 *p, u32 v);
extern void func_0207D63C(int a, int b, int c, int d, int e);
extern void func_02082AC0(u32 a, u32 b, u32 c);
extern void func_02080B98(void);
extern void func_02166B2C(void);
extern void func_02188DF0(u8 *a);
extern u32 func_02188C54(u8 *p);
extern int func_021903CC(u8 *p);
extern void func_021902AC(u16 *p, int v);
extern void *func_0218774C(int a, int b, u8 c, u8 d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f);
extern u16 func_02188C84(u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern u32 func_02043658(void);
extern u32 func_02043668(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 v);
extern void func_020435F4(u32 v);
extern void func_02188DB0(u8 *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188C58(void *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02188D38(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0216D8C0(void *, Vec *);
extern void func_0216D410(void *a0, u32 a1);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_021C7684(u32 a, u32 b, int c, int d);
extern u32 func_021C6DE0(u8 *p, u32 *a, u32 b);
extern int func_021C6E48(int);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, u32 v);
extern void func_0218FEA4(int);
extern void func_0218FE78(int, V8 *);
extern void func_0218FEC0(u8 *o);
extern int func_0218FF00(u32 a);
extern u32 func_0218FE98(u32);
extern void func_0218FF20(u8 *a);
extern void *func_021C72AC(u32 a, u16 b, int c, int d);
extern void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5);
extern u32 func_02188CD0(u8 *p);
extern void func_021AC528(u32 a, u32 b);
extern void *func_021C71D4(unsigned int a, unsigned int b, unsigned int c);
extern int func_021C7858(unsigned int a, unsigned int b, unsigned int c);
extern void func_020061E4(u32 a);
extern int func_0216D454(void *);
extern int func_0216D480(char *p);
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int *func_0218C584(int, int *, int, int *);
extern u8 *func_0218C724(u8 *owner, u32 *obj);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern u32 func_020307B0(void *p);
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern int func_021C754C(int, int, int *);
extern int func_0218C8FC(unsigned char *p, int i);
extern unsigned int func_0203630C(void);
extern void *func_0216D568(void *p, u32 v);
extern int func_021C6F00(int, int, int);
extern int func_021C7814(int, int, int, int, int);
extern void func_020061F8(int);
extern void func_0218C860(int);
extern void *func_021C7260(u32 a, u16 b, int c);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021C7D28(int a, int b, u16 c, u16 d);
extern u32 func_021C77D8(u32 a, u32 b);
extern void *sub_02030734(u32 heap, u32 size, int align, const char *file, unsigned short line);
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_0202647C(void *obj);
extern void func_0200FB38(void);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void *func_02188C7C(unsigned char *p);
extern int func_02188BE8(void *);
extern void func_0216D9A0(void *);
extern u32 *func_0216D9E4(void *c);
extern int func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0200FBA0(void);
extern void func_02012124(struct Ctx *p, u32 v);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02026474(void *obj);
extern u32 func_02026454(void *obj);
extern void func_02164FC4(char *p);
extern void *func_02188C80(void *p);
extern void *func_02029830(void *a, u32 b);
extern void *func_02029620(void *a, u32 b, u32 c);
extern void func_0218C6D0(int *p, int b);
extern void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
extern void func_0207C9D0(u8 *dst, u8 *src, int *v);
extern u8 *func_0218C7F0(u8 *owner, u32 x, struct Blk *src);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
extern int func_0218C8D8(void *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *);
extern u32 func_021A5728(u8 *p);
extern void *func_021A572C(u8 *p);
extern u16 func_021A3AB8(u32 a, u32 v);
extern int func_021A44BC(int a, int b);
extern int func_021A448C(u32 *p, int a);
extern void func_0216D88C(const struct Actor *obj, struct VecFx32 *out);
extern void func_02164208(int dir, int *p, int amt);
extern u8 func_0216D91C(int a0);
extern u8 func_0216D924(int a0);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB11C(u32 attr);
extern int func_021AB2DC(u16 id);
extern u32 func_021C19B4(u8 *a, u32 b);
extern u16 func_0216D598(void *p);
extern int func_0216E5FC(u16 id);
extern u32 func_021A395C(u8 *p);
extern u32 func_021639C0(u32 a, u32 b);
extern u32 func_021A3990(u8 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_021A3960(unsigned char *p);
extern int func_0216D3CC(int a0);
extern int func_021A5408(u8 *a);
extern int func_02197E7C(int a, int b);
extern int func_02163E58(u32 o, Vec3 *v, int *out);
extern int func_0216DB4C(void *a0, int a1);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern void func_0216D89C(u32 o, Vec3 *v);
extern void func_0216D8E0(u32 o, void *p);
extern void func_0216E014(void *a, int *p, int b);
extern void func_0216E57C(void *a);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_021A3068(u8 *p);
extern u32 func_021A36E0(u8 *p);
extern int func_021AB2E8(int id);
extern u32 func_02188D30(u8 *p);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_02030EAC(u32);
extern u16 func_0216D5F8(void *obj);
extern int func_0216D83C(void *obj);
extern int func_0216D86C(void *obj);
extern void func_02164280(int x, int y, int *p);
extern u32 func_021ACB38(u32, u32, Vec *, void *, int);
extern void func_021A2F8C(u8 *a, u32 b);
extern u32 func_02188CE8(u8 *p);
extern int func_021AA900(struct Self *self, short *pos);
extern void func_021AAB1C(void *p, int b);
extern u32 func_021A2F98(u8 *a);
extern void func_021ACBB8(u32 a, u8 v);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *a);
extern void func_021A35A0(u32 *p, int a);
extern void func_021C1988(void *a, u16 *s);
extern void func_021ABE30(int a, int *b, int c);
extern u32 func_021AD564(u32 a, u32 b, u32 c);
extern void func_021C6B18(u32 a, u16 b, u32 c);
extern void func_021AC154(u32 a);
extern int func_0209C0A4(int a, int b);
extern int func_021AD5CC(u32 a);
extern void func_021ABE64(u32 a, int b);
int func_021BEE74(u32 p0, int *st, u8 *q);
int func_021BEEB4(u32 p0, int *st, u8 *q);
int func_021BEF08(u32 p0, int *st, u8 *q);
int func_021BEF8C(u32 p0, int *st, u8 *q);
int func_021BF0A4(u32 p0, int *st, u8 *q);
int func_021BF0E4(u32 p0, int *st, u8 *q);
int func_021BF130(u32 p0, int *st, u8 *q);
int func_021BF19C(u32 p0, int *st, u8 *q);
int func_021BF208(u32 p0, int *st, u8 *q);
int func_021BF274(u32 p0, int *st, u8 *q);
int func_021BF2E0(u32 p0, int *st, u8 *q);
int func_021BF348(u32 p0, int *st, u8 *q);
int func_021BF3BC(int a, int *s, int *q);
int func_021BF430(int a, int *s, int *q);
int func_021BF4A4(int a, int *s, int *q);
int func_021BF518(int a, int *s, int *q);
void func_021BF564();
void func_021BF584(u8 *a0);
void *func_021BF58C(int a, void *p, int c);
void *func_021BF5B4(int a, int b, int c, int d, int e, int f);
u32 func_021BF5E8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void *func_021BF61C(int a, int b, int c);
int func_021BF644(int a, int b, int c);
void *func_021BF66C(int a0, void *p, int a2);
int func_021BF694(int a, int *s, int *q);
int func_021BF76C(void *task, int *state, void **q);
void func_021BF7F8(Q *q);
int func_021BF860(void **a);
int func_021BF874(void **a);
void *func_021BF898(int *q);
void func_021BF8DC(u8 *p);
int func_021BF8EC(void *task, int *state, void **q);
void func_021BF978(Q *q);
int func_021BF9E0(void **a);
int func_021BF9F4(void **a);
void *func_021BFA18(int *q);
void func_021BFA5C(u8 *p);
int func_021BFA6C(int task, int *state, Q *q);
int func_021BFB90(int task, int *state, int *q);
int func_021BFC98(int a, int *s, int *q);
void *func_021BFD34(int a0, void *p, int a2, const V3 *v);
void *func_021BFD70(int a0, void *p, int a2, int a3);
void *func_021BFDA0(int a0, void *p, int a2, int a3);
void *func_021BFDD0(int a0, void *p, int a2, int a3);
void *func_021BFE00(int a0, void *p, int a2);
int func_021BFE2C(int task, int *state, int *q);
int func_021C00C8(void *task, int *state, void **q);
void func_021C0140(u32 *p);
void func_021C017C(u8 *p);
int func_021C01E4(void **a);
int func_021C01F8(u32 *p);
int func_021C021C(u32 a, int *st, u8 *p);
void func_021C029C(u8 *p);
void func_021C02F8(u8 *p);
int func_021C0360(u8 *a);
int func_021C0374(u32 *p);
int func_021C0398(u32 task, int *st, u8 *p);
int func_021C04C0(int task, int *state, int *q);
int func_021C0598(int x, int y, const Rect *r, int unused);
Tab *func_021C05D4(u32 n, u32 heap);
void func_021C0628(int i, int a, int b, int c, int d, int e, int f, SlotTable *t);
void func_021C0674(void **p);
u32 func_021C0688(u8 *p);
int func_021C068C(int a, int b, int c, u8 d);
int func_021C06A8(u8 a, int b);
int func_021C06B4(u8 a, int b);
void func_021C06C0(u8 i, int v, int *p);
void func_021C06CC(void *p);
int func_021C06E0(u32 a, int *st);
int func_021C0780(u32 a, int *st);
int func_021C0808(void);
int func_021C080C(void);
int func_021C0810(u32 a, u32 b, u32 c, u32 d);
void *func_021C0820(void *p, int a1, u32 n);
int func_021C0844(u32 a, int *st, u8 *p);
void func_021C0904(u8 *p, u32 a, u32 n);
void func_021C0988(u8 *p);
void func_021C09A8(u8 *p, int *st, int v);
void func_021C09B0(u8 *p);
void func_021C0A10(u8 *p);
void func_021C0A48(u8 *p);
int func_021C0A70(u8 *p);
void *func_021C0AA0(void *p, int a1);
int func_021C0AC0(u32 a, int *st, u8 *p);
void func_021C0B3C(u8 *p, u32 a);
void func_021C0BD8(int *p);
void func_021C0BE8(u8 *p);
void func_021C0C48(u8 *p);
int func_021C0C80(u32 a);
u32 func_021C0C94(u32 a);
int func_021C0CA4(u8 *a, int b, int c, int d);
int func_021C0CE4(u8 *a, u32 b, u32 flags);
int func_021C0D08(void *obj, u32 dir, void *map);
int func_021C0DDC(u8 *a, u32 b, int c);
void *func_021C0E4C(u32 a, u32 b, u32 c, u32 d);
int func_021C0E98(u32 unused, int *st, u8 *p);
void func_021C1024(u32 a, u16 b, u32 c, u32 d);
int func_021C1094(void *a);
int func_021C10A0(u32 a);
void func_021C10B4(u32 task, Work_021C0810 *w);
void func_021C1228(u32 a, u16 b, u32 c, u32 d);
int func_021C12C4(void *a);
void func_021C12D0(void *h);
void func_021C12E4(u32 a, const V3 *v);
int func_021C1318(u8 *p);
int func_021C146C(u8 *p);
int func_021C14F8(u8 *p);
int func_021C157C(u8 *p);
int func_021C161C(u8 *p);
int func_021C1670(u8 *p);
void func_021C16AC(u8 *p);
extern S16 d_021D9F50;
extern const Vec d_021DA080;
extern u8 d_021DE3A0[];
extern u32 d_021DA08C[];
extern char ov021_id[];
extern u8 d_021DA098[];
extern u8 d_021DA0E0;
extern u8 d_021DE3AC;












int func_021BEE74(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        func_0204E720(((struct Obj12906 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj12906 *)q)->f14 == 1)
            return 1;
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}












int func_021BEEB4(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        if (((struct Obj06060 *)q)->f18 != 0) {
            func_021BF564(((struct Obj06060 *)q)->f4);
            func_021BF584((u8 *)(((struct Obj06060 *)q)->f4));
        }
        func_0204E720(((struct Obj06060 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj06060 *)q)->f14 == 1)
            return 1;
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}












int func_021BEF08(u32 p0, int *st, u8 *q)
{
    S16 loc;

    if (*st == 0) {
        func_0204E720(((struct Obj20152 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        func_0208068C(8);
        *(volatile u32 *)0x04000064 = 0x80330010;
        func_02087AE4();
        func_02087AE4();
        loc = d_021D9F50;
        func_0203FC28((struct DispConfig *)(&loc));
        *(volatile u16 *)0x0400000C = 0x4084 | (*(volatile u16 *)0x0400000C & 0x43);
        func_0207FDCC(8);
        func_0204047C(2, 0);
        func_02040588(2, 1);
        func_02166B0C();
        return 1;
    }
    return 0;
}












int func_021BEF8C(u32 p0, int *st, u8 *q)
{
    u32 m;

    switch (*st) {
    case 0:
        func_02189A58((u8 *)(((struct Obj01504 *)q)->f4), 1);
        ((struct Obj01504 *)q)->f1C = 0x10;
        func_0204047C(2, 0);
        func_0204047C(0, 1);
        func_02040588(0, 1);
        func_0207D63C(0x04000050, 4, 1, ((struct Obj01504 *)q)->f1C, 0);
        func_0204E720(((struct Obj01504 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj01504 *)q)->f1C != 0) {
            ((struct Obj01504 *)q)->f1C = ((struct Obj01504 *)q)->f1C - 1;
            *(volatile u16 *)0x04000052 = ((0x10 - ((struct Obj01504 *)q)->f1C) << 8) | ((struct Obj01504 *)q)->f1C;
            break;
        }
        func_02040588(2, 0);
        func_0208068C(8);
        func_02082AC0(0, 0x06800000, 0x20000);
        func_02080B98();
        func_0207FDCC(8);
        func_02166B2C();
        *st = *st + 1;
        break;
    case 2:
        func_021BF564(((struct Obj01504 *)q)->f4);
        *st = *st + 1;
        break;
    case 3:
        func_02188DF0((u8 *)(((struct Obj01504 *)q)->f4));
        *st = *st + 1;
        break;
    case 4:
        m = func_02188C54((u8 *)(((struct Obj01504 *)q)->f4));
        if (func_021903CC((u8 *)m) != 0) {
            func_021902AC((u16 *)m, 0);
            *st = *st + 1;
        }
        break;
    case 5:
        func_021902AC((u16 *)func_02188C54((u8 *)(((struct Obj01504 *)q)->f4)), 1);
        *st = *st + 1;
        break;
    case 6:
        func_021902AC((u16 *)func_02188C54((u8 *)(((struct Obj01504 *)q)->f4)), 2);
        *st = *st + 1;
        break;
    case 7:
        *st = *st + 1;
    case 8:
        func_02189A58((u8 *)(((struct Obj01504 *)q)->f4), 0);
        return 1;
    }
    return 0;
}












int func_021BF0A4(u32 p0, int *st, u8 *q)
{
    u32 a = ((struct Obj07553 *)q)->f0;
    u32 b = ((struct Obj07553 *)q)->f4;

    switch (*st) {
    case 0: {
        u32 r = (u32)func_0218774C(a, b, q[0x20], q[0x21]);
        func_02012374((struct Evt *)p0, (struct Evt **)r);
        *st = *st + 1;
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}












int func_021BF0E4(u32 p0, int *st, u8 *q)
{
    u32 a = ((struct Obj05067 *)q)->f0;
    u32 b = ((struct Obj05067 *)q)->f4;

    switch (*st) {
    case 0: {
        u32 r = (u32)func_021877A8(a, b, q[0x20], q[0x21], ((struct Obj05067 *)q)->f24, ((struct Obj05067 *)q)->f28);
        func_02012374((struct Evt *)p0, (struct Evt **)r);
        *st = *st + 1;
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}














int func_021BF130(u32 p0, int *st, u8 *q)
{
    u32 x = ((struct Obj12907 *)q)->f4;

    switch (*st) {
    case 0:
        func_0204E720(((struct Obj12907 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C((void *)3, 8, 8, 0, 6, 1, func_02188C84((u8 *)x));
        *st = *st + 1;
        break;
    case 2:
        if (func_020221A4() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}














int func_021BF19C(u32 p0, int *st, u8 *q)
{
    u32 x = ((struct Obj12908 *)q)->f4;

    switch (*st) {
    case 0:
        func_0204E720(((struct Obj12908 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C((void *)3, 2, 2, 0, 6, 1, func_02188C84((u8 *)x));
        *st = *st + 1;
        break;
    case 2:
        if (func_020221A4() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}














int func_021BF208(u32 p0, int *st, u8 *q)
{
    u32 x = ((struct Obj12909 *)q)->f4;

    switch (*st) {
    case 0:
        func_0204E720(((struct Obj12909 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C((void *)3, 4, 4, 0, 6, 1, func_02188C84((u8 *)x));
        *st = *st + 1;
        break;
    case 2:
        if (func_020221A4() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}














int func_021BF274(u32 p0, int *st, u8 *q)
{
    u32 x = ((struct Obj12910 *)q)->f4;

    switch (*st) {
    case 0:
        func_0204E720(((struct Obj12910 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C((void *)3, 10, 10, 0, 6, 1, func_02188C84((u8 *)x));
        *st = *st + 1;
        break;
    case 2:
        if (func_020221A4() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}














int func_021BF2E0(u32 p0, int *st, u8 *q)
{
    u32 x = ((struct Obj12911 *)q)->f4;

    switch (*st) {
    case 0:
        func_0204E720(((struct Obj12911 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C((void *)3, 6, 6, 0, 6, 1, func_02188C84((u8 *)x));
        *st = *st + 1;
        break;
    case 2:
        if (func_020221A4() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}














int func_021BF348(u32 p0, int *st, u8 *q)
{
    u32 x = ((struct Obj09668 *)q)->f4;

    switch (*st) {
    case 0:
        func_021BF564();
        func_021BF584((u8 *)(((struct Obj09668 *)q)->f4));
        func_0204E720(((struct Obj09668 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C((void *)3, 3, 3, 0, 6, 1, func_02188C84((u8 *)x));
        *st = *st + 1;
        break;
    case 2:
        if (func_020221A4() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}














int func_021BF3BC(int a, int *s, int *q)
{
    int k = s[0];
    int v = q[1];

    switch (k) {
    case 0:
        func_021BF564();
        func_021BF584((unsigned char *)q[1]);
        func_0204E720(q[3], 16, 0, -1);
        s[0] = s[0] + 1;
        break;
    case 1:
        func_0202208C((void *)3, 5, 5, 0, 6, 1, func_02188C84((u8 *)v));
        s[0] = s[0] + 1;
        break;
    case 2:
        if (func_020221A4() != 0) {
            s[0] = s[0] + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}













int func_021BF430(int a, int *s, int *q)
{
    int k = s[0];
    int v = q[1];

    switch (k) {
    case 0:
        func_021BF564();
        func_021BF584((unsigned char *)q[1]);
        func_0204E720(q[3], 16, 0, -1);
        s[0] = s[0] + 1;
        break;
    case 1:
        func_0202208C((void *)3, 7, 7, 0, 6, 1, func_02188C84((u8 *)v));
        s[0] = s[0] + 1;
        break;
    case 2:
        if (func_020221A4() != 0) {
            s[0] = s[0] + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}












int func_021BF4A4(int a, int *s, int *q)
{
    int k = s[0];
    int v = q[1];

    switch (k) {
    case 0:
        func_021BF564();
        func_021BF584((unsigned char *)q[1]);
        func_0204E720(q[3], 16, 0, -1);
        s[0] = s[0] + 1;
        break;
    case 1:
        func_0202208C((void *)3, 11, 11, 0, 6, 1, func_02188C84((u8 *)v));
        s[0] = s[0] + 1;
        break;
    case 2:
        if (func_020221A4() != 0) {
            s[0] = s[0] + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}










int func_021BF518(int a, int *s, int *q)
{
    switch (s[0]) {
    case 0:
        func_0204E720(q[3], 16, 0, q[4]);
        func_021BF564(q[1]);
        func_021BF584((u8 *)q[1]);
        s[0] = s[0] + 1;
        break;
    case 1:
        if (q[5] == 1) {
            return 1;
        }
        if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}













/*
 * Addresses are Black-image addresses.
 */
void func_021BF564()
{
    u32 a = func_02043658();
    u32 b = func_02043668();

    func_02188DA0();
    func_02043534(a);
    func_020435F4(b);
}













/*
 * Tail-call thunk: forwards to func_02188DB0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF584(u8 *a0)
{
    func_02188DB0(a0);
}













void *func_021BF58C(int a, void *p, int c)
{
    void *task = func_020122C0(p, (void *)a, func_021BF694, 0x68);
    Work_021BF58C *w = func_020124E8(task);

    w->x4 = c;
    w->x0 = p;
    return task;
}














void *func_021BF5B4(int a, int b, int c, int d, int e, int f)
{
    void *t = func_020122C0((void *)b, (void *)a, func_021BF76C, 0x68);
    Work_021BF5B4 *w = func_020124E8(t);
    w->f4 = c;
    w->f0 = b;
    w->f5C = d;
    w->f60 = e;
    w->f64 = f;
    return t;
}












u32 func_021BF5E8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    u32 h = (u32)func_020122C0((void *)b, (void *)a, func_021BF8EC, 0x68);
    X *x = func_020124E8((struct Obj *)h);
    x->f4 = c;
    x->f0 = b;
    x->f5C = d;
    x->f60 = e;
    x->f64 = f;
    return h;
}













void *func_021BF61C(int a, int b, int c)
{
    void *t = func_020122C0((void *)b, (void *)a, func_021BFA6C, 0x68);
    Work_021BEE74 *w = func_020124E8(t);
    w->f4 = c;
    w->f0 = b;
    return t;
}













int func_021BF644(int a, int b, int c)
{
    int h = (int)func_020122C0((void *)b, (void *)a, func_021BFB90, 0x68);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f4 = c;
    e->f0 = b;
    return h;
}












/*
 * Spawns a 0x68-byte task (callback func_021BFC98) and stores its owner and argument.
 */
void *func_021BF66C(int a0, void *p, int a2)
{
    void *t = func_020122C0(p, (void *)a0, func_021BFC98, 0x68);
    int *w = func_020124E8(t);

    w[1] = a2;
    w[0] = (int)p;
    return t;
}












int func_021BF694(int a, int *s, int *q)
{
    int h = (int)func_02188C58((void *)q[1]);
    Vec rot;
    void *t;
    int r;

    switch (s[0]) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        rot = d_021DA080;
        t = func_021A3074(func_02188CB4((struct Obj00020 *)q[1]));
        func_0216D8C0(t, &rot);
        func_0216D410(t, 1);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)q[0], q[1], 0, 1, 1, 0, 0));
        r = (int)func_021C7684(q[1], (u32)func_021A3074(func_02188CB4((struct Obj00020 *)q[1])), 0x28, 0xfa);
        func_021C6DE0((u8 *)func_02188D38((u8 *)q[1]), (u32 *)r, 0);
        s[0] = s[0] + 1;
        break;
    case 1:
        if (func_021C6E48(func_02188D38((u8 *)q[1])) != 0)
            s[0] = s[0] + 1;
        break;
    case 2:
        func_0218E13C((u8 *)h, q[2]);
        s[0] = s[0] + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}










int func_021BF76C(void *task, int *state, void **q)
{
    void *obj;
    void *h;
    void *d;

    obj = q[1];
    h = func_02188C58(obj);
    d = (void *)func_02188D38(obj);

    switch (*state) {
    case 0:
        func_0218F0A8(h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0)
            (*state)++;
        break;
    case 2:
        if (q[23] == 0) {
            func_021BF874(q);
            func_021BF7F8((Q *)q);
        }
        (*state)++;
        break;
    case 3:
        func_02012374(task, func_021BF898((int *)q));
        (*state)++;
        break;
    case 4:
        if (func_021C6E48((int)d) != 0)
            (*state)++;
        break;
    case 5:
        func_021BF860(q);
        return 1;
    }
    return 0;
}









void func_021BF7F8(Q *q)
{
    int r4;
    int r0;

    r4 = (int)func_02188C58((void *)q->f4);
    r0 = (int)func_0218FE80((void *)q->f4);
    q->fc = 60;
    q->f50 = 1;
    q->f54 = 1;
    q->f58 = r0;
    func_0218FEA0((u8 *)r0, (u32)(&q->fc));
    func_0218FEA4(q->f58);
    func_0218FE78(r4, &q->v30);
    q->v10 = q->v30;
    q->v10.w[1] = q->v10.w[1] - 0x64000;
    func_0218FEC0((u8 *)q->f58);
    func_0218FF00(q->f58);
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BF860(void **a)
{
func_0218FF20((u8 *)(((struct Obj12121 *)((u8 *)(a)))->f58));
return func_0218FE98(((struct Obj12121 *)((u8 *)(a)))->f58);
}










int func_021BF874(void **a)
{
return func_021C6DE0((u8 *)(func_02188D38((u8 *)(((struct Obj01860 *)((u8 *)(a)))->f4))), (u32 *)((u32)func_021C72AC(((struct Obj01860 *)((u8 *)(a)))->f4, 60, 8, 1)), 0);
}










void *func_021BF898(int *q)
{
    int c = q[23];
    int a = q[0];
    int b = q[1];

    if (c != 0) {
        return func_021BE9A0((void *)a, b, (u8)q[24], (u8)q[25], (int)func_021BF8DC, (int)q);
    }
    return (void *)func_021BE92C((void *)a, b, 1, 1, 1, 0, 0);
}









void func_021BF8DC(u8 *p)
{
    func_021BF874((void **)p);
    func_021BF7F8((Q *)p);
}









/*
 * Twin of func_021BF76C. func_021C6E48 takes func_02188D38's result (no
 * argument setup before its bl in case 4); that value, live across the
 * switch, is what puts the dispatch index in r1.
 */
int func_021BF8EC(void *task, int *state, void **q)
{
    void *obj;
    void *h;
    void *d;

    obj = q[1];
    h = func_02188C58(obj);
    d = (void *)func_02188D38(obj);

    switch (*state) {
    case 0:
        func_0218F0A8(h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0)
            (*state)++;
        break;
    case 2:
        if (q[23] == 0) {
            func_021BF9F4(q);
            func_021BF978((Q *)q);
        }
        (*state)++;
        break;
    case 3:
        func_02012374(task, func_021BFA18((int *)q));
        (*state)++;
        break;
    case 4:
        if (func_021C6E48((int)d) != 0)
            (*state)++;
        break;
    case 5:
        func_021BF9E0(q);
        return 1;
    }
    return 0;
}









void func_021BF978(Q *q)
{
    int r4;
    int r0;

    r4 = (int)func_02188C58((void *)q->f4);
    r0 = (int)func_0218FE80((void *)q->f4);
    q->fc = 60;
    q->f50 = 1;
    q->f54 = 1;
    q->f58 = r0;
    func_0218FEA0((u8 *)r0, (u32)(&q->fc));
    func_0218FEA4(q->f58);
    func_0218FE78(r4, &q->v30);
    q->v10 = q->v30;
    q->v10.w[1] = q->v10.w[1] - 0x64000;
    func_0218FEC0((u8 *)q->f58);
    func_0218FF00(q->f58);
}










int func_021BF9E0(void **a)
{
func_0218FF20((u8 *)(((struct Obj12122 *)((u8 *)(a)))->f58));
return func_0218FE98(((struct Obj12122 *)((u8 *)(a)))->f58);
}










int func_021BF9F4(void **a)
{
return func_021C6DE0((u8 *)(func_02188D38((u8 *)(((struct Obj01861 *)((u8 *)(a)))->f4))), (u32 *)((u32)func_021C72AC(((struct Obj01861 *)((u8 *)(a)))->f4, 60, 8, 1)), 0);
}










void *func_021BFA18(int *q)
{
    int c = q[23];
    int a = q[0];
    int b = q[1];

    if (c != 0) {
        return func_021BE9A0((void *)a, b, (u8)q[24], (u8)q[25], (int)func_021BFA5C, (int)q);
    }
    return (void *)func_021BE92C((void *)a, b, 1, 1, 1, 0, 0);
}












/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFA5C(u8 *p)
{
    func_021BF9F4((void **)p);
    func_021BF978((Q *)p);
}












int func_021BFA6C(int task, int *state, Q *q)
{
    int q0;
    int obj;
    int h;
    int d;
    int r0;
    void *t;

    q0 = q->f0;
    obj = q->f4;
    h = (int)func_02188C58((void *)obj);
    d = func_02188D38((u8 *)obj);

    switch (*state) {
    case 0:
        func_0218F0A8((u8 *)h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8((u8 *)h) == 0)
            (*state)++;
        break;
    case 2:
        func_021C6DE0((u8 *)d, (u32 *)func_021C72AC(obj, 0x3c, 8, 1), 0);
        r0 = (int)func_0218FE80((void *)obj);
        q->fc = 60;
        q->f50 = 1;
        q->f54 = 1;
        q->f58 = r0;
        func_0218FEA0((u8 *)r0, (u32)(&q->fc));
        func_0218FEA4(q->f58);
        func_0218FE78(h, &q->v30);
        q->v10 = q->v30;
        q->v10.w[1] = q->v10.w[1] - 0x64000;
        func_0218FEC0((u8 *)q->f58);
        func_0218FF00(q->f58);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)task, (struct Evt **)func_021BE92C((void *)q0, obj, 0, 1, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        if (func_021C6E48(d) != 0) {
            t = func_021A3074(func_02188CB4((struct Obj00020 *)obj));
            func_021AC528((u32)t, func_02188CD0((u8 *)obj));
            (*state)++;
        }
        break;
    case 5:
        func_0218FF20((u8 *)q->f58);
        func_0218FE98((u32)((void *)q->f58));
        return 1;
    }
    return 0;
}












int func_021BFB90(int task, int *state, int *q)
{
    int obj;
    int h;
    void *t;
    int w;
    int x;
    int d;

    obj = q[1];
    h = (int)func_02188C58((void *)obj);

    switch (*state) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        t = func_021A3074(func_02188CB4((struct Obj00020 *)obj));
        {
            Vec v;
            v.y = 0xA000;
            v.x = 0;
            v.z = 0;
            func_0216D8C0(t, &v);
        }
        func_02012374((struct Evt *)task, (struct Evt **)func_021BE92C((void *)q[0], obj, 0, 1, 1, 0, 0));
        {
            Vec v2;
            v2.y = 0x96000;
            v2.x = 0;
            v2.z = 0;
            w = (int)func_021C71D4(obj, 0x18, 3);
            x = func_021C7858(obj, -0x18, (unsigned int)(&v2));
        }
        d = func_02188D38((u8 *)obj);
        func_021C6DE0((u8 *)d, (unsigned int *)w, 0);
        func_021C6DE0((u8 *)d, (unsigned int *)x, 0);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(func_02188D38((u8 *)obj)) != 0)
            (*state)++;
        break;
    case 2:
        t = func_021A3074(func_02188CB4((struct Obj00020 *)obj));
        func_021AC528((unsigned int)t, func_02188CD0((u8 *)q[1]));
        func_020061E4(0x67B);
        (*state)++;
        break;
    case 3:
        func_0218E13C((u8 *)h, q[2]);
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}












int func_021BFC98(int a, int *s, int *q)
{
    int h = (int)func_02188C58((void *)q[1]);
    void *t;

    t = func_021A3074(func_02188CB4((struct Obj00020 *)q[1]));
    switch (s[0]) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        func_0216D410(t, 0x44);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)q[0], q[1], 0, 1, 1, 0, 0));
        s[0] = s[0] + 1;
        break;
    case 1:
        if (func_0216D454(t) == 1) {
            func_0216D480(t);
            s[0] = s[0] + 1;
        }
        break;
    case 2:
        func_0218E13C((u8 *)h, q[2]);
        s[0] = s[0] + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}












static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}












/*
 * Spawns a 0x7C-byte task and seeds it with a position triple.
 */
void *func_021BFD34(int a0, void *p, int a2, const V3 *v)
{
    void *t = func_020122C0(p, (void *)a0, func_021BFE2C, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[8] = 0;
    V3_Set((V3 *)&w[5], v->x, v->y, v->z);
    return t;
}












/*
 * Spawns a 0x7C-byte task (callback func_021C00C8).
 */
void *func_021BFD70(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, func_021C00C8, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[29] = 0;
    w[30] = a3;
    return t;
}












/*
 * Spawns a 0x7C-byte task (callback func_021C021C).
 */
void *func_021BFDA0(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, func_021C021C, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[29] = 0;
    w[30] = a3;
    return t;
}











void *func_021BFDD0(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, func_021C0398, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[4] = a3;
    return t;
}











/*
 * Spawns a 0x7C-byte task (callback func_021C04C0).
 */
void *func_021BFE00(int a0, void *p, int a2)
{
    void *t = func_020122C0(p, (void *)a0, func_021C04C0, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    return t;
}









int func_021BFE2C(int task, int *state, int *q)
{
    void *s;
    void *t;
    int u;
    int h;
    int g;
    int *r;
    int dx;
    int dz;
    int k;
    int e;
    int keys;
    int n;
    int a;
    int b;
    int c;
    int d;
    int rect[4];
    int cnt;
    Vec v;
    Vec w;

    s = func_02188CB4((struct Obj00020 *)q[1]);
    t = func_021A3074((void *)s);
    u = func_02188CD0((u8 *)q[1]);
    h = (int)func_02188C58((void *)q[1]);

    switch (*state) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        *state = 1;
        break;
    case 1:
        func_0200616C((void *)0x680, func_02006148(0x680));
        g = func_0218DC6C((u8 *)func_02188C98((u8 *)q[1]));
        rect[2] = q[5] - 0x20000;
        rect[3] = q[5] + 0x20000;
        rect[0] = q[7] - 0x20000;
        rect[1] = q[7] + 0x20000;
        r = func_0218C584(g, rect, 2, &cnt);
        if (*r != 0) {
            q[8] = (int)func_0218C724((u8 *)g, (u32 *)(*r));
            func_0218C88C((unsigned char *)q[8], 0, 0);
        } else {
            q[8] = 0;
        }
        func_020307B0(r);
        *state = 2;
        break;
    case 2:
        func_021A3038(s, (struct VecFx32 *)&v);
        dx = (v.x >> 12) / 16 - (q[5] >> 12) / 16;
        dz = (v.z >> 12) / 16 - (q[7] >> 12) / 16;
        if (dx < 0)
            dx = -dx;
        if (dz < 0)
            dz = -dz;
        if (dx == 0 && dz == 0)
            k = 0;
        else if (dx < 2 && dz < 2)
            k = 0x3c;
        else
            k = 0x78;
        if (k > 0) {
            e = func_021C754C(q[1], k, &q[5]);
            func_021C6DE0((u8 *)func_02188D38((u8 *)q[1]), (u32 *)e, 0);
            *state = 3;
        } else {
            *state = 4;
        }
        q[3] = 0;
        break;
    case 3:
        if (q[8] != 0 && func_0218C8FC((unsigned char *)q[8], 0) != 0)
            func_0218C88C((unsigned char *)q[8], 0, 0);
        keys = func_0203630C();
        if (keys & 0x40)
            func_0216D410(t, 0x24);
        if (keys & 0x80)
            func_0216D410(t, 0x25);
        if (keys & 0x20)
            func_0216D410(t, 0x26);
        if (keys & 0x10)
            func_0216D410(t, 0x27);
        n = q[3];
        q[3] = n + 1;
        if (n % 10 == 0)
            func_021AC528((u32)t, u);
        if (func_021C6E48(func_02188D38((u8 *)q[1])) != 0)
            *state = 4;
        break;
    case 4:
        func_020061E4(0x7A0);
        func_0216D568(t, 0x8000);
        w.x = 0;
        w.y = -0x1E000;
        w.z = 0;
        a = func_021C7858(q[1], 0x22, (u32)(&w));
        b = (int)func_021C71D4(q[1], 0x22, 5);
        c = func_021C6F00(q[1], 0x1e, 0xB4000);
        e = func_021C7814(q[1], 3, 0, 0x10, 0);
        d = func_02188D38((u8 *)q[1]);
        func_021C6DE0((u8 *)d, (u32 *)a, 0);
        func_021C6DE0((u8 *)d, (u32 *)b, 0);
        func_021C6DE0((u8 *)d, (u32 *)c, 0);
        func_021C6DE0((u8 *)d, (u32 *)e, c);
        q[3] = 0;
        *state = 5;
        break;
    case 5:
        if (func_021C6E48(func_02188D38((u8 *)q[1])) != 0)
            *state = 6;
        break;
    case 6:
        func_020061F8(func_02006148(0x680));
        func_0218E13C((u8 *)h, q[2]);
        if (q[8] != 0)
            func_0218C860(q[8]);
        return 1;
    }
    return 0;
}








/*
 * Same family as func_021BF76C: func_021C6E48 takes func_02188D38's result,
 * which keeps r0 live across the switch and puts the dispatch index in r1.
 */
int func_021C00C8(void *task, int *state, void **q)
{
    void *d;
    int t;

    d = (void *)func_02188D38(q[1]);

    switch (*state) {
    case 0:
        func_021C0140((u32 *)q);
        func_021C017C((u8 *)q);
        (*state)++;
        break;
    case 1:
        t = (int)q[29];
        q[29] = (void *)(t + 1);
        if (t > 35) {
            func_02012374(task, (struct Evt **)func_021C01F8((u32 *)q));
            (*state)++;
            break;
        }
    case 2:
        if (func_021C6E48((int)d) != 0) {
            func_020061E4(0x559);
            (*state)++;
        }
        break;
    case 3:
        func_021C01E4(q);
        return 1;
    }
    return 0;
}










void func_021C0140(u32 *p)
{
    u32 o = p[1];
    u32 r = func_02188D38((u8 *)o);
    u32 a = (u32)func_021C7260(o, 0x14, 3);
    u32 b = (u32)func_021C71D4(o, 0x14, 5);

    func_021C6DE0((u8 *)r, (u32 *)a, 0);
    func_021C6DE0((u8 *)r, (u32 *)b, a);
}










void func_021C017C(u8 *p)
{
    u32 a;
    u32 b;

    a = (u32)func_02188C58((void *)(((struct Obj02723 *)p)->f4));
    b = (u32)func_0218FE80((void *)(((struct Obj02723 *)p)->f4));
    ((struct Obj02723 *)p)->f24 = 0x3c;
    ((struct Obj02723 *)p)->f68 = 1;
    ((struct Obj02723 *)p)->f6C = 1;
    ((struct Obj02723 *)p)->f70 = b;
    func_0218FEA0((u8 *)b, (u32)(p + 0x24));
    func_0218FEA4(((struct Obj02723 *)p)->f70);
    func_0218FE78(a, (V8 *)(p + 0x28));
    *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
    ((struct Obj02723 *)p)->f4C -= 0x64000;
    func_0218FEC0((u8 *)(((struct Obj02723 *)p)->f70));
    func_0218FF00(((struct Obj02723 *)p)->f70);
}










int func_021C01E4(void **a)
{
func_0218FF20((u8 *)(((struct Obj12123 *)((u8 *)(a)))->f70));
return func_0218FE98((u32)((void *)(((struct Obj12123 *)((u8 *)(a)))->f70)));
}










/*
 * Calls func_021BE8D4 with mode 0 or 1 by the flag at +0x78.
 */
int func_021C01F8(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];

    if (p[30] != 0)
        func_021BE8D4((void *)a, b, 0, 0);
    else
        return func_021BE8D4((void *)a, b, 1, 0);
}










int func_021C021C(u32 a, int *st, u8 *p)
{
    int n;

    u32 q;

    q = func_02188D38((u8 *)(((struct Obj05073 *)p)->f4));
    switch (*st) {
    case 0:
        func_021C029C(p);
        func_021C02F8(p);
        func_020061E4(0x6DF);
        *st = *st + 1;
        break;
    case 1:
        n = ((struct Obj05073 *)p)->f74;
        ((struct Obj05073 *)p)->f74 = n + 1;
        if (n > 0x23) {
            func_02012374((struct Evt *)a, (struct Evt **)func_021C0374((u32 *)p));
            *st = *st + 1;
            break;
        }
    case 2:
        if (func_021C6E48(q)) {
            func_020061E4(0x559);
            *st = *st + 1;
        }
        break;
    case 3:
        func_021C0360(p);
        return 1;
    }
    return 0;
}










void func_021C029C(u8 *p)
{
    u32 s;
    u32 a;
    u32 b;
    u32 c;
    u32 d;

    s = ((struct Obj20154 *)p)->f4;
    a = func_02188D38((u8 *)s);
    b = func_021C7D28(s, (int)func_021A3074(func_02188CB4((void *)s)), 0x28, 6);
    c = (u32)func_021C7260(s, 0x14, 4);
    d = (u32)func_021C71D4(s, 0x14, 5);
    func_021C6DE0((u8 *)a, (u32 *)b, 0);
    func_021C6DE0((u8 *)a, (u32 *)c, 0);
    func_021C6DE0((u8 *)a, (u32 *)d, c);
}










void func_021C02F8(u8 *p)
{
    u32 a;
    u32 b;

    a = (u32)func_02188C58((void *)(((struct Obj02724 *)p)->f4));
    b = (u32)func_0218FE80((void *)(((struct Obj02724 *)p)->f4));
    ((struct Obj02724 *)p)->f24 = 0x3c;
    ((struct Obj02724 *)p)->f68 = 1;
    ((struct Obj02724 *)p)->f6C = 1;
    ((struct Obj02724 *)p)->f70 = b;
    func_0218FEA0((u8 *)b, (u32)(p + 0x24));
    func_0218FEA4(((struct Obj02724 *)p)->f70);
    func_0218FE78(a, (V8 *)(p + 0x28));
    *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
    ((struct Obj02724 *)p)->f4C -= 0x64000;
    func_0218FEC0((u8 *)(((struct Obj02724 *)p)->f70));
    func_0218FF00(((struct Obj02724 *)p)->f70);
}









int func_021C0360(u8 *a)
{
func_0218FF20((u8 *)(((struct Obj12124 *)((u8 *)(a)))->f70));
return func_0218FE98((u32)((void *)(((struct Obj12124 *)((u8 *)(a)))->f70)));
}










int func_021C0374(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];

    if (p[30] != 0)
        func_021BE8D4((void *)a, b, 0, 0);
    else
        return func_021BE8D4((void *)a, b, 1, 0);
}










int func_021C0398(u32 task, int *st, u8 *p)
{
    u32 obj;
    u32 h;
    u32 d;
    u32 a;
    u32 b;
    u32 c;
    u32 e;

    obj = ((struct Obj01863 *)p)->f4;
    func_02188CB4((void *)obj);
    h = (u32)func_02188C58((void *)(((struct Obj01863 *)p)->f4));
    d = func_02188D38((u8 *)obj);

    switch (*st) {
    case 0:
        a = (u32)func_021C7260(obj, 0x14, 3);
        b = (u32)func_021C71D4(obj, 0x14, 5);
        c = func_021C77D8(obj, 0x1e);
        e = func_021C7814(obj, 3, 0, 0x10, 1);
        func_021C6DE0((u8 *)d, (u32 *)a, 0);
        func_021C6DE0((u8 *)d, (u32 *)b, a);
        func_021C6DE0((u8 *)d, (u32 *)c, 0);
        func_021C6DE0((u8 *)d, (u32 *)e, c);
        if (((struct Obj01863 *)p)->f10 != 0)
            func_020061E4(0x6E7);
        else
            func_020061E4(0x676);
        b = (u32)func_0218FE80((void *)obj);
        ((struct Obj01863 *)p)->f24 = 0x3c;
        ((struct Obj01863 *)p)->f68 = 1;
        ((struct Obj01863 *)p)->f6C = 1;
        ((struct Obj01863 *)p)->f70 = b;
        func_0218FEA0((u8 *)b, (u32)(p + 0x24));
        func_0218FEA4(((struct Obj01863 *)p)->f70);
        func_0218FE78(h, (V8 *)(p + 0x28));
        *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
        ((struct Obj01863 *)p)->f4C -= 0x64000;
        func_0218FEC0((u8 *)(((struct Obj01863 *)p)->f70));
        func_0218FF00(((struct Obj01863 *)p)->f70);
        *st = *st + 1;
        break;
    case 1:
        if (func_021C6E48(d))
            *st = *st + 1;
        break;
    case 2:
        func_0218FF20((u8 *)(((struct Obj01863 *)p)->f70));
        func_0218FE98((u32)((void *)((u32)((void *)(((struct Obj01863 *)p)->f70)))));
        return 1;
    }
    return 0;
}










int func_021C04C0(int task, int *state, int *q)
{
    int obj;
    int h;
    int w;
    int e;
    int x;
    int d;

    obj = q[1];
    func_02188CB4((void *)obj);
    h = (int)func_02188C58((void *)obj);

    switch (*state) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        {
            Vec v;
            v.y = 0x96000;
            v.x = 0;
            v.z = 0;
            w = (int)func_021C71D4(obj, 0x18, 3);
            e = func_021C7814(obj, 3, 0, 0x10, 1);
            x = func_021C7858(obj, 0x18, (unsigned int)(&v));
        }
        d = func_02188D38((u8 *)obj);
        func_021C6DE0((u8 *)d, (unsigned int *)w, 0);
        func_021C6DE0((u8 *)d, (unsigned int *)x, 0);
        func_021C6DE0((u8 *)d, (unsigned int *)e, x);
        func_020061E4(0x676);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(func_02188D38((u8 *)obj)) != 0 && func_0204E804() == 0)
            (*state)++;
        break;
    case 2:
        func_0218E13C((u8 *)h, q[2]);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}










/*
 * Point-in-rectangle test against an active rect (EXACT*: trailing pad).
 */
int func_021C0598(int x, int y, const Rect *r, int unused)
{
    int l, t, rr, b;

    if (r->active == 0)
        return 0;
    l = r->x;
    t = r->y;
    rr = l + r->w - 1;
    b = t + r->h - 1;
    if (l <= x && x <= rr && t <= y && y <= b)
        return 1;
    return 0;
}










Tab *func_021C05D4(u32 n, u32 heap)
{
    u8 i;
    Tab *t;

    i = 0;
    t = (Tab *)sub_02030734(heap, 8, 0, (const char *)d_021DE3A0, 0x5a);
    t->e = (u8 *)sub_02030734(heap, n * 0x1c, 0, (const char *)d_021DE3A0, 0x5b);
    t->n = n;
    for (i = 0; i < n; i++) {
        *(u32 *)(t->e + i * 0x1c + 0x14) = 0;
    }
    return t;
}







/*
 * Unlabelled leaf of ov043 func_021F36C0: fills slot i of a table of
 * 0x1C-byte entries when it is in range and not yet in use.
 */
void func_021C0628(int i, int a, int b, int c, int d, int e, int f, SlotTable *t)
{
    if (i < t->n && t->e[i].used == 0) {
        t->e[i].f0 = a;
        t->e[i].f4 = b;
        t->e[i].f8 = c;
        t->e[i].fc = d;
        t->e[i].f10 = e;
        t->e[i].f18 = f;
        t->e[i].used = 1;
    }
}







/*
 * Frees the sub-object at +4, then the object (EXACT*: trailing pad).
 */
void func_021C0674(void **p)
{
    func_020307B0(p[1]);
    func_020307B0(p);
}







/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0688(u8 *p)
{
    return ((struct Obj18267 *)p)->f0;
}







int func_021C068C(int a, int b, int c, u8 d)
{
if (func_021C0598(a, b, (const Rect *)((((struct Obj18268 *)((u8 *)(c)))->f4 + (d * 28))), d) != 0) {
    return 1;
}
return 0;
}







int func_021C06A8(u8 a, int b)
{
return *(u32 *)((u8 *)((((struct Obj18269 *)((u8 *)(b)))->f4 + (a * 28))) + 16);
}







int func_021C06B4(u8 a, int b)
{
return *(u32 *)((u8 *)((((struct Obj18270 *)((u8 *)(b)))->f4 + (a * 28))) + 24);
}







/*
 * Unlabelled leaf; called from ov043 func_021F3AC0.
 */
void func_021C06C0(u8 i, int v, int *p)
{
    ((E *)p[1])[i].v = v;
}







/*
 * Spawns the func_021C06E0 task with no work area.
 */
void func_021C06CC(void *p)
{
    func_020122C0(p, 0, func_021C06E0, 0);
}







int func_021C06E0(u32 a, int *st)
{
    void *h = func_020124E4((void *)a);
    void *o = func_0201210C(h);
    void *v;

    switch (*st) {
    case 0:
        func_0216D9A0(func_02188C7C((void *)o));
        if (func_0202647C((void *)func_02012138(h)) == 2) {
            if (func_02012B70(func_020120F4(h)) == 1) {
                func_0200FB38();
                v = func_020146F8(h, (int)o, (int)ov021_id, (int)d_021DA08C, (int)h);
            } else {
                v = func_020122C0(h, 0, func_021C0780, 0);
            }
        } else {
            func_0200FB38();
            v = func_020146F8(h, (int)o, (int)ov021_id, (int)d_021DA08C, (int)h);
        }
        func_02012374((struct Evt *)a, v);
        (*st)++;
        break;
    case 1:
        if (o != 0 && func_02188BE8(o) == 1) {
            func_0216D9E4(func_02188C7C((void *)o));
            return 1;
        }
        break;
    }
    return 0;
}







int func_021C0780(u32 a, int *st)
{
    u32 x;
    u32 y;
    u32 z;

    x = (u32)func_020124E4((struct Obj *)a);
    y = func_02012138((const struct Ctx *)x);
    switch (*st) {
    case 0:
        if (func_0203CD98()) {
            func_0203CEAC(0);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_0203CDBC() == 1) {
            func_0200FBA0();
            func_02012124((struct Ctx *)x, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_020121CC((struct IcaAnime *)x) == 1) {
            *st = *st + 1;
            break;
        }
        return 1;
    case 3:
        z = func_02026474((void *)y);
        if (z && func_02026454((void *)y)) {
            func_02164FC4((char *)z);
            return 1;
        }
        break;
    }
    return 0;
}



int func_021C0808(void) { return 1; }


int func_021C080C(void) { return 1; }









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C0810(u32 a, u32 b, u32 c, u32 d)
{
func_02012124((struct Ctx *)c, 0);
return 1;
}









void *func_021C0820(void *p, int a1, u32 n)
{
    void *t = func_020122C0(p, (void *)a1, func_021C0844, 0x38);
    u8 *w = func_020124E8(t);

    func_021C0904(w, (u32)p, n);
    return t;
}









int func_021C0844(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00707 *)p)->f16 % 15 == 0) {
            func_021C09B0(p);
            if (p[0x14] <= p[0x15]) {
                func_021C09A8(p, st, 1);
            }
        }
        break;
    case 1:
        if (((struct Obj00707 *)p)->f16 > 10) {
            func_021C0A10(p);
            func_02012374((struct Evt *)a, func_02029830(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0x514));
            func_021C09A8(p, st, 2);
        }
        break;
    case 2:
        if (func_021C0A70(p) != 0) {
            func_021C0A48(p);
            func_021C09A8(p, st, 3);
        }
        break;
    case 3:
        func_02012374((struct Evt *)a, func_02029620(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0, 6));
        func_021C09A8(p, st, 4);
        break;
    case 4:
        func_021C0988(p);
        return 1;
    }
    ((struct Obj00707 *)p)->f16 = ((struct Obj00707 *)p)->f16 + 1;
    return 0;
}









void func_021C0904(u8 *p, u32 a, u32 n)
{
    void *s;
    u32 w;
    u32 t;
    int *r;
    int pos[3];
    int rect[4];
    int cnt;

    s = func_0201210C((void *)a);
    w = func_02188C84(s);
    t = func_02188C98(s);
    ((struct Obj02394 *)p)->f0 = w;
    p[0x14] = n;
    ((struct Obj02394 *)p)->f4 = s;
    p[0x15] = 0;
    ((struct Obj02394 *)p)->f18 = func_0218DC6C((u8 *)t);
    ((struct Obj02394 *)p)->f34 = 0;
    if (p[0x14] > 6) {
        p[0x14] = 6;
    }
    func_021A3038(func_02188CB4(((struct Obj02394 *)p)->f4), (struct VecFx32 *)pos);
    rect[0] = pos[2] - 0x50000;
    rect[1] = pos[2] + 0x50000;
    rect[2] = pos[0] - 0x50000;
    rect[3] = pos[0] + 0x50000;
    r = func_0218C584(((struct Obj02394 *)p)->f18, rect, 3, &cnt);
    if (r) {
        ((struct Obj02394 *)p)->f34 = *r;
        func_0218C6D0((int *)(*r), (int)(p + 8));
    }
    func_020307B0(r);
}









/*
 * Releases each of the p[0x14] handles (EXACT*: unlabelled follower at 0x021C09A8).
 */
void func_021C0988(u8 *p)
{
    int i;

    for (i = 0; i < p[0x14]; i++)
        func_0218C860(((int *)(p + 0x1C))[i]);
}









/*
 * Unlabelled leaf: stores the next state and clears the halfword counter at +0x16.
 */
void func_021C09A8(u8 *p, int *st, int v)
{
    *st = v;
    ((struct Obj20159 *)p)->f16 = 0;
}









void func_021C09B0(u8 *p)
{
    struct { int out[3]; int scale[3]; int mat[9]; } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        func_020520FC(0, 0, 0, (struct Mtx33 *)s.mat);
        func_0207C9D0(p + 8, d_021DA098 + i * 12, s.out);
        *(u32 *)(p + 0x1c + i * 4) = (u32)func_0218C7F0((u8 *)(((struct Obj00707 *)p)->f18), 0x62, (struct Blk *)s.out);
        p[0x15] = p[0x15] + 1;
        func_020061E4(0x568);
    }
}









/*
 * Resets each of the p[0x15] handles, then the optional one at +0x34.
 */
void func_021C0A10(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 0);
    if (((struct Obj00707 *)p)->f34 != 0)
        func_0218C69C((unsigned char *)(*(int *)&((struct Obj00707 *)p)->f18), ((struct Obj00707 *)p)->f34, 0, 0);
}









/*
 * Sets mode 3 on each of the p[0x15] handles.
 */
void func_021C0A48(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 3);
}









/*
 * Returns 1 when every one of the p[0x15] handles reports done.
 */
int func_021C0A70(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++) {
        if (func_0218C8FC((unsigned char *)(((int *)(p + 0x1C))[i]), 0) != 1)
            return 0;
    }
    return 1;
}









/*
 * Spawns a 0x3C-byte task (callback func_021C0AC0) and initialises it.
 */
void *func_021C0AA0(void *p, int a1)
{
    void *t = func_020122C0(p, (void *)a1, func_021C0AC0, 0x3C);
    u8 *w = func_020124E8(t);

    func_021C0B3C(w, (u32)p);
    return t;
}








int func_021C0AC0(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00959 *)p)->f16 % 20 == 0) {
            func_021C0BE8(p);
            if (p[0x14] <= p[0x15]) {
                *st = *st + 1;
                ((struct Obj00959 *)p)->f16 = 0;
            }
        }
        break;
    case 1:
        if (((struct Obj00959 *)p)->f16 > 10) {
            func_021C0C48(p);
            *st = *st + 1;
            ((struct Obj00959 *)p)->f16 = 0;
        }
        break;
    case 2:
        if (func_021C0C80((u32)p) != 0) {
            *st = *st + 1;
        }
        break;
    case 3:
        func_021C0BD8((int *)p);
        return 1;
    }
    ((struct Obj00959 *)p)->f16 = ((struct Obj00959 *)p)->f16 + 1;
    return 0;
}








void func_021C0B3C(u8 *p, u32 a)
{
    void *s;
    u32 t;
    int *r;
    int pos[3];
    int rect[4];
    int cnt;

    s = func_0201210C((void *)a);
    t = func_02188C98(s);
    ((struct Obj01505 *)p)->f0 = func_02188C84(s);
    ((struct Obj01505 *)p)->f4 = s;
    p[0x14] = func_021C0C94(a);
    p[0x15] = 0;
    ((struct Obj01505 *)p)->f18 = func_0218DC6C((u8 *)t);
    ((struct Obj01505 *)p)->f34 = 0;
    if (p[0x14] > 6) {
        p[0x14] = 6;
    }
    func_021A3038(func_02188CB4(((struct Obj01505 *)p)->f4), (struct VecFx32 *)pos);
    rect[0] = pos[2] - 0x50000;
    rect[1] = pos[2] + 0x50000;
    rect[2] = pos[0] - 0x50000;
    rect[3] = pos[0] + 0x50000;
    r = func_0218C584(((struct Obj01505 *)p)->f18, rect, 8, &cnt);
    if (r) {
        ((struct Obj01505 *)p)->f34 = *r;
        func_0218C6D0((int *)(*r), (int)(p + 8));
    }
    func_020307B0(r);
    if (((struct Obj01505 *)p)->f34 != 0) {
        ((struct Obj01505 *)p)->f38 = (u32)func_0218C724((u8 *)(((struct Obj01505 *)p)->f18), (u32 *)(((struct Obj01505 *)p)->f34));
    }
}








/*
 * Releases the optional handle at +0x38.
 */
void func_021C0BD8(int *p)
{
    if (p[13] != 0)
        func_0218C860(p[14]);
}








/*
 * Addresses are Black-image addresses.
 */
void func_021C0BE8(u8 *p)
{
    struct {
        int pos[3];
        int scale[3];
        int mtx[9];
    } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        func_020520FC(0, 0, 0, (struct Mtx33 *)s.mtx);
        func_0207C9D0(p + 8, &d_021DA0E0 + i * 12, s.pos);
        *(u32 *)(p + 0x1c + i * 4) = (u32)func_0218C7F0((u8 *)(((struct Obj00959 *)p)->f18), 0x62, (struct Blk *)(&s));
        p[0x15]++;
        func_020061E4(0x568);
    }
}








/*
 * Sets mode 2 on each of the p[0x15] handles, then resets the one at +0x38.
 */
void func_021C0C48(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 2);
    if (((struct Obj00959 *)p)->f34 != 0)
        func_0218C88C((unsigned char *)(((struct Obj00959 *)p)->f38), 0, 0);
}








int func_021C0C80(u32 a)
{
if (*(u32 *)&((struct Obj00959 *)((u8 *)(a)))->f34 != 0) {
    return func_0218C8D8((void *)(*(u32 *)&((struct Obj00959 *)((u8 *)(a)))->f38));
}
return 1;
}








u32 func_021C0C94(u32 a)
{
return func_0201AA1C(func_02012934(func_020120F4((const struct Ctx *)a)));
}








int func_021C0CA4(u8 *a, int b, int c, int d)
{
    int r7, r4;
    r7 = func_021A5728((u8 *)a);
    func_021A572C((u8 *)a);
    r4 = func_021A3AB8(r7, c);
    if (func_021A44BC((int)a, r4) == 0)
        return 0;
    r7 = func_021C0CE4(a, r4, d);
    if (r7 == 0)
        return 0;
    return r7;
}








/*
 * Runs func_021C0DDC when bit 0 of the flags is set.
 */
int func_021C0CE4(u8 *a, u32 b, u32 flags)
{
    int r = 0;
    int h = func_021A448C((u32 *)a, b);

    if (flags & 1)
        r = func_021C0DDC(a, b, h);
    return r;
}








int func_021C0D08(void *obj, u32 dir, void *map)
{
    Vec pos;
    Vec cur;
    int flagB;
    int flagA;
    u8 i;
    u8 m;
    u8 n;
    u8 j;
    u32 attr;
    u16 id;

    func_0216D88C(obj, (struct VecFx32 *)&pos);
    func_02164208(dir, (int *)(&pos), 0x10000);
    n = func_0216D91C((int)obj);
    m = func_0216D924((int)obj);
    flagB = 0;
    flagA = 0;
    for (i = 0; i < m; i++, pos.z -= 0x10000) {
        cur = pos;
        for (j = 0; j < n; j++, cur.x += 0x10000) {
            attr = func_021AB0D4(map, &cur);
            id = func_021AB0F0(attr);
            if (func_021AB11C(attr)) {
                if (func_021AB2DC(id) == 0)
                    return 1;
                flagA = 1;
            } else {
                flagB = 1;
            }
        }
    }
    if (flagA == 1) {
        if (flagB == 0)
            return 3;
        return 2;
    }
    return 0;
}








int func_021C0DDC(u8 *a, u32 b, int c)
{
    u32 r6;
    u32 r4;
    u32 f;

    if (c == 1) {
        r6 = func_021C19B4(a, b);
        if (r6 != 0) {
            if (func_0216E5FC(func_0216D598((void *)r6)) == 1) {
                r4 = func_021C0D08((void *)r6, b, (void *)func_02188C98((u8 *)func_021A395C((u8 *)func_021A5728((u8 *)a))));
                f = func_021639C0(r6, b);
                f &= ~1;
                if ((f & 2) && r4 - 2 <= 1)
                    f &= ~2;
                if (f == 0) {
                    int k = 0;
                    if (r4 == 3)
                        k = 1;
                    return (int)func_021C0E4C((u32)a, b, r6, k);
                }
            }
        }
    }
    return 0;
}








void *func_021C0E4C(u32 a, u32 b, u32 c, u32 d)
{
    u32 t;
    void *task;
    u32 *w;

    t = func_021A5728((u8 *)a);
    task = func_020122C0((void *)func_021A3990((u8 *)t), 0, func_021C0E98, 0x24);
    w = func_020124E8(task);
    func_02082BCC(w, 0, 0x24);
    w[0] = a;
    ((struct Obj06070 *)w)->f4 = b;
    ((struct Obj06070 *)w)->f6 = d;
    w[7] = c;
    w[8] = (u32)func_021A3960((void *)t);
    return task;
}








int func_021C0E98(u32 unused, int *st, u8 *p)
{
    Vec3 a;
    Vec3 b;
    Vec3 c;

    switch (*st) {
    case 0:
        if (func_0216D3CC(((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (func_0216D3CC(((struct Obj00235 *)p)->f20) == 0 && func_021A5408((u8 *)(((struct Obj00235 *)p)->f0)) == 0)
            break;
        func_0216D410((void *)((struct Obj00235 *)p)->f1C, func_02197E7C(((struct Obj00235 *)p)->f4, 8));
        func_0216D410((void *)((struct Obj00235 *)p)->f20, func_02197E7C(((struct Obj00235 *)p)->f4, 0x20));
        func_020061E4(0x674);
        (*st)++;
        break;
    case 1:
        if (func_0216D454((void *)((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (func_0216D454((void *)((struct Obj00235 *)p)->f20) == 0)
            break;
        if (((struct Obj00235 *)p)->f6 == 0) {
            *st = 4;
            break;
        }
        func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&a);
        func_02163E58(((struct Obj00235 *)p)->f1C, &a, (int *)(p + 0xc));
        if (func_0216D598((void *)(((struct Obj00235 *)p)->f1C)) == 0x6d)
            ((struct Obj00235 *)p)->fC -= 14 << 12;
        else
            ((struct Obj00235 *)p)->fC -= 26 << 12;
        func_0216DB4C((void *)(((struct Obj00235 *)p)->f1C), 1);
        func_0216DAE0((unsigned int *)(((struct Obj00235 *)p)->f1C), 0);
        func_020061E4(0x675);
        (*st)++;
        break;
    case 2:
        func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&b);
        if (((struct Obj00235 *)p)->fC < b.y) {
            b.y -= 0x4000;
            if (((struct Obj00235 *)p)->fC > b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        } else if (((struct Obj00235 *)p)->fC > b.y) {
            b.y += 0x4000;
            if (((struct Obj00235 *)p)->fC < b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        }
        func_0216D89C(((struct Obj00235 *)p)->f1C, &b);
        if (((struct Obj00235 *)p)->fC == b.y) {
            ((struct Obj00235 *)p)->f14 = 0x2000;
            (*st)++;
        }
        break;
    case 3:
        func_0216D8E0(((struct Obj00235 *)p)->f1C, p + 0x10);
        ((struct Obj00235 *)p)->f14 = -((struct Obj00235 *)p)->f14;
        ((struct Obj00235 *)p)->f8 = ((struct Obj00235 *)p)->f8 + 1;
        if (((struct Obj00235 *)p)->f8 & 4) {
            if (((struct Obj00235 *)p)->f14 < 0)
                ((struct Obj00235 *)p)->f14 += 0x1000;
            else if (((struct Obj00235 *)p)->f14 > 0)
                ((struct Obj00235 *)p)->f14 -= 0x1000;
        }
        if (((struct Obj00235 *)p)->f14 == 0) {
            func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&c);
            func_0216E014((void *)(((struct Obj00235 *)p)->f1C), (int *)(&c), ((struct Obj00235 *)p)->f4);
            func_0216D8E0(((struct Obj00235 *)p)->f1C, p + 0x10);
            func_0216E57C((void *)(((struct Obj00235 *)p)->f1C));
            (*st)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}








void func_021C1024(u32 a, u16 b, u32 c, u32 d)
{
    u32 *r;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x18, 1, (const char *)&d_021DE3AC, 0x1e6);
    r[3] = func_021A3068((u8 *)a);
    ((struct Obj05075 *)r)->f6 = b;
    r[4] = a;
    r[5] = func_021A36E0((u8 *)a);
    if (func_021AB2E8(func_021AB0F0(c)) == 1)
        ((struct Obj05075 *)r)->f8 = 1;
    func_02030DA8(func_02188D30((u8 *)r[3]), func_021C10B4, r, 0);
}







int func_021C1094(void *a)
{
return ((struct Obj18274 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f4;
}







int func_021C10A0(u32 a)
{
func_020307B0((void *)func_02030EE8((struct S02030EE8 *)a));
return func_02030EAC(a);
}







void func_021C10B4(u32 task, Work_021C0810 *w)
{
    void *obj;
    u16 dir;
    u32 r;
    int x;
    int y;
    Vec v;
    int h;
    s16 pos[3];
    void *q;
    int step;

    obj = func_021A3074(w->f10);
    switch (w->state) {
    case 0:
        dir = func_0216D5F8(obj);
        x = func_0216D83C(obj);
        y = func_0216D86C(obj);
        func_0216D88C(obj, (struct VecFx32 *)&v);
        func_02164280(x, y, (int *)(&v));
        step = 0x10000;
        if (w->f8 == 1)
            step = 0x20000;
        func_02164208(dir, (int *)(&v), step);
        h = 0;
        func_02163E58((u32)obj, (Vec3 *)&v, &h);
        v.y = h;
        func_021A2F8C(w->f10, func_021ACB38(func_02188CD0((u8 *)w->fC), dir, &v, obj, 0));
        q = (void *)func_02188CE8((u8 *)w->fC);
        pos[0] = (v.x >> 4) / 0x1000;
        pos[1] = (v.y >> 4) / 0x1000;
        pos[2] = (v.z >> 4) / 0x1000;
        if (func_021AA900(q, pos))
            func_021AAB1C(q, 1);
        w->state++;
        break;
    case 1:
        w->count++;
        if (w->count > 15)
            w->state++;
        break;
    case 2:
        dir = func_0216D5F8(obj);
        r = func_02197E7C(dir, 0x34);
        if (w->f8 == 1)
            r = func_02197E7C(dir, 0x38);
        func_0216D410((void *)obj, r);
        w->state++;
        break;
    case 3:
        if (func_0216D454((void *)obj) == 0)
            break;
        func_0216D480(obj);
        func_021ACBB8(func_021A2F98(w->f10), 1);
        func_021A2F48(w->f10, 4);
        w->state++;
    case 4:
        if (func_021A2F54(w->f10) == 1) {
            func_021A35A0((u32 *)w->f10, 1);
            w->f4 = 1;
            w->state++;
        }
        break;
    case 5:
        break;
    }
}






void func_021C1228(u32 a, u16 b, u32 c, u32 d)
{
    u8 *r;
    void *r7;
    Vec3 va;
    Vec3 vb;
    int out;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x4c, 1, (const char *)&d_021DE3AC, 0x2b3);
    ((struct Obj03610 *)r)->f4 = b;
    ((struct Obj03610 *)r)->f3C = a;
    ((struct Obj03610 *)r)->f40 = func_021A3068((u8 *)a);
    r7 = func_021A3074((void *)a);
    func_0216D88C(r7, (struct VecFx32 *)&va);
    vb = va;
    func_02164208(((struct Obj03610 *)r)->f4, (int *)(&vb), 0x20000);
    func_02163E58((u32)r7, &vb, &out);
    if (out > va.y)
        ((struct Obj03610 *)r)->f0 = 1;
    ((struct Obj03610 *)r)->f44 = func_021A36E0((u8 *)(((struct Obj03610 *)r)->f3C));
    func_02030DA8(func_02188D30((u8 *)(((struct Obj03610 *)r)->f40)), func_021C1988, (u32 *)r, 0);
}






int func_021C12C4(void *a)
{
return ((struct Obj18276 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f6;
}






void func_021C12D0(void *h)
{
    func_020307B0((void *)func_02030EE8(h));
    func_02030EAC((u32)h);
}






/*
 * Offsets a position by (0, 1.0, 5.0) fx32 and applies it.
 */
void func_021C12E4(u32 a, const V3 *v)
{
    V3 t = *v;

    t.y += 0x1000;
    t.z += 0x5000;
    func_0216D8E0(a, &t);
}





int func_021C1318(u8 *p)
{
    u32 k;
    void *o;
    u32 r6;
    u32 r7;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = func_021A3074(((struct Obj01665 *)p)->f3C);
    k = 1;
    func_0216DB4C(o, 1);
    func_0216D88C(o, (struct VecFx32 *)&v);
    a = v;
    b = a;
    c = a;
    func_02164208(((struct Obj01665 *)p)->f4, (int *)(&b), 0x10000);
    func_02164208(((struct Obj01665 *)p)->f4, (int *)(&c), 0x20000);
    func_02164280((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
    func_02164280((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(p + 0x24));
    *(Vec3 *)(p + 0x24) = c;
    func_02163E58((u32)o, &c, (int *)(p + 0x28));
    ((struct Obj01665 *)p)->f30 = (b.x - v.x) / 2 / 16;
    ((struct Obj01665 *)p)->f38 = (b.z - v.z) / 2 / 16;
    ((struct Obj01665 *)p)->f34 = 0x6000;
    ((struct Obj01665 *)p)->f1C = 0x1000;
    r6 = func_021A2F98((u8 *)(*(u32 *)&((struct Obj01665 *)p)->f3C));
    func_021ACBB8(r6, 2);
    if ((u16)(((struct Obj01665 *)p)->f4 + 0xfffe) <= 1)
        k = 3;
    r7 = func_02188CD0((u8 *)(((struct Obj01665 *)p)->f40));
    n = 9;
    func_021ABE30(r7, &n, 1);
    ((struct Obj01665 *)p)->f48 = func_021AD564(r7, k, r6);
    func_021C6B18(((struct Obj01665 *)p)->f40, 0x10, 0x20000);
    func_020061E4(0x6e0);
    ((struct Obj01665 *)p)->f2 = ((struct Obj01665 *)p)->f2 + 1;
    return 1;
}





int func_021C146C(u8 *p)
{
    Vec3 v;
    void *r4;
    u32 r6;

    r4 = func_021A3074(((struct Obj01359 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    v.x += ((struct Obj01359 *)p)->f30;
    v.z += ((struct Obj01359 *)p)->f38;
    func_0216D89C((u32)r4, &v);
    ((struct Obj01359 *)p)->f1C = -((struct Obj01359 *)p)->f1C;
    ((struct Obj01359 *)p)->f8 += 1;
    if (((struct Obj01359 *)p)->f8 >= 0x10) {
        ((struct Obj01359 *)p)->f8 = 0;
        ((struct Obj01359 *)p)->f1C = 0;
        ((struct Obj01359 *)p)->f2 = ((struct Obj01359 *)p)->f2 + 1;
        func_021AC154(((struct Obj01359 *)p)->f48);
        r6 = func_021A2F98((u8 *)(*(u32 *)&((struct Obj01359 *)p)->f3C));
        {
            u32 k = 2;
            if ((u16)(((struct Obj01359 *)p)->f4 + 0xfffe) <= 1)
                k = 2;
            ((struct Obj01359 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj01359 *)p)->f40)), k, r6);
        }
    }
    func_021C12E4((u32)r4, (const V3 *)(p + 0x18));
    return 0;
}





int func_021C14F8(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(((struct Obj01506 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    v.y += ((struct Obj01506 *)p)->f34;
    if (v.y >= ((struct Obj01506 *)p)->f28) {
        v.y = ((struct Obj01506 *)p)->f28;
        ((struct Obj01506 *)p)->f2 = ((struct Obj01506 *)p)->f2 + 1;
        ((struct Obj01506 *)p)->f30 = (((struct Obj01506 *)p)->f24 - v.x) / 16;
        ((struct Obj01506 *)p)->f38 = (((struct Obj01506 *)p)->f2C - v.z) / 16;
        ((struct Obj01506 *)p)->f10 = -0x8000;
        ((struct Obj01506 *)p)->f34 = 0x6000;
        ((struct Obj01506 *)p)->f10 = func_0209C0A4(-0x8000, 0xb);
        func_021C6B18(((struct Obj01506 *)p)->f40, 0x10, (u32)-0x8000 << 2);
        func_021AC154(((struct Obj01506 *)p)->f48);
    }
    func_0216D89C((u32)r4, &v);
    return 0;
}




int func_021C157C(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(((struct Obj00657 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    if (v.x < ((struct Obj00657 *)p)->f24) {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x > ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    } else {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x < ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    }
    if (v.z < ((struct Obj00657 *)p)->f2C) {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z > ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    } else {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z < ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    }
    v.y += ((struct Obj00657 *)p)->f34;
    ((struct Obj00657 *)p)->f34 += ((struct Obj00657 *)p)->f10;
    ((struct Obj00657 *)p)->f8 += 1;
    if (((struct Obj00657 *)p)->f8 >= 0x10) {
        v = *(Vec3 *)(p + 0x24);
        ((struct Obj00657 *)p)->f18 = 0;
        ((struct Obj00657 *)p)->f1C = 0;
        ((struct Obj00657 *)p)->f20 = 0;
        ((struct Obj00657 *)p)->f2 = ((struct Obj00657 *)p)->f2 + 1;
    }
    func_0216D89C((u32)r4, &v);
    func_021C12E4((u32)r4, (const V3 *)(p + 0x18));
    return 0;
}




int func_021C161C(u8 *p)
{
    void *r5;

    r5 = func_021A3074(((struct Obj04270 *)p)->f3C);
    func_0216DB4C(r5, 0);
    func_0216E014(r5, (int *)(p + 0x24), ((struct Obj04270 *)p)->f4);
    r5 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj04270 *)p)->f3C));
    func_021ACBB8((u32)r5, 1);
    ((struct Obj04270 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj04270 *)p)->f40)), 0, (u32)r5);
    func_020061E4(0x6e2);
    ((struct Obj04270 *)p)->f2 = ((struct Obj04270 *)p)->f2 + 1;
    return 0;
}




int func_021C1670(u8 *p)
{
    u32 o;

    if (((struct Obj04271 *)p)->f48 != 0 && func_021AD5CC(((struct Obj04271 *)p)->f48) == 1) {
        o = func_02188CD0((u8 *)(((struct Obj04271 *)p)->f40));
        func_021AC154(((struct Obj04271 *)p)->f48);
        func_021ABE64(o, 9);
        func_021A35A0((u32 *)(((struct Obj04271 *)p)->f3C), 1);
        ((struct Obj04271 *)p)->f48 = 0;
        ((struct Obj04271 *)p)->f6 = 1;
    }
    return 0;
}




void func_021C16AC(u8 *p)
{
    void *o;
    u32 k;
    void *r7;
    u32 t;
    Vec3 w;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = func_021A3074(((struct Obj00129 *)p)->f3C);
    switch (((struct Obj00129 *)p)->f2) {
    case 0:
        k = 1;
        func_0216DB4C(o, 1);
        func_0216D88C(o, (struct VecFx32 *)&v);
        a = v;
        b = a;
        c = a;
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&b), 0x10000);
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&c), 0x20000);
        func_02164280((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&b), 0x4000);
        func_02164280((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(&c));
        *(Vec3 *)(p + 0x24) = c;
        func_02163E58((u32)o, &c, (int *)(p + 0x28));
        ((struct Obj00129 *)p)->f30 = (b.x - v.x) / 16;
        ((struct Obj00129 *)p)->f38 = (b.z - v.z) / 16;
        ((struct Obj00129 *)p)->f34 = -0x6000;
        ((struct Obj00129 *)p)->f1C = 0x1000;
        r7 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
        func_021ACBB8((u32)r7, 2);
        if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
            k = 3;
        t = func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40));
        n = 9;
        func_021ABE30(t, &n, 1);
        ((struct Obj00129 *)p)->f48 = func_021AD564(t, k, (u32)r7);
        func_021C6B18(((struct Obj00129 *)p)->f40, 0x10, 0x20000);
        func_020061E4(0x6e1);
        ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
    case 1:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        func_0216D89C((u32)o, &w);
        ((struct Obj00129 *)p)->f1C = -((struct Obj00129 *)p)->f1C;
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            ((struct Obj00129 *)p)->f8 = 0;
            ((struct Obj00129 *)p)->f1C = 0;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            func_021AC154(((struct Obj00129 *)p)->f48);
            r7 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
            {
                u32 k2 = 2;
                if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
                    k2 = 2;
                ((struct Obj00129 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40)), k2, (u32)r7);
            }
        }
        func_021C12E4((u32)o, (const V3 *)(p + 0x18));
        break;
    case 2:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.y += ((struct Obj00129 *)p)->f34;
        if (w.y <= ((struct Obj00129 *)p)->f28) {
            w.y = ((struct Obj00129 *)p)->f28;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            ((struct Obj00129 *)p)->f30 = (((struct Obj00129 *)p)->f24 - w.x) / 16;
            ((struct Obj00129 *)p)->f38 = (((struct Obj00129 *)p)->f2C - w.z) / 16;
            func_021C6B18(((struct Obj00129 *)p)->f40, 0x10, -0x20000);
            func_021AC154(((struct Obj00129 *)p)->f48);
            r7 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
            func_021ACBB8((u32)r7, 1);
            ((struct Obj00129 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40)), 0, (u32)r7);
        }
        func_0216D89C((u32)o, &w);
        break;
    case 3:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        func_0216D89C((u32)o, &w);
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            t = func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40));
            func_0216DB4C(o, 0);
            func_0216E014(o, (int *)(p + 0x24), ((struct Obj00129 *)p)->f4);
            func_021AC154(((struct Obj00129 *)p)->f48);
            func_021ABE64(t, 9);
            func_021A35A0((u32 *)(*(u32 *)&((struct Obj00129 *)p)->f3C), 1);
            ((struct Obj00129 *)p)->f48 = 0;
            ((struct Obj00129 *)p)->f6 = 1;
            func_020061E4(0x6e2);
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
        }
        break;
    }
}
