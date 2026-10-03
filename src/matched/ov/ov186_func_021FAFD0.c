/*
 * function: func_021FAFD0
 * address: 0x021FAFD0
 * packet: pkt_ov186_021FAFD0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FB056..021FB058 is two zero alignment bytes.
 * symbols:
 *   func_021FAEE4 0x021FAEE4 thumb ov186
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 */
extern void func_021FAEE4(char *, int *);
extern void func_021FB548(char *p, short *x, short *y);
extern void func_021FB514(char *p, short x, short y);
int func_021FAFD0(char *ctx)
{
    int position[2];
    short x;
    short value;
    switch (*(int *)(ctx + 0x1c)) {
    case 0:
        func_021FAEE4(ctx, position);
        *(short *)(ctx + 0x20) = position[1];
        *(short *)(ctx + 0x22) = *(int *)(ctx + 0x18);
        *(short *)(ctx + 0x24) = 0;
        *(short *)(ctx + 0x26) = 10;
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
