/*
 * function: func_021D5394
 * address:  0x021D5394
 * packet:   pkt_ov016_021D5394
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CEINlSetExCell (libdwcutil.TWL.HYB.a(cellinfo.o))
 *
 * symbols:
 *   func_021D4E1C  0x021d4e1c  arm  ov016
 *   func_021D4FE0  0x021d4fe0  arm  ov016
 *   func_021D52D4  0x021d52d4  arm  ov016
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

extern void *func_021D4E1C(int lcd, int num, bool head);
extern GXOamAttr *func_021D4FE0(void *cell, int idx);
extern void func_021D52D4(int lcd, int idx, GXOamAttr *obj);

void *func_021D5394(int lcd, int idx, bool head)
{
    void *cell;
    GXOamAttr *obj;

    cell = func_021D4E1C(lcd, ((SELLINFO *)g_021DE674[lcd])[idx].num, head);
    obj = func_021D4FE0(cell, 0);
    func_021D52D4(lcd, idx, obj);
    return cell;
}
