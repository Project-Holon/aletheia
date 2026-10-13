/*
 * file:     queue.c
 * unit:     yes
 * function: func_021C05B0, func_021C06AC, func_021C06C8, func_021C06E0, func_021C06F0, func_021C0794, func_021C07B0, func_021C07BC, func_021C0800, func_021C0820, func_021C083C, func_021C085C, func_021C0878, func_021C08A8, func_021C08C4, func_021C08D4, func_021C08F0, func_021C0900, func_021C0918, func_021C093C, func_021C0968, func_021C097C, func_021C099C, func_021C09AC, func_021C09B0, func_021C09B4, func_021C09B8, func_021C09BC, func_021C09C4, func_021C09C8, func_021C09CC, func_021C09D0, func_021C09D8, func_021C09E0, func_021C09EC, func_021C09F8, func_021C09FC, func_021C0A04, func_021C0A38, func_021C0A54, func_021C0A5C, func_021C0AA4, func_021C0AD8, func_021C0AF0, func_021C0AF8, func_021C0B0C, func_021C0B74, func_021C0B8C, func_021C0B94, func_021C0BA8, func_021C0BB4, func_021C0BBC, func_021C0C2C, func_021C0C38, func_021C0C40, func_021C0C50, func_021C0C5C, func_021C0CC8, func_021C0CF0, func_021C0CF8, func_021C0D08, func_021C0D14, func_021C0D2C, func_021C0D38, func_021C0D5C, func_021C0D6C, func_021C0D7C, func_021C0D88, func_021C0DB4, func_021C0DBC, func_021C0DC4, func_021C0DDC, func_021C0DE4, func_021C0DF0, func_021C0DF4, func_021C0DF8, func_021C0DFC, func_021C0E00, func_021C0E04, func_021C0E08, func_021C0E3C, func_021C0E4C, func_021C0E54, func_021C0E5C, func_021C0E64, func_021C0E6C, func_021C0E78, func_021C0E98, func_021C0EA4, func_021C0EC0, func_021C0EDC, func_021C0EE4
 * address:  0x021C05B0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C3C54  0x021C3C54  data  a4
 *   d_021C37D0  0x021C37D0  data  a4
 *   BMP_CreateFromArchive  0x0204384C  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_Delete  0x020437AC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   func_020307B0  0x020307B0  arm
 *   _u32_div_f  0x0209C0A4  arm
 *   BMP_OAM_CreateSys  0x02025538  thumb  ov217
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   d_021C377C 0x021C377C data a4
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_Delete  0x0202570C  thumb
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_Delete  0x02021540  thumb
 *   func_021C29C8  0x021C29C8  thumb  ov217
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *   d_021C3A28  0x021C3A28  data  a4
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *   func_020056A0  0x020056A0  thumb
 *   func_021BF6BC  0x021BF6BC  thumb  ov217
 *   func_02030EAC  0x02030EAC  arm
 *   func_02012138  0x02012138  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   GAME_COMM_SetNotifyFlag  0x02026498  thumb
 *   func_021BF734  0x021BF734  thumb  ov217
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4 0x020120F4 thumb
 *   d_021C3F64  0x021C3F64  data
 *   d_021C3F9C  0x021C3F9C  data
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   d_021C3F80 0x021C3F80 data a4
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   func_021C29F8  0x021C29F8  thumb  ov217
 *   d_021C3F5C     0x021C3F5C  data   a4
 *   d_021C3F60     0x021C3F60  data   a1
 *   func_021C2A00  0x021C2A00  thumb  ov217
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *   d_021C3F48  0x021C3F48  data  a1
 *   d_021C4050  0x021C4050  data  a4
 *   func_02030734  0x02030734  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   CLACT_InitSystem  0x0204A48C  arm  arm9
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 */
#include "../../matched/include/Obj10961.h"
#include "../../matched/include/Obj25966.h"
#include "../../matched/include/Obj25967.h"
#include "../../matched/include/Obj25969.h"
#include "../../matched/include/Obj03953.h"
#include "../../matched/include/Obj10962.h"
#include "../../matched/include/Obj25970.h"
#include "../../matched/include/Obj25973.h"
#include "../../matched/include/Obj25974.h"
#include "../../matched/include/Obj25975.h"
#include "../../matched/include/Obj25976.h"
#include "../../matched/include/Obj25978.h"
#include "../../matched/include/Obj10963.h"
#include "../../matched/include/Obj25979.h"
#include "../../matched/include/Obj25980.h"
#include "../../matched/include/Obj25981.h"
#include "../../matched/include/Obj25982.h"
#include "../../matched/include/Obj25983.h"
#include "../../matched/include/Obj00791.h"
#include "../../matched/include/Obj25984.h"
#include "../../matched/include/Obj10964.h"
#include "../../matched/include/Obj25985.h"
#include "../../matched/include/Obj25986.h"
#include "../../matched/include/Obj25987.h"
#include "../../matched/include/Obj25988.h"
#include "../../matched/include/Obj25989.h"
#include "../../matched/include/Obj25990.h"
#include "../../matched/include/Obj25992.h"
#include "../../matched/include/Obj25993.h"
#include "../../matched/include/Obj25994.h"
#include "../../matched/include/Obj25995.h"
#include "../../matched/include/Obj10965.h"
#include "../../matched/include/Obj25997.h"
#include "../../matched/include/Obj25998.h"
#include "../../matched/include/Obj25999.h"
#include "../../matched/include/Obj26000.h"
#include "../../matched/include/Obj26001.h"
#include "../../matched/include/Obj26002.h"
#include "../../matched/include/Obj06714.h"
#include "../../matched/include/Obj26003.h"
#include "../../matched/include/Obj06715.h"

