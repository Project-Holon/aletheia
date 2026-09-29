/*
 * function: func_021D5280
 * address:  0x021D5280
 * packet:   pkt_ov016_021D5280
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CEINlRead (libdwcutil.TWL.HYB.a(cellinfo.o))
 *
 * symbols:
 *   func_021D4B68  0x021d4b68  arm  ov016
 *   g_021DE674  0x021de674  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef _Bool bool;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;
typedef struct tagOAMATTR { u16 attr0; u16 attr1; u16 attr2; } OAMATTR;
typedef struct tagSELLINFO { u16 num; u16 attr; u32 offset; } SELLINFO;

extern void *g_021DE674[2];

extern void *func_021D4B68(char *path, unsigned long *size, int alignment);

void func_021D5280(int lcd, char *file)
{
    unsigned long size;

    g_021DE674[lcd] = func_021D4B68(file, &size, 4);
}
