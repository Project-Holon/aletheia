/*
 * file:     unit_021D5280_p01.c
 * unit:     yes
 * function: func_021D5280, func_021D52B0
 * address:  0x021D5280
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
 *   func_021D4B68  0x021d4b68  arm  ov016
 *   g_021DE674  0x021de674  data
 *   func_021D4C68  0x021d4c68  arm  ov016
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef _Bool bool;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct tagOAMATTR { u16 attr0; u16 attr1; u16 attr2; } OAMATTR;

typedef struct tagSELLINFO { u16 num; u16 attr; u32 offset; } SELLINFO;

extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_021D4C68(void *file);
void func_021D5280(int lcd, char *file);
void func_021D52B0(int lcd);
extern void *g_021DE674[2];


void func_021D5280(int lcd, char *file)
{
    unsigned long size;

    g_021DE674[lcd] = func_021D4B68(file, &size, 4);
}


/*
 * sdk:      DWCi_CEINlRelease (libdwcutil.TWL.HYB.a(cellinfo.o))
 */
void func_021D52B0(int lcd)
{
    func_021D4C68(g_021DE674[lcd]);
    g_021DE674[lcd] = 0;
}