#define E ((const struct Entry_021C05B0 *)gb)
struct Bmp;
struct MsgBank;
struct Obj020437AC;
struct Sys;
struct Grid;
struct Obj;
struct PalAnmSlot;
struct Node;
struct Ctx;
struct Comm;
struct IcaAnime;
struct Cfg;
struct Bank;
struct Ring;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Entry_021C05B0 {
    int x, y, pad, bank, index, px, py;
    u8 r, g, b, pad2;
    u32 arc, member, enabled;
};

struct Row {
    u32 w[20];
};

struct Tab {
    struct Row r[3];
};

typedef signed int     s32;

struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry_021C06F0 { s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

typedef signed char    s8;

struct Ent {
    u32 a;
    u32 b;
    u8 c;
    u8 pad[11];
};

typedef struct {
    u32 w[2];
    u32 a;
    u32 b;
} Rec;

struct Arg { s16 x,y,z; u8 a,b; };

struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

struct Ring {
    u32 *buf;
    u32 count;
    u32 pos;
};

extern struct Bmp *BMP_CreateFromArchive(u32, u32, u32, u32);
extern void BMP_Blit(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *, u32);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern u32 func_020307B0(void *p);
extern void BMP_Delete(struct Obj020437AC *);
extern int BMP_OAM_CreateSys(u16 heap, int a);
extern void BMP_OAM_DeleteSys(void *p);
extern u32 func_021BF9F0(void *,u32);
extern struct Grid *BMP_OAM_Create(struct Sys *,const struct Param *);
extern void BMP_OAM_SetEnabled(u8 *,u32);
extern void BMP_OAM_UploadChars(struct Obj *);
extern void BMP_OAM_Delete(struct Grid *g);
extern void *PALANM_Create(u32);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);
extern u32 PALANM_Delete(void *a0);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 func_021C29C8(u32 a0);
extern u32 func_021C29D8(void *a0);
extern void func_021C29E8(void *p, u32 b, u32 c, u32 d);
extern int func_021C2A08(char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern int func_020056A0(void (*)(void), void *, int);
extern u32 func_021BF6BC(u32 a0, u32 a1);
extern void func_02030EAC(struct Node *n);
extern u32 func_02012138(const struct Ctx *);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 func_02026454(void *obj);
extern void GAME_COMM_SetNotifyFlag(void *obj, u32 flag);
extern u32 func_021BF734(u8 *);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern void func_02082BCC(void *dst, int val, u32 n);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern u32 CLACT_ExitSystem(u32 a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern u32 CLACT_ReleaseCellAnim();
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern void func_021C2A00(u32);
extern void func_021C29F0(u32);
extern int _s32_div_f(int, int);
void func_021C05B0(u8 *p);
void func_021C06AC(int *p);
void func_021C06C8(u8 *p);
void func_021C06E0(u8 *a0);
void func_021C06F0(u8 *p);
void func_021C0794(int *p);
void func_021C07B0(void *p);
void func_021C07BC(u8 *p);
u32 func_021C0800(u32 a0);
void func_021C0820(void *p);
void func_021C083C(u8 *p);
void func_021C085C(int *p);
void func_021C0878(u8 *p);
void func_021C08A8(int *p);
void func_021C08C4(u32 a0);
void func_021C08D4(char *p);
void func_021C08F0(u8 *a0);
u32 func_021C0900(s32 v);
void func_021C0918(u8 *a0);
int func_021C093C(u8 *a0);
void func_021C0968(unsigned char *a0);
int func_021C097C(int a0, int a1);
u32 func_021C099C(void *a0);
u32 func_021C09AC(void *p);
u32 func_021C09B0(u32 *p);
u32 func_021C09B4(void *p);
void *func_021C09B8(void *p);
void func_021C09BC(void *p, u32 v);
void func_021C09C4(u8 *p, u32 v);
u32 func_021C09C8(void *p);
u32 func_021C09CC(void *p);
void func_021C09D0(u32 a0);
void func_021C09D8(u8 *p, u32 i);
void func_021C09E0(u32 a0);
void func_021C09EC(u32 a0);
u32 func_021C09F8(void *p);
void func_021C09FC(void *p);
void func_021C0A04(u8 *p);
u32 func_021C0A38(u32 a0);
u32 func_021C0A54(void *a0);
void func_021C0A5C(u8 *p, const struct Ctx *ctx, u32 heap);
u32 func_021C0AA4(u32 a0);
void func_021C0AD8(u32 a0);
u32 func_021C0AF0(u32 a);
void func_021C0AF8(void *p);
void func_021C0B0C(u8 *p);
u32 func_021C0B74(u32 a0);
void func_021C0B8C(void *p);
void func_021C0B94(u32 a0);
void func_021C0BA8(u8 *a0);
void func_021C0BB4(void *p);
void func_021C0BBC(u8 *p);
void func_021C0C2C(u8 *a0);
void func_021C0C38(void *p);
void func_021C0C40(u32 a0);
void func_021C0C50(u8 *a0);
void func_021C0C5C(u8 *p);
void func_021C0CC8(int *p);
void func_021C0CF0(void *p);
void func_021C0CF8(u32 a0);
void func_021C0D08(u8 *a0);
void func_021C0D14(u8 *a0);
void func_021C0D2C(u8 *a0);
void func_021C0D38(u8 *p, u32 i);
void func_021C0D5C(u8 *p, u32 i);
void func_021C0D6C(u8 *p, u32 i);
void func_021C0D7C(u32 *p);
void func_021C0D88(u8 *p);
u32 func_021C0DB4(void *p, u32 i);
u32 func_021C0DBC(void *p, u32 i);
u32 func_021C0DC4(u32 a0);
void func_021C0DDC(void *a0);
void func_021C0DE4(void *p);
u32 func_021C0DF0(void *p);
u32 func_021C0DF4(void *p);
u32 func_021C0DF8(void *p);
void func_021C0DFC(void *p, u8 v);
void func_021C0E00(void *p, u32 v);
void func_021C0E04(void *p, u32 v);
int func_021C0E08(int a0, int a1);
void func_021C0E3C(void *p);
void func_021C0E4C(u32 a0, u32 a1);
u32 func_021C0E54(struct Ring *r);
void func_021C0E5C(Rec *p);
int func_021C0E64(Rec *p);
void func_021C0E6C(void *p);
void func_021C0E78(u32 a0, u32 a1, u32 a2);
void func_021C0E98(u8 *a0);
void func_021C0EA4(char *p, int v);
u32 func_021C0EC0(struct Ring *r);
void func_021C0EDC(Rec *p);
int func_021C0EE4(Rec *p);
extern const struct Tab d_021C3C54;
extern const struct Entry_021C05B0 d_021C37D0;
extern const struct Entry_021C06F0 d_021C377C[];
extern const struct Ent d_021C3A28[];
extern u8 d_021C3F64[];
extern u8 d_021C3F9C[];
extern const struct Entry d_021C3F80;
extern u8 d_021C3F5C[];
extern u8 d_021C3F60[];
extern const u8 d_021C3F48[];
extern const int d_021C4050[];






void func_021C05B0(u8 *p)
{
    struct Tab tab = d_021C3C54;
    int i;
    int j;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u32 gb = (u32)&d_021C37D0;
    bmp = BMP_CreateFromArchive(E->arc, E->member, 0, *(u16 *)(p + 4));
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 20; j++) {
            BMP_Blit(bmp, *(struct Bmp **)(p + 0x3B4), (tab.r[i].w[j] % 3) * 8, (tab.r[i].w[j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete((struct Obj020437AC *)bmp);
    color = ((E->r & 31) << 10) | ((E->g & 31) << 5) | (E->b & 31);
    text = func_02045EC0(*(struct MsgBank **)(p + 12 + E->bank * 4), E->index);
    PRINTSYS_PrintColor(*(void **)(p + 0x3B4), E->px, E->py, text, *(void **)(p + 8), color);
    func_020307B0(text);
}







void func_021C06AC(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_Delete((struct Obj020437AC *)p[i + 0xEC]);
}







void func_021C06C8(u8 *p)
{
    ((struct Obj10961 *)p)->f3A4 = BMP_OAM_CreateSys(((struct Obj10961 *)p)->f4, ((struct Obj10961 *)p)->f38C);
}







void func_021C06E0(u8 *a0)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct Obj25966 *)a0)->f3A4)));
}






