/*
 * function: func_021C01B8
 * address: 0x021C01B8
 * packet: pkt_ov217_021C01B8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: direct indexed assignment computes and spills the destination before allocation; a handle temporary first gave 116 bytes and 47 differing bytes.
 * prototype: keep caller's visible second argument to 021C0F5C despite its legacy one-argument source (021C021C loads r1 before call).
 * symbols:
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   d_021C3B7C 0x021C3B7C data ov217
 */
#include "../include/Obj14750.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Config { u8 a,b,c,d,e,f,g,h,i,j,k; u32 extra; };
struct Entry { u8 a,b,c,d,e,f,g,h,i,j,k; u32 index, mode, extra; };
extern const struct Entry d_021C3B7C[];
struct Record;
extern struct Record *BgTextLabel_Create(const struct Config *config, u32 a, u32 b, u32 heap);
extern u32 BgTextLabel_PrintMessage(u32, u32);
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
        *(u32 *)(p + i * 4 + 0x344) = (u32)BgTextLabel_Create(&args, ((struct Obj14750 *)p)->f8, *(u32 *)(p + d_021C3B7C[i].index * 4 + 12), ((struct Obj14750 *)p)->f4);
        handle = *(u32 *)(p + i * 4 + 0x344);
        BgTextLabel_PrintMessage(handle, d_021C3B7C[i].mode);
    }
}
