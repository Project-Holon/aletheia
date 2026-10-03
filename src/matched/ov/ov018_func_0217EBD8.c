/*
 * function: func_0217EBD8
 * address: 0x0217EBD8
 * packet: pkt_ov018_0217EBD8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x0217EC06.
 * interface: func_020127B8 tail-forwards func_020127AC's pointer result.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_020127B8 0x020127B8 thumb
 *   func_020127AC 0x020127AC thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern void *func_020127B8(void *);
extern void *func_020127AC(struct SaveBlock *p, u32 idx);
void *func_0217EBD8(u8 *p)
{
    void *h;
    int i;
    h = func_020120F4(*(void **)p);
    i = p[0xd8];
    if (i == func_02012B58(h) || i == 0x80) {
        return func_020127B8(h);
    } else {
        return func_020127AC(h, i);
    }
}