/*
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`sysOff=0x3B0;` before `sysOff=0x3A4;`; `outOff=0x3B0;` before
 * `outOff=0x3A8;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021C06F0(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct Entry_021C06F0 *q;
    u8 *dest;
    sysOff=0x3A4;
    outOff=0x3A8;
    callOff=0x3A8;
    uploadOff=0x3A8;
    for(i=0;i<2;i++) {
        dest=p+i*4;
        param.bmp=((struct Obj25967 *)dest)->f3B0;
        q=&d_021C377C[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BF9F0(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=BMP_OAM_Create(*(struct Sys **)(p+sysOff),&param);
        BMP_OAM_SetEnabled(*(u8 **)(dest+callOff),0);
        BMP_OAM_UploadChars(*(struct Obj **)(dest+uploadOff));
    }
}







/*
 * Addresses are Black-image addresses.
 */
void func_021C0794(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_OAM_Delete((struct Grid *)p[i + 0xEA]);
}







/*
 * Clear the u32 at +0x3b8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C07B0(void *p)
{
    ((struct Obj25969 *)p)->f3B8 = 0;
}






void func_021C07BC(u8 *p)
{
    ((struct Obj03953 *)p)->f3B8 = PALANM_Create(((struct Obj03953 *)p)->f4);
    PALANM_AllocSlotBuffers(((struct Obj03953 *)p)->f3B8, 0, 512, ((struct Obj03953 *)p)->f4);
    PALANM_AllocSlotBuffers(((struct Obj03953 *)p)->f3B8, 2, 512, ((struct Obj03953 *)p)->f4);
    PALANM_CopyHwPaletteToSlot(((struct Obj03953 *)p)->f3B8, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(((struct Obj03953 *)p)->f3B8, 2, 0, 512);
}






/*
 * Reconstructed from the listing (.inst decoded).
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001A THM_CALL PALANM_Delete       -> unresolved: 02021540 (arm, from name) has no witness outside 021C0800..021C0820
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0800(u32 a0)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct Obj10962 *)(((u8*)a0)))->f3B8), 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct Obj10962 *)(((u8*)a0)))->f3B8), 2);
    return PALANM_Delete((void *)(((struct Obj10962 *)(((u8*)a0)))->f3B8));
}







void func_021C0820(void *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(u32 *)((char *)p + i * 4 + 0x324) = 0;
}







void func_021C083C(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(int *)(p + i * 4 + 0x324) = func_021C29C8(((struct Obj25970 *)p)->f4);
}







void func_021C085C(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29D8((void *)p[i + 0xC9]);
}







void func_021C0878(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29E8((void *)(*(int *)(p + i * 4 + 0x324)), d_021C3A28[i].a, d_021C3A28[i].b, d_021C3A28[i].c);
}







void func_021C08A8(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C2A08((char *)p[i + 0xC9]);
}






/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021C08C4(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj25973 *)(((u8*)a0 + 0)))->f4);
}







void func_021C08D4(char *p)
{
    ((struct Obj25974 *)p)->f3C0 = func_020056A0((void (*)(void))func_021BF6BC, p, 0);
}







/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 960)), 960 to func_02030EAC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C08F0(u8 *a0)
{
    func_02030EAC((struct Node *)((u32)(((struct Obj25975 *)a0)->f3C0)));
}







u32 func_021C0900(s32 v)
{
    if (v < 0)
        return 0;
    if (v > 0xff)
        return 0xff;
    return (u8)v;
}






/*
 * Opens the +0x10 record (func_02012138 on the result of func_021BF734),
 * tags it with 1, and releases it when func_02026454 reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */
