/*
 * file:     the_end_graphic.c
 * unit:     yes
 * function: func_021B95A0, func_021B964C, func_021B96BC, func_021B9784, func_021B9788, func_021B9810, func_021B9814, func_021B9840, func_021B98E4, func_021B998C, func_021B99E8, func_021B99FC, func_021B9A10, func_021B9A70, func_021B9AA8, func_021B9AAC, func_021B9AB4, func_021B9AF4, func_021B9B10, func_021B9B18, func_021B9B20
 * address:  0x021B95A0
 * region:   ov182
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B9B9C 0x021B9B9C data a2
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   func_0207E468 0x0207E468 arm
 *   d_021B9BAC 0x021B9BAC data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_020362DC 0x020362DC arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   FADE_Start  0x0204E720  arm
 *   func_020434DC 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021B9C28 0x021B9C28 data a4
 *   func_02030734 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   d_021B9CE0 0x021B9CE0 data a1
 *   d_021B9C48 0x021B9C48 data a4
 *   func_021B9B8C 0x021B9B8C thumb ov182
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   d_021B9BFC 0x021B9BFC data a4
 *   d_021B9C78 0x021B9C78 data a4
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   d_021B9C0C      0x021B9C0C  data
 *   CLACT_InitSystem   0x0204A48C  arm
 *   CLACT_CreateUnit   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   BG_SYS_SetSubPlaneVisible   0x02043598  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021B9BE4 0x021B9BE4 data a4
 *   d_021B9BD8 0x021B9BD8 data a4
 *   d_021B9BF0 0x021B9BF0 data a4
 */
#include "../../matched/include/Obj03328.h"
#include "../../matched/include/Obj06593.h"
#include "../../matched/include/Obj06594.h"
#include "../../matched/include/Obj24514.h"
#include "../../matched/include/Obj24515.h"
#include "../../matched/include/Obj24516.h"

struct Obj0203159C;
struct GfFont;
struct Node;
struct PrintSys;
struct S020315D4;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {u32 id; u32 v[10];} Record;

typedef signed int     s32;

typedef struct { unsigned id; unsigned v[8]; unsigned a, b; } Record_021B9A10;

typedef struct {u32 id;u32 v[8];u32 a,b;} Record_021B9A70;

typedef unsigned long long u64;

extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, int);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void *func_020056A0(void (*)(void), void *, int);
extern unsigned GPOWER_GetSpecialPowerId(void);
extern void func_0207E468(void *, int, int);
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern int FADE_IsActive(void);
extern unsigned func_020362DC(void);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(unsigned char *);
extern void func_020409B4(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void func_020434DC(u32 mask, u32 enable);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_021B9B8C(unsigned *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(int);
extern void BMP_WIN_Init(int);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void G3D_SYSTEM_Init(int,int,int,int,u16,u16,void *);
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const void *,const void *,const void *,u16);
int func_021B95A0(void *task, int b, int c);
int func_021B964C(void *task, int b, int c, char *p);
int func_021B96BC(void *a, unsigned *state, void *c, char *p);
void func_021B9784(void);
void func_021B9788(unsigned short *p);
void func_021B9810(void *p);
void func_021B9814(void *a, void *b, void *c);
void func_021B9840(void);
char *func_021B98E4(int a, u16 heap);
void func_021B998C(char *p);
void func_021B99E8(char *p);
void func_021B99FC(int a0, char *p);
void func_021B9A10(void *p, int heap);
void func_021B9A70(void *p);
void func_021B9AA8(void *p);
void func_021B9AAC(void *a0);
void func_021B9AB4(int *p, int b, int c);
void func_021B9AF4(void *p);
void func_021B9B10(void *a0);
void func_021B9B18(void *a0);
void func_021B9B20(int *p,u16 heap);
extern const u16 d_021B9B9C;
extern const Record d_021B9BAC[1];
extern const u32 d_021B9C28[][2];
extern const char d_021B9CE0[];
extern const u32 d_021B9C48[];
extern const unsigned d_021B9BFC[];
extern const Record_021B9A10 d_021B9C78[];
extern unsigned char d_021B9C0C[];
extern const short d_020A1EB8[];
extern const int d_021B9BE4[],d_021B9BD8[],d_021B9BF0[];







int func_021B95A0(void *task, int b, int c)
{
    u16 value[1];
    char *p;
    u16 *vp;
    value[0] = d_021B9B9C;
    vp = value;
    GFL_HEAP_CreateChildHeap(1, 0x88, 0x30000);
    p = PROCSYS_AllocProcWork(task, 0x1c, 0x88);
    func_02082BCC(p, 0, 0x1c);
    ((struct Obj03328 *)p)->f0 = 0x88;
    ((struct Obj03328 *)p)->f10 = c;
    ((struct Obj03328 *)p)->f4 = func_021B98E4(1, ((struct Obj03328 *)p)->f0);
    ((struct Obj03328 *)p)->f8 = GF_FONT_Create(0x17, 0, 0, 0, ((struct Obj03328 *)p)->f0);
    ((struct Obj03328 *)p)->fC = (void *)func_0201C440((void *)(((struct Obj03328 *)p)->f0));
    func_0204047C(1, 1);
    func_0204047C(2, 0);
    ((struct Obj03328 *)p)->f14 = func_020056A0(func_021B9784, p, 1);
    func_021B9788((u16 *)p);
    if (GPOWER_GetSpecialPowerId() == 0x14)
        func_0207E468(vp, 0, 2);
    func_021B9814((void *)0x10, 0, 0);
    return 1;
}







/*
 * volatile: hardware 04001050 and 04001000 read/write at 021B966C-021B967A.
 */
int func_021B964C(void *task, int b, int c, char *p)
{
    int i;
    for (i = 0; i < sizeof(d_021B9BAC) / sizeof(d_021B9BAC[0]); i++)
        func_020403F4((u8)d_021B9BAC[i].id);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    func_021B9810(p);
    func_02030EAC(((struct Obj06593 *)p)->f14);
    func_0201C6EC(((struct Obj06593 *)p)->fC);
    func_0201C4C0(((struct Obj06593 *)p)->fC);
    GF_FONT_Delete(((struct Obj06593 *)p)->f8);
    func_021B998C(((struct Obj06593 *)p)->f4);
    func_020315D4(task);
    func_020306F0(0x88);
    return 1;
}







int func_021B96BC(void *a, unsigned *state, void *c, char *p)
{
    int ready;
    switch (*state) {
    case 0: *state = 4; break;
    case 1:
        if (!FADE_IsActive()) *state = 2;
        break;
    case 2:
        ready = 0;
        if (++((struct Obj06594 *)p)->f18 > 0x384) ready = 1;
        if (ready) {
            *state = 3;
            func_021B9814(0, (void *)0x10, 0);
        }
        break;
    case 3:
        if (!FADE_IsActive()) {
            func_021B9788((u16 *)p);
            func_021B9814((void *)0x10, 0, 0);
            *state = 4;
        }
        break;
    case 4:
        if (!FADE_IsActive()) {
            ((struct Obj06594 *)p)->f18 = 0;
            *state = 5;
        }
        break;
    case 5:
        if ((func_020362DC() & 0xb) || ++((struct Obj06594 *)p)->f18 > 0x384) {
            *state = 6;
            func_021B9814(0, (void *)0x10, 0);
        }
        break;
    case 6:
        if (!FADE_IsActive()) *state = 7;
        break;
    case 7: return 1;
    }
    PRINTSYS_QUE_Main(((struct Obj06594 *)p)->fC);
    func_021B99E8(*(char * *)&((struct Obj06594 *)p)->f4);
    return 0;
}







void func_021B9784(void)
{
}







void func_021B9788(unsigned short *p)
{
    unsigned char *q = func_020490F4(0xdc, *p);
    func_02049B68(q, 2, 0, 0, 0, *p);
    func_02049658(q, 3, 1, 0, 0, 0, *p);
    func_020498F4(q, 5, 1, 0, 0, 0, *p);
    if (GPOWER_GetSpecialPowerId() == 0x14)
        func_020413B0(1, 0, 0, 0x20, 0x18, 1);
    ARC_TOOL_DeleteHandle(q);
    func_020409B4(1);
    func_02040588(1, 1);
    func_02040588(2, 0);
}







void func_021B9810(void *p){}








void func_021B9814(void *a, void *b, void *c)
{
    if (GPOWER_GetSpecialPowerId() == 0x15)
        FADE_Start(3, (s32)a, (s32)b, (s32)c);
    else
        FADE_Start(0xc, (s32)a, (s32)b, (s32)c);
}







/*
 * volatile: hardware 04000008/04000060 read/write 021B984E-021B988C, 04000580 write 021B98AA.
 */
void func_021B9840(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3002) | 2;
    *(volatile u16 *)0x04000060 &= (u16)~0x3010;
    *(volatile u16 *)0x04000060 &= (u16)~0x3004;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    *(volatile u16 *)0x04000060 &= (u16)~0x3020;
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_SetLight((u8)i, (const u16 *)d_021B9C28[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}







char *func_021B98E4(int a, u16 heap)
{
    char *p;
    p = func_02030734(heap, 0x10, 0, d_021B9CE0, 0x1cc);
    func_02082BCC(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9C48);
    func_0204363C(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021B9A10(p, heap);
    func_021B9AB4((int *)(p + 4), (int)d_021B9C48, heap);
    func_021B9B20((int *)(p + 8), heap);
    ((struct Obj24514 *)p)->fC = func_020056A0((void ( *)(void))func_021B99FC, p, 0);
    return p;
}







/*
 * volatile: Hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 read/write at 0x021B99B2..0x021B99C8.
 */
void func_021B998C(char *p)
{
    func_02030EAC(((struct Obj24515 *)p)->fC);
    func_021B9B8C((unsigned *)(p + 8));
    func_021B9AF4(p + 4);
    func_021B9A70(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}







void func_021B99E8(char *p)
{
    func_021B9B10(p + 4);
    func_021B9AA8(p);
}







void func_021B99FC(int a0, char *p)
{
    func_021B9AAC(p);
    func_021B9B18(p + 4);
}






void func_021B9A10(void *p, int heap)
{
    unsigned i = 0;
    const Record_021B9A10 *r;
    unsigned id;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021B9BFC);
    for (; i < 2; i++) {
        r = &d_021B9C78[i];
        id = r->id;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)r->v, (unsigned char)r->a);
        func_020414AC(id);
        func_02040588(id, r->b);
    }
}






void func_021B9A70(void *p){u32 i;for(i=0;i<2;i++)func_020403F4((u8)d_021B9C78[i].id);BMP_WIN_Exit();func_0203F9B4();func_02082BCC(p,0,4);}






void func_021B9AA8(void *p){}




void func_021B9AAC(void *a0) { func_020419E4(); }




void func_021B9AB4(int *p, int b, int c)
{
    func_02082BCC((void *)((int)p), 0, 4);
    CLACT_InitSystem((const struct Cfg *)d_021B9C0C, b, c);
    p[0] = (int)CLACT_CreateUnit(0x80, 0, c);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void func_021B9AF4(void *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj24516 *)p)->f0));
    CLACT_ExitSystem();
    func_02082BCC(p, 0, 4);
}


void func_021B9B10(void *a0) { CLACT_DrawSystem(); }


void func_021B9B18(void *a0) { CLACT_VBlankSystem(); }


void func_021B9B20(int *p,u16 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,func_021B9840);
    *p=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,d_021B9BE4,d_021B9BD8,d_021B9BF0,heap);
}
