/*
 * function: GAME_DATA_WriteToSave
 * address:  0x02012CE0
 * packet:   pkt_02012C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   func_020087E8  0x020087E8  thumb
 *   func_02008860  0x02008860  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_StoreSaveTable  0x0200EE64  thumb
 *   func_020071CC  0x020071CC  thumb
 *   INTRUDE_StoreOccupy  0x0200BE54  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   MUSICAL_SHOT_GetFromSave  0x0200A864  thumb
 *   MUSICAL_SHOT_CopyPhoto  0x0200A870  thumb
 *   GIMMICK_WORK_Save  0x0200B3B0  thumb
 *   func_0200892C  0x0200892C  thumb
 *   func_0200894C  0x0200894C  thumb
 *   func_0200895C  0x0200895C  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   func_02009D08  0x02009D08  thumb
 *   func_020097F0  0x020097F0  thumb
 *   func_0200E884  0x0200E884  thumb
 *   func_02008748  0x02008748  thumb
 *   func_02008658  0x02008658  thumb
 *   func_0200863C  0x0200863C  thumb
 *
 * 204 bytes, 0x02012CE0..0x02012DAC, EXACT on the first run after the one
 * change that mattered: the u32 at p+0x15C is read once into a NAMED local and
 * handed to both 0x0200892C and 0x0200894C.  Spelled inline at each call site
 * the compiler re-materialises the address per site (`adds r1, r6, #0;
 * adds r1, #0x5c; ldr r0, [r5, r6]`) and loses four bytes; with the local it
 * keeps the value live in r7 across the two calls, exactly as the original
 * does.  The third use (0x0200895C, after two more calls) re-reads it, which
 * is also what the original does.
 *
 * p is a byte pointer: the offsets 0x15C / 0x1B8 / 0x1C4 / 0x1C5 / 0x5EC /
 * 0x694 / 0x6AC are plain byte displacements, and mwcc materialises 0x5EC as
 * a pool word (it is not a single-instruction ARM immediate).
 */
#include "../include/Obj00054.h"


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct PlayTime;
struct Rec2Head;
struct Rec94;
struct SaveBlock;
struct Sub020087E8Arg;
struct Sub02008828Obj;
struct Sub02008860Buf;
struct Sub020097BCObj;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern void func_020087E8(void *sys, const struct Sub020087E8Arg *src);
extern void func_02008860(void *sys, const struct Sub02008860Buf *src);
struct BigObj;
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void FLDMMDL_StoreSaveTable(u32 a0, u8 *a1);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *h, u32 id);
extern void INTRUDE_StoreOccupy(void *sys, const u16 *src);
extern void *GAME_DATA_GetLastBattleRecSlot(void *p);
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern void *MUSICAL_SHOT_GetFromSave(void *sys);
extern void MUSICAL_SHOT_CopyPhoto(struct Rec2Head *dest, const struct Rec2Head *src);
extern void GIMMICK_WORK_Save(struct Rec94 *dest, void *sys);
extern void func_0200892C(struct Sub02008828Obj *obj, const void *src);
extern void func_0200894C(struct Sub02008828Obj *obj, u8 value);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern struct Sub020097BCObj *func_02009D08(void *sys);
extern void func_020097F0(const struct Sub020097BCObj *src, struct Sub020097BCObj *dest);
extern void func_0200895C(struct Sub02008828Obj *obj, u8 value);
extern void func_0200E884(void *sys, void *src);
extern struct PlayTime *func_02008748(void *sys);
extern void func_02008658(struct PlayTime *p);
extern void func_0200863C(struct PlayTime *dest, const struct PlayTime *src);

void GAME_DATA_WriteToSave(u8 *p)
{
    u32 v;
    u32 h;

    v = (u32)GAME_DATA_GetMyPlayerWork((struct SaveBlock *)p);
    func_020087E8((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const struct Sub020087E8Arg *)v);
    func_02008860((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const struct Sub02008860Buf *)v);

    v = GAME_DATA_GetOccupyInfo((const struct BigObj *)p);
    FLDMMDL_StoreSaveTable(v, (u8 *)((u32)func_020071CC((struct Sub020071CCCtrl *)*(u32 *)&((struct Obj00054 *)p)->f0, 0x29)));

    INTRUDE_StoreOccupy((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const u16 *)GAME_DATA_GetLastBattleRecSlot(p));

    v = (u32)GAME_DATA_GetSecondUnionInfo(p);
    MUSICAL_SHOT_CopyPhoto(MUSICAL_SHOT_GetFromSave((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)), (const struct Rec2Head *)v);

    GIMMICK_WORK_Save((struct Rec94 *)(p + 0x5EC), (void *)(*(u32 *)&((struct Obj00054 *)p)->f0));

    h = ((struct Obj00054 *)p)->f15C;
    func_0200892C((struct Sub02008828Obj *)h, (const void *)(*(u32 *)&((struct Obj00054 *)p)->f1B8));
    func_0200894C((struct Sub02008828Obj *)h, ((struct Obj00054 *)p)->f1C4);

    v = GAME_DATA_GetWifiList((const struct BigObj *)p);
    func_020097F0((const struct Sub020097BCObj *)v, func_02009D08((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)));

    func_0200895C((struct Sub02008828Obj *)(((struct Obj00054 *)p)->f15C), ((struct Obj00054 *)p)->f1C5);

    func_0200E884(p + 0x694, (void *)(*(u32 *)&((struct Obj00054 *)p)->f0));

    v = (u32)func_02008748((void *)(*(u32 *)&((struct Obj00054 *)p)->f0));
    func_02008658((struct PlayTime *)(((struct Obj00054 *)p)->f6AC));
    func_0200863C((struct PlayTime *)v, (const struct PlayTime *)(((struct Obj00054 *)p)->f6AC));
}
