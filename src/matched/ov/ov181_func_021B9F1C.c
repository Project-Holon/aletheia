/*
 * function: func_021B9F1C
 * address: 0x021B9F1C
 * packet: pkt_ov181_021B9F1C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: arm9 0x02048C4C has no witness outside 0x021B9F1C..0x021B9F40.
 * Verified scratch blocker.c with one --arm (no --region), fixed flags: EXACT, 12 bytes.
 * extern void func_020307B0(void *);
 * void G3D_LIGHT_DeleteSlots(void *p) { func_020307B0(p); }
 * Blocker symbols: func_020307B0 0x020307B0 arm.
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 */
struct Ctx;struct Rec;
typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_LIGHT_DeleteSlots(void *);
extern void G3D_UTIL_RemoveUnit(struct Ctx *,unsigned);
extern void G3D_UTIL_Delete(struct Rec *);
extern void G3D_SYSTEM_Exit(void);
void func_021B9F1C(char *p){G3D_CAMERA_Delete(*(void **)(p+12));G3D_LIGHT_DeleteSlots(*(void **)(p+16));G3D_UTIL_RemoveUnit(*(struct Ctx **)(p+8),*(unsigned short *)(p+24));G3D_UTIL_Delete(*(struct Rec **)(p+8));G3D_SYSTEM_Exit();}
