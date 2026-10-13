/*
 * file:     cellinfo.c
 * unit:     yes
 * function: func_021D5280, func_021D52B0, func_021D52D4, func_021D5368, func_021D5394
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
 *   func_02082A7C  0x02082a7c  arm
 *   func_02082A60  0x02082a60  arm
 *   func_02082A90  0x02082a90  arm
 *   DWCi_OBJlFormGx   0x021D6F18 arm
 *   DWCi_CEINlSet     0x021D52D4 arm
 *   func_021D4E1C  0x021d4e1c  arm  ov016
 *   func_021D4FE0  0x021d4fe0  arm  ov016
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
extern void func_02082A7C(unsigned long data, void *destp, unsigned long size);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_02082A90(void *srcp, void *destp, unsigned long size);
GXOamAttr *DWCi_OBJlFormGx(int lcd);
void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern void *func_021D4E1C(int lcd, int num, int head);
extern char *func_021D4FE0(char *p, unsigned int i);
void func_021D5280(int lcd, char *file);
void func_021D52B0(int lcd);
void func_021D52D4(int lcd, int idx, GXOamAttr *obj);
GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
void *func_021D5394(int lcd, int idx, bool head);
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



void func_021D52D4(int lcd, int idx, GXOamAttr *obj)
{
    SELLINFO *info;
    OAMATTR *attr;
    GXOamAttr oam;
    int num;
    int i;

    info = (SELLINFO *)g_021DE674[lcd];
    num = info[idx].num;
    attr = (OAMATTR *)((u8 *)info + info[idx].offset);
    func_02082A7C(0, &oam, 8);
    for (i = 0; i < num; i++) {
        func_02082A60(attr, &oam, 6);
        func_02082A90(&oam, obj, 8);
        attr++;
        obj++;
    }
}



GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx)
{
    GXOamAttr *obj = DWCi_OBJlFormGx(lcd);

    DWCi_CEINlSet(lcd, idx, obj);
    return obj;
}



/*
 * sdk:      DWCi_CEINlSetExCell (libdwcutil.TWL.HYB.a(cellinfo.o))
 */
void *func_021D5394(int lcd, int idx, bool head)
{
    void *cell;
    GXOamAttr *obj;

    cell = func_021D4E1C(lcd, ((SELLINFO *)g_021DE674[lcd])[idx].num, head);
    obj = (GXOamAttr *)func_021D4FE0(cell, 0);
    func_021D52D4(lcd, idx, obj);
    return cell;
}
