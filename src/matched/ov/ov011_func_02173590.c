/*
 * function: func_02173590
 * address:  0x02173590
 * packet:   pkt_ov011_02173590
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02039414  0x02039414  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */

typedef unsigned char u8;

typedef struct {
    u8 kind;
    u8 a : 4;
    u8 b : 4;
    u8 c : 1;
    u8 d : 5;
    u8 e : 2;
} Hdr;

extern int func_0203D1B4(void);
extern int func_02039414(void);
extern int func_02012944(int a);
extern void func_02008494(int a, void *b);

void func_02173590(int a, Hdr *p, int c)
{
    p->kind = 2;
    p->a = func_0203D1B4();
    if (c != -1)
        p->b = c;
    p->c = func_02039414();
    p->d = 1;
    func_02008494(func_02012944(a), (char *)p + 8);
}
