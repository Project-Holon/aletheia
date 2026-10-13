/*
 * function: ITEMMENU_SetMoveTypeIconsVisible
 * address:  0x021B97E8
 * packet:   pkt_ov070_021B97E8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocked: WAZA_TOOL_GetDamageType (arm9 unlabelled leaf, the integrator's; 12 bytes, tail stub)
 * has no witness outside this function. Verified C for the leaf (EXACT,
 * thumb, arm9, no region):
 *   extern int func_0201BD28(int, int);   // symbols: func_0201BD28 0x0201BD28 thumb
 *   int WAZA_TOOL_GetDamageType(int a) { return func_0201BD28(a, 2); }
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_GetSlot  0x021B616C  thumb  ov070
 *   func_020212B0  0x020212B0  thumb
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int ITEMMENU_GetCursorIndex(u8 *p);
extern unsigned short *ITEMMENU_GetSlot(char *, int);
extern u16 func_020212B0(u16 id);
extern int WAZA_TOOL_GetDamageType(int);
extern u8 WAZA_TOOL_GetType(void *p);

void ITEMMENU_SetMoveTypeIconsVisible(char *p, int mode)
{
    int r;
    if (mode == 1) {
        *(int *)(p + 0x840) = 1;
    } else {
        *(int *)(p + 0x840) = 2;
    }
    if (*(int *)(p + 0x6A0) != 0) {
        func_0204B3DC((struct Obj *)(*(int *)(p + 0x6A0)), mode);
    }
    r = func_020212B0(*ITEMMENU_GetSlot(p, ITEMMENU_GetCursorIndex((u8 *)p)));
    if (r != 0) {
        func_0204B3DC((struct Obj *)(*(int *)(p + WAZA_TOOL_GetDamageType(r) * 4 + 0x6C0)), mode);
        func_0204B3DC((struct Obj *)(*(int *)(p + WAZA_TOOL_GetType((void *)r) * 4 + 0x6CC)), mode);
    }
}
