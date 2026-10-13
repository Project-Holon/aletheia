/*
 * file:     itemmenu.c
 * unit:     yes
 * function: func_021B6EF8, func_021B7128, func_021B7250, func_021B7504, func_021B7584, func_021B75A4, func_021B761C, func_021B7640, func_021B7688, func_021B76E4, func_021B7700, func_021B77E4, func_021B7804, func_021B7868, func_021B795C, func_021B7A7C, func_021B7B08, func_021B7B80, func_021B7C88, func_021B7CD0, func_021B7D20, func_021B7D9C, func_021B7DD0, func_021B7DF4, func_021B7F38, func_021B7F54, func_021B8080, func_021B809C, func_021B80BC, func_021B80C4, func_021B811C, func_021B8134, func_021B81B0, func_021B81B8, func_021B81F4, func_021B822C, func_021B8280, func_021B832C, func_021B83A0, func_021B83B8, func_021B8600, func_021B8640, func_021B8688, func_021B86B8, func_021B8904, func_021B8990, func_021B8AF4, func_021B8B0C, func_021B8B24, func_021B8B6C, func_021B8B7C, func_021B8C1C, func_021B8CB4, func_021B8CE4, func_021B8D88, func_021B8DAC, func_021B8DCC, func_021B8E08, func_021B8E48, func_021B8E84, func_021B8EA8, func_021B8F0C, func_021B8F68, func_021B8F90, func_021B8F98, func_021B913C, func_021B9178, func_021B91FC, func_021B9280, func_021B9758, func_021B97CC, func_021B97E8, func_021B9850, func_021B9AAC, func_021B9AF8, func_021B9BA0, func_021B9BDC, func_021B9DE8, func_021B9E14, func_021B9ED8, func_021B9EF4, func_021BA028, func_021BA1D0, func_021BA218, func_021BA41C, func_021BA4A4, func_021BA654, func_021BA6A4, func_021BA6F4, func_021BA8C0, func_021BA96C, func_021BA9AC, func_021BA9C0, func_021BAAA4, func_021BAB04, func_021BACF0, func_021BADAC, func_021BADB8, func_021BADF0, func_021BAE98, func_021BAF10, func_021BAF38, func_021BAFC4, func_021BB08C, func_021BB0BC, func_021BB0F8, func_021BB1AC, func_021BB1C4, func_021BB260, func_021BB368, func_021BB398, func_021BB3F4, func_021BB580, func_021BB5A4, func_021BB5DC, func_021BB690, func_021BB6E0, func_021BB724
 * address:  0x021B6EF8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027324  0x02027324  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B6120  0x021B6120  thumb  ov070
 *   func_02020FE4  0x02020FE4  thumb
 *   func_021B6EC8  0x021B6EC8  thumb  ov070
 *   d_021BB9C4     0x021BB9C4  data  a4
 *   func_021B690C  0x021B690C  thumb  ov070
 *   func_021B6934  0x021B6934  thumb  ov070
 *   func_021B6A78  0x021B6A78  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6AD8  0x021B6AD8  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_02027858  0x02027858  thumb
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_020213E0  0x020213E0  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02035C38  0x02035C38  arm
 *   func_02051C88  0x02051C88  arm
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B63F8  0x021B63F8  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021B6554  0x021B6554  thumb  ov070
 *   func_0203633C  0x0203633C  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02006238  0x02006238  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_02021350  0x02021350  thumb
 *   func_021B6204  0x021B6204  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_021B619C  0x021B619C  thumb  ov070
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02035BA4  0x02035BA4  arm
 *   d_021BB960     0x021BB960  data  a1
 *   func_02030734  0x02030734  arm
 *   sub_02007CC8   0x02007CC8  thumb
 *   func_02020F14  0x02020F14  thumb
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   MATH_QSort     0x02081BE4  arm
 *   d_021BBBC0     0x021BBBC0  data  ov070  a1
 *   func_0202EB04  0x0202EB04  thumb
 *   func_0202E448  0x0202E448  thumb
 *   func_02012BE0  0x02012BE0  thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   func_02020F34  0x02020F34  thumb
 *   d_021BB998 0x021BB998 data ov070 a4
 *   d_021BB95C 0x021BB95C data a1
 *   func_021B624C  0x021B624C  thumb  ov070
 *   func_021B6288  0x021B6288  thumb  ov070
 *   d_021BB984     0x021BB984  data  a4
 *   func_02021D50  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021BB73C  0x021BB73C  thumb  ov070
 *   func_020310C4  0x020310C4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203FB44  0x0203FB44  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02028604  0x02028604  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02051C6C  0x02051C6C  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02036270  0x02036270  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_021B66FC 0x021B66FC thumb ov070
 *   func_0202E940  0x0202E940  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0202E9AC  0x0202E9AC  thumb
 *   func_0202EA20 0x0202EA20 thumb
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0204B98C 0x0204B98C arm
 *   func_02035C08 0x02035C08 arm
 *   d_021BB978 0x021BB978 data a4
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02012B70 0x02012B70 thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   d_021BBB40     0x021BBB40  data  a4
 *   d_021BBB60     0x021BBB60  data  a4
 *   d_021BBB80     0x021BBB80  data  a4
 *   d_021BBB20     0x021BBB20  data  a4
 *   d_021BBAC0     0x021BBAC0  data  a4
 *   d_021BBAE0     0x021BBAE0  data  a4
 *   d_021BBB00     0x021BBB00  data  a4
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   d_021BBBE0  0x021BBBE0  data a4
 *   d_021BBA8C  0x021BBA8C  data  ov070
 *   d_021BBAB0  0x021BBAB0  data a4
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_0201C1C8  0x0201C1C8  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020456F8  0x020456F8  arm
 *   func_0202130C  0x0202130C  thumb
 *   func_02020FB4  0x02020FB4  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02020E60  0x02020E60  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204A600 0x0204A600 arm
 *   func_02027974 0x02027974 thumb
 *   func_02043678  0x02043678  arm
 *   func_02021288  0x02021288  thumb
 *   func_02045730  0x02045730  arm
 *   d_021BBA79     0x021BBA79  data  ov070  a1
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B908  0x0204B908  arm
 *   func_0204ABBC  0x0204ABBC  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_0202EE0C  0x0202EE0C  thumb
 *   d_021BBAA8     0x021BBAA8  data  ov070  a1
 *   d_021BBA6C     0x021BBA6C  data  a1
 *   d_021BBA68     0x021BBA68  data  a1
 *   d_021BBA64     0x021BBA64  data  ov070  a1
 *   d_021BBA74     0x021BBA74  data  a1
 *   d_021BBBCC     0x021BBBCC  data  a2
 *   d_021BBA81     0x021BBA81  data  a1
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02027778  0x02027778  thumb
 *   func_020499D4  0x020499D4  arm
 *   func_0201C158  0x0201C158  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   func_0201C1F4  0x0201C1F4  thumb
 *   func_02043AF4  0x02043AF4  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201F14C  0x0201F14C  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0200C274 0x0200C274 thumb
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02041090  0x02041090  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_020056BC  0x020056BC  thumb
 *   func_0202173C  0x0202173C  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0201C724  0x0201C724  thumb
 */
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj20665.h"
#include "../../matched/include/Obj20666.h"
#include "../../matched/include/Obj20667.h"
#include "../../matched/include/Obj04328.h"
#include "../../matched/include/Obj20669.h"
#include "../../matched/include/Obj07689.h"
#include "../../matched/include/Obj20670.h"
#include "../../matched/include/Obj01365.h"
#include "../../matched/include/Obj07690.h"
#include "../../matched/include/Obj20671.h"
#include "../../matched/include/Obj04331.h"
#include "../../matched/include/Obj09878.h"
#include "../../matched/include/Obj09879.h"
#include "../../matched/include/Obj06174.h"
#include "../../matched/include/Obj04332.h"
#include "../../matched/include/Obj06175.h"
#include "../../matched/include/Obj20672.h"
#include "../../matched/include/Obj01682.h"
#include "../../matched/include/Obj01516.h"
#include "../../matched/include/Obj01041.h"
#include "../../matched/include/Obj13157.h"
#include "../../matched/include/Obj00963.h"
#include "../../matched/include/Obj01514.h"
#include "../../matched/include/Obj09880.h"
#include "../../matched/include/Obj13158.h"
#include "../../matched/include/Obj01515.h"
#include "../../matched/include/Obj20673.h"
#include "../../matched/include/Obj09881.h"
#include "../../matched/include/Obj06176.h"
#include "../../matched/include/Obj04334.h"
#include "../../matched/include/Obj06177.h"
#include "../../matched/include/Obj06178.h"
#include "../../matched/include/Obj09882.h"
#include "../../matched/include/Obj09883.h"
#include "../../matched/include/Obj06179.h"
#include "../../matched/include/Obj13159.h"
#include "../../matched/include/Obj20676.h"
#include "../../matched/include/Obj13160.h"

#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
#define REG_GX_POWCNT_DSEL_MASK 0x8000
#define REG_GX_POWCNT_DSEL_SHIFT 15
#define P(k) (*(void **)((u32)p+(k)))
#define W(k) (*(u32 *)((u32)p+(k)))
struct MsgBank;
struct WordSet;
struct Obj;
struct TaskMenu;
struct PrintSys;
struct Ctx;
struct Row;
struct Blk34;
struct Obj_021B7D9C;
struct Rec;
struct Obj_021B7F54;
struct CodeIn;
struct S02021D50;
struct Tcbl;
struct MyItemSave;
struct Descriptor;
struct Node;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct S020315D4;
struct Obj0202EA20;
struct Actor;
struct PalAnmSlot;
struct BigObj;
struct Sub0200852CObj;
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct CharBuf;
struct Obj020437AC;
struct Bmp;
struct PtS;
struct Vec2;
struct TaskMenuTmpl;
struct Rec3;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct RangeEnt {
    u16 lo;
    u16 n;
    void (*fn)(void *);
} RangeEnt;

typedef struct Obj_021B7128 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x51C - 0x014];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x844 - 0x6AC];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    unsigned int f84C;
} Obj_021B7128;

typedef struct Obj_021B7250 Obj_021B7250;

struct Obj_021B7250 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x18 - 0x14];
    void *f018;
    unsigned char pad01C[0x20 - 0x1C];
    unsigned char f020[0x4D8];
    void (*f4F8)(Obj_021B7250 *o);
    unsigned char pad4FC[0x50C - 0x4FC];
    void *f50C;
    unsigned char pad510[0x694 - 0x510];
    void *f694;
    unsigned char pad698[0x6A4 - 0x698];
    void *f6A4;
    unsigned char pad6A8[0x80C - 0x6A8];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    int f81C;
    unsigned char pad820[0x844 - 0x820];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
    void *f850;
    unsigned char pad854[0x85C - 0x854];
    int f85C;
};

typedef signed int     s32;

typedef struct Obj_021B7504 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x844 - 0x780];
    int f844;
} Obj_021B7504;

typedef struct Obj_021B75A4 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj_021B75A4;

typedef struct Obj_021B7640 {
    unsigned char pad000[0x51C];
    void *f51C;
    unsigned char pad520[0x528 - 0x520];
    unsigned int f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj_021B7640;

typedef struct Obj_021B7688 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj_021B7688;

typedef struct Obj_021B7700 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x6A8 - 0x52C];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7700;

typedef struct Obj_021B7804 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7804;

typedef struct Obj_021B7868 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7868;

typedef struct Obj_021B8134 {
    void *f000;
    unsigned char pad004[0x80C - 0x4];
    int f80C;
    unsigned char pad810[0x814 - 0x810];
    int f814;
    int f818;
} Obj_021B8134;

typedef struct Obj_021B80C4 {
    unsigned char pad000[0x81C];
    int f81C;
    unsigned char pad820[0x850 - 0x820];
    void *f850;
} Obj_021B80C4;

typedef struct Obj_021B795C {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x7F4 - 0x6AC];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B795C;

typedef struct Obj_021B8280 Obj_021B8280;

typedef struct Obj_021B7D20 {
    unsigned char pad000[0x18];
    void *gfx;
    unsigned char pad01C[0x544 - 0x1C];
    u16 f544;
    unsigned char pad546[0x810 - 0x546];
    int timerA;
    int timerB;
    unsigned char pad818[0x84C - 0x818];
    int cell;
} Obj_021B7D20;

typedef struct Obj_021B7D9C {
    u8 pad000[0x724];
    u32 winA;
    u32 winB;
    u8 pad72C[0x7F0 - 0x72C];
    int repeat;
    int num;
} Obj_021B7D9C;

typedef struct Obj_021B7A7C Obj_021B7A7C;

typedef struct Obj_021B7B08 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x7F4 - 0x546];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7B08;

typedef struct Obj_021B7B80 {
    void *f000;
    unsigned char pad004[0x51C - 0x004];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x77C - 0x546];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7B80;

typedef struct Obj_021B7C88 Obj_021B7C88;

typedef struct Obj_021B7CD0 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj_021B7CD0;

typedef struct Item {
    u16 id;
    u16 count;
} Item;

typedef struct HitRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} HitRect;

typedef struct HitTbl {
    HitRect r[3];
} HitTbl;

typedef struct Ent {
    Item item;
    u32 key;
} Ent;

typedef struct {
    u8 pad0[0x544];
    u16 f544;
    u8 pad1[0x808 - 0x546];
    int f808;
} Work;

typedef struct Obj_021B7F54 {
    u8 pad000[0x18];
    void *save;
    u8 pad01C[0x544 - 0x1C];
    u16 heap;
    u8 pad546[0x80C - 0x546];
    u32 pocket;
} Obj_021B7F54;

typedef struct Obj_021B822C {
    unsigned char pad00[0x1C];
    int f1C;
} Obj_021B822C;

typedef struct { int v[11]; } T44;

typedef struct { unsigned char v[4]; } T4;

struct Obj_021B8280 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x4F8 - 0x14];
    void (*f4F8)(Obj_021B7250 *o);
    unsigned char pad4FC[0x80C - 0x4FC];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    unsigned char pad81C[0x844 - 0x81C];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
};

typedef struct TabTbl {
    int v[5];
} TabTbl;

typedef short s16;

typedef struct Parent {
    u8 pad00[0x34];
    u32 f34;
    u32 f38;
} Parent;

typedef struct Obj_021B8990 {
    u8 pad000[0x14];
    void *gfx;
    u8 pad018[0x4FC - 0x18];
    u32 f4FC;
    u8 pad500[0x50C - 0x500];
    u32 f50C;
    u8 pad510[0x518 - 0x510];
    u32 f518;
    u32 f51C;
    u32 f520;
    u32 f524;
    u32 f528;
    u32 f52C;
    u32 f530;
    u8 pad534[0x694 - 0x534];
    u32 f694;
    u32 f698;
    u8 pad69C[0x730 - 0x69C];
    u32 f730;
    u8 pad734[0x7E0 - 0x734];
    u32 f7E0;
    u8 pad7E4[0x80C - 0x7E4];
    int f80C;
    int f810;
    int f814;
    u8 pad818[0x838 - 0x818];
    u32 f838;
    u8 pad83C[0x844 - 0x83C];
    u32 f844;
    u8 pad848[0x84C - 0x848];
    u32 f84C;
    u8 pad850[0x86C - 0x850];
    u32 f86C;
    u32 f870;
} Obj_021B8990;

