/*
 * file:     unit_021D4B68.c
 * unit:     yes
 * function: func_021D4B68, func_021D4C68, func_021D4C9C
 * address:  0x021D4B68
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_020788AC  0x020788AC  arm
 *   func_02078C18  0x02078C18  arm
 *   func_02088234  0x02088234  arm
 *   FS_GetLength  0x02078C28  arm
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_02078B70  0x02078B70  arm
 *   func_02078A80  0x02078A80  arm
 *   func_020834C0  0x020834C0  arm
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE66C  0x021DE66C  data
 *   g_021DBFE0  0x021DBFE0  data
 *   func_021D546C  0x021D546C  arm  ov016
 *   func_0209477C  0x0209477C  arm
 *   func_020923F0  0x020923F0  arm
 */
#include "../../matched/include/G_MemArc.h"

struct FSFile;
typedef struct { unsigned char b[0x48]; } FSFile;

typedef struct { unsigned char pad[0x84]; void *queue; } MemArc;

typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned char  u8;

extern void *func_021D54C4(void *queue);
extern void func_020788AC(FSFile *file);
extern int func_02078C18(FSFile *file, char *path);
extern void func_02088234(void);
extern u32 FS_GetLength(struct FSFile *a0);
extern void *func_021D6414(unsigned long size, int alignment);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern int func_02078A80(FSFile *file);
extern void func_020834C0(void *src, void *dst);
extern void func_021D6438(void **mem);
extern void func_021D546C(void *que, void *elem);
extern int func_0209477C(const u8 *s);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
void *func_021D4B68(char *path, unsigned long *size, int alignment);
void func_021D4C68(void *file);
int func_021D4C9C(char *str0, char *str1, int n);
extern struct MemArc *g_021DE66C;
extern char g_021DBFE0[];


/*
 * sdk:      DWCi_ARClReadEx (libdwcutil.TWL.HYB.a archive.o)
 */
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
    siz = FS_GetLength((struct FSFile *)(&file));
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


/*
 * sdk:      DWCi_ARClRelease (libdwcutil.TWL.HYB.a(archive.o))
 */
void func_021D4C68(void *file)
{
	func_021D6438(&file);
	func_021D546C(*(void **)(((char *)g_021DE66C) + 0x84), file);
}


/*
 * sdk:      cmpBack (libdwcutil.TWL.HYB.a(archive.o))
 */
int func_021D4C9C(char *str0, char *str1, int n)
{
	int len0;
	int len1;
	int rs;
	len0 = func_0209477C((const u8 *)str0);
	len1 = func_0209477C((const u8 *)str1);
	if (len0 < n || len1 < n)
		return 0;
	rs = func_020923F0((const u8 *)(str0 + (len0 - n)), (const u8 *)(str1 + (len1 - n)), n);
	return rs == 0;
}
