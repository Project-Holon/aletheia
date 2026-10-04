/*
 * function: func_0215E440
 * address:  0x0215E440
 * packet:   pkt_ov010_0215E440
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Hand out the legendary for slot `which` (Thundurus 642 or Tornadus
 * 641 at level 40): fill the event record, create the Pokemon into the
 * box, and mark the slot. Levers: level and the record flag assigned the
 * same value in both switch arms (the tail-merged assignments keep them
 * as variables: level spilled to the frame, the flag in r6), species as
 * u32 truncated at the call, `a` declared before `save`.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D50C  0x0200D50C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02008530  0x02008530  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02012984  0x02012984  thumb
 *   func_0215E740  0x0215E740  thumb  ov010
 *   func_0200D470  0x0200D470  thumb
 *   d_0217293C     0x0217293C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct Big;
struct Blk37;
struct Blk38;
struct GdsEnt;
struct Mon;
struct Sub0200852CObj;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *save);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern void func_0200D50C(struct GdsEnt *e, u32 i, u32 v);
extern u8 *func_02012944(void *p);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_0200CA10(void *save);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_020307B0(void *p);
struct BigObj;
extern u8 func_02012984(const struct BigObj *p);
extern void func_0215E740(void *a, void *b, u32 which, u32 n);
extern void func_0200D470(struct Blk38 *p, u32 i, u8 v);
extern const char d_0217293C[];

void func_0215E440(void *sys, u32 which)
{
    void *a;
    void *save;
    void *rec;
    void *party;
    void *mon;
    u32 species;
    u16 level;
    u32 flag;

    save = func_02012EBC(sys);
    a = func_0200D418(save);
    rec = func_0200D4AC(a, which);
    switch (which) {
    case 0:
        species = 642;
        level = 40;
        flag = 1;
        break;
    case 1:
        species = 641;
        level = 40;
        flag = 1;
        break;
    default:
        return;
    }
    func_0200D50C(rec, 4, species);
    func_0200D50C(rec, 6, level);
    func_0200D50C(rec, 9, flag);
    party = func_02012944(sys);
    mon = func_02030734(0x8003, func_020173EC(), 1, d_0217293C, 0x12E);
    func_02017588(mon, species, level, func_02008530(party), 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
    func_0200D50C(rec, 7, 0);
    func_0200D50C(rec, 8, 1);
    func_0200D50C(rec, 2, func_02017E1C(mon, 0xAC, 0));
    func_0200D50C(rec, 3, func_02017E1C(mon, 0, 0));
    func_0200D50C(rec, 10, func_02017E1C(mon, 0x70, 0));
    func_0200D50C(rec, 5, func_02017E1C(mon, 0xA1, 0));
    func_0200CFA0(func_0200CA10(save), mon);
    func_020307B0(mon);
    func_0215E740(a, (void *)func_02012984(sys), which, 5);
    func_0200D470(a, which, 1);
}
