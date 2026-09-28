/*
 * function: DWCi_CEINlSetExObj
 * address:  0x021D5368
 * packet:   pkt_ov016_021D5368
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CEINlSetExObj (cellinfo.o), callee of DWCi_ANIMElInitEx (L5, deferred)
 *
 * symbols:
 *   DWCi_OBJlFormGx   0x021D6F18 arm
 *   DWCi_CEINlSet     0x021D52D4 arm
 */

typedef struct GXOamAttr GXOamAttr;

GXOamAttr *DWCi_OBJlFormGx(int lcd);
void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);

GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx)
{
    GXOamAttr *obj = DWCi_OBJlFormGx(lcd);

    DWCi_CEINlSet(lcd, idx, obj);
    return obj;
}
