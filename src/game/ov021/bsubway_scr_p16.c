/*
 * file:     bsubway_scr_p16.c
 * unit:     yes
 * function: func_021C94F4, func_021C952C
 * address:  0x021C94F4
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
 *   d_021DE56C  0x021DE56C  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 */
struct Tagged;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 f0; u32 f4; u32 f8[3]; } Q;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
void func_021C94F4(Q *q);
void func_021C952C(Q *q);
extern u32 d_021DE56C[3];

void func_021C94F4(Q *q)
{
    u32 h = func_021ABE24((u8 *)q->f0);
    int i;
    q->f4 = (u32)func_02046E24(h, 0x52);
    func_02046FF8((int *)q->f4);
    for (i = 0; i < 3; i++)
        q->f8[i] = (u32)func_02046E24(h, d_021DE56C[i]);
}

void func_021C952C(Q *q)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02046EFC((struct Tagged *)q->f8[i]);
    func_020470D0((u32 *)q->f4);
    func_02046EFC((struct Tagged *)q->f4);
}
