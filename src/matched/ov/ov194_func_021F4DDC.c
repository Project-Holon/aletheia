/*
 * function: NAMEIN_GRAPHIC_CopyTableEntries
 * address: 0x021F4DDC
 * packet: pkt_ov194_021F4DDC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WORDSET_CopyString 0x0201F41C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORDSET_CopyString(const u16 *,u16 *,u32);
void NAMEIN_GRAPHIC_CopyTableEntries(const char *p,int i,u16 *dst,u32 n,u8 *count) {WORDSET_CopyString((const u16 *)(p+2+i*24),dst,n);if(count){*count=0;while(*count<3 && dst[*count]!=0x3000) ++*count;}}
