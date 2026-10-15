/*
 * function: MUSICAL_DRESSUP_SYS_Exit
 * address: 0x02156C28
 * packet: pkt_ov010_02156C28
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov133_id 0x00000085 data
 */
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
typedef signed int     s32;
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void func_02034A5C(s32 handle);
extern char ov133_id[];
int MUSICAL_DRESSUP_SYS_Exit(void *a, int b, int c, void **d) { func_020307B0(*d); func_020315D4(a); GFL_HEAP_DeleteChecked(0x2d); func_02034A5C((u32)ov133_id); return 1; }
