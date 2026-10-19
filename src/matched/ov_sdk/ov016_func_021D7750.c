/*
 * function: deleteTcb
 * address:  0x021D7750
 * packet:   pkt_021D7750
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gMemTask 0x021DE6E4 data
 *   DWCi_QUElPushBack  0x021D546C  arm
 *   DWCi_HEAPlFree_  0x021D6438  arm
 *
 * note: the parked header declared g_021E66E4 (0x021E66E4); the ov016 pool
 * word at 0x021D7790 is 0x021DE6E4, so the wildcarded ABS32 hid the wrong
 * address and kept this at MATCH.  Correcting the address makes it EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct StructR4 {
    u8 pad[0xC];
    u32 fieldC;
    u8 pad10;
    u8 field11;
};

extern void DWCi_HEAPlFree_(void **mem);
extern void func_021D6D8C(void *);
extern void DWCi_QUElPushBack(void *, void *);
extern void *gMemTask;

void deleteTcb(u32 idx, struct StructR4 *r4)
{
    if (r4->field11 != 0) {
        DWCi_HEAPlFree_((void **)(&r4->fieldC));
    }
    func_021D6D8C(r4);
    DWCi_QUElPushBack(*(void **)((char *)gMemTask + idx * 64), r4);
}