void func_021C0918(u8 *a0)
{
    u32 v1 = func_02012138((const struct Ctx *)func_021BF734(a0));
    GAME_COMM_SetNotifyFlag((void *)v1, 1);
    if (func_02026454((void *)v1) == 2) {
    GAME_COMM_RequestExitNoCallback((struct Comm *)v1);
    }
}







int func_021C093C(u8 *a0)
{
    u32 r;
    r = func_021BF734(a0);
    switch (func_02026454((void *)func_02012138((const struct Ctx *)r))) {
    case 0:
        GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)r);
        return 1;
    default:
        return 1;
    case 2:
        return 0;
    }
}







void func_021C0968(unsigned char *a0)
{
    GAME_COMM_SetNotifyFlag((void *)func_02012138((const struct Ctx *)func_021BF734(a0)), 0);
}







int func_021C097C(int a0, int a1)
{
    int r;
    r = func_021C0A38(a0);
    func_021C0A04((u8 *)r);
    func_021C0A5C((u8 *)r, (const struct Ctx *)a1, a0);
    return r;
}






/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C099C(void *a0)
{
    func_021C0AA4((u32)a0);
    return func_021C0A54(a0);
}







/*
 * Field getter, u16 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09AC(void *p)
{
    return ((struct Obj25976 *)p)->f0;
}






u32 func_021C09B0(u32 *p)
{
    return p[1];
}







/*
 * Field getter, u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09B4(void *p)
{
    return ((struct Obj25978 *)p)->f8;
}







/*
 * Base pointer getter, +0xc.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C09B8(void *p)
{
    return (char *)p + 0xc;
}







/*
 * Shift the two u32 fields at +0x30/+0x34 and store the new value at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09BC(void *p, u32 v)
{
    ((struct Obj10963 *)p)->f30 = ((struct Obj10963 *)p)->f34;
    ((struct Obj10963 *)p)->f34 = v;
}






/*
 * Field setter: store the word at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09C4(u8 *p, u32 v)
{
    ((struct Obj25979 *)p)->f38 = v;
}







/*
 * Field getter, u32 at +0x30.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09C8(void *p)
{
    return ((struct Obj25980 *)p)->f30;
}







/*
 * Field getter, u32 at +0x38.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09CC(void *p)
{
    return ((struct Obj25981 *)p)->f38;
}







/*
 * Tail-call veneer: forwards its first argument to func_021C0D7C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09D0(u32 a0)
{
    func_021C0D7C((u32 *)a0);
}







/*
 * Unlabelled 4-byte tail-call veneer in a .word run; pool 0x021C09DC names
 * func_021C0D38.  Top of the func_021BA31C blocker chain.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09D8(u8 *p, u32 i)
{
    func_021C0D38(p, i);
}







void func_021C09E0(u32 a0)
{
    func_021C0D5C((u8 *)a0, 0);
}






/*
 * Tail-call veneer: forwards arg(s) a0, 0 to func_021C0D6C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09EC(u32 a0)
{
    func_021C0D6C((u8 *)a0, 0);
}






/*
 * Field getter, u32 at +0x3c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09F8(void *p)
{
    return ((struct Obj25982 *)p)->f3C;
}






/*
 * Set the u32 at +0x3c to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09FC(void *p)
{
    ((struct Obj25983 *)p)->f3C = 1;
}






void func_021C0A04(u8 *p)
{
    func_02082BCC(p, 0, 0x40);
    ((struct Obj00791 *)p)->f30 = 0;
    ((struct Obj00791 *)p)->f34 = 0;
    func_021C0AF8(p);
    func_021C0B8C(p);
    func_021C0BB4(p);
    func_021C0C38(p);
    func_021C0CF0(p);
}





u32 func_021C0A38(u32 a0)
{
    return (u32)func_02030734(a0, 64, 0, (const char *)0x21C4020, 481);
}






u32 func_021C0A54(void *a0)
{
    return func_020307B0(a0);
}




void func_021C0A5C(u8 *p, const struct Ctx *ctx, u32 heap)
{
    ((struct Obj00791 *)p)->f0 = heap;
    *(const struct Ctx * *)&((struct Obj00791 *)p)->f4 = ctx;
    ((struct Obj00791 *)p)->f8 = func_020120F4(ctx);
    func_021C0AD8((u32)p);
    func_021C0B0C(p);
    func_021C0B94((u32)p);
    func_021C0BBC(p);
    func_021C0C40((u32)p);
    func_021C0C5C(p);
    func_021C0D88(p);
    func_021C0CF8((u32)p);
    func_021C0D14(p);
}




u32 func_021C0AA4(u32 a0)
{
    func_021C0D2C((u8 *)a0);
    func_021C0D08((u8 *)a0);
    func_021C0CC8((int *)a0);
    func_021C0C50((u8 *)a0);
    func_021C0C2C((u8 *)a0);
    func_021C0BA8((u8 *)a0);
    func_021C0B74(a0);
    return func_021C0AF0(a0);
}




/*
 * Reconstructed from the listing.
 *
 * closed: both data sites carried the contested ov217 token; dropping it lets
 * the function's own region (ov217) pick the objects and 0x021C3F9C resolves
 * as sole-ref/data.  All three relocations resolve, 24 bytes EXACT.
 * See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0AD8(u32 a0)
{
    CLACT_InitSystem((const struct Cfg *)d_021C3F64, (u32)d_021C3F9C, ((struct Obj25984 *)((u8*)a0))->f0);
}







/*
 * Tail-call veneer: branch to CLACT_ExitSystem.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0AF0(u32 a)
{
    return CLACT_ExitSystem(a);
}







/*
 * Clear three u32 slots at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0AF8(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x14) = 0;
}






void func_021C0B0C(u8 *p)
{
    u16 heap = ((struct Obj00791 *)p)->f0;
    void *h = func_020490F4(83, (u16)((heap & 0x7FFF) | 0x8000));
    int a = CLACT_RegisterCharacter((void *)((u32)h), 20, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)((u32)h), 19, 0, 0, 0, 4, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 21, 24, heap);
    ((struct Obj00791 *)p)->f14 = a;
    ((struct Obj00791 *)p)->f18 = b;
    ((struct Obj00791 *)p)->f1C = c;
    ARC_TOOL_DeleteHandle(h);
}






u32 func_021C0B74(u32 a0)
{
    CLACT_ReleaseCharacter(((struct Obj10964 *)(((u8*)a0)))->f14);
    CLACT_ReleasePalette(((struct Obj10964 *)(((u8*)a0)))->f18);
    return CLACT_ReleaseCellAnim(((struct Obj10964 *)(((u8*)a0)))->f1C);
}







/*
 * Clear the u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0B8C(void *p)
{
    ((struct Obj25985 *)p)->f20 = 0;
}






void func_021C0B94(u32 a0)
{
    ((struct Obj00791 *)(((u8*)a0 + 0)))->f20 = (u32)CLACT_CreateUnit(1, 2, ((struct Obj00791 *)((u8*)a0))->f0);
}







/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 32)) to CLACT_DeleteUnit.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0BA8(u8 *a0)
{
    CLACT_DeleteUnit((struct Bank *)((u32)(((struct Obj25986 *)a0)->f20)));
}







void func_021C0BB4(void *p)
{
    ((struct Obj25987 *)p)->f24 = 0;
}






/*
 * prototype: DBC reads only r0/r1; original r2 was an earlier local-store base, not a live reader input. B294 caller observes r0 despite legacy void return.
 */
