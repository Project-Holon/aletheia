/*
 * file:     unit_021F604C.c
 * unit:     yes
 * function: func_021F604C, func_021F6060, func_021F6114, func_021F6158, func_021F6164, func_021F6194, func_021F6228, func_021F6280, func_021F62C8, func_021F62CC, func_021F62FC, func_021F6328
 * address:  0x021F604C
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Main 0x020310C4 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   func_0203FA08 0x0203FA08 arm
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021F71A4 0x021F71A4 data a2
 */
#include "../../matched/include/Obj01296.h"
#include "../../matched/include/Obj02926.h"
#include "../../matched/include/Obj25747.h"
#include "../../matched/include/Obj10939.h"
#include "../../matched/include/Obj01590.h"
#include "../../matched/include/Obj02261.h"
#include "../../matched/include/Obj10940.h"
#include "../../matched/include/Obj05550.h"
#include "../../matched/include/Obj08425.h"
#include "../../matched/include/Obj06706.h"
#include "../../matched/include/Obj25748.h"

struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Tcbl;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Cfg;
struct WordSet;
struct WinDat;
struct BmpMenu;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Main(struct Tcbl *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern signed char func_02012FFC(void);
extern void *PRINTSYS_PrintStream(void *,unsigned,unsigned,void *,unsigned,unsigned,void *,unsigned,u16,u16);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern unsigned BMP_MENU_ProcessYesNo(u8 *);
extern struct BmpMenu *BMP_MENU_CreateYesNo(const struct WinDat *,unsigned short,unsigned char,unsigned char,unsigned short);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
void func_021F604C(void);
void func_021F6060(int unused,char *p);
void func_021F6114(void *unused,char *p);
void func_021F6158(void *unused, char *p);
void func_021F6164(void *unused, char *p);
void func_021F6194(char *object,char *p,unsigned entry);
int func_021F6228(void *unused,char *p);
void func_021F6280(int unused, unsigned char *q);
void func_021F62C8(int a0, char *a1);
void func_021F62CC(void *unused, char *p);
int func_021F62FC(int a,char *p);
int func_021F6324(int a,char *p);
void func_021F6328(void);
extern const u16 d_021F71A4[];


void func_021F604C(void)
{
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(0x3c);
}

void func_021F6060(int unused,char *p)
{
    func_02049B40(23,5,0,32,32,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f5C=BMP_WIN_Create(1,0,0,1,1,1,0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01296 *)p)->f5C)),0);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01296 *)p)->f5C);
    ((struct Obj01296 *)p)->f58=BMP_WIN_Create(1,1,19,30,4,1,0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01296 *)p)->f58)),15);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01296 *)p)->f58);
    ((struct Obj01296 *)p)->f60=(u32)func_0201F5DC((void *)1,2,0,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f64=(u32)func_02045B38(0,3,260,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f54=(u32)TCBL_Create(((struct Obj01296 *)p)->f0,((struct Obj01296 *)p)->f0,1,0);
    GF_FONT_SetTextColor(1,2,15);
    func_02041B6C(1);
    ((struct Obj01296 *)p)->f50=0;
    ((struct Obj01296 *)p)->f68=0;
    ((struct Obj01296 *)p)->f6C=0;
    func_02040588(1,0);
}

void func_021F6114(void *unused,char *p)
{
    if(((struct Obj02926 *)p)->f50) PRINTSYS_PrintStreamDelete(((struct Obj02926 *)p)->f50);
    if(((struct Obj02926 *)p)->f68) STRBUF_Delete(((struct Obj02926 *)p)->f68);
    TCBL_Destroy(((struct Obj02926 *)p)->f54);
    MSGDATA_Delete(((struct Obj02926 *)p)->f64);
    func_0203FB44(1,(u16)((struct Obj02926 *)p)->f60,(u16)(((struct Obj02926 *)p)->f60>>16));
    BMP_WIN_Delete(((struct Obj02926 *)p)->f58);
    BMP_WIN_Delete(((struct Obj02926 *)p)->f5C);
}

void func_021F6158(void *unused, char *p)
{
    TCBL_Main(((struct Obj25747 *)p)->f54);
}

void func_021F6164(void *unused, char *p)
{
    void *obj;
    func_0201F73C(((struct Obj10939 *)p)->f58, 0, (u16)(((struct Obj10939 *)p)->f60), 2);
    obj = ((struct Obj10939 *)p)->f58;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_020409B4(BMP_WIN_GetBgLayer(obj));
}

/*
 * evidence: CCE4 return widened because original stores live r0 after call.
 */
void func_021F6194(char *object,char *p,unsigned entry)
{
    void *text,*words,*buffer;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01590 *)p)->f58),15);
    if(((struct Obj01590 *)p)->f50) PRINTSYS_PrintStreamDelete(((struct Obj01590 *)p)->f50);
    if(((struct Obj01590 *)p)->f68) STRBUF_Delete(((struct Obj01590 *)p)->f68);
    text=func_02045EC0(((struct Obj01590 *)p)->f64,entry);
    words=func_0201EC64(((struct Obj01590 *)p)->f0);
    func_0201EE84(words,0,((struct Obj02261 *)object)->f4);
    buffer=STRBUF_Create(256,((struct Obj01590 *)p)->f0);
    ((struct Obj01590 *)p)->f68=buffer;
    func_0201F250(words,buffer,text);
    func_0201ED04(words);
    STRBUF_Delete(text);
    ((struct Obj01590 *)p)->f50=PRINTSYS_PrintStream(((struct Obj01590 *)p)->f58,0,0,((struct Obj01590 *)p)->f68,((struct Obj01590 *)p)->f8,func_02012FFC(),((struct Obj01590 *)p)->f54,2,((struct Obj01590 *)p)->f0,15);
}

