/*
 * function: func_0216AAE4
 * address:  0x0216AAE4
 * packet:   pkt_ov010_0216AAE4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Season change: walks every mon of a party and sets the form (field 0x6F)
 * of species 585 and 586 to the season index, registering each species once
 * with func_0200CFA0 when one of its members actually changed.
 *
 * symbols:
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Blk37;
extern void *func_0200CA1C(void *a);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017988(void *mon, u16 form);
extern void func_0200CFA0(struct Blk37 *p, void *m);

void func_0216AAE4(void *sys, void *party, int season)
{
    u32 dex;
    int i;
    int n;
    int formA;
    int formB;
    int doneA;
    int doneB;

    dex = (u32)func_0200CA1C(sys);
    doneA = 0;
    doneB = 0;

    switch (season) {
    case 0:
        formA = 0;
        formB = 0;
        break;
    case 1:
        formA = 1;
        formB = 1;
        break;
    case 2:
        formA = 2;
        formB = 2;
        break;
    case 3:
        formA = 3;
        formB = 3;
        break;
    default:
        formA = 0;
        formB = 0;
        break;
    }

    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);
        int species = func_02017E1C(mon, 5, 0);
        int form = func_02017E1C(mon, 0x6F, 0);

        if (species == 585 && form != formA) {
            func_02017988(mon, formA);
            if (!doneA) {
                func_0200CFA0((struct Blk37 *)dex, mon);
                doneA = 1;
            }
        } else if (species == 586 && form != formB) {
            func_02017988(mon, formB);
            if (!doneB) {
                func_0200CFA0((struct Blk37 *)dex, mon);
                doneB = 1;
            }
        }
    }
}