void func_021C0BBC(u8 *p)
{
    struct Arg arg;
    u32 a,b,c,d;
    arg.x=d_021C3F80.x; arg.y=d_021C3F80.y; arg.z=d_021C3F80.z;
    arg.a=d_021C3F80.a; arg.b=d_021C3F80.b;
    a=func_021C0DBC(p,d_021C3F80.c);
    b=func_021C0DB4(p,d_021C3F80.d);
    c=func_021C0DB4(p,d_021C3F80.e);
    d=func_021C0DB4(p,d_021C3F80.f);
    *(u32 *)&((struct Obj00791 *)p)->f24=(u32)CLACT_CreateActor((void *)a,b,c,d,&arg,d_021C3F80.g,((struct Obj00791 *)p)->f0);
    func_0204B3DC(*(struct Obj * *)&((struct Obj00791 *)p)->f24,1);
}







/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 36)) to CLACT_DeleteActor.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0C2C(u8 *a0)
{
    CLACT_DeleteActor((struct Obj *)((u32)(((struct Obj25988 *)a0)->f24)));
}







void func_021C0C38(void *p)
{
    ((struct Obj25989 *)p)->f28 = 0;
}






void func_021C0C40(u32 a0)
{
    *(u32 *)&((struct Obj00791 *)(((u8*)a0 + 0)))->f28 = (u32)PALANM_Create(((struct Obj00791 *)((u8*)a0))->f0);
}






