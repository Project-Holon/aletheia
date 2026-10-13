/*
 * function: func_021E0D90
 * address: 0x021E0D90
 * packet: pkt_ov183_021E0D90
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0E3E alignment padding.
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021E0CE8 0x021E0CE8 thumb ov183
 */
#include "../include/Obj14438.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_021E0CE8(char *, int, int);
void func_021E0D90(char *p)
{
    int i, state;
    for (i = 1; i < 3; i++) {
        state = CLACT_GetActorAnimSeq(*(void **)(p + i * 28 + 0x194));
        if (state == 3) {
            if (!CLACT_IsActorAnimActive(*(void **)(p + i * 28 + 0x194))) {
                CLACT_SetActorAnimSeq(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
                if (((struct Obj14438 *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
                func_021E0CE8(p, 2, 0);
            }
        } else {
            if (state != *(int *)(p + i * 28 + 0x188)) CLACT_SetActorAnimSeq(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
            if (CLACT_GetActorAnimSeq(*(void **)(p + i * 28 + 0x194)) != 3) {
                if (((struct Obj14438 *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
            }
        }
    }
}
