/*
 * file:     btl_server_p85.c
 * unit:     yes
 * function: func_021C7CF4, func_021C7D00
 * address:  0x021C7CF4
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
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C7D24 0x021C7D24 thumb ov093
 *   func_021B86A0 0x021B86A0 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

u8 *func_021B9934(char *p, int i);
extern int func_021C7D24(u8 *);
extern int func_021B86A0(unsigned int **, unsigned int);
void *func_021C7CF4(int *p, int i);
int func_021C7D00(u8 *p, int b);


/*
 * Forwarding tail call: p[2] and the caller's i go to func_021B9934, whose
 * listing reads both (lsls r1, r1, #2), and its result is returned.
 */
void *func_021C7CF4(int *p, int i)
{
    return func_021B9934((char *)p[2], i);
}

int func_021C7D00(u8 *p, int b) { int i = func_021C7D24(p + 0x1ab8); if (!func_021B86A0(*(unsigned int ** *)&((struct Obj00003 *)p)->f4, i)) i = 6; return i; }
