/*
 * function: func_021ADD38
 * address:  0x021ADD38
 * packet:   pkt_ov021_021ADD38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Q { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q;

struct Node;
struct Tagged;
extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
extern void func_02030EAC(struct Node *n);

void func_021ADD38(Q *q)
{
    int i;

    for (i = 0; i < 4; i++)
        func_02046EFC((struct Tagged *)q->arr[i]);
    func_020470D0((u32 *)q->f4);
    func_02046EFC((struct Tagged *)q->f4);
    func_02030EAC((struct Node *)q->f18);
}
