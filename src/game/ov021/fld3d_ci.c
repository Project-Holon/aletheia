/*
 * file:     fld3d_ci.c
 * unit:     yes
 * function: func_021C1988, func_021C19B4, func_021C1A08, func_021C1A48, func_021C1A84, func_021C1A98, func_021C1AA8, func_021C1AB4, func_021C1AD0, func_021C1AEC, func_021C1AF4, func_021C1C04, func_021C1C24, func_021C1C4C, func_021C1CB0, func_021C1D18, func_021C1D68, func_021C1DCC, func_021C1E7C, func_021C21B4, func_021C223C, func_021C22AC, func_021C2320, func_021C2484, func_021C24A8, func_021C24BC, func_021C24F0, func_021C2734, func_021C2764, func_021C2784, func_021C27A4, func_021C27C0, func_021C27CC, func_021C27E8, func_021C27F4, func_021C2854, func_021C2918, func_021C2B1C, func_021C2B5C, func_021C2B98, func_021C2BD4, func_021C2BE4, func_021C2CF4, func_021C2D68, func_021C2EBC, func_021C2ECC, func_021C2EDC, func_021C2F14, func_021C2F50, func_021C2F84, func_021C30B8, func_021C30D4, func_021C313C, func_021C3158, func_021C3198, func_021C31D4, func_021C31FC, func_021C3204, func_021C3248, func_021C3250, func_021C3270, func_021C32BC, func_021C32F4, func_021C335C, func_021C3378, func_021C33A4, func_021C33E0, func_021C3400, func_021C340C, func_021C341C, func_021C3490, func_021C34B4, func_021C34C4, func_021C34F8, func_021C3510, func_021C3530, func_021C360C
 * address:  0x021C1988
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
 *   func_021C16AC  0x021C16AC  thumb  ov021
 *   d_021DA128     0x021DA128  data  ov021
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_02050B80  0x02050B80  arm
 *   d_021DE3C8     0x021DE3C8  data  ov021  a4
 *   func_02050DB8  0x02050DB8  arm
 *   func_02051230  0x02051230  arm
 *   func_02050ED4  0x02050ED4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02050BE8  0x02050BE8  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02048A24  0x02048A24  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 *   d_021DA6E8     0x021DA6E8  data  a4
 *   d_021DA6D0     0x021DA6D0  data  a4
 *   d_021DA6F4     0x021DA6F4  data  a4
 *   d_021DA6DC     0x021DA6DC  data  a4
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   func_02047E88  0x02047E88  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0203038C  0x0203038C  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DA7F4     0x021DA7F4  data  ov021  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017EAC  0x02017EAC  thumb
 *   abs_id_4A      0x0000004A  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F54E0  0x021F54E0  thumb  ov075
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02189A58  0x02189A58  thumb  ov021
 *   func_0204047C  0x0204047C  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 *   func_02030830  0x02030830  arm
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0207DD24  0x0207DD24  arm
 *   func_02188C60  0x02188C60  thumb  ov021
 *   func_021A0568  0x021A0568  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_02193068  0x02193068  thumb  ov021
 *   func_021BC5D4  0x021BC5D4  thumb  ov021
 *   func_021904D0  0x021904D0  thumb  ov021
 *   func_020414AC  0x020414AC  arm
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   d_021DA710     0x021DA710  data  ov021  a4
 *   func_0204779C  0x0204779C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02051B04  0x02051B04  arm
 *   func_020480E4  0x020480E4  arm
 *   func_020515CC  0x020515CC  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_02043658  0x02043658  arm
 *   func_02043534  0x02043534  arm
 *   func_020124F0  0x020124F0  thumb
 *   func_020437AC  0x020437AC  arm
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02006650  0x02006650  thumb
 *   func_02006B20  0x02006B20  thumb
 *   func_02006A8C  0x02006A8C  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_02043678  0x02043678  arm
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D064  0x0202D064  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_02049E34  0x02049E34  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02044F64  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E964  0x0206E964  arm
 *   func_02049DB4  0x02049DB4  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02046BE0  0x02046BE0  arm
 *   d_021DE3E4     0x021DE3E4  data  ov021  a4
 *   d_021DE3F4     0x021DE3F4  data  ov021  a4
 *   d_021DE404     0x021DE404  data  ov021  a4
 *   d_021DE40C     0x021DE40C  data  ov021  a4
 *   d_021DE418     0x021DE418  data  ov021  a4
 *   d_021DE428     0x021DE428  data  ov021  a4
 *   d_021DE43C     0x021DE43C  data  ov021  a4
 *   d_021DE448     0x021DE448  data  ov021  a4
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201F4A0  0x0201F4A0  thumb
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   func_02045C04  0x02045C04  arm
 *   d_021DA720     0x021DA720  data  ov021
 *   d_021DA700     0x021DA700  data  ov021
 *   d_021DE458     0x021DE458  data  ov021
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_0200BC4C  0x0200BC4C  thumb
 *   func_0201A9C8  0x0201A9C8  thumb
 *   func_021C38DC  0x021C38DC  thumb  ov021
 *   func_0201B9F0  0x0201B9F0  thumb
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_0200BCD8  0x0200BCD8  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC88  0x0200BC88  thumb
 *   func_021C36B0  0x021C36B0  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020173F0  0x020173F0  thumb
 *   func_0200BCA0  0x0200BCA0  thumb
 *   func_0216556C  0x0216556C  thumb  ov010
 *   func_021C3898  0x021C3898  thumb  ov021
 *   func_0200BC20  0x0200BC20  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_0200BD48  0x0200BD48  thumb
 *   func_021C385C  0x021C385C  thumb  ov021
 *   func_0200BC10  0x0200BC10  thumb
 *   func_0201850C  0x0201850C  thumb
 *   func_021C36EC  0x021C36EC  thumb  ov021
 *   func_02017E40  0x02017E40  thumb
 *   func_02018584  0x02018584  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_021C3670  0x021C3670  thumb  ov021
 *   func_020181F4  0x020181F4  thumb
 *   func_020180F4  0x020180F4  thumb
 *   d_021DA8C8     0x021DA8C8  data  ov021  a4
 */
#include "../../matched/include/Obj12917.h"
#include "../../matched/include/Obj09206.h"
#include "../../matched/include/Obj18282.h"
#include "../../matched/include/Obj04272.h"
#include "../../matched/include/Obj03528.h"
#include "../../matched/include/Obj03141.h"
#include "../../matched/include/Obj01213.h"
#include "../../matched/include/Obj04273.h"
#include "../../matched/include/Obj07558.h"
#include "../../matched/include/Obj00576.h"
#include "../../matched/include/Obj06072.h"
#include "../../matched/include/Obj01864.h"
#include "../../matched/include/Obj05076.h"
#include "../../matched/include/Obj05077.h"
#include "../../matched/include/Obj00456.h"
#include "../../matched/include/Obj00616.h"
#include "../../matched/include/Obj07228.h"
#include "../../matched/include/Obj20162.h"
#include "../../matched/include/Obj20169.h"
#include "../../matched/include/Obj20172.h"
#include "../../matched/include/Obj20174.h"
#include "../../matched/include/Obj01215.h"
#include "../../matched/include/Obj01214.h"
#include "../../matched/include/Obj09680.h"
#include "../../matched/include/Obj04276.h"
#include "../../matched/include/Obj00457.h"
#include "../../matched/include/Obj18295.h"
#include "../../matched/include/Obj18296.h"
#include "../../matched/include/Obj18297.h"
#include "../../matched/include/Obj18298.h"
#include "../../matched/include/Obj12922.h"
#include "../../matched/include/Obj03142.h"
#include "../../matched/include/Obj18300.h"
#include "../../matched/include/Obj18301.h"
#include "../../matched/include/Obj04896.h"

struct Light;
struct Rec;
struct Arg;
struct Desc;
struct Obj;
struct Ctx;
struct BigObj;
struct Evt;
struct DispConfig;
struct Obj00020;
struct G3dSys;
struct Obj_021C2764;
struct Node;
struct Obj020437AC;
struct Bmp;
struct Layer;
struct Tagged;
struct Sub0200852CObj;
struct StrObj;
struct TexKey;
struct WordSet;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct Party;
struct Payload;
struct PartyMon;
struct Blk37;
struct Obj11233;
struct Obj11232;
struct Obj06851;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef int (*Fn)(u16 *s);

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 fC;
} S;

typedef signed char s8;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef volatile unsigned short vu16;

typedef struct { int a, b, c, d; } BgMode;

typedef int (*StepFn)(int a, u8 *p);

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int f0;
    Vec v;
} Inner;