typedef void (*Callback)(void *);

typedef enum {
    GX_DISP_SELECT_SUB_MAIN = 0,
    GX_DISP_SELECT_MAIN_SUB = 1
} GXDispSelect;

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

typedef struct { u16 x, y, z; u8 a, b; } Rect;

typedef struct { u32 w[4]; } Tbl16;

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} Rect_021B9850;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect_021B9EF4;

typedef signed short s16_021BB6E0;

typedef struct {
    unsigned short a, b;
} Pt;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect_021BA6F4;

typedef struct {
    u8 v[5];
} B5;

typedef struct {
    u8 v[2];
} B2;

typedef struct {
    short x, y;
    unsigned short z;
    unsigned char d, e;
} Rect_021BA8C0;

typedef struct {
    unsigned char pad0[0x544];
    unsigned short heap;
    unsigned char pad546[0x590 - 0x546];
    int res[3];
    unsigned char pad59C[0x69C - 0x59C];
    int owner;
    unsigned char pad6A0[0x6AC - 0x6A0];
    int obj[5];
} W;

typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;

typedef signed short s16_021BACF0;

typedef signed short   s16_021BAF38;

typedef short s16_021BAFC4;

typedef struct {
    u16 w;
    u16 h;
    u16 pad[4];
    u16 d[1];
} Img;

typedef short s16_021BB260;

typedef short s16_021BB3F4;

typedef struct Args_021B86B8 {
    int f00, f04, f08;
    struct MyItemSave *f0C;
    int f10, f14[6], f2C, f30;
} Args_021B86B8;

typedef struct Obj_021B86B8 {
    int f00, f04, f08;
    int *f0C;
    int f10;
    struct MyItemSave *f14;
    int f18, f1C;
    u8 pad20[0x50C - 0x20];
    int f50C, f510, f514, f518, f51C, f520, f524, f528, f52C, f530;
    u8 pad534[0x544 - 0x534];
    u16 f544;
    u8 pad546[0x694 - 0x546];
    int f694, f698;
    u8 pad69C[0x730 - 0x69C];
    int f730;
    u8 pad734[0x7E0 - 0x734];
    int f7E0;
    u8 pad7E4[0x80C - 0x7E4];
    int f80C, f810, f814;
    u8 pad818[0x858 - 0x818];
    int f858;
    u8 pad85C[0x86C - 0x85C];
    int f86C, f870;
} Obj_021B86B8;

extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027324(u16 id);
extern void func_021B6100(char *p, int k);
extern u32 func_02020FE4(u16 a, u32 sel, u32 id);
extern int  func_021B6EC8(u16 id);
extern int  func_021B690C(u16 id);
extern void func_021B6934(u8 *p);
extern void func_021B6A78(u8 *p);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AD8(int p);
extern void func_021B6138(char *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u8 func_020355C4(void);
extern void func_02027858(struct TaskMenu *m);
extern int func_021B61B8(unsigned char *p);
extern unsigned short *func_021B616C(char *, int);
extern u32 func_020213E0(u16 v);
extern unsigned int func_0202136C(u16 v);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_02035C38(void);
extern s32 func_02051C88(struct Ctx *c);
extern s32 func_0202EA40(struct Row *p);
extern u32 func_021B63F8(u8 *p);
extern u32 func_020362DC(void);
extern int func_021B61C8(u8 *p);
extern void func_020061E4(unsigned int se);
extern void func_020355D8(u8 v);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void func_0204B878(struct Obj_021B7250 *p, u16 value);
extern int func_021B6554(void *o);
extern unsigned int func_0203633C(void);
extern void func_020414EC(u32 i);
extern int func_02006238(void);
extern int func_02035C60(void);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern u8 func_02021350(u16 id);
extern void func_021B6204(u8 *p, int a, unsigned int b, int c, int d);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_021B619C(int a, int b, unsigned int id);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void func_0204B3DC(struct Obj_021B7D9C *p, u32 v);
extern int func_02035BA4(const void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void *func_02020F14(u32 a);
extern int func_02020F20(int h, int id, u16 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *arc);
extern void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(Ent *, Ent *), void *buf);
extern void func_0202EB04(struct CodeIn *p);
extern u32 func_0202E448(u32 id);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern int func_02012BF8(int p, int a);
extern void *func_02020F34(unsigned int item, unsigned int which, unsigned int heap);
extern void func_021B624C(void *o, int a, int b);
extern void func_021B6288(struct Obj_021B8280 *o, int a, int b);
extern void func_02021D50(struct S02021D50 *p);
extern void func_0204A648();
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_021BB73C(u8 *p);
extern void func_020310C4(struct Tcbl *p);
extern void func_02030EAC(struct Node *n);
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern u32 func_0201D83C(void *ptr);
extern int func_02028604(int a0);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02051C6C(void *p);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern int func_02036270(int a0, int a1);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern void func_021B66FC(u8 *p);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern u32 func_0204B98C(struct Actor *a);
extern int func_02035C08(const void *p);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern int func_02012B70(const struct BigObj *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(int bg);
extern void func_020409B4(u32 layer);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0201DD68(void);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern u32 func_02027610(u32 a);
extern u32 func_020275F8(u32 a);
extern u8 func_02027604(u8 i);
extern u8 func_020275EC(int i);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_0201C1E8(int);
extern u8 func_0201C1C8(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_0202130C(u32 id);
extern void func_02020FB4(void *dst, u32 entry, u32 heap);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern int func_02020E60(unsigned short, int);
extern void func_0204A600(void);
extern void func_02027974(void *);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_02021288(u32 id);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B908(int, int);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *, u32);
extern void func_0207E780(void *, void *, u32);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_0201F7A8(void *, unsigned);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u8 func_0201C158(u16 move, u32 ppUp);
extern u32 func_0201BD28(u16 id, u32 field);
extern u32 func_0201C1F4(u16 id);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern signed char func_02012FFC(void);
extern int func_0201CCE4(int, int, int, int, int, int, int, int, int, int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_0201CE30(void *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0200C274(struct Blk34 *);
extern void *func_0204A380(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern int func_02062B30(void *file, void **out);
extern void func_02041090(unsigned int index, unsigned int a1, unsigned int a2, unsigned int a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
extern u32 func_020056BC(void);
extern int func_0202173C(int p, u16 mask, u16 col, s16_021BB3F4 step, u8 b, u8 c, u16 d, u32 ctx);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0203064C();
extern void *func_0203159C();
extern void func_02036370();
extern void func_0200816C();
extern int func_02008284(struct MyItemSave *p);
extern void func_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b);
extern int func_02007FA0();
extern int func_02045B38();
extern int func_0201EC64();
extern int func_0201C450();
extern int func_02028590();
extern int func_0201D7EC();
extern int func_02051B84();
extern int func_020056A0();
extern int func_0203101C();
extern int func_02027F60();
extern void func_0203D34C();
extern void func_021B6120(char *p);
void func_021B6EF8(u8 *p);
void func_021B7128(Obj_021B7128 *o);
void func_021B7250(Obj_021B7250 *o);
void func_021B7504(Obj_021B7504 *o);
void func_021B7584(int p);
void func_021B75A4(Obj_021B75A4 *o);
void func_021B761C(int p);
void func_021B7640(Obj_021B7640 *o);
void func_021B7688(Obj_021B7688 *o);
void func_021B76E4(int p);
void func_021B7700(Obj_021B7700 *o);
void func_021B77E4(int p);
void func_021B7804(Obj_021B7804 *o);
void func_021B7868(Obj_021B7868 *o);
void func_021B795C(Obj_021B795C *o);
void func_021B7A7C(Obj_021B7A7C *o);
void func_021B7B08(Obj_021B7B08 *o);
void func_021B7B80(Obj_021B7B80 *o);
void func_021B7C88(Obj_021B7C88 *o);
void func_021B7CD0(Obj_021B7CD0 *o);
void func_021B7D20(Obj_021B7D20 *o, int x);
void func_021B7D9C(u8 *p, int v);
void func_021B7DD0(u8 *p);
int func_021B7DF4(Obj_021B7D9C *o);
int func_021B7F38(Ent *a, Ent *b);
void func_021B7F54(Obj_021B7F54 *o);
void func_021B8080(u8 *p);
void func_021B809C(u8 *p);
void func_021B80BC(void *p);
void func_021B80C4(Obj_021B80C4 *o, int flag);
int func_021B811C(u8 *p);
int func_021B8134(Obj_021B8134 *o, int k);
int func_021B81B0(int x);
void func_021B81B8(u8 *p);
void func_021B81F4(u8 *p);
void func_021B822C(Obj_021B822C *o, void *rec, u16 *p, u8 *out);
void func_021B8280(struct Obj_021B8280 *p, unsigned char *q);
void func_021B832C(struct Obj_021B8280 *p);
int func_021B83A0(char *p, int value);
void func_021B83B8(u32 idx, int flag, Obj_021B8280 *o);
void func_021B8600(int u, int p);
void func_021B8640(int p);
void func_021B8688(int p);
int func_021B86B8(void *proc, int st, Args_021B86B8 *a);
int func_021B8904(int a, int b, int c, int p);
int func_021B8990(void *proc, int b, Parent *par, Obj_021B8990 *o);
void func_021B8AF4(void *p);
int func_021B8B0C(void *p);
void func_021B8B24(int p);
void func_021B8B6C(char *p);
void func_021B8B7C(int p);
void func_021B8C1C(int p, int a, int b);
void func_021B8CB4(char *p);
void func_021B8CE4(int p, int u, int a, int b);
void func_021B8D88(char *p);
int func_021B8DAC(void);
void func_021B8DCC(char *p);
void func_021B8E08(unsigned char *p);
void func_021B8E48(char *p);
void func_021B8E84(char *p);
void func_021B8EA8(int p);
void func_021B8F0C(int p);
int func_021B8F68(char *p, int value);
void func_021B8F90(void *o);
void func_021B8F98(void);
void func_021B913C(void);
void func_021B9178(char *p, int bg);
void func_021B91FC(char *p, void *bg);
void func_021B9280(u8 *p);
void func_021B9758(char *p);
void func_021B97CC(void *p, int v);
void func_021B97E8(char *p, int mode);
void func_021B9850(char *p);
void func_021B9AAC(char *p);
void func_021B9AF8(char *p);
void func_021B9BA0(char *p);
void func_021B9BDC(char *p);
void func_021B9DE8(char *p);
void func_021B9E14(char *p, int id);
void func_021B9ED8(char *p);
void func_021B9EF4(char *p);
void func_021BA028(char *p);
int func_021BA1D0(u16 x);
void func_021BA218(char *p);
void func_021BA41C(char *p);
void func_021BA4A4(char *p);
void func_021BA654(char *p);
void func_021BA6A4(char *p);
void func_021BA6F4(char *p);
void func_021BA8C0(W *p);
void func_021BA96C(int p, unsigned sel);
void func_021BA9AC(char *p);
void func_021BA9C0(u8 *p, int *tbl, int n);
void func_021BAAA4(int p, int mode);
void func_021BAB04(u8 *p, int x);
void func_021BACF0(int p, int mode);
void func_021BADAC(void *p);
void func_021BADB8(char *p, unsigned v);
int func_021BADF0(int p);
void func_021BAE98(int p);
void func_021BAF10(char *p);
void func_021BAF38(int p, int val);
void func_021BAFC4(u8 *p);
void func_021BB08C(char *p);
void func_021BB0BC(char *p);
void func_021BB0F8(int p);
void func_021BB1AC(char *p);
void func_021BB1C4(Work *p);
void func_021BB260(u8 *p, int val);
int func_021BB368(int x);
void func_021BB398(int p, u32 val);
void func_021BB3F4(int p, int mode);
void func_021BB580(char *p, int v);
void func_021BB5A4(char *p);
void func_021BB5DC(int p, int mode);
int func_021BB690(const char *p);
void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16_021BB6E0 y, u16 color);
void func_021BB724(void **p);
extern const RangeEnt d_021BB9C4[8];
extern HitTbl d_021BB960;
extern char d_021BBBC0[];
extern T44 d_021BB998;
extern T4 d_021BB95C;
extern const TabTbl d_021BB984;
extern const char d_021BB978[];
extern const BgTemplate d_021BBB40;
extern const BgTemplate d_021BBB60;
extern const BgTemplate d_021BBB80;
extern const BgTemplate d_021BBB20;
extern const BgTemplate d_021BBAC0;
extern const BgTemplate d_021BBAE0;
extern const BgTemplate d_021BBB00;
extern u8 d_021BBBE0[];
extern u8 d_021BBA8C[];
extern const Tbl16 d_021BBAB0;
extern const u8 d_021BBA79[];
extern const B5 d_021BBAA8;
extern const B5 d_021BBA6C;
extern const B2 d_021BBA68;
extern const B2 d_021BBA64;
extern unsigned char d_021BBA74[];
extern short d_021BBBCC[][2];
extern unsigned char d_021BBA81[];
extern char d_021BBA04[];








/*
 * The switch arms are in the original's layout order (0,1,3,4-5,2,8,9,6,7);
 * the table entry at 0x021BB9C8 is d_021BB9C4[i].fn, one extern through
 * its field (the pool word is the symbol + 4).
 */
void func_021B6EF8(u8 *p)
{
    int flag = 0;
    u32 x;
    int r;

    if (func_021BADF0((int)p) == 0)
        return;
    if (func_020279E8(((struct Obj00002 *)p)->f77C)) {
        x = *(u32 *)(p + 0x828 + func_02027A04(((struct Obj00002 *)p)->f77C) * 4);
        ((struct Obj00002 *)p)->f848 = x;
        switch (x) {
        case 0:
            func_021BB580((char *)p, 0);
            if (*(u32 *)&((struct Obj00002 *)p)->f80C != 4)
                func_02027324(((struct Obj00002 *)p)->f84C);
            if (*(u32 *)&((struct Obj00002 *)p)->f80C == 2) {
                func_021B6100((char *)p, (int)((void *)func_021B7640));
            } else if (func_02020FE4(((struct Obj00002 *)p)->f84C, 0x1D, ((struct Obj00002 *)p)->f544) == 1) {
                ((struct Obj00002 *)p)->f844 = 0xC;
                func_021B6100((char *)p, 0);
            } else if (func_021B6EC8(((struct Obj00002 *)p)->f84C) >= 0) {
                d_021BB9C4[func_021B6EC8(*(u32 *)(p + 0x84C))].fn(p);
            } else {
                r = func_021B690C(((struct Obj00002 *)p)->f84C);
                if (r == 1) {
                    func_021B6100((char *)p, (int)((void *)func_021B6934));
                } else if (r == 2) {
                    func_021B6100((char *)p, (int)((void *)func_021B6A78));
                } else {
                    ((struct Obj00002 *)p)->f844 = 5;
                    func_021B6100((char *)p, 0);
                }
            }
            break;
        case 1:
            func_021BB580((char *)p, 0);
            if (func_02028754(((struct Obj00002 *)p)->fC, 0)) {
                ((struct Obj00002 *)p)->f844 = 0xB;
                func_021B6100((char *)p, 0);
            } else {
                func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x39, (void *)(((struct Obj00002 *)p)->f524));
                func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
                func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
                func_021B6100((char *)p, (int)((void *)func_021B6AD8));
            }
            break;
        case 3:
            func_021B6100((char *)p, (int)((void *)func_021B7804));
            break;
        case 4:
        case 5:
            if (func_021B811C(p) == 1) {
                func_021B8134((Obj_021B8134 *)((struct Obj *)p), *(u32 *)&((struct Obj00002 *)p)->f810);
                func_021B6138((char *)p);
                func_021BB3F4((int)p, 1);
                func_0204B92C(((struct Obj00002 *)p)->f6A8, 1);
                func_021B8AF4(p);
            }
            break;
        case 2:
            func_021BB580((char *)p, 0);
            if ((int)((struct Obj00002 *)p)->f84C >= 0x89 && (int)((struct Obj00002 *)p)->f84C <= 0x94) {
                ((struct Obj00002 *)p)->f844 = 0x13;
                func_021B6100((char *)p, 0);
            }
            break;
        case 8:
            if (func_020355C4() == 1)
                func_021B9AAC((char *)p);
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)p), func_020355C4() == 0);
            func_021BB3F4((int)p, 1);
            func_0204B92C(((struct Obj00002 *)p)->f6A8, 1);
            func_021B8AF4(p);
            break;
        case 9:
            ((struct Obj00002 *)p)->f844 = 1;
            func_021B6100((char *)p, 0);
            break;
        case 6:
            ((struct Obj00002 *)p)->f844 = 2;
            func_021BB580((char *)p, 0);
            func_021B6100((char *)p, 0);
            break;
        case 7:
            break;
        }
        flag = 1;
    }
    if (flag) {
        func_021BA9AC((char *)p);
        func_02027858(((struct Obj00002 *)p)->f77C);
        *(u32 *)&((struct Obj00002 *)p)->f77C = 0;
    }
}









