/*
 * function: func_021F0EA4
 * address: 0x021F0EA4
 * packet: pkt_ov032_021F0EA4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02025774 0x02025774 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F0ED0 0x021F0ED0 thumb ov032
 */
extern void func_02025774(unsigned char *,unsigned);
extern void func_0204B3DC(void *,unsigned);
extern void func_021F0ED0(char *,int);
void func_021F0EA4(char *p,unsigned a) { func_02025774(*(unsigned char **)(p+0x18),a); func_0204B3DC(*(void **)(p+0x10),a); func_0204B3DC(*(void **)(p+0xc),a); if(a==0) func_021F0ED0(p,a); }
