/*
 * file:     field_effect_p40.c
 * unit:     yes
 * function: func_021AB7E4, func_021AB81C
 * address:  0x021AB7E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DE000  0x021DE000  data  a4
 *   d_021D8EEC  0x021D8EEC  data  a4
 *   func_021AB868  0x021AB868  thumb
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef struct {
    int pad[2];
    int f8[2];
} S;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021AB868(S *s);
extern void func_02049238(int a);
extern u32 func_020307B0(void *p);
S *func_021AB7E4(int heap);
void func_021AB81C(S *s);
extern char d_021DE000[];
extern const int d_021D8EEC[];


S *func_021AB7E4(int heap)
{
    S *p = func_02030734(heap, 0x10, 1, d_021DE000, 0x81);
    int i;
    for (i = 0; i < 2; i++) {
        p->f8[i] = (int)func_020490F4(d_021D8EEC[i], heap);
    }
    return p;
}


void func_021AB81C(S *s)
{
    int i;
    func_021AB868(s);
    for (i = 0; i < 2; i++) {
        func_02049238(s->f8[i]);
    }
    func_020307B0(s);
}