void func_021B7128(Obj_021B7128 *o)
{
    u16 *p;
    int s;

    p = (void *)func_021B616C((char *)((unsigned char *)o), func_021B61B8((unsigned char *)o));
    o->f84C = 0;
    if (p != 0)
        o->f84C = *p;
    s = o->f010;
    if (s == 2) {
        if (func_02020FE4(o->f84C, 3, o->f544) == 0 && func_020213E0(o->f84C) == 1) {
            if (func_0202136C(o->f84C) != 0)
                o->f844 = 0x12;
            else
                o->f844 = 3;
            func_021B6100((char *)o, 0);
            return;
        }
        func_02045CAC(o->f51C, 0x2F, (void *)o->f524);
        func_021B61F4((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB3F4((int)o, 0);
        func_021BB580((char *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7688));
    } else if (s == 5) {
        o->f844 = 1;
        func_021B6100((char *)o, 0);
    } else if (s == 4) {
        func_021B6100((char *)o, (int)((void *)func_021B795C));
    } else {
        func_021B832C((struct Obj_021B8280 *)((struct Obj_021B7128 *)o));
        func_021BADB8((char *)o, o->f84C);
        func_021BADAC(o);
        func_0204B92C((struct Obj *)o->f6A8, 0);
        func_021B6100((char *)o, (int)((void *)func_021B6EF8));
    }
}









void func_021B7250(Obj_021B7250 *o)
{
    unsigned int k;
    int v;

    if (func_0201C6B4(o->f50C) == 0)
        return;
    if (func_02035C38() == 0)
        o->f85C = 0;
    func_02051C88(o->f694);
    func_0202EA40(o->f850);
    if (o->f4F8 != func_021B7250)
        return;
    if (func_021B63F8((u8 *)o) != 0) {
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        return;
    }
    if (o->f85C == 1)
        return;
    if (func_020355C4() == 1) {
        k = func_020362DC();
        if (k == 0)
            return;
        if (func_021B61C8((u8 *)o) != 0) {
            if ((k & 0xC0A) == 0) {
                func_020061E4(0x548);
                func_021B9850((char *)o);
                func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
                return;
            }
        } else {
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
            if (k & 0xCD)
                return;
        }
    }
    if (func_020362DC() & 2) {
        o->f844 = 1;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C((int)o, 4, 0);
        return;
    }
    if (func_020362DC() & 0x400) {
        if (o->f010 == 2)
            return;
        o->f844 = 0;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C((int)o, 3, 0);
        return;
    }
    if (func_020362DC() & 0x800) {
        if (func_021B811C((u8 *)o) != 1)
            return;
        if (o->f80C == 4) {
            func_021B8134((Obj_021B8134 *)((struct Obj *)o), o->f810);
            func_021B6138((char *)o);
        } else {
            func_021B81B8((u8 *)o);
        }
        if (func_020355C4() != 1)
            return;
        func_021B9850((char *)o);
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
        return;
    }
    if ((func_020362DC() & 8) && o->f80C != 2 && o->f80C != 3 && func_021B61C8((u8 *)o) > 1) {
        func_021B8080((u8 *)o);
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        func_021B6100((char *)o, (int)((void *)func_021B8EA8));
        return;
    }
    if (func_020362DC() & 1) {
        if (func_021B61C8((u8 *)o) > 0) {
            func_021B6100((char *)o, (int)((void *)func_021B8B7C));
            return;
        }
    } else if (func_020362DC() & 4) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8((u8 *)o) > 1) {
            func_02082BCC(o->f020, 0, 0x4D8);
            func_02007CC8(o->f018, o->f020, o->f80C, 1);
            func_0204B878(o->f6A4, 2);
            func_021BB5DC((int)o, 0);
            o->f81C = 1;
            func_021B8B0C(o);
        }
        return;
    } else if (func_021B6554(o) != 0) {
        func_021BA6A4((char *)o);
        func_020061E4(0x548);
        func_021B6138((char *)o);
        return;
    }
    if (func_0203633C() & 0x10) {
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_020355D8(0);
        func_021B8CE4((int)o, v, 1, (int)((void *)func_021B8F90));
        return;
    }
    if (func_0203633C() & 0x20) {
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_020355D8(0);
        func_021B8CE4((int)o, v, 0, (int)((void *)func_021B8F90));
    }
}








void func_021B7504(Obj_021B7504 *o)
{
    if (func_020279E8(o->f77C) == 0)
        return;
    if (func_02027A04(o->f77C) == 0) {
        func_021BA9AC((char *)o);
        o->f844 = 6;
        func_021B6100((char *)o, 0);
    } else {
        func_021BA9AC((char *)o);
        func_020414EC(3);
        func_0204B92C((struct Obj *)o->f6A8, 1);
        func_021BB3F4((int)o, 1);
        if (func_020355C4() == 1) {
            func_021B9AAC((char *)o);
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 0);
        } else {
            func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), 1);
        }
        func_021B8AF4(o);
    }
    func_021BB1AC((char *)o);
}







void func_021B7584(int p) { if (func_021BADF0(p)) { func_021BB0F8(p); func_021B6100((void *)p,(int)((void *)func_021B7504)); } }








void func_021B75A4(Obj_021B75A4 *o)
{
    if (func_02006238() == 1)
        return;
    if ((func_020362DC() & 3) == 0 && func_02035C60() == 0)
        return;
    func_02045CAC(o->f51C, 0x3E, (void *)o->f524);
    func_0201EF34(o->f520, 0, func_020212B0(o->f84C));
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BACF0((int)o, 1);
    func_021B6100((char *)o, (int)((void *)func_021B7584));
}







void func_021B761C(int p) { if (func_021BADF0(p)) { func_020061E4(0x55C); func_021B6100((void *)p,(int)((void *)func_021B75A4)); } }







void func_021B7640(Obj_021B7640 *o)
{
    if (func_02021350(o->f84C) == 0xFF)
        func_02045CAC(o->f51C, 0x3C, (void *)o->f528);
    else
        func_02045CAC(o->f51C, 0x3D, (void *)o->f528);
    func_021BACF0((int)o, 1);
    func_021B6100((char *)o, (int)((void *)func_021B761C));
}







void func_021B7688(Obj_021B7688 *o)
{
    if ((func_020362DC() & 3) || func_02035C60() != 0) {
        func_020414EC(3);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        o->f83E = 1;
        func_021BA6A4((char *)o);
        func_0204B92C((struct Obj *)o->f6A8, 1);
        func_021BB3F4((int)o, 1);
        func_021B8AF4(o);
    }
}






void func_021B76E4(int p) { if (func_021BADF0(p)) func_021B6100((void *)p,(int)((void *)func_021B7688)); }







void func_021B7700(Obj_021B7700 *o)
{
    int r;
    int v;

    if (func_020279E8(o->f77C) == 0)
        return;
    r = func_02027A04(o->f77C);
    func_021BB1AC((char *)o);
    func_020414EC(3);
    if (r == 0) {
        func_020061E4(0x647);
        func_021B7D20((Obj_021B7D20 *)o, o->f7F4);
        func_02045CAC(o->f51C, 0x36, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B76E4));
    } else {
        func_0204B92C((struct Obj *)o->f6A8, 1);
        v = 1;
        func_021BB3F4((int)o, 1);
        if (func_020355C4() != 0)
            v = 0;
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)o), v);
        func_021B8AF4(o);
    }
}






void func_021B77E4(int p) { if (func_021BADF0(p)) { func_021BB0F8(p); func_021B6100((void *)p,(int)((void *)func_021B7700)); } }







void func_021B7804(Obj_021B7804 *o)
{
    o->f7F4 = 1;
    func_021B7D9C((u8 *)o, 1);
    func_02045CAC(o->f51C, 0x35, (void *)o->f524);
    func_021B6204((u8 *)o, 0, o->f84C, 1, 0);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7868));
}







void func_021B7868(Obj_021B7868 *o)
{
    int r;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_021B7DF4((Obj_021B7D9C *)o) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0((u8 *)o);
        func_02045CAC(o->f51C, 0x37, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B77E4));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C((int)o, 4, (int)((void *)func_021B8DCC));
    }
}







void func_021B795C(Obj_021B795C *o)
{
    unsigned int a;
    unsigned int b;

    func_0204B92C((struct Obj *)o->f6A8, 0);
    a = func_02020FE4(o->f84C, 0, (u32)o->f544);
    b = func_02020FE4(o->f84C, 3, (u32)o->f544);
    if (a == 0 || b != 0) {
        func_021BB3F4((int)o, 0);
        func_02045CAC(o->f51C, 0x4D, (void *)o->f524);
        func_021B61F4((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB580((char *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7C88));
        return;
    }
    o->f7F4 = 1;
    func_021BB08C((char *)o);
    func_021BB3F4((int)o, 0);
    if (func_021B616C((char *)o, func_021B61B8((u8 *)o))[1] == 1) {
        func_021B6100((char *)o, (int)((void *)func_021B7B08));
        return;
    }
    func_021B7D9C((u8 *)o, 2);
    func_02045CAC(o->f51C, 0x4E, (void *)o->f524);
    func_021B61F4((u8 *)o, 0, o->f84C);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7A7C));
}







void func_021B7A7C(Obj_021B7A7C *o)
{
    int r;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_021B7DF4((Obj_021B7D9C *)o) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0((u8 *)o);
        func_021B6100((char *)o, (int)((void *)func_021B7B08));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C((int)o, 4, (int)((void *)func_021B8E08));
    }
}







void func_021B7B08(Obj_021B7B08 *o)
{
    int v;

    func_021BB0F8((int)o);
    v = func_021B619C(o->f84C, o->f7F4, o->f544);
    func_02045CAC(o->f51C, 0x4F, (void *)o->f524);
    func_0201EFA4(o->f520, 0, v, 7, 0, 1);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7B80));
}






void func_021B7B80(Obj_021B7B80 *o)
{
    int r;
    int v;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_020279E8(o->f77C) == 0)
        return;
    r = func_02027A04(o->f77C);
    func_021BB1AC((char *)o);
    switch (r) {
    case 0:
        v = func_021B619C(o->f84C, o->f7F4, o->f544);
        func_021B7D20((Obj_021B7D20 *)o, o->f7F4);
        func_0200C278((struct Blk34 *)((unsigned int)func_02012F08(o->f000)), v);
        func_020061E4(0x655);
        func_021BAFC4((u8 *)o);
        func_02045CAC(o->f51C, 0x50, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, v, 7, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B7C88));
        break;
    case 1:
        func_021B80C4((Obj_021B80C4 *)o, func_020355C4() == 0);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
        break;
    }
}






void func_021B7C88(Obj_021B7C88 *o)
{
    if (func_021BADF0((int)o) == 0)
        return;
    if (func_020362DC() & 3) {
        func_021B80C4((Obj_021B80C4 *)o, 1);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
        return;
    }
    if (func_02035C60() != 0) {
        func_021B80C4((Obj_021B80C4 *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
    }
}







void func_021B7CD0(Obj_021B7CD0 *o)
{
    func_020414EC(3);
    o->f818 = 0xFFFF;
    func_021B6138((char *)o);
    o->f83E = 1;
    func_021BA6A4((char *)o);
    func_021BB0BC((char *)o);
    func_0204B92C((struct Obj *)o->f6A8, 1);
    func_021BB3F4((int)o, 1);
    func_021B8AF4(o);
}







void func_021B7D20(Obj_021B7D20 *o, int x)
{
    int v;

    func_021B616C((char *)((unsigned char *)o), func_021B61B8((unsigned char *)o));
    func_02007F1C(o->gfx, o->cell, x, o->f544);
    if (func_02007FB8(o->gfx, o->cell, o->f544) != 0)
        return;
    if (func_021B61C8((unsigned char *)o) + 1 < 7) {
        v = o->timerA - 1;
        if (v <= 0)
            v = 0;
        o->timerA = v;
    } else {
        v = o->timerB - 1;
        if (v < -1)
            v = -1;
        o->timerB = v;
    }
}





void func_021B7D9C(u8 *p, int v) { ((struct Obj00002 *)p)->f7EC=v; func_021BB1C4((Work *)p); func_021BB260(p,((struct Obj00002 *)p)->f7F4); func_0204B3DC(((struct Obj00002 *)p)->f724, 1); func_0204B3DC(((struct Obj00002 *)p)->f728, 1); }





void func_021B7DD0(u8 *p) { func_020414EC(3); func_0204B3DC(((struct Obj00002 *)p)->f724, 0); func_0204B3DC(((struct Obj00002 *)p)->f728, 0); }






/*
 * Quantity selector input: touch buttons (hit table d_021BB960, with
 * auto-repeat accelerating after 120 frames) or the d-pad step the count at
 * +0x7F4 by 1 or 10, wrap it between 1 and the item's count, and redraw on
 * change. Returns whether any input was taken.
 */
int func_021B7DF4(Obj_021B7D9C *o)
{
    HitTbl tbl;
    Item *e;
    int saved;
    int hit;
    int changed;
    int dir;

    changed = 0;
    saved = o->num;
    e = (void *)func_021B616C((char *)((u8 *)o), func_021B61B8((u8 *)o));
    tbl = d_021BB960;
    hit = func_02035BA4(&tbl);
    if (hit != -1) {
        o->repeat++;
        changed = 1;
    } else {
        o->repeat = 0;
    }
    if (o->repeat == 1 || o->repeat > 30) {
        switch (hit) {
        case 0:
            if (o->repeat > 120)
                o->num += 10;
            else
                o->num += 1;
            dir = 0;
            break;
        case 1:
            if (o->repeat > 120)
                o->num -= 10;
            else
                o->num -= 1;
            dir = 1;
            break;
        }
    }
    if (hit == -1) {
        if (func_0203633C() & 0x40) {
            o->num += 1;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x80) {
            o->num -= 1;
            dir = 1;
            changed = 1;
        } else if (func_0203633C() & 0x10) {
            o->num += 10;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x20) {
            o->num -= 10;
            dir = 1;
            changed = 1;
        }
    }
    if (e->count < o->num)
        o->num = 1;
    else if (o->num < 1)
        o->num = e->count;
    if (o->num != saved) {
        func_020061E4(0x548);
        if (dir == 0)
            func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7D9C *)o->winA), 0xB);
        else
            func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7D9C *)o->winB), 0xA);
        func_021BB260((u8 *)o, o->num);
    }
    return changed;
}






