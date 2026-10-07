/*
 * file:     btl_server_p20.c
 * unit:     yes
 * function: func_021BCB98, func_021BCC50
 * address:  0x021BCB98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[6]; E t; } S;

int func_021BCB98(S *p, E *cur, int start);
void func_021BCC50(S *p, E *cur);


int func_021BCB98(S *p, E *cur, int start)
{
    int a = -1;
    int b = -1;
    int i;
    int n = p->n;
    for (i = start; i < n; i++) {
        if (&p->e[i] == cur) {
            a = i;
            break;
        }
    }
    for (; start < n; start++) {
        if (p->e[start].flag == 0) {
            b = start;
            break;
        }
    }
    if (a >= 0 && b >= 0 && a > b) {
        p->t = *cur;
        for (i = a; i > b; i--)
            p->e[i] = p->e[i - 1];
        p->e[b] = p->t;
        return b;
    }
    return -1;
}


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