typedef struct {
    char pad0[0x20];
    Inner **f20;
    int f24;
    Vec f28;
} Obj_021C2484;

typedef struct {
    u32 w0;
    u16 h4;
    u16 h6;
    u16 a[2];
    u16 hc;
    u16 he;
    u16 b[4];
    u16 c[4];
    u32 w20;
} Src;

typedef struct {
    u32 kind;
    u16 id;
    u32 val;
} E0;

typedef struct {
    u16 idx;
    u16 zero;
} E2;

typedef struct {
    u16 idx;
    u16 zero;
    u16 idx2;
    E2 *list;
    u16 cnt;
} E1;

typedef struct {
    E0 *e0;
    E1 *e1;
    E2 *e2;
    E2 *e3;
    E0 *p10;
    u16 n10;
    E1 *p18;
    u16 n1c;
    u16 pad1e;
    u16 h20;
    u16 h22;
    u16 h24;
    u16 h26;
    u32 w28;
    u8 total;
    u8 na;
    u8 nb;
    u8 nc;
    u32 w30;
} Out;

typedef struct CharData {
    u8 pad00[0x14];
    u8 *raw;
} CharData;

typedef struct PlttData_021C21B4 {
    u8 pad00[0xc];
    u16 *raw;
} PlttData_021C21B4;

typedef struct Obj_021C2764 {
    u8 pad00[0x10];
    u16 heap;
    u16 pad12;
    void *f14;
    u8 pad18[0x88 - 0x18];
    CharData *chr;
    PlttData_021C21B4 *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
    u32 args[5];
} Obj_021C2764;

typedef struct { u32 v[4]; } T;

typedef struct {
    int se;
    u32 frame;
} Ent;

typedef struct {
    u16 heap;
    u16 pad;
    u32 a;
    u32 b;
    u16 n;
} R;

typedef unsigned long long u64;

typedef struct { u16 x, y; } P;

typedef struct { u32 v[4]; } T4;