int func_021B7F38(Ent *a, Ent *b)
{
    if (a->key == b->key)
        return 0;
    if (a->key > b->key)
        return 1;
    return -1;
}






void func_021B7F54(Obj_021B7F54 *o)
{
    int i;
    Ent *ents;
    Item *items;
    int n;
    int h;
    int rec;
    u32 x;
    Ent *e;

    ents = func_02030734(o->heap, 0x9B0, 0, d_021BBBC0, 0xB35);
    items = func_02030734(o->heap, 0x4D8, 0, d_021BBBC0, 0xB36);
    sub_02007CC8(o->save, items, o->pocket, 1);
    n = func_021B61C8((u8 *)o);
    h = (int)func_02020F14(o->heap);
    for (i = 0; i < n; i++) {
        rec = func_02020F20(h, items[i].id, o->heap);
        e = &ents[i];
        x = func_02021014((struct Rec *)rec, 0xF);
        e->key = (x << 28) + (func_02021014((struct Rec *)rec, 0x11) << 16) + items[i].id;
        e->item = items[i];
        func_020307B0((void *)rec);
    }
    func_02049238((void *)h);
    MATH_QSort(ents, n, 8, func_021B7F38, 0);
    for (i = 0; i < n; i++) {
        items[i] = ents[i].item;
    }
    sub_02007CC8(o->save, items, o->pocket, 0);
    func_020307B0(items);
    func_020307B0(ents);
}





void func_021B8080(u8 *p) { func_020061E4(0x663); func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7F54 *)(((struct Obj20665 *)p)->f72C)), 2); }





void func_021B809C(u8 *p) { func_021B7F54((Obj_021B7F54 *)((struct Obj_021B7F54 *)p)); ((struct Obj20666 *)p)->f818=0xFFFF; func_021B6138((char *)p); }





void func_021B80BC(void *p)
{
    void func_021BB5A4(char *p);
    func_021BB5A4(p);
}






void func_021B80C4(Obj_021B80C4 *o, int flag)
{
    if (o->f81C == 1)
        flag = 1;
    if (flag)
        func_020355D8(0);
    else
        func_020355D8(1);
    if (func_021B61C8((u8 *)o) == 0)
        flag = 0;
    if (flag == 0) {
        func_021BB398((int)o, 0);
    } else {
        func_021BB398((int)o, 1);
        func_0202EB04(o->f850);
    }
    func_021B97E8((char *)o, flag);
}





int func_021B811C(u8 *p) { int v = ((struct Obj20667 *)p)->f10; if (v==0 || v==1 || v==3) return 1; return 0; }






int func_021B8134(Obj_021B8134 *o, int k)
{
    u16 *p;
    int v;

    k += o->f814 + 1;
    if (o->f80C == 4) {
        if (func_021B61C8((u8 *)o) <= k)
            return 0;
        p = (void *)func_021B616C((char *)((u8 *)o), k);
        v = func_0202E448(*p);
        if (v == 0x19)
            return 0;
        if (func_021B83A0((char *)o, *p) == 1)
            func_02012BE0(o->f000, v, 0);
        else
            func_02012BE0(o->f000, v, 1);
        func_020061E4(0x646);
        o->f818 = 0xFFFF;
        return 1;
    }
    return 0;
}





int func_021B81B0(int x)
{
    int func_021BB368(int);
    return func_021BB368(x);
}





void func_021B81B8(u8 *p) { int a; int v; a=func_021B81B0(((struct Obj04328 *)p)->f80C); v=func_02012BF8(*(int *)&((struct Obj04328 *)p)->f0,a); func_02012BE0(((struct Obj04328 *)p)->f0,a,v^1); func_020061E4(0x646); func_021B81F4(p); }





void func_021B81F4(u8 *p) { if (((struct Obj04328 *)p)->f81C!=1) func_0204B878((struct Obj_021B7250 *)((struct Obj_021B7F54 *)(((struct Obj04328 *)p)->f718)), (unsigned int)func_02012BF8(*(int *)&((struct Obj04328 *)p)->f0,func_021B81B0(((struct Obj04328 *)p)->f80C))+6u); }






void func_021B822C(Obj_021B822C *o, void *rec, u16 *p, u8 *out)
{
    if (func_02021014(rec, 6) != 0) {
        if (func_0202136C(*p) == 1)
            *out = 2;
        else if (*p == 0x1C2 && o->f1C == 1)
            *out = 1;
        else
            *out = 0;
    }
    if ((u16)(*p + 0xFD98) <= 1)
        *out = 0;
}





void func_021B8280(struct Obj_021B8280 *p, unsigned char *q)
{
    unsigned short *e = (void *)func_021B616C((char *)((u8 *)p), func_021B61B8((u8 *)p));
    if (e != 0 && *e != 0) {
        void *h = func_02020F34(*e, 0, ((struct Obj00002 *)p)->f544);
        unsigned char v = ((struct Obj00002 *)p)->f80C;
        func_021B822C((Obj_021B822C *)p, h, e, q);
        if (func_021B8F68((char *)p, v) == 0 && q[0] != 2) {
            q[0] = 0xFF;
        }
        if (func_02021014(h, 3) == 0) {
            if (func_020213E0(*e) == 1) {
                q[1] = 6;
            }
            if (v != 2) {
                q[2] = 3;
            }
        }
        if (func_02021014(h, 4) != 0) {
            if (func_021B83A0((char *)p, *e) == 1) {
                q[2] = 5;
            } else {
                q[2] = 4;
            }
        }
        q[3] = 8;
        func_020307B0(h);
    }
}




/*
 * lever: func_021BA9C0 reads the count in r2; passing j keeps it in r2.
 */
void func_021B832C(struct Obj_021B8280 *p)
{
    T44 t = d_021BB998;
    T4 a = d_021BB95C;
    int tmp[4];
    int j;
    int i;
    func_021B8280((struct Obj_021B8280 *)p, (unsigned char *)(&a));
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int c = a.v[i];
        if (c != 0xFF) {
            *(int *)((char *)p + j * 4 + 0x828) = c;
            tmp[j] = t.v[a.v[i]];
            j++;
        }
    }
    func_021BA9C0((unsigned char *)p, tmp, j);
}




int func_021B83A0(char *p, int value)
{
    return func_02012BF8(((struct Obj20669 *)p)->f0, (int)func_0202E448((u16)value));
}





/*
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table d_021BB984, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of func_021B7250's key handling.
 */
void func_021B83B8(u32 idx, int flag, Obj_021B8280 *o)
{
    int tab;
    int count;
    int v;
    int saved;
    int cur;
    TabTbl t;

    tab = -1;
    count = func_021B61C8((unsigned char *)o);
    if (flag != 0)
        return;
    if (idx < 5) {
        t = d_021BB984;
        if (o->f80C != t.v[idx]) {
            tab = t.v[idx];
            func_021B80C4((Obj_021B80C4 *)o, 0);
        }
    } else if (idx == 5) {
        func_021B80C4((Obj_021B80C4 *)o, 0);
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_021B8CE4((int)o, v, 0, (int)((void *)func_021B8F90));
        return;
    } else if (idx == 6) {
        func_021B80C4((Obj_021B80C4 *)o, 0);
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_021B8CE4((int)o, v, 1, (int)((void *)func_021B8F90));
        return;
    } else if (idx == 7) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8((unsigned char *)o) > 1) {
            func_021B8080((u8 *)o);
            func_021B80C4((Obj_021B80C4 *)o, 0);
            o->f818 = 0xFFFF;
            func_021B6138((char *)o);
            func_021B6100((char *)o, (int)((void *)func_021B8EA8));
        }
    } else if (idx == 8) {
        if (func_021B811C((u8 *)o) == 1) {
            func_021B81B8((u8 *)o);
            func_021B80C4((Obj_021B80C4 *)o, 0);
            o->f818 = 0xFFFF;
            func_021B6138((char *)o);
        }
    } else if (idx == 9) {
        if (o->f010 != 2) {
            o->f844 = 0;
            o->f84C = 0;
            func_021B8C1C((int)o, 3, 0);
            func_020355D8(1);
        }
    } else if (idx == 10) {
        o->f844 = 1;
        o->f84C = 0;
        func_021B8C1C((int)o, 4, 0);
        func_020355D8(1);
    } else if (idx >= 11 && idx < 17) {
        if (o->f4F8 != func_021B7250)
            return;
        saved = o->f810;
        cur = func_021B61B8((u8 *)o);
        if (func_021B61C8((unsigned char *)o) == 0)
            return;
        if (o->f810 != idx - 11) {
            o->f810 = idx - 11;
            if (count <= func_021B61B8((u8 *)o)) {
                o->f810 = saved;
                return;
            }
        }
        func_021B624C(o, cur, func_021B61B8((u8 *)o));
        func_021B80C4((Obj_021B80C4 *)o, 0);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        func_021B9850((char *)o);
        func_021B6100((char *)o, (int)((void *)func_021B8B7C));
        return;
    } else if (idx >= 17) {
        if (func_021B811C((u8 *)o) == 1 && func_021B8134((Obj_021B8134 *)o, idx - 17) == 1) {
            func_021B80C4((Obj_021B80C4 *)o, 0);
            func_021B6138((char *)o);
        }
    }
    if (tab != -1) {
        v = o->f80C;
        o->f80C = tab;
        func_020061E4(0x7D9);
        func_021B6288((struct Obj_021B8280 *)o, v, o->f80C);
        func_021B80BC(o);
        func_021B80C4((Obj_021B80C4 *)o, 0);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
    }
}





void func_021B8600(int u, int p)
{
    int s = ((struct Obj07689 *)p)->f840;
    if (s == 1) {
        func_021B97CC((void *)p, 1);
        ((struct Obj07689 *)p)->f840 = 0;
    } else if (s == 2) {
        func_021B97CC((void *)p, 0);
        ((struct Obj07689 *)p)->f840 = 0;
    }
    func_02021D50((struct S02021D50 *)(((struct Obj07689 *)p)->f854));
    func_0204A648();
}





void func_021B8640(int p)
{
    if (func_0201C6B4((const struct PrintSys *)(*(int *)&((struct Obj00002 *)p)->f50C))) {
        func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj00002 *)p)->f544);
        func_020061E4(0x79F);
        func_021B6100((char *)p, (int)func_021B8688);
    }
}





/*
 * blocked:
 */
void func_021B8688(int p)
{
    int a = func_020221A4();
    int b = func_021BB690((const char *)p);
    if (a == 1 && b == 0) {
        func_0204B92C((struct Obj *)((struct Obj20670 *)p)->f6A8, 1);
        func_021B8AF4((void *)p);
    }
}


int func_021B86B8(void *proc, int st, Args_021B86B8 *a)
{
    Obj_021B86B8 *o; u16 i; s16 scr, cur;
    func_0203064C(1, 0xe, 0x34000);
    o = func_0203159C(proc, 0x874, 0xe);
    func_02082BCC(o, 0, 0x874);
    func_02036370(&o->f86C, &o->f870);
    o->f544 = 0xe;
    o->f858 = 1;
    o->f00 = a->f00; o->f08 = a->f08; o->f04 = a->f04;
    o->f14 = a->f0C; o->f18 = a->f10;
    o->f0C = a->f14;
    o->f10 = a->f2C; o->f1C = a->f30;
    func_0200816C(o->f18, o->f1C);
    o->f80C = func_02008284(o->f14);
    for (i = 0; i < 5; i++) {
        int n;
        func_02008270(o->f14, i, &scr, &cur);
        n = (u16)func_02007FA0(o->f18, i);
        for (;;) {
            if (scr == 0 && cur == 0) break;
            if (cur + 5 >= n && cur != 0) { cur--; continue; }
            if (scr + cur < n) break;
            if (cur != 0) cur--; else scr--;
        }
        if (i == o->f80C) { o->f810 = scr; o->f814 = cur - 1; }
        func_02008288(o->f14, i, scr, cur);
    }
    o->f51C = func_02045B38(0, 2, 3, o->f544);
    o->f524 = (int)func_020457B0(0xc8, o->f544);
    o->f528 = (int)func_020457B0(0xc8, o->f544);
    o->f52C = (int)func_020457B0(0x40, o->f544);
    o->f520 = func_0201EC64(o->f544);
    o->f50C = func_0201C450(0x40 << 6, o->f544);
    o->f518 = func_02028590(0xf, 1, 1, o->f544);
    o->f530 = func_0201D7EC(0x17, 0, 0, 0, o->f544);
    func_021B9280((u8 *)o);
    func_021B9BDC((char *)o);
    func_021B9EF4((char *)o);
    func_021BA8C0((W *)o);
    func_021B6120((char *)o);
    func_021BA028((char *)o);
    o->f694 = func_02051B84(d_021BBA04, func_021B83B8, o, o->f544);
    func_021B8B24((int)o);
    func_021B8E48((char *)o);
    o->f698 = func_020056A0(func_021B8600, o, 0);
    o->f730 = func_0203101C(o->f544, o->f544, 1, 0);
    func_021BAE98((int)o);
    o->f7E0 = func_02027F60(3, 9, o->f530, o->f50C, o->f544);
    func_0203D34C(1, o->f544);
    func_021B80C4((Obj_021B80C4 *)o, func_020355C4() ? 0 : 1);
    func_021B913C();
    func_021B6100((char *)o, (int)func_021B8640);
    return 1;
}


int func_021B8904(int a, int b, int c, int p)
{
    void (*fn)(int) = *(void (**)(int))((char *)p + 0x4F8);
    if (fn == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj01365 *)p)->f544);
        return 1;
    }
    ((struct Obj01365 *)p)->f818 = ((struct Obj01365 *)p)->f814;
    fn(p);
    if (((struct Obj01365 *)p)->f83E != 0) {
        func_021BA41C((char *)p);
        ((struct Obj01365 *)p)->f83E = 0;
    }
    if (((struct Obj01365 *)p)->f83C != 0) {
        func_021BA4A4((char *)p);
        ((struct Obj01365 *)p)->f83C = 0;
    }
    func_021B9ED8((char *)p);
    func_021BB73C((u8 *)p);
    func_020310C4((struct Tcbl *)(((struct Obj01365 *)p)->f730));
    return 0;
}








