/*
 * function: func_021BAA30
 * address: 0x021BAA30
 * packet: pkt_ov223_021BAA30
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;extern void CLACT_DeleteActor(struct Obj *);extern void CLACT_ReleaseCellAnim(u32),CLACT_ReleaseCharacter(u32),CLACT_ReleasePalette(u32);
void func_021BAA30(char *p) {u32 off;off=0x224;CLACT_DeleteActor(*(struct Obj **)(p+off));CLACT_ReleaseCellAnim(*(u32 *)(p+off-4));CLACT_ReleaseCharacter(*(u32 *)(p+off-12));off-=8;CLACT_ReleasePalette(*(u32 *)(p+off));}
