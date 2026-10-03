/*
 * function: func_021BE9F8
 * address: 0x021BE9F8
 * packet: pkt_ov203_021BE9F8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02080C54 0x02080C54 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BEAB8 0x021BEAB8 thumb ov203
 *   func_021BEAF8 0x021BEAF8 thumb ov203
 *   func_021BEB48 0x021BEB48 thumb ov203
 */
typedef struct Config { unsigned words[11]; } Config;
extern void func_021BEAB8(void *, void *);
struct S02030FB4;
extern void func_021BEAF8(void *node, int *s);
extern void *func_020311B8(void *, void (*)(void *, void *), unsigned, unsigned);
extern void *func_02031290(struct S02030FB4 *p);
extern unsigned short func_02080C54(void);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_021BEB48(Config *);
void *func_021BE9F8(void *manager, const Config *source)
{
    void *task;
    char *ctx;
    task = func_020311B8(manager, func_021BEAB8, 56, 5);
    ctx = func_02031290(task);
    *(Config *)(ctx + 4) = *source;
    *(void **)(ctx + 0x34) = task;
    *(unsigned *)(ctx + 0x30) = 0;
    *(unsigned *)ctx = func_02080C54();
    func_021BEB48((Config *)(ctx + 4));
    func_020056A0((unsigned)func_021BEAF8, (unsigned)ctx, 0);
    return ctx;
}
