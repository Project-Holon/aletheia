/*
 * function: MYSTERY_ALBUM_DeleteSlotWork
 * address: 0x021DD1FC
 * packet: pkt_ov121_021DD1FC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   MYSTERY_UTIL_DeleteWindowList 0x021DA280 thumb ov121
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char  u8;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void MYSTERY_UTIL_DeleteWindowList(u8 *p);
extern u32 func_020307B0(void *p);
void MYSTERY_ALBUM_DeleteSlotWork(void **p)
{
    CLACT_DeleteActor(p[8]);
    CLACT_ReleaseCharacter((u32)p[5]);
    CLACT_ReleaseCellAnim((u32)p[6]);
    CLACT_ReleasePalette((u32)p[4]);
    CLACT_DeleteActor(p[7]);
    CLACT_ReleaseCharacter((u32)p[2]);
    CLACT_ReleaseCellAnim((u32)p[3]);
    CLACT_ReleasePalette((u32)p[1]);
    MYSTERY_UTIL_DeleteWindowList(p[0]);
    func_020307B0(p);
}
