/*
 * function: func_021BBCF0
 * address: 0x021BBCF0
 * packet: pkt_ov223_021BBCF0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204363C 0x0204363C arm
 *   func_02040EBC 0x02040EBC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021B99A0 0x021B99A0 thumb ov223
 *   func_021B9D9C 0x021B9D9C thumb ov223
 *   func_021BA984 0x021BA984 thumb ov223
 *   func_021BAC70 0x021BAC70 thumb ov223
 *   func_021BAD80 0x021BAD80 thumb ov223
 *   func_021BB944 0x021BB944 thumb ov223
 */
typedef enum { BIT8=8, BIT32=32 } Bits;
extern void func_0204363C(int);
extern void func_02040EBC(int,unsigned short);
extern void func_0207D63C(unsigned,int,int,int,int);
extern void func_021B99A0(char *),func_021B9D9C(char *),func_021BA984(char *),func_021BAC70(char *),func_021BAD80(char *);
extern void func_021BB944(char *);
static inline void setbit(char *p,Bits b) { *(unsigned *)(p+36)|=b; }
int func_021BBCF0(char *p)
{
    func_0204363C(0);
    func_02040EBC(0,0x2f3b); func_02040EBC(4,0x2f3b);
    func_021B99A0(p); func_021B9D9C(p); func_021BA984(p); func_021BAC70(p); func_021BAD80(p); func_021BB944(p);
    setbit(p,BIT8); setbit(p,BIT32);
    func_0207D63C(0x04000050,5,63,8,8); func_0207D63C(0x04001050,4,63,8,8);
    *(unsigned *)(p+16)=0;
    return 8;
}