void func_021C0C50(u8 *a0)
{
    PALANM_Delete((void *)(((struct Obj25990 *)(((u8*)a0)))->f28));
}






void func_021C0C5C(u8 *p)
{
    struct PalAnmSlot *slots = *(struct PalAnmSlot * *)&((struct Obj00791 *)p)->f28;
    PALANM_AllocSlotBuffers(slots, 0, 512, ((struct Obj00791 *)p)->f0);
    PALANM_AllocSlotBuffers(slots, 2, 512, ((struct Obj00791 *)p)->f0);
    PALANM_AllocSlotBuffers(slots, 1, 512, ((struct Obj00791 *)p)->f0);
    PALANM_AllocSlotBuffers(slots, 3, 512, ((struct Obj00791 *)p)->f0);
    PALANM_CopyHwPaletteToSlot(slots, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 2, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 1, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 3, 0, 512);
}







void func_021C0CC8(int *p)
{
    int obj;
    obj = p[10];
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 2);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 1);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 3);
}







/*
 * Clear the u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0CF0(void *p)
{
    ((struct Obj25992 *)p)->f2C = 0;
}






void func_021C0CF8(u32 a0)
{
    ((struct Obj00791 *)(((u8*)a0 + 0)))->f2C = func_021C29C8(((struct Obj00791 *)((u8*)a0))->f0);
}







void func_021C0D08(u8 *a0)
{
    func_021C29D8((void *)(((struct Obj25993 *)a0)->f2C));
}






void func_021C0D14(u8 *a0)
{
    func_021C29E8((void *)((struct Obj25994 *)(((u8*)a0)))->f2C, *(u32*)(((u8*)0x21C3F50)), *(u32*)(((u8*)0x21C3F50) + 4), *(u8*)(((u8*)0x21C3F50) + 8));
}







/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 44)) to func_021C2A08.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D2C(u8 *a0)
{
    func_021C2A08((char *)((u32)(((struct Obj25995 *)a0)->f2C)));
}







/*
 * Unlabelled 22-byte ov217 leaf in a .word run; tail-calls func_021C29F8 with
 * two ov217 data-table loads indexed by i*0x14.  Middle of the
 * func_021BA31C blocker chain.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D38(u8 *p, u32 i)
{
    func_021C29F8((u8 *)(*(u32 *)(p + i * 4 + 0x2c)),
                  *(u32 *)(d_021C3F5C + i * 0x14),
                  *(u16 *)(d_021C3F60 + i * 0x14));
}






void func_021C0D5C(u8 *p, u32 i)
{
    func_021C2A00(*(u32 *)(p + i * 4 + 0x2c));
}






/*
 * Indexed getter, tail call to func_021C2A08.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D6C(u8 *p, u32 i)
{
    func_021C2A08((char *)(*(u32 *)(p + i * 4 + 0x2c)));
}






/*
 * Indexed getter, tail call to func_021C29F0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D7C(u32 *p)
{
    func_021C29F0(p[0xb]);
}







void func_021C0D88(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0xE] = d_021C3F48[i * 4];
        p[i * 4 + 0xF] = d_021C3F48[i * 4 + 1];
        p[i * 4 + 0xC] = d_021C3F48[i * 4 + 2];
        p[i * 4 + 0xD] = d_021C3F48[i * 4 + 3];
    }
}







/*
 * Indexed u32 read: element i of the table at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DB4(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x14);
}






/*
 * Indexed u32 read: element i of the table at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DBC(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x20);
}





u32 func_021C0DC4(u32 a0)
{
    return (u32)func_02030734(a0, 12, 1, (const char *)0x21C4034, 32);
}






void func_021C0DDC(void *a0)
{
    func_020307B0(a0);
}






void func_021C0DE4(void *p)
{
    ((struct Obj10965 *)p)->f0 = 0;
    ((struct Obj10965 *)p)->f4 = 0;
    ((struct Obj10965 *)p)->f8 = -0x18;
}






/*
 * Field getter, u8 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DF0(void *p)
{
    return ((struct Obj25997 *)p)->f0;
}






/*
 * Field getter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DF4(void *p)
{
    return ((struct Obj25998 *)p)->f4;
}






u32 func_021C0DF8(void *p)
{
    return ((struct Obj25999 *)p)->f8;
}






/*
 * Field setter, u8 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0DFC(void *p, u8 v)
{
    ((struct Obj26000 *)p)->f0 = v;
}






/*
 * Field setter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E00(void *p, u32 v)
{
    ((struct Obj26001 *)p)->f4 = v;
}






/*
 * Field setter, u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E04(void *p, u32 v)
{
    ((struct Obj26002 *)p)->f8 = v;
}






int func_021C0E08(int a0, int a1)
{
    int h;
    h = (int)func_02030734(a1, 0x10, 0, (const char *)d_021C4050, 0x3C);
    func_021C0E6C((void *)h);
    func_021C0E78(h, a0, a1);
    return h;
}





void func_021C0E3C(void *p)
{
    func_021C0E98(p);
    func_020307B0(p);
}




void func_021C0E4C(u32 a0, u32 a1)
{
    func_021C0EA4((char *)a0, (int)a1);
}





/*
 * Tail-call veneer: branch to func_021C0EC0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0E54(struct Ring *r)
{
    return func_021C0EC0(r);
}





/*
 * Tail-call veneer: branch to func_021C0EDC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E5C(Rec *p)
{
    func_021C0EDC(p);
}





/*
 * Tail-call veneer: branch to func_021C0EE4.
 *
 * Addresses are Black-image addresses.
 */
