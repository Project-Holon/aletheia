/*
 * function: func_021D4B68
 * address:  0x021D4B68
 * packet:   pkt_ov016_021D4B68
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ARClReadEx (libdwcutil.TWL.HYB.a archive.o)
 *
 * symbols:
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_020788AC  0x020788AC  arm
 *   func_02078C18  0x02078C18  arm
 *   func_02088234  0x02088234  arm
 *   func_02078C28  0x02078C28  arm
 *   func_021D4C9C  0x021D4C9C  arm  ov016
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_02078B70  0x02078B70  arm
 *   func_02078A80  0x02078A80  arm
 *   func_020834C0  0x020834C0  arm
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE66C  0x021DE66C  data
 *   g_021DBFE0  0x021DBFE0  data
 */

#include "../include/G_MemArc.h"

typedef struct { unsigned char b[0x48]; } FSFile;
typedef struct { unsigned char pad[0x84]; void *queue; } MemArc;

extern void *func_021D54C4(void *queue);
extern void func_020788AC(FSFile *file);
extern int func_02078C18(FSFile *file, char *path);
extern void func_02088234(void);
typedef unsigned int   u32;
struct FSFile;
extern u32 func_02078C28(struct FSFile *a0);
extern int func_021D4C9C(char *a, char *b, int n);
extern void *func_021D6414(unsigned long size, int alignment);
typedef signed int     s32;
struct FSFile;
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern int func_02078A80(FSFile *file);
extern void func_020834C0(void *src, void *dst);
extern void func_021D6438(void **mem);
extern struct MemArc *g_021DE66C;
extern char g_021DBFE0[];

void *func_021D4B68(char *path, unsigned long *size, int alignment)
{
    unsigned long siz;
    int align;
    FSFile file;
    void *fle;
    void *buf;

    func_021D54C4(g_021DE66C->queue);
    func_020788AC(&file);
    if (!func_02078C18(&file, path))
        func_02088234();
    siz = func_02078C28((struct FSFile *)(&file));
    if (size)
        *size = siz;
    if (func_021D4C9C(path, g_021DBFE0, 2))
        align = -4;
    else
        align = alignment;
    buf = func_021D6414(siz, align);
    func_02078B70((struct FSFile *)(&file), buf, siz);
    func_02078A80(&file);
    if (align > 0)
        return buf;
    siz = *(unsigned long *)buf >> 8;
    if (size)
        *size = siz;
    fle = func_021D6414(siz, alignment);
    func_020834C0(buf, fle);
    func_021D6438(&buf);
    return fle;
}
