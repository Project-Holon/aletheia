/*
 * function: P_STA_RIBBON_ShowDetail
 * address: 0x021D9568
 * packet: pkt_ov131_021D9568
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D964A follow the 226-byte body.
 * proof: selector is a byte; selector*8+316 <=2356. Position stores
 * initialize every byte of the eight-byte descriptor before passing it.
 * prototype: 0204B294 leaves 0204CFDC's pointer return live at 0204B318;
 * 021D960E stores it. Keep the own body's u32,u32,u32,u32,u32,u16,u16
 * inputs, and expose the observed r0 result despite its legacy void return.
 * symbols:
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040AE0 0x02040AE0 arm
 *   P_STA_RIBBON_GetRibbonInfo 0x021DBF2C thumb ov131
 */
#include "../include/Obj02484.h"
#include "../include/Obj03816.h"
#include "../include/Obj23157.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;
struct Cfg;
struct Descriptor;
struct Obj;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern u32 P_STA_RIBBON_GetRibbonInfo(u32,u32);
void P_STA_RIBBON_ShowDetail(u8 *a,u8 *p)
{
    void *cell;
    void *archive;
    u8 index;
    ObjPos pos;
    index=(p+p[0x59]*8)[0x13c];
    cell=((struct Obj02484 *)p)->f20;
    BMP_WIN_TransferChars(cell);
    BMP_WIN_MakeScreen(cell);
    func_02041B6C(func_02045730(cell));
    cell=((struct Obj02484 *)p)->f24;
    BMP_WIN_TransferChars(cell);
    BMP_WIN_MakeScreen(cell);
    func_02041B6C(func_02045730(cell));
    archive=func_020490F4(78,((struct Obj03816 *)a)->f0);
    ((struct Obj02484 *)p)->f18=CLACT_RegisterCharacter((void *)((u32)archive),P_STA_RIBBON_GetRibbonInfo(index,1),0,1,((struct Obj03816 *)a)->f0);
    ARC_TOOL_DeleteHandle(archive);
    pos.x=128;
    pos.y=100;
    pos.priority=10;
    pos.flags=0;
    pos.z=0;
    *(u32 *)&((struct Obj02484 *)p)->f1C=(u32)CLACT_CreateActor((void *)((struct Obj03816 *)a)->f174,((struct Obj02484 *)p)->f18,((struct Obj03816 *)a)->fB4,((struct Obj03816 *)a)->f128,&pos,1,((struct Obj03816 *)a)->f0);
    func_0204B6F4(((struct Obj02484 *)p)->f1C,(u8)P_STA_RIBBON_GetRibbonInfo(index,2),1);
    func_0204B3DC(((struct Obj02484 *)p)->f1C,1);
    func_02040AE0(6,*(u8 * *)&((struct Obj02484 *)p)->f38+12,((struct Obj23157 *)(*(u8 * *)&((struct Obj02484 *)p)->f38))->f8);
    func_02041B6C(6);
    ((struct Obj02484 *)p)->f4=1;
}
