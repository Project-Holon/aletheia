/*
 * function: func_021FE7B4
 * address: 0x021FE7B4
 * packet: pkt_ov186_021FE7B4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: plain literals 512 and 448; mwcc derives 448 from the held 512 itself. Twin shape: matched ov197 0220C980 call to func_020216D4.
 * symbols:
 *   func_020216D4 0x020216D4 thumb
 */
typedef unsigned int u32;
struct PalAnmSlot;
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void func_021FE7B4(char *p)
{
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 0, 0, 512);
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 2, 0, 448);
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 1, 0, 512);
    func_020216D4(*(struct PalAnmSlot **)(p + 0x20), 3, 0, 448);
}