int func_021F6228(void *unused,char *p)
{
    int result=0;
    switch(PRINTSYS_PrintStreamGetState(((struct Obj10940 *)p)->f50)) {
    case 0:
        if((KEY_GetCont()&3)!=0 || TOUCHPANEL_GetCont()!=0)
            PRINTSYS_PrintStreamShortWait(((struct Obj10940 *)p)->f50,0);
        break;
    case 1:
        if((KEY_GetTrg()&3)!=0 || TOUCHPANEL_GetTrg()!=0)
            PRINTSYS_PrintStreamReleasePause(((struct Obj10940 *)p)->f50);
        break;
    case 2:
        result=1;
        break;
    }
    return result;
}


void func_021F6280(int unused, unsigned char *q)
{
    int h = func_0203FA08(1, 0x500, 1);

    func_0203FB44(1, h, 0x500);
    q[0x70] = 1;
    q[0x71] = 0x18;
    q[0x72] = 0xd;
    q[0x73] = 1;
    ((struct Obj05550 *)q)->f74 = h;
    ((struct Obj05550 *)q)->f7C = 2;
}

void func_021F62C8(int a0, char *a1)
{

}

void func_021F62CC(void *unused, char *p)
{
    unsigned result;
    int flag;
    switch (((struct Obj08425 *)p)->f20) {
    case 0:
        break;
    case 1:
        result = BMP_MENU_ProcessYesNo(*(u8 * *)&((struct Obj08425 *)p)->f78);
        if (result != 0xffffffff) {
            if (result == 0) flag = 1;
            else flag = 0;
            ((struct Obj08425 *)p)->f7C = flag;
            ((struct Obj08425 *)p)->f20 = 2;
        }
        break;
    }
}

int func_021F62FC(int a,char *p){*(struct BmpMenu * *)&((struct Obj06706 *)p)->f78=BMP_MENU_CreateYesNo((const struct WinDat *)(p+0x70),((struct Obj06706 *)p)->f60,2,0,((struct Obj06706 *)p)->f0);((struct Obj06706 *)p)->f7C=2;((struct Obj06706 *)p)->f20=1;return 1;}

/*
 * extent: includes cleared tiny follower func_021F6324; no further code included.
 */
int func_021F6324(int a,char *p){return ((struct Obj25748 *)p)->f7C;}

static inline void SetPriority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3)|(priority<<0));
}

/*
 * volatile: hardware 021F6336,6342,634E,6358,6362,636E,6392.
 */
void func_021F6328(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    SetPriority(0);
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3002)|2);
    *(volatile u16 *)0x04000060 &= ~0x3010;
    *(volatile u16 *)0x04000060 &= ~0x3004;
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3000)|8);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,d_021F71A4+i*4);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
