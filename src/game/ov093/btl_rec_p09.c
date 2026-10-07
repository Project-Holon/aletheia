/*
 * file:     btl_rec_p09.c
 * unit:     yes
 * function: func_021EED00, func_021EED24, func_021EED48
 * address:  0x021EED00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F6398  0x021F6398  data  a4
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_0201EE84  0x0201EE84  thumb
 */
struct Work;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    void *f8;
    u32 fc;
    u32 t[8];
} D;

extern u8 *func_021B9940(char *p, u8 i);
extern void *func_021D5864(struct Work *p);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void *func_021D5844(void *m);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
void func_021EED00(u8 a, u32 b);
void func_021EED24(u8 a, u32 b);
void func_021EED48(u8 a, u8 b);
extern D d_021F6398;


void func_021EED00(u8 a, u32 b)
{
    func_0201EEF4(d_021F6398.f8, b, func_021D5864((struct Work *)func_021B9940((char *)d_021F6398.f4, a)));
}


void func_021EED24(u8 a, u32 b)
{
    func_0201EEF4(d_021F6398.f8, b, func_021D5844(func_021B9940((char *)d_021F6398.f4, a)));
}


void func_021EED48(u8 a, u8 b)
{
    func_0201EE84(d_021F6398.f8, b, func_021D5864((struct Work *)func_021B9940((char *)d_021F6398.f4, a)));
}
