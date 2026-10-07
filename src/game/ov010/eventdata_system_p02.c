/*
 * file:     eventdata_system_p02.c
 * unit:     yes
 * function: func_02161ECC, func_02161EEC
 * address:  0x02161ECC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02161E84 0x02161E84 thumb ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 pad; u16 ids[8]; } T;

extern int func_02161E84(T *);
int func_02161ECC(T *p);
void func_02161EEC(u16 *buf);

int func_02161ECC(T *p)
{
    if (p->lo == 0) return 0;
    if (func_02161E84(p) != 0) return 1;
    return 0;
}


/*
 * Fills ten halfwords with 0xFFFF.  A leaf with no lr-saving prologue,
 * called only from arm9 (func_0200A848), so the listing emits it as data.
 */
void func_02161EEC(u16 *buf)
{
    int i;
    for (i = 0; i < 10; i++)
        buf[i] = 0xffff;
}
