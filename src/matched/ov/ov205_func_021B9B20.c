/*
 * function: func_021B9B20
 * address: 0x021B9B20
 * packet: pkt_ov205_021B9B20
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02088864 0x02088864 arm
 *   func_02012934 0x02012934 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200725C 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_020071F0 0x020071F0 thumb
 *   func_0200EBD0 0x0200EBD0 thumb
 *   func_02012E4C 0x02012E4C thumb
 */
typedef unsigned char u8;
extern void func_02088864(void *);
extern void *func_02012934(void *p);
extern void *func_02012EBC(void *);
extern unsigned func_0200725C(void *,unsigned,u8);
extern void *func_020073D8(void *,unsigned,unsigned);
extern int func_020071F0(void *);
extern void func_0200EBD0(void *,void *,void *,unsigned);
extern void func_02012E4C(void *,void *);
void func_021B9B20(char *p)
{
    unsigned date[4];
    void *save,*object,*record;
    func_02088864(date);
    object=func_02012934(*(void **)(p+4));
    save=func_02012EBC(*(void **)(p+4));
    func_0200725C(save,8,4);
    record=func_020073D8(save,8,0);
    if(func_020071F0(save)==0) {
        func_0200EBD0(record,object,date,4);
        func_02012E4C(*(void **)(p+4),(void *)8);
        *(int *)(p+56)=1;
    }
}
