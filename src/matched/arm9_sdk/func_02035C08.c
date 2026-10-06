/*
 * function: func_02035C08
 * address:  0x02035C08
 * packet:   pkt_02035C08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224   0x02035224  arm
 *   func_02035BBC   0x02035BBC  arm
 */

struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern int func_02035BBC(void *ctx, void *param);

void func_02035C08(const void *p)
{
    func_02035BBC((void *)((int)func_02035224()), (void *)p);
}
