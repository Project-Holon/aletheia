/*
 * function: func_021BAAB8
 * address: 0x021BAAB8
 * packet: pkt_ov223_021BAAB8
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   file 0x021BCB00 data
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040E78 0x02040E78 arm
 *   func_02043678 0x02043678 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_020437D4 0x020437D4 arm
 *   func_020437EC 0x020437EC arm
 *   func_02040B1C 0x02040B1C arm
 *   func_020437AC 0x020437AC arm
 */
typedef unsigned short u16;
extern const char file[];
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned);
extern void func_020307B0(void *);
extern void func_02040E78(unsigned,void *,unsigned,unsigned);
extern void *func_02043678(unsigned,unsigned,unsigned,unsigned);
extern void func_02043AF4(void *,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void *func_020437D4(const void *);
extern unsigned func_020437EC(const void *);
extern void func_02040B1C(unsigned char,const void *,unsigned,unsigned);
extern void func_020437AC(void *);
void func_021BAAB8(u16 *p)
{
    u16 *buffer;
    void *bmp,*data;
    unsigned size;
    buffer=func_02030734(*p,32,1,file,0x92B);
    buffer[0]=0;buffer[1]=0;buffer[2]=0x7FFF;
    func_02040E78(2,buffer,32,0x1A0);
    func_02040E78(6,buffer,32,0);
    func_020307B0(buffer);
    bmp=func_02043678(2,1,32,*p);
    func_02043AF4(bmp,0,0,8,8,0);
    func_02043AF4(bmp,8,0,8,8,1);
    data=func_020437D4(bmp);size=func_020437EC(bmp);
    func_02040B1C(2,data,size,0);
    data=func_020437D4(bmp);size=func_020437EC(bmp);
    func_02040B1C(6,data,size,0);
    func_020437AC(bmp);
}
