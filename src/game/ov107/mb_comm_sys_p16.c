/*
 * file:     mb_comm_sys_p16.c
 * unit:     yes
 * function: func_021F11CC, func_021F11E0
 * address:  0x021F11CC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020173E8  0x020173E8  thumb
 */
#include "../../matched/include/Obj22298.h"
#include "../../matched/include/Obj22299.h"

typedef struct {
    unsigned char pad00[0x10];
    unsigned char *f10;
} Ov107Ctx;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Bits { unsigned char pad[24]; u16 unused:2; u16 flag:1; u16 rest:13; };

u32 func_020173E8(void);
void *func_021F11CC(Ov107Ctx *p, int i);
int func_021F11E0(unsigned char *a);
int func_021F11E8(struct Bits *a);


void *func_021F11CC(Ov107Ctx *p, int i)
{
    return p->f10 + i * func_020173E8() + 4;
}

int func_021F11E0(unsigned char *a) { return ((struct Obj22299 *)(*(unsigned char * *)&((struct Obj22298 *)a)->f10))->f2; }

int func_021F11E8(struct Bits *a) { return a->flag; }