int func_021B8990(void *proc, int b, Parent *par, Obj_021B8990 *o)
{
    if (func_020221A4() != 1)
        return 0;
    if (func_0201C6B4((const struct PrintSys *)o->f50C) == 0)
        return 0;
    func_02030EAC((struct Node *)o->f698);
    func_02008298(o->gfx, o->f80C);
    func_02008288(o->gfx, (u16)o->f80C, o->f810, o->f814 + 1);
    func_02027FD8((struct TaskMenuState *)o->f7E0);
    func_021B9AF8((char *)o);
    func_021B9758((char *)o);
    func_02031140((struct S02031140 *)o->f730);
    func_02045C04((struct Rec *)o->f51C);
    func_02045808((struct U16Vec *)o->f524);
    func_02045808((struct U16Vec *)o->f528);
    func_02045808((struct U16Vec *)o->f52C);
    func_0201ED04((struct WordSet *)o->f520);
    func_021BAF10((char *)o);
    if (o->f4FC != 0) {
        func_0203FB44((int)3, (unsigned short)o->f838, (unsigned short)(o->f838 >> 16));
        func_020452E8((struct Descriptor *)o->f4FC);
    }
    func_02040DA8(3, 1, 0);
    func_0201D83C((void *)o->f530);
    func_02028604(o->f518);
    func_0201C6EC((struct PrintSys *)o->f50C);
    func_0201C4C0((struct PrintSys *)o->f50C);
    func_021B8E84((char *)o);
    func_021B8B6C((char *)o);
    func_02051C6C((void *)o->f694);
    func_020450C8();
    func_0203F9B4();
    par->f34 = o->f844;
    par->f38 = o->f84C;
    func_02036270(o->f86C, o->f870);
    func_020315D4(proc);
    func_020306F0(0xE);
    return 1;
}







void func_021B8AF4(void *p)
{
    func_021B6100(p, (int)func_021B7250);
    func_02036270(3, 6);
}







int func_021B8B0C(void *p)
{
    func_021B6100(p, (int)func_021B66FC);
    return func_02036270(3, 6);
}








void func_021B8B24(int p)
{
    void *h;
    *(struct CodeIn * *)&((struct Obj07690 *)p)->f850 =
        func_0202E940(0x10, 0x10, 0xFFFE, ((struct Obj07690 *)p)->f544);
    h = func_020490F4(0x58, ((struct Obj07690 *)p)->f544);
    func_0202E9AC(*(struct CodeIn * *)&((struct Obj07690 *)p)->f850, h, 0x15, 0x10, 0x20);
    func_02049238(h);
}







void func_021B8B6C(char *p)
{
    func_0202EA20(*(struct Obj0202EA20 * *)&((struct Obj20671 *)p)->f850);
}








void func_021B8B7C(int p)
{
    switch (((struct Obj00002 *)p)->f864) {
    case 0:
        func_020061E4(0x54C);
    case 3:
        func_021BB398(p, 0);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 1:
    case 4:
    case 6:
        ((struct Obj00002 *)p)->f866 += 1;
        if (((struct Obj00002 *)p)->f866 == 4) {
            ((struct Obj00002 *)p)->f866 = 0;
            ((struct Obj00002 *)p)->f864 += 1;
        }
        return;
    case 2:
    case 5:
        func_021BB398(p, 2);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 7:
        ((struct Obj00002 *)p)->f864 = 0;
        func_021BB398(p, 1);
        func_0202EB04((struct CodeIn *)(*(int *)&((struct Obj00002 *)p)->f850));
        func_0202EA40((struct Row *)(*(int *)&((struct Obj00002 *)p)->f850));
        func_021B6100((char *)p, (int)func_021B7128);
        return;
    }
}








void func_021B8C1C(int p, int a, int b)
{
    int x;
    if (a == 4) {
        func_020061E4(0x551);
        x = 9;
    } else if (a == 3) {
        func_020061E4(0x556);
        x = 8;
    } else if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    ((struct Obj00002 *)p)->f864 = a;
    func_0204B8C4((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), 0);
    func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710))), (unsigned short)x);
    func_0204B92C((struct Obj *)*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710), 1);
    *(int *)&((struct Obj00002 *)p)->f868 = b;
    func_021B6100((char *)p, (int)func_021B8CB4);
}







void func_021B8CB4(char *p)
{
    if (func_0204B98C((struct Actor *)(*(int *)(p + 0x710 + ((struct Obj00002 *)p)->f864 * 4))) == 0) {
        ((struct Obj00002 *)p)->f864 = 0;
        func_021B6100(p, (int)(*(Callback *)&((struct Obj00002 *)p)->f868));
    }
}








void func_021B8CE4(int p, int u, int a, int b)
{
    int x;
    func_021B6288((struct Obj_021B8280 *)((struct Obj *)p), u, ((struct Obj00002 *)p)->f80C);
    func_021B80BC((void *)p);
    func_021B81F4((u8 *)p);
    ((struct Obj00002 *)p)->f818 = 0xFFFF;
    func_021B6138((char *)p);
    if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    ((struct Obj00002 *)p)->f864 = a;
    ((struct Obj00002 *)p)->f866 = 6;
    func_0204B8C4((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), 0);
    func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710))), (unsigned short)x);
    func_0204B92C((struct Obj *)*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710), 1);
    *(int *)&((struct Obj00002 *)p)->f868 = b;
    func_021B6100((char *)p, (int)func_021B8D88);
}







void func_021B8D88(char *p)
{
    if (((struct Obj00002 *)p)->f866 == 0) {
        ((struct Obj00002 *)p)->f864 = 0;
        func_021B6100(p, (int)(*(Callback *)&((struct Obj00002 *)p)->f868));
    } else {
        ((struct Obj00002 *)p)->f866 -= 1;
    }
}







/*
 * Return-observed exception: 02035C08's legacy definition says void,
 * but the original retains its r0 result in r4 and returns it.
 */
int func_021B8DAC(void)
{
    int result;
    result = func_02035C08(d_021BB978);
    if (result != -1)
        func_020355D8(1);
    return result;
}







void func_021B8DCC(char *p)
{
    int flag;
    func_021B7DD0((unsigned char *)p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4((int)p, 1);
    flag = 1;
    if (func_020355C4())
        flag = 0;
    func_021B80C4((Obj_021B80C4 *)((struct Obj *)p), flag);
    func_021B8AF4(p);
}








void func_021B8E08(unsigned char *p)
{
    int f;
    func_021B7DD0(p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4((int)p, 1);
    f = 1;
    if (func_020355C4()) {
        f = 0;
    }
    func_021B80C4((Obj_021B80C4 *)((struct Obj *)p), f);
    func_021B6100((char *)p, (int)func_021B7CD0);
}







void func_021B8E48(char *p)
{
    *(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854 = func_02021518(((struct Obj04331 *)p)->f544);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 2, 0x200, ((struct Obj04331 *)p)->f544);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0x20, ((struct Obj04331 *)p)->f544);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0, 0x20);
}







/*
 * 02021540 forwards r0 to the allocator's free; name the pointer here
 * despite its legacy ARM9 thunk definition omitting that argument.
 */
void func_021B8E84(char *p)
{
    func_020215A0(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 0);
    func_020215A0(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 2);
    func_02021540(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854);
}








void func_021B8EA8(int p)
{
    if (func_0204B98C((struct Actor *)(*(int *)&((struct Obj00002 *)p)->f72C)) == 0) {
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C)), 0);
        func_021B809C((u8 *)p);
        func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 0);
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x8A, (void *)(*(int *)&((struct Obj00002 *)p)->f528));
        func_021BACF0(p, 0);
        func_021BB580((char *)p, 0);
        func_021BB3F4(p, 0);
        func_021B6100((char *)p, (int)func_021B8F0C);
    }
}








void func_021B8F0C(int p)
{
    if (func_020362DC() & 3) {
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)p), 1);
    } else if (func_02035C60()) {
        func_021B80C4((Obj_021B80C4 *)((struct Obj *)p), 0);
    } else {
        return;
    }
    ((struct Obj00002 *)p)->f818 = 0xFFFF;
    func_021B6138((char *)p);
    func_021BA9AC((char *)p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4(p, 1);
    func_021B8AF4((void *)p);
}







int func_021B8F68(char *p, int value)
{
    if (((struct Obj09879 *)p)->f10 == 3 || ((struct Obj09879 *)p)->f10 == 1)
        return 0;
    if (func_02012B70((const struct BigObj *)(((struct Obj09879 *)p)->f0)) == 1 && value == 4)
        return 0;
    return 1;
}








/*
 * Unlabelled tail-call stub (00 4b 18 47 + pool word) after func_021B8F68;
 * installed as a callback by func_021B7250 and at 0x021B85E0.
 */
void func_021B8F90(void *o)
{
    func_021B8AF4(o);
}








static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) |
                          (sel << REG_GX_POWCNT_DSEL_SHIFT));
}








/*
 * BG setup: GX_SetDispSelect(0), then seven 32-byte BG templates copied
 * to the stack and handed to func_0203FCA0 for BGs 0-6, each followed by
 * its clear/enable calls.
 *
 * volatile: 0x04000304 (POWCNT1, read-modify-write at 0x021B8FA0/0x021B8FA8)
 */
void func_021B8F98(void)
{
    BgTemplate t0;
    BgTemplate t1;
    BgTemplate t2;
    BgTemplate t3;
    BgTemplate t4;
    BgTemplate t5;
    BgTemplate t6;

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    t0 = d_021BBB40;
    func_0203FCA0(0, &t0, 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 0);

    t1 = d_021BBB60;
    func_0203FCA0(1, &t1, 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 0);

    t2 = d_021BBB80;
    func_0203FCA0(2, &t2, 0);
    func_020414AC(2);
    func_020409B4(2);
    func_02040588(2, 0);

    t3 = d_021BBB20;
    func_0203FCA0(3, &t3, 0);
    func_02040C14(3, 0, 1, 0);
    func_020414AC(3);
    func_020409B4(3);
    func_02040588(3, 0);

    t4 = d_021BBAC0;
    func_0203FCA0(4, &t4, 0);
    func_02040588(4, 0);
    func_020409B4(4);

    t5 = d_021BBAE0;
    func_0203FCA0(5, &t5, 0);
    func_02040588(5, 0);

    t6 = d_021BBB00;
    func_0203FCA0(6, &t6, 0);
    func_02040588(6, 0);
    func_02040C14(6, 0, 1, 0);
    func_020414EC(6);
}







void func_021B913C(void)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
}






void func_021B9178(char *p, int bg)
{
    int a, b, c, t;
    int r = func_02008550((const struct Sub0200852CObj *)(((struct Obj06174 *)p)->f8));
    if (r == 0) {
        a = 4;
        b = 3;
        c = 5;
    } else if (r == 1) {
        a = 1;
        b = 0;
        c = 2;
    }
    func_02049B68((void *)bg, a, 0, 0, 0x20, ((struct Obj06174 *)p)->f544);
    t = func_02049740((void *)bg, b, 0, 0, 0, ((struct Obj06174 *)p)->f544);
    ((struct Obj06174 *)p)->f7F8 = t;
    func_02049990((void *)bg, c, 0, 0, (unsigned short)t, 0, 0, ((struct Obj06174 *)p)->f544);
}









void func_021B91FC(char *p, void *bg)
{
    int a, b, c, d;
    int r = func_02008550((const struct Sub0200852CObj *)(((struct Obj04332 *)p)->f8));
    if (r == 0) {
        a = 0x10;
        b = 0xf;
        c = 0xe;
        d = 0xd;
    } else if (r == 1) {
        a = 0xc;
        b = 0xb;
        c = 0xa;
        d = 9;
    }
    ((struct Obj04332 *)p)->f590 = func_0204AC18((void *)bg, a, 0, 0xc0, 0, 4, ((struct Obj04332 *)p)->f544);
    ((struct Obj04332 *)p)->f594 = func_0204A6C8((void *)bg, b, 0, 0, ((struct Obj04332 *)p)->f544);
    ((struct Obj04332 *)p)->f598 = func_0204AF28((void *)bg, c, d, ((struct Obj04332 *)p)->f544);
}









static inline void LoadIcons(u8 *p)
{
    void *a;
    u32 m;
    u32 i;

    a = func_020490F4(func_020275E4(), *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x5E0) = func_0204AC18(a, func_020275E8(), 1, 0x80, 0, 3, *(u16 *)(p + 0x544));
    m = func_020275FC(2);
    *(u32 *)(p + 0x5E4) = func_0204AF28(a, m, func_02027600(2), *(u16 *)(p + 0x544));
    for (i = 0; i < 3; i++)
        *(u32 *)(p + i * 4 + 0x5E8) = func_0204A6C8(a, func_02027610((u8)i), 0, 1, *(u16 *)(p + 0x544));
    for (i = 0; i < 17; i++)
        *(u32 *)(p + i * 4 + 0x59C) = func_0204A6C8(a, func_020275F8((u8)i), 0, 1, *(u16 *)(p + 0x544));
    func_02049238(a);
}









