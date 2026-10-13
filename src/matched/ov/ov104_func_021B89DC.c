/*
 * function: IRC_RHYTHM_BlendPaletteEntry
 * address: 0x021B89DC
 * packet: pkt_ov104_021B89DC
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Byte RGB endpoints and named signed db/dr/dg deltas, with the
 * cosine factor computed after green extraction, retain channel lifetimes.
 * Evidence: ov105_func_021B8734 blend spelling and own ARM9 queue body.
 * symbols:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern const s16 FX_SinCosTable_[];
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
static inline u16 blend(int angle,u16 c1,u16 c2) {
 u8 g1,r1,b1; int db,dr,dg; s16 factor;
 g1=(c1&0x3e0)>>5;
 factor=(s16)((FX_SinCosTable_[((angle>>4)*2)+1]+0x1000)/2);
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}
s32 IRC_RHYTHM_BlendPaletteEntry(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2) {
 *p=blend(angle,c1,c2);
 return func_02061CA4((void *)a,bank*32+index*2,(u32)p,2);
}
