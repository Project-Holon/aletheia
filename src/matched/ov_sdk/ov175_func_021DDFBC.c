/*
 * function: sakeiCreateRecordFillSoapRequest
 * address:  0x021DDFBC
 * packet:   pkt_021DDFBC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsXmlWriteStringElement   0x02182AC0  arm  ov009
 *   sakeiFillSoapRequestFieldValues   0x021DDBE4  arm  ov175
 *   sModifyXmlNamespacePrefix      0x021E3A8C  data
 *   sModifyTagTableid      0x021E3B4C  data
 *
 * Forwarder: registers the two descriptor tables with the ov009 helper
 * using the +8 block's first word and the object's +0x18 cursor, then
 * hands the object and the block's next two words to sakeiFillSoapRequestFieldValues.
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Blk;

struct SAKEField;
struct SAKERequestInternal;
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern void sakeiFillSoapRequestFieldValues(struct SAKERequestInternal *request, struct SAKEField *fields, int numFields);
extern u32 sModifyXmlNamespacePrefix[];
extern u32 sModifyTagTableid[];

u32 sakeiCreateRecordFillSoapRequest(char *obj)
{
    Blk *b = *(Blk **)(obj + 8);

    gsXmlWriteStringElement((void *)(*(u32 *)(obj + 0x18)), (char *)((u32)sModifyXmlNamespacePrefix), (char *)((u32)sModifyTagTableid), (char *)b->f0);
    sakeiFillSoapRequestFieldValues((struct SAKERequestInternal *)((u32)obj), (struct SAKEField *)b->f4, b->f8);
    return 0;
}
