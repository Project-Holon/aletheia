/*
 * function: func_021FB058
 * address: 0x021FB058
 * packet: pkt_ov186_021FB058
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FB0E6..021FB0E8 is two zero alignment bytes.
 * lever: load position[1] to a local before the target and step stores.
 * symbols:
 *   func_021FAEE4 0x021FAEE4 thumb ov186
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 */
extern void func_021FAEE4(char *, int *);
extern void func_021FB548(void *, short *, short *);
extern void func_021FB514(void *, short, int);
extern int func_021FB7B0(void *, int);
int func_021FB058(char *ctx)
{
    int position[2];
    short x;
    short value;
    int target;
    int start;
    switch (*(int *)(ctx + 0x1c)) {
    case 0:
        func_021FAEE4(ctx, position);
        target = func_021FB7B0(*(void **)(ctx + 0xc), 1);
        start = position[1];
        *(short *)(ctx + 0x22) = target;
        *(short *)(ctx + 0x24) = 0;
        *(short *)(ctx + 0x20) = start;
        *(short *)(ctx + 0x26) = 16;
        *(int *)(ctx + 0x1c) = 1;
        break;
    case 1:
        value = *(short *)(ctx + 0x20) + ((*(short *)(ctx + 0x22) - *(short *)(ctx + 0x20)) * *(short *)(ctx + 0x24)) / *(short *)(ctx + 0x26);
        func_021FB548(*(void **)(ctx + 8), &x, 0);
        func_021FB514(*(void **)(ctx + 8), x, value);
        if ((*(short *)(ctx + 0x24))++ >= *(short *)(ctx + 0x26)) *(int *)(ctx + 0x1c) = 2;
        break;
    case 2: return 1;
    }
    return 0;
}
