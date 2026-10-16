/*
 * file:     cellinfo.c
 * unit:     yes
 * function: DWCi_CEINlRead, DWCi_CEINlRelease, DWCi_CEINlSet, DWCi_CEINlSetExObj, DWCi_CEINlSetExCell
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
 *   DWCi_ARClReadEx  0x021d4b68  arm  ov016
 *   gCellinfoWork  0x021de674  data
 *   DWCi_ARClRelease  0x021d4c68  arm  ov016
 *   MIi_CpuClear32  0x02082a7c  arm
 *   MIi_CpuCopy16  0x02082a60  arm
 *   MIi_CpuCopy32  0x02082a90  arm
 *   DWCi_OBJlFormGx   0x021D6F18 arm
 *   DWCi_CEINlSet     0x021D52D4 arm
 *   DWCi_CELLlForm  0x021d4e1c  arm  ov016
 *   DWCi_CELLlGetObj  0x021d4fe0  arm  ov016
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef _Bool bool;

#include "gx_oam_types.h"

typedef struct tagOAMATTR { u16 attr0; u16 attr1; u16 attr2; } OAMATTR;

typedef struct tagSELLINFO { u16 num; u16 attr; u32 offset; } SELLINFO;

extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void DWCi_ARClRelease(void *file);
extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
GXOamAttr *DWCi_OBJlFormGx(int lcd);
void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern void *DWCi_CELLlForm(int lcd, int num, int head);
extern char *DWCi_CELLlGetObj(char *p, unsigned int i);
void DWCi_CEINlRead(int lcd, char *file);
void DWCi_CEINlRelease(int lcd);
GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
extern void *gCellinfoWork[2];


void DWCi_CEINlRead(int lcd, char *file)
{
    unsigned long size;

    gCellinfoWork[lcd] = DWCi_ARClReadEx(file, &size, 4);
}


/*
 * sdk:      DWCi_CEINlRelease (libdwcutil.TWL.HYB.a(cellinfo.o))
 */
void DWCi_CEINlRelease(int lcd)
{
    DWCi_ARClRelease(gCellinfoWork[lcd]);
    gCellinfoWork[lcd] = 0;
}


void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj)
{
    SELLINFO *info;
    OAMATTR *attr;
    GXOamAttr oam;
    int num;
    int i;

    info = (SELLINFO *)gCellinfoWork[lcd];
    num = info[idx].num;
    attr = (OAMATTR *)((u8 *)info + info[idx].offset);
    MIi_CpuClear32(0, &oam, 8);
    for (i = 0; i < num; i++) {
        MIi_CpuCopy16(attr, &oam, 6);
        MIi_CpuCopy32(&oam, obj, 8);
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
void *DWCi_CEINlSetExCell(int lcd, int idx, bool head)
{
    void *cell;
    GXOamAttr *obj;

    cell = DWCi_CELLlForm(lcd, ((SELLINFO *)gCellinfoWork[lcd])[idx].num, head);
    obj = (GXOamAttr *)DWCi_CELLlGetObj(cell, 0);
    DWCi_CEINlSet(lcd, idx, obj);
    return cell;
}
