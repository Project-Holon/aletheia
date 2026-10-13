/*
 * file:     unit_021BFFC8.c
 * unit:     yes
 * function: func_021BFFC8, func_021C0084, func_021C00AC, func_021C00F8, func_021C00FC, func_021C0114, func_021C0124, func_021C0170, func_021C0174, func_021C018C, func_021C019C, func_021C01B8, func_021C0230, func_021C0250, func_021C02A8, func_021C02C8, func_021C0358, func_021C0384, func_021C03A0, func_021C03D0, func_021C03EC, func_021C0408, func_021C0494, func_021C04B0, func_021C04CC, func_021C04FC
 * address:  0x021BFFC8
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
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204044C 0x0204044C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   sub_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021C366C 0x021C366C data a4
 *   d_021C36D8 0x021C36D8 data ov217
 *   d_021C36F8 0x021C36F8 data ov217
 *   d_021C3718 0x021C3718 data ov217
 *   d_021C3738 0x021C3738 data ov217
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_021C0EF4 0x021C0EF4 thumb ov217
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C3B7C 0x021C3B7C data ov217
 *   func_021C0F48  0x021C0F48  thumb  ov217
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   d_021C3620  0x021C3620  data  a2
 *   d_021C3618  0x021C3618  data  a1
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   d_021C37FC 0x021C37FC data a4
 *   func_021BF9FC 0x021BF9FC thumb ov217
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   d_021C37A4  0x021C37A4  data  a4
 *   BMP_Create  0x02043678  arm
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_Blit 0x020439A0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_Delete 0x020437AC arm
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 */
#include "../../matched/include/Obj25959.h"
#include "../../matched/include/Obj14748.h"
#include "../../matched/include/Obj14749.h"
#include "../../matched/include/Obj14750.h"
#include "../../matched/include/Obj08438.h"
#include "../../matched/include/Obj10960.h"
#include "../../matched/include/Obj06713.h"
#include "../../matched/include/Obj08439.h"
#include "../../matched/include/Obj25960.h"
#include "../../matched/include/Obj14752.h"
#include "../../matched/include/Obj25962.h"
#include "../../matched/include/Obj25964.h"
#include "../../matched/include/Obj14753.h"
#include "../../matched/include/Obj14754.h"

struct ArcFile;
struct Record;
struct Bank;
struct Obj;
struct Bmp;
struct MsgBank;
struct Obj020437AC;
typedef unsigned int u32;

typedef unsigned short u16;

struct DispConfig { u32 a,b,c,d; };

struct BgTemplate { u32 a,b,c,d; unsigned char e,f,g,h; u32 i; unsigned char j,k,l,m; u32 n; };

typedef unsigned char  u8;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Config { u8 a,b,c,d,e,f,g,h,i,j,k; u32 extra; };

struct Entry_021BFFC8 { u8 a,b,c,d,e,f,g,h,i,j,k; u32 index, mode, extra; };

struct Arg { s16 x,y,z; u8 a,b; };

