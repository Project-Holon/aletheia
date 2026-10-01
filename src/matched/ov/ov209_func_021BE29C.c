/*
 * function: func_021BE29C
 * address: 0x021BE29C
 * packet: pkt_ov209_021BE29C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Enum position preserves the full-width update and repeated signed-halfword argument conversions.
 * symbols:
 *   func_0200CC40 0x0200CC40 thumb
 *   func_021BE25C 0x021BE25C thumb ov209
 *   func_021BE1B8 0x021BE1B8 thumb ov209
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 *   func_021BD890 0x021BD890 thumb ov209
 *   func_021BD934 0x021BD934 thumb ov209
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0200CC40(u8 *,unsigned,unsigned *,unsigned *,unsigned *,u16);
extern int func_021BE25C(int,int);
extern void func_021BE1B8(char *,int,unsigned,u16,u16,int);
extern void func_021BD8D8(char *,int,unsigned);
extern void func_021BD890(char *,int,int);
extern void func_021BD934(char *,int,short,short,u16);
enum Position { POSITION_ZERO=0 };
void func_021BE29C(char *p,u16 species,enum Position pos,int mode)
{
    unsigned out1,outForm,out2;
    int index;
    func_0200CC40(*(u8 **)(*(char **)p+4),species,&out1,&out2,&outForm,0x806b);
    index=func_021BE25C((int)p,mode);
    func_021BE1B8(p,index,species,outForm,out1,mode);
    func_021BD8D8(p,index,1);
    func_021BD890(p,index,0);
    if (mode==1) {
        pos+=8;
        func_021BD934(p,index,112,pos,0);
        return;
    }
    pos+=8;
    func_021BD934(p,index,112,pos,1);
    func_021BD934(p,index+16,112,pos,1);
    index+=16;
    func_021BD8D8(p,index,1);
}
