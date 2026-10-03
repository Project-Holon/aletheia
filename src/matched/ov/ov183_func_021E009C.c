/*
 * function: func_021E009C
 * address: 0x021E009C
 * packet: pkt_ov183_021E009C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 * symbols:
 *   func_021FFC9C 0x021FFC9C thumb ov186
 *   func_021FFE90 0x021FFE90 thumb ov186
 *   func_021E03B0 0x021E03B0 thumb ov183
 */
typedef unsigned short u16;
extern int func_021FFC9C(char *);
extern int func_021FFE90(int *, u16 *);
extern void func_021E03B0(char *, char *, int);
int func_021E009C(char *p, char *q)
{
    u16 out;
    int result;
    func_021FFC9C(*(char **)(p + 0x1c));
    result = func_021FFE90(*(int **)(p + 0x1c), &out);
    if (result) {
        if (result == 2) {
            *(u16 *)(q + 0x14) = out;
            func_021E03B0(p, q, 1);
            *(int *)(p + 0x50) = 0;
        } else {
            *(int *)(p + 0x50) = 0;
        }
        return 1;
    }
    return 0;
}