void func_021B9280(u8 *p)
{
    Tbl16 t;
    Rect r2;
    Rect r1;
    Rect r0;
    void *h;
    u32 v;
    u32 i;

    *(volatile u16 *)0x04000050 = 0;
    func_0203F8F4(*(u16 *)(p + 0x544));
    func_02045088(*(u16 *)(p + 0x544));
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021BBBE0);
    func_0204A48C((const struct Cfg *)d_021BBA8C, (u32)d_021BBBE0, *(u16 *)(p + 0x544));
    t = d_021BBAB0;
    func_0203FC28((struct DispConfig *)(&t));
    func_02043534(0);
    func_020435F4(0);
    func_021B8F98();
    func_0201DD68();
    *(u32 *)(p + 0x838) = (u32)func_0201F5DC((void *)3, 13, 0, *(u16 *)(p + 0x544));
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    func_02049B68(h, 8, 4, 0, 0, *(u16 *)(p + 0x544));
    if (func_02008550((const struct Sub0200852CObj *)(*(u32 *)(p + 8))) == 0)
        func_02049BDC(h, 8, 4, 0x20, 0, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 6, 4, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x7FC) = v;
    func_02049990(h, 7, 4, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    func_021B9178((char *)p, (int)h);
    v = func_02049740(h, 0x11, 5, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x800) = v;
    func_02049990(h, 0x17, 5, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    func_021B91FC((char *)p, h);
    *(u32 *)(p + 0x808) = func_02049740(h, 0x21, 3, 0, 0, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x22, 0, 0x60, 0x20, *(u16 *)(p + 0x544));
    func_02049238(h);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x69C) = (u32)func_0204B100(0x34, 0, *(u16 *)(p + 0x544));
    func_02043598(0x10, 1);
    func_020434DC(0x10, 1);
    h = func_020490F4(0x53, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x1B, 0, 0x100, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 0x1C, 1, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x804) = v;
    func_02049990(h, 0x1D, 1, 0, (u16)v + 0x8000, 0, 0, *(u16 *)(p + 0x544));
    func_020409B4(1);
    *(u32 *)(p + 0x55C) = func_0204AC18(h, 0x13, 0, 0x140, 0, 3, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x564) = func_0204A6C8(h, 0x14, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x570) = func_0204AF28(h, 0x17, 0x1A, *(u16 *)(p + 0x544));
    func_02049238(h);
    func_021BA6F4((char *)p);
    LoadIcons(p);
    r2.x = 0x50;
    r2.y = 0xB8;
    r2.a = 1;
    r2.b = 1;
    r2.z = 0;
    for (i = 0; i < 3; i++) {
        *(u32 *)(p + i * 4 + 0x6C0) = (u32)func_0204B294((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + i * 4 + 0x5E8), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r2, 1, *(u16 *)(p + 0x544));
        func_0204B6F4((struct Obj *)(*(u32 *)(p + i * 4 + 0x6C0)), func_02027604((u8)i), 1);
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(u32 *)(p + i * 4 + 0x6C0))), 0);
    }
    r1.x = 0x52;
    r1.y = 0xA5;
    r1.a = 1;
    r1.b = 1;
    r1.z = 0;
    for (i = 0; i < 17; i++) {
        *(u32 *)(p + i * 4 + 0x6CC) = (u32)func_0204B294((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + i * 4 + 0x59C), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r1, 1, *(u16 *)(p + 0x544));
        func_0204B6F4((struct Obj *)(*(u32 *)(p + i * 4 + 0x6CC)), func_020275EC((u8)i), 1);
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(u32 *)(p + i * 4 + 0x6CC))), 0);
    }
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x580) = func_0204AC18(h, 0x27, 0, 0x80, 0, 2, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x584) = func_0204A6C8(h, 0x26, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x58C) = func_0204AF28(h, 0x25, 0x24, *(u16 *)(p + 0x544));
    func_02049238(h);
    r0.a = 10;
    r0.b = 1;
    r0.x = 0x92;
    r0.y = 0xB0;
    r0.z = 0;
    *(u32 *)(p + 0x72C) = (u32)func_0204B294((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + 0x584), *(u32 *)(p + 0x580), *(u32 *)(p + 0x58C), &r0, 0, *(u16 *)(p + 0x544));
    func_0204B92C((struct Obj *)(*(u32 *)(p + 0x72C)), 1);
    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(u32 *)(p + 0x72C))), 1);
    func_021BB5A4((char *)p);
}









void func_021B9758(char *p)
{
    unsigned v;
    v = ((struct Obj06175 *)p)->f7FC;
    func_0203FB44((int)4, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f800;
    func_0203FB44((int)5, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f808;
    func_0203FB44((int)3, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f7F8;
    func_0203FB44((int)0, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f804;
    func_0203FB44((int)1, (unsigned short)v, (unsigned short)(v >> 16));
}








void func_021B97CC(void *p, int v) { func_02040588(5, v); func_02040588(6, v); }







/*
 * blocked: func_0201C1E8 (arm9 unlabelled leaf, the integrator's; 12 bytes, tail stub)
 * has no witness outside this function. Verified C for the leaf (EXACT,
 * thumb, arm9, no region):
 *   extern int func_0201BD28(int, int);   // symbols: func_0201BD28 0x0201BD28 thumb
 *   int func_0201C1E8(int a) { return func_0201BD28(a, 2); }
 */
void func_021B97E8(char *p, int mode)
{
    int r;
    if (mode == 1) {
        *(int *)(p + 0x840) = 1;
    } else {
        *(int *)(p + 0x840) = 2;
    }
    if (*(int *)(p + 0x6A0) != 0) {
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(int *)(p + 0x6A0))), mode);
    }
    r = func_020212B0(*func_021B616C(p, func_021B61B8((u8 *)p)));
    if (r != 0) {
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(int *)(p + func_0201C1E8(r) * 4 + 0x6C0))), mode);
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(int *)(p + func_0201C1C8((void *)r) * 4 + 0x6CC))), mode);
    }
}








void func_021B9850(char *p)
{
    u32 i;
    u32 j;
    u16 *e;
    u16 kind;
    u8 n;

    j = 0;
    for (i = 0; i < 3; i++)
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x6C0)), 0);
    for (j = 0; j < 17; j++)
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + j * 4 + 0x6CC)), 0);
    e = (void *)func_021B616C((char *)((u8 *)p), func_021B61B8((u8 *)p));
    if (e == 0 || *e == 0) {
        func_021B97E8(p, 0);
        return;
    }
    func_021B97E8(p, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj00002 *)p)->f73C)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00002 *)p)->f744)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj00002 *)p)->f74C)), 0);
    kind = func_020212B0(*e);
    if (kind == 0) {
        func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x86, (void *)(((struct Obj00002 *)p)->f524));
        func_021B61F4((u8 *)p, 0, *e);
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021BB6E0((int)p, (u32 *)(p + 0x73C), *(u32 *)&((struct Obj00002 *)p)->f528, 0, (s16_021BB6E0)4, 0x3DC0);
        if (((struct Obj00002 *)p)->f80C != 4) {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x83, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, e[1], 3, 0, 1);
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            func_021BB6E0((int)p, (u32 *)(p + 0x744), *(u32 *)&((struct Obj00002 *)p)->f528, 0, (s16_021BB6E0)4, 0x3DC0);
        } else {
            func_02045334((struct Descriptor *)((struct Obj00002 *)p)->f744);
        }
        func_020456F8((struct Descriptor *)(*(u32 *)&((struct Obj00002 *)p)->f734));
    } else {
        n = func_02021350(*e);
        if (n == 0xFF) {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x45, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, func_0202130C(*e) + 1, 2, 2, 1);
        } else {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x47, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, n + 1, 2, 2, 1);
        }
        func_0201EF34((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 1, kind);
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021BB6E0((int)p, (u32 *)(p + 0x73C), *(u32 *)&((struct Obj00002 *)p)->f528, 0, (s16_021BB6E0)4, 0x3DC0);
        func_021BAB04((u8 *)p, kind);
        func_02045334((struct Descriptor *)((struct Obj00002 *)p)->f744);
    }
    func_02020FB4((void *)(((struct Obj00002 *)p)->f524), *e, ((struct Obj00002 *)p)->f544);
    func_021BB6E0((int)p, (u32 *)(p + 0x74C), ((struct Obj00002 *)p)->f524, 0, (s16_021BB6E0)4, 0x3DC0);
    func_021BB724((void **)(p + 0x73C));
    func_021BB724((void **)(p + 0x744));
    func_021BB724((void **)(p + 0x74C));
    func_021B9E14(p, *e);
}









void func_021B9AAC(char *p)
{
    unsigned i;
    unsigned j;
    func_021B97E8(p, 0);
    func_020456F8((struct Descriptor *)(((struct Obj20672 *)p)->f734));
    for (i = 0; i < 3; i++) {
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x6C0)), 0);
    }
    for (j = 0; j < 0x11; j++) {
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + j * 4 + 0x6CC)), 0);
    }
}









void func_021B9AF8(char *p)
{
    int i;
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f73C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f74C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f744));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f734));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f754));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f76C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f774));
    func_0204B3B4((struct Obj *)(((struct Obj01682 *)p)->f6A8));
    if (((struct Obj01682 *)p)->f6A0 != 0) {
        func_0204B3B4((struct Obj *)(((struct Obj01682 *)p)->f6A0));
        func_0204A8D4(((struct Obj01682 *)p)->f54C);
        func_0204ADA4(((struct Obj01682 *)p)->f548);
    }
    func_0204AFD8(((struct Obj01682 *)p)->f550);
    for (i = 0; i < 8; i++) {
        func_020437AC((struct Obj020437AC *)(*(int *)(p + i * 4 + 0x614)));
    }
    func_0204B1CC((struct Bank *)(((struct Obj01682 *)p)->f69C));
    func_0204A5AC();
}








void func_021B9BA0(char *p) { func_02045CAC((struct MsgBank *)(((struct Obj01516 *)p)->f51C), 0x87, (void *)(((struct Obj01516 *)p)->f524)); func_021BB6E0((int)p, (unsigned *)(p + 0x774), *(unsigned *)&((struct Obj01516 *)p)->f524, 0, (s16_021BB6E0)4, 0x3DC0); }









void func_021B9BDC(char *p)
{
    void *bg;

    ((struct Obj00002 *)p)->f774 = func_020450F0(3, 0x12, 9, 0xc, 3, 3, 1);
    func_021B9BA0(p);
    func_020456F8((struct Descriptor *)(((struct Obj00002 *)p)->f774));
    ((struct Obj00002 *)p)->f754 = func_020450F0(3, 0x11, 0xd, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f76C = func_020450F0(3, 0x11, 0xf, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f734 = func_020450F0(6, 0, 0x13, 0x20, 5, 0, 1);
    ((struct Obj00002 *)p)->f73C = func_020450F0(6, 7, 5, 0x12, 3, 0, 1);
    *(int *)&((struct Obj00002 *)p)->f744 = func_020450F0(6, 0x14, 8, 6, 3, 0, 1);
    ((struct Obj00002 *)p)->f74C = func_020450F0(6, 2, 0xc, 0x1d, 7, 0, 1);
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f73C));
    func_02045374((struct Cfg *)(*(int *)&((struct Obj00002 *)p)->f744));
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f74C));
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f734));
    bg = func_020490F4(0x19, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f550 = func_0204AF28(bg, 1, 0, ((struct Obj00002 *)p)->f544);
    func_02049238(bg);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x66, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, (s16_021BB6E0)4, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5d, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, (s16_021BB6E0)0x18, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5b, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, (s16_021BB6E0)4, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5c, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, (s16_021BB6E0)0x18, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5a, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0xd0, (s16_021BB6E0)4, 0x3DC0);
    if (func_020355C4() == 0) {
        func_021B9850(p);
    }
}








void func_021B9DE8(char *p) { if (((struct Obj01041 *)p)->f6A0) { func_0204B3B4(((struct Obj01041 *)p)->f6A0); func_0204A8D4(*(unsigned *)&((struct Obj01041 *)p)->f54C); func_0204ADA4(*(unsigned *)&((struct Obj01041 *)p)->f548); ((struct Obj01041 *)p)->f6A0 = 0; } }









void func_021B9E14(char *p, int id)
{
    void *bg;
    Rect_021B9850 r;
    if (*(int *)&((struct Obj01041 *)p)->f6A0 != 0) {
        func_021B9DE8(p);
    }
    bg = func_020490F4(0x19, ((struct Obj01041 *)p)->f544);
    ((struct Obj01041 *)p)->f548 = func_0204AC18(bg, func_02020E60(id, 2), 1, 0, 0, 1, ((struct Obj01041 *)p)->f544);
    ((struct Obj01041 *)p)->f54C = func_0204A6C8(bg, func_02020E60(id, 1), 0, 1, ((struct Obj01041 *)p)->f544);
    func_02049238(bg);
    r.a = 0x84;
    r.b = 0x50;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    *(int *)&((struct Obj01041 *)p)->f6A0 = (int)func_0204B294((void *)((struct Obj01041 *)p)->f69C, ((struct Obj01041 *)p)->f54C, ((struct Obj01041 *)p)->f548, ((struct Obj01041 *)p)->f550, &r, 1, ((struct Obj01041 *)p)->f544);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj01041 *)p)->f6A0, 1);
    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)&((struct Obj01041 *)p)->f6A0), 1);
}








void func_021B9ED8(char *p) { func_0204A600(); if (((struct Obj13157 *)p)->f77C) func_02027974(((struct Obj13157 *)p)->f77C); }








/*
 * lever:    the loop's array slots are spelled `p + i * 4 + 0x614` (index
 *           before offset), which keeps `p + i*4` in one register across both
 *           calls; `p + 0x614 + i * 4` and `((int *)(p + 0x614))[i]` both DIFF.
 */
void func_021B9EF4(char *p)
{
    void *bg;
    int i;

    bg = func_020490F4(0x58, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f574 = func_0204AC18(bg, 0x20, 0, 0x1a0, 0, 1, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f578 = func_0204A6C8(bg, 0x1f, 0, 0, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f57C = func_0204AF28(bg, 0x1e, 0x1d, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f554 = func_0204AC18(bg, 0x1c, 0, 0x60, 0, 1, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f560 = func_0204A6C8(bg, 0x1b, 0, 0, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f568 = func_0204AF28(bg, 0x1a, 0x19, ((struct Obj00963 *)p)->f544);
    for (i = 0; i < 8; i++) {
        *(int *)(p + i * 4 + 0x614) = (int)func_02043678(0xc, 2, 0x20, ((struct Obj00963 *)p)->f544);
        *(int *)(p + i * 4 + 0x5F4) =func_0204A6C8(bg, 0x14, 0, 0, ((struct Obj00963 *)p)->f544);
    }
    func_02008550((const struct Sub0200852CObj *)(((struct Obj00963 *)p)->f8));
    ((struct Obj00963 *)p)->f588 = func_0204AC18(bg, 0x15, 0, 0, 0, 3, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f56C = func_0204AF28(bg, 0x13, 0x12, ((struct Obj00963 *)p)->f544);
    func_02049238(bg);
}








void func_021BA028(char *p)
{
    Rect_021B9EF4 r1;
    Rect_021B9EF4 r2;
    Rect_021B9EF4 r3;
    int i;

    r1.a = 0xf8;
    r1.b = 0x1a;
    r1.d = 1;
    r1.e = 2;
    r1.c = 0;
    *(int *)&((struct Obj00002 *)p)->f6A8 = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f560, ((struct Obj00002 *)p)->f554, ((struct Obj00002 *)p)->f568, &r1, 0, ((struct Obj00002 *)p)->f544);
    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8), 1);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BA6A4(p);
    r2.a = 0x8c;
    r2.b = 0x30;
    r2.d = 1;
    r2.e = 2;
    r2.c = 1;
    *(int *)&((struct Obj00002 *)p)->f6A4 = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f560, ((struct Obj00002 *)p)->f554, ((struct Obj00002 *)p)->f568, &r2, 0, ((struct Obj00002 *)p)->f544);
    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A4), 1);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A4, 1);
    for (i = 0; i < 8; i++) {
        r3.a = 0x8c;
        r3.b = i * 0x18;
        r3.d = 0xa;
        r3.e = 3;
        r3.c = 0;
        *(int *)(p + i * 4 + 0x634) = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, *(int *)(p + i * 4 + 0x5F4), ((struct Obj00002 *)p)->f588, ((struct Obj00002 *)p)->f56C, &r3, 0, ((struct Obj00002 *)p)->f544);
        r3.a -= 0x18;
        r3.c = 1;
        *(int *)(p + i * 4 + 0x674) = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f578, ((struct Obj00002 *)p)->f574, ((struct Obj00002 *)p)->f57C, &r3, 0, ((struct Obj00002 *)p)->f544);
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x634)), 0);
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x674)), 0);
    }
}




