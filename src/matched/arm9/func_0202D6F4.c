/*
 * unit:     no
 * function: func_0202D6F4
 * address:  0x0202D6F4
 * packet:   pkt_0202D6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unpacks a party mon into the nine-argument sprite request of
 * func_0202D760: species (5), form (0x6F), gender (0x6E), the shiny
 * predicate func_02017EB4, isEgg (0x4C) and the personality word (id 0)
 * are read in that order, then forwarded along with the caller's own
 * a2/a3 pass-throughs.
 *
 * symbols:
 *   func_02017E88   0x02017E88  thumb
 *   func_02017EB4   0x02017EB4  thumb
 *   func_0202D760   0x0202D760  thumb
 */

typedef unsigned int u32;

extern u32 func_02017E88(void *mon, u32 id, u32 v);
extern u32 func_02017EB4(void *mon);
extern u32 func_0202D760(void *a0, u32 species, u32 form, u32 gender,
                         u32 shiny, u32 a2, u32 isEgg, u32 pid, u32 a3);

u32 func_0202D6F4(void *a0, void *mon, u32 a2, u32 a3)
{
    u32 species;
    u32 form;
    u32 gender;
    u32 shiny;
    u32 isEgg;

    species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6F, 0);
    gender = func_02017E88(mon, 0x6E, 0);
    shiny = func_02017EB4(mon);
    isEgg = func_02017E88(mon, 0x4C, 0);
    return func_0202D760(a0, species, form, gender, shiny, a2, isEgg,
                         func_02017E88(mon, 0, 0), a3);
}
