/*
 * file:     btl_server_p101.c
 * unit:     yes
 * function: func_021C9448, func_021C947C
 * address:  0x021C9448
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D5EFC 0x021D5EFC thumb ov093
 *   func_021D5F08  0x021D5F08  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { int pad0; int pad1; char *f8; void *fc; } P;

typedef struct { u32 w; u8 n; u8 ids[1]; } Ent;

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D5EFC(char *);
extern void func_021D5F08(char *p);
int func_021C9448(u8 *p, u8 *e);
int func_021C947C(P *p, const Ent *e);

/*
 * extent: compiled 50 bytes; 021C947A..021C947C is alignment padding.
 * note: caller consumes live r0 after void-declared func_021D5EFC;
 *       return interface follows its explicit u8 truncation at 021C9470.
 */
int func_021C9448(u8 *p, u8 *e)
{
    char *a;
    a = (char *)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e[4]);
    if (func_021D5B68(a) == 0) {
        func_021CD4B0(((struct Obj00003 *)p)->fC, 12, e[4]);
        return (u8)func_021D5EFC(a);
    }
    return 0;
}


int func_021C947C(P *p, const Ent *e)
{
    int r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        a = func_021B9934(p->f8, e->ids[i]);
        if (func_021D5B68(a) == 0) {
            func_021CD4B0(p->fc, 0xd, e->ids[i]);
            func_021D5F08((char *)a);
            r = 1;
        }
    }
    return r;
}
