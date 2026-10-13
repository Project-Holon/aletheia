/*
 * function: func_021D761C
 * address: 0x021D761C
 * packet: pkt_ov120_021D761C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D770E.
 * lever: indexed pointer sum before the far field offset preserves the base.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_021D6ED8 0x021D6ED8 thumb ov120
 *   func_021D6C64 0x021D6C64 thumb ov120
 *   func_021D7484 0x021D7484 thumb ov120
 *   func_021D6FB4 0x021D6FB4 thumb ov120
 *   func_021D6B5C 0x021D6B5C thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021D698C 0x021D698C thumb ov120
 *   func_021D692C 0x021D692C thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_021D6ED8(u8 *);
extern void func_021D6C64(u8 *);
extern void func_021D7484(char *p);
extern void func_021D6FB4(u8 *);
extern void func_021D6B5C(u8 *);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_021D698C(u8 *);
extern void func_021D692C(u8 *,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041B6C(u32);
void func_021D761C(u8 *p)
{
    int i;
    void *t;
    for(i=0;i<6;i++) {
        if(*(void **)(p+i*4+0x14c)) {
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x14c),0);
            CLACT_DeleteActor(*(void **)(p+i*4+0x14c));
            *(u32 *)(p+i*4+0x14c)=0;
        }
    }
    func_021D6ED8(p);
    func_021D6C64(p);
    func_021D7484((char *)p);
    func_021D6FB4(p);
    func_021D6B5C(p);
    t=func_020490F4((u32)((void *)144),((struct Obj00199 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,12,0,0,(u16)(((struct Obj00199 *)p)->f4),0,0,((struct Obj00199 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,18,4,0,(u16)(((struct Obj00199 *)p)->f0),0,0,((struct Obj00199 *)p)->fF4);
    ARC_UTIL_UploadPaletteFromHandle(t,2,5,0,0x100,0x100,((struct Obj00199 *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    func_021D698C(p);
    func_021D692C(p,0);
    func_02040588(2,0);
    func_02041B6C(0);
    func_02040588(3,0);
    ((struct Obj00199 *)p)->f110=0;
    ((struct Obj00199 *)p)->f114=0;
}
