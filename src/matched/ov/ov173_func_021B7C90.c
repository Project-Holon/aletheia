/*
 * function: func_021B7C90
 * address: 0x021B7C90
 * packet: pkt_ov173_021B7C90
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (final push G7L6): the row=3 in the old==3 arm is written as the call argument,
 *   func_020260E4(obj, row=3). As a separate statement before the call the colours of p and row swap
 *   (37 B); the argument form keeps the def of row after the p+0x1C8 load, as the original does.
 * symbols:
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_021B71C4 0x021B71C4 thumb ov173
 *   func_021B70D8 0x021B70D8 thumb ov173
 *   func_021B7F64 0x021B7F64 thumb ov173
 *   func_021B7FD0 0x021B7FD0 thumb ov173
 *   func_021B7ADC 0x021B7ADC thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021B7EB0(char *,int);
extern u16 func_021B7438(char **);
extern void func_021B71C4(char *,int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void func_021B70D8(char *);
extern void func_021B7F64(char *);
extern void func_021B7FD0(u8 *,int);
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
typedef unsigned int   u32;
extern void func_021B7ADC(unsigned char *p, u32 idx, int unused);
#define S(p) (*(char **)(p))
void func_021B7C90(char *p,int row,int old)
{
    
    func_021B7EB0(p,0);
    if(row<=3) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        *(u16 *)(S(p)+0x14)=row;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) func_021B71C4(p,func_021B7438((char **)p));
        else func_021B71C4(p,-2);
    } else if(row==6) {
        if(old==3 && *(u16 *)(S(p)+0x16)+4<*(u8 *)(p+0x1B8)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            func_020260E4(*(void **)(p+0x1C8),row=3);
            (*(u16 *)(S(p)+0x16))++;
            func_021B70D8(p);
            func_021B71C4(p,func_021B7438((char **)p));
            func_021B7F64(p);
            func_021B7FD0((u8 *)p,1);
        } else if(old==0) {
            if(*(u16 *)(S(p)+0x16)!=0) {
                GFL_USE_PlaySeDefaultVolume(0x54C);
                (*(u16 *)(S(p)+0x16))--;
                func_021B70D8(p);
                func_021B71C4(p,func_021B7438((char **)p));
                func_021B7F64(p);
                func_021B7FD0((u8 *)p,-1);
            }
            row=0;
            func_020260E4(*(void **)(p+0x1C8),0);
        } else {
            row=3;
            func_020260E4(*(void **)(p+0x1C8),3);
        }
    } else GFL_USE_PlaySeDefaultVolume(0x54C);
    func_021B7ADC((u8 *)p,(u8)row,3);
}
