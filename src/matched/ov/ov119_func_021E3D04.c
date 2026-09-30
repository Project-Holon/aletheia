/*
 * function: func_021E3D04
 * address: 0x021E3D04
 * packet: pkt_ov119_021E3D04
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
extern int func_02017DBC(void *);
extern void func_02017DE4(void *, int);
extern int func_02017E88(void *, int, int);
extern void *func_0201ADE4(unsigned short, unsigned short, unsigned int);
extern unsigned int func_0201AE1C(void *, int);
extern void func_0201AE14(void *);
unsigned char func_021E3D04(void *mon, unsigned int heap)
{
    int old;
    unsigned short result;
    int species;
    void *data;
    result = 0;
    old = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    if (func_02017E88(mon, 0xA9, 0)) {
        if (!func_02017E88(mon, 0x4C, 0)) {
            unsigned short form = func_02017E88(mon, 0x6F, 0);
            data = func_0201ADE4(species, form, heap);
            result = func_0201AE1C(data, 0x21);
            func_0201AE14(data);
        } else {
            result = 1;
            if (species != 0x1EA)
                result = 8;
        }
        result++;
    }
    func_02017DE4(mon, old);
    return result;
}
