/*
 * function: func_021BCC50
 * address:  0x021BCC50
 * packet:   pkt_ov093_021BCC50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[6]; E t; } S;

void func_021BCC50(S *p, E *cur)
{
    int i;
    int idx = -1;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur) {
            idx = i;
            break;
        }
    }
    if (idx < 0)
        return;
    p->t = *cur;
    for (i = idx; i < p->n - 1; i++)
        p->e[i] = p->e[i + 1];
    p->e[i] = p->t;
}