struct Entry_021C03D0 { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

struct Entry { int x,y,z,bank,index,px,py; u8 r,g,b,pad2; u32 arc,member,enabled; };

extern void func_0203FC28(struct DispConfig *);
extern void func_0204044C(u32);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32 *, u32, u32, int, int);
extern void BMP_WIN_Init(u16);
extern u32 func_020403F4();
extern void BMP_WIN_Exit(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_020409B4(u32);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32 func_020414EC();
extern void func_02040DA8(u32, u32, u32);
extern struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
extern u32 func_021C0F5C(u32, u32);
extern void func_021C0F48(u8 *p);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern u32 CLACT_ReleaseCellAnim();
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_021BF9FC(void *,u32);
extern u32 func_021BF9F0(void *,u32);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *,u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct Bmp *BMP_CreateFromArchive(u32,u32,u32,u32);
extern void BMP_Blit(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void BMP_Delete(struct Obj020437AC *);
void func_021BFFC8(char *p);
u32 func_021C0084(void);
void func_021C00AC(char *p);
void func_021C00F8(void);
u32 func_021C00FC(void);
void func_021C0114(void);
void func_021C0124(char *p);
void func_021C0170(void);
u32 func_021C0174(void);
void func_021C018C(u32 a0, u32 a1, u32 a2);
void func_021C019C(void *p);
void func_021C01B8(char *p);
void func_021C0230(int *p);
void func_021C0250(char *p);
u32 func_021C02A8(u32 a0);
void func_021C02C8(char *p);
u32 func_021C0358(u32 a0);
void func_021C0384(void *p);
void func_021C03A0(u8 *p);
void func_021C03D0(int *p);
void func_021C03EC(void *p);
void func_021C0408(u8 *p);
void func_021C0494(int *p);
void func_021C04B0(void *p);
void func_021C04CC(u8 *p);
void func_021C04FC(u8 *p);
extern struct DispConfig d_021C366C;
extern const struct BgTemplate d_021C36D8,d_021C36F8,d_021C3718,d_021C3738;
extern const struct Entry_021BFFC8 d_021C3B7C[];
extern const u16 d_021C3620[];
extern const u8 d_021C3618[];
extern const struct Entry_021C03D0 d_021C37FC[];
extern const struct Entry d_021C37A4[];






/*
 * data: pool 021C0068 contains 6c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 */
void func_021BFFC8(char *p)
{
    func_0203FC28(&d_021C366C);
    func_0204044C(2);
    func_0203FCA0(6, &d_021C36D8, 0);
    func_0203FCA0(7, &d_021C3738, 0);
    func_0203FCA0(2, &d_021C36F8, 0);
    func_0203FCA0(3, &d_021C3718, 0);
    sub_02040588(4, 1);
    sub_02040588(5, 1);
    sub_02040588(6, 1);
    sub_02040588(7, 1);
    sub_02040588(0, 1);
    sub_02040588(1, 1);
    sub_02040588(2, 1);
    sub_02040588(3, 1);
    func_0207D63C((u32 *)0x04001050, 2, 1, 7, 15);
    func_0207D63C((u32 *)0x04000050, 4, 2, 16, 5);
    BMP_WIN_Init(((struct Obj25959 *)p)->f4);
}






/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0084(void)
{
    BMP_WIN_Exit();
    func_020403F4(0);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(7);
    return func_020403F4(6);
}






void func_021C00AC(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = func_020490F4(192, ((struct Obj14748 *)p)->f4);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 13, ((struct Obj14748 *)p)->f4);
    func_02062B30(blob, &out);
    func_02041090(6, (u32)((char *)out + 12), 0, 0, 32, 24);
    func_020409B4(6);
    func_020307B0((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}







/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021C00F8(void)
{
}






u32 func_021C00FC(void)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}







/*
 * Tail-call veneer: forwards arg(s) 7, 1, 0 to func_02040DA8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0114(void)
{
    func_02040DA8(7, 1, 0);
}






/*
 * extent: trailing 00 00 at 021C016E is two-byte alignment padding.
 */
void func_021C0124(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = func_020490F4(192, ((struct Obj14749 *)p)->f4);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 7, ((struct Obj14749 *)p)->f4);
    func_02062B30(blob, &out);
    func_02041090(2, (u32)((char *)out + 12), 0, 0, 32, 32);
    func_020409B4(2);
    func_020307B0((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}







void func_021C0170(void)
{
}






u32 func_021C0174(void)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}







/*
 * Tail-call veneer: forwards arg(s) 3, 1, 0 to func_02040DA8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C018C(u32 a0, u32 a1, u32 a2)
{
    func_02040DA8(3, 1, 0);
}







/*
 * Clear nine u32 slots at +0x344.
 *
 * Addresses are Black-image addresses.
 */
void func_021C019C(void *p)
{
    int i;
    for (i = 0; i < 9; i++)
        *(u32 *)((char *)p + i * 4 + 0x344) = 0;
}






/*
 * lever: direct indexed assignment computes and spills the destination before allocation; a handle temporary first gave 116 bytes and 47 differing bytes.
 * prototype: keep caller's visible second argument to 021C0F5C despite its legacy one-argument source (021C021C loads r1 before call).
 */
void func_021C01B8(char *p)
{
    struct Config args;
    int i;
    for (i = 0; i < 9; i++) {
        u32 handle;
        args.a = d_021C3B7C[i].a;
        args.b = d_021C3B7C[i].b;
        args.c = d_021C3B7C[i].c;
        args.d = d_021C3B7C[i].d;
        args.e = d_021C3B7C[i].e;
        args.f = d_021C3B7C[i].f;
        args.g = d_021C3B7C[i].g;
        args.h = d_021C3B7C[i].h;
        args.i = d_021C3B7C[i].i;
        args.j = d_021C3B7C[i].j;
        args.k = d_021C3B7C[i].k;
        args.extra = d_021C3B7C[i].extra;
        *(u32 *)(p + i * 4 + 0x344) = (u32)func_021C0EF4(&args, ((struct Obj14750 *)p)->f8, *(u32 *)(p + d_021C3B7C[i].index * 4 + 12), ((struct Obj14750 *)p)->f4);
        handle = *(u32 *)(p + i * 4 + 0x344);
        func_021C0F5C(handle, d_021C3B7C[i].mode);
    }
}







/*
 * Addresses are Black-image addresses.
 */
void func_021C0230(int *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        func_021C0F48((u8 *)p[i + 0xD1]);
        p[i + 0xD1] = 0;
    }
}






void func_021C0250(char *p)
{
    u16 heap = ((struct Obj08438 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 1, heap);
    int b = CLACT_RegisterPalette((void *)h, 16, 1, 0, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    ((struct Obj08438 *)p)->f378 = a;
    ((struct Obj08438 *)p)->f37C = b;
    ((struct Obj08438 *)p)->f380 = c;
    ARC_TOOL_DeleteHandle(h);
}






u32 func_021C02A8(u32 a0)
{
    CLACT_ReleaseCharacter(((struct Obj10960 *)(((u8*)a0)))->f378);
    CLACT_ReleasePalette(((struct Obj10960 *)(((u8*)a0)))->f37C);
    return CLACT_ReleaseCellAnim(((struct Obj10960 *)(((u8*)a0)))->f380);
}






void func_021C02C8(char *p)
{
    u16 heap = ((struct Obj06713 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)((u32)h), 16, 0, 192, 0, 3, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    int d;
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(83, heap);
    d = CLACT_RegisterPaletteEx((void *)((u32)h), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj06713 *)p)->f368 = a;
    ((struct Obj06713 *)p)->f36C = b;
    ((struct Obj06713 *)p)->f374 = d;
    ((struct Obj06713 *)p)->f370 = c;
}






u32 func_021C0358(u32 a0)
{
    CLACT_ReleaseCharacter(((struct Obj08439 *)(((u8*)a0)))->f368);
    CLACT_ReleasePalette(((struct Obj08439 *)(((u8*)a0)))->f36C);
    CLACT_ReleasePalette(((struct Obj08439 *)(((u8*)a0)))->f374);
    return CLACT_ReleaseCellAnim(((struct Obj08439 *)(((u8*)a0)))->f370);
}







void func_021C0384(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x384) = 0;
}







void func_021C03A0(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(int *)(p + i * 4 + 0x384) = (int)CLACT_CreateUnit(d_021C3620[i], d_021C3618[i], ((struct Obj25960 *)p)->f4);
}






void func_021C03D0(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteUnit((struct Bank *)p[i + 0xE1]);
}






/*
 * Clear four u32 slots at +0x394.
 *
 * Addresses are Black-image addresses.
 */
void func_021C03EC(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x394) = 0;
}





/*
 * prototype: 0204B294 result observed in r0 despite legacy matched void return.
 */
void func_021C0408(u8 *p)
{
    struct Arg arg;
    const struct Entry_021C03D0 *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for(i=0;i<4;i++) {
        q=&d_021C37FC[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=func_021BF9FC(p,q->c);
        b=func_021BF9F0(p,q->d);
        c=func_021BF9F0(p,q->e);
        d=func_021BF9F0(p,q->f);
        dest=p+i*4;
        *(u32 *)&((struct Obj14752 *)dest)->f394=(u32)CLACT_CreateActor((void *)a,b,c,d,&arg,q->g,((struct Obj25962 *)p)->f4);
        func_0204B3DC(*(struct Obj * *)&((struct Obj14752 *)dest)->f394,0);
    }
}





void func_021C0494(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor((struct Obj *)p[i + 0xE5]);
}





/*
 * Clear two u32 slots at +0x3b0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C04B0(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x3b0) = 0;
}



void func_021C04CC(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(int *)(p + i * 4 + 0x3B0) = (int)BMP_Create(d_021C37A4[i].x, d_021C37A4[i].y, d_021C37A4[i].z, ((struct Obj25964 *)p)->f4);
}

void func_021C04FC(u8 *p)
{
    const struct Entry *q;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u8 *dest;
    int i;
    for(i=0;i<2;i++) {
        q=&d_021C37A4[i];
        if(q->enabled) {
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,((struct Obj14753 *)p)->f4);
            dest=p+i*4;
            BMP_Blit(bmp,*(struct Bmp * *)&((struct Obj14754 *)dest)->f3B0,0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=func_02045EC0(*(struct MsgBank **)(p+12+q->bank*4),q->index);
            PRINTSYS_PrintColor(((struct Obj14754 *)dest)->f3B0,q->px,q->py,text,((struct Obj14753 *)p)->f8,color);
            func_020307B0(text);
            BMP_Delete((struct Obj020437AC *)bmp);
        }
    }
}
