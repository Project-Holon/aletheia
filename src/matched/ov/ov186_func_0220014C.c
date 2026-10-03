/*
 * function: func_0220014C
 * address: 0x0220014C
 * packet: pkt_ov186_0220014C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: unsigned table indices preserve load scheduling; raw address casts differ by 12 bytes.
 * symbols:
 *   func_0200D064 0x0200D064 thumb
 *   d_02200C94 0x02200C94 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_02200C94[];
extern u32 func_0200D064(void *,u16);
int func_0220014C(void *p,u32 n,const u16 *ids) { u32 i; u32 end; int found; end=d_02200C94[n+1];found=0;for(i=d_02200C94[n];i<end;i++) { if(func_0200D064(p,*(const u16 *)((u32)ids+i*2)))found=1; }return found; }
