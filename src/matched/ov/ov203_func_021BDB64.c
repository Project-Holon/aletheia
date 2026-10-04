/*
 * function: func_021BDB64
 * address: 0x021BDB64
 * packet: pkt_ov203_021BDB64
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDD30 0x021BDD30 thumb ov203
 *   func_021BDF00 0x021BDF00 thumb ov203
 *   func_021BE538 0x021BE538 thumb ov203
 *   func_021BDC88 0x021BDC88 thumb ov203
 *   func_021BE620 0x021BE620 thumb ov203
 *   func_021BE638 0x021BE638 thumb ov203
 *   func_021BDC20 0x021BDC20 thumb ov203
 *   d_02FFFC3C 0x02FFFC3C data
 */
extern void func_021BDD30(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BDF00(unsigned char *);
extern int func_021BE538(void *, unsigned int);
extern int func_021BDC88(char *);
extern int func_021BE620(void *);
extern void func_021BE638(char *p, int a);
extern u32 func_020221A4(void);
extern int func_021BDC20(void *ctx, unsigned mode, unsigned heap);
extern unsigned int d_02FFFC3C;
int func_021BDB64(void *unused, int *state, void *c, char *work)
{
    int result;
    unsigned int now, delta;
    func_021BDD30(*(char **)(work + 0x1c));
    func_0201C4E4(*(void **)(work + 0x10));
    func_021BDF00(*(unsigned char **)(work + 0xc));
    result = func_021BE538(*(void **)(work + 0x18), *(unsigned int *)(work + 0x24));
    now = d_02FFFC3C;
    delta = now - *(unsigned int *)(work + 0x20);
    *(unsigned int *)(work + 0x24) = 0;
    if (*(unsigned int *)(work + 0x20) != 0 && delta > 1)
        *(unsigned int *)(work + 0x24) = delta - 1;
    *(unsigned int *)(work + 0x20) = now;
    *(unsigned int *)(work + 0x28) = *(unsigned int *)(work + 0x28) + *(unsigned int *)(work + 0x24);
    switch (*state) {
    case 0:
        if (func_021BDC88(work) != 0 || result != 0) {
            (*(int **)(work + 4))[4] = func_021BE620(*(void **)(work + 0x18)) >> 12;
            (*(int **)(work + 4))[5] = result + 1;
            func_021BE638(*(void **)(work + 0x18), (*(int **)(work + 4))[5]);
            (*state)++;
        }
        break;
    case 1:
        if (func_020221A4() == 1) {
            if (func_021BDC20((void *)((unsigned char)(*(int **)(work + 4))[1]), 0, *(unsigned short *)work))
                return 1;
            (*state)++;
        }
        break;
    case 2:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    return 0;
}
