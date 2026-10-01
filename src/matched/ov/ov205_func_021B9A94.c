/*
 * function: func_021B9A94
 * address: 0x021B9A94
 * packet: pkt_ov205_021B9A94
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012F2C 0x02012F2C thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_02008654 0x02008654 thumb
 *   func_02008D1C 0x02008D1C thumb
 */
extern void *func_02012F2C(void *);
extern void *func_02012FCC(void *);
extern unsigned short func_0200864C(void *);
extern unsigned char func_02008650(void *);
extern unsigned char func_02008654(void *);
extern unsigned func_02008D1C(void *,int,unsigned);
void func_021B9A94(char *p)
{
    void *counter,*date;
    unsigned year,month,day;
    counter=func_02012F2C(*(void **)(p+4));
    date=func_02012FCC(*(void **)(p+4));
    year=func_0200864C(date);
    month=func_02008650(date);
    day=func_02008654(date);
    func_02008D1C(counter,2,day+(year*10000+month*100));
}
