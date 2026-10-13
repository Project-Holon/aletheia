/*
 * function: DWCi_CEINlSetExCell
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
 *   DWCi_CELLlForm  0x021d4e1c  arm  ov016
 *   DWCi_CELLlGetObj  0x021d4fe0  arm  ov016
 *   DWCi_CEINlSet  0x021d52d4  arm  ov016
 *   gCellinfoWork  0x021de674  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef _Bool bool;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;
typedef struct tagOAMATTR { u16 attr0; u16 attr1; u16 attr2; } OAMATTR;
typedef struct tagSELLINFO { u16 num; u16 attr; u32 offset; } SELLINFO;

extern void *gCellinfoWork[2];

extern void *DWCi_CELLlForm(int lcd, int num, int head);
extern char *DWCi_CELLlGetObj(char *p, unsigned int i);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);

void *DWCi_CEINlSetExCell(int lcd, int idx, bool head)
{
    void *cell;
    GXOamAttr *obj;

    cell = DWCi_CELLlForm(lcd, ((SELLINFO *)gCellinfoWork[lcd])[idx].num, head);
    obj = (GXOamAttr *)DWCi_CELLlGetObj(cell, 0);
    DWCi_CEINlSet(lcd, idx, obj);
    return cell;
}