extern void func_021C16AC(u8 *p);
extern void *func_021A572C(u8 *p);
extern void *func_0216D67C(void *a0);
extern int func_0216D83C(void *p);
extern int func_021641E8(int a);
extern int func_0216D86C(void *p);
extern int func_021641F8(int a);
extern u32 func_0216D8AC(void *p);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02050B80(u32);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_02051788(char *p);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02050DB8(u8 *p);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern u32 func_02051230(u32, u32, u32, u32);
extern int func_02051614(int **p);
extern u32 func_020307B0(void *p);
extern void func_02050ED4(void);
extern void func_02050BE8();
extern void *func_02047CFC(int a, int b, int heap);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern u32 func_02048AC4(void *ptr);
extern void func_02047E54(struct Rec *p);
extern u32 func_02047E88(u32, u32);
extern u32 func_0207ADC4(u32);
void func_02048AD0(struct Light *l);
u32 func_020489F4(u8 *a0, int i);
u32 func_02048A00(u8 *a0, int i);
u32 func_02048A18(u8 *a0, int i);
void func_02047A60(void *a0, struct Arg *a1);
u32 func_0203038C(int a);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *p);
void *func_020120F4(const struct Ctx *p);
void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
u32 func_02017E1C(void *p, u32 id, u32 v);
u32 func_02017EAC(void *p);
int func_02034AC4(signed int id);
void func_02034A5C(int id);
int *func_021F54E0(int a);
extern void *func_020124E4(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(unsigned char *p);
extern void func_0216D9A0(void *o);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216CF2C(u32 a);
extern void func_02189A58(u8 *p, u32 v);
extern void func_0204047C(int idx, unsigned short val);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207FDCC(int a);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 func_02188C64(u8 *p);
extern int func_021A01A4(u32 a, u32 b);
extern void *func_02030830(u32 heapId);
extern void func_021899F8(u8 *p, u32 v);
extern int func_02005C64(void);
extern void func_0216D5E0(int a0, int a1);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern u32 func_02188C60(u8 *p);
extern void func_021A0568(u8 *p, int force);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern u32 func_02188C54(u8 *p);
extern u32 func_02188D20(u8 *p);
extern void func_02193068(char *p);
extern void func_021BC5D4(u8 *p);
extern void func_021904D0(u8 *p);
extern void func_020414AC(int);
extern u32 *func_0216D9E4(void *c);
int func_0204779C(int *p);
int func_020478B8(void *a, int idx, int amount);
u32 func_020477A4(struct G3dSys *sys, u32 idx);
u16 func_02051B04(void *res);
extern void func_020480E4(struct Ctx *c, u32 i);
int func_020515CC(int *p, int a, int b, int c);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0208068C(u32 a);
extern void func_02030EAC(struct Node *n);
extern u8 func_020416D4(u32 layer);
u32 func_02043658(void);
extern void func_02043534(u32 a);
extern void *func_020124F0(void *p);
void func_020437AC(struct Obj020437AC *p);
void func_02006CAC(void **out);
unsigned int func_02006984(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);
int func_02006650(void);
s8 func_02006B20(u32 i);
void func_02006A8C(u32 idx, int delta);
void func_020065D8(void);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_02048A0C(u8 *a0, int i);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern int func_0202D060(void);
extern s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02046BE0(u32 a, u32 b);
extern int func_0206E62C(void *a, T *t);
extern int func_0208CC78(const char *s);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_020457B0(u32 size, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201F4A0(void *dst, void *src);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D83C(void *ptr);
extern int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern u32 func_02045C04(struct Rec *rec);
extern int func_020808F4(void);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_020061E4(u32 a);
extern int func_0200BCB8(void *e);
extern void func_0200BC4C(struct Obj_021C2764 *p, s32 i, const struct Payload *src);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern int func_021C38DC(u32 a, u32 b);
extern void func_0201B9F0(void *mon);
extern u32 func_02017988(void *p, u32 a);
extern int func_0200BCA8(u32, u32);
extern u32 func_0200BC2C(u32, u32);
extern u32 func_0200BCD8(struct Obj *p, u32 i);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0200BC88(struct Obj *p, s32 i);
extern void func_021C36B0(void *e);
extern void *func_02188C80(void *p);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *func_020173F0(u16 species, u16 level, unsigned long long id, u16 heap);
extern int func_0200BCA0(struct Obj11233 *p);
extern void func_0216556C(void);
extern void func_021C3898(u32 *, u32);
extern void func_0200BC20(struct Obj11232 *p);
extern u8 func_02012984(const struct BigObj *p);
extern void func_0216AAE4(void *sys, void *party, int season);
extern void func_0200BD48(void *a, int b);
extern int func_021C385C(void **p);
extern void func_0200BC10(struct Obj06851 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_020143CC(u32 a, u32 b);
extern u32 func_0201850C(u16 species, u16 form, u32 exp);
extern int func_021C36EC(u32 a, u32 b);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u32 func_02018584(u16 a, u16 b, u16 c);
extern void func_020185C4(void *mon);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
extern int func_021C3670(void *, u32);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_020180F4(void *p, int move);
void func_021C1988(void *a, u16 *s);
u32 func_021C19B4(u8 *a, u32 b);
u32 *func_021C1A08(u32 a);
u32 func_021C1A48(S *p);
void func_021C1A84(u8 *p);
void *func_021C1A98(u16 *p, int a, int b);
int func_021C1AA8(u32 a, u32 b, u32 c, u32 d);
int func_021C1AB4(u32 *p);
int func_021C1AD0(void *a, u32 b, u32 c, u32 d);
void func_021C1AEC(void);
u32 *func_021C1AF4(u32 a, u32 b);
void func_021C1C04(u32 *p);
int func_021C1C24(u32 a, u32 b);
void func_021C1C4C(char *p);
int func_021C1CB0(int a, char *b, int c);
int func_021C1D18(int a, char *b, int c, int d, int e, int f, int g);
int func_021C1D68(int a, int b, int c);
int func_021C1DCC(int a, char *b, int c, int d);
int func_021C1E7C(int a, int *st, u8 *ctx);
int func_021C21B4(char *p);
int func_021C223C(char *p);
int func_021C22AC(char *p);
void func_021C2320(void *a, char *p, char *q, int d);
void func_021C2484(u8 *a, u8 *b);
void func_021C24A8(char *p, int k);
void func_021C24BC(Obj_021C2484 *p);
void func_021C24F0(Out *out, u32 b, u32 heap);
void func_021C2734(void **p);
void func_021C2764(u8 *p);
void func_021C2784(void *p, u32 *done);
void func_021C27A4(u8 *p);
void func_021C27C0(char *p);
void func_021C27CC(u8 *p);
void func_021C27E8(u8 *p);
int func_021C27F4(int a, int *b);
int func_021C2854(int a, char *b);
void func_021C2918(Obj_021C2764 *p);
int func_021C2B1C(int a, int *b);
int func_021C2B5C(void *t, int *st);
int func_021C2B98(void *a, u32 *p);
int func_021C2BD4(u16 id);
void func_021C2BE4(Obj_021C2764 *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile);
int func_021C2CF4(void *a, u8 *p);
int func_021C2D68(int a, int *b);
int func_021C2EBC(u32 a, u32 b);
int func_021C2ECC(u32 a, u32 b);
int func_021C2EDC(u8 *p, const char *name);
int func_021C2F14(u8 *p, const char *name);
void func_021C2F50(char *dst, const char *src);
void func_021C2F84(int s, Obj_021C2764 *p, char *a1, char *a2, u32 c, u32 d);
int func_021C30B8(void *a, u8 *b, u32 c);
void func_021C30D4(u32 unused);
void func_021C313C(u32 a, u32 *p);
void func_021C3158(u8 *p);
void func_021C3198(void *p, u32 *done);
R *func_021C31D4(u32 heap, u32 a, u32 b);
void func_021C31FC(u32 a);
void func_021C3204(u32 *p, u32 b, u32 c);
void func_021C3248(void *a0);
void func_021C3250(void *mon);
void func_021C3270(u32 *p, u32 b, u32 c);
void func_021C32BC(void **p, void *mon);
void func_021C32F4(u32 *p, u32 b);
void func_021C335C(void **p);
int func_021C3378(void **p);
void func_021C33A4(void *a);
void func_021C33E0(void *a);
int func_021C3400(void *a);
int func_021C340C(u32 a, u32 b, u32 c, u32 d);
int func_021C341C(u32 *p, u32 b);
int func_021C3490(void **p, int i);
int func_021C34B4(void **a, int b);
u8 func_021C34C4(void **p);
void *func_021C34F8(void *a, u32 b);
u32 func_021C3510(u32 a, u32 b);
void func_021C3530(void *mon, u32 b);
void func_021C360C(void *a, u32 b);
extern Fn d_021DA128[];
extern u8 d_021DE3C8;
extern u8 d_021DE3D8;
extern const VecFx32 d_021DA6E8;
extern const VecFx32 d_021DA6D0;
extern const VecFx32 d_021DA6F4;
extern const VecFx32 d_021DA6DC;
extern const s16 d_020A1EB8[];
extern u32 d_021DA7F4[];
extern unsigned char abs_id_4A[];
extern const BgMode d_021DA710;
extern char d_021DE3E4[];
extern char d_021DE3F4[];
extern char d_021DE404[];
extern char d_021DE40C[];
extern char d_021DE418[];
extern char d_021DE428[];
extern char d_021DE43C[];
extern char d_021DE448[];
extern Ent *d_021DA720[];
extern const T d_021DA700;
extern char d_021DE458[];
extern const T4 d_021DA8C8;








/*
 * Runs the state table until a state returns other than 1.
 */
void func_021C1988(void *a, u16 *s)
{
    if (s[0] != 0) {
        while (d_021DA128[(s16)s[1]](s) == 1)
            ;
    } else {
        func_021C16AC((u8 *)s);
    }
}








/*
 * Addresses are Black-image addresses.
 */
u32 func_021C19B4(u8 *a, u32 b)
{
    u32 r6;
    u32 h;
    int x;
    int y;

    r6 = (u32)func_021A572C(a);
    h = (u32)func_0216D67C((void *)r6);
    x = func_0216D83C((void *)r6);
    x += func_021641E8(b);
    y = func_0216D86C((void *)r6);
    y += func_021641F8(b);
    return (u32)func_0216DDDC(h, (s16)x, (s16)y, (u32)func_0216D8AC((void *)r6), (u32)1, 0);
}








u32 *func_021C1A08(u32 a)
{
    u32 *r;

    r = func_02030734(a, 0x10, 1, (const char *)&d_021DE3C8, 0x2e);
    ((struct Obj12917 *)r)->f4 = a;
    func_02050B80(a);
    r[2] = (u32)func_02030734(a, 0x4800, 1, (const char *)&d_021DE3C8, 0x34);
    return r;
}








/*
 * Creates the effect instance and sets its two scale parameters.
 */
u32 func_021C1A48(S *p)
{
    u32 a;
    u32 b;
    u32 o;

    p->fC = func_02050C04(p->f8, 0x4800, 1, p->f4);
    o = func_02051788((char *)p->fC);
    a = 1 << 12;
    b = 0x384000;
    func_02048B60((struct Light *)o, &a);
    func_02048B6C((struct Light *)o, &b);
    return p->fC;
}








void func_021C1A84(u8 *p)
{
    u32 v = ((struct Obj09206 *)p)->fC;
    if (v != 0) {
        func_02050DB8((u8 *)v);
        ((struct Obj09206 *)p)->fC = 0;
    }
}








/*
 * Loads a resource with the owner's heap id (tail call).
 */
void *func_021C1A98(u16 *p, int a, int b)
{
    return (void *)func_0205121C(a, b, p[2]);
}








/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C1AA8(u32 a, u32 b, u32 c, u32 d)
{
return func_02051230(((struct Obj18282 *)((u8 *)(a)))->fC, b, c, d);
}








int func_021C1AB4(u32 *p)
{
    if (p[3] == 0)
        return 1;
    if (func_02051614((int **)p[3]) == 0)
        return 1;
    return 0;
}








int func_021C1AD0(void *a, u32 b, u32 c, u32 d)
{
func_021C1A84(a);
func_02050ED4();
func_020307B0((void *)(((struct Obj09206 *)((u8 *)(a)))->f8));
return func_020307B0(a);
}








/*
 * Tail-call thunk: forwards to func_02050BE8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1AEC(void)
{
    func_02050BE8();
}








static inline void *mk(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *tgt, int heap)
{
    VecFx32 up = *upsrc;
    return func_02048A24(a, s, c, d, e, f, g, h, pos, &up, tgt, heap);
}








static inline void *mk_persp(VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *tgt, int heap)
{
    return mk(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, pos, upsrc, tgt, heap);
}








/*
 * note:     stack slots (high to low) pos1, tgt1, pos2, tgt2, up2, up1. The caller's block
 *           locals take the top slots in textual order; each up vector is an inline helper's
 *           local, and the first call reaching the helper one inline level deeper (through
 *           mk_persp) is what puts up1 below up2. Both calls through mk directly: up1/up2
 *           swapped (2 bytes out). The zero targets need a brace initialiser in a declaration.
 *
 * Addresses are Black-image addresses.
 */
u32 *func_021C1AF4(u32 a, u32 b)
{
    u32 *r;

    r = func_02030734(a, 0x138, 1, (const char *)&d_021DE3D8, 0x158);
    r[5] = (u32)func_02047CFC(8, 2, a);
    ((struct Obj04272 *)r)->f10 = a;
    r[0] = b;
    r[6] = -1;
    {
        VecFx32 p1 = d_021DA6E8;
        VecFx32 t1 = {0, 0, 0};
        r[1] = (u32)mk_persp(&p1, &d_021DA6D0, &t1, a);
    }
    {
        VecFx32 p2 = d_021DA6F4;
        VecFx32 t2 = {0, 0, 0};
        r[2] = (u32)mk(2, 0x30000, -0x30000, -0x40000, 0x40000, 0x1000, 0x400000, 0, &p2, &d_021DA6DC, &t2, a);
    }
    r[3] = 0;
    return r;
}








/*
 * Releases the effect handles and frees the object (EXACT*: trailing pad).
 */
void func_021C1C04(u32 *p)
{
    func_02048AC4((void *)p[1]);
    func_02048AC4((void *)p[2]);
    func_02047E54((struct Rec *)p[5]);
    func_020307B0(p);
}








int func_021C1C24(u32 a, u32 b)
{
((struct Obj03528 *)((u8 *)(a)))->f18 = func_02047E88(((struct Obj03528 *)((u8 *)(a)))->f14, b);
((struct Obj03528 *)((u8 *)(a)))->f28 = (1 << 12);
((struct Obj03528 *)((u8 *)(a)))->f2C = (1 << 12);
((struct Obj03528 *)((u8 *)(a)))->f30 = (1 << 12);
func_0207ADC4((a + 52));
((struct Obj03528 *)((u8 *)(a)))->f1C = 0;
((struct Obj03528 *)((u8 *)(a)))->f20 = 0;
((struct Obj03528 *)((u8 *)(a)))->f24 = 0;
return 0;
}








void func_021C1C4C(char *p)
{
    int a;
    int n;
    int i;
    u8 k;

    if (((struct Obj03141 *)p)->fC == 0)
        func_02048AD0((struct Light *)(((struct Obj03141 *)p)->f4));
    else
        func_02048AD0((struct Light *)(((struct Obj03141 *)p)->f8));
    if (((struct Obj03141 *)p)->f18 != -1) {
        a = (int)func_020489F4((u8 *)(((struct Obj03141 *)p)->f14), (u16)(((struct Obj03141 *)p)->f18));
        n = (int)func_02048A00((u8 *)(((struct Obj03141 *)p)->f14), (u16)(((struct Obj03141 *)p)->f18));
        for (k = 0; k < n; k++) {
            i = (int)func_02048A18((u8 *)(((struct Obj03141 *)p)->f14), (u16)(a + k));
            func_02047A60((void *)i, (struct Arg *)(p + 0x1c));
        }
    }
}








int func_021C1CB0(int a, char *b, int c)
{
    int r;

    if (func_0203038C(0x15) < d_021DA7F4[c])
        return 0;
    ((struct Obj01213 *)b)->f64 = 0;
    ((struct Obj01213 *)b)->f130 = 0;
    ((struct Obj01213 *)b)->f134 = 0;
    ((struct Obj01213 *)b)->f136 = 0;
    ((struct Obj01213 *)b)->f66 = c;
    *(u32 *)&((struct Obj01213 *)b)->f128 = 0;
    *(u32 *)&((struct Obj01213 *)b)->f12C = 0;
    ((struct Obj01213 *)b)->fC = 0;
    r = (int)func_020122C0((void *)a, 0, func_021C1E7C, 0x40);
    func_021C313C((u32)b, func_020124E8((struct Obj *)r));
    return r;
}








int func_021C1D18(int a, char *b, int c, int d, int e, int f, int g)
{
    char *q;
    int r;

    r = func_021C1CB0(a, b, 3);
    if (r == 0)
        return 0;
    ((struct Obj01213 *)b)->f128 = func_021C27F4;
    ((struct Obj01213 *)b)->f12C = func_021C2854;
    q = b + 0x9c;
    ((struct Obj04273 *)q)->f8 = e;
    ((struct Obj01213 *)b)->f9C = c;
    ((struct Obj04273 *)q)->fC = f;
    ((struct Obj04273 *)q)->f4 = d;
    ((struct Obj04273 *)q)->f10 = g;
    ((struct Obj04273 *)q)->f18 = 5;
    ((struct Obj04273 *)q)->f14 = 1;
    ((struct Obj04273 *)q)->f1A = 0x1e;
    return r;
}








int func_021C1D68(int a, int b, int c)
{
    int p;
    int x5;
    int x6f;
    int x6e;
    int xe;
    int x4c;

    p = (int)func_0201AB28(func_02012934(func_020120F4((const struct Ctx *)a)), c);
    x5 = func_02017E1C((void *)p, 5, 0);
    x6f = func_02017E1C((void *)p, 0x6f, 0);
    x6e = func_02017E1C((void *)p, 0x6e, 0);
    xe = func_02017EAC((void *)p);
    x4c = func_02017E1C((void *)p, 0x4c, 0);
    return func_021C1D18(a, (char *)b, x5, x6f, x6e, xe, x4c);
}








int func_021C1DCC(int a, char *b, int c, int d)
{
    int *q;
    int r;
    int x;
    int *s;

    func_02034AC4((int)abs_id_4A);
    q = func_021F54E0(c);
    r = func_021C1CB0(a, b, (u8)(*q));
    if (r == 0) {
        func_02034A5C((int)abs_id_4A);
        return 0;
    }
    x = (int)func_020124E8((struct Obj *)r);
    func_021C313C((u32)b, (u32 *)x);
    *(int *)&((struct Obj07558 *)x)->f3C = d;
    if (q[4] != 0)
        ((struct Obj01213 *)b)->f128 = func_021C2D68;
    else
        ((struct Obj01213 *)b)->f128 = 0;
    ((struct Obj01213 *)b)->f12C = func_021C2CF4;
    *(int *)&((struct Obj01213 *)b)->fC = 2;
    s = (int *)(b + 0x9c);
    ((struct Obj01213 *)b)->f9C = q[3];
    s[1] = q[1];
    s[2] = q[2];
    if (q[4] == 1)
        s[3] = 1;
    else
        s[3] = 0;
    if (q[0] == 0xd && s[3] != 0)
        s[4] = 1;
    else
        s[4] = 0;
    func_02034A5C((int)abs_id_4A);
    return r;
}








/*
 * Addresses are Black-image addresses.
 */
int func_021C1E7C(int a, int *st, u8 *ctx)
{
    u8 *p;
    int h;
    void *sys;
    int r1v;
    int r2v;
    u32 s10;
    u32 s14;
    BgMode m;

    p = *(u8 * *)&((struct Obj06072 *)ctx)->f0;
    h = (int)func_020124E4((struct Obj *)a);
    sys = func_0201210C((void *)h);
    switch (*st) {
    case 0:
        if (((struct Obj06072 *)ctx)->f38)
            func_0216D9A0(func_02188C7C((void *)sys));
        func_021C27A4(p);
        func_021C27C0((char *)p);
        if (func_021C2BD4(((struct Obj00576 *)p)->f66) == 0)
            func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, func_021C2B1C, 0));
        (*st)++;
        break;
    case 1:
        (*st)++;
        if (((struct Obj00576 *)p)->f66 == 0xb || ((struct Obj00576 *)p)->f66 == 0x12) {
            func_0216DAC8(func_021A3074(func_02188CB4((void *)sys)), 1);
            break;
        }
        if (((struct Obj00576 *)p)->f66 == 0x11) {
            u32 x = (u32)func_0216DE94(func_02188C7C((void *)sys), (u16)((struct Obj00576 *)p)->f9C);
            if (x)
                func_0216CF2C(x);
            break;
        }
    case 2:
        func_02189A58(sys, 1);
        func_021C2764(p);
        (*st)++;
        break;
    case 3:
        if (((struct Obj00576 *)p)->f70 == 0)
            break;
        func_0204047C(0, 0);
        func_0204047C(2, 1);
        m = d_021DA710;
        func_0203FC28((struct DispConfig *)(&m));
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x4084;
        func_0207FDCC(8);
        func_0207D63C(0x04000050, 0, 4, 0, 0);
        func_02040588(2, 1);
        func_021A01A4(func_02188C64(sys), 0);
        (*st)++;
        break;
    case 4:
        func_021C2320((void *)a, (char *)p, (char *)(ctx + 4), (u8)((struct Obj00576 *)p)->f66);
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_02030830(((struct Obj00576 *)p)->f10);
        func_021899F8(sys, 1);
        if (((struct Obj06072 *)ctx)->f34)
            func_021C30D4(((struct Obj06072 *)ctx)->f34);
        (*st)++;
        break;
    case 5:
        if (func_021C2BD4(((struct Obj00576 *)p)->f66))
            func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, func_021C2B98, 0));
        else
            func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, func_021C2B5C, 0));
        (*st)++;
        break;
    case 6:
        if (func_02005C64())
            break;
        (*st)++;
    case 7:
        {
            int r7v;
            int ok;

            ((struct Obj00576 *)p)->f134 += 1;
            r7v = func_021C21B4((char *)p);
            r1v = func_021C223C((char *)p);
            r2v = func_021C22AC((char *)p);
            ((struct Obj00576 *)p)->f11C = r7v;
            ((struct Obj00576 *)p)->f120 = r1v;
            ((struct Obj00576 *)p)->f124 = r2v;
            func_021C3158(p);
            ok = 0;
            if (*(StepFn *)&((struct Obj00576 *)p)->f12C)
                ok = (*(StepFn *)(p + 0x12c))(a, p);
            else if (((struct Obj00576 *)p)->f11C && ((struct Obj00576 *)p)->f120 && ((struct Obj00576 *)p)->f124)
                ok = 1;
            if (ok == 0)
                break;
        }
        (*st)++;
        break;
    case 8:
        func_021899F8(sys, 0);
        func_021C2484(p, ctx + 4);
        if (func_021C2BD4(((struct Obj00576 *)p)->f66)) {
            void *o = func_021A3074(func_02188CB4((void *)sys));
            func_0216DAC8(o, 0);
            func_0216D5E0((int)o, 1);
            func_02189A58(sys, 0);
        } else {
            func_02040588(0, 0);
            func_0207DD24(0, 0x1f, 0x7fff, 0, 0);
        }
        func_021A01A4(func_02188C64(sys), 1);
        (*st)++;
        break;
    case 9:
        func_021A0568((u8 *)func_02188C60(sys), 1);
        ((struct Obj00576 *)p)->f74 = 0;
        func_020056A0(func_021C3198, p + 0x74, 0);
        (*st)++;
        break;
    case 10:
        if (((struct Obj00576 *)p)->f74 == 0)
            break;
        func_02030830(((struct Obj00576 *)p)->f10);
        s10 = func_02188C54(sys);
        s14 = func_02188D20(sys);
        func_02193068((char *)s10);
        func_021BC5D4((u8 *)s14);
        func_021904D0((u8 *)s10);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x1f18;
        func_020414AC(2);
        func_021C27CC(p);
        func_021C27E8(p);
        func_02189A58(sys, 0);
        if (((struct Obj06072 *)ctx)->f38)
            func_0216D9E4(func_02188C7C((void *)sys));
        (*st)++;
        break;
    case 11:
        return 1;
    }
    return 0;
}