int func_021BA1D0(u16 x)
{
    if (func_02021288(x) == 1) {
        switch (func_020212B0(x)) {
        case 0xF:
        case 0x13:
        case 0x39:
        case 0x46:
        case 0x7F:
        case 0x123:
            return 1;
        }
    }
    return 0;
}









void func_021BA218(char *p)
{
    int h;
    int i;
    int idx;
    u16 *e;
    int rec;
    u32 kind;
    u16 color;
    u16 r;
    u32 w;

    if (func_021B61C8((u8 *)p) == 0) {
        func_021BB724((void **)(p + 0x774));
    } else {
        w = ((struct Obj01514 *)p)->f774;
        func_020456F8((struct Descriptor *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    if (((struct Obj01514 *)p)->f818 == ((struct Obj01514 *)p)->f814) {
        return;
    }
    h = (int)func_02020F14(((struct Obj01514 *)p)->f544);
    for (i = 0; i < 8; i++) {
        *(u32 *)(p + i * 4 + 0x654) = 0;
        idx = ((struct Obj01514 *)p)->f814 + i;
        if (idx < 0) {
            continue;
        }
        e = (void *)func_021B616C((char *)((u8 *)p), idx);
        if (e == 0 || *e == 0) {
            continue;
        }
        rec = func_02020F20(h, *e, ((struct Obj01514 *)p)->f544);
        kind = func_02021014((struct Rec *)rec, 0xf);
        if (d_021BBA79[i] == 0) {
            if (func_021BA1D0(*e) == 1) {
                color = 0x18AD;
            } else {
                color = 0x82D;
            }
        } else {
            if (func_021BA1D0(*e) == 1) {
                color = 0x20ED;
            } else {
                color = 0x106D;
            }
        }
        func_02043B5C((struct CharBuf *)(*(u32 *)(p + i * 4 + 0x614)), 0xd);
        func_02045CAC((struct MsgBank *)(((struct Obj01514 *)p)->f51C), 0x82, (void *)(((struct Obj01514 *)p)->f524));
        r = func_020212B0(*e);
        if (r == 0) {
            func_021B61F4((u8 *)p, 0, *e);
        } else {
            func_0201EF34((struct WordSet *)(((struct Obj01514 *)p)->f520), 0, r);
        }
        func_0201F250((struct WordSet *)(((struct Obj01514 *)p)->f520), (void *)(((struct Obj01514 *)p)->f528), (void *)(((struct Obj01514 *)p)->f524));
        func_0201C7D0((void *)(*(u32 *)(p + i * 4 + 0x614)), 0, 0, (void *)(((struct Obj01514 *)p)->f528), (void *)(((struct Obj01514 *)p)->f530), color);
        if (kind == 4) {
            *(u32 *)(p + i * 4 + 0x654) = 4;
        } else if (kind == 5) {
            *(u32 *)(p + i * 4 + 0x654) = 5;
        } else if (kind == 1) {
            *(u32 *)(p + i * 4 + 0x654) = 6;
        } else if (func_02021350(*e) != 0xff) {
            *(u32 *)(p + i * 4 + 0x654) = 8;
        } else if (func_0202130C(*e) != 0xff) {
            *(u32 *)(p + i * 4 + 0x654) = 7;
        } else if (func_02021014((struct Rec *)rec, 4) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 3;
        } else if (func_021B83A0(p, *e) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 2;
        } else {
            *(u32 *)(p + i * 4 + 0x654) = 1;
        }
        func_020307B0((void *)rec);
    }
    func_02049238((void *)h);
    ((struct Obj01514 *)p)->f83C = 1;
}










void func_021BA41C(char *p)
{
    Pt pt;
    func_021BB398((int)p, 0);
    func_0204B454((struct Actor *)((struct Obj01365 *)p)->f6A4, (struct PtS *)&pt, 0xFFFF);
    pt.b = (((struct Obj01365 *)p)->f810 + 1) * 0x18;
    func_0204B404((struct Obj *)(((struct Obj01365 *)p)->f6A4), (const struct Vec2 *)(&pt), 0xFFFF);
    if (func_020355C4() == 0) {
        func_021BB398((int)p, 1);
    }
    func_0202EB04((struct CodeIn *)(((struct Obj01365 *)p)->f850));
    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)((struct Obj01365 *)p)->f6A8), func_021B61C8((u8 *)p) >= 7);
    func_0204B908(((struct Obj01365 *)p)->f6A4, 0);
    func_0204B908(((struct Obj01365 *)p)->f6A8, 0);
}










void func_021BA4A4(char *p)
{
    int i;
    u8 *src;
    u8 *dst;

    for (i = 0; i < 8; i++) {
        src = (u8 *)func_0204ABBC(*(u32 *)(p + i * 4 + 0x5F4), 0);
        dst = func_020437D4(*(void **)(p + i * 4 + 0x614));
        func_020862F0(dst, func_020437EC(*(void **)(p + i * 4 + 0x614)));
        func_0207E780(dst + 0x100, src + 0x80, 0x80);
        func_0207E780(dst + 0x280, src + 0x100, 0x80);
        func_0207E780(dst, src + 0x300, 0x100);
        func_0207E780(dst + 0x180, src + 0x400, 0x100);
        if (*(u32 *)(p + i * 4 + 0x654) != 0) {
            if (((struct Obj09880 *)p)->f80C == 4) {
                if (func_021B811C((u8 *)p) == 1 && *(u32 *)(p + i * 4 + 0x654) != 3) {
                    func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)(p + i * 4 + 0x674))), *(u32 *)(p + i * 4 + 0x654) - 1);
                    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x674)), 1);
                } else {
                    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x674)), 0);
                }
            } else if (((struct Obj09880 *)p)->f80C == 0 && *(u32 *)(p + i * 4 + 0x654) >= 4) {
                func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)(p + i * 4 + 0x674))), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x674)), 1);
            } else if (((struct Obj09880 *)p)->f80C == 2 && *(u32 *)(p + i * 4 + 0x654) >= 7) {
                func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)(p + i * 4 + 0x674))), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x674)), 1);
            } else {
                func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x674)), 0);
            }
            func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x634)), 1);
        } else {
            func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x674)), 0);
            func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x634)), 0);
        }
    }
}










void func_021BA654(char *p)
{
    unsigned w;
    unsigned v;
    Pt pt;
    if (func_02035CB8(&w, &v) == 1) {
        if (v < 0x1A) {
            v = 0x1A;
        } else if (v > 0x8E) {
            v = 0x8E;
        }
        func_0204B454((struct Actor *)((struct Obj13158 *)p)->f6A8, (struct PtS *)&pt, 0xFFFF);
        pt.b = v;
        func_0204B404((struct Obj *)(((struct Obj13158 *)p)->f6A8), (const struct Vec2 *)(&pt), 0xFFFF);
    }
}










void func_021BA6A4(char *p)
{
    Pt pt;
    int n = func_021B61C8((u8 *)p);
    if (n >= 7) {
        func_0204B454((struct Actor *)*(int *)&((struct Obj00002 *)p)->f6A8, (struct PtS *)&pt, 0xFFFF);
        pt.b = func_0202EE0C(n - 6, ((struct Obj00002 *)p)->f814 + 1, 0x1A, 0x8E, 0);
        func_0204B404((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f6A8), (const struct Vec2 *)(&pt), 0xFFFF);
    }
}









void func_021BA6F4(char *p)
{
    Rect_021BA6F4 r;
    B5 t1;
    B5 t2;
    B2 t3;
    B2 t4;
    u8 i;

    r.d = 0xa;
    r.e = 1;
    t1 = d_021BBAA8;
    t2 = d_021BBA6C;
    for (i = 0; i < 5; i++) {
        r.a = t2.v[i];
        r.b = 0xa8;
        r.c = t1.v[i];
        if (i == 2) {
            r.b += 4;
        }
        *(int *)(p + i * 4 + 0x710) = (int)func_0204B294((void *)((struct Obj01515 *)p)->f69C, ((struct Obj01515 *)p)->f564, ((struct Obj01515 *)p)->f55C, ((struct Obj01515 *)p)->f570, &r, 0, ((struct Obj01515 *)p)->f544);
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + i * 4 + 0x710)), 1);
    }
    func_0204B92C((struct Obj *)((struct Obj01515 *)p)->f710, 1);
    func_0204B92C((struct Obj *)((struct Obj01515 *)p)->f714, 1);
    if (func_021B811C((u8 *)p) == 0) {
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)((struct Obj01515 *)p)->f718), 0);
    }
    if (((struct Obj01515 *)p)->f10 == 2) {
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)((struct Obj01515 *)p)->f71C), 0);
    }
    t3 = d_021BBA68;
    t4 = d_021BBA64;
    for (i = 0; i < 2; i++) {
        r.a = 0xe8;
        r.b = t4.v[i];
        r.c = t3.v[i];
        r.e = 0;
        *(int *)(p + (u8)(i + 5) * 4 + 0x710) = (int)func_0204B294((void *)((struct Obj01515 *)p)->f69C, ((struct Obj01515 *)p)->f564, ((struct Obj01515 *)p)->f55C, ((struct Obj01515 *)p)->f570, &r, 0, ((struct Obj01515 *)p)->f544);
        func_0204B92C((struct Obj *)*(int *)(p + (u8)(i + 5) * 4 + 0x710), 1);
        func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)*(int *)(p + (u8)(i + 5) * 4 + 0x710)), 0);
    }
}









/*
 * Creates five sprites from three small tables.  The work area must be a
 * struct with the resource triple as an array (args res[1], res[0], res[2]):
 * the same fields spelled as `*(int *)(p + 0x594)` offsets colour the x/y
 * loads into different registers (23 bytes of DIFF).  The tables stay
 * non-const: a const coordinate table lets its load float above the two
 * record stores.
 * The data symbols are declared without an ovNNN token (the hint is
 * contested for 0x021BBA74 and 0x021BBBCC; sole-ref/data resolves them).
 */
void func_021BA8C0(W *p)
{
    unsigned i;
    Rect_021BA8C0 r;
    for (i = 0; i < 5; i++) {
        r.d = d_021BBA74[i];
        r.e = 1;
        r.x = d_021BBBCC[i][0] - 0x10;
        r.y = d_021BBBCC[i][1];
        r.z = d_021BBA81[i * 2 + 1];
        p->obj[i] = (int)func_0204B294((void *)p->owner, p->res[1], p->res[0], p->res[2], &r, 0, p->heap);
        func_0204B92C((struct Obj *)p->obj[i], 1);
    }
}









void func_021BA96C(int p, unsigned sel)
{
    unsigned i;
    for (i = 0; i < 5; i++) {
        if (i == sel) {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(unsigned *)(p + i * 4 + 0x6AC))), d_021BBA81[i * 2]);
        } else {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(unsigned *)(p + i * 4 + 0x6AC))), d_021BBA81[i * 2 + 1]);
        }
    }
}







void func_021BA9AC(char *p) { func_0201F7A8(((struct Obj20673 *)p)->f4FC, 1); }








void func_021BA9C0(u8 *p, int *tbl, int n)
{
    Desc s;
    int i;
    int r;
    u8 *e;

    s.a = ((struct Obj00002 *)p)->f544;
    s.b = n;
    s.c = (int)(p + 0x780);
    s.d = 1;
    s.e = 0x20;
    s.f = 0x18;
    s.g = 0xD;
    s.h = 3;
    for (i = 0; i < n; i++) {
        e = p + i * 0xC;
        r = (int)func_020457B0(0x64, ((struct Obj00002 *)p)->f544);
        ((struct Obj09881 *)e)->f780 = r;
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), tbl[i], (void *)r);
        ((struct Obj09881 *)e)->f784 = 0x39E0;
        ((struct Obj09881 *)e)->f788 = 0;
    }
    *(int *)(p + (i - 1) * 0xC + 0x788) = 1;
    *(int *)&((struct Obj00002 *)p)->f77C = (int)func_02027778((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj00002 *)p)->f7E0));
    for (i = 0; i < n; i++) {
        func_02045808((struct U16Vec *)(*(int *)(p + i * 0xC + 0x780)));
    }
    func_021BB3F4((int)p, 0);
}






void func_021BAAA4(int p, int mode)
{
    void *h = func_020490F4(0x58, ((struct Obj06176 *)p)->f544);

    if (mode != 2) {
        func_020499D4(h, 0x17, 5, 0, (u16)((struct Obj06176 *)p)->f800, 0, 0, ((struct Obj06176 *)p)->f544);
    } else {
        func_020499D4(h, 0x18, 5, 0, (u16)((struct Obj06176 *)p)->f800, 0, 0, ((struct Obj06176 *)p)->f544);
    }
    func_02049238((void *)((int)h));
}





void func_021BAB04(u8 *p, int x)
{
    int a;
    int b;
    int c;
    u8 *win;

    win = p + 0x734;

    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(int *)(p + func_0201C1E8((u16)x) * 4 + 0x6C0))), (int)1);
    func_0204B3DC((struct Obj_021B7D9C *)((struct Obj *)(*(int *)(p + func_0201C1C8((void *)(u16)x) * 4 + 0x6CC))), (int)1);
    a = (int)func_0201C158(x, (int)0);
    b = (int)func_0201BD28(x, (int)3);
    c = (int)func_0201BD28(x, (int)4);
    func_02043AF4(func_02045770((struct Descriptor *)(*(int *)win)), 0xB0, 0, 0x20, 0x28, 0);
    func_02043AF4(func_02045770((struct Descriptor *)(*(int *)win)), 0xE8, 0, 0x18, 0x18, 0);
    if (b <= 1) {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x17, (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x524)), 0xB0, (s16_021BB6E0)4, 0x3DC0);
    } else {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x5F, (void *)(*(int *)(p + 0x524)));
        func_0201EFA4((struct WordSet *)(*(int *)(p + 0x520)), (int)0, (int)b, (int)3, (int)0, (int)1);
        func_0201F250((struct WordSet *)(*(int *)(p + 0x520)), (void *)(*(int *)(p + 0x528)), (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x528)), 0xB0, (s16_021BB6E0)4, 0x3DC0);
    }
    if (c == 0 || (int)func_0201C1F4(x) == 1) {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x17, (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x524)), 0xB0, (s16_021BB6E0)0x18, 0x3DC0);
    } else {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x5F, (void *)(*(int *)(p + 0x524)));
        func_0201EFA4((struct WordSet *)(*(int *)(p + 0x520)), (int)0, (int)c, (int)3, (int)0, (int)1);
        func_0201F250((struct WordSet *)(*(int *)(p + 0x520)), (void *)(*(int *)(p + 0x528)), (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x528)), 0xB0, (s16_021BB6E0)0x18, 0x3DC0);
    }
    func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x5E, (void *)(*(int *)(p + 0x524)));
    func_0201EFA4((struct WordSet *)(*(int *)(p + 0x520)), (int)0, (int)a, (int)2, (int)0, (int)1);
    func_0201F250((struct WordSet *)(*(int *)(p + 0x520)), (void *)(*(int *)(p + 0x528)), (void *)(*(int *)(p + 0x524)));
    func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x528)), 0xE8, (s16_021BB6E0)4, 0x3DC0);
    func_021BB724((void **)win);
}






