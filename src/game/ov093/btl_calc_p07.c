/*
 * file:     btl_calc_p07.c
 * unit:     yes
 * function: func_021D7494, func_021D74BC, func_021D74C8
 * address:  0x021D7494
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021F3CB0 0x021F3CB0 data a4
 *   func_02082BCC  0x02082BCC  arm
 *   g_021F3ECC 0x021F3ECC data a4
 */
#include "../../matched/include/G_Tbl.h"

typedef struct { unsigned int serial; void *head; unsigned int used; void *pool[0x84]; } List;

typedef struct { unsigned int count; unsigned short keys[0x60]; } Tbl;

void func_02082BCC(int, int, int);
void func_021D7494(void *p);
void func_021D74BC(int a);
void func_021D74C8(void);
extern List data_021F3CB0;
extern struct Tbl g_021F3ECC;

void func_021D7494(void *p) { if (data_021F3CB0.used) { func_021D74BC((int)p); data_021F3CB0.pool[--data_021F3CB0.used] = p; } }


void func_021D74BC(int a)
{
    func_02082BCC(a, 0, 0x3c);
}

void func_021D74C8(void) { Tbl *p = ((Tbl *)&g_021F3ECC); unsigned int i; p->count = 0; for (i = 0; i < 0x60; i++) p->keys[i] = 0; }