int func_021C0E64(Rec *p)
{
    return func_021C0EE4(p);
}





/*
 * Clear the u32 fields at +0, +8 and +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E6C(void *p)
{
    ((struct Obj06714 *)p)->f0 = 0;
    ((struct Obj06714 *)p)->f8 = 0;
    ((struct Obj06714 *)p)->fC = 0;
}


void func_021C0E78(u32 a0, u32 a1, u32 a2)
{
    ((struct Obj06714 *)((u8*)a0))->f0 = (u32)func_02030734(a2, ((u32)a1 << 2), 0, (const char *)0x21C4050, 211);
    ((struct Obj06714 *)(((u8*)a0)))->f4 = a1;
}



void func_021C0E98(u8 *a0)
{
    func_020307B0((void *)((u32)(((struct Obj26003 *)a0)->f0)));
}



void func_021C0EA4(char *p, int v)
{
    *(int *)(((struct Obj06715 *)p)->f0 + ((struct Obj06715 *)p)->fC * 4) = v;
    ((struct Obj06715 *)p)->fC = (((struct Obj06715 *)p)->fC + 1) % ((struct Obj06715 *)p)->f4;
}



u32 func_021C0EC0(struct Ring *r)
{
    u32 v;
    v = r->buf[r->pos];
    r->pos = (r->pos + 1) % r->count;
    return v;
}



/*
 * Clears two words of a record.  Reached only from the tail-call veneer
 * func_021C0E5C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0EDC(Rec *p)
{
    p->a = 0;
    p->b = 0;
}



/*
 * Whether two words of a record are equal.  Reached only from the tail-call
 * veneer func_021C0E64.
 *
 * Addresses are Black-image addresses.
 */
int func_021C0EE4(Rec *p)
{
    return p->a == p->b;
}