/*
 * Creates the window at p+0x4FC on first use, clears it, then either prints
 * through func_0201CCE4 (mode 1) or through func_021BB6E0, and finishes the
 * window. The window address is a named local taken after the clear calls:
 * without it the 0x4FC offset went to r4 and mode to r6, the mode-1 arm
 * consumed the offset register destructively and the join reloaded it
 * (4 bytes short).
 */
void func_021BACF0(int p, int mode)
{
    int win;

    if (((struct Obj00002 *)p)->f4FC == 0) {
        ((struct Obj00002 *)p)->f4FC = func_020450F0(3, 1, 1, 0x1E, 4, 0xC, 1);
    }
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj00002 *)p)->f4FC)), 0xF);
    func_02045334((struct Descriptor *)((struct Obj00002 *)p)->f4FC);
    win = p + 0x4FC;
    if (mode == 1) {
        ((struct Obj00002 *)p)->f510 = func_0201CCE4(((struct Obj00002 *)p)->f4FC, 0, 0, *(int *)&((struct Obj00002 *)p)->f528,
                                            ((struct Obj00002 *)p)->f530, func_02012FFC(),
                                            ((struct Obj00002 *)p)->f730, 2, ((struct Obj00002 *)p)->f544, 0xF);
    } else {
        func_021BB6E0(p, (u32 *)win, *(int *)&((struct Obj00002 *)p)->f528, 0, 0, 0x44F);
    }
    func_0201F73C((void *)(*(int *)&((struct Obj04334 *)win)->f0), 1, (u16)((struct Obj00002 *)p)->f838, 0xD);
    func_021BB724((void **)win);
}





/*
 * Tail call to func_021BACF0(p, 0).
 */
void func_021BADAC(void *p)
{
    void func_021BACF0(int p, int mode);
    func_021BACF0((int)p, 0);
}





void func_021BADB8(char *p, unsigned v) { func_02045CAC((struct MsgBank *)(((struct Obj06177 *)p)->f51C), 0x2B, (void *)(*(int *)&((struct Obj06177 *)p)->f524)); func_021B61F4((u8 *)p, 0, v); func_0201F250(((struct Obj06177 *)p)->f520, ((struct Obj06177 *)p)->f528, ((struct Obj06177 *)p)->f524); }






int func_021BADF0(int p)
{
    int r;

    if (((struct Obj00002 *)p)->f510 != 0) {
        r = func_0201CE30((void *)(((struct Obj00002 *)p)->f510));
        func_020286C4((struct Ctx *)(((struct Obj00002 *)p)->f518), (void *)(((struct Obj00002 *)p)->f510), (void *)(((struct Obj00002 *)p)->f4FC));
        switch (r) {
        case 2:
            func_0201CE48((struct Rec3 *)(((struct Obj00002 *)p)->f510));
            ((struct Obj00002 *)p)->f510 = 0;
            ((struct Obj00002 *)p)->f514 = 0;
            break;
        case 1:
            if (((struct Obj00002 *)p)->f514 == 0) {
                if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
                    func_020061E4(0x547);
                    func_0201CE38((void *)(((struct Obj00002 *)p)->f510));
                    ((struct Obj00002 *)p)->f514 = 1;
                }
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
                func_0201CE5C((struct Rec *)(((struct Obj00002 *)p)->f510), 0);
            }
            ((struct Obj00002 *)p)->f514 = 0;
            break;
        }
        return 0;
    }
    return 1;
}






void func_021BAE98(int p)
{
    ((struct Obj06178 *)p)->f504 = func_020450F0(2, 3, 0x15, 0xC, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f75C = func_020450F0(2, 1, 0x15, 8, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f764 = func_020450F0(2, 9, 0x15, 9, 3, 0xC, 1);
    func_021BAF38(p, ((struct Obj06178 *)p)->f80C);
    func_021BA96C(p, ((struct Obj06178 *)p)->f80C);
}





void func_021BAF10(char *p) { func_020452E8(((struct Obj09882 *)p)->f504); func_020452E8(((struct Obj09882 *)p)->f764); func_020452E8(((struct Obj09882 *)p)->f75C); }






void func_021BAF38(int p, int val)
{
    int r;

    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj01516 *)p)->f504)), 0);
    func_02045CAC((struct MsgBank *)(((struct Obj01516 *)p)->f51C), 0x8B, (void *)(((struct Obj01516 *)p)->f524));
    func_0201F14C((struct WordSet *)(((struct Obj01516 *)p)->f520), 0, val);
    func_0201F250((struct WordSet *)(((struct Obj01516 *)p)->f520), (void *)(((struct Obj01516 *)p)->f528), (void *)(((struct Obj01516 *)p)->f524));
    r = 0x60 - func_0201D304((struct StrObj *)(((struct Obj01516 *)p)->f528), *(int *)&((struct Obj01516 *)p)->f530, 0);
    func_021BB6E0(p, (u32 *)(p + 0x504), ((struct Obj01516 *)p)->f528, (unsigned short)(r >> 1), 4, 0x3C40);
    func_021BB724((void **)(p + 0x504));
}





void func_021BAFC4(u8 *p)
{
 unsigned long win = 0x764;
 func_02043B5C(func_02045770(P(win)),0);
 func_02043B5C(func_02045770(*(void **)(p+(win-8))),0);
 func_02045CAC(P(0x51C),0x51,P(0x524));
 func_021BB6E0((int)p, (u32 *)((u32)p+(win-8)), W(0x524), 0, 4, 0x3C40);
 func_021BB724((void **)((unsigned long)p+(win-8)));
 func_02045CAC(P(0x51C),0x52,P(0x524));
 func_0201EFA4(P(0x520),0,func_0200C274(func_02012F08(P(0))),7,1,1);
 func_0201F250(P(0x520),P(0x528),P(0x524));
 func_021BB6E0((int)p, (u32 *)((u32)p+win), W(0x528), 0, 4, 0x3C40);
 func_021BB724((void **)((u32)p+win));
}





void func_021BB08C(char *p) { func_0204B3DC((struct Obj_021B7D9C *)(((struct Obj09883 *)p)->f710), 0); func_0204B3DC((struct Obj_021B7D9C *)(((struct Obj09883 *)p)->f714), 0); func_020456F8(((struct Obj09883 *)p)->f504); func_021BAFC4((u8 *)p); }





void func_021BB0BC(char *p) { func_0204B3DC((struct Obj_021B7D9C *)(((struct Obj06179 *)p)->f710), 1); func_0204B3DC((struct Obj_021B7D9C *)(((struct Obj06179 *)p)->f714), 1); func_020456F8(((struct Obj06179 *)p)->f764); func_020456F8(((struct Obj06179 *)p)->f75C); func_021BAF38((int)p, ((struct Obj06179 *)p)->f80C); }






void func_021BB0F8(int p)
{
    Desc s;
    int h;
    int r;

    h = ((struct Obj00002 *)p)->f544;
    s.a = h;
    s.b = 2;
    s.c = p + 0x780;
    s.d = 1;
    s.e = 0x20;
    s.f = 0xC;
    s.g = 8;
    s.h = 3;
    r = (int)func_020457B0(0x64, h);
    ((struct Obj00002 *)p)->f780 = r;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x84, (void *)r);
    ((struct Obj00002 *)p)->f784 = 0x39E0;
    ((struct Obj00002 *)p)->f788 = 0;
    r = (int)func_020457B0(0x64, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f78C = r;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x85, (void *)r);
    ((struct Obj00002 *)p)->f790 = 0x39E0;
    ((struct Obj00002 *)p)->f794 = 0;
    *(int *)&((struct Obj00002 *)p)->f77C = (int)func_02027778((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj00002 *)p)->f7E0));
    func_02045808((struct U16Vec *)(((struct Obj00002 *)p)->f780));
    func_02045808((struct U16Vec *)(((struct Obj00002 *)p)->f78C));
    func_021BB580((char *)p, 0);
    func_021BB3F4(p, 0);
}





void func_021BB1AC(char *p) { func_02027858(((struct Obj13159 *)p)->f77C); ((struct Obj13159 *)p)->f77C = 0; }






void func_021BB1C4(Work *p)
{
    void *arc;
    int tex;
    Img *img;
    int i;
    u16 *d;
    int n;

    arc = func_020490F4(0x58, p->f544);
    tex = (int)func_0204A380(arc, 0x23, 0, p->f544);
    i = 0;
    if (func_02062B30((void *)tex, (void **)(&img))) {
        d = img->d;
        n = ((unsigned)img->w >> 3) * ((unsigned)img->h >> 3);
        for (; i < n; i++) {
            d[i] += (u16)((u16)p->f808 | 0x3000);
        }
        func_02041090(3, (unsigned int)img->d, 0x10, 0xC, (unsigned)img->w >> 3, (unsigned)img->h >> 3);
        func_02041B6C(3);
    }
    func_020307B0((void *)tex);
    func_02049238(arc);
}






void func_021BB260(u8 *p, int val)
{
    int v;
    u32 *win2;
    u32 *win;

    win = (u32 *)(p + 0x754);

    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win)), 5);
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x83, (void *)(*(int *)&((struct Obj00002 *)p)->f524));
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), 0, val, 3, 0, 1);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), (void *)(*(int *)&((struct Obj00002 *)p)->f528), (void *)(*(int *)&((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, win, *(u32 *)&((struct Obj00002 *)p)->f528, 0, 0, 0x3DC5);
    func_021BB724((void **)win);
    if (((struct Obj00002 *)p)->f7EC == 2) {
        win2 = (u32 *)(p + 0x76C);
        v = func_021B619C(((struct Obj00002 *)p)->f84C, ((struct Obj00002 *)p)->f7F4, ((struct Obj00002 *)p)->f544);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win2)), 5);
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x54, (void *)(*(int *)&((struct Obj00002 *)p)->f524));
        func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), 0, v, 7, 0, 1);
        func_0201F250((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), (void *)(*(int *)&((struct Obj00002 *)p)->f528), (void *)(*(int *)&((struct Obj00002 *)p)->f524));
        func_021BB6E0((int)p, win2, *(u32 *)&((struct Obj00002 *)p)->f528, 0, 0, 0x3DC5);
        func_021BB724((void **)win2);
    }
}





int func_021BB368(int x)
{
    switch (x) {
    case 0:
        return 10;
    case 3:
        return 13;
    case 1:
        return 11;
    case 2:
        return 12;
    case 4:
        return 14;
    }
    return x;
}






void func_021BB398(int p, u32 val)
{
    short b[2];
    short a[2];
    unsigned i;

    func_0204B454((struct Actor *)((struct Obj20676 *)p)->f6A4, (struct PtS *)b, 0);
    for (i = 0; i < 8; i++) {
        func_0204B454((struct Actor *)*(int *)(p + i * 4 + 0x634), (struct PtS *)a, 0);
        if (a[1] == b[1]) {
            break;
        }
    }
    func_0204B6F4((struct Obj *)(*(int *)(p + i * 4 + 0x634)), (u8)val, 0);
}






void func_021BB3F4(int p, int mode)
{
    int r;

    if (((struct Obj00002 *)p)->f858 == mode) {
        return;
    }
    ((struct Obj00002 *)p)->f858 = mode;
    r = func_02012BF8(*(int *)&((struct Obj00002 *)p)->f0, func_021BB368(((struct Obj00002 *)p)->f80C));
    if (mode == 1) {
        func_0202173C(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 0, 0, 0, func_020056BC());
        func_0202173C(((struct Obj00002 *)p)->f854, 1, 1, 0, 0, 0, 0, func_020056BC());
        func_0207D658(0x04000050, 6, 0);
        func_021BB5A4((char *)p);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f710)), 4);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f714)), 5);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f71C)), 0);
        if (r == 1) {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 7);
        } else {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 6);
        }
        func_021BB580((char *)p, 1);
    } else {
        func_020216D4((struct PalAnmSlot *)(((struct Obj00002 *)p)->f854), 2, 0, 0x200);
        func_0202173C(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 8, 8, 0, func_020056BC());
        func_0202173C(((struct Obj00002 *)p)->f854, 1, 1, 0, 8, 8, 0, func_020056BC());
        if (((struct Obj00002 *)p)->f10 == 4 && func_0204B3F4((struct Obj *)(((struct Obj00002 *)p)->f710)) == 0) {
            func_0207D658(0x04000050, 2, -8);
        } else {
            func_0207D658(0x04000050, 6, -8);
        }
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C)), 4);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f710)), 0x12);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f714)), 0x13);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f71C)), 0xE);
        if (r == 1) {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 0x16);
        } else {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 0x15);
        }
    }
}





void func_021BB580(char *p, int v) { if (v == 1) func_0204B878((struct Obj_021B7250 *)(((struct Obj13160 *)p)->f720), 1); else func_0204B878((struct Obj_021B7250 *)(((struct Obj13160 *)p)->f720), 15); }





void func_021BB5A4(char *p) { if (((struct Obj00002 *)p)->f80C == 2 || ((struct Obj00002 *)p)->f80C == 3 || func_021B61C8((u8 *)p) <= 1) func_0204B878((struct Obj_021B7250 *)(((struct Obj00002 *)p)->f72C), 4); else func_0204B878((struct Obj_021B7250 *)(((struct Obj00002 *)p)->f72C), 0); }






void func_021BB5DC(int p, int mode)
{
    int r = func_02012BF8(*(int *)&((struct Obj00002 *)p)->f0, func_021BB368(((struct Obj00002 *)p)->f80C));

    if (mode == 1) {
        func_021BB5A4((char *)p);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f710)), 4);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f714)), 5);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f71C)), 0);
        if (r == 1) {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 7);
        } else {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 6);
        }
    } else {
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C)), 4);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f710)), 0x12);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f714)), 0x13);
        func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f71C)), 0xE);
        if (r == 1) {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 0x16);
        } else {
            func_0204B878((struct Obj_021B7250 *)((struct Obj *)(((struct Obj00002 *)p)->f718)), 0x15);
        }
    }
}





/*
 * lever: expand q at the first call but retain q for the second call.
 */
int func_021BB690(const char *p)
{
    unsigned i;
    short v[2];
    const char *q;
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        q = p + off;
        func_0204B454((struct Actor *)*((int *)((p + off) + 0x6AC)), (struct PtS *)v, 0xFFFF);
        if (v[0] == *((short *)(((char *)d_021BBBCC) + off))) {
            return 0;
        }
        v[0] = v[0] + 4;
        func_0204B404((struct Obj *)(*((int *)(q + 0x6AC))), (const struct Vec2 *)v, 0xFFFF);
    }
    return 1;
}






void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16_021BB6E0 y, u16 color)
{
    u32 print = ((struct Obj01516 *)p)->f50C;

    func_0201C724((void *)print, (u32)func_02045770((struct Descriptor *)*obj), (s16_021BB6E0)x, y, str, ((struct Obj01516 *)p)->f530, color);
    *((unsigned char *)obj + 4) = 1;
}





void func_021BB724(void **p)
{
    func_02045374(*p);
    func_02041B6C(func_02045730(*p));
}
