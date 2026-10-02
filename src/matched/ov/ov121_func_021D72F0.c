/*
 * function: func_021D72F0
 * address: 0x021D72F0
 * packet: pkt_ov121_021D72F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021D83B0 0x021D83B0 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021DA8C0 0x021DA8C0 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021DA8C4 0x021DA8C4 thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 */
extern void func_021D9F08(void *, int, int, int);
extern void func_021D81B0(void *, int, int);
extern int func_021D83B0(void *);
extern void func_021D8380(void *);
extern void func_021DA8C0(void *, int);
extern void func_021DA8B0(void *, void *);
extern int func_021D9FF8(void *);
extern void func_021DA8C4(void *);
extern void func_021D6E3C(void);
void func_021D72F0(void *a, int *state, char *p)
{
    int result;
    switch (*state) {
    case 0:
        func_021D9F08(*(void **)(p+0x284), *(int *)(p+0x3a4), 126, 0);
        func_021D81B0(p, 3, 29);
        *state = 2;
        break;
    case 2:
        result = func_021D83B0(p);
        if (result == -1) break;
        func_021D8380(p);
        if (result == 0) {
            func_021D9F08(*(void **)(p+0x284), *(int *)(p+0x3a4), 132, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 1) {
            func_021D9F08(*(void **)(p+0x284), *(int *)(p+0x3a4), 133, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 2) {
            func_021D9F08(*(void **)(p+0x284), *(int *)(p+0x3a4), 134, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 3) {
            func_021DA8B0(a, func_021D6E3C);
        }
        break;
    case 3:
        if (func_021D9FF8(*(void **)(p+0x284))) func_021DA8C4(a);
        break;
    }
}
