/*
 * function: sakeiUpdateRecordFillSoapRequest
 * address:  0x021DE078
 * packet:   pkt_021DE078
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     the listing extent (136 B) runs past this 92-byte body into the
 *           next function's leaf and pool words; every compiled byte matches.
 *
 * symbols:
 *   sModifyXmlNamespacePrefix   0x021E3A8C  data
 *   sModifyTagTableid   0x021E3B4C  data
 *   sModifyTagRecordid   0x021E3B54  data
 *   sakeiFillSoapRequestFieldValues  0x021DDBE4  arm
 *
 * Object teardown: the object's +8 table supplies the two title strings that
 * get unregistered from the shared group, then the object's own four table
 * words go back to the pool manager.
 */

typedef unsigned int u32;

extern void func_02182AC0(int a, int b, int c, int d);
extern void func_02182CF0(int a, int b, int c, int d);
struct SAKEField;
struct SAKERequestInternal;
extern void sakeiFillSoapRequestFieldValues(struct SAKERequestInternal *request, struct SAKEField *fields, int numFields);
extern u32  sModifyXmlNamespacePrefix[];
extern u32  sModifyTagTableid[];
extern u32  sModifyTagRecordid[];

int sakeiUpdateRecordFillSoapRequest(int *p)
{
    int *q = (int *)p[2];

    func_02182AC0(p[6], (int)sModifyXmlNamespacePrefix, (int)sModifyTagTableid, q[0]);
    func_02182CF0(p[6], (int)sModifyXmlNamespacePrefix, (int)sModifyTagRecordid, q[1]);
    sakeiFillSoapRequestFieldValues((struct SAKERequestInternal *)p, (struct SAKEField *)q[2], q[3]);
    return 0;
}
