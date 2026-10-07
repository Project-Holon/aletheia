/*
 * file:     unit_021D5280_p02.c
 * unit:     yes
 * function: func_021D5368, func_021D5394
 * address:  0x021D5368
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
 *   DWCi_OBJlFormGx   0x021D6F18 arm
 *   DWCi_CEINlSet     0x021D52D4 arm
 *   func_021D4E1C  0x021d4e1c  arm  ov016
 *   func_021D4FE0  0x021d4fe0  arm  ov016
 *   func_021D52D4  0x021d52d4  arm  ov016
 *   g_021DE674  0x021de674  data
 */
typedef struct GXOamAttr_021D5368 GXOamAttr_021D5368;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef _Bool bool;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr_021D5394;

typedef struct tagOAMATTR { u16 attr0; u16 attr1; u16 attr2; } OAMATTR;

typedef struct tagSELLINFO { u16 num; u16 attr; u32 offset; } SELLINFO;

GXOamAttr_021D5368 *DWCi_OBJlFormGx(int lcd);
void DWCi_CEINlSet(int lcd, int idx, GXOamAttr_021D5368 *obj);
extern void *func_021D4E1C(int lcd, int num, int head);
extern char *func_021D4FE0(char *p, unsigned int i);
extern void func_021D52D4(int lcd, int idx, GXOamAttr_021D5394 *obj);
GXOamAttr_021D5368 *DWCi_CEINlSetExObj(int lcd, int idx);
void *func_021D5394(int lcd, int idx, bool head);
extern void *g_021DE674[2];


GXOamAttr_021D5368 *DWCi_CEINlSetExObj(int lcd, int idx)
{
    GXOamAttr_021D5368 *obj = DWCi_OBJlFormGx(lcd);

    DWCi_CEINlSet(lcd, idx, obj);
    return obj;
}


/*
 * sdk:      DWCi_CEINlSetExCell (libdwcutil.TWL.HYB.a(cellinfo.o))
 */
void *func_021D5394(int lcd, int idx, bool head)
{
    void *cell;
    GXOamAttr_021D5394 *obj;

    cell = func_021D4E1C(lcd, ((SELLINFO *)g_021DE674[lcd])[idx].num, head);
    obj = (GXOamAttr_021D5394 *)func_021D4FE0(cell, 0);
    func_021D52D4(lcd, idx, obj);
    return cell;
}
