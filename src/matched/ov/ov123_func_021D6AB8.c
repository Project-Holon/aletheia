/*
 * function: func_021D6AB8
 * address: 0x021D6AB8
 * packet: pkt_ov123_021D6AB8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02062A98 0x02062A98 arm
 *   func_02062A4C 0x02062A4C arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02019D30 0x02019D30 thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 */
#include "../include/Obj03268.h"
#include "../include/Obj13981.h"
#include "../include/Obj22951.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };
struct Obj { u8 pad[0x40f4]; struct Record records[30]; };
struct ArcFile;
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_02020E60(u16, int);
typedef signed int     s32;
struct NitroFileHeader;
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02019D30(u32 a, u32 n);
extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
void func_021D6AB8(u8 *p)
{
    void *h;
    void *h2;
    void *buf;
    void *buf2;
    u8 *out2;
    u8 *out;
    int i,n,species,form,gender;
    u32 value;
    u16 id;
    h = func_020490F4(25, ((struct Obj03268 *)p)->f43C4);
    for (i = 0; i < 20; i++) {
        species = ((struct Obj *)p)->records[i].d;
        if (species) {
            buf = ARC_TOOL_LoadHandleMember(h,func_02020E60(species,2),((struct Obj03268 *)p)->f43C4);
            func_02062A98(buf,(void **)(&out));
            MI_CpuCopy8(((struct Obj22951 *)out)->fC,p+0xbc+i*0x224,32);
            func_020307B0(buf);
            buf2 = ARC_TOOL_LoadHandleMember(h,func_02020E60(species,1),((struct Obj03268 *)p)->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            MI_CpuCopy8(((struct Obj13981 *)out2)->f14,p+0xdc+i*0x224,512);
            func_020307B0(buf2);
        }
    }
    ARC_TOOL_DeleteHandle(h);
    h2 = func_020490F4(7, ((struct Obj03268 *)p)->f43C4);
    for (i = 0; i < 10; i++) {
        n = i+20;
        species = ((struct Obj *)p)->records[n].d;
        if (species) {
            gender = ((struct Obj *)p)->records[n].f;
            form = (int)func_02019D30((u16)species,(u8)(((struct Obj *)p)->records[n].e));
            value = POKE_TOOL_CalcIconPalette(species,form,gender,0);
            id = POKE_TOOL_CalcGraphicIndex(species,form,gender,0);
            buf2 = ARC_TOOL_LoadHandleMember(h2,id,((struct Obj03268 *)p)->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            MI_CpuCopy8(((struct Obj13981 *)out2)->f14,p+0xdc+n*0x224,512);
            func_020307B0(buf2);
            *(u32 *)(p+n*0x224+0x2dc) = value;
        }
    }
    ARC_TOOL_DeleteHandle(h2);
}
