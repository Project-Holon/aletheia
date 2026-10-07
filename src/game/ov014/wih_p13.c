/*
 * file:     wih_p13.c
 * unit:     yes
 * function: func_02179010, func_02179024, func_02179050
 * address:  0x02179010
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WM_MeasureChannel            0x02090E50  arm
 *   g_021797A8 0x021797A8 data a4
 *   func_02178138 0x02178138 thumb ov014
 */
#include "../../matched/include/G_S.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern void WM_MeasureChannel(void);
extern void func_02178138(int);
asm void WHi_MeasureChannel(void);
u16 func_02179024(void);
int func_02179050(u16 mask);
extern struct S *g_021797A8;


asm void WHi_MeasureChannel(void)
{
	PUSH {R3, LR}
	ADD R3, R1, #0
	MOV R1, #0x1E
	STR R1, [SP, #0]
	MOV R1, #3
	MOV R2, #0x11
	BL WM_MeasureChannel
	POP {R3, PC}
}

u16 func_02179024(void) {
 func_02178138(1);
 *(u16 *)(((u8 *)g_021797A8) + 0x1EAC) = func_02179050(*(u16 *)(((u8 *)g_021797A8) + 0x1EB0));
 return *(u16 *)(((u8 *)g_021797A8) + 0x1EAC);
}


int func_02179050(u16 mask)
{
    s16 last = 0;
    s16 i;
    u16 cnt = 0;
    u32 k;

    for (i = 0; i < 16; i++) {
        if (mask & (1 << i)) {
            last = i + 1;
            cnt++;
        }
    }
    if (cnt > 1) {
        s16 j;

        *(u32 *)(((u8 *)g_021797A8) + 0x1E9C) = *(u32 *)(((u8 *)g_021797A8) + 0x1E9C) * 0x10DCD + 0x3039;
        k = (u32)(cnt * (u8) * (u32 *)(((u8 *)g_021797A8) + 0x1E9C)) << 8 >> 16;
        for (j = 0; j < 16; j++) {
            if (mask & 1) {
                if (k == 0)
                    return (s16)(j + 1);
                k = (u16)(k - 1);
            }
            mask = mask >> 1;
        }
        return 0;
    }
    return last;
}
