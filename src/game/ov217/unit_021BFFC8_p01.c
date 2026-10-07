/*
 * file:     unit_021BFFC8_p01.c
 * unit:     yes
 * function: func_021BFFC8, func_021C0084, func_021C00AC, func_021C00F8, func_021C00FC, func_021C0114, func_021C0124, func_021C0170, func_021C0174, func_021C018C, func_021C019C, func_021C01B8, func_021C0230
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
 *   sub_02045088 0x02045088 arm
 *   d_021C366C 0x021C366C data a4
 *   d_021C36D8 0x021C36D8 data ov217
 *   d_021C36F8 0x021C36F8 data ov217
 *   d_021C3718 0x021C3718 data ov217
 *   d_021C3738 0x021C3738 data ov217
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_021C0EF4 0x021C0EF4 thumb ov217
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C3B7C 0x021C3B7C data ov217
 *   func_021C0F48  0x021C0F48  thumb  ov217
 */
#include "../../matched/include/Obj25959.h"
#include "../../matched/include/Obj14748.h"
#include "../../matched/include/Obj14749.h"
#include "../../matched/include/Obj14750.h"

struct ArcFile;
struct Record;
typedef unsigned int u32;

typedef unsigned short u16;

struct DispConfig { u32 a,b,c,d; };

struct BgTemplate { u32 a,b,c,d; unsigned char e,f,g,h; u32 i; unsigned char j,k,l,m; u32 n; };

typedef unsigned char  u8;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Config { u8 a,b,c,d,e,f,g,h,i,j,k; u32 extra; };

struct Entry { u8 a,b,c,d,e,f,g,h,i,j,k; u32 index, mode, extra; };

extern void func_0203FC28(struct DispConfig *);
extern void func_0204044C(u32);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32 *, u32, u32, int, int);
extern void sub_02045088(u16);
extern u32 func_020403F4();
extern void func_020450C8(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(struct ArcFile *, u32, u32);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_020409B4(u32);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32 func_020414EC();
extern void func_02040DA8(u32, u32, u32);
extern struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
extern u32 func_021C0F5C(u32, u32);
extern void func_021C0F48(u8 *p);
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
extern struct DispConfig d_021C366C;
extern const struct BgTemplate d_021C36D8,d_021C36F8,d_021C3718,d_021C3738;
extern const struct Entry d_021C3B7C[];

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
    sub_02045088(((struct Obj25959 *)p)->f4);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0084(void)
{
    func_020450C8();
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
    blob = func_02049250((struct ArcFile *)h, 13, ((struct Obj14748 *)p)->f4);
    func_02062B30(blob, &out);
    func_02041090(6, (u32)((char *)out + 12), 0, 0, 32, 24);
    func_020409B4(6);
    func_020307B0((void *)((u32)blob));
    func_02049238(h);
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
    blob = func_02049250((struct ArcFile *)h, 7, ((struct Obj14749 *)p)->f4);
    func_02062B30(blob, &out);
    func_02041090(2, (u32)((char *)out + 12), 0, 0, 32, 32);
    func_020409B4(2);
    func_020307B0((void *)((u32)blob));
    func_02049238(h);
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
