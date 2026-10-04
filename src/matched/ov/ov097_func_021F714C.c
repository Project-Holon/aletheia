/*
 * function: func_021F714C
 * address: 0x021F714C
 * packet: pkt_ov097_021F714C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0204B294 result stored at 021F719C despite owner void; 020185F4 preserves and returns live r0; 0204B8C4 visible r1=0 retained.
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F72DC 0x021F72DC thumb ov097
 *   d_021F76C8 0x021F76C8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
struct Obj;
struct T { u32 a, b, i, j, k; };
struct P {
    u8 *parent;
    u8 pad04[0x4c];
    struct Bank *bank;
    union { struct Obj *all[24]; struct { struct Obj *a[6], *b[6], *c[6], *d[6]; } set; } actors;
    u32 tabA[9], tabB[4], tabC[4];
    void *mons[6];
};
extern const struct T d_021F76C8[];
extern struct Bank *func_0204B100(int, u8, u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_0204B92C(struct Obj *, u32);
extern void *func_020185F4(void *);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *, u32, u32);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0202136C(u16);
extern void func_0204B8C4(struct Obj *, u32);
extern void func_0204B878(struct Obj *, u16);
extern void func_021F72DC(unsigned p, unsigned i, int dx);
void func_021F714C(struct P *p)
{
    u32 i;
    u16 species;
    p->bank = func_0204B100(24, 0, 0x71);
    for (i = 0; i < 24; i++) {
        p->actors.all[i] = func_0204B294(p->bank,
            p->tabA[d_021F76C8[i].i],
            p->tabB[d_021F76C8[i].j],
            p->tabC[d_021F76C8[i].k], &d_021F76C8[i], 0, 0x71);
    }
    for (i = 0; i < 6; i++) {
        if (p->mons[i] == 0) {
            func_0204B3DC(p->actors.set.a[i], 0);
            func_0204B3DC(p->actors.set.b[i], 0);
            func_0204B3DC(p->actors.set.d[i], 0);
        } else {
            func_0204B92C(p->actors.set.a[i], 1);
            func_0204B6F4(p->actors.set.a[i], func_0201BBE8(func_020185F4(p->mons[i])), 1);
            species = func_02017E1C(p->mons[i], 6, 0);
            if (species == 0) func_0204B3DC(p->actors.set.b[i], 0);
            else if (func_0202136C(species) == 1) {
                func_0204B8C4(p->actors.set.b[i], 0);
                func_0204B878(p->actors.set.b[i], 1);
            } else {
                func_0204B8C4(p->actors.set.b[i], 0);
                func_0204B878(p->actors.set.b[i], 0);
            }
        }
        func_0204B3DC(p->actors.set.c[i], 0);
    }
    if (*(int *)(p->parent + 8) == 0) {
        for (i = 0; i < 3; i++) {
            func_021F72DC((unsigned int)p, i + 3, 128);
            func_021F72DC((unsigned int)p, i + 9, 128);
            func_021F72DC((unsigned int)p, i + 15, 128);
            func_021F72DC((unsigned int)p, i + 21, 128);
        }
    } else {
        for (i = 0; i < 3; i++) {
            func_021F72DC((unsigned int)p, i, -128);
            func_021F72DC((unsigned int)p, i + 6, -128);
            func_021F72DC((unsigned int)p, i + 12, -128);
            func_021F72DC((unsigned int)p, i + 18, -128);
        }
    }
}
