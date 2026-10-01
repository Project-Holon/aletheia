/*
 * function: func_021BF08C
 * address: 0x021BF08C
 * packet: pkt_ov217_021BF08C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 114 code bytes; show at 021BF0FE proves two zero alignment bytes before next aligned function.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_02049250 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct ArcFile;
extern void *func_020490F4(void *,unsigned);
extern unsigned func_021BF810(char *);
extern void *func_02049250(struct ArcFile *,unsigned,unsigned);
extern int func_02062B30(void *,void **);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,u8,u8);
extern void func_020409B4(unsigned);
extern void func_020307B0(void *);
extern void func_02049238(void *);
void func_021BF08C(char *p)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=func_020490F4((void *)192,*(u16 *)(p+4));
    if (*(unsigned *)(p+0x3d0)!=0) id=8;
    else if (func_021BF810(p)==0) id=6;
    else {
        id=6;
        if (*(unsigned *)(p+0x3c8)!=0) id=7;
    }
    file=func_02049250(arc,id,*(u16 *)(p+4));
    func_02062B30(file,&out);
    func_02041090(2,(unsigned)out+12,0,0,32,32);
    func_020409B4(2);
    func_020307B0(file);
    func_02049238(arc);
}
