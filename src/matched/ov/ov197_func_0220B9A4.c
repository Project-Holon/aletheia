/*
 * function: func_0220B9A4
 * address: 0x0220B9A4
 * packet: pkt_ov197_0220B9A4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   sub_02007F68 0x02007F68 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 sub_02007F68(u8 *,u16,u16,u16);
int func_0220B9A4(char *p) { char *q; if(*(u16 *)(p+0x540)==0) return 0; q=*(char **)p; if(sub_02007F68(*(u8 **)q,*(u16 *)(p+0x540),1,*(u16 *)(q+0xc))==0) { *(u16 *)(p+0x540)=0; *(u8 *)(p+0x542)=0; return 0; } return 1; }
