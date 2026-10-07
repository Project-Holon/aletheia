/*
 * file:     wih_p11.c
 * unit:     yes
 * function: func_02178E1C, func_02178E28, func_02178E38, func_02178E4C, func_02178E68
 * address:  0x02178E1C
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
 *   g_021797A8  0x021797A8  data  a4
 */
#include "../../matched/include/G_S.h"

typedef unsigned int u32;

typedef struct { void *p; unsigned short h; } S;

typedef unsigned char u8;

typedef unsigned short u16;

void func_02178E1C(u32 v);
void DWCi_MOV_WH_SetUserGameInfo(void *p, unsigned short h);
u16 func_02178E38(void);
int func_02178E4C(void);
int func_02178E68(void);
extern struct S *g_021797A8;


void func_02178E1C(u32 v)
{
    *(u32 *)(*(u32 *)0x021797A8 + 8) = v;
}


void DWCi_MOV_WH_SetUserGameInfo(void *p, unsigned short h)
{
	g_021797A8->p = p;
	g_021797A8->h = h;
}

u16 func_02178E38(void) { return *(u16 *)(((u8 *)g_021797A8) + 0x1EAA); }

int func_02178E4C(void) { if (((u8 *)g_021797A8) == 0) return 0; return *(int *)(((u8 *)g_021797A8) + 0x1E70); }

int func_02178E68(void) { if (((u8 *)g_021797A8) != 0) return *(int *)(((u8 *)g_021797A8) + 0x1E98); return 0; }
