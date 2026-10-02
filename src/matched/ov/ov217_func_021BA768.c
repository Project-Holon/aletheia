/*
 * function: func_021BA768
 * address: 0x021BA768
 * packet: pkt_ov217_021BA768
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
struct ArcFile;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02049250(struct ArcFile *,unsigned,unsigned);
extern int func_02062B30(void *,void **);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char);
extern void func_020409B4(unsigned);
extern void func_020307B0(void *);
extern void func_02049238(void *);
void func_021BA768(char *p)
{
    struct ArcFile *arc=func_020490F4((void *)192,*(u16 *)(p+4));
    void *file=func_02049250(arc,13,*(u16 *)(p+4));
    void *data;
    func_02062B30(file,&data);
    func_02041090(6,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(6);func_020307B0(file);func_02049238(arc);
}
