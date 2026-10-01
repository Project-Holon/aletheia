/*
 * function: func_021EC6F4
 * address: 0x021EC6F4
 * packet: pkt_ov170_021EC6F4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EC768 0x021EC768 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   d_021EFD4C 0x021EFD4C data a2
 */
typedef struct { short x, y; } Pos;
extern const Pos d_021EFD4C[];
extern unsigned func_0201AA18(void *);
extern void func_021EC08C(char *, int, short, short, short);
extern void func_021EC768(char *, unsigned, int);
extern void func_021EC000(char *, int, int);
#define WORK(p) (*(char **)((p) + 0x2C))
void func_021EC6F4(char *p)
{
    unsigned n = func_0201AA18(*(void **)(*(char **)p + 8));
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, d_021EFD4C[i].x + 0x98, d_021EFD4C[i].y - 0x90, 0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}
