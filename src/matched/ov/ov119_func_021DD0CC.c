/*
 * function: func_021DD0CC
 * address: 0x021DD0CC
 * packet: pkt_ov119_021DD0CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E88 0x02017E88 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_02019D84 0x02019D84 thumb
 *   d_021E7718 0x021E7718 data ov119 a4
 */
typedef unsigned int   u32;
struct Sav;
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern int func_02019D84(unsigned short);
extern const int d_021E7718[];
int func_021DD0CC(char *p, int a)
{
    int v, lock, r;
    unsigned i;
    v = func_02017E88((void *)a,5,0);
    i = 0;
    if (*(int *)(p + 0x118c) == 3) {
        lock = func_02017DBC((struct Sav *)a);
        for (; i < 15; i++) {
            r = func_02017E88((void *)a,d_021E7718[i],0);
            if (r == 1) break;
        }
        func_02017DE4((struct Sav *)a,lock);
        if (r) return 1;
        if (func_02019D84(v)) return 1;
    }
    return 0;
}
