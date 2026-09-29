/*
 * function: func_021D52D4
 * address:  0x021D52D4
 * packet:   pkt_ov016_021D52D4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CEINlSet (libdwcutil.TWL.HYB.a(cellinfo.o))
 *
 * symbols:
 *   func_02082A7C  0x02082a7c  arm
 *   func_02082A60  0x02082a60  arm
 *   func_02082A90  0x02082a90  arm
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

extern void func_02082A7C(unsigned long data, void *destp, unsigned long size);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_02082A90(void *srcp, void *destp, unsigned long size);

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
