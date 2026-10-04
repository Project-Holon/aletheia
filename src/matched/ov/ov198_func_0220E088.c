/*
 * function: func_0220E088
 * address: 0x0220E088
 * packet: pkt_ov198_0220E088
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02211AF9 0x02211AF9 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_0220BEB8 0x0220BEB8 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220C4DC 0x0220C4DC thumb ov198
 *   func_0220D6DC 0x0220D6DC thumb ov198
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0220C60C 0x0220C60C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211AF9[];
extern const int d_02211B3C[];
extern void func_0220BDA0(char *);
extern void func_0220BEB8(char *,int,int,u8,u8);
extern int func_022110D4(u8 *,int);
extern void func_0220C4DC(char *,int,int,int,u16,short,unsigned);
extern void func_0220D6DC(char *,char *,int);
typedef unsigned int   u32;
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern void func_0220C60C(char *p, int id);
void func_0220E088(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 **)(p + 0x253c) = d_02211AF9;
    func_0220BDA0((char *)p);
    func_0220BEB8((char *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + func_022110D4((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            func_0220C4DC((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC((char *)p,rec+offset,i+1);
        }
    }
    if (func_02020FE4((void *)(*(u16 *)(*(char **)p+36)),40,*(u16 *)(*(char **)p+16)) == 0)
        func_0220C60C((char *)p,104);
}