int func_021C21B4(char *p)
{
    if (((struct Obj01864 *)p)->f64 == 0) {
        if (((struct Obj01864 *)p)->f78 == 0) {
            if (((struct Obj01864 *)p)->f5C != 0) {
                (((struct Obj01864 *)p)->f5C)--;
            } else {
                func_021C24A8(p, 0);
                ((struct Obj01864 *)p)->f78 = 1;
            }
        }
        if (((struct Obj01864 *)p)->f7C == 0) {
            if (((struct Obj01864 *)p)->f5E != 0) {
                (((struct Obj01864 *)p)->f5E)--;
            } else {
                func_021C24A8(p, 1);
                ((struct Obj01864 *)p)->f7C = 1;
            }
        }
        if (((struct Obj01864 *)p)->f78 != 0 && ((struct Obj01864 *)p)->f7C != 0)
            ((struct Obj01864 *)p)->f64 = 1;
    } else if (func_021C1AB4((u32 *)(((struct Obj01864 *)p)->f0)) != 0) {
        return 1;
    }
    return 0;
}







int func_021C223C(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05076 *)p)->f80 == 0)
        return 1;
    if (((struct Obj05076 *)p)->f60 != 0) {
        (((struct Obj05076 *)p)->f60)--;
    } else {
        a = func_02048A18((u8 *)(((struct Obj05076 *)p)->f14), (int)func_020489F4((u8 *)(((struct Obj05076 *)p)->f14), (u16)(((struct Obj05076 *)p)->f18)));
        n = func_0204779C((int *)a);
        for (k = 0; k < n; k++)
            r = func_020478B8((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}







int func_021C22AC(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05077 *)p)->f84 == 0)
        return 1;
    if (((struct Obj05077 *)p)->f62 != 0) {
        (((struct Obj05077 *)p)->f62)--;
    } else {
        a = (int)func_02048A18((u8 *)(((struct Obj05077 *)p)->f14), (u16)((int)func_020489F4((u8 *)(((struct Obj05077 *)p)->f14), (u16)(((struct Obj05077 *)p)->f18)) + 1));
        n = func_0204779C((int *)a);
        for (k = 0; k < n; k++)
            r = func_020478B8((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}







void func_021C2320(void *a, char *p, char *q, int d)
{
    int t;
    u8 i;
    int base;
    int cnt;
    u8 k;
    int h;
    int n;
    int r;

    ((struct Obj00616 *)p)->f58 = func_021C1A48((S *)((struct Obj00616 *)p)->f0);
    func_021C24F0((Out *)q, d, ((struct Obj00616 *)p)->f10);
    func_021C1C24((u32)p, (u32)(q + 0x10));
    if (((struct Obj00456 *)q)->f28 != 0xFFFF) {
        t = (int)func_021C1A98((u16 *)(((struct Obj00616 *)p)->f0), 0x73, ((struct Obj00456 *)q)->f28);
        func_021C1AA8(((struct Obj00616 *)p)->f0, t, 1, 0);
    } else {
        t = 0;
    }
    base = (int)func_020489F4((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    cnt = (int)func_02048A00((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    for (i = 0; i < cnt; i++) {
        h = (int)func_02048A18((u8 *)(((struct Obj00616 *)p)->f14), (u16)(base + i));
        n = func_0204779C((int *)h);
        for (k = 0; k < n; k++)
            func_020477A4((struct G3dSys *)h, (u8)k);
    }
    ((struct Obj00616 *)p)->f5C = ((struct Obj00456 *)q)->f20;
    ((struct Obj00616 *)p)->f5E = ((struct Obj00456 *)q)->f22;
    ((struct Obj00616 *)p)->f60 = ((struct Obj00456 *)q)->f24;
    ((struct Obj00616 *)p)->f62 = ((struct Obj00456 *)q)->f26;
    if (t != 0)
        r = func_02051B04((void *)t);
    else
        r = 0;
    if (r == 2) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 0;
    } else if (r == 1) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 1;
    } else {
        ((struct Obj00616 *)p)->f78 = 1;
        ((struct Obj00616 *)p)->f7C = 1;
    }
    ((struct Obj00616 *)p)->f80 = 0;
    ((struct Obj00616 *)p)->f84 = 0;
    if (((struct Obj00456 *)q)->f2E != 0)
        ((struct Obj00616 *)p)->f80 = 1;
    if (((struct Obj00456 *)q)->f2F != 0)
        ((struct Obj00616 *)p)->f84 = 1;
    if (((struct Obj00616 *)p)->f128 != 0) {
        h = (int)func_020124E4((struct Obj_021C2764 *)a);
        func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, a, (void *)(((struct Obj00616 *)p)->f128), (int)0));
    }
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2484(u8 *a, u8 *b)
{
func_021C2734((void **)b);
func_020480E4((struct Ctx *)(((struct Obj07228 *)((u8 *)(a)))->f14), ((((struct Obj07228 *)((u8 *)(a)))->f18 << 16) >> 16));
((struct Obj07228 *)((u8 *)(a)))->f18 = (~0);
func_021C1A84((u8 *)((struct Obj07228 *)((u8 *)(a)))->f0);
}









/*
 * EXACT*: the 72-byte listing extent runs on into the unlabelled leaf
 * func_021C24BC (ov021_func_021C24BC.c), whose EXACT entry attests the
 * pool word 0x021C24BD as matched.
 */
void func_021C24A8(char *p, int k)
{
    func_020515CC((int *)(((struct Obj20162 *)p)->f58), k, (int)func_021C24BC, 0);
}









/*
 * Unlabelled thumb leaf (push {r4} only), reached through the pool word
 * 0x021C24BD in func_021C24A8. Char-pointer offsets give the same bytes
 * scheduled differently (34 differ); the struct-typed accesses keep the
 * zero-initialiser stores ahead of the loads, as in the original.
 * Addresses are Black-image addresses.
 */
void func_021C24BC(Obj_021C2484 *p)
{
    Vec o = { 0, 0, 0 };

    o.z = 0x40;
    p->f28.x = o.x + (*p->f20)->v.x;
    p->f28.y = o.y + (*p->f20)->v.y;
    p->f28.z = o.z + (*p->f20)->v.z;
}









void func_021C24F0(Out *out, u32 b, u32 heap)
{
    Src s;
    u16 ids[8];
    u8 na, nb, nc, total, baseb, basec;
    u8 i, j, n;

    func_02048F4C(&s, 0x75, b);
    na = 0;
    for (i = 0; i < 2; i++) {
        if (s.a[i] != 0xFFFF) {
            na++;
        }
    }
    nc = 0;
    nb = 0;
    for (i = 0; i < 4; i++) {
        if (s.b[i] != 0xFFFF) {
            nb++;
        }
    }
    for (i = 0; i < 4; i++) {
        if (s.c[i] != 0xFFFF) {
            nc++;
        }
    }
    baseb = 0 + na;
    basec = baseb + nb;
    total = na + nb + nc;
    if (total != 0) {
        out->e0 = func_02030734(heap, total * 12, 1, (const char *)&d_021DE3D8, 0x566);
    }
    if (na != 0) {
        out->e1 = func_02030734(heap, na * 16, 1, (const char *)&d_021DE3D8, 0x56a);
    }
    if (nb != 0) {
        out->e2 = func_02030734(heap, nb * 4, 1, (const char *)&d_021DE3D8, 0x56e);
    }
    if (nc != 0) {
        out->e3 = func_02030734(heap, nc * 4, 1, (const char *)&d_021DE3D8, 0x572);
    }
    out->total = total;
    out->na = na;
    out->nb = nb;
    out->nc = nc;
    out->h20 = s.h4;
    out->h22 = s.h6;
    out->h24 = s.hc;
    out->h26 = s.he;
    ids[0] = s.a[0];
    ids[1] = s.a[1];
    ids[2] = s.b[0];
    ids[3] = s.b[1];
    ids[4] = s.b[2];
    ids[5] = s.c[0];
    ids[6] = s.c[1];
    ids[7] = s.c[2];
    n = 0;
    for (j = 0; j < 8; j++) {
        if (ids[j] != 0xFFFF) {
            out->e0[n].kind = 0x73;
            out->e0[n].id = ids[j];
            out->e0[n].val = 0;
            n++;
        }
    }
    for (i = 0; i < nb; i++) {
        out->e2[i].idx = baseb + i;
        out->e2[i].zero = 0;
    }
    for (i = 0; i < nc; i++) {
        out->e3[i].idx = basec + i;
        out->e3[i].zero = 0;
    }
    for (i = 0; i < na; i++) {
        out->e1[i].idx = 0 + i;
        out->e1[i].zero = 0;
        out->e1[i].idx2 = 0 + i;
    }
    if (na >= 1) {
        out->e1[0].list = out->e2;
        out->e1[0].cnt = nb;
    }
    if (na >= 2) {
        out->e1[1].list = out->e3;
        out->e1[1].cnt = nc;
    }
    out->p10 = out->e0;
    out->n10 = total;
    out->n1c = na;
    out->p18 = out->e1;
    out->w28 = s.w0;
    out->w30 = s.w20;
}









/*
 * Frees the four optional buffers (EXACT*: trailing pad).
 */
void func_021C2734(void **p)
{
    if (p[2] != 0)
        func_020307B0(p[2]);
    if (p[3] != 0)
        func_020307B0(p[3]);
    if (p[1] != 0)
        func_020307B0(p[1]);
    if (p[0] != 0)
        func_020307B0(p[0]);
}









/*
 * Clears the task slot and starts the func_021C2784 task.
 */
void func_021C2764(u8 *p)
{
    ((struct Obj20169 *)p)->f70 = 0;
    func_0208068C(8);
    func_020056A0(func_021C2784, p + 0x70, 0);
}









/*
 * VBlank task: arms display capture, ends itself, flags completion.
 */
void func_021C2784(void *p, u32 *done)
{
    *(volatile u32 *)0x04000064 = 0x81330010;
    func_02030EAC(p);
    if (done != 0)
        *done = 1;
}









/*
 * Saves the four layer priorities into p[0x6C..0x6F].
 */
void func_021C27A4(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        p[0x6C + i] = func_020416D4((u8)i);
}









void func_021C27C0(char *p)
{
    ((struct Obj20172 *)p)->f68 = func_02043658();
}









/*
 * Restores the four saved layer priorities (EXACT*: unlabelled follower).
 */
void func_021C27CC(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        func_0204047C((u8)i, p[0x6C + i]);
}









void func_021C27E8(u8 *p)
{
    func_02043534(((struct Obj20174 *)p)->f68);
}









int func_021C27F4(int a, int *b)
{
    char *p;

    p = *(char **)func_020124E8(func_020124F0((struct Obj_021C2764 *)a));
    func_0201210C(func_020124E4((struct Obj_021C2764 *)((struct Obj_021C2764 *)a)));
    switch (*b) {
    case 0:
        func_021C2918((struct Obj_021C2764 *)((int)p));
        (*b)++;
        break;
    case 1:
        func_020437AC((struct Obj020437AC *)(*(int *)&((struct Obj01215 *)p)->f90));
        func_020307B0((void *)(*(int *)&((struct Obj01215 *)p)->f94));
        func_020307B0((void *)(*(int *)&((struct Obj01215 *)p)->f98));
        (*b)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}









int func_021C2854(int a, char *b)
{
    int r;
    char *q;
    char buf[4];

    q = b + 0x9c;
    if (((struct Obj01214 *)q)->f14 != 0 && ((struct Obj01214 *)q)->f18 != 0) {
        (((struct Obj01214 *)q)->f18)--;
        if (((struct Obj01214 *)q)->f18 == 0) {
            if (((struct Obj01214 *)q)->f0 == 0x1b9) {
                func_02006CAC((void **)buf);
                ((struct Obj01214 *)q)->f1C = func_02006984(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, (unsigned int)buf);
            } else {
                ((struct Obj01214 *)q)->f1C = func_02006984(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, 0);
            }
        }
        ((struct Obj01214 *)q)->f1A = 0x1e;
        return 0;
    }
    r = 0;
    if (((struct Obj01214 *)q)->f18 == 0) {
        if (func_02006650() == 0) {
            r = 1;
        } else if (((struct Obj01214 *)q)->f1A != 0) {
            (((struct Obj01214 *)q)->f1A)--;
        } else if (func_02006B20(((struct Obj01214 *)q)->f1C) > 0) {
            func_02006A8C(((struct Obj01214 *)q)->f1C, r - 16);
        } else {
            func_020065D8();
            r = 1;
        }
    }
    if (((struct Obj09680 *)b)->f11C != 0 && ((struct Obj09680 *)b)->f120 != 0 && ((struct Obj09680 *)b)->f124 != 0 && r != 0)
        return 1;
    return 0;
}









/*
 * Twin of ov195 func_0220685C (same tile-copy body). The far argument block
 * at +0x9C needs a local pointer (`a = p->args`), and the two size calls
 * must land in int locals before the (u16) << 3 conversions.
 */
void func_021C2918(Obj_021C2764 *p)
{
    u16 heap;
    u8 *buf;
    int j;
    u32 tex;
    u32 pltt;
    u8 *src;
    u32 chrFile;
    u32 plttFile;
    void *h;
    u32 *a;
    int t1;
    int t2;
    int i;
    int k;

    heap = p->heap;
    p->canvas = func_02043678(16, 16, 32, heap);
    k = 0;
    h = (void *)func_02048A0C(p->f14, 0);
    t1 = func_02047388(h);
    t2 = func_020473B8(h);
    tex = (u16)t1 << 3;
    pltt = (u16)t2 << 3;
    a = p->args;
    chrFile = func_0202D064(func_0202D060(), a[0], a[1], a[2], a[3], 0, a[4]);
    plttFile = func_0202D0D4(func_0202D060(), a[0], a[1], a[2], a[3], 0, a[4]);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = func_02049E34(func_0202D060(), chrFile, 1, (u32)(&p->chr), heap);
    p->plttRes = func_02049F34(func_0202D060(), plttFile, (u32)(&p->pltt), heap);
    src = p->chr->raw;
    buf = func_020437D4(p->canvas);
    func_02082A7C(0, buf, 0x2000);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    func_02044F64(p->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)func_020437D4(p->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)p->pltt->raw, 0x20);
    func_02030830(p->heap);
}









int func_021C2B1C(int a, int *b)
{
    func_0201210C(func_020124E4((struct Obj_021C2764 *)((struct Obj_021C2764 *)a)));
    switch (*b) {
    case 0:
        func_0204E720(4, 0, 0x10, -1);
        (*b)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}








/*
 * Fade-out state step: start the fade, then wait for it to finish.
 */
int func_021C2B5C(void *t, int *st)
{
    func_0201210C(func_020124E4((struct Obj_021C2764 *)t));
    switch (*st) {
    case 0:
        func_0204E720(4, 0x10, 0, -1);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}








/*
 * Addresses are Black-image addresses.
 */
int func_021C2B98(void *a, u32 *p)
{
    func_0201210C(func_020124E4((struct Obj_021C2764 *)a));
    switch (p[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        p[0]++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}








/*
 * Unlabelled leaf: true for the two ids 0xC and 0x13.
 * Addresses are Black-image addresses.
 */
int func_021C2BD4(u16 id)
{
    if (id == 0xc || id == 0x13)
        return 1;
    return 0;
}








/*
 * Sibling of func_021C2918 (same object layout at +0x88..+0x98), 16x16
 * tile copy with archive 0xB4 and file ids passed in.
 */
void func_021C2BE4(Obj_021C2764 *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile)
{
    u32 tex;
    u32 pltt;
    u16 heap;
    u8 *buf;
    int j;
    void *h;
    void *t;
    u8 *src;
    int i;
    int k;

    heap = p->heap;
    k = 0;
    h = (void *)func_02048A0C(p->f14, 0);
    func_02047388(h);
    func_020473B8(h);
    t = func_0206E964(func_02046F48(h));
    tex = func_021C2EDC(t, (const char *)a1);
    pltt = func_021C2F14(t, (const char *)a2);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = func_02049DB4(0xb4, chrFile, 1, (u32)(&p->chr), heap);
    p->plttRes = func_02049F34(0xb4, plttFile, (u32)(&p->pltt), heap);
    src = p->chr->raw;
    buf = func_020437D4(p->canvas);
    func_02082A7C(0, buf, 0x2000);
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            func_02082A90(src + k * 32, buf + (i + j * 16) * 32, 32);
            k++;
        }
    }
    func_02044F64(p->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)func_020437D4(p->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)p->pltt->raw, 0x20);
    func_02030830(p->heap);
}





/*
 * func_020124E8 takes the task (the first parameter, still in r0 on the
 * path to the call): that is what keeps r0 live and puts the switch value
 * in r1.
 */
int func_021C2CF4(void *a, u8 *p)
{
    switch (((struct Obj04276 *)p)->f130) {
    case 0:
        if (((struct Obj04276 *)p)->f11C != 0 && ((struct Obj04276 *)p)->f120 != 0 && ((struct Obj04276 *)p)->f124 != 0)
            ((struct Obj04276 *)p)->f130 = ((struct Obj04276 *)p)->f130 + 1;
        break;
    case 1:
        func_0204E720(((u32 *)func_020124E8(a))[0xF] != 0 ? 0xC : 3, 0, 0x10, -1);
        ((struct Obj04276 *)p)->f130 += 1;
    case 2:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}








int func_021C2D68(int a, int *b)
{
    char **pp;
    int t;
    int s;
    char *p;
    u32 *q;
    u32 x;
    u32 y;

    pp = (void *)func_020124E8(func_020124F0((struct Obj_021C2764 *)a));
    t = (int)func_020124E4((struct Obj_021C2764 *)a);
    s = (int)func_02012944(func_020120F4((const struct Ctx *)t));
    p = *pp;
    func_0201210C((void *)t);
    q = (u32 *)(p + 0x9c);
    switch (*b) {
    case 0:
        ((struct Obj00457 *)p)->f90 = func_02043678(16, 16, 32, ((struct Obj00457 *)p)->f10);
        func_021C2BE4((struct Obj_021C2764 *)p, (u32)d_021DE3E4, (u32)d_021DE3F4, q[1], q[2]);
        (*b)++;
        break;
    case 1:
        func_020437AC(((struct Obj00457 *)p)->f90);
        func_020307B0(((struct Obj00457 *)p)->f94);
        func_020307B0(((struct Obj00457 *)p)->f98);
        func_021C2F84(s, (struct Obj_021C2764 *)p, d_021DE404, d_021DE40C, q[0], 0);
        (*b)++;
        break;
    case 2:
        if (q[3] == 0) {
            *b = 4;
            break;
        }
        ((struct Obj00457 *)p)->f90 = func_02043678(16, 16, 32, ((struct Obj00457 *)p)->f10);
        if (func_02008550((const struct Sub0200852CObj *)s) == 0) {
            x = 0;
            y = 0x16;
        } else {
            x = 1;
            y = 0x17;
        }
        func_021C2BE4((struct Obj_021C2764 *)p, (u32)d_021DE418, (u32)d_021DE428, x, y);
        (*b)++;
        break;
    case 3:
        func_020437AC(((struct Obj00457 *)p)->f90);
        func_020307B0(((struct Obj00457 *)p)->f94);
        func_020307B0(((struct Obj00457 *)p)->f98);
        func_021C2F84(s, (struct Obj_021C2764 *)p, d_021DE43C, d_021DE448, 0, q[4]);
        (*b)++;
        break;
    case 4:
        ((struct Obj00457 *)p)->f1C = 0;
        ((struct Obj00457 *)p)->f20 = 0;
        ((struct Obj00457 *)p)->f24 = 0xFFD44000;
        func_02046BE0(0, 0);
        return 1;
    }
    return 0;
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2EBC(u32 a, u32 b)
{
return (((((struct Obj18296 *)((u8 *)(b)))->f0 << 16) >> 13) + ((((struct Obj18295 *)((u8 *)(a)))->f8 << 16) >> 13));
}









int func_021C2ECC(u32 a, u32 b)
{
return ((((struct Obj18298 *)((u8 *)(b)))->f0 << 3) + ((((struct Obj18297 *)((u8 *)(a)))->f2C << 16) >> 13));
}









/*
 * Builds a request block and dispatches func_021C2EBC on success (EXACT*: pad).
 */
int func_021C2EDC(u8 *p, const char *name)
{
    T t;
    int r;

    func_021C2F50((char *)&t, name);
    if (p != 0)
        r = func_0206E62C(p + 0x3C, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return func_021C2EBC((u32)p, r);
}








int func_021C2F14(u8 *p, const char *name)
{
    T t;
    int r;

    func_021C2F50((char *)&t, name);
    if (p != 0 && ((struct Obj12922 *)p)->f34 != 0)
        r = func_0206E62C(p + ((struct Obj12922 *)p)->f34, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return func_021C2ECC((u32)p, r);
}








/*
 * Copies a name into a zeroed 16-byte request block (EXACT*: pad).
 */
void func_021C2F50(char *dst, const char *src)
{
    int n = func_0208CC78(src);
    u8 i;

    for (i = 0; i < 4; i++)
        ((u32 *)dst)[i] = 0;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}








void func_021C2F84(int s, Obj_021C2764 *p, char *a1, char *a2, u32 c, u32 d)
{
    u8 buf[0x14];
    void *x;
    void *z;
    void *y;
    void *m;
    void *h;
    u16 heap;
    void *str;
    int w;
    u16 *pl;

    h = (void *)func_02048A0C(p->f14, 0);
    heap = p->heap;
    m = func_02045B38(0, 2, 0xb0, heap);
    if (c == 0) {
        x = func_0201EC64((u16)((heap & 0x7FFF) | 0x8000));
        str = func_020457B0(8, (heap & 0x7FFF) | 0x8000);
        y = func_02045EC0(m, c);
        func_0201F02C(x, 0, (void *)s);
        func_0201F250(x, str, y);
        func_02045808(y);
        func_0201ED04(x);
    } else {
        y = func_02045EC0(m, c);
        str = func_020457B0(0x10, (heap & 0x7FFF) | 0x8000);
        func_0201F4A0(str, y);
        func_02045808(y);
    }
    w = 0;
    if (d != 0) {
        z = func_0201D7EC(0x17, 0, 0, 0, heap);
        w = func_0201D304(str, (u32)z, 0);
        func_0201D83C(z);
        w = 0x3c - w;
        if (w < 0)
            w = 0;
    }
    p->plttRes = func_02049F34(0x17, 5, (u32)(&p->pltt), heap);
    pl = p->pltt->raw;
    pl[1] = 0x7FFF;
    pl[2] = 0;
    func_0216FAB4(h, a1, pl, a2, (u32)str, w, 0, 0x440, heap, (struct TexKey *)buf);
    func_020307B0(p->plttRes);
    func_020307B0(str);
    func_02045C04(m);
}








/*
 * Runs func_021C1CB0 with kind 0x11 and stores the argument at +0x9C (EXACT*: pad).
 */
int func_021C30B8(void *a, u8 *b, u32 c)
{
    int r = func_021C1CB0((int)a, (char *)b, 0x11);

    if (r == 0)
        return 0;
    *(u32 *)&((struct Obj01213 *)b)->f9C = c;
    return r;
}








/*
 * Halves every RGB555 colour in LCDC VRAM bank 0x06860000 (0xC000 halfwords)
 * to darken the captured screen. The parameter is unused (the caller passes
 * one). The channels are extracted into u8 locals (b, g, r, a), then halved
 * as separate `x = x >> 1` statements in b, g, r order; that keeps every
 * channel in its own register so the scheduler interleaves the four chains,
 * and the halving order picks which truncation is scheduled early. Casts
 * inline in the OR expression serialise the chains instead.
 */
void func_021C30D4(u32 unused)
{
    int old = func_020808F4();
    u16 *p = (u16 *)0x06860000;
    int i;

    for (i = 0; i < 0xC000; i++) {
        u16 c = *p;
        u8 b = (c >> 10) & 0x1F;
        u8 g = (c >> 5) & 0x1F;
        u8 r = c & 0x1F;
        u8 a = (c >> 15) & 1;

        b = b >> 1;
        g = g >> 1;
        r = r >> 1;
        *p = (a << 15) | (b << 10) | (g << 5) | r;
        p++;
    }
    func_0207FDCC(old);
}








/*
 * Clears a 0x40-byte record and stores its owner (EXACT*: pad).
 */
void func_021C313C(u32 a, u32 *p)
{
    func_02082BCC(p, 0, 0x40);
    p[0] = a;
    p[14] = 0;
    p[15] = 0;
}








/*
 * Plays the next sound effect of the current cue table when its frame is
 * reached.
 */
void func_021C3158(u8 *p)
{
    Ent *t = d_021DA720[((struct Obj00576 *)p)->f66];

    if (t[((struct Obj00576 *)p)->f136].se != -1 && ((struct Obj00576 *)p)->f134 == t[((struct Obj00576 *)p)->f136].frame) {
        func_020061E4(t[((struct Obj00576 *)p)->f136].se);
        (((struct Obj00576 *)p)->f136)++;
    }
}








/*
 * VBlank task: applies the saved display setup, ends itself, flags completion.
 */
void func_021C3198(void *p, u32 *done)
{
    T t;

    func_02040588(0, 1);
    t = d_021DA700;
    func_0203FC28((struct DispConfig *)(&t));
    func_02030EAC(p);
    if (done != 0)
        *done = 1;
}








/*
 * Allocates and initialises a 0x10-byte request record.
 */
R *func_021C31D4(u32 heap, u32 a, u32 b)
{
    R *r = func_02030734(heap, 0x10, 0, d_021DE458, 0x6A);

    r->heap = heap;
    r->a = a;
    r->b = b;
    r->n = 0;
    return r;
}








/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C31FC(u32 a)
{
    func_020307B0((void *)a);
}






void func_021C3204(u32 *p, u32 b, u32 c)
{
    int n = func_0200BCB8((void *)p[2]);
    u32 m = (u32)func_0201AB28((void *)b, c);

    if (n < 2) {
        func_021C3248((void *)m);
        func_021C3250((void *)m);
        func_0200BC4C((struct Obj_021C2764 *)p[2], n, (const struct Payload *)m);
        func_0201A9C8((struct Party *)b, c);
        func_021C38DC(p[1], b);
    }
}







/*
 * Tail-call thunk: forwards to func_0201B9F0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C3248(void *a0)
{
    func_0201B9F0(a0);
}








void func_021C3250(void *mon)
{
    if (func_02017E1C(mon, 5, 0) == 0x1EC)
        func_02017988(mon, 0);
}








/*
 * Addresses are Black-image addresses.
 */
void func_021C3270(u32 *p, u32 b, u32 c)
{
    u32 m;

    if (func_0200BCA8(p[2], b) == 1) {
        m = func_0200BC2C(p[2], b);
        func_021C3530((void *)m, func_0200BCD8((struct Obj *)p[2], b));
        func_021C32BC((void **)p, (void *)m);
        func_0201A98C((void *)c, (void *)m);
        func_0200BC88((struct Obj *)p[2], b);
        func_021C36B0((void *)p[2]);
    }
}








/*
 * Returns the Pokemon's held item to the bag when it fits.
 */
void func_021C32BC(void **p, void *mon)
{
    void *bag = func_0200CA1C(func_020120F4(func_02188C80(p[1])));

    if (func_0200CED4(bag, func_02017E1C(mon, 5, 0)) == 0)
        func_0200CDE0(bag, mon);
}







void func_021C32F4(u32 *p, u32 b)
{
    u32 m = (u32)func_020173F0(1, 1, 1, ((struct Obj03142 *)p)->f0);
    u32 w;

    if (func_0200BCA0((struct Obj11233 *)p[2]) == 1) {
        func_0216556C();
        func_021C33E0((void *)p[1]);
        func_021C3898(p, m);
        func_0201A98C((void *)b, (void *)m);
        func_0200BC20((struct Obj11232 *)p[2]);
        func_020307B0((void *)m);
        w = (u32)func_020120F4(func_02188C80((void *)p[1]));
        func_0216AAE4((void *)w, (void *)b, func_02012984((const struct BigObj *)w));
    }
}







/*
 * Stops the running timer and closes the record.
 */
void func_021C335C(void **p)
{
    if (func_0200BCA0(p[2]) == 1) {
        func_0200BC20(p[2]);
        func_021C33E0(p[1]);
    }
}







int func_021C3378(void **p)
{
    func_0200BD48(p[2], 1);
    if (func_021C385C(p) == 1) {
        func_0200BC10(p[2]);
        func_021C33A4(p[1]);
        return 1;
    }
    return 0;
}







/*
 * Sets event flag 0x4139 when the party is not full.
 */
void func_021C33A4(void *a)
{
    void *g = func_020120F4(func_02188C80(a));
    void *ev = (void *)func_0201296C(g);
    void *party = func_02012934(g);

    if ((int)func_0201AA18(party) < (int)func_0201AA14(party))
        *((u16 *)func_020143CC((u32)ev, 0x4139)) = 1;
}







/*
 * Clears event flag 0x4139 (EXACT*: unlabelled follower).
 */
void func_021C33E0(void *a)
{
    *((u16 *)func_020143CC(func_0201296C(func_020120F4(func_02188C80(a))), 0x4139)) = 0;
}






/*
 * Unlabelled leaf in ov021 (the listing prints it as a `.word` run at
 * 0x021C3400, next to ov010's field-VM code); ov010's func_0215CE98 reaches
 * it across the overlay pair.  Eight-byte thunk: load [a+8] and tail-call
 * the ARM9 helper.
 */
int func_021C3400(void *a)
{
    return func_0200BCA0((struct Obj11233 *)(((struct Obj18300 *)a)->f8));
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C340C(u32 a, u32 b, u32 c, u32 d)
{
return (u8)func_0200BCB8((void *)((struct Obj18301 *)((u8 *)(a)))->f8);
}




int func_021C341C(u32 *p, u32 b)
{
    u32 m;
    u32 s0;
    u32 s1;
    u32 s2;

    if (func_0200BCA8(p[2], b) != 1)
        return 1;
    m = func_0200BC2C(p[2], b);
    s2 = func_02017E1C((void *)m, 5, 0);
    s0 = func_02017E1C((void *)m, 0x6F, 0);
    s1 = func_02017E1C((void *)m, 8, 0);
    func_02017E1C((void *)m, 0x9E, 0);
    return func_0201850C(s2, s0, func_021C3510(s1, func_0200BCD8((struct Obj *)p[2], b)));
}




/*
 * Levels gained by the slot-i day-care Pokemon (EXACT*: pad).
 */
int func_021C3490(void **p, int i)
{
    int lv = func_02017E1C((void *)func_0200BC2C((u32)p[2], i), 0x9E, 0);

    return func_021C341C((u32 *)p, i) - lv;
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C34B4(void **a, int b)
{
return ((func_021C3490((void **)a, b) + 1) * 100);
}




/*
 * Compatibility of the two deposited Pokemon, 0 when fewer than two (EXACT*: pad).
 */
u8 func_021C34C4(void **p)
{
    void *a;

    if (func_0200BCB8(p[2]) < 2)
        return 0;
    a = (void *)func_0200BC2C((u32)p[2], 0);
    return func_021C36EC((u32)a, (u32)func_0200BC2C((u32)p[2], 1));
}




void *func_021C34F8(void *a, u32 b)
{
func_0200BCA8((u32)((struct Obj04896 *)a)->f8, b);
return (void *)func_0200BC2C((u32)((struct Obj04896 *)a)->f8, b);
}




/*
 * Saturating 32-bit add (EXACT*: pad).
 */
u32 func_021C3510(u32 a, u32 b)
{
    u64 s = (u64)a + b;

    if (s > 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return s;
}




/*
 * Learnset walk as in func_021C4084. Load-bearing: lv is read from the
 * first entry copy right after it is made (the value stays in the
 * register), mv from the second copy, and mv is u32/int (u16 sinks its
 * load to the call).
 */
void func_021C3530(void *mon, u32 b)
{
    P buf[26];
    P e, d, c, a;
    u32 species;
    u32 form;
    u32 max;
    int oldlv;
    int newlv;
    u32 exp;
    int i;
    int end;
    int lv;
    u32 mv;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6f, 0);
    max = func_02018584(species, form, 100);
    oldlv = func_02017E1C(mon, 0x9e, 0);
    exp = func_021C3510(func_02017E1C(mon, 8, 0), b);
    if (max < exp)
        exp = max;
    func_02017E40(mon, 8, exp);
    func_020185C4(mon);
    i = 0;
    newlv = func_02017E1C(mon, 0x9e, 0);
    func_0201ADD0((u16)species, (u16)form, buf);
    goto test;
body:
    e = a;
    lv = e.y;
    d = a;
    mv = d.x;
    if (newlv < lv)
        return;
    if (oldlv < lv)
        func_021C360C(mon, mv);
    i++;
test:
    a = buf[i];
    c = a;
    end = 0;
    if (c.x == 0xffff && c.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}




/*
 * Addresses are Black-image addresses.
 */
void func_021C360C(void *a, u32 b)
{
    T4 t = d_021DA8C8;
    int i;

    if (b != 0 && func_021C3670(a, b) == 0) {
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(a, t.v[i], 0) == 0) {
                func_020181F4(a, b, (u8)i);
                return;
            }
        }
        func_020180F4(a, (u16)b);
    }
}
