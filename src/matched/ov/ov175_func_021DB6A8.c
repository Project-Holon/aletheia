/*
 * function: func_021DB6A8
 * address: 0x021DB6A8
 * packet: pkt_ov175_021DB6A8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_021DA470 0x021DA470 thumb ov175
 *   func_021DD020 0x021DD020 thumb ov175
 *   d_021E2F2C 0x021E2F2C data a4
 *   d_021E2F38 0x021E2F38 data a4
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 */
extern void *func_02012944(void *);
extern void func_021DA470(unsigned char *);
extern int func_021DD020(char *);
extern char d_021E2F2C[], d_021E2F38[], d_021E2F4C[], d_021E2F60[];
void func_021DB6A8(char *ctx)
{
    void *record;
    record = func_02012944(*(void **)(ctx + 8));
    *(char **)(*(char **)(ctx + 0x190)) = d_021E2F2C;
    *(int *)(*(char **)(ctx + 0x190) + 4) = 8;
    *(void **)(*(char **)(ctx + 0x190) + 8) = record;
    *(int *)(*(char **)(ctx + 0x190) + 0xc) = 32;
    func_021DA470((unsigned char *)ctx + 0x38);
    *(char **)(*(char **)(ctx + 0x190) + 0x10) = d_021E2F38;
    *(int *)(*(char **)(ctx + 0x190) + 0x14) = 8;
    *(char **)(*(char **)(ctx + 0x190) + 0x18) = ctx + 0x38;
    *(int *)(*(char **)(ctx + 0x190) + 0x1c) = 6;
    *(char **)(*(char **)(ctx + 0x190) + 0x20) = d_021E2F4C;
    *(int *)(*(char **)(ctx + 0x190) + 0x24) = 2;
    *(int *)(*(char **)(ctx + 0x190) + 0x28) = *(int *)(ctx + 0xc);
    *(char **)(*(char **)(ctx + 0x190) + 0x30) = d_021E2F60;
    *(int *)(*(char **)(ctx + 0x190) + 0x34) = 2;
    *(int *)(*(char **)(ctx + 0x190) + 0x38) = func_021DD020(ctx);
    *(int *)(ctx + 0x198) = 4;
}
