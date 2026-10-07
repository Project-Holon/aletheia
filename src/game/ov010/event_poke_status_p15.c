/*
 * file:     event_poke_status_p15.c
 * unit:     yes
 * function: func_0215A4C8, func_0215A4D8, func_0215A4EC, func_0215A500, func_0215A514
 * address:  0x0215A4C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202A230  0x0202A230  thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_02014314 0x02014314 thumb
 *   func_0201433C 0x0201433C thumb
 *   func_02030734  0x02030734  arm
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   d_021728E0     0x021728E0  data  ov010  a4
 */
struct BigObj;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern u32 func_0202A230(void *a, u32 idx);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_02014314(char *a0, int a1);
extern void func_0201433C(char *a0, int a1);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void *func_02158F54(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012964(const struct BigObj *p);
int func_0215A4C8(int a0);
unsigned func_0215A4D8(void *a, unsigned b);
void func_0215A4EC(char *a, unsigned b);
void func_0215A500(char *a, unsigned b);
void *func_0215A514(int a, int heap);
extern int d_021728E0;


int func_0215A4C8(int a0)
{
    int a1;

a1 = 2;
    a0 = func_0202A230((void *)a0, a1);
loc_0215A4D0:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}

/*
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 */
unsigned func_0215A4D8(void *a, unsigned b) { return func_020142E8(a, (u16)(b + 1420)); }

void func_0215A4EC(char *a, unsigned b) { func_02014314(a, (u16)(b + 1420)); }

void func_0215A500(char *a, unsigned b) { func_0201433C(a, (u16)(b + 1420)); }


void *func_0215A514(int a, int heap)
{
    int *p = (int *)func_02030734(heap, 0x110, 1, (const char *)&d_021728E0, 0x78);

    p[0] = a;
    p[1] = (int)func_02158F54((void *)a);
    p[2] = (int)func_020120F4((const struct Ctx *)p[1]);
    p[3] = func_02012964((const struct BigObj *)p[2]);
    *((char *)p + 0x104) = 7;
    return p;
}
