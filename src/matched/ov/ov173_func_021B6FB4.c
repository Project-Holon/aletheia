/*
 * function: POKE_SUMMARY_MAIN_CountMoves
 * address: 0x021B6FB4
 * packet: pkt_ov173_021B6FB4
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Inline owner/table struct access restores the bound/index register allocation;
 * an extracted table pointer compiled 36 bytes with 18 concrete differences.
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ScanOwner { u8 pad[16]; u16 *table; };
struct ScanContext { struct ScanOwner *owner; };
u32 POKE_SUMMARY_MAIN_CountMoves(struct ScanContext *p) { u32 i;for(i=0;i<256;i++)if(p->owner->table[i]==0xffff)break;return i; }
